#include <gl.h>
#include <list.h>

#define alloc_sublist(n, cap)\
    (GLfloat *)malloc(n * sizeof(GLfloat) * cap)

#define realloc_sublist(ref, n, cap)\
    if (ref)\
        ref = (GLfloat *)realloc(ref, n * sizeof(GLfloat) * cap)

RenderList *allocRenderList() {
    RenderList *list = (RenderList *)malloc(sizeof(RenderList));
    list->len = 0;
    list->cap = DEFAULT_RENDER_LIST_CAPACITY;

    list->mode = 0;
    list->vert = NULL;
    list->normal = NULL;
    list->color = NULL;
    list->tex = NULL;

    list->next = NULL;
    return list;
}

RenderList *extendRenderList(RenderList *list) {
    list->next = allocRenderList();
    return list->next;
}

void freeRenderList(RenderList *list) {
    RenderList *next;
    do {
        if (list->vert) free(list->vert);
        if (list->normal) free(list->normal);
        if (list->color) free(list->color);
        if (list->tex) free(list->tex);
        next = list->next;
        free(list);
    } while ((list = next));
}

void ensureRenderListSize(RenderList *list) {
    if (list->len >= list->cap) {
        list->cap += DEFAULT_RENDER_LIST_CAPACITY;
        realloc_sublist(list->vert, 3, list->cap);
        realloc_sublist(list->normal, 3, list->cap);
        realloc_sublist(list->color, 4, list->cap);
        realloc_sublist(list->tex, 2, list->cap);
    }
}

void swizzleRenderList(RenderList *list) {
    if (!list->len || !list->vert) return;
    GLfloat *newVert, *newVertPos, *vertPos, *vert;
    GLfloat *newNormal, *newNormalPos, *normalPos, *normal;
    GLfloat *newColor, *newColorPos, *colorPos, *color;
    GLfloat *newTex, *newTexPos, *texPos, *tex;

    vertPos = vert = list->vert;
    normalPos = normal = list->normal;
    colorPos = color = list->color;
    texPos = tex = list->tex;

    int newLen = list->len * 1.5;
    if (vert) newVertPos = list->vert = alloc_sublist(3, newLen);
    if (normal) newNormalPos = list->normal = alloc_sublist(3, newLen);
    if (color) newColorPos = list->color = alloc_sublist(4, newLen);
    if (tex) newTexPos = list->tex = alloc_sublist(2, newLen);;

    // GLfloat *a, *b, *c, *d;
    int a = 0, b = 1, c = 2, d = 3;
    int v1, v2, v3, v4, v5, v6;

    for (int i = 0; i < list->len; i += 4) {
        /*
        a = &vertPos[3*0];
        b = &vertPos[3*1];
        c = &vertPos[3*2];
        d = &vertPos[3*3];
        #define dist(a, b)\
            pow(a[0]-b[0], 2) + pow(a[1]-b[1], 2) + pow(a[2]-b[2], 2)
        if (dist(a, c) < dist(b, d)) {
            v3 = 2; v4 = 0; v5 = 2; v6 = 3;
        } else {
            v3 = 3; v4 = 3; v5 = 1; v6 = 2;
        }
        #undef dist
        */
        v1 = a; v2 = b; v3 = d;
        v4 = b; v5 = c; v6 = d;

        memcpy(newVertPos,      &vertPos[3*v1], sizeof(GLfloat) * 3);
        memcpy(newVertPos += 3, &vertPos[3*v2], sizeof(GLfloat) * 3);
        memcpy(newVertPos += 3, &vertPos[3*v3], sizeof(GLfloat) * 3);
        memcpy(newVertPos += 3, &vertPos[3*v4], sizeof(GLfloat) * 3);
        memcpy(newVertPos += 3, &vertPos[3*v5], sizeof(GLfloat) * 3);
        memcpy(newVertPos += 3, &vertPos[3*v6], sizeof(GLfloat) * 3);
        newVertPos += 3;
        vertPos += 4 * 3;
        if (normal) {
            memcpy(newNormalPos,      &normalPos[3*v1], sizeof(GLfloat) * 3);
            memcpy(newNormalPos += 3, &normalPos[3*v2], sizeof(GLfloat) * 3);
            memcpy(newNormalPos += 3, &normalPos[3*v3], sizeof(GLfloat) * 3);
            memcpy(newNormalPos += 3, &normalPos[3*v4], sizeof(GLfloat) * 3);
            memcpy(newNormalPos += 3, &normalPos[3*v5], sizeof(GLfloat) * 3);
            memcpy(newNormalPos += 3, &normalPos[3*v6], sizeof(GLfloat) * 3);
            newNormalPos += 3;
            normalPos += 4 * 3;
        }
        if (color) {
            memcpy(newColorPos,      &colorPos[4*v1], sizeof(GLfloat) * 4);
            memcpy(newColorPos += 4, &colorPos[4*v2], sizeof(GLfloat) * 4);
            memcpy(newColorPos += 4, &colorPos[4*v3], sizeof(GLfloat) * 4);
            memcpy(newColorPos += 4, &colorPos[4*v4], sizeof(GLfloat) * 4);
            memcpy(newColorPos += 4, &colorPos[4*v5], sizeof(GLfloat) * 4);
            memcpy(newColorPos += 4, &colorPos[4*v6], sizeof(GLfloat) * 4);
            newColorPos += 4;
            colorPos += 4 * 4;
        }
        if (tex) {
            memcpy(newTexPos,      &texPos[2*v1], sizeof(GLfloat) * 2);
            memcpy(newTexPos += 2, &texPos[2*v2], sizeof(GLfloat) * 2);
            memcpy(newTexPos += 2, &texPos[2*v3], sizeof(GLfloat) * 2);
            memcpy(newTexPos += 2, &texPos[2*v4], sizeof(GLfloat) * 2);
            memcpy(newTexPos += 2, &texPos[2*v5], sizeof(GLfloat) * 2);
            memcpy(newTexPos += 2, &texPos[2*v6], sizeof(GLfloat) * 2);
            newTexPos += 2;
            texPos += 4 * 2;
        }
    }
    list->len = list->cap = newLen;

    if (vert) free(vert);
    if (normal) free(normal);
    if (color) free(color);
    if (tex) free(tex);
}

