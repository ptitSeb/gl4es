#include "gl.h"

GLstate state = {.color = {1.0f, 1.0f, 1.0f, 1.0f}};

// config functions
const GLubyte *glGetString(GLenum name) {
    LOAD_GLES(const GLubyte *, glGetString, GLenum);
    switch (name) {
        case GL_VERSION:
#ifdef USE_ES2
            return (GLubyte *)"4.3 glshim wrapper";
#else
            return (GLubyte *)"1.4 glshim wrapper";
#endif
#ifdef USE_ES2
        case GL_EXTENSIONS:
            return (const GLubyte *)(char *){
                "GL_ARB_vertex_shader "
                "GL_ARB_fragment_shader "
                "GL_ARB_vertex_buffer_object "
                "GL_EXT_framebuffer_object "
            };
#endif
        default:
            return gles_glGetString(name);
    }
}

void glGetIntegerv(GLenum pname, GLint *params) {
    LOAD_GLES(void, glGetIntegerv, GLenum pname, GLint *params);
    switch (pname) {
        case GL_MAX_ELEMENTS_INDICES:
            *params = 1024;
            break;
        case GL_AUX_BUFFERS:
            *params = 0;
            break;
        default:
            gles_glGetIntegerv(pname, params);
    }
}

static void proxy_glEnable(GLenum cap, bool enable, void (*next)(GLenum)) {
    #define proxy_enable(constant, name) \
        case constant: state.enable.name = enable; next(cap); break
    #define enable(constant, name) \
        case constant: state.enable.name = enable; break;

    // TODO: maybe could be weird behavior if someone tried to:
    // 1. enable GL_TEXTURE_1D
    // 2. enable GL_TEXTURE_2D
    // 3. disable GL_TEXTURE_1D
    // 4. render. GL_TEXTURE_2D would be disabled.
    cap = map_tex_target(cap);

    switch (cap) {
        proxy_enable(GL_BLEND, blend);
        proxy_enable(GL_TEXTURE_2D, texture_2d);
        enable(GL_TEXTURE_GEN_S, texgen_s);
        enable(GL_TEXTURE_GEN_T, texgen_t);
        enable(GL_LINE_STIPPLE, line_stipple);

        // for glDrawArrays
        proxy_enable(GL_VERTEX_ARRAY, vertex_array);
        proxy_enable(GL_NORMAL_ARRAY, normal_array);
        proxy_enable(GL_COLOR_ARRAY, color_array);
        proxy_enable(GL_TEXTURE_COORD_ARRAY, tex_coord_array);
        default: next(cap); break;
    }
    #undef proxy_enable
    #undef enable
}

void glEnable(GLenum cap) {
    LOAD_GLES(void, glEnable, GLenum);
    proxy_glEnable(cap, true, gles_glEnable);
}

void glDisable(GLenum cap) {
    LOAD_GLES(void, glDisable, GLenum);
    proxy_glEnable(cap, false, gles_glDisable);
}

#ifndef USE_ES2
void glEnableClientState(GLenum cap) {
    LOAD_GLES(void, glEnableClientState, GLenum);
    proxy_glEnable(cap, true, gles_glEnableClientState);
}

void glDisableClientState(GLenum cap) {
    LOAD_GLES(void, glDisableClientState, GLenum);
    proxy_glEnable(cap, false, gles_glDisableClientState);
}
#endif

GLboolean glIsEnabled(GLenum cap) {
    LOAD_GLES(GLboolean, glIsEnabled, GLenum);
    switch (cap) {
        case GL_LINE_STIPPLE:
            return state.enable.line_stipple;
        case GL_TEXTURE_GEN_S:
            return state.enable.texgen_s;
        case GL_TEXTURE_GEN_T:
            return state.enable.texgen_t;
        default:
            return gles_glIsEnabled(cap);
    }
}

