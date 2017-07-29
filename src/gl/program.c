#include "program.h"
#include "../glx/hardext.h"

void gl4es_glAttachShader(GLuint program, GLuint shader) {
    // sanity tests
    CHECK_PROGRAM(void, program)
    CHECK_SHADER(void, shader)

    // add shader reference to program
    if(glprogram->attach_cap == glprogram->attach_size) {
        glprogram->attach_cap += 4;
        glprogram->attach = (GLuint*)realloc(glprogram->attach, sizeof(GLuint)*glprogram->attach_cap);
    }
    glprogram->attach[glprogram->attach_size++] = glshader->id;
    ++glshader->attached;
    // send to hadware
    LOAD_GLES2(glAttachShader);
    if(gles_glAttachShader) {
        gles_glAttachShader(glprogram->id, glshader->id);
        errorGL();
    } else
        noerrorShim();
}

void gl4es_glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) {
    // sanity tests
    CHECK_PROGRAM(void, program)
    // look / create attribloc at index
    attribloc_t *attribloc = NULL;
    {
        khint_t k;
        int ret;
        khash_t(attribloclist) *attribloclist = glprogram->attribloc;
        k = kh_get(attribloclist, attribloclist, index);
        if (k != kh_end(attribloclist)) {
            attribloc = kh_value(attribloclist, k);
        } else {
            k = kh_put(attribloclist, attribloclist, index, &ret);
            attribloc = kh_value(attribloclist, k) = malloc(sizeof(attribloc_t));
            memset(attribloc, 0, sizeof(attribloc_t));
            attribloc->real_index = -1;
            attribloc->index = index;
        }
    }
    // update name
    if(attribloc->name) free(attribloc->name);
    attribloc->name = strdup(name);
    // send to hardware
    LOAD_GLES2(glBindAttribLocation);
    if(gles_glBindAttribLocation) {
        gles_glBindAttribLocation(glprogram->id, index, attribloc->name);
        errorGL();
    } else
        noerrorShim();
}

GLuint gl4es_glCreateProgram(void) {
    static GLuint lastprogram = 0;
    GLuint program;
    // create the program
    LOAD_GLES2(glCreateProgram);
    if(gles_glCreateProgram) {
        program = gles_glCreateProgram();
        if(!program) {
            errorGL();
            return 0;
        }
    } else {
        program = ++lastprogram;
        noerrorShim();
    }
    // store the new empty shader in the list for later use
   	khint_t k;
   	int ret;
	khash_t(programlist) *programs = glstate->glsl.programs;
    k = kh_get(programlist, programs, program);
    program_t *glprogram = NULL;
    if (k == kh_end(programs)){
        k = kh_put(programlist, programs, program, &ret);
        glprogram = kh_value(programs, k) = malloc(sizeof(program_t));
        memset(glprogram, 0, sizeof(program_t));
    } else {
        glprogram = kh_value(programs, k);
        if(glprogram->attribloc) {
            attribloc_t *m;
            kh_foreach_value(glprogram->attribloc, m,
                free(m->name); free(m);
            )
            kh_destroy(attribloclist, glprogram->attribloc);
            free(glprogram->attribloc);
            glprogram->attribloc = NULL;
        }
    }
    glprogram->id = program;
    // initialize attribloc hashmap
    khash_t(attribloclist) *attribloc = glprogram->attribloc = kh_init(attribloclist);
    kh_put(attribloclist, attribloc, 1, &ret);
    kh_del(attribloclist, attribloc, 1);
    // all done
    return program;
}

void actualy_deleteshader(GLuint shader);
void actualy_detachshader(GLuint shader);

