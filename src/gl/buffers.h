#include "gl.h"

#ifndef GL_BUFFERS_H
#define GL_BUFFERS_H

// VBO *****************
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

void glshim_glGenBuffers(GLsizei n, GLuint * buffers);
void glshim_glBindBuffer(GLenum target, GLuint buffer);
void glshim_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
void glshim_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
void glshim_glDeleteBuffers(GLsizei n, const GLuint * buffers);
GLboolean glshim_glIsBuffer(GLuint buffer);
void glshim_glGetBufferParameteriv(GLenum target, GLenum value, GLint * data);

void *glshim_glMapBuffer(GLenum target, GLenum access);
GLboolean glshim_glUnmapBuffer(GLenum target);
void glshim_glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);
void glshim_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);

void glGenBuffers(GLsizei n, GLuint * buffers);
void glBindBuffer(GLenum target, GLuint buffer);
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
void glDeleteBuffers(GLsizei n, const GLuint * buffers);
GLboolean glIsBuffer(GLuint buffer);
void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data);
void *glMapBuffer(GLenum target, GLenum access);
GLboolean glUnmapBuffer(GLenum target);
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);

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

// Pointer..... ******
typedef struct {
    GLint size;
    GLenum type;
    GLsizei stride;
    glbuffer_t *buffer;
    const GLvoid *pointer;
} pointer_state_t;

typedef struct {
    pointer_state_t vertex, color, normal, tex_coord[MAX_TEX], secondary;
} pointer_states_t;

// VAO ****************
typedef struct {
    GLuint           array;
    // pointer state
    pointer_states_t pointers;
    // buffer state
    glbuffer_t *vertex;
    glbuffer_t *elements;
    glbuffer_t *pack;
    glbuffer_t *unpack;
    // client state
    GLboolean  secondary_array,
               color_array,
               normal_array,
               vertex_array,
               tex_coord_array[MAX_TEX];
} glvao_t;

KHASH_MAP_INIT_INT(glvao, glvao_t*)

void glshim_glGenVertexArrays(GLsizei n, GLuint *arrays);
void glshim_glBindVertexArray(GLuint array);
void glshim_glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
GLboolean glshim_glIsVertexArray(GLuint array);

void glGenVertexArrays(GLsizei n, GLuint *arrays);
void glBindVertexArray(GLuint array);
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
GLboolean glIsVertexArray(GLuint array);
#endif
