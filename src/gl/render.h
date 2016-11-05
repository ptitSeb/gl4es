#ifndef RENDER_H
#define RENDER_H
#include "gl.h"

GLint gl4es_glRenderMode(GLenum mode);
void gl4es_glInitNames();
void gl4es_glPopName();
void gl4es_glPushName(GLuint name);
void gl4es_glLoadName(GLuint name);
void gl4es_glSelectBuffer(GLsizei size, GLuint *buffer);

void select_glDrawElements(const pointer_state_t* vtx, GLenum mode, GLuint count, GLenum type, GLvoid * indices);
void select_glDrawArrays(const pointer_state_t* vtx, GLenum mode, GLuint first, GLuint count);
#endif