void gl4es_glDeleteProgram(GLuint program) {
    CHECK_PROGRAM(void, program)
    // send to hardware
    LOAD_GLES2(glDeleteProgram);
    if(gles_glDeleteProgram) {
        gles_glDeleteProgram(glprogram->id);
        errorGL();
    } else
        noerrorShim();
    // TODO: check GL ERROR to not clean in case of error?
    // clean attached shaders
    for (int i=0; i<glprogram->attach_size; i++) {
        actualy_detachshader(glprogram->attach[i]);
        actualy_deleteshader(glprogram->attach[i]);
    }
    free(glprogram->attach);
    // clean attribloc
    if(glprogram->attribloc) {
        attribloc_t *m;
        kh_foreach_value(glprogram->attribloc, m,
            free(m->name); free(m);
        )
        kh_destroy(attribloclist, glprogram->attribloc);
        free(glprogram->attribloc);
        glprogram->attribloc = NULL;
    }
    // clean uniform list
    if(glprogram->uniform) {
        uniform_t *m;
        kh_foreach_value(glprogram->uniform, m,
            free(m->name); free(m);
        )
        kh_destroy(uniformlist, glprogram->uniform);
        free(glprogram->uniform);
        glprogram->uniform = NULL;
    }
    // clean cache
    if(glprogram->cache.cache)
        free(glprogram->cache.cache);
    // delete program
    kh_del(programlist, glstate->glsl.programs, k_program);
    free(glprogram);
}

void gl4es_glDetachShader(GLuint program, GLuint shader) {
    CHECK_PROGRAM(void, program)
    CHECK_SHADER(void, shader)
    // is shader attached?
    int f = 0;
    while(f<glprogram->attach_size && glprogram->attach[f]!=shader)
        f++;
    if(f==glprogram->attach_size) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    // send to hardware
    LOAD_GLES2(glDetachShader);
    if(gles_glDetachShader) {
        gles_glDetachShader(glprogram->id, glshader->id);
        errorGL();
    } else
        noerrorShim();
    // marked as detached
    actualy_detachshader(shader);
}

void gl4es_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {
    CHECK_PROGRAM(void, program)

    if(glprogram->attribloc) {
        khint_t k;
        k = kh_get(attribloclist, glprogram->attribloc, index);
        if (k != kh_end(glprogram->attribloc)) {
            attribloc_t *attribloc = kh_value(glprogram->attribloc, k);
            if(type) *type = attribloc->type;
            if(size) *size = attribloc->size;
            if(length) *length = strlen(attribloc->name);
            if(bufSize && name) strncpy(name, attribloc->name, bufSize-1);
            noerrorShim();
        } else
            errorShim(GL_INVALID_VALUE);    
    } else
        errorShim(GL_INVALID_VALUE);
}

void gl4es_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) {
    CHECK_PROGRAM(void, program)

    int n = glprogram->attach_size;
    if(n>maxCount) n = maxCount;

    if (count) *count=n;
    if (shaders)
        for (int i=0; i<n; i++)
            shaders[i] = glprogram->attach[i];

    noerrorShim();
}

GLint gl4es_glGetAttribLocation(GLuint program, const GLchar *name) {
    CHECK_PROGRAM(GLint, program);

    if(!glprogram->linked) {
        errorShim(GL_INVALID_OPERATION);
        return -1;
    }
    noerrorShim();
    if(strncmp(name, "gl_", 3)==0) {
        return -1;
    }

    int rloc = -1;
    int loc = -1;
    // look in already created attribloc
    if(glprogram->attribloc) {
        attribloc_t *m;
        kh_foreach_value(glprogram->attribloc, m,
            if(strcmp(m->name, name)==0) {
                loc = m->index;
                rloc = m->real_index;
            }
        )
    }
    // if found, just return the value, it's done...
    if(loc!=-1)
        return loc;
    // query hardware for the attribloc
    LOAD_GLES2(glGetAttribLocation);
    if(gles_glGetAttribLocation) {
        loc = gles_glGetAttribLocation(glprogram->id, name);
        if(rloc==-1) rloc = loc;
        errorGL();
    }
    // store the attriblocation
    if (loc!=-1) {
        attribloc_t *attribloc = NULL;
        {
            khint_t k;
            int ret;
            khash_t(attribloclist) *attribloclist = glprogram->attribloc;
            k = kh_get(attribloclist, attribloclist, rloc);
            if (k != kh_end(attribloclist)) {
                attribloc = kh_value(attribloclist, k);
            } else {
                k = kh_put(attribloclist, attribloclist, rloc, &ret);
                attribloc = kh_value(attribloclist, k) = malloc(sizeof(attribloc_t));
                memset(attribloc, 0, sizeof(attribloc_t));
                attribloc->index = loc;
                attribloc->name = strdup(name);
            }
        }
        attribloc->real_index = loc;
    }
    // end
    return loc;
}

