#include "gl.h"
#include "list.h"

#define alloc_sublist(n, cap) \
    (GLfloat *)malloc(n * sizeof(GLfloat) * cap)

#define realloc_sublist(ref, n, cap) \
    if (ref)                         \
        ref = (GLfloat *)realloc(ref, n * sizeof(GLfloat) * cap)

static GLushort *cached_q2t = NULL;
static unsigned long cached_q2t_len = 0;

RenderList *alloc_renderlist() {
    RenderList *list = (RenderList *)malloc(sizeof(RenderList));
    list->len = 0;
    list->cap = DEFAULT_RENDER_LIST_CAPACITY;

    list->calls.len = 0;
    list->calls.cap = 0;
    list->calls.calls = NULL;

    list->mode = 0;
    list->vert = NULL;
    list->normal = NULL;
    list->color = NULL;
    list->tex = NULL;
    list->material = NULL;
    list->indices = NULL;

    list->next = NULL;
    return list;
}

RenderList *extend_renderlist(RenderList *list) {
    list->next = alloc_renderlist();
    return list->next;
}

void free_renderlist(RenderList *list) {
    RenderList *next;
    do {
        if (list->calls.len > 0) {
            for (int i = 0; i < list->calls.len; i++) {
                free(list->calls.calls[i]);
            }
            free(list->calls.calls);
        }
        if (list->vert) free(list->vert);
        if (list->normal) free(list->normal);
        if (list->color) free(list->color);
        if (list->tex) free(list->tex);
        if (list->material) free(list->material);
        if (list->indices && list->indices != cached_q2t)
            free(list->indices);
        next = list->next;
        free(list);
    } while ((list = next));
}

static inline
void resize_renderlist(RenderList *list) {
    if (list->len >= list->cap) {
        list->cap += DEFAULT_RENDER_LIST_CAPACITY;
        realloc_sublist(list->vert, 3, list->cap);
        realloc_sublist(list->normal, 3, list->cap);
        realloc_sublist(list->color, 4, list->cap);
        realloc_sublist(list->tex, 2, list->cap);
    }
}

void q2t_renderlist(RenderList *list) {
    if (!list->len || !list->vert) return;
    // TODO: split to multiple lists if list->len > 65535

    int a = 0, b = 1, c = 2, d = 3;
    int winding[6] = {
        a, b, d,
        b, c, d,
    };
    unsigned long len = list->len * 1.5;

    if (list->indices && list->indices != cached_q2t)
        free(list->indices);

    if (len > cached_q2t_len) {
        if (cached_q2t)
            free(cached_q2t);
        cached_q2t = malloc(len * sizeof(GLushort));
        cached_q2t_len = len;

        GLushort *indices = cached_q2t;
        for (int i = 0; i < list->len; i += 4) {
            for (int j = 0; j < 6; j++) {
                indices[j] = i + winding[j];
            }
            indices += 6;
        }
    }

    list->indices = cached_q2t;
    list->len = len;
    return;
}

void end_renderlist(RenderList *list) {
    GLtexture *bound = state.texture.bound;
    if (list->tex && bound && (bound->width != bound->nwidth || bound->height != bound->nheight)) {
        tex_coord_npot(list->tex, list->len, bound->width, bound->height, bound->nwidth, bound->nheight);
    }
    // GL_ARB_texture_rectangle
    if (list->tex && state.texture.rect_arb && bound) {
        tex_coord_rect_arb(list->tex, list->len, bound->width, bound->height);
    }
    switch (list->mode) {
        case GL_QUADS:
            list->mode = GL_TRIANGLES;
            q2t_renderlist(list);
            break;
        case GL_POLYGON:
            list->mode = GL_TRIANGLE_FAN;
            break;
        case GL_QUAD_STRIP:
            list->mode = GL_TRIANGLE_STRIP;
            break;
    }
}

