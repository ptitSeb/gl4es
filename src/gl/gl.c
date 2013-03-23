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
bool bVertexArray = false;
bool bColorArray = false;
bool bNormalArray = false;
bool bTexCoordArray = false;
glwPointer aVertexPointer;
glwPointer aColorPointer;
glwPointer aNormalPointer;
glwPointer aTexCoordPointer;

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
    if (mode == GL_QUADS) {
        // TODO: support more types/sizes
        RenderList *list = allocRenderList();
        list->mode = mode;
        list->len = count;
        list->cap = count;

        #define type_case(magic, type, code) \
            case magic: {                    \
                type *next = (type *)src;    \
                code                         \
                break;                       \
            }

        #define type_switch(type, code)                                  \
            switch (type) {                                              \
                type_case(GL_FLOAT, GLfloat, code)                       \
                type_case(GL_UNSIGNED_BYTE, GLubyte, code)               \
                default:                                                 \
                    printf("unsupported glDrawArrays type: %i\n", type); \
                    break;                                               \
            }

        #define copy_gl_pointer(ptr, arr)\
            if (ptr.pointer) {                                                   \
                int stride, width, size;                                         \
                width = ptr.size;                                                \
                size = gl_sizeof(ptr.type);                                      \
                stride = (ptr.stride ? ptr.stride : width * size);               \
                arr = malloc(sizeof(GLfloat) * width * count);                   \
                uintptr_t src = (uintptr_t)ptr.pointer;                          \
                GLfloat *dst = arr;                                              \
                                                                                 \
                src += first * stride;                                           \
                if (ptr.type == GL_FLOAT) {                                      \
                    for (int i = 0; i < count; i++) {                            \
                        memcpy(dst, (GLvoid *)src, sizeof(GLfloat) * width);     \
                        dst += width;                                            \
                        src += stride;                                           \
                    }                                                            \
                } else {                                                         \
                    type_switch(ptr.type,                                        \
                        for (int i = 0; i < count; i++) {                        \
                            for (int k = 0; k < width; k++) {                    \
                                dst[k] = next[k];                                \
                            }                                                    \
                            dst += width;                                        \
                            src += stride;                                       \
                            next = (void *)src;                                  \
                        }                                                        \
                    )                                                            \
                }                                                                \
            }

        if (bVertexArray) {
            copy_gl_pointer(aVertexPointer, list->vert)
        }
        if (bColorArray) {
            copy_gl_pointer(aColorPointer, list->color)
        }
        if (bNormalArray) {
            copy_gl_pointer(aNormalPointer, list->normal)
        }
        if (bTexCoordArray) {
            copy_gl_pointer(aTexCoordPointer, list->tex)
        }
        #undef copy_gl_pointer
        #undef type_switch
        #undef type_case
        endRenderList(list);
        drawRenderList(list);
        freeRenderList(list);
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
    clone_gl_pointer(aVertexPointer, size);
    gles_glVertexPointer(size, type, stride, pointer);
}
void glColorPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glColorPointer, GLint, GLenum, GLsizei, const GLvoid *);
    clone_gl_pointer(aColorPointer, size);
    gles_glColorPointer(size, type, stride, pointer);
}
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glNormalPointer, GLenum, GLsizei, const GLvoid *);
    clone_gl_pointer(aNormalPointer, 3);
    gles_glNormalPointer(type, stride, pointer);
}
void glTexCoordPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(void, glTexCoordPointer, GLint, GLenum, GLsizei, const GLvoid *);
    clone_gl_pointer(aTexCoordPointer, size);
    gles_glTexCoordPointer(size, type, stride, pointer);
}
#undef clone_gl_pointer

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
    listMode = mode;

    RenderList *l = glGetList(list);
    if (l) {
        printf("newList already exists: %i. not implemented.\n", list);
        // TODO: what do we do if the list already exists?
        // iirc it's in the GL spec
        return;
    } else {
        // TODO: if activeList is already defined, we probably need to clean up here
        activeList = displayLists[list-1] = allocRenderList();
        listCompiling = true;
    }
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
    // TODO: this call can be compiled into another display list
    RenderList *l = glGetList(list);
    if (l)
        drawRenderList(l);
}

void glPushCall(void *call) {
    if (listCompiling && activeList) {
        lPushCall(activeList, call);
    }
}

void glCallLists(GLsizei n, GLenum type, const GLvoid *lists) {
    #define call(name, type)\
        case name: glCallList(((type *)lists)[i] + listBase); break

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
    RenderList *l = glGetList(list);
    if (l) {
        freeRenderList(l);
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
    listBase = base;
}

GLboolean glIsList(GLuint list) {
    if (glGetList(list)) {
        return true;
    }
    return false;
}

GLsizei gl_sizeof(GLenum type) {
    switch (type) {
        case GL_DOUBLE:
            return 8;
        case GL_FLOAT:
        case GL_INT:
        case GL_UNSIGNED_INT:
        case GL_4_BYTES:
            return 4;
        case GL_3_BYTES:
            return 3;
        case GL_UNSIGNED_SHORT:
        case GL_UNSIGNED_SHORT_5_6_5:
        case GL_UNSIGNED_SHORT_4_4_4_4:
        case GL_UNSIGNED_SHORT_5_5_5_1:
        case GL_2_BYTES:
            return 2;
        case GL_UNSIGNED_BYTE:
            return 1;
        default:
            printf("libGL: Unsupported pixel data type: %i\n", type);
            return 0;
    }
}
