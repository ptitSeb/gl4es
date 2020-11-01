#include "uniform.h"

#include "../glx/hardext.h"
#include "gl4es.h"
#include "glstate.h"
#include "loader.h"
#include "matvec.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

int uniformsize(GLenum type) {
    #define GO(T, t, s) \
        case T: return sizeof(t)*s
    #define GOV(T, t) \
        GO(T, t, 1); \
        GO(T##_VEC2, t, 2); \
        GO(T##_VEC3, t, 3); \
        GO(T##_VEC4, t, 4)
    #define GOM(T, t) \
        GO(T##_MAT2, t, 2*2); \
        GO(T##_MAT3, t, 3*3); \
        GO(T##_MAT4, t, 4*4);
    switch(type) {
    // GLES2 types
        GOV(GL_FLOAT, GLfloat);
        GOV(GL_INT, GLint);
        GOV(GL_BOOL, /*GLboolean*/GLint); //GLboolean is an unsigned char and is not suitable here
        GOM(GL_FLOAT, GLfloat);
        GO(GL_SAMPLER_2D, GLint, 1);
        GO(GL_SAMPLER_CUBE , GLint, 1);
    // Need other types?
    }
    return 0;
    #undef GOM
    #undef GOV
    #undef GO
}

int is_uniform_float(GLenum type) {
    switch (type) {
        case GL_FLOAT:
        case GL_FLOAT_VEC2:
        case GL_FLOAT_VEC3:
        case GL_FLOAT_VEC4:
        case GL_FLOAT_MAT2:
        case GL_FLOAT_MAT3:
        case GL_FLOAT_MAT4:
            return 1;
    }
    return 0;
}
int is_uniform_int(GLenum type) {
    switch (type) {
        case GL_INT:
        case GL_INT_VEC2:
        case GL_INT_VEC3:
        case GL_INT_VEC4:
        case GL_BOOL:
        case GL_BOOL_VEC2:
        case GL_BOOL_VEC3:
        case GL_BOOL_VEC4:
        case GL_SAMPLER_2D:
        case GL_SAMPLER_CUBE:
            return 1;
    }
    return 0;
}
int is_uniform_matrix(GLenum type) {
    switch (type) {
        case GL_FLOAT_MAT2:
        case GL_FLOAT_MAT3:
        case GL_FLOAT_MAT4:
            return 1;
    }
    return 0;
}

int n_uniform(GLenum type) {
    // matrix type will return 0
    switch(type) {
        case GL_FLOAT:
        case GL_INT:
        case GL_BOOL:
        case GL_SAMPLER_2D:
        case GL_SAMPLER_CUBE:
            return 1;
        case GL_FLOAT_VEC2:
        case GL_INT_VEC2:
        case GL_BOOL_VEC2:
            return 2;
        case GL_FLOAT_VEC3:
        case GL_INT_VEC3:
        case GL_BOOL_VEC3:
            return 3;
        case GL_FLOAT_VEC4:
        case GL_INT_VEC4:
        case GL_BOOL_VEC4:
            return 4;
    }
    return 0;
}

void gl4es_glGetUniformfv(GLuint program, GLint location, GLfloat *params) {
    DBG(printf("glGetUniformfv(%d, %d, %p)\n", program, location, params);)
    FLUSH_BEGINEND;
    CHECK_PROGRAM(void, program);

    khint_t k;
    uniform_t *gluniform = NULL;
    k = kh_get(uniformlist, glprogram->uniform, k);
    if(k!=kh_end(glprogram->uniform)) {
        gluniform = kh_value(glprogram->uniform, k);
        uintptr_t offs = gluniform->cache_offs;
        int size = gluniform->cache_size;
        if(is_uniform_float(gluniform->type)) {
            memcpy(params, glprogram->cache.cache+offs, size);
            noerrorShim();
            return;
        }
        // if it's not float, it can be only int for now
        int n = size / sizeof(GLint);
        GLint *fl = (GLint*)(glprogram->cache.cache + offs);
        for (int i=0; i<n; i++)
            params[i] = fl[i];  // this is probably good, int->float is straight forward
        noerrorShim();
        return;
    }
    errorShim(GL_INVALID_VALUE);
}
void gl4es_glGetUniformiv(GLuint program, GLint location, GLint *params) {
    DBG(printf("glGetUniformiv(%d, %d, %p)\n", program, location, params);)
    FLUSH_BEGINEND;
    CHECK_PROGRAM(void, program);

    khint_t k;
    uniform_t *gluniform = NULL;
    k = kh_get(uniformlist, glprogram->uniform, k);
    if(k!=kh_end(glprogram->uniform)) {
        gluniform = kh_value(glprogram->uniform, k);
        uintptr_t offs = gluniform->cache_offs;
        int size = gluniform->cache_size;
        if(is_uniform_int(gluniform->type)) {
            memcpy(params, glprogram->cache.cache+offs, size);
            noerrorShim();
            return;
        }
        // if it's not int, it can be only float for now
        int n = size / sizeof(GLfloat);
        GLfloat *fl = (GLfloat*)(glprogram->cache.cache + offs);
        for (int i=0; i<n; i++)
            params[i] = fl[i];  // is this correct? float -> int without adjustment?
        noerrorShim();
        return;
    }
    errorShim(GL_INVALID_VALUE);
}

void GoUniformfv(program_t *glprogram, GLint location, int size, int count, const GLfloat *value)
{
    DBG(printf("GoUniformfv(%p[%d], %d, %d, %d, %p) =>(%f...)\n", glprogram, glprogram->id, location, size, count, value, value[0]);)
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    m = kh_value(glprogram->uniform, k);
    if(size != n_uniform(m->type) || !is_uniform_float(m->type) || count>m->size) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    // ok, check the value in the cache
    int rsize = sizeof(GLfloat)*size*count;
    if (memcmp(glprogram->cache.cache + m->cache_offs, value, rsize)==0) {
        noerrorShim();
        return; // nothing to do, same value already there
    }
    // update uniform
    memcpy(glprogram->cache.cache + m->cache_offs, value, rsize);
    LOAD_GLES2(glUniform1fv);
    LOAD_GLES2(glUniform2fv);
    LOAD_GLES2(glUniform3fv);
    LOAD_GLES2(glUniform4fv);
    if(gles_glUniform1fv) {
        switch (size) {
            case 1: gles_glUniform1fv(m->id, count, value); break;
            case 2: gles_glUniform2fv(m->id, count, value); break;
            case 3: gles_glUniform3fv(m->id, count, value); break;
            case 4: gles_glUniform4fv(m->id, count, value); break;
        }
        errorGL();
    } else
        errorShim(GL_INVALID_OPERATION);    // no GLLS hardware
}
void GoUniformiv(program_t *glprogram, GLint location, int size, int count, const GLint *value)
{
    DBG(printf("GoUniformiv(%p[%d], %d, %d, %d, %p) =>(%d...)\n", glprogram, glprogram->id, location, size, count, value, value[0]);)
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }

    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    m = kh_value(glprogram->uniform, k);
    if(size != n_uniform(m->type) || !is_uniform_int(m->type)  || count>m->size) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    // ok, check the value in the cache
    int rsize = sizeof(GLint)*size*count;
    if (memcmp(glprogram->cache.cache + m->cache_offs, value, rsize)==0) {
        noerrorShim();
        return; // nothing to do, same value already there
    }
    DBG(printf("Uniform updated, cache=%p(%d/%d), offset=%p, size=%d\n", glprogram->cache.cache, glprogram->cache.size, glprogram->cache.cap, m->cache_offs, rsize);)
    // update uniform
    memcpy(glprogram->cache.cache + m->cache_offs, value, rsize);
    LOAD_GLES2(glUniform1iv);
    LOAD_GLES2(glUniform2iv);
    LOAD_GLES2(glUniform3iv);
    LOAD_GLES2(glUniform4iv);
    if(gles_glUniform1iv) {
        switch (size) {
            case 1: gles_glUniform1iv(m->id, count, value); break;
            case 2: gles_glUniform2iv(m->id, count, value); break;
            case 3: gles_glUniform3iv(m->id, count, value); break;
            case 4: gles_glUniform4iv(m->id, count, value); break;
        }
        errorGL();
    } else
        errorShim(GL_INVALID_OPERATION);    // no GLLS hardware
}

void gl4es_glUniform1f(GLint location, GLfloat v0) {
    DBG(printf("glUniform1f(%d, %f)\n", location, v0);)
    PUSH_IF_COMPILING(glUniform1f);
    GLuint program = glstate->glsl->program; 
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 1, 1, &v0);
}
void gl4es_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    DBG(printf("glUniform2f(%d, %f, %f)\n", location, v0, v1);)
    PUSH_IF_COMPILING(glUniform2f);
    GLfloat fl[2] = {v0, v1};
    GLuint program = glstate->glsl->program; 
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 2, 1, fl);
}
void gl4es_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    DBG(printf("glUniform3f(%d, %f, %f, %f)\n", location, v0, v1, v2);)
    PUSH_IF_COMPILING(glUniform3f);
    GLfloat fl[3] = {v0, v1, v2};
    GLuint program = glstate->glsl->program; 
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 3, 1, fl);
}
void gl4es_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    DBG(printf("glUniform4f(%d, %f, %f, %f, %f)\n", location, v0, v1, v2, v3);)
    PUSH_IF_COMPILING(glUniform4f);
    GLfloat fl[4] = {v0, v1, v2, v3};
    GLuint program = glstate->glsl->program; 
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 4, 1, fl);
}
void gl4es_glUniform1i(GLint location, GLint v0) {
    DBG(printf("glUniform1i(%d, %d)\n", location, v0);)
    PUSH_IF_COMPILING(glUniform1i);
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 1, 1, &v0);
}
void gl4es_glUniform2i(GLint location, GLint v0, GLint v1) {
    DBG(printf("glUniform2i(%d, %d, %d)\n", location, v0, v1);)
    PUSH_IF_COMPILING(glUniform2i);
    GLint fl[2] = {v0, v1};
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 2, 1, fl);
}
void gl4es_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    DBG(printf("glUniform3i(%d, %d, %d, %d)\n", location, v0, v1, v2);)
    PUSH_IF_COMPILING(glUniform3i);
    GLint fl[3] = {v0, v1, v2};
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 3, 1, fl);
}
void gl4es_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    DBG(printf("glUniform4i(%d, %d, %d, %d, %d)\n", location, v0, v1, v2, v3);)
    PUSH_IF_COMPILING(glUniform4i);
    GLint fl[4] = {v0, v1, v2, v3};
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 4, 1, fl);
}
//TODO: the "v" variant and matrix variant cannot be pushed simply...
void gl4es_glUniform1fv(GLint location, GLsizei count, const GLfloat *value) {
    DBG(printf("glUniform1fv(%d, %d, %p) =>(%f)\n", location, count, value, value[0]);)
    PUSH_IF_COMPILING(glUniform1fv);
    GLuint program = glstate->glsl->program; 
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 1, count, value);
}
void gl4es_glUniform2fv(GLint location, GLsizei count, const GLfloat *value) {
    DBG(printf("glUniform2fv(%d, %d, %p) =>(%f %f)\n", location, count, value, value[0], value[1]);)
    PUSH_IF_COMPILING(glUniform2fv);
    GLuint program = glstate->glsl->program; 
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 2, count, value);
}
void gl4es_glUniform3fv(GLint location, GLsizei count, const GLfloat *value) {
    DBG(printf("glUniform3fv(%d, %d, %p) =>(%f %f, %f)\n", location, count, value, value[0], value[1], value[2]);)
    PUSH_IF_COMPILING(glUniform3fv);
    GLuint program = glstate->glsl->program; 
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 3, count, value);
}
void gl4es_glUniform4fv(GLint location, GLsizei count, const GLfloat *value) {
    DBG(printf("glUniform4fv(%d, %d, %p) =>(%f %f, %f, %f)\n", location, count, value, value[0], value[1], value[2], value[3]);)
    PUSH_IF_COMPILING(glUniform4fv);
    GLuint program = glstate->glsl->program; 
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 4, count, value);
}
void gl4es_glUniform1iv(GLint location, GLsizei count, const GLint *value) {
    PUSH_IF_COMPILING(glUniform1iv);
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 1, count, value);
}
void gl4es_glUniform2iv(GLint location, GLsizei count, const GLint *value) {
    PUSH_IF_COMPILING(glUniform2iv);
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 2, count, value);
}
void gl4es_glUniform3iv(GLint location, GLsizei count, const GLint *value) {
    PUSH_IF_COMPILING(glUniform3iv);
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 3, count, value);
}
void gl4es_glUniform4iv(GLint location, GLsizei count, const GLint *value) {
    PUSH_IF_COMPILING(glUniform4iv);
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 4, count, value);
}

