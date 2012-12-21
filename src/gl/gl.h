#include <GLES/gl.h>
#include <dlfcn.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void glColor3f(GLfloat r, GLfloat g, GLfloat b);
void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void glDeleteList(GLuint list);
void glDeleteLists(GLuint list, GLsizei range);
void glEnd();
void glEnable(GLenum cap);
void glDisable(GLenum cap);
void glEndList(GLuint list);
void glFogi(GLenum pname, GLint param);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glLineStipple(GLuint factor, GLushort pattern);
void glNewList(GLuint list);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glTexCoord2f(GLfloat s, GLfloat t);
void glTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2i(GLint x, GLint y);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
