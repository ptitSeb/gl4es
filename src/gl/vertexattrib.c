#include "vertexattrib.h"

#include "../glx/hardext.h"
#include "buffers.h"
#include "enum_info.h"
#include "gl4es.h"
#include "glstate.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

void gl4es_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
    DBG(printf("glVertexAttribPointer(%d, %d, %s, %d, %d, %p), vertex buffer = %p\n", index, size, PrintEnum(type), normalized, stride, pointer, (glstate->vao->vertex)?glstate->vao->vertex->data:0);)
    FLUSH_BEGINEND;
    // sanity test
    if(index>=hardext.maxvattrib) {
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
    v->size = size;
    v->type = type;
    v->normalized = normalized;
    v->stride = stride;
    v->pointer = pointer;
    v->buffer = glstate->vao->vertex;
    memcpy(&glstate->glesva.wanted[index], v, sizeof(vertexattrib_t));
}
void gl4es_glEnableVertexAttribArray(GLuint index) {
    DBG(printf("glEnableVertexAttrib(%d)\n", index);)
    FLUSH_BEGINEND;
    // sanity test
    if(index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vao->vertexattrib[index].vaarray = 1;
    glstate->glesva.wanted[index].vaarray = 1;
}
void gl4es_glDisableVertexAttribArray(GLuint index) {
    DBG(printf("glDisableVertexAttrib(%d)\n", index);)
    FLUSH_BEGINEND;
    // sanity test
    if(index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vao->vertexattrib[index].vaarray = 0;
    glstate->glesva.wanted[index].vaarray = 0;
}

// TODO: move the sending of the data to the Hardware when drawing, to cache change of state
void gl4es_glVertexAttrib4f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    DBG(printf("glVertexAttrib4f(%d, %f, %f, %f, %f)\n", index, v0, v1, v2, v3);)
    FLUSH_BEGINEND;
    static GLfloat f[4];
    f[0] = v0; f[1] = v1; f[2] = v2; f[3] = v3;
    gl4es_glVertexAttrib4fv(index, f);
}
void gl4es_glVertexAttrib4fv(GLuint index, const GLfloat *v) {
    DBG(printf("glVertexAttrib4fv(%d, %p)\n", index, v);)
    FLUSH_BEGINEND;
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
    memcpy(glstate->glesva.wanted[index].current, v, 4*sizeof(GLfloat));
}

#define GetVertexAttrib(suffix, Type, factor) \
void gl4es_glGetVertexAttrib##suffix##v(GLuint index, GLenum pname, Type *params) { \
    FLUSH_BEGINEND; \
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
        case GL_VERTEX_ATTRIB_ARRAY_DIVISOR: \
            *params=glstate->vao->vertexattrib[index].divisor; \
            return; \
    } \
    errorShim(GL_INVALID_ENUM); \
}

GetVertexAttrib(d, GLdouble, 1.0);
GetVertexAttrib(f, GLfloat, 1.0f);
GetVertexAttrib(i, GLint, 2147483647.0f);
#undef GetVertexAttrib

void gl4es_glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer) {
    FLUSH_BEGINEND;
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

void gl4es_glVertexAttribDivisor(GLuint index, GLuint divisor) {
    FLUSH_BEGINEND;
    // sanity test
    if(index<0 || index>=hardext.maxvattrib) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->vao->vertexattrib[index].divisor = divisor;
    glstate->glesva.wanted[index].divisor = divisor;
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

// ============= GL_ARB_vertex_shader =================
GLvoid glVertexAttrib4fARB(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) AliasExport("gl4es_glVertexAttrib4f");
GLvoid glVertexAttrib4fvARB(GLuint index, const GLfloat *v) AliasExport("gl4es_glVertexAttrib4fv");

GLvoid glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glVertexAttribPointer");

GLvoid glEnableVertexAttribArrayARB(GLuint index) AliasExport("gl4es_glEnableVertexAttribArray");
GLvoid glDisableVertexAttribArrayARB(GLuint index) AliasExport("gl4es_glDisableVertexAttribArray");

GLvoid glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble *params) AliasExport("gl4es_glGetVertexAttribdv");
GLvoid glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetVertexAttribfv");
GLvoid glGetVertexAttribivARB(GLuint index, GLenum pname, GLint *params) AliasExport("gl4es_glGetVertexAttribiv");
GLvoid glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid **pointer) AliasExport("gl4es_glGetVertexAttribPointerv");

// ============== GL_ARB_instanced_arrays =================
void glVertexAttribDivisor(GLuint index, GLuint divisor) AliasExport("gl4es_glVertexAttribDivisor");
void glVertexAttribDivisorARB(GLuint index, GLuint divisor) AliasExport("gl4es_glVertexAttribDivisor");