void gl4es_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("glUniformMatrix2fv(%d, %d, %d, %p)\n", location, count, transpose, value);)
    PUSH_IF_COMPILING(glUniformMatrix2fv);
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformMatrix2fv(glprogram, location, count, transpose, value);
}

void gl4es_glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
    DBG(printf("glUniform1f(%d, %f)\n", location, v0);)
    PUSH_IF_COMPILING(glUniform1f);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 1, 1, &v0);
}
void gl4es_glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
    DBG(printf("glUniform2f(%d, %f, %f)\n", location, v0, v1);)
    PUSH_IF_COMPILING(glUniform2f);
    GLfloat fl[2] = {v0, v1};
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 2, 1, fl);
}
void gl4es_glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    DBG(printf("glUniform3f(%d, %f, %f, %f)\n", location, v0, v1, v2);)
    PUSH_IF_COMPILING(glUniform3f);
    GLfloat fl[3] = {v0, v1, v2};
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 3, 1, fl);
}
void gl4es_glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    DBG(printf("glUniform4f(%d, %f, %f, %f, %f)\n", location, v0, v1, v2, v3);)
    PUSH_IF_COMPILING(glUniform4f);
    GLfloat fl[4] = {v0, v1, v2, v3};
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 4, 1, fl);
}
void gl4es_glProgramUniform1i(GLuint program, GLint location, GLint v0) {
    DBG(printf("glUniform1i(%d, %d)\n", location, v0);)
    PUSH_IF_COMPILING(glUniform1i);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 1, 1, &v0);
}
void gl4es_glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {
    DBG(printf("glUniform2i(%d, %d, %d)\n", location, v0, v1);)
    PUSH_IF_COMPILING(glUniform2i);
    GLint fl[2] = {v0, v1};
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 2, 1, fl);
}
void gl4es_glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
    DBG(printf("glUniform3i(%d, %d, %d, %d)\n", location, v0, v1, v2);)
    PUSH_IF_COMPILING(glUniform3i);
    GLint fl[3] = {v0, v1, v2};
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 3, 1, fl);
}
void gl4es_glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    DBG(printf("glUniform4i(%d, %d, %d, %d, %d)\n", location, v0, v1, v2, v3);)
    PUSH_IF_COMPILING(glUniform4i);
    GLint fl[4] = {v0, v1, v2, v3};
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 4, 1, fl);
}
//TODO: the "v" variant and matrix variant cannot be pushed simply...
void gl4es_glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    DBG(printf("glUniform1fv(%d, %d, %p) =>(%f)\n", location, count, value, value[0]);)
    PUSH_IF_COMPILING(glUniform1fv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 1, count, value);
}
void gl4es_glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    DBG(printf("glUniform2fv(%d, %d, %p) =>(%f %f)\n", location, count, value, value[0], value[1]);)
    PUSH_IF_COMPILING(glUniform2fv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 2, count, value);
}
void gl4es_glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    DBG(printf("glUniform3fv(%d, %d, %p) =>(%f %f, %f)\n", location, count, value, value[0], value[1], value[2]);)
    PUSH_IF_COMPILING(glUniform3fv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 3, count, value);
}
void gl4es_glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    DBG(printf("glUniform4fv(%d, %d, %p) =>(%f %f, %f, %f)\n", location, count, value, value[0], value[1], value[2], value[3]);)
    PUSH_IF_COMPILING(glUniform4fv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformfv(glprogram, location, 4, count, value);
}
void gl4es_glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) {
    PUSH_IF_COMPILING(glUniform1iv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 1, count, value);
}
void gl4es_glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) {
    PUSH_IF_COMPILING(glUniform2iv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 2, count, value);
}
void gl4es_glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) {
    PUSH_IF_COMPILING(glUniform3iv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 3, count, value);
}
void gl4es_glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) {
    PUSH_IF_COMPILING(glUniform4iv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformiv(glprogram, location, 4, count, value);
}

void gl4es_glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("glUniformMatrix2fv(%d, %d, %d, %p)\n", location, count, transpose, value);)
    PUSH_IF_COMPILING(glUniformMatrix2fv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformMatrix2fv(glprogram, location, count, transpose, value);
}

