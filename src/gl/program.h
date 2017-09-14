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
    //ATT_POINTSIZE,   //this one is supported by GLES hardware
    ATT_MAX
} reserved_attrib_t;

typedef enum {
    MAT_MV = 0,
    MAT_MV_I,
    MAT_MV_T,
    MAT_MV_IT,
    MAT_P,
    MAT_P_I,
    MAT_P_T,
    MAT_P_IT,
    MAT_MVP,
    MAT_MVP_I,
    MAT_MVP_T,
    MAT_MVP_IT,
    MAT_T0,
    MAT_T0_I,
    MAT_T0_T,
    MAT_T0_IT,
    MAT_T1,
    MAT_T1_I,
    MAT_T1_T,
    MAT_T1_IT,
    MAT_T2,
    MAT_T2_I,
    MAT_T2_T,
    MAT_T2_IT,
    MAT_T3,
    MAT_T3_I,
    MAT_T3_T,
    MAT_T3_IT,
    MAT_T4,
    MAT_T4_I,
    MAT_T4_T,
    MAT_T4_IT,
    MAT_T5,
    MAT_T5_I,
    MAT_T5_T,
    MAT_T5_IT,
    MAT_T6,
    MAT_T6_I,
    MAT_T6_T,
    MAT_T6_IT,
    MAT_T7,
    MAT_T7_I,
    MAT_T7_T,
    MAT_T7_IT,
    MAT_N,
    MAT_MAX
} reserved_matrix_t;

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
    GLint       ambient; //vec4
    GLint       diffuse; //vec4
    GLint       specular; //vec4
    GLint       position; //vec4
    GLint       halfVector; //vec4
    GLint       spotDirection; //vec3
    GLint       spotExponent; //float
    GLint       spotCutoff; //float
    GLint       spotCosCutoff; //float
    GLint       constantAttenuation; //float
    GLint       linearAttenuation; //float
    GLint       quadraticAttenuation; //float
} builtin_lightsource_t;

typedef struct {
    GLint       emission; //vec4
    GLint       ambient; //vec4
    GLint       diffuse; //vec4
    GLint       specular; //vec4
    GLint       shininess; //float
} builtin_material_t;

typedef struct {
    GLint       sceneColor; //vec4
} builtin_lightmodelproducts_t;

typedef struct {
    GLint       ambient; //vec4
    GLint       diffuse; //vec4
    GLint       specular; //vec4
} builtin_lightproducts_t;

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
    GLint           builtin_attrib[ATT_MAX];
    GLint           builtin_matrix[MAT_MAX];
    builtin_lightsource_t           builtin_lights[MAX_LIGHT];
    builtin_material_t              builtin_material[2];
    builtin_lightmodelproducts_t    builtin_lightmodelprod[2];
    builtin_lightproducts_t         builtin_lightprod[2][MAX_LIGHT];
} program_t;

KHASH_MAP_INIT_INT(programlist, program_t *)
void deleteProgram(program_t *glprogram, khint_t k_program);

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

#define APPLY_PROGRAM(prg, glprg) \
    if(glstate->gleshard.program != prg) {  \
        glstate->gleshard.program = prg;    \
        glstate->gleshard.glprogram = glprg;\
        LOAD_GLES2(glUseProgram);           \
        if(gles_glUseProgram)               \
            gles_glUseProgram(prg);         \
    }

#endif