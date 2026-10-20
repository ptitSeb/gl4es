#include "list.h"

#include "../glx/hardext.h"
#include "wrap/gl4es.h"
#include "fpe.h"
#include "init.h"
#include "line.h"
#include "loader.h"
#include "matrix.h"
#include "texgen.h"
#include "render.h"
#include "fpe.h"

/* Temporary projection-row bias for polygon-mode lines when
 * GL_POLYGON_OFFSET_LINE is on. GLES fill-offset does not apply to
 * GL_LINES; cached object-space verts are never written.
 * TODO: only shaders that use the projection matrix get the bias; a program
 * that writes gl_Position without it isn't offset. */
static int begin_polygon_line_zbias(int from_polygon_mode, gl4es_mvp_save_t *saved)
{
    if (!from_polygon_mode || !glstate->enable.polyline_offset)
        return 0;
    gl4es_mvp_save(saved);
    gl4es_mvp_poke_proj_zbias(gl4es_polygon_offset_ndc_d());
    return 1;
}

static void end_polygon_line_zbias(int applied, const gl4es_mvp_save_t *saved)
{
    if (applied)
        gl4es_mvp_restore(saved);
}

/* return 1 if failed, 2 if succeed */
typedef struct array2vbo_s {
    uintptr_t   real_base;
    uint32_t    real_size;
    uint32_t    stride;
    uintptr_t   vbo_base;
    uintptr_t   vbo_basebase;
} array2vbo_t;

int list2VBO(renderlist_t* list)
{
    LOAD_GLES2(glGenBuffers);
    LOAD_GLES2(glBufferData);
    LOAD_GLES2(glBufferSubData);
    array2vbo_t work[ATT_MAX] = {0};
    // list -> work
    int imax = 0;
    int len = list->len;
    if(list->vert) {
        work[imax].real_base = (uintptr_t)list->vert;
        work[imax].stride = list->vert_stride;
        if(!work[imax].stride) work[imax].stride = 4*4; // 4*GL_FLOAT
        work[imax].real_size = work[imax].stride*len;
        imax++;
    }
    if(list->color) {
        work[imax].real_base = (uintptr_t)list->color;
        work[imax].stride = list->color_stride;
        if(!work[imax].stride) work[imax].stride = 4*4; // 4*GL_FLOAT
        work[imax].real_size = work[imax].stride*len;
        imax++;
    }
    if(list->secondary) {
        work[imax].real_base = (uintptr_t)list->secondary;
        work[imax].stride = list->secondary_stride;
        if(!work[imax].stride) work[imax].stride = 4*4; // 4*GL_FLOAT
        work[imax].real_size = work[imax].stride*len;
        imax++;
    }
    if(list->fogcoord) {
        work[imax].real_base = (uintptr_t)list->fogcoord;
        work[imax].stride = list->fogcoord_stride;
        if(!work[imax].stride) work[imax].stride = 1*4; // 1*GL_FLOAT
        work[imax].real_size = work[imax].stride*len;
        imax++;
    }
    if(list->normal) {
        work[imax].real_base = (uintptr_t)list->normal;
        work[imax].stride = list->normal_stride;
        if(!work[imax].stride) work[imax].stride = 3*4; // 3*GL_FLOAT
        work[imax].real_size = work[imax].stride*len;
        imax++;
    }
    for (int a=0; a<list->maxtex; ++a) {
        if(list->tex[a]) {
            work[imax].real_base = (uintptr_t)list->tex[a];
            work[imax].stride = list->tex_stride[a];
            if(!work[imax].stride) work[imax].stride = 4*4; // 4*GL_FLOAT
            work[imax].real_size = work[imax].stride*len;
            imax++;
        }
    }
    // sort the real address...
    int sorted[ATT_MAX];
    for (int i=0; i<imax; ++i)
        sorted[i] = i;
    // bubble sort, array is small enough, and probably almost sorted
    for (int i=0; i<imax-1; ++i)
        for (int j=i+1; j<imax; ++j)
            if(work[sorted[i]].real_base > work[sorted[j]].real_base) {
                int tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
            }
    // get a base vbo offset
    uintptr_t vbo_base = 0;
    for (int i=0; i<imax; ++i) {
        uintptr_t base = vbo_base;
        uintptr_t basebase = vbo_base;
        array2vbo_t *r = work+sorted[i];
        if(i) for(int j=i-1; j<i; ++j) {
            array2vbo_t *t = work+sorted[j];
            if(r->real_base<t->real_base+t->real_size) {
                base = r->vbo_base + (r->real_base - t->real_base);
                basebase = r->vbo_basebase;
                break;
            }
        }
        r->vbo_base = base;
        r->vbo_basebase = basebase;
        if(base == basebase)
            vbo_base += r->real_size;
    }
    if(!vbo_base)   // no data?!
        return 1;
    // Create the VBO and fill the data
    gles_glGenBuffers(1, &list->vbo_array);
    bindBuffer(GL_ARRAY_BUFFER, list->vbo_array);
    gles_glBufferData(GL_ARRAY_BUFFER, vbo_base, NULL, GL_STATIC_DRAW);
    for(int i=0; i<imax; ++i) {
        array2vbo_t *r = work+sorted[i];
        if(r->vbo_base==r->vbo_basebase)
            gles_glBufferSubData(GL_ARRAY_BUFFER, r->vbo_basebase, r->real_size, (void*)r->real_base);
    }
    // work -> list
    imax = 0;
    if(list->vert) {
        list->vbo_vert = (GLfloat*)work[imax].vbo_base;
        imax++;
    }
    if(list->color) {
        list->vbo_color = (GLfloat*)work[imax].vbo_base;
        imax++;
    }
    if(list->secondary) {
        list->vbo_secondary = (GLfloat*)work[imax].vbo_base;
        imax++;
    }
    if(list->fogcoord) {
        list->vbo_fogcoord = (GLfloat*)work[imax].vbo_base;
        imax++;
    }
    if(list->normal) {
        list->vbo_normal = (GLfloat*)work[imax].vbo_base;
        imax++;
    }
    for (int a=0; a<list->maxtex; ++a) {
        if(list->tex[a]) {
            list->vbo_tex[a] = (GLfloat*)work[imax].vbo_base;
            imax++;
        }
    }

    return 2;
}
typedef struct save_vbo_s {
    GLuint          real_buffer;
    const GLvoid*   real_pointer;
    glbuffer_t*     buffer;
} save_vbo_t;