static RenderList *arrays_to_renderlist(RenderList *list, GLenum mode,
                                        GLsizei skip, GLsizei count) {
    if (! list)
        list = alloc_renderlist();

    list->mode = mode;
    list->len = count;
    list->cap = count;
    if (state.enable.vertex_array) {
        list->vert = copy_gl_pointer(&state.pointers.vertex, 3, count);
    }
    if (state.enable.color_array) {
        list->color = copy_gl_pointer(&state.pointers.color, 4, count);
    }
    if (state.enable.normal_array) {
        list->normal = copy_gl_pointer(&state.pointers.normal, 3, count);
    }
    if (state.enable.tex_coord_array) {
        list->tex = copy_gl_pointer(&state.pointers.tex_coord, 2, count);
    }

    end_renderlist(list);
    return list;
}

void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) {
    if (state.list.active && state.list.compiling) {
        GLushort *shortIndices = copy_gl_array(indices, type, 1, 0,
                                               GL_UNSIGNED_SHORT, 1, count);
        GLsizei max = 0;
        GLsizei min = -1;
        for (int i = 0; i < count; i++) {
            GLsizei n = shortIndices[i];
            if (! min)
                min = n;
            min = (n < min) ? n : min;
            max = (n > max) ? n : max;
        }
        RenderList *list = state.list.active = extend_renderlist(state.list.active);
        // TODO: skip via min?
        arrays_to_renderlist(list, mode, 0, max + 1);
        list->indices = shortIndices;
        list->len = count;
        return;
    }

    LOAD_GLES(void, glDrawElements, GLenum, GLsizei, GLenum, const GLvoid *);
    // TODO: do more than just thunk indices
    if (type == GL_UNSIGNED_INT) {
        // TODO: split for count > 65535?
        GLushort *shortIndices = copy_gl_array(indices, type, 1, 0,
                                               GL_UNSIGNED_SHORT, 1, count);
        gles_glDrawElements(mode, count, GL_UNSIGNED_SHORT, shortIndices);
        free(shortIndices);
    } else {
        gles_glDrawElements(mode, count, type, indices);
    }
}

void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    if (mode == GL_QUAD_STRIP)
        mode = GL_TRIANGLE_STRIP;

    RenderList *list;
    if (state.list.active && state.list.compiling) {
        list = state.list.active = extend_renderlist(state.list.active);
        arrays_to_renderlist(list, mode, first, count);
        return;
    }

    if (mode == GL_QUADS || (state.pointers.tex_coord.pointer && state.texture.rect_arb)) {
        list = arrays_to_renderlist(NULL, mode, first, count);
        draw_renderlist(list);
        free_renderlist(list);
    } else {
        LOAD_GLES(void, glDrawArrays, GLenum, GLint, GLsizei);
        gles_glDrawArrays(mode, first, count);
    }
}

#define clone_gl_pointer(t, s)\
    t.size = s; t.type = type; t.stride = stride; t.pointer = pointer;
void glVertexPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glVertexPointer, GLint, GLenum, GLsizei, const GLvoid *);
    clone_gl_pointer(state.pointers.vertex, size);
    gles_glVertexPointer(size, type, stride, pointer);
}
void glColorPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glColorPointer, GLint, GLenum, GLsizei, const GLvoid *);
    clone_gl_pointer(state.pointers.color, size);
    gles_glColorPointer(size, type, stride, pointer);
}
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glNormalPointer, GLenum, GLsizei, const GLvoid *);
    clone_gl_pointer(state.pointers.normal, 3);
    gles_glNormalPointer(type, stride, pointer);
}
void glTexCoordPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glTexCoordPointer, GLint, GLenum, GLsizei, const GLvoid *);
    clone_gl_pointer(state.pointers.tex_coord, size);
    gles_glTexCoordPointer(size, type, stride, pointer);
}
#undef clone_gl_pointer

