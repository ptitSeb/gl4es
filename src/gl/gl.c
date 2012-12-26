#include <gl.h>

// ugly global variables

glwList *glwActiveList;
glwListData *glwLastListData;
GLuint glwListPos;
GLuint glwListSize;

GLfloat glwVerts[10240][3];
GLfloat glwTexCoords[10240][2];
GLfloat glwColors[10240][4];

GLfloat glwColor[4];
GLfloat glwTexCoord[2];

GLuint glwPos;
GLenum glwDrawMode;
bool glwImmediate;
bool glwEnableVertex;
bool glwEnableColor;
bool glwEnableTexCoord;

bool bTexGenS;
GLenum texGenS;
GLfloat texGenSv[4];

bool bTexGenT;
GLenum texGenT;
GLfloat texGenTv[4];

bool bLineStipple;
GLint stippleFactor = 1;
GLushort stipplePattern = 0xFFFF;

bool bBlend;
bool bTexture2d;

// config functions

void glwEnable(GLenum cap, bool enable, void (*next)(GLenum)) {
    switch (cap) {
        /*
        case GL_TEXTURE_GEN_S: bTexGenS = enable; break;
        case GL_TEXTURE_GEN_T: bTexGenT = enable; break;
        */
        case GL_BLEND: bBlend = enable; next(cap); break;
        case GL_TEXTURE_2D: bTexture2d = enable; next(cap); break;
        case GL_LINE_STIPPLE: bLineStipple = enable; break;
        default: next(cap); break;
    }
}

void glEnable(GLenum cap) {
    LOAD_REAL(void, glEnable, GLenum);
    glwEnable(cap, true, real_glEnable);
}

void glDisable(GLenum cap) {
    LOAD_REAL(void, glDisable, GLenum);
    glwEnable(cap, false, real_glDisable);
}

// texture generation

void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    // coord is in: GL_S, GL_T, GL_R, GL_Q
    // pname == GL_TEXTURE_GEN_MODE
    /* param is in:
        GL_OBJECT_LINEAR, GL_EYE_LINEAR,
        GL_SPHERE_MAP, GL_NORMAL_MAP, or GL_REFLECTION_MAP
    */
    switch (coord) {
        case GL_S: texGenS = param; break;
        case GL_T: texGenT = param; break;
    }
}


void glTexGenfv(GLenum coord, GLenum pname, GLfloat *param) {
    return;
    // pname is in: GL_TEXTURE_GEN_MODE, GL_OBJECT_PLANE, GL_EYE_PLANE

    if (pname == GL_TEXTURE_GEN_MODE) {
        switch (coord) {
            case GL_S: texGenS = *param; break;
            case GL_T: texGenT = *param; break;
        }
    } else {
        switch (coord) {
            case GL_S:
                // texGenS = pname;
                memcpy(texGenSv, param, 4 * sizeof(GLfloat));
                break;
            case GL_T:
                // texGenT = pname;
                memcpy(texGenTv, param, 4 * sizeof(GLfloat));
                break;
        }
    }

    /*
    If pname is GL_TEXTURE_GEN_MODE, then the array must contain
    a single symbolic constant, one of
    GL_OBJECT_LINEAR, GL_EYE_LINEAR, GL_SPHERE_MAP, GL_NORMAL_MAP,
    or GL_REFLECTION_MAP.
    Otherwise, params holds the coefficients for the texture-coordinate
    generation function specified by pname.
    */
}

// TODO: put these in a lib
GLfloat dot(GLfloat *a, GLfloat *b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]+b[2] + a[3]+b[3];
}

GLfloat genTexCoord(GLfloat *vert, GLenum type, GLfloat *params) {
    switch (type) {
        case GL_OBJECT_LINEAR:
        case GL_SPHERE_MAP:
            return dot(vert, params);
            break;
    }
    return 0;
}

