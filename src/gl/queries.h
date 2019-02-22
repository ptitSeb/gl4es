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

typedef struct {
    GLuint id;
    GLenum target;
    int num;
} glquery_t;

KHASH_MAP_DECLARE_INT(queries, glquery_t *)

#endif // _GL4ES_QUERIES_H_
