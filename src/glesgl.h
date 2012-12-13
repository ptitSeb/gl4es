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

#define GLW_LIST_SIZE 12*256*sizeof(GLFloat)

void glBegin(GLenum mode);
void glEnd();

// TODO: dlsym or whatever and allow passthrough of identical calls
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glVertex2f(GLfloat x, GLfloat y) {
    glVertex3f(x, y, 0);
}

void glwColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void glColor3f(GLfloat r, GLFloat g, GLFloat b) {
    glColor4f(r, g, b, 1.0f);
}

void glwTexCoord2f(GLfloat s, GLfloat t);
GLuint glGenLists(GLsizei range);
void glNewList(GLuint list);
void glEndList(GLuint list);
void glCallList(GLuint list);
void glDeleteList(GLuint list);