void genTexCoords(GLfloat *verts, GLfloat *coords, GLint count) {
    return;
    int i;
    for (i = 0; i < count; i++) {
        GLfloat *tex = &coords[i];
        if (bTexGenS) tex[0] = genTexCoord(&verts[i], texGenS, texGenSv);
        if (bTexGenT) tex[1] = genTexCoord(&verts[i], texGenT, texGenTv);
    }
}

// drawing

void glwDrawArrays(GLfloat *vert,
                   GLfloat *color, GLfloat *tex,
                   GLenum mode, GLuint length) {
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
    GLubyte *data = NULL;
    if (bLineStipple) {
        data = (GLubyte *)malloc(32 * sizeof(GLubyte));
        GLubyte *dataPos = data;
        // generate our texture
        for (int i = 0; i < 16; i++) {
            GLubyte bit = (stipplePattern >> i) & 1 ? 255 : 0;
            *dataPos++ = bit;
        }

        // generate our texture coords
        tex = (GLfloat *)malloc(length * 2 * sizeof(GLfloat));
        GLfloat *texPos = tex;
        for (int i = 0; i < length; i++) {
            *texPos++ = 0; // TODO: generate texture X coordinates
            *texPos++ = 0;
        }

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA,
            16, 2, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
    }

    if (tex != NULL) {
        printf("tex\n");
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, tex);
    }

    glDrawArrays(mode, 0, length);

    if (texture) {
        free(data);
        glDeleteTextures(1, &texture);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

// misc functions

void glLineStipple(GLuint factor, GLushort pattern) {
    stippleFactor = factor;
    stipplePattern = pattern;
}

// immediate mode functions

void glBegin(GLenum mode) {
    if (mode == GL_QUADS) mode = GL_TRIANGLE_FAN;
    if (mode == GL_QUAD_STRIP) mode = GL_TRIANGLE_STRIP;
    if (mode == GL_POLYGON) mode = GL_TRIANGLE_FAN;

    glwPos = 0;
    glwDrawMode = mode;
    glwEnableVertex = false;
    glwEnableColor = false;
    glwEnableTexCoord = false;
    glwImmediate = true;
}

void glEnd() {
    glwImmediate = false;

    // are we not in a display list?
    if (glwActiveList == NULL) {
        GLfloat *vert = NULL, *color = NULL, *tex = NULL;
        if (glwEnableVertex) vert = *glwVerts;
        if (glwEnableColor) color = *glwColors;
        if (glwEnableTexCoord) tex = *glwTexCoords;

        glwDrawArrays(vert, color, tex, glwDrawMode, glwPos);
    } else {
        glwListData *l = glwActiveList->data;
        GLuint size = glwListPos + (3 + (glwEnableColor ? 4 : 0) + (glwEnableTexCoord ? 2 : 0) * glwPos);

        if (!size) return;
        if (size > glwListSize) {
            GLuint newSize = glwListSize + GLW_LIST_SIZE;
            printf("realloc'ing to %d\n", newSize);
            l = realloc(l, sizeof(glwListData) + newSize);
            printf("realloc'd to %d\n", newSize);
        }

        if (glwLastListData != NULL) {
            glwLastListData->isLast = false;
        }

        char *start = (char *)l;

        glwListData cur = {true, glwPos, glwDrawMode, glwEnableColor, glwEnableTexCoord, 0};
        memcpy(start + glwListPos, &cur, sizeof(glwListData));

        glwLastListData = (glwListData *)(start + glwListPos);
        glwListPos += sizeof(glwListData) - sizeof(GLfloat);
        
        memcpy(start + glwListPos, *glwVerts, glwPos * sizeof(GLfloat) * 3);
        glwListPos += glwPos * sizeof(GLfloat) * 3;

        if (glwEnableColor) {
            memcpy(start + glwListPos, *glwColors, glwPos * sizeof(GLfloat) * 4);
            glwListPos += glwPos * sizeof(GLfloat) * 4;
        }

        if (glwEnableTexCoord) {
            memcpy(start + glwListPos, *glwTexCoords, glwPos * sizeof(GLfloat) * 2);
            glwListPos += glwPos * sizeof(GLfloat) * 2;
        }
    }
}

void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    glwEnableVertex = true;
    if (glwEnableColor) {
        memcpy(&glwColors[glwPos][0], glwColor, sizeof(GLfloat) * 4);
    }
    if (glwEnableTexCoord) {
        memcpy(&glwTexCoords[glwPos][0], glwTexCoord, sizeof(GLfloat) * 2);
    }

    GLfloat vert[] = {x, y, z};
    memcpy(&glwVerts[glwPos][0], vert, sizeof(GLfloat) * 3);

    glwPos++;
}

