#include "gl.h"
#include "list.h"

#define alloc_sublist(n, cap) \
    (GLfloat *)malloc(n * sizeof(GLfloat) * cap)

#define realloc_sublist(ref, n, cap) \
    if (ref)                         \
        ref = (GLfloat *)realloc(ref, n * sizeof(GLfloat) * cap)

renderlist_t *alloc_renderlist() {
    int a;

    renderlist_t *list = (renderlist_t *)malloc(sizeof(renderlist_t));
    list->len = 0;
    list->ilen = 0;
    list->cap = DEFAULT_RENDER_LIST_CAPACITY;

    list->calls.len = 0;
    list->calls.cap = 0;
    list->calls.calls = NULL;

    list->mode = 0;
    list->mode_init = 0;
    list->shared_arrays = false;
    list->vert = NULL;
    list->normal = NULL;
    list->color = NULL;
    list->secondary = NULL;

    list->glcall_list = 0;
    list->raster = NULL;
    
    list->stage = STAGE_NONE;
    
    list->pushattribute = 0;
    list->popattribute = false;
    
    list->raster_op = 0;
    for (a=0; a<3; a++)
        list->raster_xyz[a]=0.0f;
        
    list->matrix_op = 0;
    for (a=0; a<16; a++)
        list->matrix_val[a]=((a%4)==0)?1.0f:0.0f;    // load identity matrix
    
    for (a=0; a<MAX_TEX; a++)
       list->tex[a] = NULL;
    list->material = NULL;
    list->light = NULL;
    list->texgen = NULL;
    list->lightmodel = NULL;
    list->lightmodelparam = GL_LIGHT_MODEL_AMBIENT;
    list->indices = NULL;
    list->indice_cap = 0;
    list->set_texture = false;
    list->texture = 0;
    list->target_texture = GL_TEXTURE_2D;
    list->polygon_mode = 0;
    list->fog_op = 0;
    
    list->prev = NULL;
    list->next = NULL;
    list->open = true;
    return list;
}

bool ispurerender_renderlist(renderlist_t *list) {
    // return true if renderlist contains only rendering command, no state changes
    if (list->calls.len)
        return false;
    if (list->glcall_list)
        return false;
    if (list->matrix_op)
        return false;
    if (list->raster_op)
        return false;
    if (list->raster)
        return false;
    if (list->pushattribute)
        return false;
    if (list->popattribute)
        return false;
    if (list->material || list->light || list->lightmodel)
        return false;
    if (list->fog_op)
        return false;
    if (list->texgen)
        return false;
    if (list->mode_init == 0)
        return false;
    
    return true;
}

int rendermode_dimensions(GLenum mode) {
    // return 1 for points, 2 for any lines, 3 for any triangles, 4 for any Quad and 5 for polygon
    switch (mode) {
        case GL_POINTS:
            return 1;
        case GL_LINES:
        case GL_LINE_LOOP:
        case GL_LINE_STRIP:
            return 2;
        case GL_TRIANGLES:
        case GL_TRIANGLE_FAN:
        case GL_TRIANGLE_STRIP:
            return 3;
        case GL_QUADS:
        case GL_QUAD_STRIP:
            return 4;
        case GL_POLYGON:
            return 5;
    }
    return 0;
}

extern GLuint gl_mergelist;

bool islistscompatible_renderlist(renderlist_t *a, renderlist_t *b) {
    if (!gl_mergelist)
        return false;
        
    // check if 2 "pure rendering" list are compatible for merge
    if (a->mode_init != b->mode_init) {
        int a_mode = rendermode_dimensions(a->mode_init);
        int b_mode = rendermode_dimensions(b->mode_init);
        if ((a_mode == 5) || (b_mode == 5))
            return false;       // Let's not merge polygons
        if ((a_mode == 0) || (b_mode == 0))
            return false;       // undetermined is not good
        if (a_mode == 4) a_mode = 3; // quads are handled as triangles
        if (b_mode == 4) b_mode = 3;
        if (a_mode != b_mode)
            return false;
    }
/*    if ((a->indices==NULL) != (b->indices==NULL))
        return false;*/
    if (a->polygon_mode != b->polygon_mode)
        return false;
    if ((a->vert==NULL) != (b->vert==NULL))
        return false;
    if ((a->normal==NULL) != (b->normal==NULL))
        return false;
    if ((a->color==NULL) != (b->color==NULL))
        return false;
    if ((a->secondary==NULL) != (b->secondary==NULL))
        return false;
    // check the textures
    for (int i=0; i<MAX_TEX; i++)
        if ((a->tex[i]==NULL) != (b->tex[i]==NULL))
            return false;
    if ((a->set_texture==b->set_texture) && ((a->texture != b->texture) || (a->target_texture != b->target_texture)))
        return false;
    if (!a->set_texture && b->set_texture)
        return false;
    // polygon mode
    if(a->polygon_mode!=b->polygon_mode)
        return false;
        
    // Check the size of a list, if it"s too big, don't merge...
    if ((a->len+b->len)>30000)
        return false;
    if ((a->ilen+b->ilen)>30000)
        return false;
    
    return true;
}

void renderlist_createindices(renderlist_t *a, GLushort *indices, int count) {
    int ilen = a->len;
    for (int i = 0; i<ilen; i++) {
        indices[i] = i+count;
    }
}

#define vind(a) (((ind)?ind[(a)]:(a))+count)

void renderlist_lineloop_lines(renderlist_t *a, GLushort *indices, int count) {
    GLushort *ind = a->indices;
    int len = (ind)? a->ilen:a->len;
    int ilen = len*2;  // new size is 2* + return
    for (int i = 0; i<ilen-1; i++) {
        indices[i] = vind((i+1)/2);
    }
    // go back to initial point
    indices[ilen-1] = indices[0];
}

