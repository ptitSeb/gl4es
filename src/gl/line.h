#include "gl.h"

bool bLineStipple;
GLint stippleFactor;
GLushort stipplePattern;

GLuint genStippleTex(GLint factor, GLint pattern, GLfloat *vert,
                     GLubyte **pixels, GLfloat **tex, int length);
