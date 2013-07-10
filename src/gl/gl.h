#include <dlfcn.h>
#include <GLES/gl.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GL_H
#define GL_H

#include "config.h"
#include "wrap/es.h"
#include "const.h"

#define checkError(code)                          \
    {int error; while ((error = glGetError())) {} \
    code                                          \
    if ((error = glGetError()))                   \
        printf(#code " -> %i\n", error);}

#define printError(file, line)              \
    {int error; if ((error = glGetError())) \
        printf(file ":%i -> %i\n", line, error);}

#define GLdouble double

// will become a reference to dlopen'd gles
void *gles;

#ifdef USE_ES2
#define GLES_LIB "libGLESv2.so"
#else
#define GLES_LIB "libGLES_CM.so"
#endif

#define WARN_NULL(name) if (name == NULL) printf("libGL: warning, " #name " is NULL\n");

#define LOAD_GLES(type, name, args...)                              \
    typedef type (*glesptr_##name)(args);                           \
    static glesptr_##name gles_##name;                              \
    if (gles_##name == NULL) {                                      \
        if (gles == NULL) {                                         \
            gles = dlopen(GLES_LIB, RTLD_LOCAL | RTLD_LAZY);        \
            WARN_NULL(gles);                                        \
        }                                                           \
        gles_##name = (glesptr_##name)dlsym(gles, #name);           \
        WARN_NULL(gles_##name);                                     \
    }

#define WRAP_GLES(type, name, args...) \
    type name(args) {                  \
        LOAD_GLES(type, name, args);

#define END_WRAP }

static const GLsizei gl_sizeof(GLenum type) {
    // types
    switch (type) {
        case GL_DOUBLE:
            return 8;
        case GL_FLOAT:
        case GL_INT:
        case GL_UNSIGNED_INT:
        case GL_UNSIGNED_INT_10_10_10_2:
        case GL_UNSIGNED_INT_2_10_10_10_REV:
        case GL_UNSIGNED_INT_8_8_8_8:
        case GL_UNSIGNED_INT_8_8_8_8_REV:
        case GL_4_BYTES:
            return 4;
        case GL_3_BYTES:
            return 3;
        case GL_LUMINANCE_ALPHA:
        case GL_UNSIGNED_SHORT:
        case GL_UNSIGNED_SHORT_1_5_5_5_REV:
        case GL_UNSIGNED_SHORT_4_4_4_4:
        case GL_UNSIGNED_SHORT_4_4_4_4_REV:
        case GL_UNSIGNED_SHORT_5_5_5_1:
        case GL_UNSIGNED_SHORT_5_6_5:
        case GL_UNSIGNED_SHORT_5_6_5_REV:
        case GL_2_BYTES:
            return 2;
        case GL_LUMINANCE:
        case GL_UNSIGNED_BYTE:
        case GL_UNSIGNED_BYTE_2_3_3_REV:
        case GL_UNSIGNED_BYTE_3_3_2:
            return 1;
    }
    // formats
    switch (type) {
        case GL_RED:
            return 1;
        case GL_RG:
            return 2;
        case GL_RGB:
        case GL_BGR:
            return 3;
        case GL_RGBA:
        case GL_BGRA:
            return 4;
    }
    printf("libGL: Unsupported pixel data type: %i\n", type);
    return 0;
}

#include "wrap/stub.h"
#include "wrap/gl.h"
#include "light.h"
#include "line.h"
#include "list.h"
#include "pixel.h"
#include "raster.h"
#include "stack.h"
#include "texgen.h"
#include "texture.h"

#include "state.h"
extern GLstate state;

// newly-defined GL functions
GLboolean glIsList(GLuint list);
GLuint glGenLists(GLsizei range);
void glActiveTextureARB(GLenum texture);
void glBegin(GLenum mode);
void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, const GLvoid *lists);
void glClearDepth(GLdouble depth);
void glDeleteList(GLuint list);
void glDeleteLists(GLuint list, GLsizei range);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glEnd();
void glEndList(GLuint list);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glGetDoublev(GLenum pname, GLdouble *params);
void glIndexf(GLfloat i);
void glListBase(GLuint base);
void glNewList(GLuint list, GLenum mode);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
void glTexCoord2f(GLfloat s, GLfloat t);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2i(GLint x, GLint y);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);

// custom functions
void glPushCall(void *call);

#endif