void renderlist_linestrip_lines(renderlist_t *a, GLushort *indices, int count) {
    GLushort *ind = a->indices;
    int len = (ind)? a->ilen:a->len;
    int ilen = len*2-2;  // new size is 2*
    if (ilen<0) ilen=0;
    for (int i = 0; i<ilen; i++) {
        indices[i] = vind((i+1)/2);
    }
}

void renderlist_triangletrip_triangles(renderlist_t *a, GLushort *indices, int count) {
    GLushort *ind = a->indices;
    int len = (ind)? a->ilen:a->len;
    int ilen = (len-2)*3;  
    if (ilen<0) ilen=0;
    for (int i = 2; i<len; i++) {
        indices[(i-2)*3+(i%2)] = vind(i-2);
        indices[(i-2)*3+1-(i%2)] = vind(i-1);
        indices[(i-2)*3+2] = vind(i);
    }
}

void renderlist_trianglefan_triangles(renderlist_t *a, GLushort *indices, int count) {
    GLushort *ind = a->indices;
    int len = (ind)? a->ilen:a->len;
    int ilen = (len-2)*3;  
    if (ilen<0) ilen=0;
    for (int i = 2; i<len; i++) {
        indices[(i-2)*3+0] = vind(0);
        indices[(i-2)*3+1] = vind(i-1);
        indices[(i-2)*3+2] = vind(i);
    }
}

void renderlist_quads_triangles(renderlist_t *a, GLushort *indices, int count) {
    GLushort *ind = a->indices;
    int len = (ind)? a->ilen:a->len;
    // len must be a multiple of 4 !
    len &= ~3;  // discard extra vertex...
    int ilen = len*3/2;
    for (int i=0, j=0; i+3<len; i+=4, j+=6) {
        indices[j+0] = vind(i+0);
        indices[j+1] = vind(i+1);
        indices[j+2] = vind(i+2);

        indices[j+3] = vind(i+0);
        indices[j+4] = vind(i+2);
        indices[j+5] = vind(i+3);
    }
}
#undef vind
#define vind(a) ((ind)?ind[(a)]:(a))
void renderlist_quads2triangles(renderlist_t *a) {
    GLushort *ind = a->indices;
    int len = (ind)? a->ilen:a->len;
    // len must be a multiple of 4 !
    len &= ~3;  // discard extra vertex...
    int ilen = len*3/2;
    a->indices = (GLushort*)malloc(ilen*sizeof(GLushort));
    for (int i=0, j=0; i+3<len; i+=4, j+=6) {
        a->indices[j+0] = vind(i+0);
        a->indices[j+1] = vind(i+1);
        a->indices[j+2] = vind(i+2);

        a->indices[j+3] = vind(i+0);
        a->indices[j+4] = vind(i+2);
        a->indices[j+5] = vind(i+3);
    }
    a->ilen = ilen;
    if ((ind) && !a->shared_arrays) free(ind);
    a->mode = GL_TRIANGLES;
}
#undef vind

