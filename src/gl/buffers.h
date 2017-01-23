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

void gl4es_glGenBuffers(GLsizei n, GLuint * buffers);
void gl4es_glBindBuffer(GLenum target, GLuint buffer);
void gl4es_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
void gl4es_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
void gl4es_glDeleteBuffers(GLsizei n, const GLuint * buffers);
GLboolean gl4es_glIsBuffer(GLuint buffer);
void gl4es_glGetBufferParameteriv(GLenum target, GLenum value, GLint * data);

void *gl4es_glMapBuffer(GLenum target, GLenum access);
GLboolean gl4es_glUnmapBuffer(GLenum target);
void gl4es_glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);
void gl4es_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);

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
    const GLvoid *pointer;
} pointer_state_t;

typedef struct {
    pointer_state_t vertex, color, normal, tex_coord[MAX_TEX], secondary;
} pointer_states_t;

typedef struct {
    GLfloat *ptr;
    pointer_state_t state;
    GLboolean enabled;
} pointer_cache_t;

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
    // VAO optimisation: keep a shared copy of the digested datas (unless the vao is the default one)
    int *shared_arrays;
    pointer_cache_t vert;
    pointer_cache_t normal;
    pointer_cache_t color;
    pointer_cache_t secondary;
    pointer_cache_t tex[MAX_TEX];
    int cache_count;
} glvao_t;

void VaoSharedClear(glvao_t *vao);

KHASH_MAP_INIT_INT(glvao, glvao_t*)

void gl4es_glGenVertexArrays(GLsizei n, GLuint *arrays);
void gl4es_glBindVertexArray(GLuint array);
void gl4es_glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
GLboolean gl4es_glIsVertexArray(GLuint array);

void glGenVertexArrays(GLsizei n, GLuint *arrays);
void glBindVertexArray(GLuint array);
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
GLboolean glIsVertexArray(GLuint array);
#endif
