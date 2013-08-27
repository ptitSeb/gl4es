#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../proxy.h"


#ifndef skip_client_glAccum
void glAccum(GLenum op, GLfloat value) {
    glAccum_INDEXED *packed_data = malloc(sizeof(glAccum_INDEXED));
    packed_data->func = glAccum_INDEX;
    packed_data->args.a1 = op;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glActiveTexture
void glActiveTexture(GLenum texture) {
    glActiveTexture_INDEXED *packed_data = malloc(sizeof(glActiveTexture_INDEXED));
    packed_data->func = glActiveTexture_INDEX;
    packed_data->args.a1 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glAlphaFunc
void glAlphaFunc(GLenum func, GLfloat ref) {
    glAlphaFunc_INDEXED *packed_data = malloc(sizeof(glAlphaFunc_INDEXED));
    packed_data->func = glAlphaFunc_INDEX;
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glAreTexturesResident
GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences) {
    glAreTexturesResident_INDEXED *packed_data = malloc(sizeof(glAreTexturesResident_INDEXED));
    packed_data->func = glAreTexturesResident_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    packed_data->args.a3 = residences;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glArrayElement
void glArrayElement(GLint i) {
    glArrayElement_INDEXED *packed_data = malloc(sizeof(glArrayElement_INDEXED));
    packed_data->func = glArrayElement_INDEX;
    packed_data->args.a1 = i;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBegin
void glBegin(GLenum mode) {
    glBegin_INDEXED *packed_data = malloc(sizeof(glBegin_INDEXED));
    packed_data->func = glBegin_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBeginQuery
void glBeginQuery(GLenum target, GLuint id) {
    glBeginQuery_INDEXED *packed_data = malloc(sizeof(glBeginQuery_INDEXED));
    packed_data->func = glBeginQuery_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBindBuffer
void glBindBuffer(GLenum target, GLuint buffer) {
    glBindBuffer_INDEXED *packed_data = malloc(sizeof(glBindBuffer_INDEXED));
    packed_data->func = glBindBuffer_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBindTexture
void glBindTexture(GLenum target, GLuint texture) {
    glBindTexture_INDEXED *packed_data = malloc(sizeof(glBindTexture_INDEXED));
    packed_data->func = glBindTexture_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBitmap
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap) {
    glBitmap_INDEXED *packed_data = malloc(sizeof(glBitmap_INDEXED));
    packed_data->func = glBitmap_INDEX;
    packed_data->args.a1 = width;
    packed_data->args.a2 = height;
    packed_data->args.a3 = xorig;
    packed_data->args.a4 = yorig;
    packed_data->args.a5 = xmove;
    packed_data->args.a6 = ymove;
    packed_data->args.a7 = bitmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBlendColor
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glBlendColor_INDEXED *packed_data = malloc(sizeof(glBlendColor_INDEXED));
    packed_data->func = glBlendColor_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBlendEquation
void glBlendEquation(GLenum mode) {
    glBlendEquation_INDEXED *packed_data = malloc(sizeof(glBlendEquation_INDEXED));
    packed_data->func = glBlendEquation_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBlendFunc
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    glBlendFunc_INDEXED *packed_data = malloc(sizeof(glBlendFunc_INDEXED));
    packed_data->func = glBlendFunc_INDEX;
    packed_data->args.a1 = sfactor;
    packed_data->args.a2 = dfactor;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBlendFuncSeparate
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    glBlendFuncSeparate_INDEXED *packed_data = malloc(sizeof(glBlendFuncSeparate_INDEXED));
    packed_data->func = glBlendFuncSeparate_INDEX;
    packed_data->args.a1 = sfactorRGB;
    packed_data->args.a2 = dfactorRGB;
    packed_data->args.a3 = sfactorAlpha;
    packed_data->args.a4 = dfactorAlpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBufferData
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    glBufferData_INDEXED *packed_data = malloc(sizeof(glBufferData_INDEXED));
    packed_data->func = glBufferData_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = size;
    packed_data->args.a3 = data;
    packed_data->args.a4 = usage;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glBufferSubData
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    glBufferSubData_INDEXED *packed_data = malloc(sizeof(glBufferSubData_INDEXED));
    packed_data->func = glBufferSubData_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = size;
    packed_data->args.a4 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCallList
void glCallList(GLuint list) {
    glCallList_INDEXED *packed_data = malloc(sizeof(glCallList_INDEXED));
    packed_data->func = glCallList_INDEX;
    packed_data->args.a1 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCallLists
void glCallLists(GLsizei n, GLenum type, const GLvoid * lists) {
    glCallLists_INDEXED *packed_data = malloc(sizeof(glCallLists_INDEXED));
    packed_data->func = glCallLists_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = type;
    packed_data->args.a3 = lists;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glClear
void glClear(GLbitfield mask) {
    glClear_INDEXED *packed_data = malloc(sizeof(glClear_INDEXED));
    packed_data->func = glClear_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glClearAccum
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glClearAccum_INDEXED *packed_data = malloc(sizeof(glClearAccum_INDEXED));
    packed_data->func = glClearAccum_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glClearColor
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glClearColor_INDEXED *packed_data = malloc(sizeof(glClearColor_INDEXED));
    packed_data->func = glClearColor_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glClearDepth
void glClearDepth(GLdouble depth) {
    glClearDepth_INDEXED *packed_data = malloc(sizeof(glClearDepth_INDEXED));
    packed_data->func = glClearDepth_INDEX;
    packed_data->args.a1 = depth;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glClearIndex
void glClearIndex(GLfloat c) {
    glClearIndex_INDEXED *packed_data = malloc(sizeof(glClearIndex_INDEXED));
    packed_data->func = glClearIndex_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glClearStencil
void glClearStencil(GLint s) {
    glClearStencil_INDEXED *packed_data = malloc(sizeof(glClearStencil_INDEXED));
    packed_data->func = glClearStencil_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glClientActiveTexture
void glClientActiveTexture(GLenum texture) {
    glClientActiveTexture_INDEXED *packed_data = malloc(sizeof(glClientActiveTexture_INDEXED));
    packed_data->func = glClientActiveTexture_INDEX;
    packed_data->args.a1 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glClipPlane
void glClipPlane(GLenum plane, const GLdouble * equation) {
    glClipPlane_INDEXED *packed_data = malloc(sizeof(glClipPlane_INDEXED));
    packed_data->func = glClipPlane_INDEX;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3b
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    glColor3b_INDEXED *packed_data = malloc(sizeof(glColor3b_INDEXED));
    packed_data->func = glColor3b_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3bv
void glColor3bv(const GLbyte * v) {
    glColor3bv_INDEXED *packed_data = malloc(sizeof(glColor3bv_INDEXED));
    packed_data->func = glColor3bv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3d
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    glColor3d_INDEXED *packed_data = malloc(sizeof(glColor3d_INDEXED));
    packed_data->func = glColor3d_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3dv
void glColor3dv(const GLdouble * v) {
    glColor3dv_INDEXED *packed_data = malloc(sizeof(glColor3dv_INDEXED));
    packed_data->func = glColor3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3f
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f_INDEXED *packed_data = malloc(sizeof(glColor3f_INDEXED));
    packed_data->func = glColor3f_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3fv
void glColor3fv(const GLfloat * v) {
    glColor3fv_INDEXED *packed_data = malloc(sizeof(glColor3fv_INDEXED));
    packed_data->func = glColor3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3i
void glColor3i(GLint red, GLint green, GLint blue) {
    glColor3i_INDEXED *packed_data = malloc(sizeof(glColor3i_INDEXED));
    packed_data->func = glColor3i_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3iv
void glColor3iv(const GLint * v) {
    glColor3iv_INDEXED *packed_data = malloc(sizeof(glColor3iv_INDEXED));
    packed_data->func = glColor3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3s
void glColor3s(GLshort red, GLshort green, GLshort blue) {
    glColor3s_INDEXED *packed_data = malloc(sizeof(glColor3s_INDEXED));
    packed_data->func = glColor3s_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3sv
void glColor3sv(const GLshort * v) {
    glColor3sv_INDEXED *packed_data = malloc(sizeof(glColor3sv_INDEXED));
    packed_data->func = glColor3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3ub
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    glColor3ub_INDEXED *packed_data = malloc(sizeof(glColor3ub_INDEXED));
    packed_data->func = glColor3ub_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3ubv
void glColor3ubv(const GLubyte * v) {
    glColor3ubv_INDEXED *packed_data = malloc(sizeof(glColor3ubv_INDEXED));
    packed_data->func = glColor3ubv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3ui
void glColor3ui(GLuint red, GLuint green, GLuint blue) {
    glColor3ui_INDEXED *packed_data = malloc(sizeof(glColor3ui_INDEXED));
    packed_data->func = glColor3ui_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3uiv
void glColor3uiv(const GLuint * v) {
    glColor3uiv_INDEXED *packed_data = malloc(sizeof(glColor3uiv_INDEXED));
    packed_data->func = glColor3uiv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3us
void glColor3us(GLushort red, GLushort green, GLushort blue) {
    glColor3us_INDEXED *packed_data = malloc(sizeof(glColor3us_INDEXED));
    packed_data->func = glColor3us_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor3usv
void glColor3usv(const GLushort * v) {
    glColor3usv_INDEXED *packed_data = malloc(sizeof(glColor3usv_INDEXED));
    packed_data->func = glColor3usv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4b
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    glColor4b_INDEXED *packed_data = malloc(sizeof(glColor4b_INDEXED));
    packed_data->func = glColor4b_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4bv
void glColor4bv(const GLbyte * v) {
    glColor4bv_INDEXED *packed_data = malloc(sizeof(glColor4bv_INDEXED));
    packed_data->func = glColor4bv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4d
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    glColor4d_INDEXED *packed_data = malloc(sizeof(glColor4d_INDEXED));
    packed_data->func = glColor4d_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4dv
void glColor4dv(const GLdouble * v) {
    glColor4dv_INDEXED *packed_data = malloc(sizeof(glColor4dv_INDEXED));
    packed_data->func = glColor4dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4f
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glColor4f_INDEXED *packed_data = malloc(sizeof(glColor4f_INDEXED));
    packed_data->func = glColor4f_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4fv
void glColor4fv(const GLfloat * v) {
    glColor4fv_INDEXED *packed_data = malloc(sizeof(glColor4fv_INDEXED));
    packed_data->func = glColor4fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4i
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
    glColor4i_INDEXED *packed_data = malloc(sizeof(glColor4i_INDEXED));
    packed_data->func = glColor4i_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4iv
void glColor4iv(const GLint * v) {
    glColor4iv_INDEXED *packed_data = malloc(sizeof(glColor4iv_INDEXED));
    packed_data->func = glColor4iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4s
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    glColor4s_INDEXED *packed_data = malloc(sizeof(glColor4s_INDEXED));
    packed_data->func = glColor4s_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4sv
void glColor4sv(const GLshort * v) {
    glColor4sv_INDEXED *packed_data = malloc(sizeof(glColor4sv_INDEXED));
    packed_data->func = glColor4sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4ub
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    glColor4ub_INDEXED *packed_data = malloc(sizeof(glColor4ub_INDEXED));
    packed_data->func = glColor4ub_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4ubv
void glColor4ubv(const GLubyte * v) {
    glColor4ubv_INDEXED *packed_data = malloc(sizeof(glColor4ubv_INDEXED));
    packed_data->func = glColor4ubv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4ui
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    glColor4ui_INDEXED *packed_data = malloc(sizeof(glColor4ui_INDEXED));
    packed_data->func = glColor4ui_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4uiv
void glColor4uiv(const GLuint * v) {
    glColor4uiv_INDEXED *packed_data = malloc(sizeof(glColor4uiv_INDEXED));
    packed_data->func = glColor4uiv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4us
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    glColor4us_INDEXED *packed_data = malloc(sizeof(glColor4us_INDEXED));
    packed_data->func = glColor4us_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColor4usv
void glColor4usv(const GLushort * v) {
    glColor4usv_INDEXED *packed_data = malloc(sizeof(glColor4usv_INDEXED));
    packed_data->func = glColor4usv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColorMask
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    glColorMask_INDEXED *packed_data = malloc(sizeof(glColorMask_INDEXED));
    packed_data->func = glColorMask_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColorMaterial
void glColorMaterial(GLenum face, GLenum mode) {
    glColorMaterial_INDEXED *packed_data = malloc(sizeof(glColorMaterial_INDEXED));
    packed_data->func = glColorMaterial_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColorPointer
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glColorPointer_INDEXED *packed_data = malloc(sizeof(glColorPointer_INDEXED));
    packed_data->func = glColorPointer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColorSubTable
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data) {
    glColorSubTable_INDEXED *packed_data = malloc(sizeof(glColorSubTable_INDEXED));
    packed_data->func = glColorSubTable_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = start;
    packed_data->args.a3 = count;
    packed_data->args.a4 = format;
    packed_data->args.a5 = type;
    packed_data->args.a6 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColorTable
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table) {
    glColorTable_INDEXED *packed_data = malloc(sizeof(glColorTable_INDEXED));
    packed_data->func = glColorTable_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = format;
    packed_data->args.a5 = type;
    packed_data->args.a6 = table;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColorTableParameterfv
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glColorTableParameterfv_INDEXED *packed_data = malloc(sizeof(glColorTableParameterfv_INDEXED));
    packed_data->func = glColorTableParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glColorTableParameteriv
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glColorTableParameteriv_INDEXED *packed_data = malloc(sizeof(glColorTableParameteriv_INDEXED));
    packed_data->func = glColorTableParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCompressedTexImage1D
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexImage1D_INDEXED *packed_data = malloc(sizeof(glCompressedTexImage1D_INDEXED));
    packed_data->func = glCompressedTexImage1D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = border;
    packed_data->args.a6 = imageSize;
    packed_data->args.a7 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCompressedTexImage2D
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexImage2D_INDEXED *packed_data = malloc(sizeof(glCompressedTexImage2D_INDEXED));
    packed_data->func = glCompressedTexImage2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = height;
    packed_data->args.a6 = border;
    packed_data->args.a7 = imageSize;
    packed_data->args.a8 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCompressedTexImage3D
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexImage3D_INDEXED *packed_data = malloc(sizeof(glCompressedTexImage3D_INDEXED));
    packed_data->func = glCompressedTexImage3D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = height;
    packed_data->args.a6 = depth;
    packed_data->args.a7 = border;
    packed_data->args.a8 = imageSize;
    packed_data->args.a9 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCompressedTexSubImage1D
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexSubImage1D_INDEXED *packed_data = malloc(sizeof(glCompressedTexSubImage1D_INDEXED));
    packed_data->func = glCompressedTexSubImage1D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = width;
    packed_data->args.a5 = format;
    packed_data->args.a6 = imageSize;
    packed_data->args.a7 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCompressedTexSubImage2D
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexSubImage2D_INDEXED *packed_data = malloc(sizeof(glCompressedTexSubImage2D_INDEXED));
    packed_data->func = glCompressedTexSubImage2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = width;
    packed_data->args.a6 = height;
    packed_data->args.a7 = format;
    packed_data->args.a8 = imageSize;
    packed_data->args.a9 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCompressedTexSubImage3D
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexSubImage3D_INDEXED *packed_data = malloc(sizeof(glCompressedTexSubImage3D_INDEXED));
    packed_data->func = glCompressedTexSubImage3D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = zoffset;
    packed_data->args.a6 = width;
    packed_data->args.a7 = height;
    packed_data->args.a8 = depth;
    packed_data->args.a9 = format;
    packed_data->args.a10 = imageSize;
    packed_data->args.a11 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glConvolutionFilter1D
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image) {
    glConvolutionFilter1D_INDEXED *packed_data = malloc(sizeof(glConvolutionFilter1D_INDEXED));
    packed_data->func = glConvolutionFilter1D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = format;
    packed_data->args.a5 = type;
    packed_data->args.a6 = image;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glConvolutionFilter2D
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image) {
    glConvolutionFilter2D_INDEXED *packed_data = malloc(sizeof(glConvolutionFilter2D_INDEXED));
    packed_data->func = glConvolutionFilter2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = format;
    packed_data->args.a6 = type;
    packed_data->args.a7 = image;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glConvolutionParameterf
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
    glConvolutionParameterf_INDEXED *packed_data = malloc(sizeof(glConvolutionParameterf_INDEXED));
    packed_data->func = glConvolutionParameterf_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glConvolutionParameterfv
void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glConvolutionParameterfv_INDEXED *packed_data = malloc(sizeof(glConvolutionParameterfv_INDEXED));
    packed_data->func = glConvolutionParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glConvolutionParameteri
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
    glConvolutionParameteri_INDEXED *packed_data = malloc(sizeof(glConvolutionParameteri_INDEXED));
    packed_data->func = glConvolutionParameteri_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glConvolutionParameteriv
void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glConvolutionParameteriv_INDEXED *packed_data = malloc(sizeof(glConvolutionParameteriv_INDEXED));
    packed_data->func = glConvolutionParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyColorSubTable
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    glCopyColorSubTable_INDEXED *packed_data = malloc(sizeof(glCopyColorSubTable_INDEXED));
    packed_data->func = glCopyColorSubTable_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = start;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyColorTable
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    glCopyColorTable_INDEXED *packed_data = malloc(sizeof(glCopyColorTable_INDEXED));
    packed_data->func = glCopyColorTable_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyConvolutionFilter1D
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    glCopyConvolutionFilter1D_INDEXED *packed_data = malloc(sizeof(glCopyConvolutionFilter1D_INDEXED));
    packed_data->func = glCopyConvolutionFilter1D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyConvolutionFilter2D
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    glCopyConvolutionFilter2D_INDEXED *packed_data = malloc(sizeof(glCopyConvolutionFilter2D_INDEXED));
    packed_data->func = glCopyConvolutionFilter2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    packed_data->args.a6 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyPixels
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
    glCopyPixels_INDEXED *packed_data = malloc(sizeof(glCopyPixels_INDEXED));
    packed_data->func = glCopyPixels_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyTexImage1D
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    glCopyTexImage1D_INDEXED *packed_data = malloc(sizeof(glCopyTexImage1D_INDEXED));
    packed_data->func = glCopyTexImage1D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = x;
    packed_data->args.a5 = y;
    packed_data->args.a6 = width;
    packed_data->args.a7 = border;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyTexImage2D
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    glCopyTexImage2D_INDEXED *packed_data = malloc(sizeof(glCopyTexImage2D_INDEXED));
    packed_data->func = glCopyTexImage2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = x;
    packed_data->args.a5 = y;
    packed_data->args.a6 = width;
    packed_data->args.a7 = height;
    packed_data->args.a8 = border;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyTexSubImage1D
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    glCopyTexSubImage1D_INDEXED *packed_data = malloc(sizeof(glCopyTexSubImage1D_INDEXED));
    packed_data->func = glCopyTexSubImage1D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = x;
    packed_data->args.a5 = y;
    packed_data->args.a6 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyTexSubImage2D
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glCopyTexSubImage2D_INDEXED *packed_data = malloc(sizeof(glCopyTexSubImage2D_INDEXED));
    packed_data->func = glCopyTexSubImage2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = x;
    packed_data->args.a6 = y;
    packed_data->args.a7 = width;
    packed_data->args.a8 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCopyTexSubImage3D
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glCopyTexSubImage3D_INDEXED *packed_data = malloc(sizeof(glCopyTexSubImage3D_INDEXED));
    packed_data->func = glCopyTexSubImage3D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = zoffset;
    packed_data->args.a6 = x;
    packed_data->args.a7 = y;
    packed_data->args.a8 = width;
    packed_data->args.a9 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glCullFace
void glCullFace(GLenum mode) {
    glCullFace_INDEXED *packed_data = malloc(sizeof(glCullFace_INDEXED));
    packed_data->func = glCullFace_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDeleteBuffers
void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    glDeleteBuffers_INDEXED *packed_data = malloc(sizeof(glDeleteBuffers_INDEXED));
    packed_data->func = glDeleteBuffers_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffers;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDeleteLists
void glDeleteLists(GLuint list, GLsizei range) {
    glDeleteLists_INDEXED *packed_data = malloc(sizeof(glDeleteLists_INDEXED));
    packed_data->func = glDeleteLists_INDEX;
    packed_data->args.a1 = list;
    packed_data->args.a2 = range;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDeleteQueries
void glDeleteQueries(GLsizei n, const GLuint * ids) {
    glDeleteQueries_INDEXED *packed_data = malloc(sizeof(glDeleteQueries_INDEXED));
    packed_data->func = glDeleteQueries_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = ids;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDeleteTextures
void glDeleteTextures(GLsizei n, const GLuint * textures) {
    glDeleteTextures_INDEXED *packed_data = malloc(sizeof(glDeleteTextures_INDEXED));
    packed_data->func = glDeleteTextures_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDepthFunc
void glDepthFunc(GLenum func) {
    glDepthFunc_INDEXED *packed_data = malloc(sizeof(glDepthFunc_INDEXED));
    packed_data->func = glDepthFunc_INDEX;
    packed_data->args.a1 = func;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDepthMask
void glDepthMask(GLboolean flag) {
    glDepthMask_INDEXED *packed_data = malloc(sizeof(glDepthMask_INDEXED));
    packed_data->func = glDepthMask_INDEX;
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDepthRange
void glDepthRange(GLdouble near, GLdouble far) {
    glDepthRange_INDEXED *packed_data = malloc(sizeof(glDepthRange_INDEXED));
    packed_data->func = glDepthRange_INDEX;
    packed_data->args.a1 = near;
    packed_data->args.a2 = far;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDisable
void glDisable(GLenum cap) {
    glDisable_INDEXED *packed_data = malloc(sizeof(glDisable_INDEXED));
    packed_data->func = glDisable_INDEX;
    packed_data->args.a1 = cap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDisableClientState
void glDisableClientState(GLenum array) {
    glDisableClientState_INDEXED *packed_data = malloc(sizeof(glDisableClientState_INDEXED));
    packed_data->func = glDisableClientState_INDEX;
    packed_data->args.a1 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDrawArrays
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    glDrawArrays_INDEXED *packed_data = malloc(sizeof(glDrawArrays_INDEXED));
    packed_data->func = glDrawArrays_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDrawBuffer
void glDrawBuffer(GLenum mode) {
    glDrawBuffer_INDEXED *packed_data = malloc(sizeof(glDrawBuffer_INDEXED));
    packed_data->func = glDrawBuffer_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDrawElements
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    glDrawElements_INDEXED *packed_data = malloc(sizeof(glDrawElements_INDEXED));
    packed_data->func = glDrawElements_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = count;
    packed_data->args.a3 = type;
    packed_data->args.a4 = indices;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDrawPixels
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    glDrawPixels_INDEXED *packed_data = malloc(sizeof(glDrawPixels_INDEXED));
    packed_data->func = glDrawPixels_INDEX;
    packed_data->args.a1 = width;
    packed_data->args.a2 = height;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glDrawRangeElements
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices) {
    glDrawRangeElements_INDEXED *packed_data = malloc(sizeof(glDrawRangeElements_INDEXED));
    packed_data->func = glDrawRangeElements_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = start;
    packed_data->args.a3 = end;
    packed_data->args.a4 = count;
    packed_data->args.a5 = type;
    packed_data->args.a6 = indices;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEdgeFlag
void glEdgeFlag(GLboolean flag) {
    glEdgeFlag_INDEXED *packed_data = malloc(sizeof(glEdgeFlag_INDEXED));
    packed_data->func = glEdgeFlag_INDEX;
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEdgeFlagPointer
void glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer) {
    glEdgeFlagPointer_INDEXED *packed_data = malloc(sizeof(glEdgeFlagPointer_INDEXED));
    packed_data->func = glEdgeFlagPointer_INDEX;
    packed_data->args.a1 = stride;
    packed_data->args.a2 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEdgeFlagv
void glEdgeFlagv(const GLboolean * flag) {
    glEdgeFlagv_INDEXED *packed_data = malloc(sizeof(glEdgeFlagv_INDEXED));
    packed_data->func = glEdgeFlagv_INDEX;
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEnable
void glEnable(GLenum cap) {
    glEnable_INDEXED *packed_data = malloc(sizeof(glEnable_INDEXED));
    packed_data->func = glEnable_INDEX;
    packed_data->args.a1 = cap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEnableClientState
void glEnableClientState(GLenum array) {
    glEnableClientState_INDEXED *packed_data = malloc(sizeof(glEnableClientState_INDEXED));
    packed_data->func = glEnableClientState_INDEX;
    packed_data->args.a1 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEnd
void glEnd() {
    glEnd_INDEXED *packed_data = malloc(sizeof(glEnd_INDEXED));
    packed_data->func = glEnd_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEndList
void glEndList() {
    glEndList_INDEXED *packed_data = malloc(sizeof(glEndList_INDEXED));
    packed_data->func = glEndList_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEndQuery
void glEndQuery(GLenum target) {
    glEndQuery_INDEXED *packed_data = malloc(sizeof(glEndQuery_INDEXED));
    packed_data->func = glEndQuery_INDEX;
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalCoord1d
void glEvalCoord1d(GLdouble u) {
    glEvalCoord1d_INDEXED *packed_data = malloc(sizeof(glEvalCoord1d_INDEXED));
    packed_data->func = glEvalCoord1d_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalCoord1dv
void glEvalCoord1dv(const GLdouble * u) {
    glEvalCoord1dv_INDEXED *packed_data = malloc(sizeof(glEvalCoord1dv_INDEXED));
    packed_data->func = glEvalCoord1dv_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalCoord1f
void glEvalCoord1f(GLfloat u) {
    glEvalCoord1f_INDEXED *packed_data = malloc(sizeof(glEvalCoord1f_INDEXED));
    packed_data->func = glEvalCoord1f_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalCoord1fv
void glEvalCoord1fv(const GLfloat * u) {
    glEvalCoord1fv_INDEXED *packed_data = malloc(sizeof(glEvalCoord1fv_INDEXED));
    packed_data->func = glEvalCoord1fv_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalCoord2d
void glEvalCoord2d(GLdouble u, GLdouble v) {
    glEvalCoord2d_INDEXED *packed_data = malloc(sizeof(glEvalCoord2d_INDEXED));
    packed_data->func = glEvalCoord2d_INDEX;
    packed_data->args.a1 = u;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalCoord2dv
void glEvalCoord2dv(const GLdouble * u) {
    glEvalCoord2dv_INDEXED *packed_data = malloc(sizeof(glEvalCoord2dv_INDEXED));
    packed_data->func = glEvalCoord2dv_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalCoord2f
void glEvalCoord2f(GLfloat u, GLfloat v) {
    glEvalCoord2f_INDEXED *packed_data = malloc(sizeof(glEvalCoord2f_INDEXED));
    packed_data->func = glEvalCoord2f_INDEX;
    packed_data->args.a1 = u;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalCoord2fv
void glEvalCoord2fv(const GLfloat * u) {
    glEvalCoord2fv_INDEXED *packed_data = malloc(sizeof(glEvalCoord2fv_INDEXED));
    packed_data->func = glEvalCoord2fv_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalMesh1
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    glEvalMesh1_INDEXED *packed_data = malloc(sizeof(glEvalMesh1_INDEXED));
    packed_data->func = glEvalMesh1_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = i1;
    packed_data->args.a3 = i2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalMesh2
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    glEvalMesh2_INDEXED *packed_data = malloc(sizeof(glEvalMesh2_INDEXED));
    packed_data->func = glEvalMesh2_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = i1;
    packed_data->args.a3 = i2;
    packed_data->args.a4 = j1;
    packed_data->args.a5 = j2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalPoint1
void glEvalPoint1(GLint i) {
    glEvalPoint1_INDEXED *packed_data = malloc(sizeof(glEvalPoint1_INDEXED));
    packed_data->func = glEvalPoint1_INDEX;
    packed_data->args.a1 = i;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glEvalPoint2
void glEvalPoint2(GLint i, GLint j) {
    glEvalPoint2_INDEXED *packed_data = malloc(sizeof(glEvalPoint2_INDEXED));
    packed_data->func = glEvalPoint2_INDEX;
    packed_data->args.a1 = i;
    packed_data->args.a2 = j;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFeedbackBuffer
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
    glFeedbackBuffer_INDEXED *packed_data = malloc(sizeof(glFeedbackBuffer_INDEXED));
    packed_data->func = glFeedbackBuffer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFinish
void glFinish() {
    glFinish_INDEXED *packed_data = malloc(sizeof(glFinish_INDEXED));
    packed_data->func = glFinish_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFlush
void glFlush() {
    glFlush_INDEXED *packed_data = malloc(sizeof(glFlush_INDEXED));
    packed_data->func = glFlush_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogCoordPointer
void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glFogCoordPointer_INDEXED *packed_data = malloc(sizeof(glFogCoordPointer_INDEXED));
    packed_data->func = glFogCoordPointer_INDEX;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogCoordd
void glFogCoordd(GLdouble coord) {
    glFogCoordd_INDEXED *packed_data = malloc(sizeof(glFogCoordd_INDEXED));
    packed_data->func = glFogCoordd_INDEX;
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogCoorddv
void glFogCoorddv(const GLdouble * coord) {
    glFogCoorddv_INDEXED *packed_data = malloc(sizeof(glFogCoorddv_INDEXED));
    packed_data->func = glFogCoorddv_INDEX;
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogCoordf
void glFogCoordf(GLfloat coord) {
    glFogCoordf_INDEXED *packed_data = malloc(sizeof(glFogCoordf_INDEXED));
    packed_data->func = glFogCoordf_INDEX;
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogCoordfv
void glFogCoordfv(const GLfloat * coord) {
    glFogCoordfv_INDEXED *packed_data = malloc(sizeof(glFogCoordfv_INDEXED));
    packed_data->func = glFogCoordfv_INDEX;
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogf
void glFogf(GLenum pname, GLfloat param) {
    glFogf_INDEXED *packed_data = malloc(sizeof(glFogf_INDEXED));
    packed_data->func = glFogf_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogfv
void glFogfv(GLenum pname, const GLfloat * params) {
    glFogfv_INDEXED *packed_data = malloc(sizeof(glFogfv_INDEXED));
    packed_data->func = glFogfv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogi
void glFogi(GLenum pname, GLint param) {
    glFogi_INDEXED *packed_data = malloc(sizeof(glFogi_INDEXED));
    packed_data->func = glFogi_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFogiv
void glFogiv(GLenum pname, const GLint * params) {
    glFogiv_INDEXED *packed_data = malloc(sizeof(glFogiv_INDEXED));
    packed_data->func = glFogiv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFrontFace
void glFrontFace(GLenum mode) {
    glFrontFace_INDEXED *packed_data = malloc(sizeof(glFrontFace_INDEXED));
    packed_data->func = glFrontFace_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glFrustum
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    glFrustum_INDEXED *packed_data = malloc(sizeof(glFrustum_INDEXED));
    packed_data->func = glFrustum_INDEX;
    packed_data->args.a1 = left;
    packed_data->args.a2 = right;
    packed_data->args.a3 = bottom;
    packed_data->args.a4 = top;
    packed_data->args.a5 = zNear;
    packed_data->args.a6 = zFar;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGenBuffers
void glGenBuffers(GLsizei n, GLuint * buffers) {
    glGenBuffers_INDEXED *packed_data = malloc(sizeof(glGenBuffers_INDEXED));
    packed_data->func = glGenBuffers_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffers;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGenLists
GLuint glGenLists(GLsizei range) {
    glGenLists_INDEXED *packed_data = malloc(sizeof(glGenLists_INDEXED));
    packed_data->func = glGenLists_INDEX;
    packed_data->args.a1 = range;
    GLuint ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glGenQueries
void glGenQueries(GLsizei n, GLuint * ids) {
    glGenQueries_INDEXED *packed_data = malloc(sizeof(glGenQueries_INDEXED));
    packed_data->func = glGenQueries_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = ids;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGenTextures
void glGenTextures(GLsizei n, GLuint * textures) {
    glGenTextures_INDEXED *packed_data = malloc(sizeof(glGenTextures_INDEXED));
    packed_data->func = glGenTextures_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetBooleanv
void glGetBooleanv(GLenum pname, GLboolean * params) {
    glGetBooleanv_INDEXED *packed_data = malloc(sizeof(glGetBooleanv_INDEXED));
    packed_data->func = glGetBooleanv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetBufferParameteriv
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetBufferParameteriv_INDEXED *packed_data = malloc(sizeof(glGetBufferParameteriv_INDEXED));
    packed_data->func = glGetBufferParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetBufferPointerv
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params) {
    glGetBufferPointerv_INDEXED *packed_data = malloc(sizeof(glGetBufferPointerv_INDEXED));
    packed_data->func = glGetBufferPointerv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetBufferSubData
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
    glGetBufferSubData_INDEXED *packed_data = malloc(sizeof(glGetBufferSubData_INDEXED));
    packed_data->func = glGetBufferSubData_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = size;
    packed_data->args.a4 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetClipPlane
void glGetClipPlane(GLenum plane, GLdouble * equation) {
    glGetClipPlane_INDEXED *packed_data = malloc(sizeof(glGetClipPlane_INDEXED));
    packed_data->func = glGetClipPlane_INDEX;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetColorTable
void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid * table) {
    glGetColorTable_INDEXED *packed_data = malloc(sizeof(glGetColorTable_INDEXED));
    packed_data->func = glGetColorTable_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = table;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetColorTableParameterfv
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetColorTableParameterfv_INDEXED *packed_data = malloc(sizeof(glGetColorTableParameterfv_INDEXED));
    packed_data->func = glGetColorTableParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetColorTableParameteriv
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetColorTableParameteriv_INDEXED *packed_data = malloc(sizeof(glGetColorTableParameteriv_INDEXED));
    packed_data->func = glGetColorTableParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetCompressedTexImage
void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img) {
    glGetCompressedTexImage_INDEXED *packed_data = malloc(sizeof(glGetCompressedTexImage_INDEXED));
    packed_data->func = glGetCompressedTexImage_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = img;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetConvolutionFilter
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid * image) {
    glGetConvolutionFilter_INDEXED *packed_data = malloc(sizeof(glGetConvolutionFilter_INDEXED));
    packed_data->func = glGetConvolutionFilter_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = image;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetConvolutionParameterfv
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetConvolutionParameterfv_INDEXED *packed_data = malloc(sizeof(glGetConvolutionParameterfv_INDEXED));
    packed_data->func = glGetConvolutionParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetConvolutionParameteriv
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetConvolutionParameteriv_INDEXED *packed_data = malloc(sizeof(glGetConvolutionParameteriv_INDEXED));
    packed_data->func = glGetConvolutionParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetDoublev
void glGetDoublev(GLenum pname, GLdouble * params) {
    glGetDoublev_INDEXED *packed_data = malloc(sizeof(glGetDoublev_INDEXED));
    packed_data->func = glGetDoublev_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetError
GLenum glGetError() {
    glGetError_INDEXED *packed_data = malloc(sizeof(glGetError_INDEXED));
    packed_data->func = glGetError_INDEX;
    GLenum ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glGetFloatv
void glGetFloatv(GLenum pname, GLfloat * params) {
    glGetFloatv_INDEXED *packed_data = malloc(sizeof(glGetFloatv_INDEXED));
    packed_data->func = glGetFloatv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetHistogram
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    glGetHistogram_INDEXED *packed_data = malloc(sizeof(glGetHistogram_INDEXED));
    packed_data->func = glGetHistogram_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = reset;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetHistogramParameterfv
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetHistogramParameterfv_INDEXED *packed_data = malloc(sizeof(glGetHistogramParameterfv_INDEXED));
    packed_data->func = glGetHistogramParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetHistogramParameteriv
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetHistogramParameteriv_INDEXED *packed_data = malloc(sizeof(glGetHistogramParameteriv_INDEXED));
    packed_data->func = glGetHistogramParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetIntegerv
void glGetIntegerv(GLenum pname, GLint * params) {
    glGetIntegerv_INDEXED *packed_data = malloc(sizeof(glGetIntegerv_INDEXED));
    packed_data->func = glGetIntegerv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetLightfv
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    glGetLightfv_INDEXED *packed_data = malloc(sizeof(glGetLightfv_INDEXED));
    packed_data->func = glGetLightfv_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetLightiv
void glGetLightiv(GLenum light, GLenum pname, GLint * params) {
    glGetLightiv_INDEXED *packed_data = malloc(sizeof(glGetLightiv_INDEXED));
    packed_data->func = glGetLightiv_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetMapdv
void glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
    glGetMapdv_INDEXED *packed_data = malloc(sizeof(glGetMapdv_INDEXED));
    packed_data->func = glGetMapdv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetMapfv
void glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
    glGetMapfv_INDEXED *packed_data = malloc(sizeof(glGetMapfv_INDEXED));
    packed_data->func = glGetMapfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetMapiv
void glGetMapiv(GLenum target, GLenum query, GLint * v) {
    glGetMapiv_INDEXED *packed_data = malloc(sizeof(glGetMapiv_INDEXED));
    packed_data->func = glGetMapiv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetMaterialfv
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    glGetMaterialfv_INDEXED *packed_data = malloc(sizeof(glGetMaterialfv_INDEXED));
    packed_data->func = glGetMaterialfv_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetMaterialiv
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
    glGetMaterialiv_INDEXED *packed_data = malloc(sizeof(glGetMaterialiv_INDEXED));
    packed_data->func = glGetMaterialiv_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetMinmax
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    glGetMinmax_INDEXED *packed_data = malloc(sizeof(glGetMinmax_INDEXED));
    packed_data->func = glGetMinmax_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = reset;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetMinmaxParameterfv
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetMinmaxParameterfv_INDEXED *packed_data = malloc(sizeof(glGetMinmaxParameterfv_INDEXED));
    packed_data->func = glGetMinmaxParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetMinmaxParameteriv
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetMinmaxParameteriv_INDEXED *packed_data = malloc(sizeof(glGetMinmaxParameteriv_INDEXED));
    packed_data->func = glGetMinmaxParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetPixelMapfv
void glGetPixelMapfv(GLenum map, GLfloat * values) {
    glGetPixelMapfv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapfv_INDEXED));
    packed_data->func = glGetPixelMapfv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetPixelMapuiv
void glGetPixelMapuiv(GLenum map, GLuint * values) {
    glGetPixelMapuiv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapuiv_INDEXED));
    packed_data->func = glGetPixelMapuiv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetPixelMapusv
void glGetPixelMapusv(GLenum map, GLushort * values) {
    glGetPixelMapusv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapusv_INDEXED));
    packed_data->func = glGetPixelMapusv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetPointerv
void glGetPointerv(GLenum pname, GLvoid ** params) {
    glGetPointerv_INDEXED *packed_data = malloc(sizeof(glGetPointerv_INDEXED));
    packed_data->func = glGetPointerv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetPolygonStipple
void glGetPolygonStipple(GLubyte * mask) {
    glGetPolygonStipple_INDEXED *packed_data = malloc(sizeof(glGetPolygonStipple_INDEXED));
    packed_data->func = glGetPolygonStipple_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetQueryObjectiv
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    glGetQueryObjectiv_INDEXED *packed_data = malloc(sizeof(glGetQueryObjectiv_INDEXED));
    packed_data->func = glGetQueryObjectiv_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetQueryObjectuiv
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    glGetQueryObjectuiv_INDEXED *packed_data = malloc(sizeof(glGetQueryObjectuiv_INDEXED));
    packed_data->func = glGetQueryObjectuiv_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetQueryiv
void glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    glGetQueryiv_INDEXED *packed_data = malloc(sizeof(glGetQueryiv_INDEXED));
    packed_data->func = glGetQueryiv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetSeparableFilter
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span) {
    glGetSeparableFilter_INDEXED *packed_data = malloc(sizeof(glGetSeparableFilter_INDEXED));
    packed_data->func = glGetSeparableFilter_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = row;
    packed_data->args.a5 = column;
    packed_data->args.a6 = span;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetString
const GLubyte * glGetString(GLenum name) {
    glGetString_INDEXED *packed_data = malloc(sizeof(glGetString_INDEXED));
    packed_data->func = glGetString_INDEX;
    packed_data->args.a1 = name;
    const GLubyte * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glGetTexEnvfv
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetTexEnvfv_INDEXED *packed_data = malloc(sizeof(glGetTexEnvfv_INDEXED));
    packed_data->func = glGetTexEnvfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexEnviv
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    glGetTexEnviv_INDEXED *packed_data = malloc(sizeof(glGetTexEnviv_INDEXED));
    packed_data->func = glGetTexEnviv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexGendv
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
    glGetTexGendv_INDEXED *packed_data = malloc(sizeof(glGetTexGendv_INDEXED));
    packed_data->func = glGetTexGendv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexGenfv
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
    glGetTexGenfv_INDEXED *packed_data = malloc(sizeof(glGetTexGenfv_INDEXED));
    packed_data->func = glGetTexGenfv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexGeniv
void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
    glGetTexGeniv_INDEXED *packed_data = malloc(sizeof(glGetTexGeniv_INDEXED));
    packed_data->func = glGetTexGeniv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexImage
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels) {
    glGetTexImage_INDEXED *packed_data = malloc(sizeof(glGetTexImage_INDEXED));
    packed_data->func = glGetTexImage_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexLevelParameterfv
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    glGetTexLevelParameterfv_INDEXED *packed_data = malloc(sizeof(glGetTexLevelParameterfv_INDEXED));
    packed_data->func = glGetTexLevelParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexLevelParameteriv
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    glGetTexLevelParameteriv_INDEXED *packed_data = malloc(sizeof(glGetTexLevelParameteriv_INDEXED));
    packed_data->func = glGetTexLevelParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexParameterfv
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetTexParameterfv_INDEXED *packed_data = malloc(sizeof(glGetTexParameterfv_INDEXED));
    packed_data->func = glGetTexParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glGetTexParameteriv
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetTexParameteriv_INDEXED *packed_data = malloc(sizeof(glGetTexParameteriv_INDEXED));
    packed_data->func = glGetTexParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glHint
void glHint(GLenum target, GLenum mode) {
    glHint_INDEXED *packed_data = malloc(sizeof(glHint_INDEXED));
    packed_data->func = glHint_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glHistogram
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    glHistogram_INDEXED *packed_data = malloc(sizeof(glHistogram_INDEXED));
    packed_data->func = glHistogram_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = width;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = sink;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexMask
void glIndexMask(GLuint mask) {
    glIndexMask_INDEXED *packed_data = malloc(sizeof(glIndexMask_INDEXED));
    packed_data->func = glIndexMask_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexPointer
void glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glIndexPointer_INDEXED *packed_data = malloc(sizeof(glIndexPointer_INDEXED));
    packed_data->func = glIndexPointer_INDEX;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexd
void glIndexd(GLdouble c) {
    glIndexd_INDEXED *packed_data = malloc(sizeof(glIndexd_INDEXED));
    packed_data->func = glIndexd_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexdv
void glIndexdv(const GLdouble * c) {
    glIndexdv_INDEXED *packed_data = malloc(sizeof(glIndexdv_INDEXED));
    packed_data->func = glIndexdv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexf
void glIndexf(GLfloat c) {
    glIndexf_INDEXED *packed_data = malloc(sizeof(glIndexf_INDEXED));
    packed_data->func = glIndexf_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexfv
void glIndexfv(const GLfloat * c) {
    glIndexfv_INDEXED *packed_data = malloc(sizeof(glIndexfv_INDEXED));
    packed_data->func = glIndexfv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexi
void glIndexi(GLint c) {
    glIndexi_INDEXED *packed_data = malloc(sizeof(glIndexi_INDEXED));
    packed_data->func = glIndexi_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexiv
void glIndexiv(const GLint * c) {
    glIndexiv_INDEXED *packed_data = malloc(sizeof(glIndexiv_INDEXED));
    packed_data->func = glIndexiv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexs
void glIndexs(GLshort c) {
    glIndexs_INDEXED *packed_data = malloc(sizeof(glIndexs_INDEXED));
    packed_data->func = glIndexs_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexsv
void glIndexsv(const GLshort * c) {
    glIndexsv_INDEXED *packed_data = malloc(sizeof(glIndexsv_INDEXED));
    packed_data->func = glIndexsv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexub
void glIndexub(GLubyte c) {
    glIndexub_INDEXED *packed_data = malloc(sizeof(glIndexub_INDEXED));
    packed_data->func = glIndexub_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIndexubv
void glIndexubv(const GLubyte * c) {
    glIndexubv_INDEXED *packed_data = malloc(sizeof(glIndexubv_INDEXED));
    packed_data->func = glIndexubv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glInitNames
void glInitNames() {
    glInitNames_INDEXED *packed_data = malloc(sizeof(glInitNames_INDEXED));
    packed_data->func = glInitNames_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glInterleavedArrays
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid * pointer) {
    glInterleavedArrays_INDEXED *packed_data = malloc(sizeof(glInterleavedArrays_INDEXED));
    packed_data->func = glInterleavedArrays_INDEX;
    packed_data->args.a1 = format;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glIsBuffer
GLboolean glIsBuffer(GLuint buffer) {
    glIsBuffer_INDEXED *packed_data = malloc(sizeof(glIsBuffer_INDEXED));
    packed_data->func = glIsBuffer_INDEX;
    packed_data->args.a1 = buffer;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glIsEnabled
GLboolean glIsEnabled(GLenum cap) {
    glIsEnabled_INDEXED *packed_data = malloc(sizeof(glIsEnabled_INDEXED));
    packed_data->func = glIsEnabled_INDEX;
    packed_data->args.a1 = cap;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glIsList
GLboolean glIsList(GLuint list) {
    glIsList_INDEXED *packed_data = malloc(sizeof(glIsList_INDEXED));
    packed_data->func = glIsList_INDEX;
    packed_data->args.a1 = list;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glIsQuery
GLboolean glIsQuery(GLuint id) {
    glIsQuery_INDEXED *packed_data = malloc(sizeof(glIsQuery_INDEXED));
    packed_data->func = glIsQuery_INDEX;
    packed_data->args.a1 = id;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glIsTexture
GLboolean glIsTexture(GLuint texture) {
    glIsTexture_INDEXED *packed_data = malloc(sizeof(glIsTexture_INDEXED));
    packed_data->func = glIsTexture_INDEX;
    packed_data->args.a1 = texture;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glLightModelf
void glLightModelf(GLenum pname, GLfloat param) {
    glLightModelf_INDEXED *packed_data = malloc(sizeof(glLightModelf_INDEXED));
    packed_data->func = glLightModelf_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLightModelfv
void glLightModelfv(GLenum pname, const GLfloat * params) {
    glLightModelfv_INDEXED *packed_data = malloc(sizeof(glLightModelfv_INDEXED));
    packed_data->func = glLightModelfv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLightModeli
void glLightModeli(GLenum pname, GLint param) {
    glLightModeli_INDEXED *packed_data = malloc(sizeof(glLightModeli_INDEXED));
    packed_data->func = glLightModeli_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLightModeliv
void glLightModeliv(GLenum pname, const GLint * params) {
    glLightModeliv_INDEXED *packed_data = malloc(sizeof(glLightModeliv_INDEXED));
    packed_data->func = glLightModeliv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLightf
void glLightf(GLenum light, GLenum pname, GLfloat param) {
    glLightf_INDEXED *packed_data = malloc(sizeof(glLightf_INDEXED));
    packed_data->func = glLightf_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLightfv
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    glLightfv_INDEXED *packed_data = malloc(sizeof(glLightfv_INDEXED));
    packed_data->func = glLightfv_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLighti
void glLighti(GLenum light, GLenum pname, GLint param) {
    glLighti_INDEXED *packed_data = malloc(sizeof(glLighti_INDEXED));
    packed_data->func = glLighti_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLightiv
void glLightiv(GLenum light, GLenum pname, const GLint * params) {
    glLightiv_INDEXED *packed_data = malloc(sizeof(glLightiv_INDEXED));
    packed_data->func = glLightiv_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLineStipple
void glLineStipple(GLint factor, GLushort pattern) {
    glLineStipple_INDEXED *packed_data = malloc(sizeof(glLineStipple_INDEXED));
    packed_data->func = glLineStipple_INDEX;
    packed_data->args.a1 = factor;
    packed_data->args.a2 = pattern;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLineWidth
void glLineWidth(GLfloat width) {
    glLineWidth_INDEXED *packed_data = malloc(sizeof(glLineWidth_INDEXED));
    packed_data->func = glLineWidth_INDEX;
    packed_data->args.a1 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glListBase
void glListBase(GLuint base) {
    glListBase_INDEXED *packed_data = malloc(sizeof(glListBase_INDEXED));
    packed_data->func = glListBase_INDEX;
    packed_data->args.a1 = base;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLoadIdentity
void glLoadIdentity() {
    glLoadIdentity_INDEXED *packed_data = malloc(sizeof(glLoadIdentity_INDEXED));
    packed_data->func = glLoadIdentity_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLoadMatrixd
void glLoadMatrixd(const GLdouble * m) {
    glLoadMatrixd_INDEXED *packed_data = malloc(sizeof(glLoadMatrixd_INDEXED));
    packed_data->func = glLoadMatrixd_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLoadMatrixf
void glLoadMatrixf(const GLfloat * m) {
    glLoadMatrixf_INDEXED *packed_data = malloc(sizeof(glLoadMatrixf_INDEXED));
    packed_data->func = glLoadMatrixf_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLoadName
void glLoadName(GLuint name) {
    glLoadName_INDEXED *packed_data = malloc(sizeof(glLoadName_INDEXED));
    packed_data->func = glLoadName_INDEX;
    packed_data->args.a1 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLoadTransposeMatrixd
void glLoadTransposeMatrixd(const GLdouble * m) {
    glLoadTransposeMatrixd_INDEXED *packed_data = malloc(sizeof(glLoadTransposeMatrixd_INDEXED));
    packed_data->func = glLoadTransposeMatrixd_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLoadTransposeMatrixf
void glLoadTransposeMatrixf(const GLfloat * m) {
    glLoadTransposeMatrixf_INDEXED *packed_data = malloc(sizeof(glLoadTransposeMatrixf_INDEXED));
    packed_data->func = glLoadTransposeMatrixf_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glLogicOp
void glLogicOp(GLenum opcode) {
    glLogicOp_INDEXED *packed_data = malloc(sizeof(glLogicOp_INDEXED));
    packed_data->func = glLogicOp_INDEX;
    packed_data->args.a1 = opcode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMap1d
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points) {
    glMap1d_INDEXED *packed_data = malloc(sizeof(glMap1d_INDEXED));
    packed_data->func = glMap1d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = stride;
    packed_data->args.a5 = order;
    packed_data->args.a6 = points;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMap1f
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points) {
    glMap1f_INDEXED *packed_data = malloc(sizeof(glMap1f_INDEXED));
    packed_data->func = glMap1f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = stride;
    packed_data->args.a5 = order;
    packed_data->args.a6 = points;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMap2d
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points) {
    glMap2d_INDEXED *packed_data = malloc(sizeof(glMap2d_INDEXED));
    packed_data->func = glMap2d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = ustride;
    packed_data->args.a5 = uorder;
    packed_data->args.a6 = v1;
    packed_data->args.a7 = v2;
    packed_data->args.a8 = vstride;
    packed_data->args.a9 = vorder;
    packed_data->args.a10 = points;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMap2f
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points) {
    glMap2f_INDEXED *packed_data = malloc(sizeof(glMap2f_INDEXED));
    packed_data->func = glMap2f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = ustride;
    packed_data->args.a5 = uorder;
    packed_data->args.a6 = v1;
    packed_data->args.a7 = v2;
    packed_data->args.a8 = vstride;
    packed_data->args.a9 = vorder;
    packed_data->args.a10 = points;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMapBuffer
GLvoid * glMapBuffer(GLenum target, GLenum access) {
    glMapBuffer_INDEXED *packed_data = malloc(sizeof(glMapBuffer_INDEXED));
    packed_data->func = glMapBuffer_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = access;
    GLvoid * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glMapGrid1d
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    glMapGrid1d_INDEXED *packed_data = malloc(sizeof(glMapGrid1d_INDEXED));
    packed_data->func = glMapGrid1d_INDEX;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMapGrid1f
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    glMapGrid1f_INDEXED *packed_data = malloc(sizeof(glMapGrid1f_INDEXED));
    packed_data->func = glMapGrid1f_INDEX;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMapGrid2d
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
    glMapGrid2d_INDEXED *packed_data = malloc(sizeof(glMapGrid2d_INDEXED));
    packed_data->func = glMapGrid2d_INDEX;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = vn;
    packed_data->args.a5 = v1;
    packed_data->args.a6 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMapGrid2f
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
    glMapGrid2f_INDEXED *packed_data = malloc(sizeof(glMapGrid2f_INDEXED));
    packed_data->func = glMapGrid2f_INDEX;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = vn;
    packed_data->args.a5 = v1;
    packed_data->args.a6 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMaterialf
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    glMaterialf_INDEXED *packed_data = malloc(sizeof(glMaterialf_INDEXED));
    packed_data->func = glMaterialf_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMaterialfv
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    glMaterialfv_INDEXED *packed_data = malloc(sizeof(glMaterialfv_INDEXED));
    packed_data->func = glMaterialfv_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMateriali
void glMateriali(GLenum face, GLenum pname, GLint param) {
    glMateriali_INDEXED *packed_data = malloc(sizeof(glMateriali_INDEXED));
    packed_data->func = glMateriali_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMaterialiv
void glMaterialiv(GLenum face, GLenum pname, const GLint * params) {
    glMaterialiv_INDEXED *packed_data = malloc(sizeof(glMaterialiv_INDEXED));
    packed_data->func = glMaterialiv_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMatrixMode
void glMatrixMode(GLenum mode) {
    glMatrixMode_INDEXED *packed_data = malloc(sizeof(glMatrixMode_INDEXED));
    packed_data->func = glMatrixMode_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMinmax
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
    glMinmax_INDEXED *packed_data = malloc(sizeof(glMinmax_INDEXED));
    packed_data->func = glMinmax_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = sink;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultMatrixd
void glMultMatrixd(const GLdouble * m) {
    glMultMatrixd_INDEXED *packed_data = malloc(sizeof(glMultMatrixd_INDEXED));
    packed_data->func = glMultMatrixd_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultMatrixf
void glMultMatrixf(const GLfloat * m) {
    glMultMatrixf_INDEXED *packed_data = malloc(sizeof(glMultMatrixf_INDEXED));
    packed_data->func = glMultMatrixf_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultTransposeMatrixd
void glMultTransposeMatrixd(const GLdouble * m) {
    glMultTransposeMatrixd_INDEXED *packed_data = malloc(sizeof(glMultTransposeMatrixd_INDEXED));
    packed_data->func = glMultTransposeMatrixd_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultTransposeMatrixf
void glMultTransposeMatrixf(const GLfloat * m) {
    glMultTransposeMatrixf_INDEXED *packed_data = malloc(sizeof(glMultTransposeMatrixf_INDEXED));
    packed_data->func = glMultTransposeMatrixf_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiDrawArrays
void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    glMultiDrawArrays_INDEXED *packed_data = malloc(sizeof(glMultiDrawArrays_INDEXED));
    packed_data->func = glMultiDrawArrays_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    packed_data->args.a4 = drawcount;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiDrawElements
void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, GLvoid*const * indices, GLsizei drawcount) {
    glMultiDrawElements_INDEXED *packed_data = malloc(sizeof(glMultiDrawElements_INDEXED));
    packed_data->func = glMultiDrawElements_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = count;
    packed_data->args.a3 = type;
    packed_data->args.a4 = indices;
    packed_data->args.a5 = drawcount;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord1d
void glMultiTexCoord1d(GLenum target, GLdouble s) {
    glMultiTexCoord1d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1d_INDEXED));
    packed_data->func = glMultiTexCoord1d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord1dv
void glMultiTexCoord1dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord1dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1dv_INDEXED));
    packed_data->func = glMultiTexCoord1dv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord1f
void glMultiTexCoord1f(GLenum target, GLfloat s) {
    glMultiTexCoord1f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1f_INDEXED));
    packed_data->func = glMultiTexCoord1f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord1fv
void glMultiTexCoord1fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord1fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1fv_INDEXED));
    packed_data->func = glMultiTexCoord1fv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord1i
void glMultiTexCoord1i(GLenum target, GLint s) {
    glMultiTexCoord1i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1i_INDEXED));
    packed_data->func = glMultiTexCoord1i_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord1iv
void glMultiTexCoord1iv(GLenum target, const GLint * v) {
    glMultiTexCoord1iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1iv_INDEXED));
    packed_data->func = glMultiTexCoord1iv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord1s
void glMultiTexCoord1s(GLenum target, GLshort s) {
    glMultiTexCoord1s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1s_INDEXED));
    packed_data->func = glMultiTexCoord1s_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord1sv
void glMultiTexCoord1sv(GLenum target, const GLshort * v) {
    glMultiTexCoord1sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1sv_INDEXED));
    packed_data->func = glMultiTexCoord1sv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord2d
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    glMultiTexCoord2d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2d_INDEXED));
    packed_data->func = glMultiTexCoord2d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord2dv
void glMultiTexCoord2dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord2dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2dv_INDEXED));
    packed_data->func = glMultiTexCoord2dv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord2f
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    glMultiTexCoord2f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2f_INDEXED));
    packed_data->func = glMultiTexCoord2f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord2fv
void glMultiTexCoord2fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord2fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2fv_INDEXED));
    packed_data->func = glMultiTexCoord2fv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord2i
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
    glMultiTexCoord2i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2i_INDEXED));
    packed_data->func = glMultiTexCoord2i_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord2iv
void glMultiTexCoord2iv(GLenum target, const GLint * v) {
    glMultiTexCoord2iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2iv_INDEXED));
    packed_data->func = glMultiTexCoord2iv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord2s
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    glMultiTexCoord2s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2s_INDEXED));
    packed_data->func = glMultiTexCoord2s_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord2sv
void glMultiTexCoord2sv(GLenum target, const GLshort * v) {
    glMultiTexCoord2sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2sv_INDEXED));
    packed_data->func = glMultiTexCoord2sv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord3d
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    glMultiTexCoord3d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3d_INDEXED));
    packed_data->func = glMultiTexCoord3d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord3dv
void glMultiTexCoord3dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord3dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3dv_INDEXED));
    packed_data->func = glMultiTexCoord3dv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord3f
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    glMultiTexCoord3f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3f_INDEXED));
    packed_data->func = glMultiTexCoord3f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord3fv
void glMultiTexCoord3fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord3fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3fv_INDEXED));
    packed_data->func = glMultiTexCoord3fv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord3i
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    glMultiTexCoord3i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3i_INDEXED));
    packed_data->func = glMultiTexCoord3i_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord3iv
void glMultiTexCoord3iv(GLenum target, const GLint * v) {
    glMultiTexCoord3iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3iv_INDEXED));
    packed_data->func = glMultiTexCoord3iv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord3s
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    glMultiTexCoord3s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3s_INDEXED));
    packed_data->func = glMultiTexCoord3s_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord3sv
void glMultiTexCoord3sv(GLenum target, const GLshort * v) {
    glMultiTexCoord3sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3sv_INDEXED));
    packed_data->func = glMultiTexCoord3sv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord4d
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    glMultiTexCoord4d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4d_INDEXED));
    packed_data->func = glMultiTexCoord4d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord4dv
void glMultiTexCoord4dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord4dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4dv_INDEXED));
    packed_data->func = glMultiTexCoord4dv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord4f
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    glMultiTexCoord4f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4f_INDEXED));
    packed_data->func = glMultiTexCoord4f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord4fv
void glMultiTexCoord4fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord4fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4fv_INDEXED));
    packed_data->func = glMultiTexCoord4fv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord4i
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    glMultiTexCoord4i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4i_INDEXED));
    packed_data->func = glMultiTexCoord4i_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord4iv
void glMultiTexCoord4iv(GLenum target, const GLint * v) {
    glMultiTexCoord4iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4iv_INDEXED));
    packed_data->func = glMultiTexCoord4iv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord4s
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    glMultiTexCoord4s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4s_INDEXED));
    packed_data->func = glMultiTexCoord4s_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glMultiTexCoord4sv
void glMultiTexCoord4sv(GLenum target, const GLshort * v) {
    glMultiTexCoord4sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4sv_INDEXED));
    packed_data->func = glMultiTexCoord4sv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNewList
void glNewList(GLuint list, GLenum mode) {
    glNewList_INDEXED *packed_data = malloc(sizeof(glNewList_INDEXED));
    packed_data->func = glNewList_INDEX;
    packed_data->args.a1 = list;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3b
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    glNormal3b_INDEXED *packed_data = malloc(sizeof(glNormal3b_INDEXED));
    packed_data->func = glNormal3b_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3bv
void glNormal3bv(const GLbyte * v) {
    glNormal3bv_INDEXED *packed_data = malloc(sizeof(glNormal3bv_INDEXED));
    packed_data->func = glNormal3bv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3d
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    glNormal3d_INDEXED *packed_data = malloc(sizeof(glNormal3d_INDEXED));
    packed_data->func = glNormal3d_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3dv
void glNormal3dv(const GLdouble * v) {
    glNormal3dv_INDEXED *packed_data = malloc(sizeof(glNormal3dv_INDEXED));
    packed_data->func = glNormal3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3f
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    glNormal3f_INDEXED *packed_data = malloc(sizeof(glNormal3f_INDEXED));
    packed_data->func = glNormal3f_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3fv
void glNormal3fv(const GLfloat * v) {
    glNormal3fv_INDEXED *packed_data = malloc(sizeof(glNormal3fv_INDEXED));
    packed_data->func = glNormal3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3i
void glNormal3i(GLint nx, GLint ny, GLint nz) {
    glNormal3i_INDEXED *packed_data = malloc(sizeof(glNormal3i_INDEXED));
    packed_data->func = glNormal3i_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3iv
void glNormal3iv(const GLint * v) {
    glNormal3iv_INDEXED *packed_data = malloc(sizeof(glNormal3iv_INDEXED));
    packed_data->func = glNormal3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3s
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
    glNormal3s_INDEXED *packed_data = malloc(sizeof(glNormal3s_INDEXED));
    packed_data->func = glNormal3s_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormal3sv
void glNormal3sv(const GLshort * v) {
    glNormal3sv_INDEXED *packed_data = malloc(sizeof(glNormal3sv_INDEXED));
    packed_data->func = glNormal3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glNormalPointer
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glNormalPointer_INDEXED *packed_data = malloc(sizeof(glNormalPointer_INDEXED));
    packed_data->func = glNormalPointer_INDEX;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glOrtho
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    glOrtho_INDEXED *packed_data = malloc(sizeof(glOrtho_INDEXED));
    packed_data->func = glOrtho_INDEX;
    packed_data->args.a1 = left;
    packed_data->args.a2 = right;
    packed_data->args.a3 = bottom;
    packed_data->args.a4 = top;
    packed_data->args.a5 = zNear;
    packed_data->args.a6 = zFar;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPassThrough
void glPassThrough(GLfloat token) {
    glPassThrough_INDEXED *packed_data = malloc(sizeof(glPassThrough_INDEXED));
    packed_data->func = glPassThrough_INDEX;
    packed_data->args.a1 = token;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPixelMapfv
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values) {
    glPixelMapfv_INDEXED *packed_data = malloc(sizeof(glPixelMapfv_INDEXED));
    packed_data->func = glPixelMapfv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPixelMapuiv
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values) {
    glPixelMapuiv_INDEXED *packed_data = malloc(sizeof(glPixelMapuiv_INDEXED));
    packed_data->func = glPixelMapuiv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPixelMapusv
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values) {
    glPixelMapusv_INDEXED *packed_data = malloc(sizeof(glPixelMapusv_INDEXED));
    packed_data->func = glPixelMapusv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPixelStoref
void glPixelStoref(GLenum pname, GLfloat param) {
    glPixelStoref_INDEXED *packed_data = malloc(sizeof(glPixelStoref_INDEXED));
    packed_data->func = glPixelStoref_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPixelStorei
void glPixelStorei(GLenum pname, GLint param) {
    glPixelStorei_INDEXED *packed_data = malloc(sizeof(glPixelStorei_INDEXED));
    packed_data->func = glPixelStorei_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPixelTransferf
void glPixelTransferf(GLenum pname, GLfloat param) {
    glPixelTransferf_INDEXED *packed_data = malloc(sizeof(glPixelTransferf_INDEXED));
    packed_data->func = glPixelTransferf_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPixelTransferi
void glPixelTransferi(GLenum pname, GLint param) {
    glPixelTransferi_INDEXED *packed_data = malloc(sizeof(glPixelTransferi_INDEXED));
    packed_data->func = glPixelTransferi_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPixelZoom
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    glPixelZoom_INDEXED *packed_data = malloc(sizeof(glPixelZoom_INDEXED));
    packed_data->func = glPixelZoom_INDEX;
    packed_data->args.a1 = xfactor;
    packed_data->args.a2 = yfactor;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPointParameterf
void glPointParameterf(GLenum pname, GLfloat param) {
    glPointParameterf_INDEXED *packed_data = malloc(sizeof(glPointParameterf_INDEXED));
    packed_data->func = glPointParameterf_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPointParameterfv
void glPointParameterfv(GLenum pname, const GLfloat * params) {
    glPointParameterfv_INDEXED *packed_data = malloc(sizeof(glPointParameterfv_INDEXED));
    packed_data->func = glPointParameterfv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPointParameteri
void glPointParameteri(GLenum pname, GLint param) {
    glPointParameteri_INDEXED *packed_data = malloc(sizeof(glPointParameteri_INDEXED));
    packed_data->func = glPointParameteri_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPointParameteriv
void glPointParameteriv(GLenum pname, const GLint * params) {
    glPointParameteriv_INDEXED *packed_data = malloc(sizeof(glPointParameteriv_INDEXED));
    packed_data->func = glPointParameteriv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPointSize
void glPointSize(GLfloat size) {
    glPointSize_INDEXED *packed_data = malloc(sizeof(glPointSize_INDEXED));
    packed_data->func = glPointSize_INDEX;
    packed_data->args.a1 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPolygonMode
void glPolygonMode(GLenum face, GLenum mode) {
    glPolygonMode_INDEXED *packed_data = malloc(sizeof(glPolygonMode_INDEXED));
    packed_data->func = glPolygonMode_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPolygonOffset
void glPolygonOffset(GLfloat factor, GLfloat units) {
    glPolygonOffset_INDEXED *packed_data = malloc(sizeof(glPolygonOffset_INDEXED));
    packed_data->func = glPolygonOffset_INDEX;
    packed_data->args.a1 = factor;
    packed_data->args.a2 = units;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPolygonStipple
void glPolygonStipple(const GLubyte * mask) {
    glPolygonStipple_INDEXED *packed_data = malloc(sizeof(glPolygonStipple_INDEXED));
    packed_data->func = glPolygonStipple_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPopAttrib
void glPopAttrib() {
    glPopAttrib_INDEXED *packed_data = malloc(sizeof(glPopAttrib_INDEXED));
    packed_data->func = glPopAttrib_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPopClientAttrib
void glPopClientAttrib() {
    glPopClientAttrib_INDEXED *packed_data = malloc(sizeof(glPopClientAttrib_INDEXED));
    packed_data->func = glPopClientAttrib_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPopMatrix
void glPopMatrix() {
    glPopMatrix_INDEXED *packed_data = malloc(sizeof(glPopMatrix_INDEXED));
    packed_data->func = glPopMatrix_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPopName
void glPopName() {
    glPopName_INDEXED *packed_data = malloc(sizeof(glPopName_INDEXED));
    packed_data->func = glPopName_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPrioritizeTextures
void glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities) {
    glPrioritizeTextures_INDEXED *packed_data = malloc(sizeof(glPrioritizeTextures_INDEXED));
    packed_data->func = glPrioritizeTextures_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    packed_data->args.a3 = priorities;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPushAttrib
void glPushAttrib(GLbitfield mask) {
    glPushAttrib_INDEXED *packed_data = malloc(sizeof(glPushAttrib_INDEXED));
    packed_data->func = glPushAttrib_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPushClientAttrib
void glPushClientAttrib(GLbitfield mask) {
    glPushClientAttrib_INDEXED *packed_data = malloc(sizeof(glPushClientAttrib_INDEXED));
    packed_data->func = glPushClientAttrib_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPushMatrix
void glPushMatrix() {
    glPushMatrix_INDEXED *packed_data = malloc(sizeof(glPushMatrix_INDEXED));
    packed_data->func = glPushMatrix_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glPushName
void glPushName(GLuint name) {
    glPushName_INDEXED *packed_data = malloc(sizeof(glPushName_INDEXED));
    packed_data->func = glPushName_INDEX;
    packed_data->args.a1 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos2d
void glRasterPos2d(GLdouble x, GLdouble y) {
    glRasterPos2d_INDEXED *packed_data = malloc(sizeof(glRasterPos2d_INDEXED));
    packed_data->func = glRasterPos2d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos2dv
void glRasterPos2dv(const GLdouble * v) {
    glRasterPos2dv_INDEXED *packed_data = malloc(sizeof(glRasterPos2dv_INDEXED));
    packed_data->func = glRasterPos2dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos2f
void glRasterPos2f(GLfloat x, GLfloat y) {
    glRasterPos2f_INDEXED *packed_data = malloc(sizeof(glRasterPos2f_INDEXED));
    packed_data->func = glRasterPos2f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos2fv
void glRasterPos2fv(const GLfloat * v) {
    glRasterPos2fv_INDEXED *packed_data = malloc(sizeof(glRasterPos2fv_INDEXED));
    packed_data->func = glRasterPos2fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos2i
void glRasterPos2i(GLint x, GLint y) {
    glRasterPos2i_INDEXED *packed_data = malloc(sizeof(glRasterPos2i_INDEXED));
    packed_data->func = glRasterPos2i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos2iv
void glRasterPos2iv(const GLint * v) {
    glRasterPos2iv_INDEXED *packed_data = malloc(sizeof(glRasterPos2iv_INDEXED));
    packed_data->func = glRasterPos2iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos2s
void glRasterPos2s(GLshort x, GLshort y) {
    glRasterPos2s_INDEXED *packed_data = malloc(sizeof(glRasterPos2s_INDEXED));
    packed_data->func = glRasterPos2s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos2sv
void glRasterPos2sv(const GLshort * v) {
    glRasterPos2sv_INDEXED *packed_data = malloc(sizeof(glRasterPos2sv_INDEXED));
    packed_data->func = glRasterPos2sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos3d
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    glRasterPos3d_INDEXED *packed_data = malloc(sizeof(glRasterPos3d_INDEXED));
    packed_data->func = glRasterPos3d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos3dv
void glRasterPos3dv(const GLdouble * v) {
    glRasterPos3dv_INDEXED *packed_data = malloc(sizeof(glRasterPos3dv_INDEXED));
    packed_data->func = glRasterPos3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos3f
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    glRasterPos3f_INDEXED *packed_data = malloc(sizeof(glRasterPos3f_INDEXED));
    packed_data->func = glRasterPos3f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos3fv
void glRasterPos3fv(const GLfloat * v) {
    glRasterPos3fv_INDEXED *packed_data = malloc(sizeof(glRasterPos3fv_INDEXED));
    packed_data->func = glRasterPos3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos3i
void glRasterPos3i(GLint x, GLint y, GLint z) {
    glRasterPos3i_INDEXED *packed_data = malloc(sizeof(glRasterPos3i_INDEXED));
    packed_data->func = glRasterPos3i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos3iv
void glRasterPos3iv(const GLint * v) {
    glRasterPos3iv_INDEXED *packed_data = malloc(sizeof(glRasterPos3iv_INDEXED));
    packed_data->func = glRasterPos3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos3s
void glRasterPos3s(GLshort x, GLshort y, GLshort z) {
    glRasterPos3s_INDEXED *packed_data = malloc(sizeof(glRasterPos3s_INDEXED));
    packed_data->func = glRasterPos3s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos3sv
void glRasterPos3sv(const GLshort * v) {
    glRasterPos3sv_INDEXED *packed_data = malloc(sizeof(glRasterPos3sv_INDEXED));
    packed_data->func = glRasterPos3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos4d
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glRasterPos4d_INDEXED *packed_data = malloc(sizeof(glRasterPos4d_INDEXED));
    packed_data->func = glRasterPos4d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos4dv
void glRasterPos4dv(const GLdouble * v) {
    glRasterPos4dv_INDEXED *packed_data = malloc(sizeof(glRasterPos4dv_INDEXED));
    packed_data->func = glRasterPos4dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos4f
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glRasterPos4f_INDEXED *packed_data = malloc(sizeof(glRasterPos4f_INDEXED));
    packed_data->func = glRasterPos4f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos4fv
void glRasterPos4fv(const GLfloat * v) {
    glRasterPos4fv_INDEXED *packed_data = malloc(sizeof(glRasterPos4fv_INDEXED));
    packed_data->func = glRasterPos4fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos4i
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    glRasterPos4i_INDEXED *packed_data = malloc(sizeof(glRasterPos4i_INDEXED));
    packed_data->func = glRasterPos4i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos4iv
void glRasterPos4iv(const GLint * v) {
    glRasterPos4iv_INDEXED *packed_data = malloc(sizeof(glRasterPos4iv_INDEXED));
    packed_data->func = glRasterPos4iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos4s
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    glRasterPos4s_INDEXED *packed_data = malloc(sizeof(glRasterPos4s_INDEXED));
    packed_data->func = glRasterPos4s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRasterPos4sv
void glRasterPos4sv(const GLshort * v) {
    glRasterPos4sv_INDEXED *packed_data = malloc(sizeof(glRasterPos4sv_INDEXED));
    packed_data->func = glRasterPos4sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glReadBuffer
void glReadBuffer(GLenum mode) {
    glReadBuffer_INDEXED *packed_data = malloc(sizeof(glReadBuffer_INDEXED));
    packed_data->func = glReadBuffer_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glReadPixels
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    glReadPixels_INDEXED *packed_data = malloc(sizeof(glReadPixels_INDEXED));
    packed_data->func = glReadPixels_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = format;
    packed_data->args.a6 = type;
    packed_data->args.a7 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRectd
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    glRectd_INDEXED *packed_data = malloc(sizeof(glRectd_INDEXED));
    packed_data->func = glRectd_INDEX;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRectdv
void glRectdv(const GLdouble * v1, const GLdouble * v2) {
    glRectdv_INDEXED *packed_data = malloc(sizeof(glRectdv_INDEXED));
    packed_data->func = glRectdv_INDEX;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRectf
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glRectf_INDEXED *packed_data = malloc(sizeof(glRectf_INDEXED));
    packed_data->func = glRectf_INDEX;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRectfv
void glRectfv(const GLfloat * v1, const GLfloat * v2) {
    glRectfv_INDEXED *packed_data = malloc(sizeof(glRectfv_INDEXED));
    packed_data->func = glRectfv_INDEX;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRecti
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
    glRecti_INDEXED *packed_data = malloc(sizeof(glRecti_INDEXED));
    packed_data->func = glRecti_INDEX;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRectiv
void glRectiv(const GLint * v1, const GLint * v2) {
    glRectiv_INDEXED *packed_data = malloc(sizeof(glRectiv_INDEXED));
    packed_data->func = glRectiv_INDEX;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRects
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    glRects_INDEXED *packed_data = malloc(sizeof(glRects_INDEXED));
    packed_data->func = glRects_INDEX;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRectsv
void glRectsv(const GLshort * v1, const GLshort * v2) {
    glRectsv_INDEXED *packed_data = malloc(sizeof(glRectsv_INDEXED));
    packed_data->func = glRectsv_INDEX;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRenderMode
GLint glRenderMode(GLenum mode) {
    glRenderMode_INDEXED *packed_data = malloc(sizeof(glRenderMode_INDEXED));
    packed_data->func = glRenderMode_INDEX;
    packed_data->args.a1 = mode;
    GLint ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glResetHistogram
void glResetHistogram(GLenum target) {
    glResetHistogram_INDEXED *packed_data = malloc(sizeof(glResetHistogram_INDEXED));
    packed_data->func = glResetHistogram_INDEX;
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glResetMinmax
void glResetMinmax(GLenum target) {
    glResetMinmax_INDEXED *packed_data = malloc(sizeof(glResetMinmax_INDEXED));
    packed_data->func = glResetMinmax_INDEX;
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRotated
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    glRotated_INDEXED *packed_data = malloc(sizeof(glRotated_INDEXED));
    packed_data->func = glRotated_INDEX;
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glRotatef
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    glRotatef_INDEXED *packed_data = malloc(sizeof(glRotatef_INDEXED));
    packed_data->func = glRotatef_INDEX;
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSampleCoverage
void glSampleCoverage(GLfloat value, GLboolean invert) {
    glSampleCoverage_INDEXED *packed_data = malloc(sizeof(glSampleCoverage_INDEXED));
    packed_data->func = glSampleCoverage_INDEX;
    packed_data->args.a1 = value;
    packed_data->args.a2 = invert;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glScaled
void glScaled(GLdouble x, GLdouble y, GLdouble z) {
    glScaled_INDEXED *packed_data = malloc(sizeof(glScaled_INDEXED));
    packed_data->func = glScaled_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glScalef
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
    glScalef_INDEXED *packed_data = malloc(sizeof(glScalef_INDEXED));
    packed_data->func = glScalef_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glScissor
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    glScissor_INDEXED *packed_data = malloc(sizeof(glScissor_INDEXED));
    packed_data->func = glScissor_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3b
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    glSecondaryColor3b_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3b_INDEXED));
    packed_data->func = glSecondaryColor3b_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3bv
void glSecondaryColor3bv(const GLbyte * v) {
    glSecondaryColor3bv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3bv_INDEXED));
    packed_data->func = glSecondaryColor3bv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3d
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    glSecondaryColor3d_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3d_INDEXED));
    packed_data->func = glSecondaryColor3d_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3dv
void glSecondaryColor3dv(const GLdouble * v) {
    glSecondaryColor3dv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3dv_INDEXED));
    packed_data->func = glSecondaryColor3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3f
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    glSecondaryColor3f_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3f_INDEXED));
    packed_data->func = glSecondaryColor3f_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3fv
void glSecondaryColor3fv(const GLfloat * v) {
    glSecondaryColor3fv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3fv_INDEXED));
    packed_data->func = glSecondaryColor3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3i
void glSecondaryColor3i(GLint red, GLint green, GLint blue) {
    glSecondaryColor3i_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3i_INDEXED));
    packed_data->func = glSecondaryColor3i_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3iv
void glSecondaryColor3iv(const GLint * v) {
    glSecondaryColor3iv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3iv_INDEXED));
    packed_data->func = glSecondaryColor3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3s
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    glSecondaryColor3s_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3s_INDEXED));
    packed_data->func = glSecondaryColor3s_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3sv
void glSecondaryColor3sv(const GLshort * v) {
    glSecondaryColor3sv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3sv_INDEXED));
    packed_data->func = glSecondaryColor3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3ub
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    glSecondaryColor3ub_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ub_INDEXED));
    packed_data->func = glSecondaryColor3ub_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3ubv
void glSecondaryColor3ubv(const GLubyte * v) {
    glSecondaryColor3ubv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ubv_INDEXED));
    packed_data->func = glSecondaryColor3ubv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3ui
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    glSecondaryColor3ui_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ui_INDEXED));
    packed_data->func = glSecondaryColor3ui_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3uiv
void glSecondaryColor3uiv(const GLuint * v) {
    glSecondaryColor3uiv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3uiv_INDEXED));
    packed_data->func = glSecondaryColor3uiv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3us
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    glSecondaryColor3us_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3us_INDEXED));
    packed_data->func = glSecondaryColor3us_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColor3usv
void glSecondaryColor3usv(const GLushort * v) {
    glSecondaryColor3usv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3usv_INDEXED));
    packed_data->func = glSecondaryColor3usv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSecondaryColorPointer
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glSecondaryColorPointer_INDEXED *packed_data = malloc(sizeof(glSecondaryColorPointer_INDEXED));
    packed_data->func = glSecondaryColorPointer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSelectBuffer
void glSelectBuffer(GLsizei size, GLuint * buffer) {
    glSelectBuffer_INDEXED *packed_data = malloc(sizeof(glSelectBuffer_INDEXED));
    packed_data->func = glSelectBuffer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glSeparableFilter2D
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column) {
    glSeparableFilter2D_INDEXED *packed_data = malloc(sizeof(glSeparableFilter2D_INDEXED));
    packed_data->func = glSeparableFilter2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = format;
    packed_data->args.a6 = type;
    packed_data->args.a7 = row;
    packed_data->args.a8 = column;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glShadeModel
void glShadeModel(GLenum mode) {
    glShadeModel_INDEXED *packed_data = malloc(sizeof(glShadeModel_INDEXED));
    packed_data->func = glShadeModel_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glStencilFunc
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    glStencilFunc_INDEXED *packed_data = malloc(sizeof(glStencilFunc_INDEXED));
    packed_data->func = glStencilFunc_INDEX;
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    packed_data->args.a3 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glStencilMask
void glStencilMask(GLuint mask) {
    glStencilMask_INDEXED *packed_data = malloc(sizeof(glStencilMask_INDEXED));
    packed_data->func = glStencilMask_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glStencilOp
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    glStencilOp_INDEXED *packed_data = malloc(sizeof(glStencilOp_INDEXED));
    packed_data->func = glStencilOp_INDEX;
    packed_data->args.a1 = fail;
    packed_data->args.a2 = zfail;
    packed_data->args.a3 = zpass;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord1d
void glTexCoord1d(GLdouble s) {
    glTexCoord1d_INDEXED *packed_data = malloc(sizeof(glTexCoord1d_INDEXED));
    packed_data->func = glTexCoord1d_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord1dv
void glTexCoord1dv(const GLdouble * v) {
    glTexCoord1dv_INDEXED *packed_data = malloc(sizeof(glTexCoord1dv_INDEXED));
    packed_data->func = glTexCoord1dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord1f
void glTexCoord1f(GLfloat s) {
    glTexCoord1f_INDEXED *packed_data = malloc(sizeof(glTexCoord1f_INDEXED));
    packed_data->func = glTexCoord1f_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord1fv
void glTexCoord1fv(const GLfloat * v) {
    glTexCoord1fv_INDEXED *packed_data = malloc(sizeof(glTexCoord1fv_INDEXED));
    packed_data->func = glTexCoord1fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord1i
void glTexCoord1i(GLint s) {
    glTexCoord1i_INDEXED *packed_data = malloc(sizeof(glTexCoord1i_INDEXED));
    packed_data->func = glTexCoord1i_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord1iv
void glTexCoord1iv(const GLint * v) {
    glTexCoord1iv_INDEXED *packed_data = malloc(sizeof(glTexCoord1iv_INDEXED));
    packed_data->func = glTexCoord1iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord1s
void glTexCoord1s(GLshort s) {
    glTexCoord1s_INDEXED *packed_data = malloc(sizeof(glTexCoord1s_INDEXED));
    packed_data->func = glTexCoord1s_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord1sv
void glTexCoord1sv(const GLshort * v) {
    glTexCoord1sv_INDEXED *packed_data = malloc(sizeof(glTexCoord1sv_INDEXED));
    packed_data->func = glTexCoord1sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord2d
void glTexCoord2d(GLdouble s, GLdouble t) {
    glTexCoord2d_INDEXED *packed_data = malloc(sizeof(glTexCoord2d_INDEXED));
    packed_data->func = glTexCoord2d_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord2dv
void glTexCoord2dv(const GLdouble * v) {
    glTexCoord2dv_INDEXED *packed_data = malloc(sizeof(glTexCoord2dv_INDEXED));
    packed_data->func = glTexCoord2dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord2f
void glTexCoord2f(GLfloat s, GLfloat t) {
    glTexCoord2f_INDEXED *packed_data = malloc(sizeof(glTexCoord2f_INDEXED));
    packed_data->func = glTexCoord2f_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord2fv
void glTexCoord2fv(const GLfloat * v) {
    glTexCoord2fv_INDEXED *packed_data = malloc(sizeof(glTexCoord2fv_INDEXED));
    packed_data->func = glTexCoord2fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord2i
void glTexCoord2i(GLint s, GLint t) {
    glTexCoord2i_INDEXED *packed_data = malloc(sizeof(glTexCoord2i_INDEXED));
    packed_data->func = glTexCoord2i_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord2iv
void glTexCoord2iv(const GLint * v) {
    glTexCoord2iv_INDEXED *packed_data = malloc(sizeof(glTexCoord2iv_INDEXED));
    packed_data->func = glTexCoord2iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord2s
void glTexCoord2s(GLshort s, GLshort t) {
    glTexCoord2s_INDEXED *packed_data = malloc(sizeof(glTexCoord2s_INDEXED));
    packed_data->func = glTexCoord2s_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord2sv
void glTexCoord2sv(const GLshort * v) {
    glTexCoord2sv_INDEXED *packed_data = malloc(sizeof(glTexCoord2sv_INDEXED));
    packed_data->func = glTexCoord2sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord3d
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    glTexCoord3d_INDEXED *packed_data = malloc(sizeof(glTexCoord3d_INDEXED));
    packed_data->func = glTexCoord3d_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord3dv
void glTexCoord3dv(const GLdouble * v) {
    glTexCoord3dv_INDEXED *packed_data = malloc(sizeof(glTexCoord3dv_INDEXED));
    packed_data->func = glTexCoord3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord3f
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    glTexCoord3f_INDEXED *packed_data = malloc(sizeof(glTexCoord3f_INDEXED));
    packed_data->func = glTexCoord3f_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord3fv
void glTexCoord3fv(const GLfloat * v) {
    glTexCoord3fv_INDEXED *packed_data = malloc(sizeof(glTexCoord3fv_INDEXED));
    packed_data->func = glTexCoord3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord3i
void glTexCoord3i(GLint s, GLint t, GLint r) {
    glTexCoord3i_INDEXED *packed_data = malloc(sizeof(glTexCoord3i_INDEXED));
    packed_data->func = glTexCoord3i_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord3iv
void glTexCoord3iv(const GLint * v) {
    glTexCoord3iv_INDEXED *packed_data = malloc(sizeof(glTexCoord3iv_INDEXED));
    packed_data->func = glTexCoord3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord3s
void glTexCoord3s(GLshort s, GLshort t, GLshort r) {
    glTexCoord3s_INDEXED *packed_data = malloc(sizeof(glTexCoord3s_INDEXED));
    packed_data->func = glTexCoord3s_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord3sv
void glTexCoord3sv(const GLshort * v) {
    glTexCoord3sv_INDEXED *packed_data = malloc(sizeof(glTexCoord3sv_INDEXED));
    packed_data->func = glTexCoord3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord4d
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    glTexCoord4d_INDEXED *packed_data = malloc(sizeof(glTexCoord4d_INDEXED));
    packed_data->func = glTexCoord4d_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord4dv
void glTexCoord4dv(const GLdouble * v) {
    glTexCoord4dv_INDEXED *packed_data = malloc(sizeof(glTexCoord4dv_INDEXED));
    packed_data->func = glTexCoord4dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord4f
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    glTexCoord4f_INDEXED *packed_data = malloc(sizeof(glTexCoord4f_INDEXED));
    packed_data->func = glTexCoord4f_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord4fv
void glTexCoord4fv(const GLfloat * v) {
    glTexCoord4fv_INDEXED *packed_data = malloc(sizeof(glTexCoord4fv_INDEXED));
    packed_data->func = glTexCoord4fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord4i
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    glTexCoord4i_INDEXED *packed_data = malloc(sizeof(glTexCoord4i_INDEXED));
    packed_data->func = glTexCoord4i_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord4iv
void glTexCoord4iv(const GLint * v) {
    glTexCoord4iv_INDEXED *packed_data = malloc(sizeof(glTexCoord4iv_INDEXED));
    packed_data->func = glTexCoord4iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord4s
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    glTexCoord4s_INDEXED *packed_data = malloc(sizeof(glTexCoord4s_INDEXED));
    packed_data->func = glTexCoord4s_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoord4sv
void glTexCoord4sv(const GLshort * v) {
    glTexCoord4sv_INDEXED *packed_data = malloc(sizeof(glTexCoord4sv_INDEXED));
    packed_data->func = glTexCoord4sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexCoordPointer
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glTexCoordPointer_INDEXED *packed_data = malloc(sizeof(glTexCoordPointer_INDEXED));
    packed_data->func = glTexCoordPointer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexEnvf
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    glTexEnvf_INDEXED *packed_data = malloc(sizeof(glTexEnvf_INDEXED));
    packed_data->func = glTexEnvf_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexEnvfv
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    glTexEnvfv_INDEXED *packed_data = malloc(sizeof(glTexEnvfv_INDEXED));
    packed_data->func = glTexEnvfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexEnvi
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    glTexEnvi_INDEXED *packed_data = malloc(sizeof(glTexEnvi_INDEXED));
    packed_data->func = glTexEnvi_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexEnviv
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    glTexEnviv_INDEXED *packed_data = malloc(sizeof(glTexEnviv_INDEXED));
    packed_data->func = glTexEnviv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexGend
void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    glTexGend_INDEXED *packed_data = malloc(sizeof(glTexGend_INDEXED));
    packed_data->func = glTexGend_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexGendv
void glTexGendv(GLenum coord, GLenum pname, const GLdouble * params) {
    glTexGendv_INDEXED *packed_data = malloc(sizeof(glTexGendv_INDEXED));
    packed_data->func = glTexGendv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexGenf
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    glTexGenf_INDEXED *packed_data = malloc(sizeof(glTexGenf_INDEXED));
    packed_data->func = glTexGenf_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexGenfv
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    glTexGenfv_INDEXED *packed_data = malloc(sizeof(glTexGenfv_INDEXED));
    packed_data->func = glTexGenfv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexGeni
void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    glTexGeni_INDEXED *packed_data = malloc(sizeof(glTexGeni_INDEXED));
    packed_data->func = glTexGeni_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexGeniv
void glTexGeniv(GLenum coord, GLenum pname, const GLint * params) {
    glTexGeniv_INDEXED *packed_data = malloc(sizeof(glTexGeniv_INDEXED));
    packed_data->func = glTexGeniv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexImage1D
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexImage1D_INDEXED *packed_data = malloc(sizeof(glTexImage1D_INDEXED));
    packed_data->func = glTexImage1D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = border;
    packed_data->args.a6 = format;
    packed_data->args.a7 = type;
    packed_data->args.a8 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexImage2D
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexImage2D_INDEXED *packed_data = malloc(sizeof(glTexImage2D_INDEXED));
    packed_data->func = glTexImage2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = height;
    packed_data->args.a6 = border;
    packed_data->args.a7 = format;
    packed_data->args.a8 = type;
    packed_data->args.a9 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexImage3D
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexImage3D_INDEXED *packed_data = malloc(sizeof(glTexImage3D_INDEXED));
    packed_data->func = glTexImage3D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = height;
    packed_data->args.a6 = depth;
    packed_data->args.a7 = border;
    packed_data->args.a8 = format;
    packed_data->args.a9 = type;
    packed_data->args.a10 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexParameterf
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    glTexParameterf_INDEXED *packed_data = malloc(sizeof(glTexParameterf_INDEXED));
    packed_data->func = glTexParameterf_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexParameterfv
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glTexParameterfv_INDEXED *packed_data = malloc(sizeof(glTexParameterfv_INDEXED));
    packed_data->func = glTexParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexParameteri
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    glTexParameteri_INDEXED *packed_data = malloc(sizeof(glTexParameteri_INDEXED));
    packed_data->func = glTexParameteri_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexParameteriv
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glTexParameteriv_INDEXED *packed_data = malloc(sizeof(glTexParameteriv_INDEXED));
    packed_data->func = glTexParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexSubImage1D
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexSubImage1D_INDEXED *packed_data = malloc(sizeof(glTexSubImage1D_INDEXED));
    packed_data->func = glTexSubImage1D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = width;
    packed_data->args.a5 = format;
    packed_data->args.a6 = type;
    packed_data->args.a7 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexSubImage2D
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexSubImage2D_INDEXED *packed_data = malloc(sizeof(glTexSubImage2D_INDEXED));
    packed_data->func = glTexSubImage2D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = width;
    packed_data->args.a6 = height;
    packed_data->args.a7 = format;
    packed_data->args.a8 = type;
    packed_data->args.a9 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTexSubImage3D
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexSubImage3D_INDEXED *packed_data = malloc(sizeof(glTexSubImage3D_INDEXED));
    packed_data->func = glTexSubImage3D_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = zoffset;
    packed_data->args.a6 = width;
    packed_data->args.a7 = height;
    packed_data->args.a8 = depth;
    packed_data->args.a9 = format;
    packed_data->args.a10 = type;
    packed_data->args.a11 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTranslated
void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    glTranslated_INDEXED *packed_data = malloc(sizeof(glTranslated_INDEXED));
    packed_data->func = glTranslated_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glTranslatef
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    glTranslatef_INDEXED *packed_data = malloc(sizeof(glTranslatef_INDEXED));
    packed_data->func = glTranslatef_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glUnmapBuffer
GLboolean glUnmapBuffer(GLenum target) {
    glUnmapBuffer_INDEXED *packed_data = malloc(sizeof(glUnmapBuffer_INDEXED));
    packed_data->func = glUnmapBuffer_INDEX;
    packed_data->args.a1 = target;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glVertex2d
void glVertex2d(GLdouble x, GLdouble y) {
    glVertex2d_INDEXED *packed_data = malloc(sizeof(glVertex2d_INDEXED));
    packed_data->func = glVertex2d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex2dv
void glVertex2dv(const GLdouble * v) {
    glVertex2dv_INDEXED *packed_data = malloc(sizeof(glVertex2dv_INDEXED));
    packed_data->func = glVertex2dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex2f
void glVertex2f(GLfloat x, GLfloat y) {
    glVertex2f_INDEXED *packed_data = malloc(sizeof(glVertex2f_INDEXED));
    packed_data->func = glVertex2f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex2fv
void glVertex2fv(const GLfloat * v) {
    glVertex2fv_INDEXED *packed_data = malloc(sizeof(glVertex2fv_INDEXED));
    packed_data->func = glVertex2fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex2i
void glVertex2i(GLint x, GLint y) {
    glVertex2i_INDEXED *packed_data = malloc(sizeof(glVertex2i_INDEXED));
    packed_data->func = glVertex2i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex2iv
void glVertex2iv(const GLint * v) {
    glVertex2iv_INDEXED *packed_data = malloc(sizeof(glVertex2iv_INDEXED));
    packed_data->func = glVertex2iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex2s
void glVertex2s(GLshort x, GLshort y) {
    glVertex2s_INDEXED *packed_data = malloc(sizeof(glVertex2s_INDEXED));
    packed_data->func = glVertex2s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex2sv
void glVertex2sv(const GLshort * v) {
    glVertex2sv_INDEXED *packed_data = malloc(sizeof(glVertex2sv_INDEXED));
    packed_data->func = glVertex2sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex3d
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
    glVertex3d_INDEXED *packed_data = malloc(sizeof(glVertex3d_INDEXED));
    packed_data->func = glVertex3d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex3dv
void glVertex3dv(const GLdouble * v) {
    glVertex3dv_INDEXED *packed_data = malloc(sizeof(glVertex3dv_INDEXED));
    packed_data->func = glVertex3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex3f
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    glVertex3f_INDEXED *packed_data = malloc(sizeof(glVertex3f_INDEXED));
    packed_data->func = glVertex3f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex3fv
void glVertex3fv(const GLfloat * v) {
    glVertex3fv_INDEXED *packed_data = malloc(sizeof(glVertex3fv_INDEXED));
    packed_data->func = glVertex3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex3i
void glVertex3i(GLint x, GLint y, GLint z) {
    glVertex3i_INDEXED *packed_data = malloc(sizeof(glVertex3i_INDEXED));
    packed_data->func = glVertex3i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex3iv
void glVertex3iv(const GLint * v) {
    glVertex3iv_INDEXED *packed_data = malloc(sizeof(glVertex3iv_INDEXED));
    packed_data->func = glVertex3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex3s
void glVertex3s(GLshort x, GLshort y, GLshort z) {
    glVertex3s_INDEXED *packed_data = malloc(sizeof(glVertex3s_INDEXED));
    packed_data->func = glVertex3s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex3sv
void glVertex3sv(const GLshort * v) {
    glVertex3sv_INDEXED *packed_data = malloc(sizeof(glVertex3sv_INDEXED));
    packed_data->func = glVertex3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex4d
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glVertex4d_INDEXED *packed_data = malloc(sizeof(glVertex4d_INDEXED));
    packed_data->func = glVertex4d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex4dv
void glVertex4dv(const GLdouble * v) {
    glVertex4dv_INDEXED *packed_data = malloc(sizeof(glVertex4dv_INDEXED));
    packed_data->func = glVertex4dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex4f
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glVertex4f_INDEXED *packed_data = malloc(sizeof(glVertex4f_INDEXED));
    packed_data->func = glVertex4f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex4fv
void glVertex4fv(const GLfloat * v) {
    glVertex4fv_INDEXED *packed_data = malloc(sizeof(glVertex4fv_INDEXED));
    packed_data->func = glVertex4fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex4i
void glVertex4i(GLint x, GLint y, GLint z, GLint w) {
    glVertex4i_INDEXED *packed_data = malloc(sizeof(glVertex4i_INDEXED));
    packed_data->func = glVertex4i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex4iv
void glVertex4iv(const GLint * v) {
    glVertex4iv_INDEXED *packed_data = malloc(sizeof(glVertex4iv_INDEXED));
    packed_data->func = glVertex4iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex4s
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    glVertex4s_INDEXED *packed_data = malloc(sizeof(glVertex4s_INDEXED));
    packed_data->func = glVertex4s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertex4sv
void glVertex4sv(const GLshort * v) {
    glVertex4sv_INDEXED *packed_data = malloc(sizeof(glVertex4sv_INDEXED));
    packed_data->func = glVertex4sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glVertexPointer
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glVertexPointer_INDEXED *packed_data = malloc(sizeof(glVertexPointer_INDEXED));
    packed_data->func = glVertexPointer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glViewport
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    glViewport_INDEXED *packed_data = malloc(sizeof(glViewport_INDEXED));
    packed_data->func = glViewport_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos2d
void glWindowPos2d(GLdouble x, GLdouble y) {
    glWindowPos2d_INDEXED *packed_data = malloc(sizeof(glWindowPos2d_INDEXED));
    packed_data->func = glWindowPos2d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos2dv
void glWindowPos2dv(const GLdouble * v) {
    glWindowPos2dv_INDEXED *packed_data = malloc(sizeof(glWindowPos2dv_INDEXED));
    packed_data->func = glWindowPos2dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos2f
void glWindowPos2f(GLfloat x, GLfloat y) {
    glWindowPos2f_INDEXED *packed_data = malloc(sizeof(glWindowPos2f_INDEXED));
    packed_data->func = glWindowPos2f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos2fv
void glWindowPos2fv(const GLfloat * v) {
    glWindowPos2fv_INDEXED *packed_data = malloc(sizeof(glWindowPos2fv_INDEXED));
    packed_data->func = glWindowPos2fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos2i
void glWindowPos2i(GLint x, GLint y) {
    glWindowPos2i_INDEXED *packed_data = malloc(sizeof(glWindowPos2i_INDEXED));
    packed_data->func = glWindowPos2i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos2iv
void glWindowPos2iv(const GLint * v) {
    glWindowPos2iv_INDEXED *packed_data = malloc(sizeof(glWindowPos2iv_INDEXED));
    packed_data->func = glWindowPos2iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos2s
void glWindowPos2s(GLshort x, GLshort y) {
    glWindowPos2s_INDEXED *packed_data = malloc(sizeof(glWindowPos2s_INDEXED));
    packed_data->func = glWindowPos2s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos2sv
void glWindowPos2sv(const GLshort * v) {
    glWindowPos2sv_INDEXED *packed_data = malloc(sizeof(glWindowPos2sv_INDEXED));
    packed_data->func = glWindowPos2sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos3d
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    glWindowPos3d_INDEXED *packed_data = malloc(sizeof(glWindowPos3d_INDEXED));
    packed_data->func = glWindowPos3d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos3dv
void glWindowPos3dv(const GLdouble * v) {
    glWindowPos3dv_INDEXED *packed_data = malloc(sizeof(glWindowPos3dv_INDEXED));
    packed_data->func = glWindowPos3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos3f
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    glWindowPos3f_INDEXED *packed_data = malloc(sizeof(glWindowPos3f_INDEXED));
    packed_data->func = glWindowPos3f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos3fv
void glWindowPos3fv(const GLfloat * v) {
    glWindowPos3fv_INDEXED *packed_data = malloc(sizeof(glWindowPos3fv_INDEXED));
    packed_data->func = glWindowPos3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos3i
void glWindowPos3i(GLint x, GLint y, GLint z) {
    glWindowPos3i_INDEXED *packed_data = malloc(sizeof(glWindowPos3i_INDEXED));
    packed_data->func = glWindowPos3i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos3iv
void glWindowPos3iv(const GLint * v) {
    glWindowPos3iv_INDEXED *packed_data = malloc(sizeof(glWindowPos3iv_INDEXED));
    packed_data->func = glWindowPos3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos3s
void glWindowPos3s(GLshort x, GLshort y, GLshort z) {
    glWindowPos3s_INDEXED *packed_data = malloc(sizeof(glWindowPos3s_INDEXED));
    packed_data->func = glWindowPos3s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glWindowPos3sv
void glWindowPos3sv(const GLshort * v) {
    glWindowPos3sv_INDEXED *packed_data = malloc(sizeof(glWindowPos3sv_INDEXED));
    packed_data->func = glWindowPos3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXBindHyperpipeSGIX
int glXBindHyperpipeSGIX(Display * dpy, int hpId) {
    glXBindHyperpipeSGIX_INDEXED *packed_data = malloc(sizeof(glXBindHyperpipeSGIX_INDEXED));
    packed_data->func = glXBindHyperpipeSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXBindSwapBarrierSGIX
void glXBindSwapBarrierSGIX(uint32_t window, uint32_t barrier) {
    glXBindSwapBarrierSGIX_INDEXED *packed_data = malloc(sizeof(glXBindSwapBarrierSGIX_INDEXED));
    packed_data->func = glXBindSwapBarrierSGIX_INDEX;
    packed_data->args.a1 = window;
    packed_data->args.a2 = barrier;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXChangeDrawableAttributes
void glXChangeDrawableAttributes(uint32_t drawable) {
    glXChangeDrawableAttributes_INDEXED *packed_data = malloc(sizeof(glXChangeDrawableAttributes_INDEXED));
    packed_data->func = glXChangeDrawableAttributes_INDEX;
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXChangeDrawableAttributesSGIX
void glXChangeDrawableAttributesSGIX(uint32_t drawable) {
    glXChangeDrawableAttributesSGIX_INDEXED *packed_data = malloc(sizeof(glXChangeDrawableAttributesSGIX_INDEXED));
    packed_data->func = glXChangeDrawableAttributesSGIX_INDEX;
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXChooseFBConfig
GLXFBConfig * glXChooseFBConfig(Display * dpy, int screen, const int * attrib_list, int * nelements) {
    glXChooseFBConfig_INDEXED *packed_data = malloc(sizeof(glXChooseFBConfig_INDEXED));
    packed_data->func = glXChooseFBConfig_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = attrib_list;
    packed_data->args.a4 = nelements;
    GLXFBConfig * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXChooseVisual
XVisualInfo * glXChooseVisual(Display * dpy, int screen, int * attribList) {
    glXChooseVisual_INDEXED *packed_data = malloc(sizeof(glXChooseVisual_INDEXED));
    packed_data->func = glXChooseVisual_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = attribList;
    XVisualInfo * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXClientInfo
void glXClientInfo() {
    glXClientInfo_INDEXED *packed_data = malloc(sizeof(glXClientInfo_INDEXED));
    packed_data->func = glXClientInfo_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXCopyContext
void glXCopyContext(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask) {
    glXCopyContext_INDEXED *packed_data = malloc(sizeof(glXCopyContext_INDEXED));
    packed_data->func = glXCopyContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = src;
    packed_data->args.a3 = dst;
    packed_data->args.a4 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXCreateContext
GLXContext glXCreateContext(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct) {
    glXCreateContext_INDEXED *packed_data = malloc(sizeof(glXCreateContext_INDEXED));
    packed_data->func = glXCreateContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = vis;
    packed_data->args.a3 = shareList;
    packed_data->args.a4 = direct;
    GLXContext ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXCreateContextAttribsARB
GLXContext glXCreateContextAttribsARB(Display * display, void * config, GLXContext share_context, Bool direct, const int * attrib_list) {
    glXCreateContextAttribsARB_INDEXED *packed_data = malloc(sizeof(glXCreateContextAttribsARB_INDEXED));
    packed_data->func = glXCreateContextAttribsARB_INDEX;
    packed_data->args.a1 = display;
    packed_data->args.a2 = config;
    packed_data->args.a3 = share_context;
    packed_data->args.a4 = direct;
    packed_data->args.a5 = attrib_list;
    GLXContext ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXCreateContextWithConfigSGIX
void glXCreateContextWithConfigSGIX(uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list) {
    glXCreateContextWithConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateContextWithConfigSGIX_INDEXED));
    packed_data->func = glXCreateContextWithConfigSGIX_INDEX;
    packed_data->args.a1 = gc_id;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = config;
    packed_data->args.a4 = share_list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXCreateGLXPbufferSGIX
void glXCreateGLXPbufferSGIX(uint32_t config, uint32_t pbuffer) {
    glXCreateGLXPbufferSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPbufferSGIX_INDEXED));
    packed_data->func = glXCreateGLXPbufferSGIX_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = pbuffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXCreateGLXPixmap
GLXPixmap glXCreateGLXPixmap(Display * dpy, XVisualInfo * visual, Pixmap pixmap) {
    glXCreateGLXPixmap_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPixmap_INDEXED));
    packed_data->func = glXCreateGLXPixmap_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = visual;
    packed_data->args.a3 = pixmap;
    GLXPixmap ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXCreateGLXPixmapWithConfigSGIX
void glXCreateGLXPixmapWithConfigSGIX(uint32_t config, uint32_t pixmap, uint32_t glxpixmap) {
    glXCreateGLXPixmapWithConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPixmapWithConfigSGIX_INDEXED));
    packed_data->func = glXCreateGLXPixmapWithConfigSGIX_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = pixmap;
    packed_data->args.a3 = glxpixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXCreateGLXVideoSourceSGIX
void glXCreateGLXVideoSourceSGIX(Display * dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node) {
    glXCreateGLXVideoSourceSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateGLXVideoSourceSGIX_INDEXED));
    packed_data->func = glXCreateGLXVideoSourceSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = server;
    packed_data->args.a4 = path;
    packed_data->args.a5 = class;
    packed_data->args.a6 = node;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXCreateNewContext
GLXContext glXCreateNewContext(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct) {
    glXCreateNewContext_INDEXED *packed_data = malloc(sizeof(glXCreateNewContext_INDEXED));
    packed_data->func = glXCreateNewContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = render_type;
    packed_data->args.a4 = share_list;
    packed_data->args.a5 = direct;
    GLXContext ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXCreatePbuffer
GLXPbuffer glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list) {
    glXCreatePbuffer_INDEXED *packed_data = malloc(sizeof(glXCreatePbuffer_INDEXED));
    packed_data->func = glXCreatePbuffer_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = attrib_list;
    GLXPbuffer ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXCreatePixmap
GLXPixmap glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list) {
    glXCreatePixmap_INDEXED *packed_data = malloc(sizeof(glXCreatePixmap_INDEXED));
    packed_data->func = glXCreatePixmap_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = pixmap;
    packed_data->args.a4 = attrib_list;
    GLXPixmap ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXCreateWindow
GLXWindow glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list) {
    glXCreateWindow_INDEXED *packed_data = malloc(sizeof(glXCreateWindow_INDEXED));
    packed_data->func = glXCreateWindow_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = win;
    packed_data->args.a4 = attrib_list;
    GLXWindow ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXDestroyContext
void glXDestroyContext(Display * dpy, GLXContext ctx) {
    glXDestroyContext_INDEXED *packed_data = malloc(sizeof(glXDestroyContext_INDEXED));
    packed_data->func = glXDestroyContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXDestroyGLXPbufferSGIX
void glXDestroyGLXPbufferSGIX(uint32_t pbuffer) {
    glXDestroyGLXPbufferSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXPbufferSGIX_INDEXED));
    packed_data->func = glXDestroyGLXPbufferSGIX_INDEX;
    packed_data->args.a1 = pbuffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXDestroyGLXPixmap
void glXDestroyGLXPixmap(Display * dpy, GLXPixmap pixmap) {
    glXDestroyGLXPixmap_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXPixmap_INDEXED));
    packed_data->func = glXDestroyGLXPixmap_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXDestroyGLXVideoSourceSGIX
void glXDestroyGLXVideoSourceSGIX(Display * dpy, uint32_t glxvideosource) {
    glXDestroyGLXVideoSourceSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXVideoSourceSGIX_INDEXED));
    packed_data->func = glXDestroyGLXVideoSourceSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = glxvideosource;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXDestroyHyperpipeConfigSGIX
int glXDestroyHyperpipeConfigSGIX(Display * dpy, int hpId) {
    glXDestroyHyperpipeConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyHyperpipeConfigSGIX_INDEXED));
    packed_data->func = glXDestroyHyperpipeConfigSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXDestroyPbuffer
void glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf) {
    glXDestroyPbuffer_INDEXED *packed_data = malloc(sizeof(glXDestroyPbuffer_INDEXED));
    packed_data->func = glXDestroyPbuffer_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pbuf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXDestroyPixmap
void glXDestroyPixmap(Display * dpy, GLXPixmap pixmap) {
    glXDestroyPixmap_INDEXED *packed_data = malloc(sizeof(glXDestroyPixmap_INDEXED));
    packed_data->func = glXDestroyPixmap_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXDestroyWindow
void glXDestroyWindow(Display * dpy, GLXWindow win) {
    glXDestroyWindow_INDEXED *packed_data = malloc(sizeof(glXDestroyWindow_INDEXED));
    packed_data->func = glXDestroyWindow_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = win;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXGetClientString
const char * glXGetClientString(Display * display, int name) {
    glXGetClientString_INDEXED *packed_data = malloc(sizeof(glXGetClientString_INDEXED));
    packed_data->func = glXGetClientString_INDEX;
    packed_data->args.a1 = display;
    packed_data->args.a2 = name;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetConfig
int glXGetConfig(Display * display, XVisualInfo * visual, int attribute, int * value) {
    glXGetConfig_INDEXED *packed_data = malloc(sizeof(glXGetConfig_INDEXED));
    packed_data->func = glXGetConfig_INDEX;
    packed_data->args.a1 = display;
    packed_data->args.a2 = visual;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetCurrentContext
GLXContext glXGetCurrentContext() {
    glXGetCurrentContext_INDEXED *packed_data = malloc(sizeof(glXGetCurrentContext_INDEXED));
    packed_data->func = glXGetCurrentContext_INDEX;
    GLXContext ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetCurrentDisplay
Display * glXGetCurrentDisplay() {
    glXGetCurrentDisplay_INDEXED *packed_data = malloc(sizeof(glXGetCurrentDisplay_INDEXED));
    packed_data->func = glXGetCurrentDisplay_INDEX;
    Display * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetCurrentDrawable
GLXDrawable glXGetCurrentDrawable() {
    glXGetCurrentDrawable_INDEXED *packed_data = malloc(sizeof(glXGetCurrentDrawable_INDEXED));
    packed_data->func = glXGetCurrentDrawable_INDEX;
    GLXDrawable ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetCurrentReadDrawable
GLXDrawable glXGetCurrentReadDrawable() {
    glXGetCurrentReadDrawable_INDEXED *packed_data = malloc(sizeof(glXGetCurrentReadDrawable_INDEXED));
    packed_data->func = glXGetCurrentReadDrawable_INDEX;
    GLXDrawable ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetDrawableAttributes
void glXGetDrawableAttributes(uint32_t drawable) {
    glXGetDrawableAttributes_INDEXED *packed_data = malloc(sizeof(glXGetDrawableAttributes_INDEXED));
    packed_data->func = glXGetDrawableAttributes_INDEX;
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXGetDrawableAttributesSGIX
void glXGetDrawableAttributesSGIX(uint32_t drawable) {
    glXGetDrawableAttributesSGIX_INDEXED *packed_data = malloc(sizeof(glXGetDrawableAttributesSGIX_INDEXED));
    packed_data->func = glXGetDrawableAttributesSGIX_INDEX;
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXGetFBConfigAttrib
int glXGetFBConfigAttrib(Display * dpy, GLXFBConfig config, int attribute, int * value) {
    glXGetFBConfigAttrib_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigAttrib_INDEXED));
    packed_data->func = glXGetFBConfigAttrib_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetFBConfigs
GLXFBConfig * glXGetFBConfigs(Display * dpy, int screen, int * nelements) {
    glXGetFBConfigs_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigs_INDEXED));
    packed_data->func = glXGetFBConfigs_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = nelements;
    GLXFBConfig * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetFBConfigsSGIX
void glXGetFBConfigsSGIX() {
    glXGetFBConfigsSGIX_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigsSGIX_INDEXED));
    packed_data->func = glXGetFBConfigsSGIX_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXGetProcAddress
__GLXextFuncPtr glXGetProcAddress(const GLubyte * procName) {
    glXGetProcAddress_INDEXED *packed_data = malloc(sizeof(glXGetProcAddress_INDEXED));
    packed_data->func = glXGetProcAddress_INDEX;
    packed_data->args.a1 = procName;
    __GLXextFuncPtr ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXGetSelectedEvent
void glXGetSelectedEvent(Display * dpy, GLXDrawable draw, unsigned long * event_mask) {
    glXGetSelectedEvent_INDEXED *packed_data = malloc(sizeof(glXGetSelectedEvent_INDEXED));
    packed_data->func = glXGetSelectedEvent_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = event_mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXGetVisualConfigs
void glXGetVisualConfigs() {
    glXGetVisualConfigs_INDEXED *packed_data = malloc(sizeof(glXGetVisualConfigs_INDEXED));
    packed_data->func = glXGetVisualConfigs_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXGetVisualFromFBConfig
XVisualInfo * glXGetVisualFromFBConfig(Display * dpy, GLXFBConfig config) {
    glXGetVisualFromFBConfig_INDEXED *packed_data = malloc(sizeof(glXGetVisualFromFBConfig_INDEXED));
    packed_data->func = glXGetVisualFromFBConfig_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    XVisualInfo * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXHyperpipeAttribSGIX
int glXHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList) {
    glXHyperpipeAttribSGIX_INDEXED *packed_data = malloc(sizeof(glXHyperpipeAttribSGIX_INDEXED));
    packed_data->func = glXHyperpipeAttribSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = timeSlice;
    packed_data->args.a3 = attrib;
    packed_data->args.a4 = size;
    packed_data->args.a5 = attribList;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXHyperpipeConfigSGIX
int glXHyperpipeConfigSGIX(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int * hpId) {
    glXHyperpipeConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXHyperpipeConfigSGIX_INDEXED));
    packed_data->func = glXHyperpipeConfigSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = networkId;
    packed_data->args.a3 = npipes;
    packed_data->args.a4 = cfg;
    packed_data->args.a5 = hpId;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXIsDirect
Bool glXIsDirect(Display * dpy, GLXContext ctx) {
    glXIsDirect_INDEXED *packed_data = malloc(sizeof(glXIsDirect_INDEXED));
    packed_data->func = glXIsDirect_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXJoinSwapGroupSGIX
void glXJoinSwapGroupSGIX(uint32_t window, uint32_t group) {
    glXJoinSwapGroupSGIX_INDEXED *packed_data = malloc(sizeof(glXJoinSwapGroupSGIX_INDEXED));
    packed_data->func = glXJoinSwapGroupSGIX_INDEX;
    packed_data->args.a1 = window;
    packed_data->args.a2 = group;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXMakeContextCurrent
Bool glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
    glXMakeContextCurrent_INDEXED *packed_data = malloc(sizeof(glXMakeContextCurrent_INDEXED));
    packed_data->func = glXMakeContextCurrent_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = read;
    packed_data->args.a4 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXMakeCurrent
Bool glXMakeCurrent(Display * dpy, GLXDrawable drawable, GLXContext ctx) {
    glXMakeCurrent_INDEXED *packed_data = malloc(sizeof(glXMakeCurrent_INDEXED));
    packed_data->func = glXMakeCurrent_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = drawable;
    packed_data->args.a3 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXMakeCurrentReadSGI
void glXMakeCurrentReadSGI(uint32_t drawable, uint32_t readdrawable, uint32_t context) {
    glXMakeCurrentReadSGI_INDEXED *packed_data = malloc(sizeof(glXMakeCurrentReadSGI_INDEXED));
    packed_data->func = glXMakeCurrentReadSGI_INDEX;
    packed_data->args.a1 = drawable;
    packed_data->args.a2 = readdrawable;
    packed_data->args.a3 = context;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXQueryContext
int glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value) {
    glXQueryContext_INDEXED *packed_data = malloc(sizeof(glXQueryContext_INDEXED));
    packed_data->func = glXQueryContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXQueryContextInfoEXT
void glXQueryContextInfoEXT() {
    glXQueryContextInfoEXT_INDEXED *packed_data = malloc(sizeof(glXQueryContextInfoEXT_INDEXED));
    packed_data->func = glXQueryContextInfoEXT_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXQueryDrawable
void glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value) {
    glXQueryDrawable_INDEXED *packed_data = malloc(sizeof(glXQueryDrawable_INDEXED));
    packed_data->func = glXQueryDrawable_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXQueryExtension
Bool glXQueryExtension(Display * display, int * errorBase, int * eventBase) {
    glXQueryExtension_INDEXED *packed_data = malloc(sizeof(glXQueryExtension_INDEXED));
    packed_data->func = glXQueryExtension_INDEX;
    packed_data->args.a1 = display;
    packed_data->args.a2 = errorBase;
    packed_data->args.a3 = eventBase;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXQueryExtensionsString
const char * glXQueryExtensionsString(Display * dpy, int screen) {
    glXQueryExtensionsString_INDEXED *packed_data = malloc(sizeof(glXQueryExtensionsString_INDEXED));
    packed_data->func = glXQueryExtensionsString_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXQueryHyperpipeAttribSGIX
int glXQueryHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * returnAttribList) {
    glXQueryHyperpipeAttribSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeAttribSGIX_INDEXED));
    packed_data->func = glXQueryHyperpipeAttribSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = timeSlice;
    packed_data->args.a3 = attrib;
    packed_data->args.a4 = size;
    packed_data->args.a5 = returnAttribList;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXQueryHyperpipeBestAttribSGIX
int glXQueryHyperpipeBestAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList, void * returnAttribList) {
    glXQueryHyperpipeBestAttribSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeBestAttribSGIX_INDEXED));
    packed_data->func = glXQueryHyperpipeBestAttribSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = timeSlice;
    packed_data->args.a3 = attrib;
    packed_data->args.a4 = size;
    packed_data->args.a5 = attribList;
    packed_data->args.a6 = returnAttribList;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXQueryHyperpipeConfigSGIX
GLXHyperpipeConfigSGIX * glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes) {
    glXQueryHyperpipeConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeConfigSGIX_INDEXED));
    packed_data->func = glXQueryHyperpipeConfigSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    packed_data->args.a3 = npipes;
    GLXHyperpipeConfigSGIX * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXQueryHyperpipeNetworkSGIX
GLXHyperpipeNetworkSGIX * glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes) {
    glXQueryHyperpipeNetworkSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeNetworkSGIX_INDEXED));
    packed_data->func = glXQueryHyperpipeNetworkSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = npipes;
    GLXHyperpipeNetworkSGIX * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXQueryMaxSwapBarriersSGIX
void glXQueryMaxSwapBarriersSGIX() {
    glXQueryMaxSwapBarriersSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryMaxSwapBarriersSGIX_INDEXED));
    packed_data->func = glXQueryMaxSwapBarriersSGIX_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXQueryServerString
const char * glXQueryServerString(Display * dpy, int screen, int name) {
    glXQueryServerString_INDEXED *packed_data = malloc(sizeof(glXQueryServerString_INDEXED));
    packed_data->func = glXQueryServerString_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = name;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXQueryVersion
Bool glXQueryVersion(Display * dpy, int * maj, int * min) {
    glXQueryVersion_INDEXED *packed_data = malloc(sizeof(glXQueryVersion_INDEXED));
    packed_data->func = glXQueryVersion_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = maj;
    packed_data->args.a3 = min;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_glXRender
void glXRender() {
    glXRender_INDEXED *packed_data = malloc(sizeof(glXRender_INDEXED));
    packed_data->func = glXRender_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXRenderLarge
void glXRenderLarge() {
    glXRenderLarge_INDEXED *packed_data = malloc(sizeof(glXRenderLarge_INDEXED));
    packed_data->func = glXRenderLarge_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXSelectEvent
void glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask) {
    glXSelectEvent_INDEXED *packed_data = malloc(sizeof(glXSelectEvent_INDEXED));
    packed_data->func = glXSelectEvent_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = event_mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXSwapBuffers
void glXSwapBuffers(Display * dpy, GLXDrawable drawable) {
    glXSwapBuffers_INDEXED *packed_data = malloc(sizeof(glXSwapBuffers_INDEXED));
    packed_data->func = glXSwapBuffers_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXSwapIntervalSGI
void glXSwapIntervalSGI() {
    glXSwapIntervalSGI_INDEXED *packed_data = malloc(sizeof(glXSwapIntervalSGI_INDEXED));
    packed_data->func = glXSwapIntervalSGI_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXUseXFont
void glXUseXFont(Font font, int first, int count, int list) {
    glXUseXFont_INDEXED *packed_data = malloc(sizeof(glXUseXFont_INDEXED));
    packed_data->func = glXUseXFont_INDEX;
    packed_data->args.a1 = font;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    packed_data->args.a4 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXVendorPrivate
void glXVendorPrivate() {
    glXVendorPrivate_INDEXED *packed_data = malloc(sizeof(glXVendorPrivate_INDEXED));
    packed_data->func = glXVendorPrivate_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXVendorPrivateWithReply
void glXVendorPrivateWithReply() {
    glXVendorPrivateWithReply_INDEXED *packed_data = malloc(sizeof(glXVendorPrivateWithReply_INDEXED));
    packed_data->func = glXVendorPrivateWithReply_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXWaitGL
void glXWaitGL() {
    glXWaitGL_INDEXED *packed_data = malloc(sizeof(glXWaitGL_INDEXED));
    packed_data->func = glXWaitGL_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_glXWaitX
void glXWaitX() {
    glXWaitX_INDEXED *packed_data = malloc(sizeof(glXWaitX_INDEXED));
    packed_data->func = glXWaitX_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif


__GLXextFuncPtr glXGetProcAddressARB(const GLubyte *name) {
    if (strcmp(name, "glAccum") == 0) {
        return (void *)glAccum;
    }
    if (strcmp(name, "glActiveTexture") == 0) {
        return (void *)glActiveTexture;
    }
    if (strcmp(name, "glAlphaFunc") == 0) {
        return (void *)glAlphaFunc;
    }
    if (strcmp(name, "glAreTexturesResident") == 0) {
        return (void *)glAreTexturesResident;
    }
    if (strcmp(name, "glArrayElement") == 0) {
        return (void *)glArrayElement;
    }
    if (strcmp(name, "glBegin") == 0) {
        return (void *)glBegin;
    }
    if (strcmp(name, "glBeginQuery") == 0) {
        return (void *)glBeginQuery;
    }
    if (strcmp(name, "glBindBuffer") == 0) {
        return (void *)glBindBuffer;
    }
    if (strcmp(name, "glBindTexture") == 0) {
        return (void *)glBindTexture;
    }
    if (strcmp(name, "glBitmap") == 0) {
        return (void *)glBitmap;
    }
    if (strcmp(name, "glBlendColor") == 0) {
        return (void *)glBlendColor;
    }
    if (strcmp(name, "glBlendEquation") == 0) {
        return (void *)glBlendEquation;
    }
    if (strcmp(name, "glBlendFunc") == 0) {
        return (void *)glBlendFunc;
    }
    if (strcmp(name, "glBlendFuncSeparate") == 0) {
        return (void *)glBlendFuncSeparate;
    }
    if (strcmp(name, "glBufferData") == 0) {
        return (void *)glBufferData;
    }
    if (strcmp(name, "glBufferSubData") == 0) {
        return (void *)glBufferSubData;
    }
    if (strcmp(name, "glCallList") == 0) {
        return (void *)glCallList;
    }
    if (strcmp(name, "glCallLists") == 0) {
        return (void *)glCallLists;
    }
    if (strcmp(name, "glClear") == 0) {
        return (void *)glClear;
    }
    if (strcmp(name, "glClearAccum") == 0) {
        return (void *)glClearAccum;
    }
    if (strcmp(name, "glClearColor") == 0) {
        return (void *)glClearColor;
    }
    if (strcmp(name, "glClearDepth") == 0) {
        return (void *)glClearDepth;
    }
    if (strcmp(name, "glClearIndex") == 0) {
        return (void *)glClearIndex;
    }
    if (strcmp(name, "glClearStencil") == 0) {
        return (void *)glClearStencil;
    }
    if (strcmp(name, "glClientActiveTexture") == 0) {
        return (void *)glClientActiveTexture;
    }
    if (strcmp(name, "glClipPlane") == 0) {
        return (void *)glClipPlane;
    }
    if (strcmp(name, "glColor3b") == 0) {
        return (void *)glColor3b;
    }
    if (strcmp(name, "glColor3bv") == 0) {
        return (void *)glColor3bv;
    }
    if (strcmp(name, "glColor3d") == 0) {
        return (void *)glColor3d;
    }
    if (strcmp(name, "glColor3dv") == 0) {
        return (void *)glColor3dv;
    }
    if (strcmp(name, "glColor3f") == 0) {
        return (void *)glColor3f;
    }
    if (strcmp(name, "glColor3fv") == 0) {
        return (void *)glColor3fv;
    }
    if (strcmp(name, "glColor3i") == 0) {
        return (void *)glColor3i;
    }
    if (strcmp(name, "glColor3iv") == 0) {
        return (void *)glColor3iv;
    }
    if (strcmp(name, "glColor3s") == 0) {
        return (void *)glColor3s;
    }
    if (strcmp(name, "glColor3sv") == 0) {
        return (void *)glColor3sv;
    }
    if (strcmp(name, "glColor3ub") == 0) {
        return (void *)glColor3ub;
    }
    if (strcmp(name, "glColor3ubv") == 0) {
        return (void *)glColor3ubv;
    }
    if (strcmp(name, "glColor3ui") == 0) {
        return (void *)glColor3ui;
    }
    if (strcmp(name, "glColor3uiv") == 0) {
        return (void *)glColor3uiv;
    }
    if (strcmp(name, "glColor3us") == 0) {
        return (void *)glColor3us;
    }
    if (strcmp(name, "glColor3usv") == 0) {
        return (void *)glColor3usv;
    }
    if (strcmp(name, "glColor4b") == 0) {
        return (void *)glColor4b;
    }
    if (strcmp(name, "glColor4bv") == 0) {
        return (void *)glColor4bv;
    }
    if (strcmp(name, "glColor4d") == 0) {
        return (void *)glColor4d;
    }
    if (strcmp(name, "glColor4dv") == 0) {
        return (void *)glColor4dv;
    }
    if (strcmp(name, "glColor4f") == 0) {
        return (void *)glColor4f;
    }
    if (strcmp(name, "glColor4fv") == 0) {
        return (void *)glColor4fv;
    }
    if (strcmp(name, "glColor4i") == 0) {
        return (void *)glColor4i;
    }
    if (strcmp(name, "glColor4iv") == 0) {
        return (void *)glColor4iv;
    }
    if (strcmp(name, "glColor4s") == 0) {
        return (void *)glColor4s;
    }
    if (strcmp(name, "glColor4sv") == 0) {
        return (void *)glColor4sv;
    }
    if (strcmp(name, "glColor4ub") == 0) {
        return (void *)glColor4ub;
    }
    if (strcmp(name, "glColor4ubv") == 0) {
        return (void *)glColor4ubv;
    }
    if (strcmp(name, "glColor4ui") == 0) {
        return (void *)glColor4ui;
    }
    if (strcmp(name, "glColor4uiv") == 0) {
        return (void *)glColor4uiv;
    }
    if (strcmp(name, "glColor4us") == 0) {
        return (void *)glColor4us;
    }
    if (strcmp(name, "glColor4usv") == 0) {
        return (void *)glColor4usv;
    }
    if (strcmp(name, "glColorMask") == 0) {
        return (void *)glColorMask;
    }
    if (strcmp(name, "glColorMaterial") == 0) {
        return (void *)glColorMaterial;
    }
    if (strcmp(name, "glColorPointer") == 0) {
        return (void *)glColorPointer;
    }
    if (strcmp(name, "glColorSubTable") == 0) {
        return (void *)glColorSubTable;
    }
    if (strcmp(name, "glColorTable") == 0) {
        return (void *)glColorTable;
    }
    if (strcmp(name, "glColorTableParameterfv") == 0) {
        return (void *)glColorTableParameterfv;
    }
    if (strcmp(name, "glColorTableParameteriv") == 0) {
        return (void *)glColorTableParameteriv;
    }
    if (strcmp(name, "glCompressedTexImage1D") == 0) {
        return (void *)glCompressedTexImage1D;
    }
    if (strcmp(name, "glCompressedTexImage2D") == 0) {
        return (void *)glCompressedTexImage2D;
    }
    if (strcmp(name, "glCompressedTexImage3D") == 0) {
        return (void *)glCompressedTexImage3D;
    }
    if (strcmp(name, "glCompressedTexSubImage1D") == 0) {
        return (void *)glCompressedTexSubImage1D;
    }
    if (strcmp(name, "glCompressedTexSubImage2D") == 0) {
        return (void *)glCompressedTexSubImage2D;
    }
    if (strcmp(name, "glCompressedTexSubImage3D") == 0) {
        return (void *)glCompressedTexSubImage3D;
    }
    if (strcmp(name, "glConvolutionFilter1D") == 0) {
        return (void *)glConvolutionFilter1D;
    }
    if (strcmp(name, "glConvolutionFilter2D") == 0) {
        return (void *)glConvolutionFilter2D;
    }
    if (strcmp(name, "glConvolutionParameterf") == 0) {
        return (void *)glConvolutionParameterf;
    }
    if (strcmp(name, "glConvolutionParameterfv") == 0) {
        return (void *)glConvolutionParameterfv;
    }
    if (strcmp(name, "glConvolutionParameteri") == 0) {
        return (void *)glConvolutionParameteri;
    }
    if (strcmp(name, "glConvolutionParameteriv") == 0) {
        return (void *)glConvolutionParameteriv;
    }
    if (strcmp(name, "glCopyColorSubTable") == 0) {
        return (void *)glCopyColorSubTable;
    }
    if (strcmp(name, "glCopyColorTable") == 0) {
        return (void *)glCopyColorTable;
    }
    if (strcmp(name, "glCopyConvolutionFilter1D") == 0) {
        return (void *)glCopyConvolutionFilter1D;
    }
    if (strcmp(name, "glCopyConvolutionFilter2D") == 0) {
        return (void *)glCopyConvolutionFilter2D;
    }
    if (strcmp(name, "glCopyPixels") == 0) {
        return (void *)glCopyPixels;
    }
    if (strcmp(name, "glCopyTexImage1D") == 0) {
        return (void *)glCopyTexImage1D;
    }
    if (strcmp(name, "glCopyTexImage2D") == 0) {
        return (void *)glCopyTexImage2D;
    }
    if (strcmp(name, "glCopyTexSubImage1D") == 0) {
        return (void *)glCopyTexSubImage1D;
    }
    if (strcmp(name, "glCopyTexSubImage2D") == 0) {
        return (void *)glCopyTexSubImage2D;
    }
    if (strcmp(name, "glCopyTexSubImage3D") == 0) {
        return (void *)glCopyTexSubImage3D;
    }
    if (strcmp(name, "glCullFace") == 0) {
        return (void *)glCullFace;
    }
    if (strcmp(name, "glDeleteBuffers") == 0) {
        return (void *)glDeleteBuffers;
    }
    if (strcmp(name, "glDeleteLists") == 0) {
        return (void *)glDeleteLists;
    }
    if (strcmp(name, "glDeleteQueries") == 0) {
        return (void *)glDeleteQueries;
    }
    if (strcmp(name, "glDeleteTextures") == 0) {
        return (void *)glDeleteTextures;
    }
    if (strcmp(name, "glDepthFunc") == 0) {
        return (void *)glDepthFunc;
    }
    if (strcmp(name, "glDepthMask") == 0) {
        return (void *)glDepthMask;
    }
    if (strcmp(name, "glDepthRange") == 0) {
        return (void *)glDepthRange;
    }
    if (strcmp(name, "glDisable") == 0) {
        return (void *)glDisable;
    }
    if (strcmp(name, "glDisableClientState") == 0) {
        return (void *)glDisableClientState;
    }
    if (strcmp(name, "glDrawArrays") == 0) {
        return (void *)glDrawArrays;
    }
    if (strcmp(name, "glDrawBuffer") == 0) {
        return (void *)glDrawBuffer;
    }
    if (strcmp(name, "glDrawElements") == 0) {
        return (void *)glDrawElements;
    }
    if (strcmp(name, "glDrawPixels") == 0) {
        return (void *)glDrawPixels;
    }
    if (strcmp(name, "glDrawRangeElements") == 0) {
        return (void *)glDrawRangeElements;
    }
    if (strcmp(name, "glEdgeFlag") == 0) {
        return (void *)glEdgeFlag;
    }
    if (strcmp(name, "glEdgeFlagPointer") == 0) {
        return (void *)glEdgeFlagPointer;
    }
    if (strcmp(name, "glEdgeFlagv") == 0) {
        return (void *)glEdgeFlagv;
    }
    if (strcmp(name, "glEnable") == 0) {
        return (void *)glEnable;
    }
    if (strcmp(name, "glEnableClientState") == 0) {
        return (void *)glEnableClientState;
    }
    if (strcmp(name, "glEnd") == 0) {
        return (void *)glEnd;
    }
    if (strcmp(name, "glEndList") == 0) {
        return (void *)glEndList;
    }
    if (strcmp(name, "glEndQuery") == 0) {
        return (void *)glEndQuery;
    }
    if (strcmp(name, "glEvalCoord1d") == 0) {
        return (void *)glEvalCoord1d;
    }
    if (strcmp(name, "glEvalCoord1dv") == 0) {
        return (void *)glEvalCoord1dv;
    }
    if (strcmp(name, "glEvalCoord1f") == 0) {
        return (void *)glEvalCoord1f;
    }
    if (strcmp(name, "glEvalCoord1fv") == 0) {
        return (void *)glEvalCoord1fv;
    }
    if (strcmp(name, "glEvalCoord2d") == 0) {
        return (void *)glEvalCoord2d;
    }
    if (strcmp(name, "glEvalCoord2dv") == 0) {
        return (void *)glEvalCoord2dv;
    }
    if (strcmp(name, "glEvalCoord2f") == 0) {
        return (void *)glEvalCoord2f;
    }
    if (strcmp(name, "glEvalCoord2fv") == 0) {
        return (void *)glEvalCoord2fv;
    }
    if (strcmp(name, "glEvalMesh1") == 0) {
        return (void *)glEvalMesh1;
    }
    if (strcmp(name, "glEvalMesh2") == 0) {
        return (void *)glEvalMesh2;
    }
    if (strcmp(name, "glEvalPoint1") == 0) {
        return (void *)glEvalPoint1;
    }
    if (strcmp(name, "glEvalPoint2") == 0) {
        return (void *)glEvalPoint2;
    }
    if (strcmp(name, "glFeedbackBuffer") == 0) {
        return (void *)glFeedbackBuffer;
    }
    if (strcmp(name, "glFinish") == 0) {
        return (void *)glFinish;
    }
    if (strcmp(name, "glFlush") == 0) {
        return (void *)glFlush;
    }
    if (strcmp(name, "glFogCoordPointer") == 0) {
        return (void *)glFogCoordPointer;
    }
    if (strcmp(name, "glFogCoordd") == 0) {
        return (void *)glFogCoordd;
    }
    if (strcmp(name, "glFogCoorddv") == 0) {
        return (void *)glFogCoorddv;
    }
    if (strcmp(name, "glFogCoordf") == 0) {
        return (void *)glFogCoordf;
    }
    if (strcmp(name, "glFogCoordfv") == 0) {
        return (void *)glFogCoordfv;
    }
    if (strcmp(name, "glFogf") == 0) {
        return (void *)glFogf;
    }
    if (strcmp(name, "glFogfv") == 0) {
        return (void *)glFogfv;
    }
    if (strcmp(name, "glFogi") == 0) {
        return (void *)glFogi;
    }
    if (strcmp(name, "glFogiv") == 0) {
        return (void *)glFogiv;
    }
    if (strcmp(name, "glFrontFace") == 0) {
        return (void *)glFrontFace;
    }
    if (strcmp(name, "glFrustum") == 0) {
        return (void *)glFrustum;
    }
    if (strcmp(name, "glGenBuffers") == 0) {
        return (void *)glGenBuffers;
    }
    if (strcmp(name, "glGenLists") == 0) {
        return (void *)glGenLists;
    }
    if (strcmp(name, "glGenQueries") == 0) {
        return (void *)glGenQueries;
    }
    if (strcmp(name, "glGenTextures") == 0) {
        return (void *)glGenTextures;
    }
    if (strcmp(name, "glGetBooleanv") == 0) {
        return (void *)glGetBooleanv;
    }
    if (strcmp(name, "glGetBufferParameteriv") == 0) {
        return (void *)glGetBufferParameteriv;
    }
    if (strcmp(name, "glGetBufferPointerv") == 0) {
        return (void *)glGetBufferPointerv;
    }
    if (strcmp(name, "glGetBufferSubData") == 0) {
        return (void *)glGetBufferSubData;
    }
    if (strcmp(name, "glGetClipPlane") == 0) {
        return (void *)glGetClipPlane;
    }
    if (strcmp(name, "glGetColorTable") == 0) {
        return (void *)glGetColorTable;
    }
    if (strcmp(name, "glGetColorTableParameterfv") == 0) {
        return (void *)glGetColorTableParameterfv;
    }
    if (strcmp(name, "glGetColorTableParameteriv") == 0) {
        return (void *)glGetColorTableParameteriv;
    }
    if (strcmp(name, "glGetCompressedTexImage") == 0) {
        return (void *)glGetCompressedTexImage;
    }
    if (strcmp(name, "glGetConvolutionFilter") == 0) {
        return (void *)glGetConvolutionFilter;
    }
    if (strcmp(name, "glGetConvolutionParameterfv") == 0) {
        return (void *)glGetConvolutionParameterfv;
    }
    if (strcmp(name, "glGetConvolutionParameteriv") == 0) {
        return (void *)glGetConvolutionParameteriv;
    }
    if (strcmp(name, "glGetDoublev") == 0) {
        return (void *)glGetDoublev;
    }
    if (strcmp(name, "glGetError") == 0) {
        return (void *)glGetError;
    }
    if (strcmp(name, "glGetFloatv") == 0) {
        return (void *)glGetFloatv;
    }
    if (strcmp(name, "glGetHistogram") == 0) {
        return (void *)glGetHistogram;
    }
    if (strcmp(name, "glGetHistogramParameterfv") == 0) {
        return (void *)glGetHistogramParameterfv;
    }
    if (strcmp(name, "glGetHistogramParameteriv") == 0) {
        return (void *)glGetHistogramParameteriv;
    }
    if (strcmp(name, "glGetIntegerv") == 0) {
        return (void *)glGetIntegerv;
    }
    if (strcmp(name, "glGetLightfv") == 0) {
        return (void *)glGetLightfv;
    }
    if (strcmp(name, "glGetLightiv") == 0) {
        return (void *)glGetLightiv;
    }
    if (strcmp(name, "glGetMapdv") == 0) {
        return (void *)glGetMapdv;
    }
    if (strcmp(name, "glGetMapfv") == 0) {
        return (void *)glGetMapfv;
    }
    if (strcmp(name, "glGetMapiv") == 0) {
        return (void *)glGetMapiv;
    }
    if (strcmp(name, "glGetMaterialfv") == 0) {
        return (void *)glGetMaterialfv;
    }
    if (strcmp(name, "glGetMaterialiv") == 0) {
        return (void *)glGetMaterialiv;
    }
    if (strcmp(name, "glGetMinmax") == 0) {
        return (void *)glGetMinmax;
    }
    if (strcmp(name, "glGetMinmaxParameterfv") == 0) {
        return (void *)glGetMinmaxParameterfv;
    }
    if (strcmp(name, "glGetMinmaxParameteriv") == 0) {
        return (void *)glGetMinmaxParameteriv;
    }
    if (strcmp(name, "glGetPixelMapfv") == 0) {
        return (void *)glGetPixelMapfv;
    }
    if (strcmp(name, "glGetPixelMapuiv") == 0) {
        return (void *)glGetPixelMapuiv;
    }
    if (strcmp(name, "glGetPixelMapusv") == 0) {
        return (void *)glGetPixelMapusv;
    }
    if (strcmp(name, "glGetPointerv") == 0) {
        return (void *)glGetPointerv;
    }
    if (strcmp(name, "glGetPolygonStipple") == 0) {
        return (void *)glGetPolygonStipple;
    }
    if (strcmp(name, "glGetQueryObjectiv") == 0) {
        return (void *)glGetQueryObjectiv;
    }
    if (strcmp(name, "glGetQueryObjectuiv") == 0) {
        return (void *)glGetQueryObjectuiv;
    }
    if (strcmp(name, "glGetQueryiv") == 0) {
        return (void *)glGetQueryiv;
    }
    if (strcmp(name, "glGetSeparableFilter") == 0) {
        return (void *)glGetSeparableFilter;
    }
    if (strcmp(name, "glGetString") == 0) {
        return (void *)glGetString;
    }
    if (strcmp(name, "glGetTexEnvfv") == 0) {
        return (void *)glGetTexEnvfv;
    }
    if (strcmp(name, "glGetTexEnviv") == 0) {
        return (void *)glGetTexEnviv;
    }
    if (strcmp(name, "glGetTexGendv") == 0) {
        return (void *)glGetTexGendv;
    }
    if (strcmp(name, "glGetTexGenfv") == 0) {
        return (void *)glGetTexGenfv;
    }
    if (strcmp(name, "glGetTexGeniv") == 0) {
        return (void *)glGetTexGeniv;
    }
    if (strcmp(name, "glGetTexImage") == 0) {
        return (void *)glGetTexImage;
    }
    if (strcmp(name, "glGetTexLevelParameterfv") == 0) {
        return (void *)glGetTexLevelParameterfv;
    }
    if (strcmp(name, "glGetTexLevelParameteriv") == 0) {
        return (void *)glGetTexLevelParameteriv;
    }
    if (strcmp(name, "glGetTexParameterfv") == 0) {
        return (void *)glGetTexParameterfv;
    }
    if (strcmp(name, "glGetTexParameteriv") == 0) {
        return (void *)glGetTexParameteriv;
    }
    if (strcmp(name, "glHint") == 0) {
        return (void *)glHint;
    }
    if (strcmp(name, "glHistogram") == 0) {
        return (void *)glHistogram;
    }
    if (strcmp(name, "glIndexMask") == 0) {
        return (void *)glIndexMask;
    }
    if (strcmp(name, "glIndexPointer") == 0) {
        return (void *)glIndexPointer;
    }
    if (strcmp(name, "glIndexd") == 0) {
        return (void *)glIndexd;
    }
    if (strcmp(name, "glIndexdv") == 0) {
        return (void *)glIndexdv;
    }
    if (strcmp(name, "glIndexf") == 0) {
        return (void *)glIndexf;
    }
    if (strcmp(name, "glIndexfv") == 0) {
        return (void *)glIndexfv;
    }
    if (strcmp(name, "glIndexi") == 0) {
        return (void *)glIndexi;
    }
    if (strcmp(name, "glIndexiv") == 0) {
        return (void *)glIndexiv;
    }
    if (strcmp(name, "glIndexs") == 0) {
        return (void *)glIndexs;
    }
    if (strcmp(name, "glIndexsv") == 0) {
        return (void *)glIndexsv;
    }
    if (strcmp(name, "glIndexub") == 0) {
        return (void *)glIndexub;
    }
    if (strcmp(name, "glIndexubv") == 0) {
        return (void *)glIndexubv;
    }
    if (strcmp(name, "glInitNames") == 0) {
        return (void *)glInitNames;
    }
    if (strcmp(name, "glInterleavedArrays") == 0) {
        return (void *)glInterleavedArrays;
    }
    if (strcmp(name, "glIsBuffer") == 0) {
        return (void *)glIsBuffer;
    }
    if (strcmp(name, "glIsEnabled") == 0) {
        return (void *)glIsEnabled;
    }
    if (strcmp(name, "glIsList") == 0) {
        return (void *)glIsList;
    }
    if (strcmp(name, "glIsQuery") == 0) {
        return (void *)glIsQuery;
    }
    if (strcmp(name, "glIsTexture") == 0) {
        return (void *)glIsTexture;
    }
    if (strcmp(name, "glLightModelf") == 0) {
        return (void *)glLightModelf;
    }
    if (strcmp(name, "glLightModelfv") == 0) {
        return (void *)glLightModelfv;
    }
    if (strcmp(name, "glLightModeli") == 0) {
        return (void *)glLightModeli;
    }
    if (strcmp(name, "glLightModeliv") == 0) {
        return (void *)glLightModeliv;
    }
    if (strcmp(name, "glLightf") == 0) {
        return (void *)glLightf;
    }
    if (strcmp(name, "glLightfv") == 0) {
        return (void *)glLightfv;
    }
    if (strcmp(name, "glLighti") == 0) {
        return (void *)glLighti;
    }
    if (strcmp(name, "glLightiv") == 0) {
        return (void *)glLightiv;
    }
    if (strcmp(name, "glLineStipple") == 0) {
        return (void *)glLineStipple;
    }
    if (strcmp(name, "glLineWidth") == 0) {
        return (void *)glLineWidth;
    }
    if (strcmp(name, "glListBase") == 0) {
        return (void *)glListBase;
    }
    if (strcmp(name, "glLoadIdentity") == 0) {
        return (void *)glLoadIdentity;
    }
    if (strcmp(name, "glLoadMatrixd") == 0) {
        return (void *)glLoadMatrixd;
    }
    if (strcmp(name, "glLoadMatrixf") == 0) {
        return (void *)glLoadMatrixf;
    }
    if (strcmp(name, "glLoadName") == 0) {
        return (void *)glLoadName;
    }
    if (strcmp(name, "glLoadTransposeMatrixd") == 0) {
        return (void *)glLoadTransposeMatrixd;
    }
    if (strcmp(name, "glLoadTransposeMatrixf") == 0) {
        return (void *)glLoadTransposeMatrixf;
    }
    if (strcmp(name, "glLogicOp") == 0) {
        return (void *)glLogicOp;
    }
    if (strcmp(name, "glMap1d") == 0) {
        return (void *)glMap1d;
    }
    if (strcmp(name, "glMap1f") == 0) {
        return (void *)glMap1f;
    }
    if (strcmp(name, "glMap2d") == 0) {
        return (void *)glMap2d;
    }
    if (strcmp(name, "glMap2f") == 0) {
        return (void *)glMap2f;
    }
    if (strcmp(name, "glMapBuffer") == 0) {
        return (void *)glMapBuffer;
    }
    if (strcmp(name, "glMapGrid1d") == 0) {
        return (void *)glMapGrid1d;
    }
    if (strcmp(name, "glMapGrid1f") == 0) {
        return (void *)glMapGrid1f;
    }
    if (strcmp(name, "glMapGrid2d") == 0) {
        return (void *)glMapGrid2d;
    }
    if (strcmp(name, "glMapGrid2f") == 0) {
        return (void *)glMapGrid2f;
    }
    if (strcmp(name, "glMaterialf") == 0) {
        return (void *)glMaterialf;
    }
    if (strcmp(name, "glMaterialfv") == 0) {
        return (void *)glMaterialfv;
    }
    if (strcmp(name, "glMateriali") == 0) {
        return (void *)glMateriali;
    }
    if (strcmp(name, "glMaterialiv") == 0) {
        return (void *)glMaterialiv;
    }
    if (strcmp(name, "glMatrixMode") == 0) {
        return (void *)glMatrixMode;
    }
    if (strcmp(name, "glMinmax") == 0) {
        return (void *)glMinmax;
    }
    if (strcmp(name, "glMultMatrixd") == 0) {
        return (void *)glMultMatrixd;
    }
    if (strcmp(name, "glMultMatrixf") == 0) {
        return (void *)glMultMatrixf;
    }
    if (strcmp(name, "glMultTransposeMatrixd") == 0) {
        return (void *)glMultTransposeMatrixd;
    }
    if (strcmp(name, "glMultTransposeMatrixf") == 0) {
        return (void *)glMultTransposeMatrixf;
    }
    if (strcmp(name, "glMultiDrawArrays") == 0) {
        return (void *)glMultiDrawArrays;
    }
    if (strcmp(name, "glMultiDrawElements") == 0) {
        return (void *)glMultiDrawElements;
    }
    if (strcmp(name, "glMultiTexCoord1d") == 0) {
        return (void *)glMultiTexCoord1d;
    }
    if (strcmp(name, "glMultiTexCoord1dv") == 0) {
        return (void *)glMultiTexCoord1dv;
    }
    if (strcmp(name, "glMultiTexCoord1f") == 0) {
        return (void *)glMultiTexCoord1f;
    }
    if (strcmp(name, "glMultiTexCoord1fv") == 0) {
        return (void *)glMultiTexCoord1fv;
    }
    if (strcmp(name, "glMultiTexCoord1i") == 0) {
        return (void *)glMultiTexCoord1i;
    }
    if (strcmp(name, "glMultiTexCoord1iv") == 0) {
        return (void *)glMultiTexCoord1iv;
    }
    if (strcmp(name, "glMultiTexCoord1s") == 0) {
        return (void *)glMultiTexCoord1s;
    }
    if (strcmp(name, "glMultiTexCoord1sv") == 0) {
        return (void *)glMultiTexCoord1sv;
    }
    if (strcmp(name, "glMultiTexCoord2d") == 0) {
        return (void *)glMultiTexCoord2d;
    }
    if (strcmp(name, "glMultiTexCoord2dv") == 0) {
        return (void *)glMultiTexCoord2dv;
    }
    if (strcmp(name, "glMultiTexCoord2f") == 0) {
        return (void *)glMultiTexCoord2f;
    }
    if (strcmp(name, "glMultiTexCoord2fv") == 0) {
        return (void *)glMultiTexCoord2fv;
    }
    if (strcmp(name, "glMultiTexCoord2i") == 0) {
        return (void *)glMultiTexCoord2i;
    }
    if (strcmp(name, "glMultiTexCoord2iv") == 0) {
        return (void *)glMultiTexCoord2iv;
    }
    if (strcmp(name, "glMultiTexCoord2s") == 0) {
        return (void *)glMultiTexCoord2s;
    }
    if (strcmp(name, "glMultiTexCoord2sv") == 0) {
        return (void *)glMultiTexCoord2sv;
    }
    if (strcmp(name, "glMultiTexCoord3d") == 0) {
        return (void *)glMultiTexCoord3d;
    }
    if (strcmp(name, "glMultiTexCoord3dv") == 0) {
        return (void *)glMultiTexCoord3dv;
    }
    if (strcmp(name, "glMultiTexCoord3f") == 0) {
        return (void *)glMultiTexCoord3f;
    }
    if (strcmp(name, "glMultiTexCoord3fv") == 0) {
        return (void *)glMultiTexCoord3fv;
    }
    if (strcmp(name, "glMultiTexCoord3i") == 0) {
        return (void *)glMultiTexCoord3i;
    }
    if (strcmp(name, "glMultiTexCoord3iv") == 0) {
        return (void *)glMultiTexCoord3iv;
    }
    if (strcmp(name, "glMultiTexCoord3s") == 0) {
        return (void *)glMultiTexCoord3s;
    }
    if (strcmp(name, "glMultiTexCoord3sv") == 0) {
        return (void *)glMultiTexCoord3sv;
    }
    if (strcmp(name, "glMultiTexCoord4d") == 0) {
        return (void *)glMultiTexCoord4d;
    }
    if (strcmp(name, "glMultiTexCoord4dv") == 0) {
        return (void *)glMultiTexCoord4dv;
    }
    if (strcmp(name, "glMultiTexCoord4f") == 0) {
        return (void *)glMultiTexCoord4f;
    }
    if (strcmp(name, "glMultiTexCoord4fv") == 0) {
        return (void *)glMultiTexCoord4fv;
    }
    if (strcmp(name, "glMultiTexCoord4i") == 0) {
        return (void *)glMultiTexCoord4i;
    }
    if (strcmp(name, "glMultiTexCoord4iv") == 0) {
        return (void *)glMultiTexCoord4iv;
    }
    if (strcmp(name, "glMultiTexCoord4s") == 0) {
        return (void *)glMultiTexCoord4s;
    }
    if (strcmp(name, "glMultiTexCoord4sv") == 0) {
        return (void *)glMultiTexCoord4sv;
    }
    if (strcmp(name, "glNewList") == 0) {
        return (void *)glNewList;
    }
    if (strcmp(name, "glNormal3b") == 0) {
        return (void *)glNormal3b;
    }
    if (strcmp(name, "glNormal3bv") == 0) {
        return (void *)glNormal3bv;
    }
    if (strcmp(name, "glNormal3d") == 0) {
        return (void *)glNormal3d;
    }
    if (strcmp(name, "glNormal3dv") == 0) {
        return (void *)glNormal3dv;
    }
    if (strcmp(name, "glNormal3f") == 0) {
        return (void *)glNormal3f;
    }
    if (strcmp(name, "glNormal3fv") == 0) {
        return (void *)glNormal3fv;
    }
    if (strcmp(name, "glNormal3i") == 0) {
        return (void *)glNormal3i;
    }
    if (strcmp(name, "glNormal3iv") == 0) {
        return (void *)glNormal3iv;
    }
    if (strcmp(name, "glNormal3s") == 0) {
        return (void *)glNormal3s;
    }
    if (strcmp(name, "glNormal3sv") == 0) {
        return (void *)glNormal3sv;
    }
    if (strcmp(name, "glNormalPointer") == 0) {
        return (void *)glNormalPointer;
    }
    if (strcmp(name, "glOrtho") == 0) {
        return (void *)glOrtho;
    }
    if (strcmp(name, "glPassThrough") == 0) {
        return (void *)glPassThrough;
    }
    if (strcmp(name, "glPixelMapfv") == 0) {
        return (void *)glPixelMapfv;
    }
    if (strcmp(name, "glPixelMapuiv") == 0) {
        return (void *)glPixelMapuiv;
    }
    if (strcmp(name, "glPixelMapusv") == 0) {
        return (void *)glPixelMapusv;
    }
    if (strcmp(name, "glPixelStoref") == 0) {
        return (void *)glPixelStoref;
    }
    if (strcmp(name, "glPixelStorei") == 0) {
        return (void *)glPixelStorei;
    }
    if (strcmp(name, "glPixelTransferf") == 0) {
        return (void *)glPixelTransferf;
    }
    if (strcmp(name, "glPixelTransferi") == 0) {
        return (void *)glPixelTransferi;
    }
    if (strcmp(name, "glPixelZoom") == 0) {
        return (void *)glPixelZoom;
    }
    if (strcmp(name, "glPointParameterf") == 0) {
        return (void *)glPointParameterf;
    }
    if (strcmp(name, "glPointParameterfv") == 0) {
        return (void *)glPointParameterfv;
    }
    if (strcmp(name, "glPointParameteri") == 0) {
        return (void *)glPointParameteri;
    }
    if (strcmp(name, "glPointParameteriv") == 0) {
        return (void *)glPointParameteriv;
    }
    if (strcmp(name, "glPointSize") == 0) {
        return (void *)glPointSize;
    }
    if (strcmp(name, "glPolygonMode") == 0) {
        return (void *)glPolygonMode;
    }
    if (strcmp(name, "glPolygonOffset") == 0) {
        return (void *)glPolygonOffset;
    }
    if (strcmp(name, "glPolygonStipple") == 0) {
        return (void *)glPolygonStipple;
    }
    if (strcmp(name, "glPopAttrib") == 0) {
        return (void *)glPopAttrib;
    }
    if (strcmp(name, "glPopClientAttrib") == 0) {
        return (void *)glPopClientAttrib;
    }
    if (strcmp(name, "glPopMatrix") == 0) {
        return (void *)glPopMatrix;
    }
    if (strcmp(name, "glPopName") == 0) {
        return (void *)glPopName;
    }
    if (strcmp(name, "glPrioritizeTextures") == 0) {
        return (void *)glPrioritizeTextures;
    }
    if (strcmp(name, "glPushAttrib") == 0) {
        return (void *)glPushAttrib;
    }
    if (strcmp(name, "glPushClientAttrib") == 0) {
        return (void *)glPushClientAttrib;
    }
    if (strcmp(name, "glPushMatrix") == 0) {
        return (void *)glPushMatrix;
    }
    if (strcmp(name, "glPushName") == 0) {
        return (void *)glPushName;
    }
    if (strcmp(name, "glRasterPos2d") == 0) {
        return (void *)glRasterPos2d;
    }
    if (strcmp(name, "glRasterPos2dv") == 0) {
        return (void *)glRasterPos2dv;
    }
    if (strcmp(name, "glRasterPos2f") == 0) {
        return (void *)glRasterPos2f;
    }
    if (strcmp(name, "glRasterPos2fv") == 0) {
        return (void *)glRasterPos2fv;
    }
    if (strcmp(name, "glRasterPos2i") == 0) {
        return (void *)glRasterPos2i;
    }
    if (strcmp(name, "glRasterPos2iv") == 0) {
        return (void *)glRasterPos2iv;
    }
    if (strcmp(name, "glRasterPos2s") == 0) {
        return (void *)glRasterPos2s;
    }
    if (strcmp(name, "glRasterPos2sv") == 0) {
        return (void *)glRasterPos2sv;
    }
    if (strcmp(name, "glRasterPos3d") == 0) {
        return (void *)glRasterPos3d;
    }
    if (strcmp(name, "glRasterPos3dv") == 0) {
        return (void *)glRasterPos3dv;
    }
    if (strcmp(name, "glRasterPos3f") == 0) {
        return (void *)glRasterPos3f;
    }
    if (strcmp(name, "glRasterPos3fv") == 0) {
        return (void *)glRasterPos3fv;
    }
    if (strcmp(name, "glRasterPos3i") == 0) {
        return (void *)glRasterPos3i;
    }
    if (strcmp(name, "glRasterPos3iv") == 0) {
        return (void *)glRasterPos3iv;
    }
    if (strcmp(name, "glRasterPos3s") == 0) {
        return (void *)glRasterPos3s;
    }
    if (strcmp(name, "glRasterPos3sv") == 0) {
        return (void *)glRasterPos3sv;
    }
    if (strcmp(name, "glRasterPos4d") == 0) {
        return (void *)glRasterPos4d;
    }
    if (strcmp(name, "glRasterPos4dv") == 0) {
        return (void *)glRasterPos4dv;
    }
    if (strcmp(name, "glRasterPos4f") == 0) {
        return (void *)glRasterPos4f;
    }
    if (strcmp(name, "glRasterPos4fv") == 0) {
        return (void *)glRasterPos4fv;
    }
    if (strcmp(name, "glRasterPos4i") == 0) {
        return (void *)glRasterPos4i;
    }
    if (strcmp(name, "glRasterPos4iv") == 0) {
        return (void *)glRasterPos4iv;
    }
    if (strcmp(name, "glRasterPos4s") == 0) {
        return (void *)glRasterPos4s;
    }
    if (strcmp(name, "glRasterPos4sv") == 0) {
        return (void *)glRasterPos4sv;
    }
    if (strcmp(name, "glReadBuffer") == 0) {
        return (void *)glReadBuffer;
    }
    if (strcmp(name, "glReadPixels") == 0) {
        return (void *)glReadPixels;
    }
    if (strcmp(name, "glRectd") == 0) {
        return (void *)glRectd;
    }
    if (strcmp(name, "glRectdv") == 0) {
        return (void *)glRectdv;
    }
    if (strcmp(name, "glRectf") == 0) {
        return (void *)glRectf;
    }
    if (strcmp(name, "glRectfv") == 0) {
        return (void *)glRectfv;
    }
    if (strcmp(name, "glRecti") == 0) {
        return (void *)glRecti;
    }
    if (strcmp(name, "glRectiv") == 0) {
        return (void *)glRectiv;
    }
    if (strcmp(name, "glRects") == 0) {
        return (void *)glRects;
    }
    if (strcmp(name, "glRectsv") == 0) {
        return (void *)glRectsv;
    }
    if (strcmp(name, "glRenderMode") == 0) {
        return (void *)glRenderMode;
    }
    if (strcmp(name, "glResetHistogram") == 0) {
        return (void *)glResetHistogram;
    }
    if (strcmp(name, "glResetMinmax") == 0) {
        return (void *)glResetMinmax;
    }
    if (strcmp(name, "glRotated") == 0) {
        return (void *)glRotated;
    }
    if (strcmp(name, "glRotatef") == 0) {
        return (void *)glRotatef;
    }
    if (strcmp(name, "glSampleCoverage") == 0) {
        return (void *)glSampleCoverage;
    }
    if (strcmp(name, "glScaled") == 0) {
        return (void *)glScaled;
    }
    if (strcmp(name, "glScalef") == 0) {
        return (void *)glScalef;
    }
    if (strcmp(name, "glScissor") == 0) {
        return (void *)glScissor;
    }
    if (strcmp(name, "glSecondaryColor3b") == 0) {
        return (void *)glSecondaryColor3b;
    }
    if (strcmp(name, "glSecondaryColor3bv") == 0) {
        return (void *)glSecondaryColor3bv;
    }
    if (strcmp(name, "glSecondaryColor3d") == 0) {
        return (void *)glSecondaryColor3d;
    }
    if (strcmp(name, "glSecondaryColor3dv") == 0) {
        return (void *)glSecondaryColor3dv;
    }
    if (strcmp(name, "glSecondaryColor3f") == 0) {
        return (void *)glSecondaryColor3f;
    }
    if (strcmp(name, "glSecondaryColor3fv") == 0) {
        return (void *)glSecondaryColor3fv;
    }
    if (strcmp(name, "glSecondaryColor3i") == 0) {
        return (void *)glSecondaryColor3i;
    }
    if (strcmp(name, "glSecondaryColor3iv") == 0) {
        return (void *)glSecondaryColor3iv;
    }
    if (strcmp(name, "glSecondaryColor3s") == 0) {
        return (void *)glSecondaryColor3s;
    }
    if (strcmp(name, "glSecondaryColor3sv") == 0) {
        return (void *)glSecondaryColor3sv;
    }
    if (strcmp(name, "glSecondaryColor3ub") == 0) {
        return (void *)glSecondaryColor3ub;
    }
    if (strcmp(name, "glSecondaryColor3ubv") == 0) {
        return (void *)glSecondaryColor3ubv;
    }
    if (strcmp(name, "glSecondaryColor3ui") == 0) {
        return (void *)glSecondaryColor3ui;
    }
    if (strcmp(name, "glSecondaryColor3uiv") == 0) {
        return (void *)glSecondaryColor3uiv;
    }
    if (strcmp(name, "glSecondaryColor3us") == 0) {
        return (void *)glSecondaryColor3us;
    }
    if (strcmp(name, "glSecondaryColor3usv") == 0) {
        return (void *)glSecondaryColor3usv;
    }
    if (strcmp(name, "glSecondaryColorPointer") == 0) {
        return (void *)glSecondaryColorPointer;
    }
    if (strcmp(name, "glSelectBuffer") == 0) {
        return (void *)glSelectBuffer;
    }
    if (strcmp(name, "glSeparableFilter2D") == 0) {
        return (void *)glSeparableFilter2D;
    }
    if (strcmp(name, "glShadeModel") == 0) {
        return (void *)glShadeModel;
    }
    if (strcmp(name, "glStencilFunc") == 0) {
        return (void *)glStencilFunc;
    }
    if (strcmp(name, "glStencilMask") == 0) {
        return (void *)glStencilMask;
    }
    if (strcmp(name, "glStencilOp") == 0) {
        return (void *)glStencilOp;
    }
    if (strcmp(name, "glTexCoord1d") == 0) {
        return (void *)glTexCoord1d;
    }
    if (strcmp(name, "glTexCoord1dv") == 0) {
        return (void *)glTexCoord1dv;
    }
    if (strcmp(name, "glTexCoord1f") == 0) {
        return (void *)glTexCoord1f;
    }
    if (strcmp(name, "glTexCoord1fv") == 0) {
        return (void *)glTexCoord1fv;
    }
    if (strcmp(name, "glTexCoord1i") == 0) {
        return (void *)glTexCoord1i;
    }
    if (strcmp(name, "glTexCoord1iv") == 0) {
        return (void *)glTexCoord1iv;
    }
    if (strcmp(name, "glTexCoord1s") == 0) {
        return (void *)glTexCoord1s;
    }
    if (strcmp(name, "glTexCoord1sv") == 0) {
        return (void *)glTexCoord1sv;
    }
    if (strcmp(name, "glTexCoord2d") == 0) {
        return (void *)glTexCoord2d;
    }
    if (strcmp(name, "glTexCoord2dv") == 0) {
        return (void *)glTexCoord2dv;
    }
    if (strcmp(name, "glTexCoord2f") == 0) {
        return (void *)glTexCoord2f;
    }
    if (strcmp(name, "glTexCoord2fv") == 0) {
        return (void *)glTexCoord2fv;
    }
    if (strcmp(name, "glTexCoord2i") == 0) {
        return (void *)glTexCoord2i;
    }
    if (strcmp(name, "glTexCoord2iv") == 0) {
        return (void *)glTexCoord2iv;
    }
    if (strcmp(name, "glTexCoord2s") == 0) {
        return (void *)glTexCoord2s;
    }
    if (strcmp(name, "glTexCoord2sv") == 0) {
        return (void *)glTexCoord2sv;
    }
    if (strcmp(name, "glTexCoord3d") == 0) {
        return (void *)glTexCoord3d;
    }
    if (strcmp(name, "glTexCoord3dv") == 0) {
        return (void *)glTexCoord3dv;
    }
    if (strcmp(name, "glTexCoord3f") == 0) {
        return (void *)glTexCoord3f;
    }
    if (strcmp(name, "glTexCoord3fv") == 0) {
        return (void *)glTexCoord3fv;
    }
    if (strcmp(name, "glTexCoord3i") == 0) {
        return (void *)glTexCoord3i;
    }
    if (strcmp(name, "glTexCoord3iv") == 0) {
        return (void *)glTexCoord3iv;
    }
    if (strcmp(name, "glTexCoord3s") == 0) {
        return (void *)glTexCoord3s;
    }
    if (strcmp(name, "glTexCoord3sv") == 0) {
        return (void *)glTexCoord3sv;
    }
    if (strcmp(name, "glTexCoord4d") == 0) {
        return (void *)glTexCoord4d;
    }
    if (strcmp(name, "glTexCoord4dv") == 0) {
        return (void *)glTexCoord4dv;
    }
    if (strcmp(name, "glTexCoord4f") == 0) {
        return (void *)glTexCoord4f;
    }
    if (strcmp(name, "glTexCoord4fv") == 0) {
        return (void *)glTexCoord4fv;
    }
    if (strcmp(name, "glTexCoord4i") == 0) {
        return (void *)glTexCoord4i;
    }
    if (strcmp(name, "glTexCoord4iv") == 0) {
        return (void *)glTexCoord4iv;
    }
    if (strcmp(name, "glTexCoord4s") == 0) {
        return (void *)glTexCoord4s;
    }
    if (strcmp(name, "glTexCoord4sv") == 0) {
        return (void *)glTexCoord4sv;
    }
    if (strcmp(name, "glTexCoordPointer") == 0) {
        return (void *)glTexCoordPointer;
    }
    if (strcmp(name, "glTexEnvf") == 0) {
        return (void *)glTexEnvf;
    }
    if (strcmp(name, "glTexEnvfv") == 0) {
        return (void *)glTexEnvfv;
    }
    if (strcmp(name, "glTexEnvi") == 0) {
        return (void *)glTexEnvi;
    }
    if (strcmp(name, "glTexEnviv") == 0) {
        return (void *)glTexEnviv;
    }
    if (strcmp(name, "glTexGend") == 0) {
        return (void *)glTexGend;
    }
    if (strcmp(name, "glTexGendv") == 0) {
        return (void *)glTexGendv;
    }
    if (strcmp(name, "glTexGenf") == 0) {
        return (void *)glTexGenf;
    }
    if (strcmp(name, "glTexGenfv") == 0) {
        return (void *)glTexGenfv;
    }
    if (strcmp(name, "glTexGeni") == 0) {
        return (void *)glTexGeni;
    }
    if (strcmp(name, "glTexGeniv") == 0) {
        return (void *)glTexGeniv;
    }
    if (strcmp(name, "glTexImage1D") == 0) {
        return (void *)glTexImage1D;
    }
    if (strcmp(name, "glTexImage2D") == 0) {
        return (void *)glTexImage2D;
    }
    if (strcmp(name, "glTexImage3D") == 0) {
        return (void *)glTexImage3D;
    }
    if (strcmp(name, "glTexParameterf") == 0) {
        return (void *)glTexParameterf;
    }
    if (strcmp(name, "glTexParameterfv") == 0) {
        return (void *)glTexParameterfv;
    }
    if (strcmp(name, "glTexParameteri") == 0) {
        return (void *)glTexParameteri;
    }
    if (strcmp(name, "glTexParameteriv") == 0) {
        return (void *)glTexParameteriv;
    }
    if (strcmp(name, "glTexSubImage1D") == 0) {
        return (void *)glTexSubImage1D;
    }
    if (strcmp(name, "glTexSubImage2D") == 0) {
        return (void *)glTexSubImage2D;
    }
    if (strcmp(name, "glTexSubImage3D") == 0) {
        return (void *)glTexSubImage3D;
    }
    if (strcmp(name, "glTranslated") == 0) {
        return (void *)glTranslated;
    }
    if (strcmp(name, "glTranslatef") == 0) {
        return (void *)glTranslatef;
    }
    if (strcmp(name, "glUnmapBuffer") == 0) {
        return (void *)glUnmapBuffer;
    }
    if (strcmp(name, "glVertex2d") == 0) {
        return (void *)glVertex2d;
    }
    if (strcmp(name, "glVertex2dv") == 0) {
        return (void *)glVertex2dv;
    }
    if (strcmp(name, "glVertex2f") == 0) {
        return (void *)glVertex2f;
    }
    if (strcmp(name, "glVertex2fv") == 0) {
        return (void *)glVertex2fv;
    }
    if (strcmp(name, "glVertex2i") == 0) {
        return (void *)glVertex2i;
    }
    if (strcmp(name, "glVertex2iv") == 0) {
        return (void *)glVertex2iv;
    }
    if (strcmp(name, "glVertex2s") == 0) {
        return (void *)glVertex2s;
    }
    if (strcmp(name, "glVertex2sv") == 0) {
        return (void *)glVertex2sv;
    }
    if (strcmp(name, "glVertex3d") == 0) {
        return (void *)glVertex3d;
    }
    if (strcmp(name, "glVertex3dv") == 0) {
        return (void *)glVertex3dv;
    }
    if (strcmp(name, "glVertex3f") == 0) {
        return (void *)glVertex3f;
    }
    if (strcmp(name, "glVertex3fv") == 0) {
        return (void *)glVertex3fv;
    }
    if (strcmp(name, "glVertex3i") == 0) {
        return (void *)glVertex3i;
    }
    if (strcmp(name, "glVertex3iv") == 0) {
        return (void *)glVertex3iv;
    }
    if (strcmp(name, "glVertex3s") == 0) {
        return (void *)glVertex3s;
    }
    if (strcmp(name, "glVertex3sv") == 0) {
        return (void *)glVertex3sv;
    }
    if (strcmp(name, "glVertex4d") == 0) {
        return (void *)glVertex4d;
    }
    if (strcmp(name, "glVertex4dv") == 0) {
        return (void *)glVertex4dv;
    }
    if (strcmp(name, "glVertex4f") == 0) {
        return (void *)glVertex4f;
    }
    if (strcmp(name, "glVertex4fv") == 0) {
        return (void *)glVertex4fv;
    }
    if (strcmp(name, "glVertex4i") == 0) {
        return (void *)glVertex4i;
    }
    if (strcmp(name, "glVertex4iv") == 0) {
        return (void *)glVertex4iv;
    }
    if (strcmp(name, "glVertex4s") == 0) {
        return (void *)glVertex4s;
    }
    if (strcmp(name, "glVertex4sv") == 0) {
        return (void *)glVertex4sv;
    }
    if (strcmp(name, "glVertexPointer") == 0) {
        return (void *)glVertexPointer;
    }
    if (strcmp(name, "glViewport") == 0) {
        return (void *)glViewport;
    }
    if (strcmp(name, "glWindowPos2d") == 0) {
        return (void *)glWindowPos2d;
    }
    if (strcmp(name, "glWindowPos2dv") == 0) {
        return (void *)glWindowPos2dv;
    }
    if (strcmp(name, "glWindowPos2f") == 0) {
        return (void *)glWindowPos2f;
    }
    if (strcmp(name, "glWindowPos2fv") == 0) {
        return (void *)glWindowPos2fv;
    }
    if (strcmp(name, "glWindowPos2i") == 0) {
        return (void *)glWindowPos2i;
    }
    if (strcmp(name, "glWindowPos2iv") == 0) {
        return (void *)glWindowPos2iv;
    }
    if (strcmp(name, "glWindowPos2s") == 0) {
        return (void *)glWindowPos2s;
    }
    if (strcmp(name, "glWindowPos2sv") == 0) {
        return (void *)glWindowPos2sv;
    }
    if (strcmp(name, "glWindowPos3d") == 0) {
        return (void *)glWindowPos3d;
    }
    if (strcmp(name, "glWindowPos3dv") == 0) {
        return (void *)glWindowPos3dv;
    }
    if (strcmp(name, "glWindowPos3f") == 0) {
        return (void *)glWindowPos3f;
    }
    if (strcmp(name, "glWindowPos3fv") == 0) {
        return (void *)glWindowPos3fv;
    }
    if (strcmp(name, "glWindowPos3i") == 0) {
        return (void *)glWindowPos3i;
    }
    if (strcmp(name, "glWindowPos3iv") == 0) {
        return (void *)glWindowPos3iv;
    }
    if (strcmp(name, "glWindowPos3s") == 0) {
        return (void *)glWindowPos3s;
    }
    if (strcmp(name, "glWindowPos3sv") == 0) {
        return (void *)glWindowPos3sv;
    }
    if (strcmp(name, "glXBindHyperpipeSGIX") == 0) {
        return (void *)glXBindHyperpipeSGIX;
    }
    if (strcmp(name, "glXBindSwapBarrierSGIX") == 0) {
        return (void *)glXBindSwapBarrierSGIX;
    }
    if (strcmp(name, "glXChangeDrawableAttributes") == 0) {
        return (void *)glXChangeDrawableAttributes;
    }
    if (strcmp(name, "glXChangeDrawableAttributesSGIX") == 0) {
        return (void *)glXChangeDrawableAttributesSGIX;
    }
    if (strcmp(name, "glXChooseFBConfig") == 0) {
        return (void *)glXChooseFBConfig;
    }
    if (strcmp(name, "glXChooseVisual") == 0) {
        return (void *)glXChooseVisual;
    }
    if (strcmp(name, "glXClientInfo") == 0) {
        return (void *)glXClientInfo;
    }
    if (strcmp(name, "glXCopyContext") == 0) {
        return (void *)glXCopyContext;
    }
    if (strcmp(name, "glXCreateContext") == 0) {
        return (void *)glXCreateContext;
    }
    if (strcmp(name, "glXCreateContextAttribsARB") == 0) {
        return (void *)glXCreateContextAttribsARB;
    }
    if (strcmp(name, "glXCreateContextWithConfigSGIX") == 0) {
        return (void *)glXCreateContextWithConfigSGIX;
    }
    if (strcmp(name, "glXCreateGLXPbufferSGIX") == 0) {
        return (void *)glXCreateGLXPbufferSGIX;
    }
    if (strcmp(name, "glXCreateGLXPixmap") == 0) {
        return (void *)glXCreateGLXPixmap;
    }
    if (strcmp(name, "glXCreateGLXPixmapWithConfigSGIX") == 0) {
        return (void *)glXCreateGLXPixmapWithConfigSGIX;
    }
    if (strcmp(name, "glXCreateGLXVideoSourceSGIX") == 0) {
        return (void *)glXCreateGLXVideoSourceSGIX;
    }
    if (strcmp(name, "glXCreateNewContext") == 0) {
        return (void *)glXCreateNewContext;
    }
    if (strcmp(name, "glXCreatePbuffer") == 0) {
        return (void *)glXCreatePbuffer;
    }
    if (strcmp(name, "glXCreatePixmap") == 0) {
        return (void *)glXCreatePixmap;
    }
    if (strcmp(name, "glXCreateWindow") == 0) {
        return (void *)glXCreateWindow;
    }
    if (strcmp(name, "glXDestroyContext") == 0) {
        return (void *)glXDestroyContext;
    }
    if (strcmp(name, "glXDestroyGLXPbufferSGIX") == 0) {
        return (void *)glXDestroyGLXPbufferSGIX;
    }
    if (strcmp(name, "glXDestroyGLXPixmap") == 0) {
        return (void *)glXDestroyGLXPixmap;
    }
    if (strcmp(name, "glXDestroyGLXVideoSourceSGIX") == 0) {
        return (void *)glXDestroyGLXVideoSourceSGIX;
    }
    if (strcmp(name, "glXDestroyHyperpipeConfigSGIX") == 0) {
        return (void *)glXDestroyHyperpipeConfigSGIX;
    }
    if (strcmp(name, "glXDestroyPbuffer") == 0) {
        return (void *)glXDestroyPbuffer;
    }
    if (strcmp(name, "glXDestroyPixmap") == 0) {
        return (void *)glXDestroyPixmap;
    }
    if (strcmp(name, "glXDestroyWindow") == 0) {
        return (void *)glXDestroyWindow;
    }
    if (strcmp(name, "glXGetClientString") == 0) {
        return (void *)glXGetClientString;
    }
    if (strcmp(name, "glXGetConfig") == 0) {
        return (void *)glXGetConfig;
    }
    if (strcmp(name, "glXGetCurrentContext") == 0) {
        return (void *)glXGetCurrentContext;
    }
    if (strcmp(name, "glXGetCurrentDisplay") == 0) {
        return (void *)glXGetCurrentDisplay;
    }
    if (strcmp(name, "glXGetCurrentDrawable") == 0) {
        return (void *)glXGetCurrentDrawable;
    }
    if (strcmp(name, "glXGetCurrentReadDrawable") == 0) {
        return (void *)glXGetCurrentReadDrawable;
    }
    if (strcmp(name, "glXGetDrawableAttributes") == 0) {
        return (void *)glXGetDrawableAttributes;
    }
    if (strcmp(name, "glXGetDrawableAttributesSGIX") == 0) {
        return (void *)glXGetDrawableAttributesSGIX;
    }
    if (strcmp(name, "glXGetFBConfigAttrib") == 0) {
        return (void *)glXGetFBConfigAttrib;
    }
    if (strcmp(name, "glXGetFBConfigs") == 0) {
        return (void *)glXGetFBConfigs;
    }
    if (strcmp(name, "glXGetFBConfigsSGIX") == 0) {
        return (void *)glXGetFBConfigsSGIX;
    }
    if (strcmp(name, "glXGetProcAddress") == 0) {
        return (void *)glXGetProcAddress;
    }
    if (strcmp(name, "glXGetSelectedEvent") == 0) {
        return (void *)glXGetSelectedEvent;
    }
    if (strcmp(name, "glXGetVisualConfigs") == 0) {
        return (void *)glXGetVisualConfigs;
    }
    if (strcmp(name, "glXGetVisualFromFBConfig") == 0) {
        return (void *)glXGetVisualFromFBConfig;
    }
    if (strcmp(name, "glXHyperpipeAttribSGIX") == 0) {
        return (void *)glXHyperpipeAttribSGIX;
    }
    if (strcmp(name, "glXHyperpipeConfigSGIX") == 0) {
        return (void *)glXHyperpipeConfigSGIX;
    }
    if (strcmp(name, "glXIsDirect") == 0) {
        return (void *)glXIsDirect;
    }
    if (strcmp(name, "glXJoinSwapGroupSGIX") == 0) {
        return (void *)glXJoinSwapGroupSGIX;
    }
    if (strcmp(name, "glXMakeContextCurrent") == 0) {
        return (void *)glXMakeContextCurrent;
    }
    if (strcmp(name, "glXMakeCurrent") == 0) {
        return (void *)glXMakeCurrent;
    }
    if (strcmp(name, "glXMakeCurrentReadSGI") == 0) {
        return (void *)glXMakeCurrentReadSGI;
    }
    if (strcmp(name, "glXQueryContext") == 0) {
        return (void *)glXQueryContext;
    }
    if (strcmp(name, "glXQueryContextInfoEXT") == 0) {
        return (void *)glXQueryContextInfoEXT;
    }
    if (strcmp(name, "glXQueryDrawable") == 0) {
        return (void *)glXQueryDrawable;
    }
    if (strcmp(name, "glXQueryExtension") == 0) {
        return (void *)glXQueryExtension;
    }
    if (strcmp(name, "glXQueryExtensionsString") == 0) {
        return (void *)glXQueryExtensionsString;
    }
    if (strcmp(name, "glXQueryHyperpipeAttribSGIX") == 0) {
        return (void *)glXQueryHyperpipeAttribSGIX;
    }
    if (strcmp(name, "glXQueryHyperpipeBestAttribSGIX") == 0) {
        return (void *)glXQueryHyperpipeBestAttribSGIX;
    }
    if (strcmp(name, "glXQueryHyperpipeConfigSGIX") == 0) {
        return (void *)glXQueryHyperpipeConfigSGIX;
    }
    if (strcmp(name, "glXQueryHyperpipeNetworkSGIX") == 0) {
        return (void *)glXQueryHyperpipeNetworkSGIX;
    }
    if (strcmp(name, "glXQueryMaxSwapBarriersSGIX") == 0) {
        return (void *)glXQueryMaxSwapBarriersSGIX;
    }
    if (strcmp(name, "glXQueryServerString") == 0) {
        return (void *)glXQueryServerString;
    }
    if (strcmp(name, "glXQueryVersion") == 0) {
        return (void *)glXQueryVersion;
    }
    if (strcmp(name, "glXRender") == 0) {
        return (void *)glXRender;
    }
    if (strcmp(name, "glXRenderLarge") == 0) {
        return (void *)glXRenderLarge;
    }
    if (strcmp(name, "glXSelectEvent") == 0) {
        return (void *)glXSelectEvent;
    }
    if (strcmp(name, "glXSwapBuffers") == 0) {
        return (void *)glXSwapBuffers;
    }
    if (strcmp(name, "glXSwapIntervalSGI") == 0) {
        return (void *)glXSwapIntervalSGI;
    }
    if (strcmp(name, "glXUseXFont") == 0) {
        return (void *)glXUseXFont;
    }
    if (strcmp(name, "glXVendorPrivate") == 0) {
        return (void *)glXVendorPrivate;
    }
    if (strcmp(name, "glXVendorPrivateWithReply") == 0) {
        return (void *)glXVendorPrivateWithReply;
    }
    if (strcmp(name, "glXWaitGL") == 0) {
        return (void *)glXWaitGL;
    }
    if (strcmp(name, "glXWaitX") == 0) {
        return (void *)glXWaitX;
    }
    printf("glXGetProcAddress(%s) not found\n", name);
    return NULL;
}

__GLXextFuncPtr glXGetProcAddress(const GLubyte *name) {
    return glXGetProcAddressARB(name);
}
