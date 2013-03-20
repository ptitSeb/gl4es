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
#include "list.h"
#include "raster.h"
#include "stack.h"
#include "texgen.h"
#include "texture.h"

typedef struct {
    GLubyte pos;
    GLubyte len;
    GLubyte created;
    GLubyte free;
    RenderList *list;
} glwList;

typedef struct {
    GLint size;
    GLenum type;
    GLsizei stride;
    const GLvoid *pointer;
} glwPointer;

bool bLineStipple;
bool bTexGenS;
bool bTexGenT;
bool listCompiling;
bool listMode;

// don't auto-wrap these functions
#define skip_glColor4f
#define skip_glColor4ub
#define skip_glDisable
#define skip_glEnable
#define skip_glGetString
#define skip_glMaterialfv
#define skip_glTexImage2D
#define skip_glViewport

// glDrawArrays
#define skip_glDrawArrays
#define skip_glVertexPointer
#define skip_glColorPointer
#define skip_glNormalPointer
#define skip_glTexCoordPointer
#define skip_glDisableClientState
#define skip_glEnableClientState

// don't compile these into display lists
#define direct_glColorPointer
#define direct_glDeleteLists
#define direct_glDisableClientState
#define direct_glEdgeFlagPointer
#define direct_glEnableClientState
#define direct_glFeedbackBuffer
#define direct_glFinish
#define direct_glFlush
#define direct_glGenLists
#define direct_glIndexPointer
#define direct_glInterleavedArrays
#define direct_glIsEnabled
#define direct_glIsList
#define direct_glNormalPointer
#define direct_glPopClientAttrib
#define direct_glPixelStore
#define direct_glPushClientAttrib
#define direct_glReadPixels
#define direct_glRenderMode
#define direct_glSelectBuffer
#define direct_glTexCoordPointer
#define direct_glVertexPointer

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
