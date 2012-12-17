#include <glesgl.h>

// ugly global variables

glwList *glwActiveList;
glwListData *glwLastListData;
GLuint glwListPos;
GLuint glwListSize;

GLfloat glwVerts[10240][3];
GLfloat glwTexCoords[10240][2];
GLfloat glwColors[10240][4];

GLfloat glwColor[4];
GLfloat glwTexCoord[4];

GLuint glwPos;
GLenum glwDrawMode;
bool glwImmediate;
bool glwEnableVertex;
bool glwEnableColor;
bool glwEnableTexCoord;

void *gles;
void (*glesColor4f)(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

// immediate mode functions

void glBegin(GLenum mode) {
    if (mode == GL_QUADS) mode = GL_TRIANGLE_FAN;
    if (mode == GL_QUAD_STRIP) mode = GL_TRIANGLE_STRIP;
    if (mode == GL_POLYGON) mode = GL_TRIANGLE_FAN;
    printf("glBegin(%i)\n", mode);

    glwPos = 0;
    glwDrawMode = mode;
    glwEnableVertex = false;
    glwEnableColor = false;
    glwEnableTexCoord = false;
    glwImmediate = true;
}

void glEnd() {
    printf("glEnd()\n");
    glwImmediate = false;

    // are we in the middle of a display list?
    if (glwActiveList == NULL) {
        if (glwEnableVertex) {
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(3, GL_FLOAT, 0, *glwVerts);
        }
        if (glwEnableColor) {
            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(4, GL_FLOAT, 0, *glwColors);
        }
        if (glwEnableTexCoord) {
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, *glwTexCoords);
        }

        glDrawArrays(glwDrawMode, 0, glwPos);

        if (glwEnableVertex)
            glDisableClientState(GL_VERTEX_ARRAY);
        if (glwEnableColor)
            glDisableClientState(GL_COLOR_ARRAY);
        if (glwEnableTexCoord)
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    } else {
        glwListData *l = glwActiveList->data;
        GLuint size = glwListPos + (3 + (glwEnableColor ? 4 : 0) + (glwEnableTexCoord ? 2 : 0) * glwPos);

        if (size > glwListSize) {
            GLuint difference = size - glwListSize;
            GLuint newSize = glwListSize + ((difference / GLW_LIST_SIZE) + 1) * GLW_LIST_SIZE;
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
    printf("glVertex3f(%.2f, %.2f, %.2f)\n", x, y, z);
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
    printf("glColor4f(%.2f, %.2f, %.2f, %.2f)\n", r, g, b, a);
    if (glwImmediate) {
        GLfloat color[] = {r, g, b, a};
        if (!glwEnableColor) {
            glwEnableColor = true;
            // catch up
            int i;
            for (i = 0; i < glwPos; i++) {
                memcpy(&glwColors[i][0], color, sizeof(GLfloat) * 4);
            }

            memcpy(glwColor, color, sizeof(GLfloat) * 4);
        }
    } else {
        // load upstream glColor4f if necessary
        if (glesColor4f == NULL) {
            if (gles == NULL) {
                gles = dlopen("libGLES_CM.so", RTLD_LOCAL | RTLD_LAZY);
            }
            glesColor4f = dlsym(gles, "glColor4f");
        }
        glesColor4f(r, g, b, a);
    }
}

void glTexCoord2f(GLfloat s, GLfloat t) {
    printf("glTexCoord2f(%.2f, %.2f)\n", s, t);
    if (glwImmediate) {
        GLfloat tex[] = {s, t};
        if (!glwEnableTexCoord) {
            glwEnableTexCoord = true;
            // catch up
            int i;
            for (i = 0; i < glwPos; i++) {
                memcpy(&glwTexCoords[i][0], tex, sizeof(GLfloat) * 4);
            }
        }

        memcpy(glwTexCoord, tex, sizeof(GLfloat) * 4);
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
    glwList *l = (glwList *)(list * 8);

    l->created = true;
    l->data = (glwListData *)malloc(sizeof(glwListData) + GLW_LIST_SIZE);

    glwActiveList = l;
    glwLastListData = NULL;
    glwListPos = 0;
    glwListSize = sizeof(glwListData) + GLW_LIST_SIZE;
}

void glEndList(GLuint list) {
    glwActiveList = NULL;
}

void glCallList(GLuint list) {
    GLfloat *data, *vert, *color, *tex;
    glwListData *next, *ld;

    glwList *l = (glwList *)(list * 8);
    ld = l->data;

    glEnableClientState(GL_VERTEX_ARRAY);

    while (true) {
        vert = &ld->data;

        glVertexPointer(3, GL_FLOAT, 0, vert);

        next = (glwListData *)(vert + (ld->len*3));
        if (ld->useColor) {
            color = (GLfloat *)next;
            next = (glwListData *)(color + (ld->len * 4));

            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(4, GL_FLOAT, 0, color);
        }
        if (ld->useTex) {
            tex = (GLfloat *)next;
            next = (glwListData *)(tex + (ld->len * 2));

            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, 0, tex);
        }

        glDrawArrays(ld->mode, 0, ld->len);

        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        if (ld->isLast) break;
        ld = next;
    }
    glDisableClientState(GL_VERTEX_ARRAY);
}

void glDeleteList(GLuint list) {
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