int renderlist_getindicesize(renderlist_t *a) {
    int ilen_a;
    switch (a->mode) {
        case GL_LINE_LOOP:
            ilen_a = (((a->indices)? a->ilen:a->len)-2)*3;
            if (ilen_a<0) ilen_a=1; // special borked case...
            break;
        case GL_LINE_STRIP:
            ilen_a = (((a->indices)? a->ilen:a->len)*2)-2;
            if (ilen_a<0) ilen_a=1; // special borked case...
            break;
        case GL_QUAD_STRIP:
        case GL_TRIANGLE_STRIP:
            ilen_a = (((a->indices)? a->ilen:a->len)-2)*3;
            if (ilen_a<0) ilen_a=1; // special borked case...
            break;
        case GL_TRIANGLE_FAN:
        case GL_POLYGON:
            ilen_a = (((a->indices)? a->ilen:a->len)-2)*3;
            if (ilen_a<0) ilen_a=1; // special borked case...
            break;
        case GL_QUADS:
            ilen_a = ((((a->indices)? a->ilen:a->len)&~3)*3)/2;
            break;
        default:
            ilen_a = a->ilen;
            break;
    }
    return ilen_a;
}
void append_renderlist(renderlist_t *a, renderlist_t *b) {
    // append all draw elements of b in a
    
    // check the final indice size of a and b
    int ilen_a = renderlist_getindicesize(a);
    int ilen_b = renderlist_getindicesize(b);
    // lets append all the arrays
    unsigned long cap = a->cap;
    if (a->len + b->len >= cap) cap += b->cap + DEFAULT_RENDER_LIST_CAPACITY;
    if (a->shared_arrays) {
        // Unshare if shared (shared array are not used for now)
        a->cap = cap;
        GLfloat *tmp;
        tmp = a->vert;
        if (tmp) {
            a->vert = alloc_sublist(3, cap);
            memcpy(a->vert, tmp, 3*a->len*sizeof(GLfloat));
        }
        tmp = a->normal;
        if (tmp) {
            a->normal = alloc_sublist(3, cap);
            memcpy(a->normal, tmp, 3*a->len*sizeof(GLfloat));
        }
        tmp = a->color;
        if (tmp) {
            a->color = alloc_sublist(4, cap);
            memcpy(a->color, tmp, 4*a->len*sizeof(GLfloat));
        }
        tmp = a->secondary;
        if (tmp) {
            a->secondary = alloc_sublist(4, cap);
            memcpy(a->secondary, tmp, 4*a->len*sizeof(GLfloat));
        }
        for (int i=0; i<MAX_TEX; i++) {
            tmp = a->tex[i];
            if (tmp) {
                a->tex[i] = alloc_sublist(2, cap);
                memcpy(a->tex[i], tmp, 2*a->len*sizeof(GLfloat));
            }
        }
        if (a->indices) {
            GLushort* tmpi = a->indices;
            a->indice_cap = ((ilen_a)?ilen_a:a->len) + ((ilen_b)?ilen_b:b->len);
            if (a->indice_cap > 48) a->indice_cap = (a->indice_cap+511)&~511;
            a->indices = (GLushort*)malloc(a->indice_cap*sizeof(GLushort));
            memcpy(a->indices, tmpi, a->ilen*sizeof(GLushort));
        }
        a->shared_arrays = false;
    } else {
        if (a->cap < cap) {
            a->cap = cap;
            if (a->vert)    realloc_sublist(a->vert, 3, cap);
            if (a->normal)  realloc_sublist(a->normal, 3, cap);
            if (a->color)   realloc_sublist(a->color, 4, cap);
            if (a->secondary) realloc_sublist(a->secondary, 4, cap);
            for (int i=0; i<MAX_TEX; i++)
               if (a->tex[i]) realloc_sublist(a->tex[i], 2, cap);
        }
    }
    // append arrays
    if (a->vert) memcpy(a->vert+a->len*3, b->vert, b->len*3*sizeof(GLfloat));
    if (a->normal) memcpy(a->normal+a->len*3, b->normal, b->len*3*sizeof(GLfloat));
    if (a->color) memcpy(a->color+a->len*4, b->color, b->len*4*sizeof(GLfloat));
    if (a->secondary) memcpy(a->secondary+a->len*4, b->secondary, b->len*4*sizeof(GLfloat));
    for (int i=0; i<MAX_TEX; i++)
        if (a->tex[i]) memcpy(a->tex[i]+a->len*2, b->tex[i], b->len*2*sizeof(GLfloat));
    
    // indices
    if (ilen_a + ilen_b)
    {
        // alloc or realloc a->indices first...
        int capindices = ((ilen_a)?ilen_a:a->len) + ((ilen_b)?ilen_b:b->len);
        if (capindices > 48) capindices = (capindices+511)&~511;
        #define alloc_a_indices                                      \
        newind=(GLushort*)malloc(capindices*sizeof(GLushort))
        #define copy_a_indices                                       \
        if (a->indices) free(a->indices);                            \
        a->indices = newind;                                         \
        a->indice_cap = capindices
        // check if "a" needs to be converted
        GLushort *newind=NULL;
        switch (a->mode) {
            case GL_LINE_LOOP:
                alloc_a_indices;
                renderlist_lineloop_lines(a, newind, 0);
                a->mode = GL_LINES;
                copy_a_indices;
                break;
            case GL_LINE_STRIP:
                alloc_a_indices;
                renderlist_linestrip_lines(a, newind, 0);
                a->mode = GL_LINES;
                copy_a_indices;
                break;
            case GL_QUAD_STRIP:
            case GL_TRIANGLE_STRIP:
                alloc_a_indices;
                renderlist_triangletrip_triangles(a, newind, 0);
                a->mode = GL_TRIANGLES;
                copy_a_indices;
                break;
            case GL_TRIANGLE_FAN:
            case GL_POLYGON:
                alloc_a_indices;
                renderlist_trianglefan_triangles(a, newind, 0);
                a->mode = GL_TRIANGLES;
                copy_a_indices;
                break;
            case GL_QUADS:
                alloc_a_indices;
                renderlist_quads_triangles(a, newind, 0);
                a->mode = GL_TRIANGLES;
                copy_a_indices;
                break;
            default:
                if (!ilen_a) {
                    // no a->indices, must alloc and fill one
                    alloc_a_indices;
                    renderlist_createindices(a, newind, 0);
                    ilen_a = a->len;
                    copy_a_indices;
                } else {
                    // a->indices already exist, just check if need to adjust its size
                    if (a->indice_cap < capindices) {
                        a->indices = (GLushort*)realloc(a->indices, capindices*sizeof(GLushort));
                        a->indice_cap = capindices;
                    }
                }
                break;
        }
        #undef copy_a_indices
        #undef alloc_a_indices

        a->ilen = ilen_a;
        // then append b
        switch (b->mode) {
            case GL_LINE_LOOP:
                renderlist_lineloop_lines(b, a->indices + ilen_a, a->len);
                break;
            case GL_LINE_STRIP:
                renderlist_linestrip_lines(b, a->indices + ilen_a, a->len);
                break;
            case GL_QUAD_STRIP:
            case GL_TRIANGLE_STRIP:
                renderlist_triangletrip_triangles(b, a->indices + ilen_a, a->len);
                break;
            case GL_TRIANGLE_FAN:
            case GL_POLYGON:
                renderlist_trianglefan_triangles(b, a->indices + ilen_a, a->len);
                break;
            case GL_QUADS:
                renderlist_quads_triangles(b, a->indices + ilen_a, a->len);
                break;
            default:
                // no transform here, just take (or create) the indice list as-is
                if (!b->ilen) {
                    // append a newly created indice list
                    renderlist_createindices(b, a->indices + ilen_a, a->len);
                    ilen_b = b->len;
                } else {
                    // append existing one
                    newind = a->indices+ilen_a;
                    for(int i=0; i<b->ilen; i++)
                        newind[i] = b->indices[i]+a->len;
                }
                break;
        }
    }
    // lenghts
    a->len += b->len;
    a->ilen += ilen_b;
    //all done
    return;
}

renderlist_t *extend_renderlist(renderlist_t *list) {
    if ((list->prev!=NULL) && ispurerender_renderlist(list) && islistscompatible_renderlist(list->prev, list)) {
        // close first!
        if (list->open)
            end_renderlist(list);
        // append list!
//printf("merge list 0x%04X(0x%04X) %i(%i) - %i + 0x%04X(0x%04X) %i(%i) - %i", 
//    list->prev->mode_init, list->prev->mode, list->prev->len, list->prev->cap, list->prev->ilen, list->mode_init, list->mode, list->len, list->cap, list->ilen);
        append_renderlist(list->prev, list);
//printf(" -> %i(%i) - %i\n", list->prev->len, list->prev->cap, list->prev->ilen);
        renderlist_t *new = alloc_renderlist();
        new->prev = list->prev;
        list->prev->next = new;
        // detach
        list->prev = NULL;
        // free list now
        free_renderlist(list);
        return new;
    } else {
        renderlist_t *new = alloc_renderlist();
        list->next = new;
        new->prev = list;
        if (list->open)
            end_renderlist(list);
        return new;
    }
}

