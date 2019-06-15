#include "buffers.h"

#include "khash.h"
#include "../glx/hardext.h"
#include "attributes.h"
#include "debug.h"
#include "gl4es.h"
#include "glstate.h"
#include "logs.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif


KHASH_MAP_IMPL_INT(buff, glbuffer_t *);
KHASH_MAP_IMPL_INT(glvao, glvao_t*);

static GLuint lastbuffer = 1;

// Utility function to bind / unbind a particular buffer

glbuffer_t** BUFF(GLenum target) {
 switch(target) {
     case GL_ARRAY_BUFFER:
        return &glstate->vao->vertex;
        break;
     case GL_ELEMENT_ARRAY_BUFFER:
        return &glstate->vao->elements;
        break;
     case GL_PIXEL_PACK_BUFFER:
        return &glstate->vao->pack;
        break;
     case GL_PIXEL_UNPACK_BUFFER:
        return &glstate->vao->unpack;
        break;
     default:
       LOGD("LIBGL: Warning, unknown buffer target 0x%04X\n", target);
 }
 return (glbuffer_t**)NULL;
}

void unbind_buffer(GLenum target) {
    glbuffer_t **t = BUFF(target);
    if (t)
		*t=(glbuffer_t*)NULL;
}
void bind_buffer(GLenum target, glbuffer_t* buff) {
    glbuffer_t ** t = BUFF(target);
    if (t)
		*t = buff;
}
glbuffer_t* getbuffer_buffer(GLenum target) {
    glbuffer_t ** t = BUFF(target);
    if (t)
		return *t;
    return NULL;
}
glbuffer_t* getbuffer_id(GLuint buffer) {
    if(!buffer)
        return NULL;
   	khint_t k;
   	int ret;
	khash_t(buff) *list = glstate->buffers;
    k = kh_get(buff, list, buffer);
    if (k == kh_end(list))
        return NULL;
    return kh_value(list, k);
}

int buffer_target(GLenum target) {
	if (target==GL_ARRAY_BUFFER)
		return 1;
	if (target==GL_ELEMENT_ARRAY_BUFFER)
		return 1;
	if (target==GL_PIXEL_PACK_BUFFER)
		return 1;
	if (target==GL_PIXEL_UNPACK_BUFFER)
		return 1;
	return 0;
}

void gl4es_glGenBuffers(GLsizei n, GLuint * buffers) {
    DBG(printf("glGenBuffers(%i, %p)\n", n, buffers);)
	noerrorShim();
    if (n<1) {
		errorShim(GL_INVALID_VALUE);
        return;
    }
    for (int i=0; i<n; i++) {
        buffers[i] = lastbuffer++;
    }
}

void gl4es_glBindBuffer(GLenum target, GLuint buffer) {
    DBG(printf("glBindBuffer(%s, %u)\n", PrintEnum(target), buffer);)
    if (glstate->list.pending)  // this is probably not needed as long as real VBO are not used
         flush();

   	khint_t k;
   	int ret;
	khash_t(buff) *list = glstate->buffers;
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
    // if buffer = 0 => unbind buffer!
    if (buffer == 0) {
        // unbind buffer
        unbind_buffer(target);
    } else {
        // search for an existing buffer
        k = kh_get(buff, list, buffer);
        glbuffer_t *buff = NULL;
        if (k == kh_end(list)){
            k = kh_put(buff, list, buffer, &ret);
            buff = kh_value(list, k) = malloc(sizeof(glbuffer_t));
            buff->buffer = buffer;
            buff->type = target;
            buff->data = NULL;
            buff->usage = GL_STATIC_DRAW;
            buff->size = 0;
            buff->access = GL_READ_WRITE;
            buff->mapped = 0;
        } else {
            buff = kh_value(list, k);
        }
        bind_buffer(target, buff);
    }
    noerrorShim();
}

void gl4es_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    DBG(printf("glBufferData(%s, %i, %p, %s)\n", PrintEnum(target), size, data, PrintEnum(usage));)
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
    glbuffer_t *buff = getbuffer_buffer(target);
    if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
        LOGE("LIBGL: Warning, null buffer for target=0x%04X for glBufferData\n", target);
        return;
    }
    if (buff->data) {
        free(buff->data);

    }
    if(target==GL_ARRAY_BUFFER)
        VaoSharedClear(glstate->vao);
        
    buff->size = size;
    buff->usage = usage;
    buff->data = malloc(size);
    buff->access = GL_READ_WRITE;
    if (data)
        memcpy(buff->data, data, size);
    noerrorShim();
}

