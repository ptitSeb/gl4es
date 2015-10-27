#include "buffers.h"

static GLuint lastbuffer = 1;

// Utility function to bond / unbind a particular buffer

glbuffer_t** BUFF(GLenum target) {
 switch(target) {
     case GL_ARRAY_BUFFER:
        return &state.buffers.vertex;
        break;
     case GL_ELEMENT_ARRAY_BUFFER:
        return &state.buffers.elements;
        break;
     case GL_PIXEL_PACK_BUFFER:
        return &state.buffers.pack;
        break;
     case GL_PIXEL_UNPACK_BUFFER:
        return &state.buffers.unpack;
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

void glGenBuffers(GLsizei n, GLuint * buffers) {
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

void glBindBuffer(GLenum target, GLuint buffer) {
//printf("glBindBuffer(0x%04X, %u)\n", target, buffer);

   	khint_t k;
   	int ret;
	khash_t(buff) *list = state.buffers.list;
	if (! list) {
		list = state.buffers.list = kh_init(buff);
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

void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
//printf("glBufferData(0x%04X, %i, %p, 0x%04X)\n", target, size, data, usage);
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

void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
//printf("glBufferSubData(0x%04X, %p, %i, %p)\n", target, offset, size, data);
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

void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
//printf("glDeleteBuffers(%i, %p)\n", n, buffers);
	khash_t(buff) *list = state.buffers.list;
    if (list) {
        khint_t k;
        glbuffer_t *buff;
        for (int i = 0; i < n; i++) {
            GLuint t = buffers[i];
            k = kh_get(buff, list, t);
            if (k != kh_end(list)) {
                buff = kh_value(list, k);
                if (state.buffers.vertex == buff)
					state.buffers.vertex = NULL;
                if (state.buffers.elements == buff)
					state.buffers.elements = NULL;
                if (state.buffers.pack == buff)
					state.buffers.pack = NULL;
                if (state.buffers.unpack == buff)
					state.buffers.unpack = NULL;
                if (buff->data) free(buff->data);
                kh_del(buff, list, k);
                free(buff);
            }
        }
    }
    noerrorShim();
}

GLboolean glIsBuffer(GLuint buffer) {
//printf("glIsBuffer(%u)\n", buffer);
	khash_t(buff) *list = state.buffers.list;
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



void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data) {
//printf("glGetBufferParameteriv(0x%04X, 0x%04X, %p)\n", target, value, data);
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

void *glMapBuffer(GLenum target, GLenum access) {
//printf("glMapBuffer(0x%04X, 0x%04X)\n", target, access);
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

GLboolean glUnmapBuffer(GLenum target) {
//printf("glUnmapBuffer(0x%04X)\n", target);
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

void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
//printf("glGetBufferSubData(0x%04X, %p, %i, %p)\n", target, offset, size, data);
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

void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params) {
//printf("glGetBufferPointerv(0x%04X, 0x%04X, %p)\n", target, pname, params);
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


void glGenBuffersARB(GLsizei n, GLuint * buffers) {
	glGenBuffers(n, buffers);
}
void glBindBufferARB(GLenum target, GLuint buffer) {
	glBindBuffer(target, buffer);
}
void glBufferDataARB(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
	glBufferData(target, size, data, usage);
}
void glBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
	glBufferSubData(target, offset, size, data);
}
void glDeleteBuffersARB(GLsizei n, const GLuint * buffers) {
	glDeleteBuffers(n, buffers);
}
GLboolean glIsBufferARB(GLuint buffer) {
	return glIsBuffer(buffer);
}
void glGetBufferParameterivARB(GLenum target, GLenum value, GLint * data) {
	glGetBufferParameteriv(target, value, data);
}
void *glMapBufferARB(GLenum target, GLenum access) {
	glMapBuffer(target, access);
}
GLboolean glUnmapBufferARB(GLenum target) {
	return glUnmapBuffer(target);
}
void glGetBufferSubDataARB(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
	glGetBufferSubData(target, offset, size, data);
}
void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid ** params) {
	glGetBufferPointerv(target, pname, params);
}

// VAO ****************
static GLuint lastvao = 1;

void glGenVertexArrays(GLsizei n, GLuint *arrays) {
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
void glBindVertexArray(GLuint array) {
//printf("glBindVertexArray(%u)\n", array);

   	khint_t k;
   	int ret;
	khash_t(glvao) *list = state.vaos;
	if (! list) {
		list = state.vaos = kh_init(glvao);
		// segfaults if we don't do a single put
		kh_put(glvao, list, 1, &ret);
		kh_del(glvao, list, 1);
	}
    // check if needs to copy the data to current vao
    if ((state.bindedvao!=NULL) && (state.bindedvao->array!=array))
    {
        memcpy(&state.bindedvao->pointers, &state.pointers, sizeof(state.pointers));
    }
    // if array = 0 => unbind buffer!
    if (array == 0) {
        // unbind buffer
        state.bindedvao = NULL;
    } else {
        // search for an existing buffer
        k = kh_get(glvao, list, array);
        glvao_t *glvao = NULL;
        if (k == kh_end(list)){
            k = kh_put(glvao, list, array, &ret);
            glvao = kh_value(list, k) = malloc(sizeof(glvao_t));
            glvao->array = array;
            // new vao is binded to nothing
            memset(&glvao->pointers, 0, sizeof(glvao->pointers));  
        } else {
            glvao = kh_value(list, k);
        }
        state.bindedvao = glvao;
        memcpy(&state.pointers, &glvao->pointers, sizeof(state.pointers));
    }
    noerrorShim();
}
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays) {
//printf("glDeleteVertexArrays(%i, %p)\n", n, arrays);
	khash_t(glvao) *list = state.vaos;
    if (list) {
        khint_t k;
        glvao_t *glvao;
        for (int i = 0; i < n; i++) {
            GLuint t = arrays[i];
            k = kh_get(glvao, list, t);
            if (k != kh_end(list)) {
                glvao = kh_value(list, k);
                kh_del(glvao, list, k);
                free(glvao);
            }
        }
    }
    noerrorShim();
}
GLboolean glIsVertexArray(GLuint array) {
//printf("glIsVertexArray(%u)\n", array);
	khash_t(glvao) *list = state.vaos;
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
