#include <gl.h>

RenderList *activeList = NULL;
GLfloat lastColor[4] = {1.0f, 1.0f, 1.0f, 1.0f};
bool listCompiling = false;
bool listMode = 0;
GLuint listBase = 0;

bool bTexGenS = false;
bool bTexGenT = false;
bool bLineStipple = false;
bool bBlend = false;
bool bTexture2d = false;

// glDrawArrays
static bool bVertexArray = false;
static bool bColorArray = false;
static bool bNormalArray = false;
static bool bTexCoordArray = false;
static glwPointer aVertexPointer;
static glwPointer aColorPointer;
static glwPointer aNormalPointer;
static glwPointer aTexCoordPointer;

// config functions

const GLubyte *glGetString(GLenum name) {
    LOAD_GLES(const GLubyte *, glGetString, GLenum);
    switch (name) {
        case GL_VERSION:
            return (GLubyte *)"1.4 Narwhal 0.5";
        default:
            return gles_glGetString(name);
    }
}

void glwEnable(GLenum cap, bool enable, void (*next)(GLenum)) {
    switch (cap) {
        case GL_TEXTURE_GEN_S: bTexGenS = enable; break;
        case GL_TEXTURE_GEN_T: bTexGenT = enable; break;
        case GL_BLEND: bBlend = enable; next(cap); break;
        case GL_TEXTURE_2D: bTexture2d = enable; next(cap); break;
        case GL_LINE_STIPPLE: bLineStipple = enable; break;

        // for glDrawArrays
        case GL_VERTEX_ARRAY: bVertexArray = enable; next(cap); break;
        case GL_NORMAL_ARRAY: bNormalArray = enable; next(cap); break;
        case GL_COLOR_ARRAY: bColorArray = enable; next(cap); break;
        case GL_TEXTURE_COORD_ARRAY: bTexCoordArray = enable; next(cap); break;
        default: next(cap); break;
    }
}

void glEnable(GLenum cap) {
    LOAD_GLES(void, glEnable, GLenum);
    glwEnable(cap, true, gles_glEnable);
}

void glDisable(GLenum cap) {
    LOAD_GLES(void, glDisable, GLenum);
    glwEnable(cap, false, gles_glDisable);
}

// glDrawArrays
void glEnableClientState(GLenum cap) {
    LOAD_GLES(void, glEnableClientState, GLenum);
    if (cap == GL_POINT_SIZE_ARRAY_OES) printf("point size\n");
    glwEnable(cap, true, gles_glEnableClientState);
}

void glDisableClientState(GLenum cap) {
    LOAD_GLES(void, glDisableClientState, GLenum);
    glwEnable(cap, false, gles_glDisableClientState);
}

void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    glBegin(mode);
    for (int i = first; i < count; i++) {
        if (bVertexArray) {
            GLfloat *vp = (GLfloat *)aVertexPointer.pointer;
            if (vp) {
                GLfloat *v = &vp[i*3];
                glVertex3fv(v);
            }
        }
        if (bColorArray) {
            GLfloat *cp = (GLfloat *)aColorPointer.pointer;
            if (cp) {
                GLfloat *c = &cp[i*4];
                glColor4fv(c);
            }
        }
        if (bNormalArray) {
            GLfloat *np = (GLfloat *)aNormalPointer.pointer;
            if (np) {
                GLfloat *n = &np[i*3];
                glNormal3fv(n);
            }
        }
        if (bTexCoordArray) {
            GLfloat *tp = (GLfloat *)aTexCoordPointer.pointer;
            if (tp) {
                GLfloat *t = &tp[i*2];
                glTexCoord2fv(t);
            }
        }
    }
    glEnd();
}

#define copy_gl_pointer(t, s)\
    t.size = s; t.type = type; t.stride = stride; t.pointer = pointer;
void glVertexPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glVertexPointer, GLint, GLenum, GLsizei, const GLvoid *);
    copy_gl_pointer(aVertexPointer, size);
    gles_glVertexPointer(size, type, stride, pointer);
}
void glColorPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glColorPointer, GLint, GLenum, GLsizei, const GLvoid *);
    copy_gl_pointer(aColorPointer, size);
    gles_glColorPointer(size, type, stride, pointer);
}
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glNormalPointer, GLenum, GLsizei, const GLvoid *);
    copy_gl_pointer(aNormalPointer, 3);
    gles_glNormalPointer(type, stride, pointer);
}
void glTexCoordPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glTexCoordPointer, GLint, GLenum, GLsizei, const GLvoid *);
    copy_gl_pointer(aTexCoordPointer, size);
    gles_glTexCoordPointer(size, type, stride, pointer);
}
#undef copy_gl_pointer