void gl4es_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {
    CHECK_PROGRAM(GLvoid, program);

    if(!glprogram->linked) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    noerrorShim();
    if(strncmp(name, "gl_", 3)==0) {
        return;
    }

    // look in uniform cache, that is filled when program is linked
    if(glprogram->uniform) {
        uniform_t *m;
        khint_t k;
        kh_get(uniformlist, glprogram->uniform, k);
        if (k!=kh_end(glprogram->uniform)) {
            m = kh_value(glprogram->uniform, k);
            if(type) *type = m->type;
            if(size) *size = m->size;
            if(length) *length = strlen(m->name);
            if(bufSize && name) strncat(name, m->name, bufSize-1);
            return;
        }
    }
    // end
    errorShim(GL_INVALID_VALUE);
}

static const char* notlinked = "Program not linked";
static const char* linked = "Program linked, but no shader support";
static const char* validated = "Program validated, but no shader support";
const char* getFakeProgramInfo(program_t* glprogram) {
    return (glprogram->linked)?((glprogram->validated)?validated:linked):notlinked;
}

void gl4es_glGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog) {
    CHECK_PROGRAM(void, program)

    if(maxLength<0) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(!maxLength) {
        noerrorShim();
        return;
    }

    LOAD_GLES2(glGetProgramInfoLog);
    if(gles_glGetProgramInfoLog) {
        gles_glGetProgramInfoLog(glprogram->id, maxLength, length, infoLog);
        errorGL();
    } else {
        const char* res = getFakeProgramInfo(glprogram);
        int l = strlen(res)+1;
        if (l>maxLength) l = maxLength;
        if(length) *length = l-1;
        if(infoLog) strncpy(infoLog, res, l);
        noerrorShim();
    }
}

void gl4es_glGetProgramiv(GLuint program, GLenum pname, GLint *params) {
    CHECK_PROGRAM(void, program)

    LOAD_GLES2(glGetProgramiv);
    noerrorShim();
    switch(pname) {
        case GL_DELETE_STATUS:
            if(gles_glGetProgramiv) {
                gles_glGetProgramiv(glprogram->id, pname, params);
                errorGL();
            } else
                *params = GL_FALSE;
            break;
        case GL_LINK_STATUS:
            *params = glprogram->linked?GL_TRUE:GL_FALSE;
            break;
        case GL_VALIDATE_STATUS:
            *params = glprogram->valid_result;
            break;
        case GL_INFO_LOG_LENGTH:
            if(gles_glGetProgramiv) {
                gles_glGetProgramiv(glprogram->id, pname, params);
                errorGL();
            } else
                *params = strlen(getFakeProgramInfo(glprogram));
            break;
        case GL_ATTACHED_SHADERS:
            *params = glprogram->attach_size;
            break;
        case GL_ACTIVE_ATTRIBUTES:
        case GL_ACTIVE_ATTRIBUTE_MAX_LENGTH:
            if(gles_glGetProgramiv) {
                gles_glGetProgramiv(glprogram->id, pname, params);
                errorGL();
            } else
                *params = 0;
            break;
        case GL_ACTIVE_UNIFORMS:
            *params = (glprogram->uniform)?(kh_size(glprogram->uniform)):0;
            break;
        case GL_ACTIVE_UNIFORM_MAX_LENGTH:
            {
                int l = 0;
                uniform_t *m;
                kh_foreach_value(glprogram->uniform, m,
                    if(l<strlen(m->name)+1)
                        l = strlen(m->name)+1;
                )
                *params = l;
            }
            break;
        case GL_PROGRAM_BINARY_LENGTH:
            // TODO: check if extension is present
            if(gles_glGetProgramiv) {
                gles_glGetProgramiv(glprogram->id, pname, params);
                errorGL();
            } else
                errorShim(GL_INVALID_ENUM);
            break;
            
        default:
            if(gles_glGetProgramiv) {
                gles_glGetProgramiv(glprogram->id, pname, params);
                errorGL();
            } else
                errorShim(GL_INVALID_ENUM);
            break;
    }
}