void listActiveVBO(renderlist_t* list, save_vbo_t* saved) {
    if(list->vert) {
        saved[ATT_VERTEX].real_buffer = glstate->vao->vertexattrib[ATT_VERTEX].real_buffer;
        saved[ATT_VERTEX].real_pointer = glstate->vao->vertexattrib[ATT_VERTEX].real_pointer;
        saved[ATT_VERTEX].buffer = glstate->vao->vertexattrib[ATT_VERTEX].buffer;
        glstate->vao->vertexattrib[ATT_VERTEX].real_buffer = list->vbo_array;
        glstate->vao->vertexattrib[ATT_VERTEX].real_pointer = list->vbo_vert;
        glstate->vao->vertexattrib[ATT_VERTEX].buffer = NULL;
    }
    if(list->color) {
        saved[ATT_COLOR].real_buffer = glstate->vao->vertexattrib[ATT_COLOR].real_buffer;
        saved[ATT_COLOR].real_pointer = glstate->vao->vertexattrib[ATT_COLOR].real_pointer;
        saved[ATT_COLOR].buffer = glstate->vao->vertexattrib[ATT_COLOR].buffer;
        glstate->vao->vertexattrib[ATT_COLOR].real_buffer = list->vbo_array;
        glstate->vao->vertexattrib[ATT_COLOR].real_pointer = list->vbo_color;
        glstate->vao->vertexattrib[ATT_COLOR].buffer = NULL;
    }
    if(list->secondary) {
        saved[ATT_SECONDARY].real_buffer = glstate->vao->vertexattrib[ATT_SECONDARY].real_buffer;
        saved[ATT_SECONDARY].real_pointer = glstate->vao->vertexattrib[ATT_SECONDARY].real_pointer;
        saved[ATT_SECONDARY].buffer = glstate->vao->vertexattrib[ATT_SECONDARY].buffer;
        glstate->vao->vertexattrib[ATT_SECONDARY].real_buffer = list->vbo_array;
        glstate->vao->vertexattrib[ATT_SECONDARY].real_pointer = list->vbo_secondary;
        glstate->vao->vertexattrib[ATT_SECONDARY].buffer = NULL;
    }
    if(list->fogcoord) {
        saved[ATT_FOGCOORD].real_buffer = glstate->vao->vertexattrib[ATT_FOGCOORD].real_buffer;
        saved[ATT_FOGCOORD].real_pointer = glstate->vao->vertexattrib[ATT_FOGCOORD].real_pointer;
        saved[ATT_FOGCOORD].buffer = glstate->vao->vertexattrib[ATT_FOGCOORD].buffer;
        glstate->vao->vertexattrib[ATT_FOGCOORD].real_buffer = list->vbo_array;
        glstate->vao->vertexattrib[ATT_FOGCOORD].real_pointer = list->vbo_fogcoord;
        glstate->vao->vertexattrib[ATT_FOGCOORD].buffer = NULL;
    }
    if(list->normal) {
        saved[ATT_NORMAL].real_buffer = glstate->vao->vertexattrib[ATT_NORMAL].real_buffer;
        saved[ATT_NORMAL].real_pointer = glstate->vao->vertexattrib[ATT_NORMAL].real_pointer;
        saved[ATT_NORMAL].buffer = glstate->vao->vertexattrib[ATT_NORMAL].buffer;
        glstate->vao->vertexattrib[ATT_NORMAL].real_buffer = list->vbo_array;
        glstate->vao->vertexattrib[ATT_NORMAL].real_pointer = list->vbo_normal;
        glstate->vao->vertexattrib[ATT_NORMAL].buffer = NULL;
    }
    for (int a=0; a<list->maxtex; ++a) {
        if(list->tex[a]) {
            saved[ATT_MULTITEXCOORD0+a].real_buffer = glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].real_buffer;
            saved[ATT_MULTITEXCOORD0+a].real_pointer = glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].real_pointer;
            saved[ATT_MULTITEXCOORD0+a].buffer = glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].buffer;
            glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].real_buffer = list->vbo_array;
            glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].real_pointer = list->vbo_tex[a];
            glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].buffer = NULL;
        }
    }
}
void listInactiveVBO(renderlist_t* list, save_vbo_t* saved) {
    if(list->vert) {
        glstate->vao->vertexattrib[ATT_VERTEX].real_buffer = saved[ATT_VERTEX].real_buffer;
        glstate->vao->vertexattrib[ATT_VERTEX].real_pointer = saved[ATT_VERTEX].real_pointer;
        glstate->vao->vertexattrib[ATT_VERTEX].buffer = saved[ATT_VERTEX].buffer;
    }
    if(list->color) {
        glstate->vao->vertexattrib[ATT_COLOR].real_buffer = saved[ATT_COLOR].real_buffer;
        glstate->vao->vertexattrib[ATT_COLOR].real_pointer = saved[ATT_COLOR].real_pointer;
        glstate->vao->vertexattrib[ATT_COLOR].buffer = saved[ATT_COLOR].buffer;
    }
    if(list->secondary) {
        glstate->vao->vertexattrib[ATT_SECONDARY].real_buffer = saved[ATT_SECONDARY].real_buffer;
        glstate->vao->vertexattrib[ATT_SECONDARY].real_pointer = saved[ATT_SECONDARY].real_pointer;
        glstate->vao->vertexattrib[ATT_SECONDARY].buffer = saved[ATT_SECONDARY].buffer;
    }
    if(list->fogcoord) {
        glstate->vao->vertexattrib[ATT_FOGCOORD].real_buffer = saved[ATT_FOGCOORD].real_buffer;
        glstate->vao->vertexattrib[ATT_FOGCOORD].real_pointer = saved[ATT_FOGCOORD].real_pointer;
        glstate->vao->vertexattrib[ATT_FOGCOORD].buffer = saved[ATT_FOGCOORD].buffer;
    }
    if(list->normal) {
        glstate->vao->vertexattrib[ATT_NORMAL].real_buffer = saved[ATT_NORMAL].real_buffer;
        glstate->vao->vertexattrib[ATT_NORMAL].real_pointer = saved[ATT_NORMAL].real_pointer;
        glstate->vao->vertexattrib[ATT_NORMAL].buffer = saved[ATT_NORMAL].buffer;
    }
    for (int a=0; a<list->maxtex; ++a) {
        if(list->tex[a]) {
            glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].real_buffer = saved[ATT_MULTITEXCOORD0+a].real_buffer;
            glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].real_pointer = saved[ATT_MULTITEXCOORD0+a].real_pointer;
            glstate->vao->vertexattrib[ATT_MULTITEXCOORD0+a].buffer = saved[ATT_MULTITEXCOORD0+a].buffer;
        }
    }
}

/* Build boundary indices from vertex-order flags and modeinit_t.vlen.  The
 * caller allocates four indices per vertex; return -1 for a topology that
 * cannot be reconstructed within that bound so it can fall back to
 * fill_lineIndices().  GL_QUAD_STRIP fits the allocation. */
#define EDGE_EMIT(a, b)                                   \
    do {                                                  \
        if (edgeflag[(a)]) {                              \
            ind_line[k++] = (GLushort)(a);                \
            ind_line[k++] = (GLushort)(b);                \
        }                                                 \
    } while (0)
#define EDGE_ALWAYS(a, b)                                 \
    do {                                                  \
        ind_line[k++] = (GLushort)(a);                    \
        ind_line[k++] = (GLushort)(b);                    \
    } while (0)

