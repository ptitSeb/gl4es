#include "gl.h"

#ifndef GL_BUFFERS_H
#define GL_BUFFERS_H

typedef struct {
    GLuint      buffer;
    GLenum      type;
    GLsizeiptr  size;
    GLenum      usage;
    GLint		access;
    int			mapped;
    GLvoid     *data;
} glbuffer_t;

KHASH_MAP_INIT_INT(buff, glbuffer_t *)

/*
extern void glGenBuffers(GLsizei n, GLuint * buffers);
extern void glBindBuffer(GLenum target, GLuint buffer);
extern void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
extern void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
extern void glDeleteBuffers(GLsizei n, const GLuint * buffers);
extern GLboolean glIsBuffer(GLuint buffer);
extern void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data);
*/
void *glMapBuffer(GLenum target, GLenum access);
GLboolean glUnmapBuffer(GLenum target);
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);
extern void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);

void glGenBuffersARB(GLsizei n, GLuint * buffers);
void glBindBufferARB(GLenum target, GLuint buffer);
void glBufferDataARB(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
void glBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
void glDeleteBuffersARB(GLsizei n, const GLuint * buffers);
GLboolean glIsBufferARB(GLuint buffer);
void glGetBufferParameterivARB(GLenum target, GLenum value, GLint * data);
void *glMapBufferARB(GLenum target, GLenum access);
GLboolean glUnmapBufferARB(GLenum target);
void glGetBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid ** params);

#endif