void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer) {
    uintptr_t ptr = (uintptr_t)pointer;
    // element lengths
    GLsizei tex, color, normal, vert;
    // element formats
    GLenum tf, cf, nf, vf;
    tf = cf = nf = vf = GL_FLOAT;

    switch (format) {
        GL_V2F: vert = 2; break;
        GL_V3F: vert = 3; break;
        GL_C4UB_V2F:
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 2;
            break;
        GL_C4UB_V3F:
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 3;
            break;
        GL_C3F_V3F:
            color = 3;
            vert = 4;
            break;
        GL_N3F_V3F:
            normal = 3;
            vert = 3;
            break;
        GL_C4F_N3F_V3F:
            color = 4;
            normal = 3;
            vert = 3;
            break;
        GL_T2F_V3F:
            tex = 2;
            vert = 3;
            break;
        GL_T4F_V4F:
            tex = 4;
            vert = 4;
            break;
        GL_T2F_C4UB_V3F:
            tex = 2;
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 3;
            break;
        GL_T2F_C3F_V3F:
            tex = 2;
            color = 3;
            vert = 3;
            break;
        GL_T2F_N3F_V3F:
            tex = 2;
            normal = 3;
            vert = 3;
            break;
        GL_T2F_C4F_N3F_V3F:
            tex = 2;
            color = 4;
            normal = 3;
            vert = 3;
            break;
        GL_T4F_C4F_N3F_V4F:
            tex = 4;
            color = 4;
            normal = 4;
            vert = 4;
            break;
    }
    if (! stride)
        stride = tex * gl_sizeof(tf) +
                 color * gl_sizeof(cf) +
                 normal * gl_sizeof(nf) +
                 vert * gl_sizeof(vf);
    if (tex) {
        glTexCoordPointer(tex, tf, stride, (GLvoid *)ptr);
        ptr += tex * gl_sizeof(tf);
    }
    if (color) {
        glColorPointer(color, cf, stride, (GLvoid *)ptr);
        ptr += color * gl_sizeof(cf);
    }
    if (normal) {
        glNormalPointer(nf, stride, (GLvoid *)ptr);
        ptr += normal * gl_sizeof(nf);
    }
    if (vert)
        glVertexPointer(vert, vf, stride, (GLvoid *)ptr);
}

// immediate mode functions

void glBegin(GLenum mode) {
    if (! state.list.compiling) {
        state.list.active = alloc_renderlist();
    }
    memcpy(state.list.active->lastColor, state.color, sizeof(GLfloat) * 4);
    state.list.active->mode = mode;
}

void glEnd() {
    if (! state.list.active) return;

    end_renderlist(state.list.active);
    // render if we're not in a display list
    if (! state.list.compiling) {
        draw_renderlist(state.list.active);
        free_renderlist(state.list.active);
        state.list.active = NULL;
    } else {
        state.list.active = extend_renderlist(state.list.active);
    }
}

void glNormal3f(GLfloat x, GLfloat y, GLfloat z) {
    if (state.list.active) {
        rlNormal3f(state.list.active, x, y, z);
    } else {
        LOAD_GLES(void, glNormal3f, GLfloat, GLfloat, GLfloat);
        gles_glNormal3f(x, y, z);
    }
}

void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    if (state.list.active) {
        rlVertex3f(state.list.active, x, y, z);
    }
}

void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (state.list.active) {
        rlColor4f(state.list.active, r, g, b, a);
    } else {
        LOAD_GLES(void, glColor4f, GLfloat, GLfloat, GLfloat, GLfloat);
        gles_glColor4f(r, g, b, a);
        state.color[0] = r; state.color[1] = g;
        state.color[2] = b; state.color[3] = a;
    }
}

void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {
    LOAD_GLES(void, glMaterialfv, GLenum face, GLenum pname, const GLfloat *params);
    if (state.list.active) {
        rlMaterialfv(state.list.active, face, pname, params);
    } else {
        gles_glMaterialfv(face, pname, params);
    }
}

void glTexCoord2f(GLfloat s, GLfloat t) {
    if (state.list.active) {
        rlTexCoord2f(state.list.active, s, t);
    }
}

void glArrayElement(GLint i) {
    GLfloat *v;
    PointerState *p;
    p = &state.pointers.color;
    if (p->pointer) {
        v = gl_pointer_index(p, i);
        GLuint scale = gl_max_value(p->type);
        // color[3] defaults to 1.0f
        if (p->size < 4)
            v[3] = 1.0f;

        // scale color coordinates to a 0 - 1.0 range
        for (int i = 0; i < p->size; i++) {
            v[i] /= scale;
        }
        glColor4fv(v);
    }
    p = &state.pointers.normal;
    if (p->pointer) {
        v = gl_pointer_index(p, i);
        glNormal3fv(v);
    }
    p = &state.pointers.tex_coord;
    if (p->pointer) {
        v = gl_pointer_index(p, i);
        glTexCoord2fv(v);
    }
    p = &state.pointers.vertex;
    if (p->pointer) {
        v = gl_pointer_index(p, i);
        if (p->size == 4) {
            glVertex4fv(v);
        } else {
            glVertex3fv(v);
        }
    }
}