void draw_renderlist(RenderList *list) {
    if (!list) return;
    LOAD_GLES(void, glDrawArrays, GLenum, GLint, GLsizei);
    LOAD_GLES(void, glDrawElements, GLenum, GLsizei, GLenum, const GLvoid *);

    glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
    do {
        // optimize zero-length segments out earlier?
        CallList *cl = &list->calls;
        if (cl->len > 0) {
            for (int i = 0; i < cl->len; i++) {
                glPackedCall(cl->calls[i]);
            }
        }
        if (! list->len)
            continue;

#ifdef USE_ES2
        if (list->vert) {
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, list->vert);
        }
        gles_glDrawArrays(list->mode, 0, list->len);
#else
        if (list->vert) {
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(3, GL_FLOAT, 0, list->vert);
        } else {
            glDisableClientState(GL_VERTEX_ARRAY);
        }

        if (list->normal) {
            glEnableClientState(GL_NORMAL_ARRAY);
            glNormalPointer(GL_FLOAT, 0, list->normal);
        } else {
            glDisableClientState(GL_NORMAL_ARRAY);
        }

        if (list->color) {
            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(4, GL_FLOAT, 0, list->color);
        } else {
            glDisableClientState(GL_COLOR_ARRAY);
        }

        if (list->material) {
            RenderMaterial *m = list->material;
            int i, pos = 0;
            for (i = 0; i < list->material->count; i++) {
                m = list->material + i;
                glMaterialfv(GL_FRONT_AND_BACK, m->pname, m->color);
            }
        }

        GLuint texture;

        bool stipple = false;
        if (! list->tex) {
            // TODO: do we need to support GL_LINE_STRIP?
            if (list->mode == GL_LINES && state.enable.line_stipple) {
                stipple = true;
                glPushAttrib(GL_COLOR_BUFFER_BIT | GL_ENABLE_BIT | GL_TEXTURE_BIT);
                glEnable(GL_BLEND);
                glEnable(GL_TEXTURE_2D);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE);
                list->tex = gen_stipple_tex_coords(list->vert, list->len);
            } else if (state.enable.texgen_s || state.enable.texgen_t) {
                gen_tex_coords(list->vert, &list->tex, list->len);
            }
        }

        if (list->tex) {
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, list->tex);
        } else {
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        }

        if (list->indices) {
            gles_glDrawElements(list->mode, list->len, GL_UNSIGNED_SHORT, list->indices);
        } else {
            gles_glDrawArrays(list->mode, 0, list->len);
        }
        if (stipple) {
            glPopAttrib();
        }
#endif
    } while ((list = list->next));
    glPopClientAttrib();
}

// gl function wrappers

void rlVertex3f(RenderList *list, GLfloat x, GLfloat y, GLfloat z) {
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
        memcpy(color, list->lastColor, sizeof(GLfloat) * 4);
    }

    if (list->tex) {
        GLfloat *tex = list->tex + (list->len * 2);
        memcpy(tex, list->lastTex, sizeof(GLfloat) * 2);
    }

    GLfloat *vert = list->vert + (list->len++ * 3);
    vert[0] = x; vert[1] = y; vert[2] = z;
}

void rlNormal3f(RenderList *list, GLfloat x, GLfloat y, GLfloat z) {
    GLfloat *normal = list->lastNormal;
    normal[0] = x; normal[1] = y; normal[2] = z;

    if (list->normal == NULL) {
        list->normal = alloc_sublist(3, list->cap);
        // catch up
        int i;
        for (i = 0; i < list->len; i++) {
            GLfloat *normal = (list->normal + (i * 4));
            memcpy(normal, list->lastNormal, sizeof(GLfloat) * 4);
        }
    } else {
        resize_renderlist(list);
    }
}

void rlColor4f(RenderList *list, GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (list->color == NULL) {
        list->color = alloc_sublist(4, list->cap);
        // catch up
        int i;
        for (i = 0; i < list->len; i++) {
            GLfloat *color = (list->color + (i * 4));
            memcpy(color, list->lastColor, sizeof(GLfloat) * 4);
        }
    } else {
        resize_renderlist(list);
    }

    GLfloat *color = list->lastColor;
    color[0] = r; color[1] = g; color[2] = b; color[3] = a;
}

void rlMaterialfv(RenderList *list, GLenum face, GLenum pname, const GLfloat * params) {
    int *count;
    if (! list->material) {
        // TODO: fixed size is a hack
        list->material = malloc(20 * sizeof(RenderMaterial));
        list->material->count = 0;
    }
    RenderMaterial *m = list->material + list->material->count;
    m->face = face;
    m->pname = pname;
    memcpy(m->color, params, sizeof(GLfloat) * 4);

    list->material->count++;
}

void rlTexCoord2f(RenderList *list, GLfloat s, GLfloat t) {
    GLfloat *tex = list->lastTex;
    tex[0] = s; tex[1] = t;

    if (list->tex == NULL) {
        list->tex = alloc_sublist(2, list->cap);
    } else {
        resize_renderlist(list);
    }
}

void rlPushCall(RenderList *list, UnknownCall *data) {
    CallList *cl = &list->calls;
    if (!cl->calls) {
        cl->cap = DEFAULT_CALL_LIST_CAPACITY;
        cl->calls = malloc(DEFAULT_CALL_LIST_CAPACITY * sizeof(uintptr_t));
    } else if (list->calls.len == list->calls.cap) {
        cl->cap += DEFAULT_CALL_LIST_CAPACITY;
        cl->calls = realloc(cl->calls, cl->cap * sizeof(uintptr_t));
    }
    cl->calls[cl->len++] = data;
}

#undef alloc_sublist
#undef realloc_sublist
