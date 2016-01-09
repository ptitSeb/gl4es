#include "gl.h"

void glshim_glLightModelf(GLenum pname, GLfloat param);
void glshim_glLightModelfv(GLenum pname, const GLfloat* params);
void glshim_glLightfv(GLenum light, GLenum pname, const GLfloat* params);
void glshim_glLightf(GLenum light, GLenum pname, const GLfloat params);
