#include <GLES/gl.h>
#include <dlfcn.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct {
    GLuint isLast;
    GLuint len;
    GLenum mode;
    GLuint useColor;
    GLuint useTex;
    GLfloat data;
} glwListData;

typedef struct {
    GLubyte pos;
    GLubyte len;
    GLubyte created;
    GLubyte free;
    glwListData *data;
} glwList;

#define GL_QUADS      7
#define GL_QUAD_STRIP 8
#define GL_POLYGON    9

#define GL_TEXTURE_GEN_S    0x0C60
#define GL_TEXTURE_GEN_T    0x0C61
#define GL_TEXTURE_GEN_MODE 0x2500

#define GL_LINE_SMOOTH            0x0B20
#define GL_LINE_STIPPLE           0x0B24
#define GL_LINE_STIPPLE_PATTERN   0x0B25
#define GL_LINE_STIPPLE_REPEAT    0x0B26
#define GL_LINE_WIDTH             0x0B21
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_LINE_WIDTH_RANGE       0x0B22

#define GL_OBJECT_LINEAR    0x2401
#define GL_OBJECT_PLANE     0x2501
#define GL_EYE_LINEAR       0x2400
#define GL_EYE_PLANE        0x2502
#define GL_SPHERE_MAP       0x2402

#define GL_S 0x2000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003

#define GLW_LIST_SIZE 12*10240*sizeof(GLfloat)

#define GLdouble double

GLuint glGenLists(GLsizei range);
void glActiveTextureARB(GLenum texture);
void glBegin(GLenum mode);
void glCallList(GLuint list);
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
void glLineStipple(GLuint factor, GLushort pattern);
void glNewList(GLuint list);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glTexCoord2f(GLfloat s, GLfloat t);
void glTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2i(GLint x, GLint y);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
