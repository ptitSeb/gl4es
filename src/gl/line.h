#include "gl.h"

bool bLineStipple;
GLint stippleFactor;
GLushort stipplePattern;

GLuint genStippleTex(GLint factor, GLint pattern, GLfloat *pixels,
                     GLfloat *vert, GLfloat **tex, int length);
