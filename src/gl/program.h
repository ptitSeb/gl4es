#include "gl.h"

#ifndef __PROGRAM_H_
#define __PROGRAM_H_

#include "shader.h"
#include "uniform.h"

typedef struct {
    GLuint      index;
    GLint       real_index;
    GLenum      type;
    int         size;
    char*       name;
} attribloc_t;
KHASH_MAP_INIT_INT(attribloclist, attribloc_t *)

typedef struct {
    GLuint          internal_id; // internal id of the uniform
    GLuint          id;     // glsl id of the uniform
    GLenum          type;   // type of the uniform (GL_VERTEX or GL_FRAGMENT)
    GLint           size;
    char*           name; // original source of the uniform
    uintptr_t       cache_offs;
    int             cache_size; // this is GLsizeof(type)*size
} uniform_t;

KHASH_MAP_INIT_INT(uniformlist, uniform_t *)

typedef struct {
    void*           cache;  // buffer of the uniform size
    int             cap;    // capacity of the cache
    int             size;   // next available free space in the cache
} uniformcache_t;

typedef struct {
    GLuint          id;     // internal id of the shader
    int             linked;
    int             validated;
    GLenum          valid_result;
    int             attach_cap;
    int             attach_size;
    GLuint          *attach;
    khash_t(attribloclist)     *attribloc;
    khash_t(uniformlist) *uniform;
    uniformcache_t  cache;
} program_t;

KHASH_MAP_INIT_INT(programlist, program_t *)

void gl4es_glAttachShader(GLuint program, GLuint shader);
void gl4es_glBindAttribLocation(GLuint program, GLuint index, const GLchar *name);
GLuint gl4es_glCreateProgram(void);
void gl4es_glDeleteProgram(GLuint program);
void gl4es_glDetachShader(GLuint program, GLuint shader);
void gl4es_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
void gl4es_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
void gl4es_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLint gl4es_glGetAttribLocation(GLuint program, const GLchar *name);
void gl4es_glGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog);
void gl4es_glGetProgramiv(GLuint program, GLenum pname, GLint *params);
GLint gl4es_glGetUniformLocation(GLuint program, const GLchar *name);
GLboolean gl4es_glIsProgram(GLuint program);
void gl4es_glLinkProgram(GLuint program);
void gl4es_glUseProgram(GLuint program);
void gl4es_glValidateProgram(GLuint program);


#define CHECK_PROGRAM(type, program) \
    if(!program) { \
        noerrorShim(); \
        return (type)0; \
    } \
    program_t *glprogram = NULL; \
    khint_t k_##program; \
    { \
        int ret; \
        khash_t(programlist) *programs = glstate->glsl.programs; \
        k_##program = kh_get(programlist, programs, program); \
        if (k_##program != kh_end(programs)) \
            glprogram = kh_value(programs, k_##program); \
    } \
    if(!glprogram) { \
        errorShim(GL_INVALID_OPERATION); \
        return (type)0; \
    }


#endif