static int build_lineIndices_edgeflag(const modeinit_t *modes, int length,
                                      int total_verts,
                                      const GLubyte *edgeflag,
                                      GLushort *ind_line)
{
    int k = 0;
    int start = 0;
    for (int m = 0; m < length; ++m) {
        /* The last block's recorded span can lag the list's final length
         * (rlEnd trims, and a block is stamped as the next one opens), so the
         * tail always runs to the real vertex count. */
        int end = (m + 1 < length) ? modes[m].vlen : total_verts;
        if (end > total_verts)
            end = total_verts;
        if (end < start)
            return -1;      /* bookkeeping we do not trust: use the old path */
        int len = end - start;
        if (len == 0)
            continue;
        switch (modes[m].mode_init) {
            case GL_TRIANGLES:
                for (int i = 0; i + 2 < len; i += 3) {
                    int a = start + i;
                    EDGE_EMIT(a + 0, a + 1);
                    EDGE_EMIT(a + 1, a + 2);
                    EDGE_EMIT(a + 2, a + 0);
                }
                break;
            case GL_QUADS:
                for (int i = 0; i + 3 < len; i += 4) {
                    int a = start + i;
                    EDGE_EMIT(a + 0, a + 1);
                    EDGE_EMIT(a + 1, a + 2);
                    EDGE_EMIT(a + 2, a + 3);
                    EDGE_EMIT(a + 3, a + 0);
                }
                break;
            case GL_QUAD_STRIP:
                /* quad q is bounded by v(2q) -> v(2q+1) -> v(2q+3) -> v(2q+2);
                 * GL ignores edge flags for strips, so all four are drawn */
                for (int i = 0; i + 3 < len; i += 2) {
                    int a = start + i;
                    EDGE_ALWAYS(a + 0, a + 1);
                    EDGE_ALWAYS(a + 1, a + 3);
                    EDGE_ALWAYS(a + 3, a + 2);
                    EDGE_ALWAYS(a + 2, a + 0);
                }
                break;
            case GL_POLYGON:
                if (len > 2) {
                    for (int i = 0; i < len - 1; ++i)
                        EDGE_EMIT(start + i, start + i + 1);
                    EDGE_EMIT(start + len - 1, start);
                }
                break;
            default:
                return -1;
        }
        start = end;
    }
    return k;
}

#undef EDGE_EMIT
#undef EDGE_ALWAYS

int fill_lineIndices(modeinit_t *modes, int length, GLenum mode, GLushort* indices, GLushort *ind_line)
{
    #define ind(a)  indices?indices[a]:(a)
    int k=0;
    int i=0;
    for (int m=0; m<length; m++) {
        GLenum mode_init = modes[k].mode_init;
        int len = modes[k].ilen;
        switch (mode) {
            case GL_TRIANGLE_STRIP:
                if (mode_init==GL_QUAD_STRIP) {
                    /* Quad q is bounded by v(2q)->v(2q+1)->v(2q+3)->v(2q+2). */
                    for (; i+3<len; i+=2) {
                        ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                        ind_line[k++] = ind(i+1); ind_line[k++] = ind(i+3);
                        ind_line[k++] = ind(i+3); ind_line[k++] = ind(i+2);
                        ind_line[k++] = ind(i+2); ind_line[k++] = ind(i+0);
                    }
                    i = len;
                    break;
                }
                // first 3 points a triangle, then a 2 lines per new point
                if (len>2) {
                    ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                    i+=2;
                    for (; i<len; i++) {
                        ind_line[k++] = ind(i-2); ind_line[k++] = ind(i);
                        ind_line[k++] = ind(i-1); ind_line[k++] = ind(i);
                    }
                }
                break;
            case GL_TRIANGLE_FAN:
                if(mode_init==GL_QUAD_STRIP) {
                    // first 4 points is a quad, then 2 points per new quad
                    if (len>3) {
                        ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                        i+=2;
                        for (; i<len-1; i+=2) {
                            ind_line[k++] = ind(i-1); ind_line[k++] = ind(i);
                            ind_line[k++] = ind(i-2); ind_line[k++] = ind(i+1);
                            ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                        }
                    }
                } else if(mode_init==GL_POLYGON || mode_init==GL_QUADS) {
                    /* A lone GL_QUADS block is a four-vertex fan; walk its ring. */
                    if (len) {
                        int z = i;
                        ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                        ++i;
                        for (; i<len; i++) {
                            ind_line[k++] = ind(i-1); ind_line[k++] = ind(i);
                        }
                        ind_line[k++] = ind(len-1); ind_line[k++] = ind(z);
                    }
                } else {
                    // first 3 points a triangle, then a 2 lines per new point too
                    if (len>2) {
                        int z = i;
                        ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                        i+=2;
                        for (; i<len; i++) {
                            ind_line[k++] = ind(z); ind_line[k++] = ind(i);
                            ind_line[k++] = ind(i-1); ind_line[k++] = ind(i);
                        }
                    }
                }
                break;
            case GL_TRIANGLES:
            switch (mode_init) {
                case GL_TRIANGLE_STRIP:
                case GL_TRIANGLE_FAN:
                case GL_TRIANGLES:
                    if(len>2) {
                        // 1 triangle -> 3 lines => 6 half-lines !
                        for (; i<len-2; i+=3) {
                            ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                            ind_line[k++] = ind(i+1); ind_line[k++] = ind(i+2);
                            ind_line[k++] = ind(i+2); ind_line[k++] = ind(i+0);
                        }
                    }
                    break;
                case GL_QUADS:
                    if (len>3) {
                        // 4 lines per quads, but dest may already be a triangles list...
                        if (len==4) {
                            // just 1 Quad
                            for (; i<4; i++) {
                                ind_line[k++] = ind(i+0); ind_line[k++] = ind((i+1)%4);
                            }
                        } else {
                            // list of triangles, 2 per quads...
                            for (; i<len-5; i+=6) {
                                ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                                ind_line[k++] = ind(i+1); ind_line[k++] = ind(i+2);
                                ind_line[k++] = ind(i+2); ind_line[k++] = ind(i+5);
                                ind_line[k++] = ind(i+5); ind_line[k++] = ind(i+0);
                            }
                        }
                    }
                    break;
                case GL_QUAD_STRIP:
                    // first 4 points is a quad, then 2 points per new quad
                    if (len>3) {
                        ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                        i+=2;
                        for (; i<len-1; i+=2) {
                            ind_line[k++] = ind(i-1); ind_line[k++] = ind(i);
                            ind_line[k++] = ind(i-2); ind_line[k++] = ind(i+1);
                            ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                        }
                    }
                    break;
                case GL_POLYGON:
                    // if polygons have been merged, then info is lost...
                    if (len) {
                        int z = i;
                        ind_line[k++] = ind(i+0); ind_line[k++] = ind(i+1);
                        ++i;
                        for (; i<len; i++) {
                            ind_line[k++] = ind(i-1); ind_line[k++] = ind(i);
                        }
                        ind_line[k++] = ind(len-1); ind_line[k++] = ind(z);
                    }
                    break;
            }
            break;
        }
    }
    #undef ind
    return k;
}

