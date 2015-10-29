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

void glGenVertexArrays(GLsizei n, GLuint *arrays);
void glBindVertexArray(GLuint array);
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
GLboolean glIsVertexArray(GLuint array);

#endif
