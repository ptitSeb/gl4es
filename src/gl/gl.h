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

#include "gleswrap.h"

#define checkError(code)\
    {int error; while ((error = glGetError())) {}\
    code\
    if ((error = glGetError()))\
        printf(#code " -> %i\n", error);}

#define printError(file, line)\
    {int error; if ((error = glGetError()))\
        printf(file ":%i -> %i\n", line, error);}

#define GLdouble double

#include <glconst.h>
#include <list.h>

// will become a reference to dlopen'd gles
void *gles;

#define LOAD_REAL(type, name, args...)\
    static type (*real_##name)(args);\
    if (real_##name == NULL) {\
        if (gles == NULL) {\
            gles = dlopen("libGLES_CM.so", RTLD_LOCAL | RTLD_LAZY);\
        }\
        real_##name = dlsym(gles, #name);\
    }

#include "glstub.h"
#include "glwrap.h"
#include "texture.h"

typedef struct {
    GLubyte pos;
    GLubyte len;
    GLubyte created;
    GLubyte free;
    RenderList *list;
} glwList;

GLuint glGenLists(GLsizei range);
void glActiveTextureARB(GLenum texture);
void glBegin(GLenum mode);
void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, const GLvoid *lists);
void glClearDepth(GLdouble depth);
void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void glDeleteList(GLuint list);
void glDeleteLists(GLuint list, GLsizei range);
void glDisable(GLenum cap);
void glEnable(GLenum cap);
void glEnd();
void glEndList(GLuint list);
void glFogi(GLenum pname, GLint param);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glGetDoublev(GLenum pname, GLdouble *params);
void glIndexf(GLfloat i);
void glLineStipple(GLuint factor, GLushort pattern);
void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
void glListBase(GLuint base);
void glNewList(GLuint list);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glTexCoord2f(GLfloat s, GLfloat t);
void glTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2i(GLint x, GLint y);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);

#endif