void free_renderlist(renderlist_t *list) {
	// test if list is NULL
	if (list == NULL)
		return;
    // we want the first list in the chain
    while (list->prev)
        list = list->prev;

    renderlist_t *next;
    do {
        if (list->calls.len > 0) {
            for (int i = 0; i < list->calls.len; i++) {
                free(list->calls.calls[i]);
            }
            free(list->calls.calls);
        }
        int a;
        if (!list->shared_arrays) {
            if (list->vert) free(list->vert);
            if (list->normal) free(list->normal);
            if (list->color) free(list->color);
            if (list->secondary) free(list->secondary);
            for (a=0; a<MAX_TEX; a++)
                if (list->tex[a]) free(list->tex[a]);
            if (list->indices)
                free(list->indices);
        }

        if (list->material) {
            rendermaterial_t *m;
            kh_foreach_value(list->material, m,
                free(m);
            )
            kh_destroy(material, list->material);
        }
        if (list->light) {
            renderlight_t *m;
            kh_foreach_value(list->light, m,
                free(m);
            )
            kh_destroy(light, list->light);
        }
        if (list->texgen) {
            rendertexgen_t *m;
            kh_foreach_value(list->texgen, m,
                free(m);
            )
            kh_destroy(texgen, list->texgen);
        }
        if (list->lightmodel)
			free(list->lightmodel);
			
        if (list->raster) {
			if (list->raster->texture)
				glDeleteTextures(1, &list->raster->texture);
			free(list->raster);
		}

        next = list->next;
        free(list);
    } while ((list = next));
}

static inline
void resize_renderlist(renderlist_t *list) {
    if (list->len >= list->cap) {
        list->cap += DEFAULT_RENDER_LIST_CAPACITY;
        realloc_sublist(list->vert, 3, list->cap);
        realloc_sublist(list->normal, 3, list->cap);
        realloc_sublist(list->color, 4, list->cap);
        realloc_sublist(list->secondary, 4, list->cap);
        for (int a=0; a<MAX_TEX; a++)
           realloc_sublist(list->tex[a], 2, list->cap);
    }
}

void end_renderlist(renderlist_t *list) {
    if (! list->open)
        return;

    list->stage = STAGE_LAST;
    list->open = false;
    for (int a=0; a<MAX_TEX; a++) {
	    gltexture_t *bound = state.texture.bound[a];
	    if ((list->tex[a]) && (bound) && ((bound->width != bound->nwidth) || (bound->height != bound->nheight))) {
		    tex_coord_npot(list->tex[a], list->len, bound->width, bound->height, bound->nwidth, bound->nheight);
	    }
	    // GL_ARB_texture_rectangle
	    if ((list->tex[a]) && state.texture.rect_arb[a] && (bound)) {
		    tex_coord_rect_arb(list->tex[a], list->len, bound->width, bound->height);
	    }
    }
    switch (list->mode) {
        case GL_QUADS:
			if (((list->indices) && (list->ilen==4)) || ((list->indices==NULL) && (list->len==4))) {
				list->mode = GL_TRIANGLE_FAN;
			} else {
                renderlist_quads2triangles(list);
			}
            break;
        case GL_POLYGON:
            list->mode = GL_TRIANGLE_FAN;
            break;
        case GL_QUAD_STRIP:
            list->mode = GL_TRIANGLE_STRIP;
            break;
    }
}