void gl4es_glNamedBufferData(GLuint buffer, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    DBG(printf("glNamedBufferData(%u, %i, %p, %s)\n", buffer, size, data, PrintEnum(usage));)
    glbuffer_t *buff = getbuffer_id(buffer);
    if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
        return;
    }
    if (buff->data) {
        free(buff->data);

    }

    buff->size = size;
    buff->usage = usage;
    buff->data = malloc(size);
    buff->access = GL_READ_WRITE;
    if (data)
        memcpy(buff->data, data, size);
    noerrorShim();
}

void gl4es_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    DBG(printf("glBufferSubData(%s, %p, %i, %p)\n", PrintEnum(target), offset, size, data);)
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
    glbuffer_t *buff = getbuffer_buffer(target);
    if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
        DBG(printf("LIBGL: Warning, null buffer for target=0x%04X for glBufferSubData\n", target);)
        return;
    }

    if(target==GL_ARRAY_BUFFER)
        VaoSharedClear(glstate->vao);

    if (offset<0 || size<0 || offset+size>buff->size) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
        
    memcpy(buff->data + offset, data, size);
    noerrorShim();
}
void gl4es_glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    DBG(printf("glNamedBufferSubData(%u, %p, %i, %p)\n", buffer, offset, size, data);)
    glbuffer_t *buff = getbuffer_id(buffer);
    if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
        return;
    }

    if (offset<0 || size<0 || offset+size>buff->size) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
        
    memcpy(buff->data + offset, data, size);
    noerrorShim();
}

void gl4es_glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    DBG(printf("glDeleteBuffers(%i, %p)\n", n, buffers);)
    if(!glstate) return;
    FLUSH_BEGINEND;
    
    VaoSharedClear(glstate->vao);
	khash_t(buff) *list = glstate->buffers;
    if (list) {
        khint_t k;
        glbuffer_t *buff;
        for (int i = 0; i < n; i++) {
            GLuint t = buffers[i];
            if (t) {    // don't allow to remove default one
                k = kh_get(buff, list, t);
                if (k != kh_end(list)) {
                    buff = kh_value(list, k);
                    if (glstate->vao->vertex == buff)
                        glstate->vao->vertex = NULL;
                    if (glstate->vao->elements == buff)
                        glstate->vao->elements = NULL;
                    if (glstate->vao->pack == buff)
                        glstate->vao->pack = NULL;
                    if (glstate->vao->unpack == buff)
                        glstate->vao->unpack = NULL;
                    for (int j = 0; j < hardext.maxvattrib; j++)
                        if (glstate->vao->vertexattrib[j].buffer == buff)
                            glstate->vao->vertexattrib[j].buffer = NULL;
                    if (buff->data) free(buff->data);
                    kh_del(buff, list, k);
                    free(buff);
                }
            }
        }
    }
    noerrorShim();
}

GLboolean gl4es_glIsBuffer(GLuint buffer) {
    DBG(printf("glIsBuffer(%u)\n", buffer);)
	khash_t(buff) *list = glstate->buffers;
	khint_t k;
	noerrorShim();
    if (list) {
		k = kh_get(buff, list, buffer);
		if (k != kh_end(list)) {
			return GL_TRUE;
		}
	}
	return GL_FALSE;
}


static void* bufferGetParameteriv(glbuffer_t* buff, GLenum value, GLint * data) {
	noerrorShim();
	switch (value) {
		case GL_BUFFER_ACCESS:
			data[0] = buff->access;
			break;
		case GL_BUFFER_ACCESS_FLAGS:
			data[0] = GL_MAP_READ_BIT | GL_MAP_WRITE_BIT;
			break;
		case GL_BUFFER_MAPPED:
			data[0]=(buff->mapped)?GL_TRUE:GL_FALSE;
			break;
		case GL_BUFFER_MAP_LENGTH:
			data[0]=(buff->mapped)?buff->size:0;
			break;
		case GL_BUFFER_MAP_OFFSET:
			data[0]=0;
			break;
		case GL_BUFFER_SIZE:
			data[0] = buff->size;
			break;
		case GL_BUFFER_USAGE:
			data[0] = buff->usage;
			break;
		default:
			errorShim(GL_INVALID_ENUM);
		/* TODO Error if something else */
	}
}