GLint gl4es_glGetUniformLocation(GLuint program, const GLchar *name) {
    CHECK_PROGRAM(GLint, program)

    noerrorShim();
    int res = -1;
    if(strncmp(name, "gl_", 3)==0)
        return res;

    if(glprogram->uniform) {
        uniform_t *m;
        khint_t k;
        kh_foreach_value(glprogram->uniform, m,
            if(strcmp(m->name, name)==0) {
                res = m->id;
                break;
            }
        )
    }

    return res;
}

GLboolean gl4es_glIsProgram(GLuint program) {
    noerrorShim();
    if(!program) {
        return GL_FALSE;
    }
    program_t *glprogram = NULL;
    khint_t k;
    int ret;
    khash_t(programlist) *programs = glstate->glsl.programs;
    k = kh_get(programlist, programs, program);
    if (k != kh_end(programs))
        return GL_TRUE;
    return GL_FALSE;
}

void gl4es_glLinkProgram(GLuint program) {
    CHECK_PROGRAM(void, program)
    noerrorShim();

    // clear all Attrib location cache
    if(glprogram->attribloc) {
        attribloc_t *m;
        khint_t k;
        kh_foreach(glprogram->attribloc, k, m,
            free(m->name); free(m);
            kh_del(attribloclist, glprogram->attribloc, k);
        )
    }
    // clear all Uniform cache
    if(glprogram->uniform) {
        uniform_t *m;
        khint_t k;
        kh_foreach(glprogram->uniform, k, m,
            free(m->name); free(m);
            kh_del(uniformlist, glprogram->uniform, k);
        )
    }
    glprogram->cache.size = 0;  // reset cache buffer

    LOAD_GLES2(glLinkProgram);
    if(gles_glLinkProgram) {
        LOAD_GLES(glGetError);
        LOAD_GLES2(glGetProgramiv);
        LOAD_GLES2(glGetActiveUniform);
        LOAD_GLES2(glGetActiveAttrib);
        gles_glLinkProgram(glprogram->id);
        GLenum err = gles_glGetError();
        int n=0;
        int maxsize=0;
        khint_t k;
        int ret;
        // Grab all Uniform
        gles_glGetProgramiv(glprogram->id, GL_ACTIVE_UNIFORMS, &n);
        gles_glGetProgramiv(glprogram->id, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxsize);
        khash_t(uniformlist) *uniforms = glprogram->uniform;
        uniform_t *gluniform = NULL;
        int uniform_cache = 0;
        for (int i=0; i<n; i++) {
            k = kh_put(uniformlist, uniforms, i, &ret);
            gluniform = kh_value(uniforms, k) = malloc(sizeof(uniform_t));
            memset(gluniform, 0, sizeof(uniform_t));
            gluniform->name = (char*)malloc(maxsize);
            gluniform->id = i;
            gluniform->internal_id = i;
            gles_glGetActiveUniform(glprogram->id, gluniform->id, maxsize, NULL, &gluniform->size, &gluniform->type, gluniform->name);
            gluniform->cache_offs = uniform_cache;
            gluniform->cache_size = uniformsize(gluniform->type)*gluniform->size;
            uniform_cache += gluniform->cache_size;
        }
        // reset uniform cache
        if(glprogram->cache.cap < uniform_cache) {
            glprogram->cache.cap=uniform_cache;
            glprogram->cache.cache = malloc(glprogram->cache.cap);
        }
        memset(glprogram->cache.cache, 0, glprogram->cache.cap);
        // Grab all Attrib
        gles_glGetProgramiv(glprogram->id, GL_ACTIVE_ATTRIBUTES, &n);
        gles_glGetProgramiv(glprogram->id, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxsize);
        khash_t(attribloclist) *attriblocs = glprogram->attribloc;
        attribloc_t *glattribloc = NULL;
        for (int i=0; i<n; i++) {
            k = kh_put(attribloclist, attriblocs, i, &ret);
            glattribloc = kh_value(attriblocs, k) = malloc(sizeof(uniform_t));
            memset(glattribloc, 0, sizeof(attribloc_t));
            glattribloc->name = (char*)malloc(maxsize);
            glattribloc->index = i;
            glattribloc->real_index = i;
            gles_glGetActiveAttrib(glprogram->id, glattribloc->real_index, maxsize, NULL, &glattribloc->size, &glattribloc->type, glattribloc->name);
        }
        // all done
        errorShim(err);
    } else {
        noerrorShim();
    }
    glprogram->linked = 1;
}

