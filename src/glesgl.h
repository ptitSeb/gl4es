#include <GLES/gl.h>
#include <inttypes.h>
#include <stdbool.h>
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

#define GLW_LIST_SIZE sizeof(GLfloat)*12*256

void glBegin(GLenum mode);
void glEnd();
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glwColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void glwTexCoord2f(GLfloat s, GLfloat t);
GLuint glGenLists(GLsizei range);
void glNewList(GLuint list);
void glEndList(GLuint list);
void glCallList(GLuint list);
void glDeleteList(GLuint list);