void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (glwImmediate) {
        GLfloat color[] = {r, g, b, a};
        if (!glwEnableColor) {
            glwEnableColor = true;
            // catch up
            int i;
            for (i = 0; i < glwPos; i++) {
                memcpy(&glwColors[i], color, sizeof(GLfloat) * 4);
            }

            memcpy(glwColor, color, sizeof(GLfloat) * 4);
        }
    } else {
        LOAD_REAL(void, glColor4f, GLfloat, GLfloat, GLfloat, GLfloat);
        real_glColor4f(r, g, b, a);
    }
}

void glTexCoord2f(GLfloat s, GLfloat t) {
    if (glwImmediate) {
        GLfloat tex[] = {s, t};
        if (!glwEnableTexCoord) {
            glwEnableTexCoord = true;
            // catch up
            int i;
            for (i = 0; i < glwPos; i++) {
                memcpy(&glwTexCoords[i], tex, sizeof(GLfloat) * 2);
            }
        }

        memcpy(glwTexCoord, tex, sizeof(GLfloat) * 2);
    }
}

// display lists

GLuint glGenLists(GLsizei range) {
    glwList *lists = (glwList *)malloc(range * sizeof(glwList));
    int i;
    for (i = 0; i < range; i++) {
        glwList list = {i, range, 0, 0, NULL};
        lists[i] = list;
    }

    return (uintptr_t)lists / 8;
}

void glNewList(GLuint list) {
    printf("glNewList(%i);\n", list);
    glwList *l = (glwList *)(list * 8);

    l->created = true;
    l->data = (glwListData *)malloc(sizeof(glwListData) + GLW_LIST_SIZE);

    glwActiveList = l;
    glwLastListData = NULL;
    glwListPos = 0;
    glwListSize = sizeof(glwListData) + GLW_LIST_SIZE;
}

void glEndList(GLuint list) {
    printf("glEndList(%i);\n", list);
    glwActiveList = NULL;
}

void glCallList(GLuint list) {
    GLfloat *data, *vert, *color, *tex;
    bool freeTex;
    glwListData *next, *ld;

    glwList *l = (glwList *)(list * 8);
    ld = l->data;

    while (true) {
        vert = &ld->data;
        next = (glwListData *)(vert + (ld->len*3));
        if (ld->useColor) {
            color = (GLfloat *)next;
            next = (glwListData *)(color + (ld->len * 4));
        }
        if (ld->useTex) {
            tex = (GLfloat *)next;
            next = (glwListData *)(tex + (ld->len * 2));
        }

        glwDrawArrays(vert, color, tex, ld->mode, ld->len);

        if (ld->isLast || !next->len) break;
        ld = next;
    }
}

void glDeleteList(GLuint list) {
    printf("glDeleteList(%i);\n", list);
    glwList *l = (glwList *)(list * 8);
    l->free = true;
    if (l->created) {
        free(l->data);
    }

    // only free if the display list group is empty
    int i;
    for (i = 0; i < l->len; i++) {
        if (! (l-l->pos+i)->free)
            return;
    }

    free(l-l->pos);
}

void glDeleteLists(GLuint list, GLsizei range) {
    int i;
    for (i = 0; i < range; i++) {
        glDeleteList(list+i);
    }
}
