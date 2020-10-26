#ifndef _GL4ES_QUERIES_H_
#define _GL4ES_QUERIES_H_

#include "khash.h"
#include "gles.h"

void gl4es_glBeginQuery(GLenum target, GLuint id);
void gl4es_glEndQuery(GLenum target);
void gl4es_glGenQueries(GLsizei n, GLuint * ids);
void gl4es_glDeleteQueries(GLsizei n, const GLuint* ids);
GLboolean gl4es_glIsQuery(GLuint id);
void gl4es_glGetQueryiv(GLenum target, GLenum pname, GLint* params);
void gl4es_glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params);
void gl4es_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params);
void gl4es_glQueryCounter(GLuint id, GLenum target);
void gl4es_glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params);
void gl4es_glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params);

unsigned long long get_clock();

#endif // _GL4ES_QUERIES_H_
