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

#define GLW_LIST_SIZE 12*256*sizeof(GLfloat)

void glBegin(GLenum mode);
void glEnd();

void glClearDepth(GLclampf depth);

void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void glColor3f(GLfloat r, GLfloat g, GLfloat b);

void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2i(GLint x, GLint y);

void glTexCoord2f(GLfloat s, GLfloat t);

GLuint glGenLists(GLsizei range);
void glCallList(GLuint list);
void glDeleteList(GLuint list);
void glEndList(GLuint list);
void glNewList(GLuint list);

// stubs
void glClearDepth(GLfloat depth);