/* WebGL's client-side glDrawElements path is unusually expensive: Emscripten
 * has to upload the index array and scan it to discover the client vertex
 * range for every draw.  Polygon-mode lines are generated indices, so expand
 * the enabled arrays in that order and use glDrawArrays(GL_LINES) instead.
 *
 * Keep this ES2+ only.  The ES1 path can synthesize texture coordinates and
 * final colors below, after this point, and still uses the indexed fallback.
 * And keep it to Emscripten: native drivers read client-side arrays in place,
 * so there the expansion is only extra copying. */
#ifdef __EMSCRIPTEN__
#define LINE_ARRAYS 1
#else
#define LINE_ARRAYS 0
#endif
static GLfloat *expand_line_array(const GLfloat *src, int stride,
                                  int components, const GLushort *indices,
                                  int count)
{
    if (!src)
        return NULL;
    if (!stride)
        stride = components * (int)sizeof(GLfloat);
    GLfloat *dst = (GLfloat *)malloc((size_t)count * components * sizeof(GLfloat));
    if (!dst)
        return NULL;
    for (int i = 0; i < count; ++i) {
        const GLfloat *item = (const GLfloat *)((const char *)src +
                                                (size_t)indices[i] * stride);
        memcpy(dst + (size_t)i * components, item,
               (size_t)components * sizeof(GLfloat));
    }
    return dst;
}

static int build_line_arrays(line_arrays_t *arrays, const renderlist_t *list,
                             const GLushort *indices, int count)
{
    if (!list->vert)
        return 0;
    memset(arrays, 0, sizeof(*arrays));
    arrays->count = count;
    arrays->vert = expand_line_array(list->vert, list->vert_stride, 4,
                                     indices, count);
    if (list->vert && !arrays->vert)
        goto failed;
    arrays->normal = expand_line_array(list->normal, list->normal_stride, 3,
                                       indices, count);
    if (list->normal && !arrays->normal)
        goto failed;
    arrays->color = expand_line_array(list->color, list->color_stride, 4,
                                      indices, count);
    if (list->color && !arrays->color)
        goto failed;
    arrays->secondary = expand_line_array(list->secondary,
                                          list->secondary_stride, 4,
                                          indices, count);
    if (list->secondary && !arrays->secondary)
        goto failed;
    arrays->fogcoord = expand_line_array(list->fogcoord, list->fogcoord_stride,
                                         1, indices, count);
    if (list->fogcoord && !arrays->fogcoord)
        goto failed;
    for (int a = 0; a < list->maxtex; ++a) {
        arrays->tex[a] = expand_line_array(list->tex[a], list->tex_stride[a],
                                           4, indices, count);
        if (list->tex[a] && !arrays->tex[a])
            goto failed;
    }
    return 1;

failed:
    clear_line_arrays(arrays);
    return 0;
}

static int line_arrays_to_vbo(line_arrays_t *arrays, const renderlist_t *list)
{
    renderlist_t expanded = {0};
    expanded.len = arrays->count;
    expanded.vert = arrays->vert;
    expanded.normal = arrays->normal;
    expanded.color = arrays->color;
    expanded.secondary = arrays->secondary;
    expanded.fogcoord = arrays->fogcoord;
    expanded.maxtex = list->maxtex;
    for (int a = 0; a < list->maxtex; ++a)
        expanded.tex[a] = arrays->tex[a];
    if (list2VBO(&expanded) != 2)
        return 0;
    arrays->vbo_array = expanded.vbo_array;
    arrays->vbo_vert = expanded.vbo_vert;
    arrays->vbo_normal = expanded.vbo_normal;
    arrays->vbo_color = expanded.vbo_color;
    arrays->vbo_secondary = expanded.vbo_secondary;
    arrays->vbo_fogcoord = expanded.vbo_fogcoord;
    for (int a = 0; a < list->maxtex; ++a)
        arrays->vbo_tex[a] = expanded.vbo_tex[a];
    return 1;
}

static void line_arrays_vbo_view(renderlist_t *view,
                                 const line_arrays_t *arrays,
                                 int maxtex)
{
    memset(view, 0, sizeof(*view));
    view->vert = arrays->vert;
    view->normal = arrays->normal;
    view->color = arrays->color;
    view->secondary = arrays->secondary;
    view->fogcoord = arrays->fogcoord;
    view->maxtex = maxtex;
    view->vbo_array = arrays->vbo_array;
    view->vbo_vert = arrays->vbo_vert;
    view->vbo_normal = arrays->vbo_normal;
    view->vbo_color = arrays->vbo_color;
    view->vbo_secondary = arrays->vbo_secondary;
    view->vbo_fogcoord = arrays->vbo_fogcoord;
    for (int a = 0; a < maxtex; ++a) {
        view->tex[a] = arrays->tex[a];
        view->vbo_tex[a] = arrays->vbo_tex[a];
    }
}

