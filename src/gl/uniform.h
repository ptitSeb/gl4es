#ifndef _GL4ES_UNIFORM_H_
#define _GL4ES_UNIFORM_H_

#include "gles.h"

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

// ========== GL_ARB_shader_objects ==============
GLvoid glUniform1fARB(GLint location, GLfloat v0);
GLvoid glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
GLvoid glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLvoid glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLvoid glUniform1iARB(GLint location, GLint v0);
GLvoid glUniform2iARB(GLint location, GLint v0, GLint v1);
GLvoid glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
GLvoid glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLvoid glUniform1fvARB(GLint location, GLsizei count, const GLfloat *value);
GLvoid glUniform2fvARB(GLint location, GLsizei count, const GLfloat *value);
GLvoid glUniform3fvARB(GLint location, GLsizei count, const GLfloat *value);
GLvoid glUniform4fvARB(GLint location, GLsizei count, const GLfloat *value);
GLvoid glUniform1ivARB(GLint location, GLsizei count, const GLint *value);
GLvoid glUniform2ivARB(GLint location, GLsizei count, const GLint *value);
GLvoid glUniform3ivARB(GLint location, GLsizei count, const GLint *value);
GLvoid glUniform4ivARB(GLint location, GLsizei count, const GLint *value);
GLvoid glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLvoid glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLvoid glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
// ===========
void gl4es_glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
void gl4es_glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void gl4es_glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void gl4es_glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void gl4es_glProgramUniform1i(GLuint program, GLint location, GLint v0);
void gl4es_glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1); 
void gl4es_glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2); 
void gl4es_glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);

void gl4es_glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value); 
void gl4es_glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value); 
void gl4es_glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void gl4es_glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void gl4es_glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value);
void gl4es_glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value);
void gl4es_glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value);
void gl4es_glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value);

void gl4es_glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void gl4es_glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void gl4es_glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);


#endif // _GL4ES_UNIFORM_H_