void gl4es_glGetBufferParameteriv(GLenum target, GLenum value, GLint * data) {
    DBG(printf("glGetBufferParameteriv(%s, %s, %p)\n", PrintEnum(target), PrintEnum(value), data);)
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	glbuffer_t* buff = getbuffer_buffer(target);
	if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
		return;		// Should generate an error!
	}
    bufferGetParameteriv(buff, value, data);
}
void gl4es_glGetNamedBufferParameteriv(GLuint buffer, GLenum value, GLint * data) {
    DBG(printf("glGetNamedBufferParameteriv(%u, %s, %p)\n", buffer, PrintEnum(value), data);)
	glbuffer_t* buff = getbuffer_id(buffer);
	if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
		return;		// Should generate an error!
	}
    bufferGetParameteriv(buff, value, data);
}

void *gl4es_glMapBuffer(GLenum target, GLenum access) {
    DBG(printf("glMapBuffer(%s, %s)\n", PrintEnum(target), PrintEnum(access));)
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return (void*)NULL;
	}

    if(target==GL_ARRAY_BUFFER)
        VaoSharedClear(glstate->vao);

	glbuffer_t *buff = getbuffer_buffer(target);
	if (buff==NULL)
		return (void*)NULL;		// Should generate an error!
	buff->access = access;	// not used
	buff->mapped = 1;
	noerrorShim();
	return buff->data;		// Not nice, should do some copy or something probably
}
void *gl4es_glMapNamedBuffer(GLuint buffer, GLenum access) {
    DBG(printf("glMapNamedBuffer(%u, %s)\n", buffer, PrintEnum(access));)

	glbuffer_t *buff = getbuffer_id(buffer);
	if (buff==NULL)
		return (void*)NULL;		// Should generate an error!
	buff->access = access;	// not used
	buff->mapped = 1;
	noerrorShim();
	return buff->data;		// Not nice, should do some copy or something probably
}

GLboolean gl4es_glUnmapBuffer(GLenum target) {
    DBG(printf("glUnmapBuffer(%s)\n", PrintEnum(target));)
    if(glstate->list.compiling) {errorShim(GL_INVALID_OPERATION); return GL_FALSE;}
    if(glstate->list.active)
        flush();
        
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return GL_FALSE;
	}

    if(target==GL_ARRAY_BUFFER)
        VaoSharedClear(glstate->vao);
        
	glbuffer_t *buff = getbuffer_buffer(target);
	if (buff==NULL)
		return GL_FALSE;		// Should generate an error!
	noerrorShim();
	if (buff->mapped) {
		buff->mapped = 0;
		return GL_TRUE;
	}
	return GL_FALSE;
}
GLboolean gl4es_glUnmapNamedBuffer(GLuint buffer) {
    DBG(printf("glUnmapNamedBuffer(%u)\n", buffer);)
    if(glstate->list.compiling) {errorShim(GL_INVALID_OPERATION); return GL_FALSE;}
    if(glstate->list.active)
        flush();
        
	glbuffer_t *buff = getbuffer_id(buffer);
	if (buff==NULL)
		return GL_FALSE;		// Should generate an error!
	noerrorShim();
	if (buff->mapped) {
		buff->mapped = 0;
		return GL_TRUE;
	}
	return GL_FALSE;
}

void gl4es_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
    DBG(printf("glGetBufferSubData(%s, %p, %i, %p)\n", PrintEnum(target), offset, size, data);)
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	glbuffer_t *buff = getbuffer_buffer(target);

	if (buff==NULL)
		return;		// Should generate an error!
	// TODO, check parameter consistancie
    memcpy(data, buff->data+offset, size);
	noerrorShim();
}
void gl4es_glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid * data) {
    DBG(printf("glGetNamedBufferSubData(%u, %p, %i, %p)\n", buffer, offset, size, data);)
	glbuffer_t *buff = getbuffer_id(buffer);

	if (buff==NULL)
		return;		// Should generate an error!
	// TODO, check parameter consistancie
    memcpy(data, buff->data+offset, size);
	noerrorShim();
}

void gl4es_glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params) {
    DBG(printf("glGetBufferPointerv(%s, %s, %p)\n", PrintEnum(target), PrintEnum(pname), params);)
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	glbuffer_t *buff = getbuffer_buffer(target);
	if (buff==NULL)
		return;		// Should generate an error!
	if (pname != GL_BUFFER_MAP_POINTER) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	if (!buff->mapped) {
		params[0] = NULL;
	} else {
		params[0] = buff->data;
	}
}
void gl4es_glGetNamedBufferPointerv(GLuint buffer, GLenum pname, GLvoid ** params) {
    DBG(printf("glGetNamedBufferPointerv(%u, %s, %p)\n", buffer, PrintEnum(pname), params);)
	glbuffer_t *buff = getbuffer_id(buffer);
	if (buff==NULL)
		return;		// Should generate an error!
	if (pname != GL_BUFFER_MAP_POINTER) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	if (!buff->mapped) {
		params[0] = NULL;
	} else {
		params[0] = buff->data;
	}
}

