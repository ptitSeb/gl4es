#include "uniform.h"
#include "program.h"
#include "matvec.h"
#include "../glx/hardext.h"

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
        GOV(GL_BOOL, GLboolean);
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

void GoUniformfv(GLint location, int size, int count, const GLfloat *value)
{
    GLuint program = glstate->glsl.program; // to be checked, current program may not be this one

    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    CHECK_PROGRAM(void, program);

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
void GoUniformiv(GLint location, int size, int count, const GLint *value)
{
    GLuint program = glstate->glsl.program;
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    CHECK_PROGRAM(void, program); // to be checked, current program may not be this one
    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
    }
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
    GoUniformfv(location, 1, 1, &v0);
}
void gl4es_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    GLfloat fl[2] = {v0, v1};
    GoUniformfv(location, 2, 1, fl);
}
void gl4es_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    GLfloat fl[3] = {v0, v1, v2};
    GoUniformfv(location, 3, 1, fl);
}
void gl4es_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    GLfloat fl[4] = {v0, v1, v2, v3};
    GoUniformfv(location, 4, 1, fl);
}
void gl4es_glUniform1i(GLint location, GLint v0) {
    GoUniformiv(location, 1, 1, &v0);
}
void gl4es_glUniform2i(GLint location, GLint v0, GLint v1) {
    GLint fl[2] = {v0, v1};
    GoUniformiv(location, 2, 1, fl);
}
void gl4es_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    GLint fl[3] = {v0, v1, v2};
    GoUniformiv(location, 3, 1, fl);
}
void gl4es_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    GLint fl[4] = {v0, v1, v2, v3};
    GoUniformiv(location, 4, 1, fl);
}
void gl4es_glUniform1fv(GLint location, GLsizei count, const GLfloat *value) {
    GoUniformfv(location, 1, 1, value);
}
void gl4es_glUniform2fv(GLint location, GLsizei count, const GLfloat *value) {
    GoUniformfv(location, 2, 1, value);
}
void gl4es_glUniform3fv(GLint location, GLsizei count, const GLfloat *value) {
    GoUniformfv(location, 3, 1, value);
}
void gl4es_glUniform4fv(GLint location, GLsizei count, const GLfloat *value) {
    GoUniformfv(location, 4, 1, value);
}
void gl4es_glUniform1iv(GLint location, GLsizei count, const GLint *value) {
    GoUniformiv(location, 1, 1, value);
}
void gl4es_glUniform2iv(GLint location, GLsizei count, const GLint *value) {
    GoUniformiv(location, 2, 1, value);
}
void gl4es_glUniform3iv(GLint location, GLsizei count, const GLint *value) {
    GoUniformiv(location, 3, 1, value);
}
void gl4es_glUniform4iv(GLint location, GLsizei count, const GLint *value) {
    GoUniformiv(location, 4, 1, value);
}

void gl4es_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    GLuint program = glstate->glsl.program;
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    CHECK_PROGRAM(void, program); // to be checked, current program may not be this one
    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
    }
    if(m->type!=GL_FLOAT_MAT2  || count>m->size) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    // transpose if needed
    GLfloat *v = (GLfloat*)value;
    if(transpose) {
        v = (GLfloat*)malloc(sizeof(GLfloat)*2*2);
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
    GLuint program = glstate->glsl.program;
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    CHECK_PROGRAM(void, program); // to be checked, current program may not be this one
    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
    }
    if(m->type!=GL_FLOAT_MAT3  || count>m->size) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    // transpose if needed
    GLfloat *v = (GLfloat*)value;
    if(transpose) {
        v = (GLfloat*)malloc(sizeof(GLfloat)*3*3);
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
    GLuint program = glstate->glsl.program;
    if(location==-1) {
        noerrorShim();
        return;
    }
    if(count<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    CHECK_PROGRAM(void, program); // to be checked, current program may not be this one
    khint_t k;
    uniform_t *m;
    k = kh_get(uniformlist, glprogram->uniform, location);
    if (k==kh_end(glprogram->uniform)) {
        errorShim(GL_INVALID_OPERATION);
    }
    if(m->type!=GL_FLOAT_MAT4  || count>m->size) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    // transpose if needed
    GLfloat *v = (GLfloat*)value;
    if(transpose) {
        v = (GLfloat*)malloc(sizeof(GLfloat)*4*4);
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
    } else
        errorShim(GL_INVALID_OPERATION);    // no GLSL hardware
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