void GoUniformMatrix2fv(program_t *glprogram, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("GoUniformMatrix2fv(%p[%d], %d, %d, %d, %p)\n", glprogram, glprogram->id, location, count, transpose, value);)
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    m = kh_value(glprogram->uniform, k);
    if(m->type!=GL_FLOAT_MAT2  || count>m->size) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    // transpose if needed
    GLfloat *v = (GLfloat*)value;
    GLfloat tmp[4];
    if(transpose) {
        v = tmp;
        for (int n=0; n<count; n++)
            for (int i=0; i<2; i++)
                for (int j=0; j<2; j++)
                    v[n*2*2+i*2+j]=value[n*2*2+i+j*2];

    }
    // ok, check the value in the cache
    int rsize = sizeof(GLfloat)*2*2*count;
    if (memcmp(glprogram->cache.cache + m->cache_offs, v, rsize)==0) {
        noerrorShim();
        return; // nothing to do, same value already there
    }
    // update uniform
    memcpy(glprogram->cache.cache + m->cache_offs, v, rsize);
    LOAD_GLES2(glUniformMatrix2fv);
    if (gles_glUniformMatrix2fv) {
        gles_glUniformMatrix2fv(m->id, count, GL_FALSE, v);
        errorGL();
    } else
        errorShim(GL_INVALID_OPERATION);    // no GLSL hardware
}

