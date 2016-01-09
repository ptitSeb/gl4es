#ifndef RENDER_H
#define RENDER_H
#include "gl.h"

GLint glshim_glRenderMode(GLenum mode);
void glshim_glInitNames();
void glshim_glPopName();
void glshim_glPushName(GLuint name);
void glshim_glLoadName(GLuint name);
void glshim_glSelectBuffer(GLsizei size, GLuint *buffer);

void select_glDrawElements(const pointer_state_t* vtx, GLenum mode, GLuint count, GLenum type, GLvoid * indices);
void select_glDrawArrays(const pointer_state_t* vtx, GLenum mode, GLuint first, GLuint count);
#endif
