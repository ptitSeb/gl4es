#include "gl.h"

#ifndef __UNIFORM_H_
#define __UNIFORM_H_

int uniformsize(GLenum type);
int is_uniform_int(GLenum type);
int is_uniform_float(GLenum type);
int is_uniform_matrix(GLenum type);
int n_uniform(GLenum type);

void gl4es_glGetUniformfv(GLuint program, GLint location, GLfloat *params);
void gl4es_glGetUniformiv(GLuint program, GLint location, GLint *params);

void gl4es_glUniform1f(GLint location, GLfloat v0);
void gl4es_glUniform2f(GLint location, GLfloat v0, GLfloat v1);
void gl4es_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void gl4es_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void gl4es_glUniform1i(GLint location, GLint v0);
void gl4es_glUniform2i(GLint location, GLint v0, GLint v1); 
void gl4es_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2); 
void gl4es_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);

void gl4es_glUniform1fv(GLint location, GLsizei count, const GLfloat *value); 
void gl4es_glUniform2fv(GLint location, GLsizei count, const GLfloat *value); 
void gl4es_glUniform3fv(GLint location, GLsizei count, const GLfloat *value);
void gl4es_glUniform4fv(GLint location, GLsizei count, const GLfloat *value);
void gl4es_glUniform1iv(GLint location, GLsizei count, const GLint *value);
void gl4es_glUniform2iv(GLint location, GLsizei count, const GLint *value);
void gl4es_glUniform3iv(GLint location, GLsizei count, const GLint *value);
void gl4es_glUniform4iv(GLint location, GLsizei count, const GLint *value);

void gl4es_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void gl4es_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void gl4es_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

#endif