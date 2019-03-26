#ifndef _GL4ES_BUFFERS_H_
#define _GL4ES_BUFFERS_H_

#include "khash.h"
#include "../config.h"
#include "gles.h"

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

KHASH_MAP_DECLARE_INT(buff, glbuffer_t *);

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

void *gl4es_glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void gl4es_glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);

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

void *glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);

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
    GLboolean enabled;
} pointer_state_t;

typedef enum {
    ATT_VERTEX = 0,
    ATT_COLOR,
    ATT_MULTITEXCOORD0,
    ATT_MULTITEXCOORD1,
    ATT_MULTITEXCOORD2,
    ATT_MULTITEXCOORD3,
    ATT_MULTITEXCOORD4,
    ATT_MULTITEXCOORD5,
    ATT_MULTITEXCOORD6,
    ATT_MULTITEXCOORD7,
    ATT_NORMAL,
    ATT_SECONDARY,
    ATT_FOGCOORD,
    //ATT_POINTSIZE,   //this one is supported by GLES hardware
    ATT_MAX
} reserved_attrib_t;

#define NB_VA (ATT_MAX)

typedef struct {
    GLfloat *ptr;
    pointer_state_t state;
    GLboolean enabled;
} pointer_cache_t;

// Vertex Attrib.. ***
typedef struct {
    GLint           size;
    GLenum          type;
    GLsizei         stride;
    const GLvoid*   pointer;
    GLboolean       vaarray;
    GLboolean       normalized;
    glbuffer_t      *buffer;    // reference buffer
    GLfloat         current[4];
    GLint           divisor;
} vertexattrib_t;

// VAO ****************
typedef struct {
    GLuint           array;
    // pointer state
    pointer_state_t  pointers[NB_VA];
    // buffer state
    glbuffer_t *vertex;
    glbuffer_t *elements;
    glbuffer_t *pack;
    glbuffer_t *unpack;
    // locked arrays
    GLboolean locked;
    GLsizei   count;
    GLint     first;
    GLboolean locked_mapped;
    pointer_state_t   locked_pointers[NB_VA];

    int maxtex; // upper limit enabled tex_coord
    // VAO optimisation: keep a shared copy of the digested datas (unless the vao is the default one)
    int *shared_arrays;
    pointer_cache_t vert;
    pointer_cache_t normal;
    pointer_cache_t color;
    pointer_cache_t secondary;
    pointer_cache_t fog;
    pointer_cache_t tex[MAX_TEX];
    int cache_count;
    // Vertex Attrib
    vertexattrib_t  vertexattrib[MAX_VATTRIB];
    // TODO: Cache VA also?
} glvao_t;

void VaoSharedClear(glvao_t *vao);
void VaoInit(glvao_t *vao);

KHASH_MAP_DECLARE_INT(glvao, glvao_t*);

void gl4es_glGenVertexArrays(GLsizei n, GLuint *arrays);
void gl4es_glBindVertexArray(GLuint array);
void gl4es_glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
GLboolean gl4es_glIsVertexArray(GLuint array);

void glGenVertexArrays(GLsizei n, GLuint *arrays);
void glBindVertexArray(GLuint array);
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
GLboolean glIsVertexArray(GLuint array);

void gl4es_glNamedBufferData(GLuint buffer, GLsizeiptr size, const GLvoid * data, GLenum usage);
void gl4es_glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid * data);
void gl4es_glGetNamedBufferParameteriv(GLuint buffer, GLenum value, GLint * data);
void* gl4es_glMapNamedBuffer(GLuint buffer, GLenum access);
GLboolean gl4es_glUnmapNamedBuffer(GLuint buffer);
void gl4es_glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid * data);
void gl4es_glGetNamedBufferPointerv(GLuint buffer, GLenum pname, GLvoid ** params);

#endif // _GL4ES_BUFFERS_H_