void draw_renderlist(renderlist_t *list) {
    if (!list) return;
    // go to 1st...
    while (list->prev) list = list->prev;
    // ok, go on now, draw everything
//printf("draw_renderlist %p, gl_batch=%i, size=%i, mode=0x%04X(0x%04X), ilen=%d, next=%p\n", list, state.gl_batch, list->len, list->mode, list->mode_init, list->ilen, list->next);
    LOAD_GLES(glDrawArrays);
    LOAD_GLES(glDrawElements);
#ifdef USE_ES2
    LOAD_GLES(glVertexAttribPointer);
#else
    LOAD_GLES(glVertexPointer);
    LOAD_GLES(glNormalPointer);
    LOAD_GLES(glColorPointer);
    LOAD_GLES(glTexCoordPointer);
#endif
    LOAD_GLES(glEnable);
    LOAD_GLES(glDisable);
    glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

	GLfloat *final_colors;
	int old_tex;
    GLushort *indices;
    do {
        // push/pop attributes
        if (list->pushattribute)
            glPushAttrib(list->pushattribute);
        if (list->popattribute)
            glPopAttrib();
        // do call_list
        if (list->glcall_list)
            glCallList(list->glcall_list);
        call_list_t *cl = &list->calls;
        if (cl->len > 0) {
            for (int i = 0; i < cl->len; i++) {
                glPackedCall(cl->calls[i]);
            }
        }
        if (list->fog_op) {
            switch (list->fog_op) {
                case 1: // GL_FOG_COLOR
                    glFogfv(GL_FOG_COLOR, list->fog_val);
                    break;
            }
        }
        if (list->matrix_op) {
            switch (list->matrix_op) {
                case 1: // load
                    glLoadMatrixf(list->matrix_val);
                    break;
                case 2: // mult
                    glMultMatrixf(list->matrix_val);
                    break;
            }
        }
        old_tex = state.texture.active;
	    if (list->set_texture) {
		glBindTexture(list->target_texture, list->texture);
        }
        // raster
        if (list->raster_op) {
            if (list->raster_op==1) {
                glRasterPos3f(list->raster_xyz[0], list->raster_xyz[1], list->raster_xyz[2]);
            } else if (list->raster_op==2) {
                glWindowPos3f(list->raster_xyz[0], list->raster_xyz[1], list->raster_xyz[2]);
            } else if (list->raster_op==3) {
                glPixelZoom(list->raster_xyz[0], list->raster_xyz[1]);
            } else if ((list->raster_op&0x10000) == 0x10000) {
                glPixelTransferf(list->raster_op&0xFFFF, list->raster_xyz[0]);
            }
        }
        if (list->raster) {
            rasterlist_t * r = list->raster;
            //glBitmap(r->width, r->height, r->xorig, r->yorig, r->xmove, r->ymove, r->raster);
            render_raster_list(list->raster);
        }
			

        if (list->material) {
            khash_t(material) *map = list->material;
            rendermaterial_t *m;
            kh_foreach_value(map, m,
                switch (m->pname) {
                    case GL_SHININESS:
                        glMaterialf(GL_FRONT_AND_BACK,  m->pname, m->color[0]);
                        break;
                    default:
                        glMaterialfv(GL_FRONT_AND_BACK, m->pname, m->color);
                }
            )
        }
        if (list->light) {
            khash_t(light) *lig = list->light;
            renderlight_t *m;
            kh_foreach_value(lig, m,
                switch (m->pname) {
                    default:
                        glLightfv(m->which, m->pname, m->color);
                }
            )
        }
        if (list->lightmodel) {
            glLightModelfv(list->lightmodelparam, list->lightmodel);
        }
		
        if (list->texgen) {
            khash_t(texgen) *tgn = list->texgen;
            rendertexgen_t *m;
            kh_foreach_value(tgn, m,
                switch (m->pname) {
                    case GL_TEXTURE_GEN_MODE:
                    glTexGeni(m->coord, m->pname, m->color[0]);
                    break;
                    default:
                    glTexGenfv(m->coord, m->pname, m->color);
                }
            )
        }
        
        if (list->polygon_mode) {
            glPolygonMode(GL_FRONT_AND_BACK, list->polygon_mode);}

        if (! list->len)
            continue;
#ifdef USE_ES2
        if (list->vert) {
            glEnableVertexAttribArray(0);
            gles_glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, list->vert);
        }
        gles_glDrawArrays(list->mode, 0, list->len);
#else
        if (list->vert) {
            glEnableClientState(GL_VERTEX_ARRAY);
            gles_glVertexPointer(3, GL_FLOAT, 0, list->vert);
        } else {
            glDisableClientState(GL_VERTEX_ARRAY);
        }

        if (list->normal) {
            glEnableClientState(GL_NORMAL_ARRAY);
            gles_glNormalPointer(GL_FLOAT, 0, list->normal);
        } else {
            glDisableClientState(GL_NORMAL_ARRAY);
        }

        indices = list->indices;
           
		final_colors = NULL;
        if (list->color) {
            glEnableClientState(GL_COLOR_ARRAY);
            if (state.enable.color_sum && (list->secondary)) {
				final_colors=(GLfloat*)malloc(list->len * 4 * sizeof(GLfloat));
				if (indices) {
					for (int i=0; i<list->ilen; i++)
						for (int j=0; j<4; j++) {
							const int k=indices[i]*4+j;
							final_colors[k]=list->color[k] + list->secondary[k];
						}
				 } else {
					for (int i=0; i<list->len*4; i++)
						final_colors[i]=list->color[i] + list->secondary[i];
				}
				gles_glColorPointer(4, GL_FLOAT, 0, final_colors);
			} else
				gles_glColorPointer(4, GL_FLOAT, 0, list->color);
        } else {
            glDisableClientState(GL_COLOR_ARRAY);
        }
        GLuint texture;
        bool stipple;
        stipple = false;
        if (! list->tex[0]) {
            // TODO: do we need to support GL_LINE_STRIP?
            if (list->mode == GL_LINES && state.enable.line_stipple) {
                stipple = true;
                glPushAttrib(GL_COLOR_BUFFER_BIT | GL_ENABLE_BIT | GL_TEXTURE_BIT);
                glEnable(GL_BLEND);
                glEnable(GL_TEXTURE_2D);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE);
                list->tex[0] = gen_stipple_tex_coords(list->vert, list->len);
            } 
	}
	GLfloat *texgened[MAX_TEX];
	GLint needclean[MAX_TEX];
	for (int a=0; a<MAX_TEX; a++) {
		texgened[a]=NULL;
        needclean[a]=0;
		if ((state.enable.texgen_s[a] || state.enable.texgen_t[a] || state.enable.texgen_r[a])) {
		    gen_tex_coords(list->vert, list->normal, &texgened[a], list->len, &needclean[a], a, (list->ilen<list->len)?indices:NULL, (list->ilen<list->len)?list->ilen:0);
		} else if (state.enable.texture_2d[a] && (list->tex[a]==NULL)) {
		    gen_tex_coords(list->vert, list->normal, &texgened[a], list->len, &needclean[a], a, (list->ilen<list->len)?indices:NULL, (list->ilen<list->len)?list->ilen:0);
		}
    }
	old_tex = state.texture.client;
        for (int a=0; a<MAX_TEX; a++) {
		    if ((list->tex[a] || texgened[a])/* && state.enable.texture_2d[a]*/) {
                glClientActiveTexture(GL_TEXTURE0+a);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		        gles_glTexCoordPointer(2, GL_FLOAT, 0, (texgened[a])?texgened[a]:list->tex[a]);
		    } else {
			if (state.enable.tex_coord_array[a]) {
			    glClientActiveTexture(GL_TEXTURE0+a);
			    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		    } 
//else if (!state.enable.texgen_s[a] && state.enable.texture_2d[a]) printf("LIBGL: texture_2d[%i] without TexCoord, mode=0x%04X (init=0x%04X), listlen=%i\n", a, list->mode, list->mode_init, list->len);
			    
		    }
        }
        for (int aa=0; aa<MAX_TEX; aa++) {
            if (!state.enable.texture_2d[aa] && (state.enable.texture_1d[aa] || state.enable.texture_3d[aa])) {
                glClientActiveTexture(aa+GL_TEXTURE0);
                gles_glEnable(GL_TEXTURE_2D);
            }
        }
        if (state.texture.client != old_tex) glClientActiveTexture(GL_TEXTURE0+old_tex);

        GLenum mode;
        mode = list->mode;
        if ((state.polygon_mode == GL_LINE) && (mode>=GL_TRIANGLES))
			mode = GL_LINES;
		if ((state.polygon_mode == GL_POINT) && (mode>=GL_TRIANGLES))
			mode = GL_POINTS;

        if (indices) {
            if (state.render_mode == GL_SELECT) {
                pointer_state_t vtx;
                vtx.pointer = list->vert;
                vtx.type = GL_FLOAT;
                vtx.size = 3;
                vtx.stride = 0;
                select_glDrawElements(&vtx, list->mode, list->len, GL_UNSIGNED_SHORT, indices);
            } else {
                if (state.polygon_mode == GL_LINE && list->mode_init>=GL_TRIANGLES) {
                    int n, s;
                    int ilen = list->ilen;
                    GLushort ind_line[ilen*3+1];
                    int k=0;
                    switch (list->mode_init) {
                        case GL_TRIANGLES:
                            // 1 triangle -> 3 lines
                            for (int i = 0; i<ilen; i+=3) {
                                ind_line[k++] = indices[i+0]; ind_line[k++] = indices[i+1];
                                ind_line[k++] = indices[i+1]; ind_line[k++] = indices[i+2];
                                ind_line[k++] = indices[i+2]; ind_line[k++] = indices[i+0];
                            }
                            break;
                        case GL_TRIANGLE_STRIP:
                            // first 3 points a triangle, then a 2 lines per new point
                            if (ilen>2) {
                                ind_line[k++] = indices[0]; ind_line[k++] = indices[1];
                            }
                            for (int i = 2; i<ilen; i++) {
                                ind_line[k++] = indices[i-2]; ind_line[k++] = indices[i];
                                ind_line[k++] = indices[i-1]; ind_line[k++] = indices[i];
                            }
                            break;
                        case GL_TRIANGLE_FAN:
                            // first 3 points a triangle, then a 2 lines per new point too
                            if (ilen>2) {
                                ind_line[k++] = indices[0]; ind_line[k++] = indices[1];
                            }
                            for (int i = 2; i<ilen; i++) {
                                ind_line[k++] = indices[0]; ind_line[k++] = indices[i];
                                ind_line[k++] = indices[i-1]; ind_line[k++] = indices[i];
                            }
                            break;
                        case GL_QUADS:
                            // 4 lines per quads, but dest may already be a triangles list...
                            if (list->mode == GL_TRIANGLE_FAN) {
                                // just 1 Quad
                                for (int i=0; i<4; i++) {
                                    ind_line[k++] = indices[i+0]; ind_line[k++] = indices[(i+1)%4];
                                }
                            } else {
                                // list of triangles, 2 per quads...
                                for (int i=0; i<ilen; i+=6) {
                                    ind_line[k++] = indices[i+0]; ind_line[k++] = indices[i+1];
                                    ind_line[k++] = indices[i+1]; ind_line[k++] = indices[i+2];
                                    ind_line[k++] = indices[i+2]; ind_line[k++] = indices[i+5];
                                    ind_line[k++] = indices[i+5]; ind_line[k++] = indices[i+0];
                                }
                            }
                            break;
                        case GL_QUAD_STRIP:
                            // first 4 points is a quad, then 2 points per new quad
                            if (ilen>2) {
                                ind_line[k++] = indices[0]; ind_line[k++] = indices[1];
                            }
                            for (int i = 2; i<ilen; i+=2) {
                                ind_line[k++] = indices[i-1]; ind_line[k++] = indices[i];
                                ind_line[k++] = indices[i-2]; ind_line[k++] = indices[i+1];
                                ind_line[k++] = indices[i+0]; ind_line[k++] = indices[i+1];
                            }
                            break;
                        case GL_POLYGON:
                            // if polygons have been merged, then info is lost...
                            if (ilen) {
                                ind_line[k++] = indices[0]; ind_line[k++] = indices[1];
                            }
                            for (int i = 1; i<ilen; i++) {
                                ind_line[k++] = indices[i-1]; ind_line[k++] = indices[i];
                            }
                            if (ilen) {
                                ind_line[k++] = indices[ilen-1]; ind_line[k++] = indices[0];
                            }
                            break;
                    }
                    gles_glDrawElements(mode, k, GL_UNSIGNED_SHORT, ind_line);
                } else {
                    gles_glDrawElements(mode, list->ilen, GL_UNSIGNED_SHORT, indices);
                }
            }
        } else {
            if (state.render_mode == GL_SELECT) {	
                pointer_state_t vtx;
                vtx.pointer = list->vert;
                vtx.type = GL_FLOAT;
                vtx.size = 3;
                vtx.stride = 0;
                select_glDrawArrays(&vtx, list->mode, 0, list->len);
            } else {
                int len = list->len;
                if ((state.polygon_mode == GL_LINE) && (list->mode_init>=GL_TRIANGLES)) {
                    int n, s;
                    GLushort ind_line[len*3+1];
                    int k=0;
                    switch (list->mode_init) {
                        case GL_TRIANGLES:
                            // 1 triangle -> 3 lines
                            for (int i = 0; i<len; i+=3) {
                                ind_line[k++] = i+0; ind_line[k++] = i+1;
                                ind_line[k++] = i+1; ind_line[k++] = i+2;
                                ind_line[k++] = i+2; ind_line[k++] = i+0;
                            }
                            break;
                        case GL_TRIANGLE_STRIP:
                            // first 3 points a triangle, then a 2 lines per new point
                            if (len>2) {
                                ind_line[k++] = 0; ind_line[k++] = 1;
                            }
                            for (int i = 2; i<len; i++) {
                                ind_line[k++] = i-2; ind_line[k++] = i;
                                ind_line[k++] = i-1; ind_line[k++] = i;
                            }
                            break;
                        case GL_TRIANGLE_FAN:
                            // first 3 points a triangle, then a 2 lines per new point too
                            if (len>2) {
                                ind_line[k++] = 0; ind_line[k++] = 1;
                            }
                            for (int i = 2; i<len; i++) {
                                ind_line[k++] = 0; ind_line[k++] = i;
                                ind_line[k++] = i-1; ind_line[k++] = i;
                            }
                            break;
                        case GL_QUADS:
                            // 4 lines per quads, QUAD without indices means 1 single quad
                            if (list->mode == GL_TRIANGLE_FAN) {
                                // just 1 Quad
                                for (int i=0; i<4; i++) {
                                    ind_line[k++] = i+0; ind_line[k++] = (i+1)%4;
                                }
                            } else {
                                // cannot go there!
                            }
                            break;
                        case GL_QUAD_STRIP:
                            // first 4 points is a quad, then 2 points per new quad
                            if (len>2) {
                                ind_line[k++] = 0; ind_line[k++] = 1;
                            }
                            for (int i = 2; i<len; i+=2) {
                                ind_line[k++] = i-1; ind_line[k++] = i;
                                ind_line[k++] = i-2; ind_line[k++] = i+1;
                                ind_line[k++] = i+0; ind_line[k++] = i+1;
                            }
                            break;
                        case GL_POLYGON:
                            // if polygons have been merged, then info is lost...
                            if (len) {
                                ind_line[k++] = 0; ind_line[k++] = 1;
                            }
                            for (int i = 1; i<len; i++) {
                                ind_line[k++] = i-1; ind_line[k++] = i;
                            }
                            if (len) {
                                ind_line[k++] = len-1; ind_line[k++] = 0;
                            }
                            break;
                    }
					gles_glDrawElements(mode, k, GL_UNSIGNED_SHORT, ind_line);
                } else {
                    gles_glDrawArrays(mode, 0, len);
                }
            }
        }
        for (int a=0; a<MAX_TEX; a++) {
            if (needclean[a])
                gen_tex_clean(needclean[a], a);
			if (texgened[a]) {
				free(texgened[a]);
				texgened[a] = NULL;
			}
		}
        for (int aa=0; aa<MAX_TEX; aa++) {
            if (!state.enable.texture_2d[aa] && (state.enable.texture_1d[aa] || state.enable.texture_3d[aa])) {
                glClientActiveTexture(aa+GL_TEXTURE0);
                gles_glDisable(GL_TEXTURE_2D);
            }
        }
        if (state.texture.client!=old_tex)
            glClientActiveTexture(old_tex+GL_TEXTURE0);

		if (final_colors)
			free(final_colors);
        if (stipple) {
            glPopAttrib();
        }
