#include "gl.h"

extern void glLineStipple(GLuint factor, GLushort pattern);
extern GLuint gen_stipple_tex(GLfloat *vert, GLfloat **tex, int length);
