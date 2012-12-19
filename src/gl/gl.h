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

#define GL_QUADS 7
#define GL_QUAD_STRIP 8
#define GL_POLYGON 9

#define GLW_LIST_SIZE 12*256*sizeof(GLfloat)

void glBegin(GLenum mode);
void glEnd();

void glActiveTextureARB(GLenum texture);
void glFogi(GLenum pname, GLint param);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void glTexGenfv(GLenum coord, GLenum pname, GLfloat *params);

void glClearDepth(double depth);
void glOrtho(double left, double right, double bottom,
             double top, double near, double far);

void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void glColor3f(GLfloat r, GLfloat g, GLfloat b);

void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2i(GLint x, GLint y);

void glTexCoord2f(GLfloat s, GLfloat t);

GLuint glGenLists(GLsizei range);
void glCallList(GLuint list);
void glDeleteList(GLuint list);
void glDeleteLists(GLuint list, GLsizei range);
void glEndList(GLuint list);
void glNewList(GLuint list);