void gl4es_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("glUniformMatrix3fv(%d, %d, %d, %p)\n", location, count, transpose, value);)
    PUSH_IF_COMPILING(glUniformMatrix3fv);
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformMatrix3fv(glprogram, location, count, transpose, value);
}

void gl4es_glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("glUniformMatrix3fv(%d, %d, %d, %p)\n", location, count, transpose, value);)
    PUSH_IF_COMPILING(glUniformMatrix3fv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformMatrix3fv(glprogram, location, count, transpose, value);
}

void GoUniformMatrix3fv(program_t *glprogram, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("GoUniformMatrix3fv(%p[%d], %d, %d, %d, %p)\n", glprogram, glprogram->id, location, count, transpose, value);)
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    m = kh_value(glprogram->uniform, k);
    if(m->type!=GL_FLOAT_MAT3  || count>m->size) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    // transpose if needed
    GLfloat *v = (GLfloat*)value;
    GLfloat tmp[9];
    if(transpose) {
        v = tmp;
        for (int n=0; n<count; n++)
            for (int i=0; i<3; i++)
                for (int j=0; j<3; j++)
                    v[n*3*3+i*3+j]=value[n*3*3+i+j*3];

    }
    // ok, check the value in the cache
    int rsize = sizeof(GLfloat)*3*3*count;
    if (memcmp(glprogram->cache.cache + m->cache_offs, v, rsize)==0) {
        noerrorShim();
        return; // nothing to do, same value already there
    }
    // update uniform
    memcpy(glprogram->cache.cache + m->cache_offs, v, rsize);
    LOAD_GLES2(glUniformMatrix3fv);
    if (gles_glUniformMatrix3fv) {
        gles_glUniformMatrix3fv(m->id, count, GL_FALSE, v);
        errorGL();
    } else
        errorShim(GL_INVALID_OPERATION);    // no GLSL hardware
}
void gl4es_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("glUniformMatrix4fv(%d, %d, %d, %p) p=>(%f, %f, %f, %f, %f...)\n", location, count, transpose, value, value[0], value[1], value[2], value[3], value[4]);)
    PUSH_IF_COMPILING(glUniformMatrix4fv);
    GLuint program = glstate->glsl->program;
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformMatrix4fv(glprogram, location, count, transpose, value);
}
void gl4es_glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("glUniformMatrix4fv(%d, %d, %d, %p) p=>(%f, %f, %f, %f, %f...)\n", location, count, transpose, value, value[0], value[1], value[2], value[3], value[4]);)
    PUSH_IF_COMPILING(glUniformMatrix4fv);
    CHECK_PROGRAM(void, program);
    APPLY_PROGRAM(program, glprogram);
    GoUniformMatrix4fv(glprogram, location, count, transpose, value);
}

