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

#define LOAD_GLES(type, name, args...)\
    static type (*gles_##name)(args);\
    if (gles_##name == NULL) {\
        if (gles == NULL) {\
            gles = dlopen("libGLES_CM.so", RTLD_LOCAL | RTLD_LAZY);\
        }\
        gles_##name = dlsym(gles, #name);\
    }

#define WRAP_GLES(type, name, args...)\
    type name(args) {\
        LOAD_GLES(type, name, args);

#define END_WRAP }

#include "glstub.h"
#include "glwrap.h"
#include "line.h"
#include "raster.h"
#include "texture.h"

typedef struct {
    GLubyte pos;
    GLubyte len;
    GLubyte created;
    GLubyte free;
    RenderList *list;
} glwList;

bool bLineStipple;

// don't auto-wrap these functions
#define skip_glColor4f
#define skip_glColor4ub
#define skip_glDisable
#define skip_glEnable
#define skip_glMaterialfv
#define skip_glTexImage2D
#define skip_glViewport

// newly-defined GL functions
GLuint glGenLists(GLsizei range);
void glActiveTextureARB(GLenum texture);
void glBegin(GLenum mode);
void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, const GLvoid *lists);
void glClearDepth(GLdouble depth);
void glDeleteList(GLuint list);
void glDeleteLists(GLuint list, GLsizei range);
void glEnd();
void glEndList(GLuint list);
void glFogi(GLenum pname, GLint param);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glGetDoublev(GLenum pname, GLdouble *params);
void glIndexf(GLfloat i);
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