void draw_renderlist(renderlist_t *list) {
    if (!list) return;
    // go to 1st...
    while (list->prev) list = list->prev;
    // ok, go on now, draw everything
//printf("draw_renderlist %p, size=%i, mode=%s(%s), ilen=%d, next=%p, color=%p, secondarycolor=%p fogcoord=%p\n", list, list->len, PrintEnum(list->mode), PrintEnum(list->mode_init), list->ilen, list->next, list->color, list->secondary, list->fogcoord);
    LOAD_GLES_FPE(glDrawArrays);
    LOAD_GLES_FPE(glDrawElements);
    LOAD_GLES_FPE(glVertexPointer);
    LOAD_GLES_FPE(glNormalPointer);
    LOAD_GLES_FPE(glColorPointer);
    LOAD_GLES_FPE(glTexCoordPointer);
    LOAD_GLES_FPE(glEnable);
    LOAD_GLES_FPE(glDisable);
    gl4es_glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

	int old_tex;
    GLushort *indices;
    int use_texgen[MAX_TEX] = {0};
    old_tex = glstate->texture.client;
    GLuint cur_tex = old_tex;
    GLint needclean[MAX_TEX] = {0};
    bool stipple;
    int stipple_tmu;
    GLenum stipple_env;
    GLenum stipple_afunc;
    GLfloat stipple_aref;
    int stipple_tex2d;
    int stipple_alpha;
    int stipple_old;
    int stipple_texgen[4];
    
    do {
        // close if needed!
        if (list->open)
            list = end_renderlist(list);
        // push/pop attributes
        if (list->pushattribute)
            gl4es_glPushAttrib(list->pushattribute);
        if (list->popattribute)
            gl4es_glPopAttrib();
        call_list_t *cl = &list->calls;
        if (cl->len > 0) {
            for (int i = 0; i < cl->len; i++) {
                glPackedCall(cl->calls[i]);
            }
        }
        if(list->render_op) {
            switch(list->render_op) {
                case 1: gl4es_glInitNames(); break;
                case 2: gl4es_glPopName(); break;
                case 3: gl4es_glPushName(list->render_arg); break;
                case 4: gl4es_glLoadName(list->render_arg); break;
            }
        }
        if (list->fog_op) {
            gl4es_glFogfv(GL_FOG_COLOR, list->fog_val);
        }
        if (list->pointparam_op) {
            switch (list->pointparam_op) {
                case 1: // GL_POINT_DISTANCE_ATTENUATION 
                    gl4es_glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION , list->pointparam_val);
                    break;
            }
        }
        if (list->pointsize_op) {
            gl4es_glPointSize(list->pointsize_val);
        }
        if (list->matrix_op) {
            switch (list->matrix_op) {
                case 1: // load
                    gl4es_glLoadMatrixf(list->matrix_val);
                    break;
                case 2: // mult
                    gl4es_glMultMatrixf(list->matrix_val);
                    break;
            }
        }
        if (list->set_tmu) {
            gl4es_glActiveTexture(GL_TEXTURE0+list->tmu);
        }
	    if (list->set_texture) {
            gl4es_glBindTexture(list->target_texture, list->texture);
        }
        // raster
        if (list->raster_op) {
            if (list->raster_op==1) {
                gl4es_glRasterPos3f(list->raster_xyz[0], list->raster_xyz[1], list->raster_xyz[2]);
            } else if (list->raster_op==2) {
                gl4es_glWindowPos3f(list->raster_xyz[0], list->raster_xyz[1], list->raster_xyz[2]);
            } else if (list->raster_op==3) {
                gl4es_glPixelZoom(list->raster_xyz[0], list->raster_xyz[1]);
            } else if ((list->raster_op&0x10000) == 0x10000) {
                gl4es_glPixelTransferf(list->raster_op&0xFFFF, list->raster_xyz[0]);
            }
        }
        if (list->raster) {
            rasterlist_t * r = list->raster;
            //glBitmap(r->width, r->height, r->xorig, r->yorig, r->xmove, r->ymove, r->raster);
            render_raster_list(list->raster);
        }
		// bitmaps
        if (list->bitmaps) {
            for (int i=0; i<list->bitmaps->count; i++) {
                bitmap_list_t *l = &list->bitmaps->list[i];
                gl4es_glBitmap(l->width, l->height, l->xorig, l->yorig, l->xmove, l->ymove, l->bitmap);
            }
        }

        if (list->material) {
            khash_t(material) *map = list->material;
            rendermaterial_t *m;
            kh_foreach_value(map, m,
                switch (m->pname) {
                    case GL_SHININESS:
                        gl4es_glMaterialf(m->face,  m->pname, m->color[0]);
                        break;
                    default:
                        gl4es_glMaterialfv(m->face, m->pname, m->color);
                }
            )
        }
        if (list->colormat_face)
            gl4es_glColorMaterial(list->colormat_face, list->colormat_mode);
        if (list->light) {
            khash_t(light) *lig = list->light;
            renderlight_t *m;
            kh_foreach_value(lig, m,
                switch (m->pname) {
                    default:
                        gl4es_glLightfv(m->which, m->pname, m->color);
                }
            )
        }
        if (list->lightmodel) {
            gl4es_glLightModelfv(list->lightmodelparam, list->lightmodel);
        }

        if (list->linestipple_op) {
            gl4es_glLineStipple(list->linestipple_factor, list->linestipple_pattern);
        }
		
        if (list->texenv) {
            khash_t(texenv) *tgn = list->texenv;
            rendertexenv_t *m;
            kh_foreach_value(tgn, m,
                gl4es_glTexEnvfv(m->target, m->pname, m->params);
            )
        }

        if (list->texgen) {
            khash_t(texgen) *tgn = list->texgen;
            rendertexgen_t *m;
            kh_foreach_value(tgn, m,
                gl4es_glTexGenfv(m->coord, m->pname, m->color);
            )
        }
        
        if (list->polygon_mode) {
            gl4es_glPolygonMode(GL_FRONT_AND_BACK, list->polygon_mode);
        }

        if (! list->len)
            continue;

        int use_vbo_array = list->use_vbo_array;
        if(!use_vbo_array && (hardext.esversion==1 || globals4es.usevbo==0 || !list->name)) {
            use_vbo_array = 1;
        }
        int use_vbo_indices = list->use_vbo_indices;
        if(!use_vbo_indices &&  (hardext.esversion==1 || globals4es.usevbo==0 || !list->name)) {
            use_vbo_indices = 1;
        }
        indices = list->indices;
        line_arrays_t transient_line_arrays = {0};
        line_arrays_t *line_arrays = &transient_line_arrays;
        int use_line_arrays = 0;
        if (LINE_ARRAYS && hardext.esversion > 1 && glstate->render_mode != GL_SELECT &&
                glstate->polygon_mode == GL_LINE &&
                list->mode_init >= GL_TRIANGLES) {
            int source_count = indices ? list->ilen : list->len;
            if (!list->ind_lines) {
                list->ind_lines = (GLushort *)malloc(
                    sizeof(GLushort) * (source_count * 4 + 2));
                if (list->ind_lines) {
                    modeinit_t tmp;
                    tmp.mode_init = list->mode_init;
                    tmp.ilen = source_count;
                    tmp.vlen = list->len;
                    int ef_k = -1;
                    if (list->edgeflag)
                        ef_k = build_lineIndices_edgeflag(
                            list->mode_inits ? list->mode_inits : &tmp,
                            list->mode_inits ? list->mode_init_len : 1,
                            list->len, list->edgeflag, list->ind_lines);
                    list->ind_line = (ef_k >= 0) ? ef_k : fill_lineIndices(
                        list->mode_inits ? list->mode_inits : &tmp,
                        list->mode_inits ? list->mode_init_len : 1,
                        list->mode, indices, list->ind_lines);
                }
            }
            if (list->ind_lines && list->ind_line > 0 &&
                    list->line_arrays_cacheable) {
                if (!list->line_arrays) {
                    line_arrays_t *cached = (line_arrays_t *)calloc(
                        1, sizeof(line_arrays_t));
                    if (cached && build_line_arrays(
                            cached, list, list->ind_lines, list->ind_line)) {
                        list->line_arrays = cached;
                    } else
                        free(cached);
                }
                if (list->line_arrays) {
                    line_arrays = list->line_arrays;
                    use_line_arrays = 1;
                }
            }
            if (!use_line_arrays && list->ind_lines && list->ind_line > 0)
                use_line_arrays = build_line_arrays(
                    line_arrays, list, list->ind_lines, list->ind_line);
            if (use_line_arrays)
                use_vbo_array = 1;
        }
        GLfloat *draw_vert = use_line_arrays ? line_arrays->vert : list->vert;
        GLfloat *draw_normal = use_line_arrays ? line_arrays->normal : list->normal;
        GLfloat *draw_color = use_line_arrays ? line_arrays->color : list->color;
        GLfloat *draw_secondary = use_line_arrays ? line_arrays->secondary : list->secondary;
        GLfloat *draw_fogcoord = use_line_arrays ? line_arrays->fogcoord : list->fogcoord;
        int draw_vert_stride = use_line_arrays ? 0 : list->vert_stride;
        int draw_normal_stride = use_line_arrays ? 0 : list->normal_stride;
        int draw_color_stride = use_line_arrays ? 0 : list->color_stride;
        int draw_secondary_stride = use_line_arrays ? 0 : list->secondary_stride;
        int draw_fogcoord_stride = use_line_arrays ? 0 : list->fogcoord_stride;

        if (draw_vert) {
            fpe_glEnableClientState(GL_VERTEX_ARRAY);
            gles_glVertexPointer(4, GL_FLOAT, draw_vert_stride, draw_vert);
        } else {
            fpe_glDisableClientState(GL_VERTEX_ARRAY);
        }

        if (draw_normal) {
            fpe_glEnableClientState(GL_NORMAL_ARRAY);
            gles_glNormalPointer(GL_FLOAT, draw_normal_stride, draw_normal);
        } else {
            fpe_glDisableClientState(GL_NORMAL_ARRAY);
        }

        if(glstate->raster.bm_drawing)
            bitmap_flush();
        if (draw_color) {
            fpe_glEnableClientState(GL_COLOR_ARRAY);
            if (glstate->enable.color_sum && (list->secondary) && hardext.esversion==1 && !list->use_glstate) {
                if(!list->final_colors) {
                    list->final_colors=(GLfloat*)malloc(list->len * 4 * sizeof(GLfloat));
                    if (indices) {
                        for (int i=0; i<list->ilen; i++)
                            for (int j=0; j<4; j++) {
                                const int k=indices[i]*4+j;
                                list->final_colors[k]=list->color[k] + list->secondary[k];
                            }
                    } else {
                        for (int i=0; i<list->len*4; i++)
                            list->final_colors[i]=list->color[i] + list->secondary[i];
                    }
                }
                gles_glColorPointer(4, GL_FLOAT, 0, list->final_colors);
            } else {
//printf("colors=%f, %f, %f, %f / %f, %f, %f, %f\n", list->color[0],list->color[1],list->color[2],list->color[3], list->color[4],list->color[5],list->color[6],list->color[7]);
                gles_glColorPointer(4, GL_FLOAT, draw_color_stride, draw_color);
            }
        } else {
            fpe_glDisableClientState(GL_COLOR_ARRAY);
        }
        if(hardext.esversion > 1) {
            // secondary color only on ES2+
            if (glstate->enable.color_sum && draw_secondary) {
                fpe_glEnableClientState(GL_SECONDARY_COLOR_ARRAY);
                fpe_glSecondaryColorPointer(4, GL_FLOAT, draw_secondary_stride, draw_secondary);
            } else {
                fpe_glDisableClientState(GL_SECONDARY_COLOR_ARRAY);
            }
            // fog coord only on ES2+
            if ((glstate->fog.coord_src==GL_FOG_COORD) && draw_fogcoord) {
                fpe_glEnableClientState(GL_FOG_COORD_ARRAY);
                fpe_glFogCoordPointer(GL_FLOAT, draw_fogcoord_stride, draw_fogcoord);
            } else {
                fpe_glDisableClientState(GL_FOG_COORD_ARRAY);
            }
        }
        #define TEXTURE(A) if (cur_tex!=A) {gl4es_glClientActiveTexture(A+GL_TEXTURE0); cur_tex=A;}
        stipple = false;
        if ((list->mode == GL_LINES || list->mode == GL_LINE_STRIP || list->mode == GL_LINE_LOOP)
                && glstate->enable.line_stipple) {
            stipple = true;
            if(get_target(glstate->enable.texture[0])!=-1)
                stipple_tmu = 1;
            else
                stipple_tmu = 0;
        }
        if (stipple) {
            if(!use_vbo_array) use_vbo_array = 1;
            stipple_old = glstate->gleshard->active;
            if(glstate->gleshard->active!=stipple_tmu) {
                LOAD_GLES(glActiveTexture);
                gl4es_glActiveTexture(GL_TEXTURE0+stipple_tmu);
            }
            TEXTURE(stipple_tmu);
            GLenum matmode;
            gl4es_glGetIntegerv(GL_MATRIX_MODE, (GLint *) &matmode);
            gl4es_glMatrixMode(GL_TEXTURE);
            gl4es_glPushMatrix();
            gl4es_glLoadIdentity();
            gl4es_glMatrixMode(matmode);
            stipple_env = glstate->texenv[stipple_tmu].env.mode;
            gl4es_glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            stipple_tex2d = gl4es_glIsEnabled(GL_TEXTURE_2D);
            stipple_alpha = gl4es_glIsEnabled(GL_ALPHA_TEST);
            gl4es_glEnable(GL_TEXTURE_2D);
            gl4es_glEnable(GL_ALPHA_TEST);
            for (int k=0; k<4; k++) {
                stipple_texgen[k] = gl4es_glIsEnabled(GL_TEXTURE_GEN_S+k);
                if(stipple_texgen[k])
                    gl4es_glDisable(GL_TEXTURE_GEN_S+k);
            }
            stipple_afunc = glstate->alphafunc;
            stipple_aref = glstate->alpharef;
            gl4es_glAlphaFunc(GL_GREATER, 0.0f);
            bind_stipple_tex();
            modeinit_t tmp; tmp.mode_init = list->mode_init; tmp.ilen=list->ilen?list->ilen:list->len;
            list->tex[stipple_tmu] = gen_stipple_tex_coords(list->vert, list->indices, list->mode_inits?list->mode_inits:&tmp, list->vert_stride, list->mode_inits?list->mode_init_len:1, (list->use_glstate)?(list->vert+8+stipple_tmu*4):NULL);
        }
        #define RS(A, len) if(glstate->texgenedsz[A]<len) {free(glstate->texgened[A]); glstate->texgened[A]=malloc(4*sizeof(GLfloat)*len); glstate->texgenedsz[A]=len; } use_texgen[A]=1
        // cannot use list->maxtex because some TMU can be using TexGen or point sprites...
        if(hardext.esversion==1) {
            for (int a=0; a<hardext.maxtex; a++) {
                if(glstate->enable.texture[a] || (stipple && a==stipple_tmu)) {
                    const GLint itarget = (stipple && a==stipple_tmu)?ENABLED_TEX2D:get_target(glstate->enable.texture[a]);
                    needclean[a]=0;
                    use_texgen[a]=0;
                    if ((glstate->enable.texgen_s[a] || glstate->enable.texgen_t[a] || glstate->enable.texgen_r[a]  || glstate->enable.texgen_q[a])) {
                        TEXTURE(a);
                        RS(a, list->len);
                        gen_tex_coords(list->vert, list->normal, &glstate->texgened[a], list->len, &needclean[a], a, (list->ilen<list->len)?indices:NULL, (list->ilen<list->len)?list->ilen:0);
                    } else if ((list->tex[a]==NULL) && !(list->mode==GL_POINT && glstate->texture.pscoordreplace[a])) {
                        RS(a, list->len);
                        gen_tex_coords(list->vert, list->normal, &glstate->texgened[a], list->len, &needclean[a], a, (list->ilen<list->len)?indices:NULL, (list->ilen<list->len)?list->ilen:0);
                    }
                    // adjust the tex_coord now if needed, even on texgened ones
                    gltexture_t *bound = glstate->texture.bound[a][itarget];
                    if((list->tex[a] || (use_texgen[a] && !needclean[a])) && ((!(globals4es.texmat || glstate->texture_matrix[a]->identity)) || (bound->adjust))) {
                        if(!use_texgen[a]) {
                            RS(a, list->len);
                            if(list->tex_stride[a]) {
                                GLfloat *src = list->tex[a];
                                GLfloat *dst = glstate->texgened[a];
				int stride = list->tex_stride[a]>>2;    // stride need to be a multiple of 4 (i.e. sizeof(GLfloat))
                                for (int ii=0; ii<list->len; ii++) {
                                    memcpy(dst, src, 4*sizeof(GLfloat));
                                    src+=stride;
                                    dst+=4;
                                }
                            } else
                                memcpy(glstate->texgened[a], list->tex[a], 4*sizeof(GLfloat)*list->len);
                        }
                        if (!(globals4es.texmat || glstate->texture_matrix[a]->identity))
                            tex_coord_matrix(glstate->texgened[a], list->len, getTexMat(a));
                        if (bound->adjust) {
                            tex_coord_npot(glstate->texgened[a], list->len, bound->width, bound->height, bound->nwidth, bound->nheight);
                        }
                    }
                }
                if ((list->tex[a] || (use_texgen[a] && !needclean[a]))/* && glstate->enable.texture[a]*/) {
                    TEXTURE(a);
                    fpe_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                    gles_glTexCoordPointer(4, GL_FLOAT, (use_texgen[a])?0:list->tex_stride[a], (use_texgen[a])?glstate->texgened[a]:list->tex[a]);
                } else {
                    if (glstate->gleshard->vertexattrib[ATT_MULTITEXCOORD0+a].enabled || (hardext.esversion!=1)) {   // optim for ES1.1 to avoid useless texture switch
                        TEXTURE(a);
                        fpe_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                    } 
//else if (!glstate->enable.texgen_s[a] && glstate->enable.texture[a]) printf("LIBGL: texture[%i] without TexCoord, mode=0x%04X (init=0x%04X), listlen=%i\n", a, list->mode, list->mode_init, list->len);
                    
                }
                if (!IS_TEX2D(glstate->enable.texture[a]) && (IS_ANYTEX(glstate->enable.texture[a]))) {
                    TEXTURE(a);
                    gl4es_glActiveTexture(GL_TEXTURE0+a);
                    realize_active();
                    gles_glEnable(GL_TEXTURE_2D);
                }
            }
        } else {
            // texture loop for ES2+ version
            for (int a=0; a<hardext.maxtex; a++) {
                GLfloat *draw_tex = use_line_arrays ? line_arrays->tex[a] : list->tex[a];
                if(draw_tex) {
                    TEXTURE(a);
                    fpe_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                    gles_glTexCoordPointer(4, GL_FLOAT,
                                           use_line_arrays ? 0 : list->tex_stride[a],
                                           draw_tex);
                } else {
                    TEXTURE(a);
                    fpe_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                }
            }
        }
        if (glstate->texture.client != old_tex) TEXTURE(old_tex);
        #undef RS
        #undef TEXTURE

        realize_textures(1);

        if(use_vbo_array==0) {
            if((glstate->render_mode == GL_SELECT) || (glstate->polygon_mode == GL_LINE) || (glstate->polygon_mode == GL_POINT))
                use_vbo_array = 1;
            else
                // evaluated, seems good to go !
                use_vbo_array = list2VBO(list);
        }
        if (use_line_arrays && list->line_arrays == line_arrays &&
                !line_arrays->vbo_array)
            line_arrays_to_vbo(line_arrays, list);
        save_vbo_t saved[NB_VA];
        if(use_vbo_array==2)
            listActiveVBO(list, saved);
        renderlist_t line_vbo_view;     // filled by line_arrays_vbo_view() when used
        save_vbo_t line_saved[NB_VA];
        int use_line_vbo = use_line_arrays && line_arrays->vbo_array;
        if (use_line_vbo) {
            line_arrays_vbo_view(&line_vbo_view, line_arrays, list->maxtex);
            listActiveVBO(&line_vbo_view, line_saved);
        }
        if(!use_line_arrays && list->use_vbo_array != use_vbo_array)
            list->use_vbo_array = use_vbo_array;
        
        GLenum mode;
        mode = list->mode;
        if ((glstate->polygon_mode == GL_LINE) && (mode>=GL_TRIANGLES))
			mode = GL_LINES;
		if ((glstate->polygon_mode == GL_POINT) && (mode>=GL_TRIANGLES))
			mode = GL_POINTS;

        if (use_line_arrays) {
            gl4es_mvp_save_t zbias_saved;
            int zbias = begin_polygon_line_zbias(1, &zbias_saved);
            if(list->instanceCount==1)
                gles_glDrawArrays(GL_LINES, 0, line_arrays->count);
            else {
                for (glstate->instanceID=0; glstate->instanceID<list->instanceCount; ++glstate->instanceID)
                    gles_glDrawArrays(GL_LINES, 0, line_arrays->count);
                glstate->instanceID = 0;
            }
            end_polygon_line_zbias(zbias, &zbias_saved);
        } else if (indices) {
            if (glstate->render_mode == GL_SELECT) {
                vertexattrib_t vtx = {0};
                vtx.pointer = list->vert;
                vtx.type = GL_FLOAT;
                vtx.normalized = GL_FALSE;
                vtx.size = 4;
                vtx.stride = 0;
                select_glDrawElements(&vtx, list->mode, list->ilen, GL_UNSIGNED_SHORT, indices);
                use_vbo_indices = 1;
            } else {
                GLuint old_index = wantBufferIndex(0);
                if (glstate->polygon_mode == GL_LINE && list->mode_init>=GL_TRIANGLES) {
                    int ilen = list->ilen;
                    if(!list->ind_lines) {
                        GLushort *ind_line = list->ind_lines = (GLushort*)malloc(sizeof(GLushort)*ilen*4+2);
                        modeinit_t tmp; tmp.mode_init = list->mode_init; tmp.ilen=list->ilen; tmp.vlen=list->len;
                        int ef_k = list->edgeflag ? build_lineIndices_edgeflag(list->mode_inits?list->mode_inits:&tmp, list->mode_inits?list->mode_init_len:1, list->len, list->edgeflag, list->ind_lines) : -1;
                        int k = (ef_k >= 0) ? ef_k : fill_lineIndices(list->mode_inits?list->mode_inits:&tmp, list->mode_inits?list->mode_init_len:1, list->mode, indices, list->ind_lines);
                        list->ind_line = k;
                    }
                    bindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                    {
                        gl4es_mvp_save_t zbias_saved;
                        int zbias = begin_polygon_line_zbias(1, &zbias_saved);
                        gles_glDrawElements(mode, list->ind_line, GL_UNSIGNED_SHORT, list->ind_lines);
                        end_polygon_line_zbias(zbias, &zbias_saved);
                    }
                    use_vbo_indices = 1;
                } else {
                    int vbo_indices = 0;
                    if(!use_vbo_indices) {
                        // create VBO for indices
                        LOAD_GLES2(glGenBuffers);
                        LOAD_GLES2(glBufferData);
                        gles_glGenBuffers(1, &list->vbo_indices);
                        bindBuffer(GL_ELEMENT_ARRAY_BUFFER, list->vbo_indices);
                        gles_glBufferData(GL_ELEMENT_ARRAY_BUFFER, list->ilen*sizeof(GLushort), indices, GL_STATIC_DRAW);
                        use_vbo_indices = 2;
                        vbo_indices = 1;
                    } else if(use_vbo_indices==2) {
                        bindBuffer(GL_ELEMENT_ARRAY_BUFFER, list->vbo_indices);
                        vbo_indices = 1;
                    } else
                        realize_bufferIndex();
                    if(list->instanceCount==1)
                        gles_glDrawElements(mode, list->ilen, GL_UNSIGNED_SHORT, vbo_indices?NULL:indices);
                    else {
                        for (glstate->instanceID=0; glstate->instanceID<list->instanceCount; ++glstate->instanceID)
                            gles_glDrawElements(mode, list->ilen, GL_UNSIGNED_SHORT, vbo_indices?NULL:indices);
                        glstate->instanceID = 0;
                    }
                }
                wantBufferIndex(old_index);
            }
        } else {
            if (glstate->render_mode == GL_SELECT) {	
                vertexattrib_t vtx = {0};
                vtx.pointer = list->vert;
                vtx.type = GL_FLOAT;
                vtx.size = 4;
                vtx.normalized = GL_FALSE;
                vtx.stride = 0;
                select_glDrawArrays(&vtx, list->mode, 0, list->len);
            } else {
                int len = list->len;
                if ((glstate->polygon_mode == GL_LINE) && (list->mode_init>=GL_TRIANGLES)) {
                    if(!list->ind_lines) {
                        GLushort *ind_line = list->ind_lines = (GLushort*)malloc(sizeof(GLushort)*len*4+2);
                        modeinit_t tmp; tmp.mode_init = list->mode_init; tmp.ilen=len; tmp.vlen=list->len;
                        int ef_k = list->edgeflag ? build_lineIndices_edgeflag(list->mode_inits?list->mode_inits:&tmp, list->mode_inits?list->mode_init_len:1, list->len, list->edgeflag, list->ind_lines) : -1;
                        int k = (ef_k >= 0) ? ef_k : fill_lineIndices(list->mode_inits?list->mode_inits:&tmp, list->mode_inits?list->mode_init_len:1, list->mode, NULL, list->ind_lines);
                        list->ind_line = k;
                    }
                    bindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                    {
                        gl4es_mvp_save_t zbias_saved;
                        int zbias = begin_polygon_line_zbias(1, &zbias_saved);
                        gles_glDrawElements(mode, list->ind_line, GL_UNSIGNED_SHORT, list->ind_lines);
                        end_polygon_line_zbias(zbias, &zbias_saved);
                    }
                } else {
                    if(list->instanceCount==1)
                        gles_glDrawArrays(mode, 0, len);
                    else {
                        for (glstate->instanceID=0; glstate->instanceID<list->instanceCount; ++glstate->instanceID)
                            gles_glDrawArrays(mode, 0, len);
                        glstate->instanceID = 0;
                    }
                }
            }
        }
        if(list->use_vbo_indices != use_vbo_indices)
            list->use_vbo_indices = use_vbo_indices;
        if(use_vbo_array==2)
            listInactiveVBO(list, saved);
        if(use_line_vbo)
            listInactiveVBO(&line_vbo_view, line_saved);
        if (use_line_arrays && line_arrays == &transient_line_arrays)
            clear_line_arrays(&transient_line_arrays);

        #define TEXTURE(A) if (cur_tex!=A) {gl4es_glClientActiveTexture(A+GL_TEXTURE0); cur_tex=A;}
        if(hardext.esversion==1)
            for (int a=0; a<hardext.maxtex; a++) {
                if (needclean[a]) {
                    TEXTURE(a);
                    gen_tex_clean(needclean[a], a);
                }
                if (!IS_TEX2D(glstate->enable.texture[a]) && (IS_ANYTEX(glstate->enable.texture[a]))) {
                    TEXTURE(a);
                    gles_glDisable(GL_TEXTURE_2D);
                }
            }
        if (glstate->texture.client!=old_tex)
            TEXTURE(old_tex);
        #undef TEXTURE

        if (stipple) {
            if(!list->use_glstate)   //TODO: avoid that malloc/free...
                free(list->tex[stipple_tmu]);
            list->tex[stipple_tmu]=NULL;
            LOAD_GLES(glActiveTexture);
            if(glstate->gleshard->active!=stipple_tmu)
                gl4es_glActiveTexture(GL_TEXTURE0+stipple_tmu);
            GLenum matmode;
            gl4es_glGetIntegerv(GL_MATRIX_MODE, (GLint *) &matmode);
            gl4es_glMatrixMode(GL_TEXTURE);
            gl4es_glPopMatrix();
            gl4es_glMatrixMode(matmode);
            gl4es_glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, stipple_env);
            gl4es_glAlphaFunc(stipple_afunc, stipple_aref);
            if(stipple_tex2d)
                gl4es_glEnable(GL_TEXTURE_2D);
            else
                gl4es_glDisable(GL_TEXTURE_2D);
            if(stipple_alpha)
                gl4es_glEnable(GL_ALPHA_TEST);
            else
                gl4es_glDisable(GL_ALPHA_TEST);
            for (int k=0; k<4; k++) {
                if(stipple_texgen[k])
                    gl4es_glEnable(GL_TEXTURE_GEN_S+k);
            }
            if(glstate->gleshard->active!=stipple_old)
                gl4es_glActiveTexture(GL_TEXTURE0+stipple_old);
        }
        if(list->post_color) gl4es_glColor4fv(list->post_colors);
        if(list->post_normal) gl4es_glNormal3fv(list->post_normals);
    } while ((list = list->next));
    gl4es_glPopClientAttrib();
}