void GoUniformMatrix4fv(program_t *glprogram, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    DBG(printf("GoUniformMatrix4fv(%p[%d], %d, %d, %d, %p) p=>(%f, %f, %f, %f, %f...)\n", glprogram, glprogram->id, location, count, transpose, value, value[0], value[1], value[2], value[3], value[4]);)
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    m = kh_value(glprogram->uniform, k);
    if(m->type!=GL_FLOAT_MAT4  || count>m->size) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    // transpose if needed
    GLfloat *v = (GLfloat*)value;
    GLfloat tmp[16];
    if(transpose) {
        v = tmp;
        for (int n=0; n<count; n++)
            matrix_transpose(value+n*4*4, v+n*4*4);

    }
    // ok, check the value in the cache
    int rsize = sizeof(GLfloat)*4*4*count;
    if (memcmp(glprogram->cache.cache + m->cache_offs, v, rsize)==0) {
        noerrorShim();
        return; // nothing to do, same value already there
    }
    // update uniform
    memcpy(glprogram->cache.cache + m->cache_offs, v, rsize);
    LOAD_GLES2(glUniformMatrix4fv);
    if (gles_glUniformMatrix4fv) {
        gles_glUniformMatrix4fv(m->id, count, GL_FALSE, v);
        errorGL();
    } else {
        //printf("No GLES2 function\n");
        errorShim(GL_INVALID_OPERATION);    // no GLSL hardware
    }
}

