#include "gl.h"

#ifndef GL_QUERIES_H
#define GL_QUERIES_H

void glshim_glBeginQuery(GLenum target, GLuint id);
void glshim_glEndQuery(GLenum target);
void glshim_glGenQueries(GLsizei n, GLuint * ids);
void glshim_glDeleteQueries(GLsizei n, const GLuint* ids);
GLboolean glshim_glIsQuery(GLuint id);
void glshim_glGetQueryiv(GLenum target, GLenum pname, GLint* params);
void glshim_glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params);
void glshim_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params);

typedef struct {
    GLuint id;
    GLenum target;
    int num;
} glquery_t;

KHASH_MAP_INIT_INT(queries, glquery_t *)

#endif