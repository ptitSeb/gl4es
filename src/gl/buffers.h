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


extern void glGenBuffers(GLsizei n, GLuint * buffers);
extern void glBindBuffer(GLenum target, GLuint buffer);
extern void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
extern void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
extern void glDeleteBuffers(GLsizei n, const GLuint * buffers);
extern GLboolean glIsBuffer(GLuint buffer);
extern void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data);
extern void *glMapBuffer(GLenum target, GLenum access);
extern GLboolean glUnmapBuffer(GLenum target);
extern void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
extern void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);

extern void glGenBuffersARB(GLsizei n, GLuint * buffers);
extern void glBindBufferARB(GLenum target, GLuint buffer);
extern void glBufferDataARB(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
extern void glBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
extern void glDeleteBuffersARB(GLsizei n, const GLuint * buffers);
extern GLboolean glIsBufferARB(GLuint buffer);
extern void glGetBufferParameterivARB(GLenum target, GLenum value, GLint * data);
extern void *glMapBufferARB(GLenum target, GLenum access);
extern GLboolean glUnmapBufferARB(GLenum target);
extern void glGetBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
extern void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid ** params);

#endif
