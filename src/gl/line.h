#include "gl.h"

void gl4es_glLineStipple(GLuint factor, GLushort pattern);
GLfloat *gen_stipple_tex_coords(GLfloat *vert, GLenum mode, int stride, int length, GLfloat* noalloctex);
void bind_stipple_tex();