// TODO: store these on state
// display lists
RenderList **displayLists = NULL;
int listCount = 0;
int listCap = 0;

static RenderList *glGetList(GLuint list) {
    list -= 1;
    if (list < listCount) {
        return displayLists[list];
    }
    return NULL;
}

GLuint glGenLists(GLsizei range) {
    int start = listCount;
    if (displayLists == NULL) {
        listCap += range + 100;
        displayLists = malloc(listCap * sizeof(uintptr_t));
    } else if (listCount + range > listCap) {
        listCap += range + 100;
        displayLists = realloc(displayLists, listCap * sizeof(uintptr_t));
    }
    listCount += range;

    for (int i = 0; i < range; i++) {
        displayLists[start+i] = NULL;
    }
    return start + 1;
}

void glNewList(GLuint list, GLenum mode) {
    if (list > listCount) return;
    state.list.mode = mode;
    state.list.name = list;

    RenderList *l = glGetList(list);
    if (l) {
        printf("newList already exists: %i. not implemented.\n", list);
        // TODO: what do we do if the list already exists?
        // iirc it's in the GL spec
        return;
    } else {
        // TODO: if state.list.active is already defined, we probably need to clean up here
        state.list.active = displayLists[list-1] = alloc_renderlist();
        state.list.compiling = true;
    }
}

void glEndList() {
    GLuint list = state.list.name;
    if (state.list.compiling) {
        state.list.compiling = false;
        state.list.active = NULL;
        if (state.list.mode == GL_COMPILE_AND_EXECUTE) {
            glCallList(list);
        }
    }
}

void glCallList(GLuint list) {
    // TODO: this call can be compiled into another display list
    RenderList *l = glGetList(list);
    if (l) {
        draw_renderlist(l);
    }
}

void glPushCall(void *call) {
    if (state.list.compiling && state.list.active) {
        rlPushCall(state.list.active, call);
    }
}

void glCallLists(GLsizei n, GLenum type, const GLvoid *lists) {
    #define call(name, type)\
        case name: glCallList(((type *)lists)[i] + state.list.base); break

    // seriously wtf
    #define call_bytes(name, stride)\
        case name:\
            l = (GLubyte *)lists;\
            list = 0;\
            for (j = 0; j < stride; j++) {\
                list += *(l + (i * stride + j)) << (stride - j);\
            }\
            glCallList(list + state.list.base);\
            break

    unsigned int i, j;
    GLuint list;
    GLubyte *l;
    for (i = 0; i < n; i++) {
        switch (type) {
            call(GL_BYTE, GLbyte);
            call(GL_UNSIGNED_BYTE, GLubyte);
            call(GL_SHORT, GLshort);
            call(GL_UNSIGNED_SHORT, GLushort);
            call(GL_INT, GLint);
            call(GL_UNSIGNED_INT, GLuint);
            call(GL_FLOAT, GLfloat);
            call_bytes(GL_2_BYTES, 2);
            call_bytes(GL_3_BYTES, 3);
            call_bytes(GL_4_BYTES, 4);
        }
    }
    #undef call
    #undef call_bytes
}

void glDeleteList(GLuint list) {
    RenderList *l = glGetList(list);
    if (l) {
        free_renderlist(l);
        displayLists[list-1] = NULL;
    }

    // lists just grow upwards, maybe use a better storage mechanism?
}

void glDeleteLists(GLuint list, GLsizei range) {
    int i;
    for (i = 0; i < range; i++) {
        glDeleteList(list+i);
    }
}

void glListBase(GLuint base) {
    state.list.base = base;
}

GLboolean glIsList(GLuint list) {
    if (glGetList(list)) {
        return true;
    }
    return false;
}
