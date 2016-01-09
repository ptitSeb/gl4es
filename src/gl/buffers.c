#include "buffers.h"
#include "debug.h"

static GLuint lastbuffer = 1;

// Utility function to bind / unbind a particular buffer

glbuffer_t** BUFF(GLenum target) {
 switch(target) {
     case GL_ARRAY_BUFFER:
        return &glstate.vao->vertex;
        break;
     case GL_ELEMENT_ARRAY_BUFFER:
        return &glstate.vao->elements;
        break;
     case GL_PIXEL_PACK_BUFFER:
        return &glstate.vao->pack;
        break;
     case GL_PIXEL_UNPACK_BUFFER:
        return &glstate.vao->unpack;
        break;
     default:
       printf("LIBGL: Warning, unknown buffer target 0x%04X\n", target);
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

void glshim_glGenBuffers(GLsizei n, GLuint * buffers) {
//printf("glGenBuffers(%i, %p)\n", n, buffers);
	noerrorShim();
    if (n<1) {
		errorShim(GL_INVALID_VALUE);
        return;
    }
    for (int i=0; i<n; i++) {
        buffers[i] = lastbuffer++;
    }
}

void glshim_glBindBuffer(GLenum target, GLuint buffer) {
//printf("glBindBuffer(%s, %u)\n", PrintEnum(target), buffer);
    if (glstate.gl_batch) {
         flush();
    }

   	khint_t k;
   	int ret;
	khash_t(buff) *list = glstate.buffers;
	if (! list) {
		list = glstate.buffers = kh_init(buff);
		// segfaults if we don't do a single put
		kh_put(buff, list, 1, &ret);
		kh_del(buff, list, 1);
	}
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

void glshim_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
//printf("glBufferData(%s, %i, %p, %s)\n", PrintEnum(target), size, data, PrintEnum(usage));
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
    glbuffer_t *buff = getbuffer_buffer(target);
    if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
        printf("LIBGL: Warning, null buffer for target=0x%04X for glBufferData\n", target);
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

void glshim_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
//printf("glBufferSubData(%s, %p, %i, %p)\n", PrintEnum(target), offset, size, data);
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
    glbuffer_t *buff = getbuffer_buffer(target);
    if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
//        printf("LIBGL: Warning, null buffer for target=0x%04X for glBufferSubData\n", target);
        return;
    }
    memcpy(buff->data + offset, data, size);    //TODO, some check maybe?
    noerrorShim();
}

void glshim_glDeleteBuffers(GLsizei n, const GLuint * buffers) {
//printf("glDeleteBuffers(%i, %p)\n", n, buffers);
    if (glstate.gl_batch) {
         flush();
    }

	khash_t(buff) *list = glstate.buffers;
    if (list) {
        khint_t k;
        glbuffer_t *buff;
        for (int i = 0; i < n; i++) {
            GLuint t = buffers[i];
            if (t) {    // don't allow to remove default one
                k = kh_get(buff, list, t);
                if (k != kh_end(list)) {
                    buff = kh_value(list, k);
                    if (glstate.vao->vertex == buff)
                        glstate.vao->vertex = NULL;
                    if (glstate.vao->elements == buff)
                        glstate.vao->elements = NULL;
                    if (glstate.vao->pack == buff)
                        glstate.vao->pack = NULL;
                    if (glstate.vao->unpack == buff)
                        glstate.vao->unpack = NULL;
                    if (buff->data) free(buff->data);
                    kh_del(buff, list, k);
                    free(buff);
                }
            }
        }
    }
    noerrorShim();
}

GLboolean glshim_glIsBuffer(GLuint buffer) {
//printf("glIsBuffer(%u)\n", buffer);
	khash_t(buff) *list = glstate.buffers;
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



void glshim_glGetBufferParameteriv(GLenum target, GLenum value, GLint * data) {
//printf("glGetBufferParameteriv(%s, %s, %p)\n", PrintEnum(target), PrintEnum(value), data);
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	glbuffer_t* buff = getbuffer_buffer(target);
	if (buff==NULL) {
		errorShim(GL_INVALID_OPERATION);
		return;		// Should generate an error!
	}
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

void *glshim_glMapBuffer(GLenum target, GLenum access) {
//printf("glMapBuffer(%s, %s)\n", PrintEnum(target), PrintEnum(access));
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return (void*)NULL;
	}
	glbuffer_t *buff = getbuffer_buffer(target);
	if (buff==NULL)
		return (void*)NULL;		// Should generate an error!
	buff->access = access;	// not used
	buff->mapped = 1;
	noerrorShim();
	return buff->data;		// Not nice, should do some copy or something probably
}

GLboolean glshim_glUnmapBuffer(GLenum target) {
//printf("glUnmapBuffer(%s)\n", PrintEnum(target));
	if (!buffer_target(target)) {
		errorShim(GL_INVALID_ENUM);
		return GL_FALSE;
	}
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

void glshim_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
//printf("glGetBufferSubData(%s, %p, %i, %p)\n", PrintEnum(target), offset, size, data);
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

void glshim_glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params) {
//printf("glGetBufferPointerv(%s, %s, %p)\n", PrintEnum(target), PrintEnum(pname), params);
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

//Direct wrapper
void glGenBuffers(GLsizei n, GLuint * buffers) __attribute__((alias("glshim_glGenBuffers")));
void glBindBuffer(GLenum target, GLuint buffer) __attribute__((alias("glshim_glBindBuffer")));
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) __attribute__((alias("glshim_glBufferData")));
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) __attribute__((alias("glshim_glBufferSubData")));
void glDeleteBuffers(GLsizei n, const GLuint * buffers) __attribute__((alias("glshim_glDeleteBuffers")));
GLboolean glIsBuffer(GLuint buffer) __attribute__((alias("glshim_glIsBuffer")));
void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data) __attribute__((alias("glshim_glGetBufferParameteriv")));
void *glMapBuffer(GLenum target, GLenum access) __attribute__((alias("glshim_glMapBuffer")));
GLboolean glUnmapBuffer(GLenum target) __attribute__((alias("glshim_glUnmapBuffer")));
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) __attribute__((alias("glshim_glGetBufferSubData")));
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params) __attribute__((alias("glshim_glGetBufferPointerv")));