void endRenderList(RenderList *list) {
    switch (list->mode) {
        case GL_QUADS:
            list->mode = GL_TRIANGLES;
            swizzleRenderList(list);
            break;
        case GL_POLYGON:
            list->mode = GL_TRIANGLE_FAN;
            break;
        case GL_QUAD_STRIP:
            list->mode = GL_TRIANGLE_STRIP;
            break;
    }
}

void drawRenderList(RenderList *list) {
    do {
        // optimize zero-length segments out earlier?
        if (! list->len)
            continue;

        if (list->vert) {
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(3, GL_FLOAT, 0, list->vert);
        }

        if (list->normal) {
            glEnableClientState(GL_NORMAL_ARRAY);
            glNormalPointer(GL_FLOAT, 0, list->normal);
        }

        if (list->color) {
            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(4, GL_FLOAT, 0, list->color);
        }

        // TODO: copy over stipple code
        GLfloat *tex = list->tex;

        if (tex) {
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, tex);
        }

        glDrawArrays(list->mode, 0, list->len);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    } while ((list = list->next));
}

void lVertex3f(RenderList *list, GLfloat x, GLfloat y, GLfloat z) {
    if (list->vert == NULL) {
        list->vert = alloc_sublist(3, list->cap);
    } else {
        ensureRenderListSize(list);
    }

    if (list->normal) {
        GLfloat *normal = list->color + (list->len * 3);
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

void lNormal3f(RenderList *list, GLfloat x, GLfloat y, GLfloat z) {
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
        ensureRenderListSize(list);
    }
}

void lColor4f(RenderList *list, GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (list->color == NULL) {
        list->color = alloc_sublist(4, list->cap);
        // catch up
        int i;
        for (i = 0; i < list->len; i++) {
            GLfloat *color = (list->color + (i * 4));
            memcpy(color, list->lastColor, sizeof(GLfloat) * 4);
        }
    } else {
        ensureRenderListSize(list);
    }

    GLfloat *color = list->lastColor;
    color[0] = r; color[1] = g; color[2] = b; color[3] = a;
}

void lTexCoord2f(RenderList *list, GLfloat s, GLfloat t) {
    GLfloat *tex = list->lastTex;
    tex[0] = s; tex[1] = t;

    if (list->tex == NULL) {
        list->tex = alloc_sublist(2, list->cap);
        // catch up
        int i;
        for (i = 0; i < list->len; i++) {
            GLfloat *color = (list->color + (i * 4));
            memcpy(color, list->lastColor, sizeof(GLfloat) * 4);
        }
    } else {
        ensureRenderListSize(list);
    }
}

#undef alloc_sublist

#if 0
// drawing

void glwDrawArrays(GLfloat *vert,
                   GLfloat *color, GLfloat *tex,
                   GLenum mode, GLuint length) {
    if (! length) return;

    if (vert != NULL) {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vert);
    }

    if (color != NULL) {
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(4, GL_FLOAT, 0, color);
    }

/*
    if (bTexGenS || bTexGenT) {
        genTexCoords(*vert, *tex, length);
    }
*/
    GLuint texture;
    if (bLineStipple) {
        GLubyte data[16];
        // generate our texture
        for (int i = 0; i < 16; i++) {
            data[i] = (stipplePattern >> i) & 1 ? 255 : 0;
        }

        // generate our texture coords
        tex = (GLfloat *)malloc(length * 2 * sizeof(GLfloat));
        GLfloat *texPos = tex;
        GLfloat *vertPos = vert;

        GLfloat x1, x2, y1, y2;
        GLfloat len;
        for (int i = 0; i < length / 2; i++) {
            x1 = *vertPos++;
            y1 = *vertPos++;
            vertPos++; // z
            x2 = *vertPos++;
            y2 = *vertPos++;
            vertPos++;

            len = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) / stippleFactor;

            *texPos++ = 0;
            *texPos++ = 0;
            *texPos++ = len;
            *texPos++ = 0;
        }

        // TODO: *disable* this afterward?
        // maybe implement glPush/PopAttrib
        glEnable(GL_BLEND);
        glEnable(GL_TEXTURE_2D);
        // restore this after?
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA,
            16, 1, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
    }

    if (tex != NULL) {
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, tex);
    }

    glDrawArrays(mode, 0, length);

    if (texture) { // TODO: separate flag for this?
        glDeleteTextures(1, &texture);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
#endif
