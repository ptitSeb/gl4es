#ifndef RENDER_H
#define RENDER_H
#include "gl.h"

GLint glRenderMode(GLenum mode);
void glInitNames();
void glPopName();
void glPushName(GLuint name);
void glLoadName(GLuint name);
void glSelectBuffer(GLsizei size, GLuint *buffer);

void select_glDrawElements(GLenum mode, GLuint count, GLenum type, GLvoid * indices);
void select_glDrawArrays(GLenum mode, GLuint first, GLuint count);
#endif
