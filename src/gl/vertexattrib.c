#include "vertexattrib.h"
#include "buffers.h"
#include "../glx/hardext.h"

void gl4es_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(size<1 || (size>4 && size!=GL_BGRA)) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    // TODO: test Type also
    vertexattrib_t *v = &glstate->vao->vertexattrib[index];
    noerrorShim();
    if(stride==0) stride=((size==GL_BGRA)?4:size)*gl_sizeof(type);
    if(size==v->size && type==v->type && normalized==v->normalized && stride==v->stride && pointer==v->pointer && glstate->vao->vertex==v->buffer)
        return; // no changes
    v->size = size;
    v->type = type;
    v->normalized = normalized;
    v->stride = stride;
    v->pointer = pointer;
    v->buffer = glstate->vao->vertex;
    // TODO: move the sending of the data to the Hardware when drawing, to convert if needed the data
    // send to hardware, if any
    LOAD_GLES2(glVertexAttribPointer);
    if(gles_glVertexAttribPointer) {
        gles_glVertexAttribPointer(index, size, type, normalized, stride, (GLvoid*)((uintptr_t)pointer+((v->buffer)?(uintptr_t)v->buffer->data:0)));
        errorGL();
    } else
        errorShim(GL_INVALID_VALUE);
}
void gl4es_glEnableVertexAttribArray(GLuint index) {
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(glstate->vao->vertexattrib[index].vaarray == 1) {
        noerrorShim();
        return; // already enalbled
    }
    glstate->vao->vertexattrib[index].vaarray = 1;
    // TODO: move the sending of the data to the Hardware when drawing, to cache change of state
    LOAD_GLES2(glEnableVertexAttribArray);
    if(gles_glEnableVertexAttribArray) {
        gles_glEnableVertexAttribArray(index);
        errorGL();
    } else {
        errorShim(GL_INVALID_ENUM);
    }
}
void gl4es_glDisableVertexAttribArray(GLuint index) {
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if(glstate->vao->vertexattrib[index].vaarray == 0) {
        noerrorShim();
        return; // already enalbled
    }
    glstate->vao->vertexattrib[index].vaarray = 0;
    // TODO: move the sending of the data to the Hardware when drawing, to cache change of state
    LOAD_GLES2(glDisableVertexAttribArray);
    if(gles_glDisableVertexAttribArray) {
        gles_glDisableVertexAttribArray(index);
        errorGL();
    } else {
        errorShim(GL_INVALID_ENUM);
    }
}

// TODO: move the sending of the data to the Hardware when drawing, to cache change of state
void gl4es_glVertexAttrib4f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    static GLfloat f[4];
    f[0] = v0; f[1] = v1; f[2] = v2; f[3] = v3;
    gl4es_glVertexAttrib4fv(index, f);
}
void gl4es_glVertexAttrib4fv(GLuint index, const GLfloat *v) {
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    // test if changed
    if(memcmp(glstate->vao->vertexattrib[index].current, v, 4*sizeof(GLfloat))==0) {
        noerrorShim();
        return;
    }
    memcpy(glstate->vao->vertexattrib[index].current, v, 4*sizeof(GLfloat));
    LOAD_GLES2(glVertexAttrib4fv);
    if(gles_glVertexAttrib4fv) {
        gles_glVertexAttrib4fv(index, v);
        errorGL();
    } else {
        errorShim(GL_INVALID_VALUE);
    }
}

#define GetVertexAttrib(suffix, Type, factor) \
void gl4es_glGetVertexAttrib##suffix##v(GLuint index, GLenum pname, Type *params) { \
    if(index<0 || index>=hardext.maxvattrib) { \
        errorShim(GL_INVALID_VALUE); \
        return; \
    } \
    noerrorShim(); \
    switch(pname) { \
        case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING: \
            *params=(glstate->vao->vertexattrib[index].buffer)?glstate->vao->vertexattrib[index].buffer->buffer:0; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_ENABLED: \
            *params=(glstate->vao->vertexattrib[index].vaarray)?1:0; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_SIZE: \
            *params=glstate->vao->vertexattrib[index].size; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_STRIDE: \
            *params=glstate->vao->vertexattrib[index].stride; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_TYPE: \
            *params=glstate->vao->vertexattrib[index].type; \
            return; \
        case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED: \
            *params=glstate->vao->vertexattrib[index].normalized; \
            return; \
        case GL_CURRENT_VERTEX_ATTRIB: \
            for (int i=0; i<4; i++) \
                *params=glstate->vao->vertexattrib[index].current[i]*factor; \
            return; \
    } \
    errorShim(GL_INVALID_ENUM); \
}

GetVertexAttrib(d, GLdouble, 1.0);
GetVertexAttrib(f, GLfloat, 1.0f);
GetVertexAttrib(i, GLint, 2147483647.0f);
#undef GetVertexAttrib

void gl4es_glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer) {
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    if (pname!=GL_VERTEX_ATTRIB_ARRAY_POINTER) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    *pointer = (GLvoid*)glstate->vao->vertexattrib[index].pointer;
    noerrorShim();
}

void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glVertexAttribPointer");
void glEnableVertexAttribArray(GLuint index) AliasExport("gl4es_glEnableVertexAttribArray");
void glDisableVertexAttribArray(GLuint index) AliasExport("gl4es_glDisableVertexAttribArray");
void glVertexAttrib4f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) AliasExport("gl4es_glVertexAttrib4f");
void glVertexAttrib4fv(GLuint index, const GLfloat *v) AliasExport("gl4es_glVertexAttrib4fv");
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) AliasExport("gl4es_glGetVertexAttribdv");
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetVertexAttribfv");
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) AliasExport("gl4es_glGetVertexAttribiv");
void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer) AliasExport("gl4es_glGetVertexAttribPointerv");