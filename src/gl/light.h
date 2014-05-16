#include "gl.h"

void glLightModelf(GLenum pname, GLfloat param);
void glLightModelfv(GLenum pname, const GLfloat* params);
void glLightfv(GLenum light, GLenum pname, const GLfloat* params);
void glLightf(GLenum light, GLenum pname, const GLfloat params);