void* gl4es_glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    DBG(printf("glMapBuffer(%s, %s)\n", PrintEnum(target), PrintEnum(access));)
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return (void*)NULL;
	}

    if(target==GL_ARRAY_BUFFER)
        VaoSharedClear(glstate->vao);

	glbuffer_t *buff = getbuffer_buffer(target);
	if (buff==NULL)
		return (void*)NULL;		// Should generate an error!
	buff->access = access;	// not used
	buff->mapped = 1;
	noerrorShim();
    uintptr_t ret = (uintptr_t)buff->data;
    ret += offset;
	return (void*)ret;		// Not nice, should do some copy or something probably
}
void gl4es_glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
{
    // ignored for now. A proprer handling is probably necessary
    // but that would mean also proprer handling of MapBuffer in the first place
    // with shadow copy for example when in read mode only
}


//Direct wrapper
void glGenBuffers(GLsizei n, GLuint * buffers) AliasExport("gl4es_glGenBuffers");
void glBindBuffer(GLenum target, GLuint buffer) AliasExport("gl4es_glBindBuffer");
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) AliasExport("gl4es_glBufferData");
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) AliasExport("gl4es_glBufferSubData");
void glDeleteBuffers(GLsizei n, const GLuint * buffers) AliasExport("gl4es_glDeleteBuffers");
GLboolean glIsBuffer(GLuint buffer) AliasExport("gl4es_glIsBuffer");
void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data) AliasExport("gl4es_glGetBufferParameteriv");
void *glMapBuffer(GLenum target, GLenum access) AliasExport("gl4es_glMapBuffer");
GLboolean glUnmapBuffer(GLenum target) AliasExport("gl4es_glUnmapBuffer");
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) AliasExport("gl4es_glGetBufferSubData");
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params) AliasExport("gl4es_glGetBufferPointerv");

void *glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) AliasExport("gl4es_glMapBufferRange");
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) AliasExport("gl4es_glFlushMappedBufferRange");

//ARB wrapper
void glGenBuffersARB(GLsizei n, GLuint * buffers) AliasExport("gl4es_glGenBuffers");
void glBindBufferARB(GLenum target, GLuint buffer) AliasExport("gl4es_glBindBuffer");
void glBufferDataARB(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) AliasExport("gl4es_glBufferData");
void glBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) AliasExport("gl4es_glBufferSubData");
void glDeleteBuffersARB(GLsizei n, const GLuint * buffers) AliasExport("gl4es_glDeleteBuffers");
GLboolean glIsBufferARB(GLuint buffer) AliasExport("gl4es_glIsBuffer");
void glGetBufferParameterivARB(GLenum target, GLenum value, GLint * data) AliasExport("gl4es_glGetBufferParameteriv");
void *glMapBufferARB(GLenum target, GLenum access) AliasExport("gl4es_glMapBuffer");
GLboolean glUnmapBufferARB(GLenum target) AliasExport("gl4es_glUnmapBuffer");
void glGetBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) AliasExport("gl4es_glGetBufferSubData");
void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid ** params) AliasExport("gl4es_glGetBufferPointerv");

//Direct Access
void glNamedBufferData(GLuint buffer, GLsizeiptr size, const GLvoid * data, GLenum usage) AliasExport("gl4es_glNamedBufferData");
void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid * data) AliasExport("gl4es_glNamedBufferSubData");
void glGetNamedBufferParameteriv(GLuint buffer, GLenum value, GLint * data) AliasExport("gl4es_glGetNamedBufferParameteriv");
void *glMapNamedBuffer(GLuint buffer, GLenum access) AliasExport("gl4es_glMapNamedBuffer");
GLboolean glUnmapNamedBuffer(GLuint buffer) AliasExport("gl4es_glUnmapNamedBuffer");
void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid * data) AliasExport("gl4es_glGetNamedBufferSubData");
void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, GLvoid ** params) AliasExport("gl4es_glGetNamedBufferPointerv");

void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const GLvoid * data, GLenum usage) AliasExport("gl4es_glNamedBufferData");
void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid * data) AliasExport("gl4es_glNamedBufferSubData");
void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum value, GLint * data) AliasExport("gl4es_glGetNamedBufferParameteriv");
void *glMapNamedBufferEXT(GLuint buffer, GLenum access) AliasExport("gl4es_glMapNamedBuffer");
GLboolean glUnmapNamedBufferEXT(GLuint buffer) AliasExport("gl4es_glUnmapNamedBuffer");
void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid * data) AliasExport("gl4es_glGetNamedBufferSubData");
void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, GLvoid ** params) AliasExport("gl4es_glGetNamedBufferPointerv");