int GetUniformi(program_t *glprogram, GLint location)
{
    if(location==-1) {
        noerrorShim();
        return 0;
    }

    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        return 0;
    }
    m = kh_value(glprogram->uniform, k);

    // ok, grab the value in the cache
    GLint ret;
    memcpy(&ret, glprogram->cache.cache + m->cache_offs, sizeof(GLint));
    return ret;
}

const char* GetUniformName(program_t *glprogram, GLint location)
{
    if(location==-1) {
        noerrorShim();
        return 0;
    }

    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        return 0;
    }
    m = kh_value(glprogram->uniform, k);

    // ok, grab the value in the cache
    return m->name;
}

void glGetUniformfv(GLuint program, GLint location, GLfloat *params) AliasExport("gl4es_glGetUniformfv");
void glGetUniformiv(GLuint program, GLint location, GLint *params) AliasExport("gl4es_glGetUniformiv");
void glUniform1f(GLint location, GLfloat v0) AliasExport("gl4es_glUniform1f");
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) AliasExport("gl4es_glUniform2f");
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) AliasExport("gl4es_glUniform3f");
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) AliasExport("gl4es_glUniform4f");
void glUniform1i(GLint location, GLint v0) AliasExport("gl4es_glUniform1i");
void glUniform2i(GLint location, GLint v0, GLint v1) AliasExport("gl4es_glUniform2i");
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) AliasExport("gl4es_glUniform3i");
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) AliasExport("gl4es_glUniform4i");
void glUniform1fv(GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glUniform1fv");
void glUniform2fv(GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glUniform2fv");
void glUniform3fv(GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glUniform3fv");
void glUniform4fv(GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glUniform4fv");
void glUniform1iv(GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glUniform1iv");
void glUniform2iv(GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glUniform2iv");
void glUniform3iv(GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glUniform3iv");
void glUniform4iv(GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glUniform4iv");
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glUniformMatrix2fv");
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glUniformMatrix3fv");
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glUniformMatrix4fv");

// ============ GL_ARB_shader_objects ================

GLvoid glUniform1fARB(GLint location, GLfloat v0) AliasExport("gl4es_glUniform1f");
GLvoid glUniform2fARB(GLint location, GLfloat v0, GLfloat v1) AliasExport("gl4es_glUniform2f");
GLvoid glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) AliasExport("gl4es_glUniform3f");
GLvoid glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) AliasExport("gl4es_glUniform4f");

GLvoid glUniform1iARB(GLint location, GLint v0) AliasExport("gl4es_glUniform1i");
GLvoid glUniform2iARB(GLint location, GLint v0, GLint v1) AliasExport("gl4es_glUniform2i");
GLvoid glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2) AliasExport("gl4es_glUniform3i");
GLvoid glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) AliasExport("gl4es_glUniform4i");

GLvoid glUniform1fvARB(GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glUniform1fv");
GLvoid glUniform2fvARB(GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glUniform2fv");
GLvoid glUniform3fvARB(GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glUniform3fv");
GLvoid glUniform4fvARB(GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glUniform4fv");

GLvoid glUniform1ivARB(GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glUniform1iv");
GLvoid glUniform2ivARB(GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glUniform2iv");
GLvoid glUniform3ivARB(GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glUniform3iv");
GLvoid glUniform4ivARB(GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glUniform4iv");

GLvoid glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glUniformMatrix2fv");
GLvoid glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glUniformMatrix3fv");
GLvoid glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glUniformMatrix4fv");

GLvoid glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat *params) AliasExport("gl4es_glGetUniformfv");
GLvoid glGetUniformivARB(GLhandleARB programObj, GLint location, GLint *params) AliasExport("gl4es_glGetUniformiv");

// ===============
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) AliasExport("gl4es_glProgramUniform1f");
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) AliasExport("gl4es_glProgramUniform2f");
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) AliasExport("gl4es_glProgramUniform3f");
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) AliasExport("gl4es_glProgramUniform4f");
void glProgramUniform1i(GLuint program, GLint location, GLint v0) AliasExport("gl4es_glProgramUniform1i");
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) AliasExport("gl4es_glProgramUniform2i");
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) AliasExport("gl4es_glProgramUniform3i");
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) AliasExport("gl4es_glProgramUniform4i");
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glProgramUniform1fv");
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glProgramUniform2fv");
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glProgramUniform3fv");
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glProgramUniform4fv");
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glProgramUniform1iv");
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glProgramUniform2iv");
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glProgramUniform3iv");
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glProgramUniform4iv");
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glProgramUniformMatrix2fv");
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glProgramUniformMatrix3fv");
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glProgramUniformMatrix4fv");
// ===============	EXT_direct_state_access (part of it)
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) AliasExport("gl4es_glProgramUniform1f");
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) AliasExport("gl4es_glProgramUniform2f");
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) AliasExport("gl4es_glProgramUniform3f");
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) AliasExport("gl4es_glProgramUniform4f");
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0) AliasExport("gl4es_glProgramUniform1i");
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) AliasExport("gl4es_glProgramUniform2i");
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) AliasExport("gl4es_glProgramUniform3i");
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) AliasExport("gl4es_glProgramUniform4i");
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glProgramUniform1fv");
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glProgramUniform2fv");
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glProgramUniform3fv");
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value) AliasExport("gl4es_glProgramUniform4fv");
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glProgramUniform1iv");
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glProgramUniform2iv");
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glProgramUniform3iv");
void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value) AliasExport("gl4es_glProgramUniform4iv");
void glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glProgramUniformMatrix2fv");
void glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glProgramUniformMatrix3fv");
void glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) AliasExport("gl4es_glProgramUniformMatrix4fv");