// immediate mode functions

void glBegin(GLenum mode) {
    if (! listCompiling) {
        activeList = allocRenderList();
    }
    memcpy(activeList->lastColor, lastColor, sizeof(GLfloat) * 4);
    activeList->mode = mode;
}

void glEnd() {
    // render if we're not in a display list
    if (! activeList) return;

    endRenderList(activeList);
    if (! listCompiling) {
        drawRenderList(activeList);
        freeRenderList(activeList);
        activeList = NULL;
    } else {
        activeList = extendRenderList(activeList);
    }
}

void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    if (activeList) {
        lVertex3f(activeList, x, y, z);
    }
}

void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (activeList) {
        lColor4f(activeList, r, g, b, a);
    } else {
        LOAD_GLES(void, glColor4f, GLfloat, GLfloat, GLfloat, GLfloat);
        gles_glColor4f(r, g, b, a);
        lastColor[0] = r; lastColor[1] = g;
        lastColor[2] = b; lastColor[3] = a;
    }
}

void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {
    LOAD_GLES(void, glMaterialfv, GLenum face, GLenum pname, const GLfloat *params);
    if (activeList) {
        lMaterialfv(activeList, face, pname, params);
    } else {
        gles_glMaterialfv(face, pname, params);
    }
}

void glTexCoord2f(GLfloat s, GLfloat t) {
    if (activeList) {
        lTexCoord2f(activeList, s, t);
    }
}

// display lists
glwList **displayLists = NULL;
int listCount = 0;
int listCap = 0;

GLuint glGenLists(GLsizei range) {
    int start = listCount;
    if (displayLists == NULL) {
        listCap += range + 100;
        displayLists = (glwList **)malloc(listCap * sizeof(glwList *));
    } else if (listCount + range > listCap) {
        listCap += range + 100;
        displayLists = (glwList **)realloc(displayLists, listCap * sizeof(glwList *));
    }
    listCount += range;

    int i;
    glwList *lists = (glwList *)malloc(range * sizeof(glwList));
    for (i = 0; i < range; i++) {
        glwList list = {i, range, 0, 0, NULL};
        memcpy(lists+i, &list, sizeof(glwList));
        displayLists[start+i] = lists + i;
    }

    return start;
}

void glNewList(GLuint list, GLenum mode) {
    if (list >= listCount) return;
    listMode = mode;

    glwList *l = displayLists[list];
    if (l->created) return;

    // TODO: if activeList is defined, we probably need to clean up here
    l->created = true;
    listCompiling = true;
    activeList = l->list = allocRenderList();
}

void glEndList(GLuint list) {
    if (listCompiling) {
        listCompiling = false;
        activeList = NULL;
        if (listMode == GL_COMPILE_AND_EXECUTE) {
            glCallList(list);
        }
    }
}

void glCallList(GLuint list) {
    // TODO: this can be compiled into another display list
    if (list >= listCount) return;

    glwList *l = displayLists[list];
    if (l->created)
        drawRenderList(l->list);
}

void glPushCall(void *call) {
    if (listCompiling && activeList) {
        lPushCall(activeList, call);
    }
}

void glCallLists(GLsizei n, GLenum type, const GLvoid *lists) {
    #define call(name, type)\
        case name: glCallList(*(((type *)lists + i) + listBase)); break

    // seriously wtf
    #define call_bytes(name, stride)\
        case name:\
            l = (GLubyte *)lists;\
            list = 0;\
            for (j = 0; j < stride; j++) {\
                list += *(l + (i * stride + j)) << (stride - j);\
            }\
            glCallList(list + listBase);\
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
    if (list >= listCount) return;

    glwList *l = displayLists[list];
    l->free = true;
    if (l->created) {
        freeRenderList(l->list);
        l->created = false;
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
    listBase = base;
}

GLboolean glIsList(GLuint list) {
    if (list < listCount) {
        glwList *l = displayLists[list];
        if (l->created)
            return true;
    }
    return false;
}