// VAO ****************
static GLuint lastvao = 1;

void gl4es_glGenVertexArrays(GLsizei n, GLuint *arrays) {
    DBG(printf("glGenVertexArrays(%i, %p)\n", n, arrays);)
	noerrorShim();
    if (n<1) {
		errorShim(GL_INVALID_VALUE);
        return;
    }
    for (int i=0; i<n; i++) {
        arrays[i] = lastvao++;
    }
}
void gl4es_glBindVertexArray(GLuint array) {
    DBG(printf("glBindVertexArray(%u)\n", array);)
    if (glstate->list.pending)
         flush();

   	khint_t k;
   	int ret;
	khash_t(glvao) *list = glstate->vaos;
    // if array = 0 => unbind buffer!
    if (array == 0) {
        // unbind buffer
        glstate->vao = glstate->defaultvao;
    } else {
        // search for an existing buffer
        k = kh_get(glvao, list, array);
        glvao_t *glvao = NULL;
        if (k == kh_end(list)){
            k = kh_put(glvao, list, array, &ret);
            glvao = kh_value(list, k) = malloc(sizeof(glvao_t));
            // new vao is binded to nothing
            VaoInit(glvao);
            // TODO: check if should copy status of current VAO instead of cleanning everything

            // just put is number
            glvao->array = array;
        } else {
            glvao = kh_value(list, k);
        }
        glstate->vao = glvao;
    }
    // TODO: find a better way to do that, to many useless copying stuff
    if(glstate->fpe_state)
        memcpy(glstate->glesva.wanted, glstate->vao->vertexattrib, MAX_VATTRIB * sizeof(vertexattrib_t));

    noerrorShim();
}
void gl4es_glDeleteVertexArrays(GLsizei n, const GLuint *arrays) {
    DBG(printf("glDeleteVertexArrays(%i, %p)\n", n, arrays);)
    if(!glstate) return;
    FLUSH_BEGINEND;

	khash_t(glvao) *list = glstate->vaos;
    if (list) {
        khint_t k;
        glvao_t *glvao;
        for (int i = 0; i < n; i++) {
            GLuint t = arrays[i];
            if (t) {    // don't allow to remove the default one
                k = kh_get(glvao, list, t);
                if (k != kh_end(list)) {
                    glvao = kh_value(list, k);
                    VaoSharedClear(glvao);
                    kh_del(glvao, list, k);
                    //free(glvao);  //let the use delete those
                }
            }
        }
    }
    noerrorShim();
}
GLboolean gl4es_glIsVertexArray(GLuint array) {
    DBG(printf("glIsVertexArray(%u)\n", array);)
    if(!glstate)
        return GL_FALSE;
	khash_t(glvao) *list = glstate->vaos;
	khint_t k;
	noerrorShim();
    if (list) {
		k = kh_get(glvao, list, array);
		if (k != kh_end(list)) {
			return GL_TRUE;
		}
	}
	return GL_FALSE;
}

void VaoSharedClear(glvao_t *vao) {
    if(vao==NULL || vao->shared_arrays==NULL)
        return;
    if(!(--(*vao->shared_arrays))) {
        free(vao->vert.ptr);
        free(vao->color.ptr);
        free(vao->secondary.ptr);
        free(vao->normal.ptr);
        for (int i=0; i<hardext.maxtex; i++)
            free(vao->tex[i].ptr);
        free(vao->shared_arrays);
    }
    vao->vert.ptr = NULL;
    vao->color.ptr = NULL;
    vao->secondary.ptr = NULL;
    vao->normal.ptr = NULL;
    for (int i=0; i<hardext.maxtex; i++)
        vao->tex[i].ptr = NULL;
    vao->shared_arrays = NULL;
}

void VaoInit(glvao_t *vao) {
    memset(vao, 0, sizeof(glvao_t));
    for (int i=0; i<hardext.maxvattrib; i++) {
        vao->vertexattrib[i].size = 4;
        vao->vertexattrib[i].type = GL_FLOAT;
        vao->vertexattrib[i].current[3] = 1.0f;
    }
}

//Direct wrapper
void glGenVertexArrays(GLsizei n, GLuint *arrays) AliasExport("gl4es_glGenVertexArrays");
void glBindVertexArray(GLuint array) AliasExport("gl4es_glBindVertexArray");
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays) AliasExport("gl4es_glDeleteVertexArrays");
GLboolean glIsVertexArray(GLuint array) AliasExport("gl4es_glIsVertexArray");