#endif
    } while ((list = list->next));
    glPopClientAttrib();
}

// gl function wrappers

void rlVertex3f(renderlist_t *list, GLfloat x, GLfloat y, GLfloat z) {
    if (list->vert == NULL) {
        list->vert = alloc_sublist(3, list->cap);
    } else {
        resize_renderlist(list);
    }

    if (list->normal) {
        GLfloat *normal = list->normal + (list->len * 3);
        memcpy(normal, list->lastNormal, sizeof(GLfloat) * 3);
    }

    if (list->color) {
        GLfloat *color = list->color + (list->len * 4);
        memcpy(color, state.color, sizeof(GLfloat) * 4);
    }

    if (list->secondary) {
        GLfloat *secondary = list->secondary + (list->len * 4);
        memcpy(secondary, state.secondary, sizeof(GLfloat) * 4);
    }

    for (int a=0; a<MAX_TEX; a++) {
		if (list->tex[a]) {
			GLfloat *tex = list->tex[a] + (list->len * 2);
			memcpy(tex, state.texcoord[a], sizeof(GLfloat) * 2);
		}
    }

    GLfloat *vert = list->vert + (list->len++ * 3);
    vert[0] = x; vert[1] = y; vert[2] = z;
}

void rlNormal3f(renderlist_t *list, GLfloat x, GLfloat y, GLfloat z) {
    if (list->normal == NULL) {
        list->normal = alloc_sublist(3, list->cap);
        // catch up
        int i;
        if (list->len) for (i = 0; i < list->len-1; i++) {
            GLfloat *normal = (list->normal + (i * 3));
            memcpy(normal, list->lastNormal, sizeof(GLfloat) * 3);
        }
    } else {
        resize_renderlist(list);
    }
    
    GLfloat *normal = list->lastNormal;
    normal[0] = x; normal[1] = y; normal[2] = z;
}

