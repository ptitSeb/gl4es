#include "gl.h"

void gl4es_glLineStipple(GLuint factor, GLushort pattern);
GLfloat *gen_stipple_tex_coords(GLfloat *vert, int length);
void bind_stipple_tex();