void gl4es_glUseProgram(GLuint program) {
    CHECK_PROGRAM(void, program)
    noerrorShim();

    if(glstate->glsl.program==glprogram->id) {
        return; // already binded
    }

    glstate->glsl.program=glprogram->id;

    // TODO: actualy bind the program when drawing
    LOAD_GLES2(glUseProgram);
    if(gles_glUseProgram) {
        gles_glUseProgram(glprogram->id);
        errorGL();
    };
}

void gl4es_glValidateProgram(GLuint program) {
    CHECK_PROGRAM(void, program)
    noerrorShim();

    LOAD_GLES2(glValidateProgram);
    if(gles_glValidateProgram) {
        LOAD_GLES(glGetError);
        LOAD_GLES2(glGetProgramiv);
        gles_glValidateProgram(glprogram->id);
        GLenum err = gles_glGetError();
        gles_glGetProgramiv(glprogram->id, GL_VALIDATE_STATUS, &glprogram->valid_result);
        errorShim(err);
        // TODO: grab all Uniform and Attrib of the program
    } else {
        noerrorShim();
    }
    glprogram->validated = 1;
}


void glAttachShader(GLuint program, GLuint shader) AliasExport("gl4es_glAttachShader");
void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) AliasExport("gl4es_glBindAttribLocation");
GLuint glCreateProgram(void) AliasExport("gl4es_glCreateProgram");
void glDeleteProgram(GLuint program) AliasExport("gl4es_glDeleteProgram");
void glDetachShader(GLuint program, GLuint shader) AliasExport("gl4es_glDetachShader");
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) AliasExport("gl4es_glGetActiveAttrib");
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) AliasExport("gl4es_glGetAttachedShaders");
GLint glGetAttribLocation(GLuint program, const GLchar *name) AliasExport("gl4es_glGetAttribLocation");
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) AliasExport("gl4es_glGetActiveUniform");void glGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog) AliasExport("gl4es_glGetProgramInfoLog");
void glGetProgramiv(GLuint program, GLenum pname, GLint *params) AliasExport("gl4es_glGetProgramiv");
GLint glGetUniformLocation(GLuint program, const GLchar *name) AliasExport("gl4es_glGetUniformLocation");
GLboolean glIsProgram(GLuint program) AliasExport("gl4es_glIsProgram");
void glLinkProgram(GLuint program) AliasExport("gl4es_glLinkProgram");
void glUseProgram(GLuint program) AliasExport("gl4es_glUseProgram");
void glValidateProgram(GLuint program) AliasExport("gl4es_glValidateProgram");