void rlColor4f(renderlist_t *list, GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (list->color == NULL) {
        list->color = alloc_sublist(4, list->cap);
        // catch up
        int i;
        if (list->len) for (i = 0; i < list->len-1; i++) {
            GLfloat *color = (list->color + (i * 4));
            memcpy(color, state.color, sizeof(GLfloat) * 4);
        } else {
            GLfloat *color = list->color;
            color[0] = r; color[1] = g; color[2] = b; color[3] = a;
        }
    } else {
        resize_renderlist(list);
    }

    GLfloat *color = state.color;
    color[0] = r; color[1] = g; color[2] = b; color[3] = a;
}

void rlSecondary3f(renderlist_t *list, GLfloat r, GLfloat g, GLfloat b) {
    if (list->secondary == NULL) {
        list->secondary = alloc_sublist(4, list->cap);
        // catch up
        int i;
        if (list->len) for (i = 0; i < list->len-1; i++) {
            GLfloat *secondary = (list->secondary + (i * 4));
            memcpy(secondary, state.secondary, sizeof(GLfloat) * 4);
        }
    } else {
        resize_renderlist(list);
    }

    GLfloat *color = state.secondary;
    color[0] = r; color[1] = g; color[2] = b; color[3] = 0.0f;
}

void rlMaterialfv(renderlist_t *list, GLenum face, GLenum pname, const GLfloat * params) {
    rendermaterial_t *m;
    khash_t(material) *map;
    khint_t k;
    int ret;
    if (! list->material) {
        list->material = map = kh_init(material);
        // segfaults if we don't do a single put
        kh_put(material, map, 1, &ret);
        kh_del(material, map, 1);
    } else {
        map = list->material;
    }

    // TODO: currently puts all faces in the same map
    k = kh_get(material, map, pname);
    if (k == kh_end(map)) {
        k = kh_put(material, map, pname, &ret);
        m = kh_value(map, k) = malloc(sizeof(rendermaterial_t));
    } else {
        m = kh_value(map, k);
    }

    m->face = face;
    m->pname = pname;
    m->color[0] = params[0];
    m->color[1] = params[1];
    m->color[2] = params[2];
    m->color[3] = params[3];
}