//ARB wrapper
void glGenBuffersARB(GLsizei n, GLuint * buffers) __attribute__((alias("glshim_glGenBuffers")));
void glBindBufferARB(GLenum target, GLuint buffer) __attribute__((alias("glshim_glBindBuffer")));
void glBufferDataARB(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) __attribute__((alias("glshim_glBufferData")));
void glBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) __attribute__((alias("glshim_glBufferSubData")));
void glDeleteBuffersARB(GLsizei n, const GLuint * buffers) __attribute__((alias("glshim_glDeleteBuffers")));
GLboolean glIsBufferARB(GLuint buffer) __attribute__((alias("glshim_glIsBuffer")));
void glGetBufferParameterivARB(GLenum target, GLenum value, GLint * data) __attribute__((alias("glshim_glGetBufferParameteriv")));
void *glMapBufferARB(GLenum target, GLenum access) __attribute__((alias("glshim_glMapBuffer")));
GLboolean glUnmapBufferARB(GLenum target) __attribute__((alias("glshim_glUnmapBuffer")));
void glGetBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) __attribute__((alias("glshim_glGetBufferSubData")));
void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid ** params) __attribute__((alias("glshim_glGetBufferPointerv")));

// VAO ****************
static GLuint lastvao = 1;

void glshim_glGenVertexArrays(GLsizei n, GLuint *arrays) {
//printf("glGenVertexArrays(%i, %p)\n", n, arrays);
	noerrorShim();
    if (n<1) {
		errorShim(GL_INVALID_VALUE);
        return;
    }
    for (int i=0; i<n; i++) {
        arrays[i] = lastvao++;
    }
}
void glshim_glBindVertexArray(GLuint array) {
//printf("glBindVertexArray(%u)\n", array);
    if (glstate.gl_batch) {
         flush();
    }

   	khint_t k;
   	int ret;
	khash_t(glvao) *list = glstate.vaos;
	if (! list) {
		list = glstate.vaos = kh_init(glvao);
		// segfaults if we don't do a single put
		kh_put(glvao, list, 1, &ret);
		kh_del(glvao, list, 1);
	}
    // if array = 0 => unbind buffer!
    if (array == 0) {
        // unbind buffer
        glstate.vao = glstate.defaultvao;
    } else {
        // search for an existing buffer
        k = kh_get(glvao, list, array);
        glvao_t *glvao = NULL;
        if (k == kh_end(list)){
            k = kh_put(glvao, list, array, &ret);
            glvao = kh_value(list, k) = malloc(sizeof(glvao_t));
            // new vao is binded to nothing
            memset(glvao, 0, sizeof(glvao_t));
            /*
            glstate.vao->vertex = glstate.defaultvbo;
            glstate.vao->elements = glstate.defaultvbo;
            glstate.vao->pack = glstate.defaultvbo;
            glstate.vao->unpack = glstate.defaultvbo;
            */

            // just put is number
            glvao->array = array;
        } else {
            glvao = kh_value(list, k);
        }
        glstate.vao = glvao;
    }
    noerrorShim();
}
void glshim_glDeleteVertexArrays(GLsizei n, const GLuint *arrays) {
//printf("glDeleteVertexArrays(%i, %p)\n", n, arrays);
    if (glstate.gl_batch) {
         flush();
    }
	khash_t(glvao) *list = glstate.vaos;
    if (list) {
        khint_t k;
        glvao_t *glvao;
        for (int i = 0; i < n; i++) {
            GLuint t = arrays[i];
            if (t) {    // don't allow to remove the default one
                k = kh_get(glvao, list, t);
                if (k != kh_end(list)) {
                    glvao = kh_value(list, k);
                    kh_del(glvao, list, k);
                    free(glvao);
                }
            }
        }
    }
    noerrorShim();
}
GLboolean glshim_glIsVertexArray(GLuint array) {
//printf("glIsVertexArray(%u)\n", array);
	khash_t(glvao) *list = glstate.vaos;
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

//Dirzct wrapper
void glGenVertexArrays(GLsizei n, GLuint *arrays) __attribute__((alias("glshim_glGenVertexArrays")));
void glBindVertexArray(GLuint array) __attribute__((alias("glshim_glBindVertexArray")));
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays) __attribute__((alias("glshim_glDeleteVertexArrays")));
GLboolean glIsVertexArray(GLuint array) __attribute__((alias("glshim_glIsVertexArray")));

