#include "gl.h"
#include <math.h>

void glTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void genTexCoords(GLfloat *verts, GLfloat **coords, GLint count);