void rlLightfv(renderlist_t *list, GLenum which, GLenum pname, const GLfloat * params) {
    renderlight_t *m;
    khash_t(light) *map;
    khint_t k;
    int ret;
    if (! list->light) {
        list->light = map = kh_init(light);
        // segfaults if we don't do a single put
        kh_put(light, map, 1, &ret);
        kh_del(light, map, 1);
    } else {
        map = list->light;
    }

	int key = pname | ((which-GL_LIGHT0)<<16);
    k = kh_get(light, map, key);
    if (k == kh_end(map)) {
        k = kh_put(light, map, key, &ret);
        m = kh_value(map, k) = malloc(sizeof(renderlight_t));
    } else {
        m = kh_value(map, k);
    }

    m->which = which;
    m->pname = pname;
    m->color[0] = params[0];
    m->color[1] = params[1];
    m->color[2] = params[2];
    m->color[3] = params[3];
}

void rlTexGenfv(renderlist_t *list, GLenum coord, GLenum pname, const GLfloat * params) {
    rendertexgen_t *m;
    khash_t(texgen) *map;
    khint_t k;
    int ret;
    if (! list->texgen) {
        list->texgen = map = kh_init(texgen);
        // segfaults if we don't do a single put
        kh_put(texgen, map, 1, &ret);
        kh_del(texgen, map, 1);
    } else {
        map = list->texgen;
    }

	int key = pname | ((coord-GL_S)<<16);
    k = kh_get(texgen, map, key);
    if (k == kh_end(map)) {
        k = kh_put(texgen, map, key, &ret);
        m = kh_value(map, k) = malloc(sizeof(rendertexgen_t));
    } else {
        m = kh_value(map, k);
    }

    m->coord = coord;
    m->pname = pname;
    m->color[0] = params[0];
    m->color[1] = params[1];
    m->color[2] = params[2];
    m->color[3] = params[3];
}

void rlTexCoord2f(renderlist_t *list, GLfloat s, GLfloat t) {
    if (list->tex[0] == NULL) {
        list->tex[0] = alloc_sublist(2, list->cap);
        // catch up
        GLfloat *tex = list->tex[0];
        if (list->len) for (int i = 0; i < list->len-1; i++) {
            memcpy(tex, state.texcoord[0], sizeof(GLfloat) * 2);
            tex += 2;
        }
    } else {
        resize_renderlist(list);
    }
    GLfloat *tex = state.texcoord[0];
    tex[0] = s; tex[1] = t;
}

void rlMultiTexCoord2f(renderlist_t *list, GLenum target, GLfloat s, GLfloat t) {
    if (list->tex[target-GL_TEXTURE0] == NULL) {
        list->tex[target-GL_TEXTURE0] = alloc_sublist(2, list->cap);
        // catch up
        GLfloat *tex = list->tex[target-GL_TEXTURE0];
        if (list->len) for (int i = 0; i < list->len-1; i++) {
            memcpy(tex, state.texcoord[target-GL_TEXTURE0], sizeof(GLfloat) * 2);
            tex += 2;
        }
    } else {
        resize_renderlist(list);
    }
    GLfloat *tex = state.texcoord[target-GL_TEXTURE0];
    tex[0] = s; tex[1] = t;
}

void rlBindTexture(renderlist_t *list, GLenum target, GLuint texture) {
    list->texture = texture;
    list->target_texture = target;
    list->set_texture = true;
}

void rlRasterOp(renderlist_t *list, int op, GLfloat x, GLfloat y, GLfloat z) {
    list->raster_op = op;
    list->raster_xyz[0] = x;
    list->raster_xyz[1] = y;
    list->raster_xyz[2] = z;
}

void rlFogOp(renderlist_t *list, int op, const GLfloat* v) {
    list->fog_op = op;
    list->fog_val[0] = v[0];
    list->fog_val[1] = v[1];
    list->fog_val[2] = v[2];
    list->fog_val[3] = v[3];
}

void rlPushCall(renderlist_t *list, packed_call_t *data) {
    call_list_t *cl = &list->calls;
    if (!cl->calls) {
        cl->cap = DEFAULT_CALL_LIST_CAPACITY;
        cl->calls = malloc(DEFAULT_CALL_LIST_CAPACITY * sizeof(uintptr_t));
    } else if (list->calls.len == list->calls.cap) {
        cl->cap += DEFAULT_CALL_LIST_CAPACITY;
        cl->calls = realloc(cl->calls, cl->cap * sizeof(uintptr_t));
    }
    cl->calls[cl->len++] = data;
}

renderlist_t* GetFirst(const renderlist_t* list) {
    while(list->prev)
        list = list->prev;
    return list;
}

#undef alloc_sublist
#undef realloc_sublist
