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
#ifndef skip_client_snd_asoundlib_version
const char * snd_asoundlib_version() {
    snd_asoundlib_version_INDEXED *packed_data = malloc(sizeof(snd_asoundlib_version_INDEXED));
    packed_data->func = snd_asoundlib_version_INDEX;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_add_ctl_handler
int snd_async_add_ctl_handler(snd_async_handler_t ** handler, snd_ctl_t * ctl, snd_async_callback_t callback, void * private_data) {
    snd_async_add_ctl_handler_INDEXED *packed_data = malloc(sizeof(snd_async_add_ctl_handler_INDEXED));
    packed_data->func = snd_async_add_ctl_handler_INDEX;
    packed_data->args.a1 = handler;
    packed_data->args.a2 = ctl;
    packed_data->args.a3 = callback;
    packed_data->args.a4 = private_data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_add_handler
int snd_async_add_handler(snd_async_handler_t ** handler, int fd, snd_async_callback_t callback, void * private_data) {
    snd_async_add_handler_INDEXED *packed_data = malloc(sizeof(snd_async_add_handler_INDEXED));
    packed_data->func = snd_async_add_handler_INDEX;
    packed_data->args.a1 = handler;
    packed_data->args.a2 = fd;
    packed_data->args.a3 = callback;
    packed_data->args.a4 = private_data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_add_pcm_handler
int snd_async_add_pcm_handler(snd_async_handler_t ** handler, snd_pcm_t * pcm, snd_async_callback_t callback, void * private_data) {
    snd_async_add_pcm_handler_INDEXED *packed_data = malloc(sizeof(snd_async_add_pcm_handler_INDEXED));
    packed_data->func = snd_async_add_pcm_handler_INDEX;
    packed_data->args.a1 = handler;
    packed_data->args.a2 = pcm;
    packed_data->args.a3 = callback;
    packed_data->args.a4 = private_data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_add_timer_handler
int snd_async_add_timer_handler(snd_async_handler_t ** handler, snd_timer_t * timer, snd_async_callback_t callback, void * private_data) {
    snd_async_add_timer_handler_INDEXED *packed_data = malloc(sizeof(snd_async_add_timer_handler_INDEXED));
    packed_data->func = snd_async_add_timer_handler_INDEX;
    packed_data->args.a1 = handler;
    packed_data->args.a2 = timer;
    packed_data->args.a3 = callback;
    packed_data->args.a4 = private_data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_del_handler
int snd_async_del_handler(snd_async_handler_t * handler) {
    snd_async_del_handler_INDEXED *packed_data = malloc(sizeof(snd_async_del_handler_INDEXED));
    packed_data->func = snd_async_del_handler_INDEX;
    packed_data->args.a1 = handler;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_handler_get_callback_private
void * snd_async_handler_get_callback_private(snd_async_handler_t * handler) {
    snd_async_handler_get_callback_private_INDEXED *packed_data = malloc(sizeof(snd_async_handler_get_callback_private_INDEXED));
    packed_data->func = snd_async_handler_get_callback_private_INDEX;
    packed_data->args.a1 = handler;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_handler_get_ctl
snd_ctl_t * snd_async_handler_get_ctl(snd_async_handler_t * handler) {
    snd_async_handler_get_ctl_INDEXED *packed_data = malloc(sizeof(snd_async_handler_get_ctl_INDEXED));
    packed_data->func = snd_async_handler_get_ctl_INDEX;
    packed_data->args.a1 = handler;
    snd_ctl_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_handler_get_fd
int snd_async_handler_get_fd(snd_async_handler_t * handler) {
    snd_async_handler_get_fd_INDEXED *packed_data = malloc(sizeof(snd_async_handler_get_fd_INDEXED));
    packed_data->func = snd_async_handler_get_fd_INDEX;
    packed_data->args.a1 = handler;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_handler_get_pcm
snd_pcm_t * snd_async_handler_get_pcm(snd_async_handler_t * handler) {
    snd_async_handler_get_pcm_INDEXED *packed_data = malloc(sizeof(snd_async_handler_get_pcm_INDEXED));
    packed_data->func = snd_async_handler_get_pcm_INDEX;
    packed_data->args.a1 = handler;
    snd_pcm_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_handler_get_signo
int snd_async_handler_get_signo(snd_async_handler_t * handler) {
    snd_async_handler_get_signo_INDEXED *packed_data = malloc(sizeof(snd_async_handler_get_signo_INDEXED));
    packed_data->func = snd_async_handler_get_signo_INDEX;
    packed_data->args.a1 = handler;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_async_handler_get_timer
snd_timer_t * snd_async_handler_get_timer(snd_async_handler_t * handler) {
    snd_async_handler_get_timer_INDEXED *packed_data = malloc(sizeof(snd_async_handler_get_timer_INDEXED));
    packed_data->func = snd_async_handler_get_timer_INDEX;
    packed_data->args.a1 = handler;
    snd_timer_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_card_get_index
int snd_card_get_index(const char * name) {
    snd_card_get_index_INDEXED *packed_data = malloc(sizeof(snd_card_get_index_INDEXED));
    packed_data->func = snd_card_get_index_INDEX;
    packed_data->args.a1 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_card_get_longname
int snd_card_get_longname(int card, char ** name) {
    snd_card_get_longname_INDEXED *packed_data = malloc(sizeof(snd_card_get_longname_INDEXED));
    packed_data->func = snd_card_get_longname_INDEX;
    packed_data->args.a1 = card;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_card_get_name
int snd_card_get_name(int card, char ** name) {
    snd_card_get_name_INDEXED *packed_data = malloc(sizeof(snd_card_get_name_INDEXED));
    packed_data->func = snd_card_get_name_INDEX;
    packed_data->args.a1 = card;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_card_load
int snd_card_load(int card) {
    snd_card_load_INDEXED *packed_data = malloc(sizeof(snd_card_load_INDEXED));
    packed_data->func = snd_card_load_INDEX;
    packed_data->args.a1 = card;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_card_next
int snd_card_next(int * card) {
    snd_card_next_INDEXED *packed_data = malloc(sizeof(snd_card_next_INDEXED));
    packed_data->func = snd_card_next_INDEX;
    packed_data->args.a1 = card;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_add
int snd_config_add(snd_config_t * config, snd_config_t * leaf) {
    snd_config_add_INDEXED *packed_data = malloc(sizeof(snd_config_add_INDEXED));
    packed_data->func = snd_config_add_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = leaf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_copy
int snd_config_copy(snd_config_t ** dst, snd_config_t * src) {
    snd_config_copy_INDEXED *packed_data = malloc(sizeof(snd_config_copy_INDEXED));
    packed_data->func = snd_config_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_delete
int snd_config_delete(snd_config_t * config) {
    snd_config_delete_INDEXED *packed_data = malloc(sizeof(snd_config_delete_INDEXED));
    packed_data->func = snd_config_delete_INDEX;
    packed_data->args.a1 = config;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_delete_compound_members
int snd_config_delete_compound_members(const snd_config_t * config) {
    snd_config_delete_compound_members_INDEXED *packed_data = malloc(sizeof(snd_config_delete_compound_members_INDEXED));
    packed_data->func = snd_config_delete_compound_members_INDEX;
    packed_data->args.a1 = config;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_evaluate
int snd_config_evaluate(snd_config_t * config, snd_config_t * root, snd_config_t * private_data, snd_config_t ** result) {
    snd_config_evaluate_INDEXED *packed_data = malloc(sizeof(snd_config_evaluate_INDEXED));
    packed_data->func = snd_config_evaluate_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = root;
    packed_data->args.a3 = private_data;
    packed_data->args.a4 = result;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_expand
int snd_config_expand(snd_config_t * config, snd_config_t * root, const char * args, snd_config_t * private_data, snd_config_t ** result) {
    snd_config_expand_INDEXED *packed_data = malloc(sizeof(snd_config_expand_INDEXED));
    packed_data->func = snd_config_expand_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = root;
    packed_data->args.a3 = args;
    packed_data->args.a4 = private_data;
    packed_data->args.a5 = result;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_ascii
int snd_config_get_ascii(const snd_config_t * config, char ** value) {
    snd_config_get_ascii_INDEXED *packed_data = malloc(sizeof(snd_config_get_ascii_INDEXED));
    packed_data->func = snd_config_get_ascii_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_bool
int snd_config_get_bool(const snd_config_t * conf) {
    snd_config_get_bool_INDEXED *packed_data = malloc(sizeof(snd_config_get_bool_INDEXED));
    packed_data->func = snd_config_get_bool_INDEX;
    packed_data->args.a1 = conf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_bool_ascii
int snd_config_get_bool_ascii(const char * ascii) {
    snd_config_get_bool_ascii_INDEXED *packed_data = malloc(sizeof(snd_config_get_bool_ascii_INDEXED));
    packed_data->func = snd_config_get_bool_ascii_INDEX;
    packed_data->args.a1 = ascii;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_ctl_iface
int snd_config_get_ctl_iface(const snd_config_t * conf) {
    snd_config_get_ctl_iface_INDEXED *packed_data = malloc(sizeof(snd_config_get_ctl_iface_INDEXED));
    packed_data->func = snd_config_get_ctl_iface_INDEX;
    packed_data->args.a1 = conf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_ctl_iface_ascii
int snd_config_get_ctl_iface_ascii(const char * ascii) {
    snd_config_get_ctl_iface_ascii_INDEXED *packed_data = malloc(sizeof(snd_config_get_ctl_iface_ascii_INDEXED));
    packed_data->func = snd_config_get_ctl_iface_ascii_INDEX;
    packed_data->args.a1 = ascii;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_id
int snd_config_get_id(const snd_config_t * config, const char ** value) {
    snd_config_get_id_INDEXED *packed_data = malloc(sizeof(snd_config_get_id_INDEXED));
    packed_data->func = snd_config_get_id_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_integer
int snd_config_get_integer(const snd_config_t * config, long * value) {
    snd_config_get_integer_INDEXED *packed_data = malloc(sizeof(snd_config_get_integer_INDEXED));
    packed_data->func = snd_config_get_integer_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_integer64
int snd_config_get_integer64(const snd_config_t * config, long long * value) {
    snd_config_get_integer64_INDEXED *packed_data = malloc(sizeof(snd_config_get_integer64_INDEXED));
    packed_data->func = snd_config_get_integer64_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_ireal
int snd_config_get_ireal(const snd_config_t * config, double * value) {
    snd_config_get_ireal_INDEXED *packed_data = malloc(sizeof(snd_config_get_ireal_INDEXED));
    packed_data->func = snd_config_get_ireal_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_pointer
int snd_config_get_pointer(const snd_config_t * config, const void ** value) {
    snd_config_get_pointer_INDEXED *packed_data = malloc(sizeof(snd_config_get_pointer_INDEXED));
    packed_data->func = snd_config_get_pointer_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_real
int snd_config_get_real(const snd_config_t * config, double * value) {
    snd_config_get_real_INDEXED *packed_data = malloc(sizeof(snd_config_get_real_INDEXED));
    packed_data->func = snd_config_get_real_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_string
int snd_config_get_string(const snd_config_t * config, const char ** value) {
    snd_config_get_string_INDEXED *packed_data = malloc(sizeof(snd_config_get_string_INDEXED));
    packed_data->func = snd_config_get_string_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_get_type
snd_config_type_t snd_config_get_type(const snd_config_t * config) {
    snd_config_get_type_INDEXED *packed_data = malloc(sizeof(snd_config_get_type_INDEXED));
    packed_data->func = snd_config_get_type_INDEX;
    packed_data->args.a1 = config;
    snd_config_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_imake_integer
int snd_config_imake_integer(snd_config_t ** config, const char * key, const long value) {
    snd_config_imake_integer_INDEXED *packed_data = malloc(sizeof(snd_config_imake_integer_INDEXED));
    packed_data->func = snd_config_imake_integer_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_imake_integer64
int snd_config_imake_integer64(snd_config_t ** config, const char * key, const long long value) {
    snd_config_imake_integer64_INDEXED *packed_data = malloc(sizeof(snd_config_imake_integer64_INDEXED));
    packed_data->func = snd_config_imake_integer64_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_imake_pointer
int snd_config_imake_pointer(snd_config_t ** config, const char * key, const void * ptr) {
    snd_config_imake_pointer_INDEXED *packed_data = malloc(sizeof(snd_config_imake_pointer_INDEXED));
    packed_data->func = snd_config_imake_pointer_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    packed_data->args.a3 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_imake_real
int snd_config_imake_real(snd_config_t ** config, const char * key, const double value) {
    snd_config_imake_real_INDEXED *packed_data = malloc(sizeof(snd_config_imake_real_INDEXED));
    packed_data->func = snd_config_imake_real_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_imake_string
int snd_config_imake_string(snd_config_t ** config, const char * key, const char * ascii) {
    snd_config_imake_string_INDEXED *packed_data = malloc(sizeof(snd_config_imake_string_INDEXED));
    packed_data->func = snd_config_imake_string_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    packed_data->args.a3 = ascii;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_iterator_end
snd_config_iterator_t snd_config_iterator_end(const snd_config_t * node) {
    snd_config_iterator_end_INDEXED *packed_data = malloc(sizeof(snd_config_iterator_end_INDEXED));
    packed_data->func = snd_config_iterator_end_INDEX;
    packed_data->args.a1 = node;
    snd_config_iterator_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_iterator_entry
snd_config_t * snd_config_iterator_entry(const snd_config_iterator_t iterator) {
    snd_config_iterator_entry_INDEXED *packed_data = malloc(sizeof(snd_config_iterator_entry_INDEXED));
    packed_data->func = snd_config_iterator_entry_INDEX;
    packed_data->args.a1 = iterator;
    snd_config_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_iterator_first
snd_config_iterator_t snd_config_iterator_first(const snd_config_t * node) {
    snd_config_iterator_first_INDEXED *packed_data = malloc(sizeof(snd_config_iterator_first_INDEXED));
    packed_data->func = snd_config_iterator_first_INDEX;
    packed_data->args.a1 = node;
    snd_config_iterator_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_iterator_next
snd_config_iterator_t snd_config_iterator_next(const snd_config_iterator_t iterator) {
    snd_config_iterator_next_INDEXED *packed_data = malloc(sizeof(snd_config_iterator_next_INDEXED));
    packed_data->func = snd_config_iterator_next_INDEX;
    packed_data->args.a1 = iterator;
    snd_config_iterator_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_load
int snd_config_load(snd_config_t * config, snd_input_t * in) {
    snd_config_load_INDEXED *packed_data = malloc(sizeof(snd_config_load_INDEXED));
    packed_data->func = snd_config_load_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = in;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_load_override
int snd_config_load_override(snd_config_t * config, snd_input_t * in) {
    snd_config_load_override_INDEXED *packed_data = malloc(sizeof(snd_config_load_override_INDEXED));
    packed_data->func = snd_config_load_override_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = in;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_make
int snd_config_make(snd_config_t ** config, const char * key, snd_config_type_t type) {
    snd_config_make_INDEXED *packed_data = malloc(sizeof(snd_config_make_INDEXED));
    packed_data->func = snd_config_make_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    packed_data->args.a3 = type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_make_compound
int snd_config_make_compound(snd_config_t ** config, const char * key, int join) {
    snd_config_make_compound_INDEXED *packed_data = malloc(sizeof(snd_config_make_compound_INDEXED));
    packed_data->func = snd_config_make_compound_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    packed_data->args.a3 = join;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_make_integer
int snd_config_make_integer(snd_config_t ** config, const char * key) {
    snd_config_make_integer_INDEXED *packed_data = malloc(sizeof(snd_config_make_integer_INDEXED));
    packed_data->func = snd_config_make_integer_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_make_integer64
int snd_config_make_integer64(snd_config_t ** config, const char * key) {
    snd_config_make_integer64_INDEXED *packed_data = malloc(sizeof(snd_config_make_integer64_INDEXED));
    packed_data->func = snd_config_make_integer64_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_make_pointer
int snd_config_make_pointer(snd_config_t ** config, const char * key) {
    snd_config_make_pointer_INDEXED *packed_data = malloc(sizeof(snd_config_make_pointer_INDEXED));
    packed_data->func = snd_config_make_pointer_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_make_real
int snd_config_make_real(snd_config_t ** config, const char * key) {
    snd_config_make_real_INDEXED *packed_data = malloc(sizeof(snd_config_make_real_INDEXED));
    packed_data->func = snd_config_make_real_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_make_string
int snd_config_make_string(snd_config_t ** config, const char * key) {
    snd_config_make_string_INDEXED *packed_data = malloc(sizeof(snd_config_make_string_INDEXED));
    packed_data->func = snd_config_make_string_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_save
int snd_config_save(snd_config_t * config, snd_output_t * out) {
    snd_config_save_INDEXED *packed_data = malloc(sizeof(snd_config_save_INDEXED));
    packed_data->func = snd_config_save_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = out;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_search
int snd_config_search(snd_config_t * config, const char * key, snd_config_t ** result) {
    snd_config_search_INDEXED *packed_data = malloc(sizeof(snd_config_search_INDEXED));
    packed_data->func = snd_config_search_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = key;
    packed_data->args.a3 = result;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_search_definition
int snd_config_search_definition(snd_config_t * config, const char * base, const char * key, snd_config_t ** result) {
    snd_config_search_definition_INDEXED *packed_data = malloc(sizeof(snd_config_search_definition_INDEXED));
    packed_data->func = snd_config_search_definition_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = base;
    packed_data->args.a3 = key;
    packed_data->args.a4 = result;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_set_ascii
int snd_config_set_ascii(snd_config_t * config, const char * ascii) {
    snd_config_set_ascii_INDEXED *packed_data = malloc(sizeof(snd_config_set_ascii_INDEXED));
    packed_data->func = snd_config_set_ascii_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = ascii;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_set_id
int snd_config_set_id(snd_config_t * config, const char * id) {
    snd_config_set_id_INDEXED *packed_data = malloc(sizeof(snd_config_set_id_INDEXED));
    packed_data->func = snd_config_set_id_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_set_integer
int snd_config_set_integer(snd_config_t * config, long value) {
    snd_config_set_integer_INDEXED *packed_data = malloc(sizeof(snd_config_set_integer_INDEXED));
    packed_data->func = snd_config_set_integer_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_set_integer64
int snd_config_set_integer64(snd_config_t * config, long long value) {
    snd_config_set_integer64_INDEXED *packed_data = malloc(sizeof(snd_config_set_integer64_INDEXED));
    packed_data->func = snd_config_set_integer64_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_set_pointer
int snd_config_set_pointer(snd_config_t * config, const void * ptr) {
    snd_config_set_pointer_INDEXED *packed_data = malloc(sizeof(snd_config_set_pointer_INDEXED));
    packed_data->func = snd_config_set_pointer_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_set_real
int snd_config_set_real(snd_config_t * config, double value) {
    snd_config_set_real_INDEXED *packed_data = malloc(sizeof(snd_config_set_real_INDEXED));
    packed_data->func = snd_config_set_real_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_set_string
int snd_config_set_string(snd_config_t * config, const char * value) {
    snd_config_set_string_INDEXED *packed_data = malloc(sizeof(snd_config_set_string_INDEXED));
    packed_data->func = snd_config_set_string_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_test_id
int snd_config_test_id(const snd_config_t * config, const char * id) {
    snd_config_test_id_INDEXED *packed_data = malloc(sizeof(snd_config_test_id_INDEXED));
    packed_data->func = snd_config_test_id_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_top
int snd_config_top(snd_config_t ** config) {
    snd_config_top_INDEXED *packed_data = malloc(sizeof(snd_config_top_INDEXED));
    packed_data->func = snd_config_top_INDEX;
    packed_data->args.a1 = config;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_update
int snd_config_update() {
    snd_config_update_INDEXED *packed_data = malloc(sizeof(snd_config_update_INDEXED));
    packed_data->func = snd_config_update_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_update_free
int snd_config_update_free(snd_config_update_t * update) {
    snd_config_update_free_INDEXED *packed_data = malloc(sizeof(snd_config_update_free_INDEXED));
    packed_data->func = snd_config_update_free_INDEX;
    packed_data->args.a1 = update;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_update_free_global
int snd_config_update_free_global() {
    snd_config_update_free_global_INDEXED *packed_data = malloc(sizeof(snd_config_update_free_global_INDEXED));
    packed_data->func = snd_config_update_free_global_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_config_update_r
int snd_config_update_r(snd_config_t ** top, snd_config_update_t ** update, const char * path) {
    snd_config_update_r_INDEXED *packed_data = malloc(sizeof(snd_config_update_r_INDEXED));
    packed_data->func = snd_config_update_r_INDEX;
    packed_data->args.a1 = top;
    packed_data->args.a2 = update;
    packed_data->args.a3 = path;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info
int snd_ctl_card_info(snd_ctl_t * ctl, snd_ctl_card_info_t * info) {
    snd_ctl_card_info_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_INDEXED));
    packed_data->func = snd_ctl_card_info_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_clear
void snd_ctl_card_info_clear(snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_clear_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_clear_INDEXED));
    packed_data->func = snd_ctl_card_info_clear_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_card_info_copy
void snd_ctl_card_info_copy(snd_ctl_card_info_t * dst, const snd_ctl_card_info_t * src) {
    snd_ctl_card_info_copy_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_copy_INDEXED));
    packed_data->func = snd_ctl_card_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_card_info_free
void snd_ctl_card_info_free(snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_free_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_free_INDEXED));
    packed_data->func = snd_ctl_card_info_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_card_info_get_card
int snd_ctl_card_info_get_card(const snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_get_card_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_get_card_INDEXED));
    packed_data->func = snd_ctl_card_info_get_card_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_get_components
const char * snd_ctl_card_info_get_components(const snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_get_components_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_get_components_INDEXED));
    packed_data->func = snd_ctl_card_info_get_components_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_get_driver
const char * snd_ctl_card_info_get_driver(const snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_get_driver_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_get_driver_INDEXED));
    packed_data->func = snd_ctl_card_info_get_driver_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_get_id
const char * snd_ctl_card_info_get_id(const snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_get_id_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_get_id_INDEXED));
    packed_data->func = snd_ctl_card_info_get_id_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_get_longname
const char * snd_ctl_card_info_get_longname(const snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_get_longname_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_get_longname_INDEXED));
    packed_data->func = snd_ctl_card_info_get_longname_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_get_mixername
const char * snd_ctl_card_info_get_mixername(const snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_get_mixername_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_get_mixername_INDEXED));
    packed_data->func = snd_ctl_card_info_get_mixername_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_get_name
const char * snd_ctl_card_info_get_name(const snd_ctl_card_info_t * obj) {
    snd_ctl_card_info_get_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_get_name_INDEXED));
    packed_data->func = snd_ctl_card_info_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_malloc
int snd_ctl_card_info_malloc(snd_ctl_card_info_t ** ptr) {
    snd_ctl_card_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_malloc_INDEXED));
    packed_data->func = snd_ctl_card_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_card_info_sizeof
size_t snd_ctl_card_info_sizeof() {
    snd_ctl_card_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_ctl_card_info_sizeof_INDEXED));
    packed_data->func = snd_ctl_card_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_close
int snd_ctl_close(snd_ctl_t * ctl) {
    snd_ctl_close_INDEXED *packed_data = malloc(sizeof(snd_ctl_close_INDEXED));
    packed_data->func = snd_ctl_close_INDEX;
    packed_data->args.a1 = ctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_add_boolean
int snd_ctl_elem_add_boolean(snd_ctl_t * ctl, const snd_ctl_elem_id_t * id, unsigned int count) {
    snd_ctl_elem_add_boolean_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_add_boolean_INDEXED));
    packed_data->func = snd_ctl_elem_add_boolean_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    packed_data->args.a3 = count;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_add_iec958
int snd_ctl_elem_add_iec958(snd_ctl_t * ctl, const snd_ctl_elem_id_t * id) {
    snd_ctl_elem_add_iec958_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_add_iec958_INDEXED));
    packed_data->func = snd_ctl_elem_add_iec958_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_add_integer
int snd_ctl_elem_add_integer(snd_ctl_t * ctl, const snd_ctl_elem_id_t * id, unsigned int count, long imin, long imax, long istep) {
    snd_ctl_elem_add_integer_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_add_integer_INDEXED));
    packed_data->func = snd_ctl_elem_add_integer_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    packed_data->args.a3 = count;
    packed_data->args.a4 = imin;
    packed_data->args.a5 = imax;
    packed_data->args.a6 = istep;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_add_integer64
int snd_ctl_elem_add_integer64(snd_ctl_t * ctl, const snd_ctl_elem_id_t * id, unsigned int count, long long imin, long long imax, long long istep) {
    snd_ctl_elem_add_integer64_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_add_integer64_INDEXED));
    packed_data->func = snd_ctl_elem_add_integer64_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    packed_data->args.a3 = count;
    packed_data->args.a4 = imin;
    packed_data->args.a5 = imax;
    packed_data->args.a6 = istep;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_id_clear
void snd_ctl_elem_id_clear(snd_ctl_elem_id_t * obj) {
    snd_ctl_elem_id_clear_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_clear_INDEXED));
    packed_data->func = snd_ctl_elem_id_clear_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_copy
void snd_ctl_elem_id_copy(snd_ctl_elem_id_t * dst, const snd_ctl_elem_id_t * src) {
    snd_ctl_elem_id_copy_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_copy_INDEXED));
    packed_data->func = snd_ctl_elem_id_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_free
void snd_ctl_elem_id_free(snd_ctl_elem_id_t * obj) {
    snd_ctl_elem_id_free_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_free_INDEXED));
    packed_data->func = snd_ctl_elem_id_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_get_device
unsigned int snd_ctl_elem_id_get_device(const snd_ctl_elem_id_t * obj) {
    snd_ctl_elem_id_get_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_get_device_INDEXED));
    packed_data->func = snd_ctl_elem_id_get_device_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_id_get_index
unsigned int snd_ctl_elem_id_get_index(const snd_ctl_elem_id_t * obj) {
    snd_ctl_elem_id_get_index_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_get_index_INDEXED));
    packed_data->func = snd_ctl_elem_id_get_index_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_id_get_interface
snd_ctl_elem_iface_t snd_ctl_elem_id_get_interface(const snd_ctl_elem_id_t * obj) {
    snd_ctl_elem_id_get_interface_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_get_interface_INDEXED));
    packed_data->func = snd_ctl_elem_id_get_interface_INDEX;
    packed_data->args.a1 = obj;
    snd_ctl_elem_iface_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_id_get_name
const char * snd_ctl_elem_id_get_name(const snd_ctl_elem_id_t * obj) {
    snd_ctl_elem_id_get_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_get_name_INDEXED));
    packed_data->func = snd_ctl_elem_id_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_id_get_numid
unsigned int snd_ctl_elem_id_get_numid(const snd_ctl_elem_id_t * obj) {
    snd_ctl_elem_id_get_numid_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_get_numid_INDEXED));
    packed_data->func = snd_ctl_elem_id_get_numid_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_id_get_subdevice
unsigned int snd_ctl_elem_id_get_subdevice(const snd_ctl_elem_id_t * obj) {
    snd_ctl_elem_id_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_get_subdevice_INDEXED));
    packed_data->func = snd_ctl_elem_id_get_subdevice_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_id_malloc
int snd_ctl_elem_id_malloc(snd_ctl_elem_id_t ** ptr) {
    snd_ctl_elem_id_malloc_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_malloc_INDEXED));
    packed_data->func = snd_ctl_elem_id_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_id_set_device
void snd_ctl_elem_id_set_device(snd_ctl_elem_id_t * obj, unsigned int val) {
    snd_ctl_elem_id_set_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_set_device_INDEXED));
    packed_data->func = snd_ctl_elem_id_set_device_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_set_index
void snd_ctl_elem_id_set_index(snd_ctl_elem_id_t * obj, unsigned int val) {
    snd_ctl_elem_id_set_index_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_set_index_INDEXED));
    packed_data->func = snd_ctl_elem_id_set_index_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_set_interface
void snd_ctl_elem_id_set_interface(snd_ctl_elem_id_t * obj, snd_ctl_elem_iface_t val) {
    snd_ctl_elem_id_set_interface_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_set_interface_INDEXED));
    packed_data->func = snd_ctl_elem_id_set_interface_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_set_name
void snd_ctl_elem_id_set_name(snd_ctl_elem_id_t * obj, const char * val) {
    snd_ctl_elem_id_set_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_set_name_INDEXED));
    packed_data->func = snd_ctl_elem_id_set_name_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_set_numid
void snd_ctl_elem_id_set_numid(snd_ctl_elem_id_t * obj, unsigned int val) {
    snd_ctl_elem_id_set_numid_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_set_numid_INDEXED));
    packed_data->func = snd_ctl_elem_id_set_numid_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_set_subdevice
void snd_ctl_elem_id_set_subdevice(snd_ctl_elem_id_t * obj, unsigned int val) {
    snd_ctl_elem_id_set_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_set_subdevice_INDEXED));
    packed_data->func = snd_ctl_elem_id_set_subdevice_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_id_sizeof
size_t snd_ctl_elem_id_sizeof() {
    snd_ctl_elem_id_sizeof_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_id_sizeof_INDEXED));
    packed_data->func = snd_ctl_elem_id_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_iface_name
const char * snd_ctl_elem_iface_name(snd_ctl_elem_iface_t iface) {
    snd_ctl_elem_iface_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_iface_name_INDEXED));
    packed_data->func = snd_ctl_elem_iface_name_INDEX;
    packed_data->args.a1 = iface;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info
int snd_ctl_elem_info(snd_ctl_t * ctl, snd_ctl_elem_info_t * info) {
    snd_ctl_elem_info_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_INDEXED));
    packed_data->func = snd_ctl_elem_info_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_clear
void snd_ctl_elem_info_clear(snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_clear_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_clear_INDEXED));
    packed_data->func = snd_ctl_elem_info_clear_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_copy
void snd_ctl_elem_info_copy(snd_ctl_elem_info_t * dst, const snd_ctl_elem_info_t * src) {
    snd_ctl_elem_info_copy_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_copy_INDEXED));
    packed_data->func = snd_ctl_elem_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_free
void snd_ctl_elem_info_free(snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_free_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_free_INDEXED));
    packed_data->func = snd_ctl_elem_info_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_count
unsigned int snd_ctl_elem_info_get_count(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_count_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_count_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_count_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_device
unsigned int snd_ctl_elem_info_get_device(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_device_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_device_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_dimension
int snd_ctl_elem_info_get_dimension(const snd_ctl_elem_info_t * obj, unsigned int idx) {
    snd_ctl_elem_info_get_dimension_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_dimension_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_dimension_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_dimensions
int snd_ctl_elem_info_get_dimensions(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_dimensions_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_dimensions_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_dimensions_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_id
void snd_ctl_elem_info_get_id(const snd_ctl_elem_info_t * obj, snd_ctl_elem_id_t * ptr) {
    snd_ctl_elem_info_get_id_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_id_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_id_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_index
unsigned int snd_ctl_elem_info_get_index(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_index_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_index_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_index_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_interface
snd_ctl_elem_iface_t snd_ctl_elem_info_get_interface(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_interface_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_interface_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_interface_INDEX;
    packed_data->args.a1 = obj;
    snd_ctl_elem_iface_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_item_name
const char * snd_ctl_elem_info_get_item_name(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_item_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_item_name_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_item_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_items
unsigned int snd_ctl_elem_info_get_items(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_items_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_items_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_items_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_max
long snd_ctl_elem_info_get_max(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_max_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_max_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_max_INDEX;
    packed_data->args.a1 = obj;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_max64
long long snd_ctl_elem_info_get_max64(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_max64_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_max64_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_max64_INDEX;
    packed_data->args.a1 = obj;
    long long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_min
long snd_ctl_elem_info_get_min(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_min_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_min_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_min_INDEX;
    packed_data->args.a1 = obj;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_min64
long long snd_ctl_elem_info_get_min64(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_min64_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_min64_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_min64_INDEX;
    packed_data->args.a1 = obj;
    long long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_name
const char * snd_ctl_elem_info_get_name(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_name_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_numid
unsigned int snd_ctl_elem_info_get_numid(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_numid_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_numid_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_numid_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_owner
pid_t snd_ctl_elem_info_get_owner(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_owner_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_owner_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_owner_INDEX;
    packed_data->args.a1 = obj;
    pid_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_step
long snd_ctl_elem_info_get_step(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_step_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_step_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_step_INDEX;
    packed_data->args.a1 = obj;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_step64
long long snd_ctl_elem_info_get_step64(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_step64_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_step64_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_step64_INDEX;
    packed_data->args.a1 = obj;
    long long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_subdevice
unsigned int snd_ctl_elem_info_get_subdevice(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_subdevice_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_subdevice_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_get_type
snd_ctl_elem_type_t snd_ctl_elem_info_get_type(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_get_type_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_get_type_INDEXED));
    packed_data->func = snd_ctl_elem_info_get_type_INDEX;
    packed_data->args.a1 = obj;
    snd_ctl_elem_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_inactive
int snd_ctl_elem_info_is_inactive(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_inactive_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_inactive_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_inactive_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_locked
int snd_ctl_elem_info_is_locked(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_locked_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_locked_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_locked_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_owner
int snd_ctl_elem_info_is_owner(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_owner_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_owner_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_owner_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_readable
int snd_ctl_elem_info_is_readable(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_readable_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_readable_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_readable_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_tlv_commandable
int snd_ctl_elem_info_is_tlv_commandable(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_tlv_commandable_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_tlv_commandable_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_tlv_commandable_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_tlv_readable
int snd_ctl_elem_info_is_tlv_readable(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_tlv_readable_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_tlv_readable_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_tlv_readable_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_tlv_writable
int snd_ctl_elem_info_is_tlv_writable(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_tlv_writable_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_tlv_writable_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_tlv_writable_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_user
int snd_ctl_elem_info_is_user(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_user_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_user_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_user_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_volatile
int snd_ctl_elem_info_is_volatile(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_volatile_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_volatile_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_volatile_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_is_writable
int snd_ctl_elem_info_is_writable(const snd_ctl_elem_info_t * obj) {
    snd_ctl_elem_info_is_writable_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_is_writable_INDEXED));
    packed_data->func = snd_ctl_elem_info_is_writable_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_malloc
int snd_ctl_elem_info_malloc(snd_ctl_elem_info_t ** ptr) {
    snd_ctl_elem_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_malloc_INDEXED));
    packed_data->func = snd_ctl_elem_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_info_set_device
void snd_ctl_elem_info_set_device(snd_ctl_elem_info_t * obj, unsigned int val) {
    snd_ctl_elem_info_set_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_set_device_INDEXED));
    packed_data->func = snd_ctl_elem_info_set_device_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_set_id
void snd_ctl_elem_info_set_id(snd_ctl_elem_info_t * obj, const snd_ctl_elem_id_t * ptr) {
    snd_ctl_elem_info_set_id_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_set_id_INDEXED));
    packed_data->func = snd_ctl_elem_info_set_id_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_set_index
void snd_ctl_elem_info_set_index(snd_ctl_elem_info_t * obj, unsigned int val) {
    snd_ctl_elem_info_set_index_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_set_index_INDEXED));
    packed_data->func = snd_ctl_elem_info_set_index_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_set_interface
void snd_ctl_elem_info_set_interface(snd_ctl_elem_info_t * obj, snd_ctl_elem_iface_t val) {
    snd_ctl_elem_info_set_interface_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_set_interface_INDEXED));
    packed_data->func = snd_ctl_elem_info_set_interface_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_set_item
void snd_ctl_elem_info_set_item(snd_ctl_elem_info_t * obj, unsigned int val) {
    snd_ctl_elem_info_set_item_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_set_item_INDEXED));
    packed_data->func = snd_ctl_elem_info_set_item_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_set_name
void snd_ctl_elem_info_set_name(snd_ctl_elem_info_t * obj, const char * val) {
    snd_ctl_elem_info_set_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_set_name_INDEXED));
    packed_data->func = snd_ctl_elem_info_set_name_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_set_numid
void snd_ctl_elem_info_set_numid(snd_ctl_elem_info_t * obj, unsigned int val) {
    snd_ctl_elem_info_set_numid_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_set_numid_INDEXED));
    packed_data->func = snd_ctl_elem_info_set_numid_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_set_subdevice
void snd_ctl_elem_info_set_subdevice(snd_ctl_elem_info_t * obj, unsigned int val) {
    snd_ctl_elem_info_set_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_set_subdevice_INDEXED));
    packed_data->func = snd_ctl_elem_info_set_subdevice_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_info_sizeof
size_t snd_ctl_elem_info_sizeof() {
    snd_ctl_elem_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_info_sizeof_INDEXED));
    packed_data->func = snd_ctl_elem_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list
int snd_ctl_elem_list(snd_ctl_t * ctl, snd_ctl_elem_list_t * list) {
    snd_ctl_elem_list_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_INDEXED));
    packed_data->func = snd_ctl_elem_list_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_alloc_space
int snd_ctl_elem_list_alloc_space(snd_ctl_elem_list_t * obj, unsigned int entries) {
    snd_ctl_elem_list_alloc_space_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_alloc_space_INDEXED));
    packed_data->func = snd_ctl_elem_list_alloc_space_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = entries;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_clear
void snd_ctl_elem_list_clear(snd_ctl_elem_list_t * obj) {
    snd_ctl_elem_list_clear_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_clear_INDEXED));
    packed_data->func = snd_ctl_elem_list_clear_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_list_copy
void snd_ctl_elem_list_copy(snd_ctl_elem_list_t * dst, const snd_ctl_elem_list_t * src) {
    snd_ctl_elem_list_copy_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_copy_INDEXED));
    packed_data->func = snd_ctl_elem_list_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_list_free
void snd_ctl_elem_list_free(snd_ctl_elem_list_t * obj) {
    snd_ctl_elem_list_free_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_free_INDEXED));
    packed_data->func = snd_ctl_elem_list_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_list_free_space
void snd_ctl_elem_list_free_space(snd_ctl_elem_list_t * obj) {
    snd_ctl_elem_list_free_space_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_free_space_INDEXED));
    packed_data->func = snd_ctl_elem_list_free_space_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_count
unsigned int snd_ctl_elem_list_get_count(const snd_ctl_elem_list_t * obj) {
    snd_ctl_elem_list_get_count_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_count_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_count_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_device
unsigned int snd_ctl_elem_list_get_device(const snd_ctl_elem_list_t * obj, unsigned int idx) {
    snd_ctl_elem_list_get_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_device_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_device_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_id
void snd_ctl_elem_list_get_id(const snd_ctl_elem_list_t * obj, unsigned int idx, snd_ctl_elem_id_t * ptr) {
    snd_ctl_elem_list_get_id_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_id_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_id_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    packed_data->args.a3 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_index
unsigned int snd_ctl_elem_list_get_index(const snd_ctl_elem_list_t * obj, unsigned int idx) {
    snd_ctl_elem_list_get_index_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_index_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_index_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_interface
snd_ctl_elem_iface_t snd_ctl_elem_list_get_interface(const snd_ctl_elem_list_t * obj, unsigned int idx) {
    snd_ctl_elem_list_get_interface_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_interface_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_interface_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    snd_ctl_elem_iface_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_name
const char * snd_ctl_elem_list_get_name(const snd_ctl_elem_list_t * obj, unsigned int idx) {
    snd_ctl_elem_list_get_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_name_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_name_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_numid
unsigned int snd_ctl_elem_list_get_numid(const snd_ctl_elem_list_t * obj, unsigned int idx) {
    snd_ctl_elem_list_get_numid_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_numid_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_numid_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_subdevice
unsigned int snd_ctl_elem_list_get_subdevice(const snd_ctl_elem_list_t * obj, unsigned int idx) {
    snd_ctl_elem_list_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_subdevice_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_subdevice_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_get_used
unsigned int snd_ctl_elem_list_get_used(const snd_ctl_elem_list_t * obj) {
    snd_ctl_elem_list_get_used_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_get_used_INDEXED));
    packed_data->func = snd_ctl_elem_list_get_used_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_malloc
int snd_ctl_elem_list_malloc(snd_ctl_elem_list_t ** ptr) {
    snd_ctl_elem_list_malloc_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_malloc_INDEXED));
    packed_data->func = snd_ctl_elem_list_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_list_set_offset
void snd_ctl_elem_list_set_offset(snd_ctl_elem_list_t * obj, unsigned int val) {
    snd_ctl_elem_list_set_offset_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_set_offset_INDEXED));
    packed_data->func = snd_ctl_elem_list_set_offset_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_list_sizeof
size_t snd_ctl_elem_list_sizeof() {
    snd_ctl_elem_list_sizeof_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_list_sizeof_INDEXED));
    packed_data->func = snd_ctl_elem_list_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_lock
int snd_ctl_elem_lock(snd_ctl_t * ctl, snd_ctl_elem_id_t * id) {
    snd_ctl_elem_lock_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_lock_INDEXED));
    packed_data->func = snd_ctl_elem_lock_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_read
int snd_ctl_elem_read(snd_ctl_t * ctl, snd_ctl_elem_value_t * value) {
    snd_ctl_elem_read_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_read_INDEXED));
    packed_data->func = snd_ctl_elem_read_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_remove
int snd_ctl_elem_remove(snd_ctl_t * ctl, snd_ctl_elem_id_t * id) {
    snd_ctl_elem_remove_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_remove_INDEXED));
    packed_data->func = snd_ctl_elem_remove_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_set_bytes
void snd_ctl_elem_set_bytes(snd_ctl_elem_value_t * obj, void * data, size_t size) {
    snd_ctl_elem_set_bytes_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_set_bytes_INDEXED));
    packed_data->func = snd_ctl_elem_set_bytes_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = data;
    packed_data->args.a3 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_tlv_command
int snd_ctl_elem_tlv_command(snd_ctl_t * ctl, const snd_ctl_elem_id_t * id, const unsigned int * tlv) {
    snd_ctl_elem_tlv_command_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_tlv_command_INDEXED));
    packed_data->func = snd_ctl_elem_tlv_command_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    packed_data->args.a3 = tlv;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_tlv_read
int snd_ctl_elem_tlv_read(snd_ctl_t * ctl, const snd_ctl_elem_id_t * id, unsigned int * tlv, unsigned int tlv_size) {
    snd_ctl_elem_tlv_read_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_tlv_read_INDEXED));
    packed_data->func = snd_ctl_elem_tlv_read_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    packed_data->args.a3 = tlv;
    packed_data->args.a4 = tlv_size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_tlv_write
int snd_ctl_elem_tlv_write(snd_ctl_t * ctl, const snd_ctl_elem_id_t * id, const unsigned int * tlv) {
    snd_ctl_elem_tlv_write_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_tlv_write_INDEXED));
    packed_data->func = snd_ctl_elem_tlv_write_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    packed_data->args.a3 = tlv;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_type_name
const char * snd_ctl_elem_type_name(snd_ctl_elem_type_t type) {
    snd_ctl_elem_type_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_type_name_INDEXED));
    packed_data->func = snd_ctl_elem_type_name_INDEX;
    packed_data->args.a1 = type;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_unlock
int snd_ctl_elem_unlock(snd_ctl_t * ctl, snd_ctl_elem_id_t * id) {
    snd_ctl_elem_unlock_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_unlock_INDEXED));
    packed_data->func = snd_ctl_elem_unlock_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_clear
void snd_ctl_elem_value_clear(snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_clear_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_clear_INDEXED));
    packed_data->func = snd_ctl_elem_value_clear_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_copy
void snd_ctl_elem_value_copy(snd_ctl_elem_value_t * dst, const snd_ctl_elem_value_t * src) {
    snd_ctl_elem_value_copy_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_copy_INDEXED));
    packed_data->func = snd_ctl_elem_value_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_free
void snd_ctl_elem_value_free(snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_free_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_free_INDEXED));
    packed_data->func = snd_ctl_elem_value_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_boolean
int snd_ctl_elem_value_get_boolean(const snd_ctl_elem_value_t * obj, unsigned int idx) {
    snd_ctl_elem_value_get_boolean_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_boolean_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_boolean_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_byte
unsigned char snd_ctl_elem_value_get_byte(const snd_ctl_elem_value_t * obj, unsigned int idx) {
    snd_ctl_elem_value_get_byte_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_byte_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_byte_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    unsigned char ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_bytes
const void * snd_ctl_elem_value_get_bytes(const snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_get_bytes_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_bytes_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_bytes_INDEX;
    packed_data->args.a1 = obj;
    const void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_device
unsigned int snd_ctl_elem_value_get_device(const snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_get_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_device_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_device_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_enumerated
unsigned int snd_ctl_elem_value_get_enumerated(const snd_ctl_elem_value_t * obj, unsigned int idx) {
    snd_ctl_elem_value_get_enumerated_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_enumerated_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_enumerated_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_id
void snd_ctl_elem_value_get_id(const snd_ctl_elem_value_t * obj, snd_ctl_elem_id_t * ptr) {
    snd_ctl_elem_value_get_id_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_id_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_id_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_iec958
void snd_ctl_elem_value_get_iec958(const snd_ctl_elem_value_t * obj, snd_aes_iec958_t * ptr) {
    snd_ctl_elem_value_get_iec958_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_iec958_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_iec958_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_index
unsigned int snd_ctl_elem_value_get_index(const snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_get_index_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_index_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_index_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_integer
long snd_ctl_elem_value_get_integer(const snd_ctl_elem_value_t * obj, unsigned int idx) {
    snd_ctl_elem_value_get_integer_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_integer_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_integer_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_integer64
long long snd_ctl_elem_value_get_integer64(const snd_ctl_elem_value_t * obj, unsigned int idx) {
    snd_ctl_elem_value_get_integer64_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_integer64_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_integer64_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    long long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_interface
snd_ctl_elem_iface_t snd_ctl_elem_value_get_interface(const snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_get_interface_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_interface_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_interface_INDEX;
    packed_data->args.a1 = obj;
    snd_ctl_elem_iface_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_name
const char * snd_ctl_elem_value_get_name(const snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_get_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_name_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_numid
unsigned int snd_ctl_elem_value_get_numid(const snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_get_numid_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_numid_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_numid_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_get_subdevice
unsigned int snd_ctl_elem_value_get_subdevice(const snd_ctl_elem_value_t * obj) {
    snd_ctl_elem_value_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_get_subdevice_INDEXED));
    packed_data->func = snd_ctl_elem_value_get_subdevice_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_malloc
int snd_ctl_elem_value_malloc(snd_ctl_elem_value_t ** ptr) {
    snd_ctl_elem_value_malloc_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_malloc_INDEXED));
    packed_data->func = snd_ctl_elem_value_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_boolean
void snd_ctl_elem_value_set_boolean(snd_ctl_elem_value_t * obj, unsigned int idx, long val) {
    snd_ctl_elem_value_set_boolean_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_boolean_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_boolean_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_byte
void snd_ctl_elem_value_set_byte(snd_ctl_elem_value_t * obj, unsigned int idx, unsigned char val) {
    snd_ctl_elem_value_set_byte_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_byte_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_byte_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_device
void snd_ctl_elem_value_set_device(snd_ctl_elem_value_t * obj, unsigned int val) {
    snd_ctl_elem_value_set_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_device_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_device_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_enumerated
void snd_ctl_elem_value_set_enumerated(snd_ctl_elem_value_t * obj, unsigned int idx, unsigned int val) {
    snd_ctl_elem_value_set_enumerated_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_enumerated_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_enumerated_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_id
void snd_ctl_elem_value_set_id(snd_ctl_elem_value_t * obj, const snd_ctl_elem_id_t * ptr) {
    snd_ctl_elem_value_set_id_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_id_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_id_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_iec958
void snd_ctl_elem_value_set_iec958(snd_ctl_elem_value_t * obj, const snd_aes_iec958_t * ptr) {
    snd_ctl_elem_value_set_iec958_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_iec958_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_iec958_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_index
void snd_ctl_elem_value_set_index(snd_ctl_elem_value_t * obj, unsigned int val) {
    snd_ctl_elem_value_set_index_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_index_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_index_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_integer
void snd_ctl_elem_value_set_integer(snd_ctl_elem_value_t * obj, unsigned int idx, long val) {
    snd_ctl_elem_value_set_integer_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_integer_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_integer_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_integer64
void snd_ctl_elem_value_set_integer64(snd_ctl_elem_value_t * obj, unsigned int idx, long long val) {
    snd_ctl_elem_value_set_integer64_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_integer64_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_integer64_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = idx;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_interface
void snd_ctl_elem_value_set_interface(snd_ctl_elem_value_t * obj, snd_ctl_elem_iface_t val) {
    snd_ctl_elem_value_set_interface_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_interface_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_interface_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_name
void snd_ctl_elem_value_set_name(snd_ctl_elem_value_t * obj, const char * val) {
    snd_ctl_elem_value_set_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_name_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_name_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_numid
void snd_ctl_elem_value_set_numid(snd_ctl_elem_value_t * obj, unsigned int val) {
    snd_ctl_elem_value_set_numid_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_numid_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_numid_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_set_subdevice
void snd_ctl_elem_value_set_subdevice(snd_ctl_elem_value_t * obj, unsigned int val) {
    snd_ctl_elem_value_set_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_set_subdevice_INDEXED));
    packed_data->func = snd_ctl_elem_value_set_subdevice_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_elem_value_sizeof
size_t snd_ctl_elem_value_sizeof() {
    snd_ctl_elem_value_sizeof_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_value_sizeof_INDEXED));
    packed_data->func = snd_ctl_elem_value_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_elem_write
int snd_ctl_elem_write(snd_ctl_t * ctl, snd_ctl_elem_value_t * value) {
    snd_ctl_elem_write_INDEXED *packed_data = malloc(sizeof(snd_ctl_elem_write_INDEXED));
    packed_data->func = snd_ctl_elem_write_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_clear
void snd_ctl_event_clear(snd_ctl_event_t * obj) {
    snd_ctl_event_clear_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_clear_INDEXED));
    packed_data->func = snd_ctl_event_clear_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_event_copy
void snd_ctl_event_copy(snd_ctl_event_t * dst, const snd_ctl_event_t * src) {
    snd_ctl_event_copy_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_copy_INDEXED));
    packed_data->func = snd_ctl_event_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_event_elem_get_device
unsigned int snd_ctl_event_elem_get_device(const snd_ctl_event_t * obj) {
    snd_ctl_event_elem_get_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_elem_get_device_INDEXED));
    packed_data->func = snd_ctl_event_elem_get_device_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_elem_get_id
void snd_ctl_event_elem_get_id(const snd_ctl_event_t * obj, snd_ctl_elem_id_t * ptr) {
    snd_ctl_event_elem_get_id_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_elem_get_id_INDEXED));
    packed_data->func = snd_ctl_event_elem_get_id_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_event_elem_get_index
unsigned int snd_ctl_event_elem_get_index(const snd_ctl_event_t * obj) {
    snd_ctl_event_elem_get_index_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_elem_get_index_INDEXED));
    packed_data->func = snd_ctl_event_elem_get_index_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_elem_get_interface
snd_ctl_elem_iface_t snd_ctl_event_elem_get_interface(const snd_ctl_event_t * obj) {
    snd_ctl_event_elem_get_interface_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_elem_get_interface_INDEXED));
    packed_data->func = snd_ctl_event_elem_get_interface_INDEX;
    packed_data->args.a1 = obj;
    snd_ctl_elem_iface_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_elem_get_mask
unsigned int snd_ctl_event_elem_get_mask(const snd_ctl_event_t * obj) {
    snd_ctl_event_elem_get_mask_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_elem_get_mask_INDEXED));
    packed_data->func = snd_ctl_event_elem_get_mask_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_elem_get_name
const char * snd_ctl_event_elem_get_name(const snd_ctl_event_t * obj) {
    snd_ctl_event_elem_get_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_elem_get_name_INDEXED));
    packed_data->func = snd_ctl_event_elem_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_elem_get_numid
unsigned int snd_ctl_event_elem_get_numid(const snd_ctl_event_t * obj) {
    snd_ctl_event_elem_get_numid_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_elem_get_numid_INDEXED));
    packed_data->func = snd_ctl_event_elem_get_numid_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_elem_get_subdevice
unsigned int snd_ctl_event_elem_get_subdevice(const snd_ctl_event_t * obj) {
    snd_ctl_event_elem_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_elem_get_subdevice_INDEXED));
    packed_data->func = snd_ctl_event_elem_get_subdevice_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_free
void snd_ctl_event_free(snd_ctl_event_t * obj) {
    snd_ctl_event_free_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_free_INDEXED));
    packed_data->func = snd_ctl_event_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_ctl_event_get_type
snd_ctl_event_type_t snd_ctl_event_get_type(const snd_ctl_event_t * obj) {
    snd_ctl_event_get_type_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_get_type_INDEXED));
    packed_data->func = snd_ctl_event_get_type_INDEX;
    packed_data->args.a1 = obj;
    snd_ctl_event_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_malloc
int snd_ctl_event_malloc(snd_ctl_event_t ** ptr) {
    snd_ctl_event_malloc_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_malloc_INDEXED));
    packed_data->func = snd_ctl_event_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_sizeof
size_t snd_ctl_event_sizeof() {
    snd_ctl_event_sizeof_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_sizeof_INDEXED));
    packed_data->func = snd_ctl_event_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_event_type_name
const char * snd_ctl_event_type_name(snd_ctl_event_type_t type) {
    snd_ctl_event_type_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_event_type_name_INDEXED));
    packed_data->func = snd_ctl_event_type_name_INDEX;
    packed_data->args.a1 = type;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_get_power_state
int snd_ctl_get_power_state(snd_ctl_t * ctl, unsigned int * state) {
    snd_ctl_get_power_state_INDEXED *packed_data = malloc(sizeof(snd_ctl_get_power_state_INDEXED));
    packed_data->func = snd_ctl_get_power_state_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = state;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_hwdep_info
int snd_ctl_hwdep_info(snd_ctl_t * ctl, snd_hwdep_info_t * info) {
    snd_ctl_hwdep_info_INDEXED *packed_data = malloc(sizeof(snd_ctl_hwdep_info_INDEXED));
    packed_data->func = snd_ctl_hwdep_info_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_hwdep_next_device
int snd_ctl_hwdep_next_device(snd_ctl_t * ctl, int * device) {
    snd_ctl_hwdep_next_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_hwdep_next_device_INDEXED));
    packed_data->func = snd_ctl_hwdep_next_device_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = device;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_name
const char * snd_ctl_name(snd_ctl_t * ctl) {
    snd_ctl_name_INDEXED *packed_data = malloc(sizeof(snd_ctl_name_INDEXED));
    packed_data->func = snd_ctl_name_INDEX;
    packed_data->args.a1 = ctl;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_nonblock
int snd_ctl_nonblock(snd_ctl_t * ctl, int nonblock) {
    snd_ctl_nonblock_INDEXED *packed_data = malloc(sizeof(snd_ctl_nonblock_INDEXED));
    packed_data->func = snd_ctl_nonblock_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = nonblock;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_open
int snd_ctl_open(snd_ctl_t ** ctl, const char * name, int mode) {
    snd_ctl_open_INDEXED *packed_data = malloc(sizeof(snd_ctl_open_INDEXED));
    packed_data->func = snd_ctl_open_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = name;
    packed_data->args.a3 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_open_lconf
int snd_ctl_open_lconf(snd_ctl_t ** ctl, const char * name, int mode, snd_config_t * lconf) {
    snd_ctl_open_lconf_INDEXED *packed_data = malloc(sizeof(snd_ctl_open_lconf_INDEXED));
    packed_data->func = snd_ctl_open_lconf_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = name;
    packed_data->args.a3 = mode;
    packed_data->args.a4 = lconf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_pcm_info
int snd_ctl_pcm_info(snd_ctl_t * ctl, snd_pcm_info_t * info) {
    snd_ctl_pcm_info_INDEXED *packed_data = malloc(sizeof(snd_ctl_pcm_info_INDEXED));
    packed_data->func = snd_ctl_pcm_info_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_pcm_next_device
int snd_ctl_pcm_next_device(snd_ctl_t * ctl, int * device) {
    snd_ctl_pcm_next_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_pcm_next_device_INDEXED));
    packed_data->func = snd_ctl_pcm_next_device_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = device;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_pcm_prefer_subdevice
int snd_ctl_pcm_prefer_subdevice(snd_ctl_t * ctl, int subdev) {
    snd_ctl_pcm_prefer_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_pcm_prefer_subdevice_INDEXED));
    packed_data->func = snd_ctl_pcm_prefer_subdevice_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = subdev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_poll_descriptors
int snd_ctl_poll_descriptors(snd_ctl_t * ctl, struct pollfd * pfds, unsigned int space) {
    snd_ctl_poll_descriptors_INDEXED *packed_data = malloc(sizeof(snd_ctl_poll_descriptors_INDEXED));
    packed_data->func = snd_ctl_poll_descriptors_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = space;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_poll_descriptors_count
int snd_ctl_poll_descriptors_count(snd_ctl_t * ctl) {
    snd_ctl_poll_descriptors_count_INDEXED *packed_data = malloc(sizeof(snd_ctl_poll_descriptors_count_INDEXED));
    packed_data->func = snd_ctl_poll_descriptors_count_INDEX;
    packed_data->args.a1 = ctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_poll_descriptors_revents
int snd_ctl_poll_descriptors_revents(snd_ctl_t * ctl, struct pollfd * pfds, unsigned int nfds, unsigned short * revents) {
    snd_ctl_poll_descriptors_revents_INDEXED *packed_data = malloc(sizeof(snd_ctl_poll_descriptors_revents_INDEXED));
    packed_data->func = snd_ctl_poll_descriptors_revents_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = nfds;
    packed_data->args.a4 = revents;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_rawmidi_info
int snd_ctl_rawmidi_info(snd_ctl_t * ctl, snd_rawmidi_info_t * info) {
    snd_ctl_rawmidi_info_INDEXED *packed_data = malloc(sizeof(snd_ctl_rawmidi_info_INDEXED));
    packed_data->func = snd_ctl_rawmidi_info_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_rawmidi_next_device
int snd_ctl_rawmidi_next_device(snd_ctl_t * ctl, int * device) {
    snd_ctl_rawmidi_next_device_INDEXED *packed_data = malloc(sizeof(snd_ctl_rawmidi_next_device_INDEXED));
    packed_data->func = snd_ctl_rawmidi_next_device_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = device;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_rawmidi_prefer_subdevice
int snd_ctl_rawmidi_prefer_subdevice(snd_ctl_t * ctl, int subdev) {
    snd_ctl_rawmidi_prefer_subdevice_INDEXED *packed_data = malloc(sizeof(snd_ctl_rawmidi_prefer_subdevice_INDEXED));
    packed_data->func = snd_ctl_rawmidi_prefer_subdevice_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = subdev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_read
int snd_ctl_read(snd_ctl_t * ctl, snd_ctl_event_t * event) {
    snd_ctl_read_INDEXED *packed_data = malloc(sizeof(snd_ctl_read_INDEXED));
    packed_data->func = snd_ctl_read_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = event;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_set_power_state
int snd_ctl_set_power_state(snd_ctl_t * ctl, unsigned int state) {
    snd_ctl_set_power_state_INDEXED *packed_data = malloc(sizeof(snd_ctl_set_power_state_INDEXED));
    packed_data->func = snd_ctl_set_power_state_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = state;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_subscribe_events
int snd_ctl_subscribe_events(snd_ctl_t * ctl, int subscribe) {
    snd_ctl_subscribe_events_INDEXED *packed_data = malloc(sizeof(snd_ctl_subscribe_events_INDEXED));
    packed_data->func = snd_ctl_subscribe_events_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = subscribe;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_type
snd_ctl_type_t snd_ctl_type(snd_ctl_t * ctl) {
    snd_ctl_type_INDEXED *packed_data = malloc(sizeof(snd_ctl_type_INDEXED));
    packed_data->func = snd_ctl_type_INDEX;
    packed_data->args.a1 = ctl;
    snd_ctl_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_ctl_wait
int snd_ctl_wait(snd_ctl_t * ctl, int timeout) {
    snd_ctl_wait_INDEXED *packed_data = malloc(sizeof(snd_ctl_wait_INDEXED));
    packed_data->func = snd_ctl_wait_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = timeout;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_dlclose
int snd_dlclose(void * handle) {
    snd_dlclose_INDEXED *packed_data = malloc(sizeof(snd_dlclose_INDEXED));
    packed_data->func = snd_dlclose_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_dlopen
void * snd_dlopen(const char * file, int mode) {
    snd_dlopen_INDEXED *packed_data = malloc(sizeof(snd_dlopen_INDEXED));
    packed_data->func = snd_dlopen_INDEX;
    packed_data->args.a1 = file;
    packed_data->args.a2 = mode;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_dlsym
void * snd_dlsym(void * handle, const char * name, const char * version) {
    snd_dlsym_INDEXED *packed_data = malloc(sizeof(snd_dlsym_INDEXED));
    packed_data->func = snd_dlsym_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = name;
    packed_data->args.a3 = version;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_close
int snd_hctl_close(snd_hctl_t * hctl) {
    snd_hctl_close_INDEXED *packed_data = malloc(sizeof(snd_hctl_close_INDEXED));
    packed_data->func = snd_hctl_close_INDEX;
    packed_data->args.a1 = hctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_compare_fast
int snd_hctl_compare_fast(const snd_hctl_elem_t * c1, const snd_hctl_elem_t * c2) {
    snd_hctl_compare_fast_INDEXED *packed_data = malloc(sizeof(snd_hctl_compare_fast_INDEXED));
    packed_data->func = snd_hctl_compare_fast_INDEX;
    packed_data->args.a1 = c1;
    packed_data->args.a2 = c2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_ctl
snd_ctl_t * snd_hctl_ctl(snd_hctl_t * hctl) {
    snd_hctl_ctl_INDEXED *packed_data = malloc(sizeof(snd_hctl_ctl_INDEXED));
    packed_data->func = snd_hctl_ctl_INDEX;
    packed_data->args.a1 = hctl;
    snd_ctl_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_get_callback_private
void * snd_hctl_elem_get_callback_private(const snd_hctl_elem_t * obj) {
    snd_hctl_elem_get_callback_private_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_callback_private_INDEXED));
    packed_data->func = snd_hctl_elem_get_callback_private_INDEX;
    packed_data->args.a1 = obj;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_get_device
unsigned int snd_hctl_elem_get_device(const snd_hctl_elem_t * obj) {
    snd_hctl_elem_get_device_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_device_INDEXED));
    packed_data->func = snd_hctl_elem_get_device_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_get_hctl
snd_hctl_t * snd_hctl_elem_get_hctl(snd_hctl_elem_t * elem) {
    snd_hctl_elem_get_hctl_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_hctl_INDEXED));
    packed_data->func = snd_hctl_elem_get_hctl_INDEX;
    packed_data->args.a1 = elem;
    snd_hctl_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_get_id
void snd_hctl_elem_get_id(const snd_hctl_elem_t * obj, snd_ctl_elem_id_t * ptr) {
    snd_hctl_elem_get_id_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_id_INDEXED));
    packed_data->func = snd_hctl_elem_get_id_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hctl_elem_get_index
unsigned int snd_hctl_elem_get_index(const snd_hctl_elem_t * obj) {
    snd_hctl_elem_get_index_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_index_INDEXED));
    packed_data->func = snd_hctl_elem_get_index_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_get_interface
snd_ctl_elem_iface_t snd_hctl_elem_get_interface(const snd_hctl_elem_t * obj) {
    snd_hctl_elem_get_interface_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_interface_INDEXED));
    packed_data->func = snd_hctl_elem_get_interface_INDEX;
    packed_data->args.a1 = obj;
    snd_ctl_elem_iface_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_get_name
const char * snd_hctl_elem_get_name(const snd_hctl_elem_t * obj) {
    snd_hctl_elem_get_name_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_name_INDEXED));
    packed_data->func = snd_hctl_elem_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_get_numid
unsigned int snd_hctl_elem_get_numid(const snd_hctl_elem_t * obj) {
    snd_hctl_elem_get_numid_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_numid_INDEXED));
    packed_data->func = snd_hctl_elem_get_numid_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_get_subdevice
unsigned int snd_hctl_elem_get_subdevice(const snd_hctl_elem_t * obj) {
    snd_hctl_elem_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_get_subdevice_INDEXED));
    packed_data->func = snd_hctl_elem_get_subdevice_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_info
int snd_hctl_elem_info(snd_hctl_elem_t * elem, snd_ctl_elem_info_t * info) {
    snd_hctl_elem_info_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_info_INDEXED));
    packed_data->func = snd_hctl_elem_info_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_next
snd_hctl_elem_t * snd_hctl_elem_next(snd_hctl_elem_t * elem) {
    snd_hctl_elem_next_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_next_INDEXED));
    packed_data->func = snd_hctl_elem_next_INDEX;
    packed_data->args.a1 = elem;
    snd_hctl_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_prev
snd_hctl_elem_t * snd_hctl_elem_prev(snd_hctl_elem_t * elem) {
    snd_hctl_elem_prev_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_prev_INDEXED));
    packed_data->func = snd_hctl_elem_prev_INDEX;
    packed_data->args.a1 = elem;
    snd_hctl_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_read
int snd_hctl_elem_read(snd_hctl_elem_t * elem, snd_ctl_elem_value_t * value) {
    snd_hctl_elem_read_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_read_INDEXED));
    packed_data->func = snd_hctl_elem_read_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_set_callback
void snd_hctl_elem_set_callback(snd_hctl_elem_t * obj, snd_hctl_elem_callback_t val) {
    snd_hctl_elem_set_callback_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_set_callback_INDEXED));
    packed_data->func = snd_hctl_elem_set_callback_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hctl_elem_set_callback_private
void snd_hctl_elem_set_callback_private(snd_hctl_elem_t * obj, void * val) {
    snd_hctl_elem_set_callback_private_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_set_callback_private_INDEXED));
    packed_data->func = snd_hctl_elem_set_callback_private_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hctl_elem_tlv_command
int snd_hctl_elem_tlv_command(snd_hctl_elem_t * elem, const unsigned int * tlv) {
    snd_hctl_elem_tlv_command_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_tlv_command_INDEXED));
    packed_data->func = snd_hctl_elem_tlv_command_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = tlv;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_tlv_read
int snd_hctl_elem_tlv_read(snd_hctl_elem_t * elem, unsigned int * tlv, unsigned int tlv_size) {
    snd_hctl_elem_tlv_read_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_tlv_read_INDEXED));
    packed_data->func = snd_hctl_elem_tlv_read_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = tlv;
    packed_data->args.a3 = tlv_size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_tlv_write
int snd_hctl_elem_tlv_write(snd_hctl_elem_t * elem, const unsigned int * tlv) {
    snd_hctl_elem_tlv_write_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_tlv_write_INDEXED));
    packed_data->func = snd_hctl_elem_tlv_write_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = tlv;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_elem_write
int snd_hctl_elem_write(snd_hctl_elem_t * elem, snd_ctl_elem_value_t * value) {
    snd_hctl_elem_write_INDEXED *packed_data = malloc(sizeof(snd_hctl_elem_write_INDEXED));
    packed_data->func = snd_hctl_elem_write_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_find_elem
snd_hctl_elem_t * snd_hctl_find_elem(snd_hctl_t * hctl, const snd_ctl_elem_id_t * id) {
    snd_hctl_find_elem_INDEXED *packed_data = malloc(sizeof(snd_hctl_find_elem_INDEXED));
    packed_data->func = snd_hctl_find_elem_INDEX;
    packed_data->args.a1 = hctl;
    packed_data->args.a2 = id;
    snd_hctl_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_first_elem
snd_hctl_elem_t * snd_hctl_first_elem(snd_hctl_t * hctl) {
    snd_hctl_first_elem_INDEXED *packed_data = malloc(sizeof(snd_hctl_first_elem_INDEXED));
    packed_data->func = snd_hctl_first_elem_INDEX;
    packed_data->args.a1 = hctl;
    snd_hctl_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_free
int snd_hctl_free(snd_hctl_t * hctl) {
    snd_hctl_free_INDEXED *packed_data = malloc(sizeof(snd_hctl_free_INDEXED));
    packed_data->func = snd_hctl_free_INDEX;
    packed_data->args.a1 = hctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_get_callback_private
void * snd_hctl_get_callback_private(snd_hctl_t * hctl) {
    snd_hctl_get_callback_private_INDEXED *packed_data = malloc(sizeof(snd_hctl_get_callback_private_INDEXED));
    packed_data->func = snd_hctl_get_callback_private_INDEX;
    packed_data->args.a1 = hctl;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_get_count
unsigned int snd_hctl_get_count(snd_hctl_t * hctl) {
    snd_hctl_get_count_INDEXED *packed_data = malloc(sizeof(snd_hctl_get_count_INDEXED));
    packed_data->func = snd_hctl_get_count_INDEX;
    packed_data->args.a1 = hctl;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_handle_events
int snd_hctl_handle_events(snd_hctl_t * hctl) {
    snd_hctl_handle_events_INDEXED *packed_data = malloc(sizeof(snd_hctl_handle_events_INDEXED));
    packed_data->func = snd_hctl_handle_events_INDEX;
    packed_data->args.a1 = hctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_last_elem
snd_hctl_elem_t * snd_hctl_last_elem(snd_hctl_t * hctl) {
    snd_hctl_last_elem_INDEXED *packed_data = malloc(sizeof(snd_hctl_last_elem_INDEXED));
    packed_data->func = snd_hctl_last_elem_INDEX;
    packed_data->args.a1 = hctl;
    snd_hctl_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_load
int snd_hctl_load(snd_hctl_t * hctl) {
    snd_hctl_load_INDEXED *packed_data = malloc(sizeof(snd_hctl_load_INDEXED));
    packed_data->func = snd_hctl_load_INDEX;
    packed_data->args.a1 = hctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_name
const char * snd_hctl_name(snd_hctl_t * hctl) {
    snd_hctl_name_INDEXED *packed_data = malloc(sizeof(snd_hctl_name_INDEXED));
    packed_data->func = snd_hctl_name_INDEX;
    packed_data->args.a1 = hctl;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_nonblock
int snd_hctl_nonblock(snd_hctl_t * hctl, int nonblock) {
    snd_hctl_nonblock_INDEXED *packed_data = malloc(sizeof(snd_hctl_nonblock_INDEXED));
    packed_data->func = snd_hctl_nonblock_INDEX;
    packed_data->args.a1 = hctl;
    packed_data->args.a2 = nonblock;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_open
int snd_hctl_open(snd_hctl_t ** hctl, const char * name, int mode) {
    snd_hctl_open_INDEXED *packed_data = malloc(sizeof(snd_hctl_open_INDEXED));
    packed_data->func = snd_hctl_open_INDEX;
    packed_data->args.a1 = hctl;
    packed_data->args.a2 = name;
    packed_data->args.a3 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_open_ctl
int snd_hctl_open_ctl(snd_hctl_t ** hctlp, snd_ctl_t * ctl) {
    snd_hctl_open_ctl_INDEXED *packed_data = malloc(sizeof(snd_hctl_open_ctl_INDEXED));
    packed_data->func = snd_hctl_open_ctl_INDEX;
    packed_data->args.a1 = hctlp;
    packed_data->args.a2 = ctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_poll_descriptors
int snd_hctl_poll_descriptors(snd_hctl_t * hctl, struct pollfd * pfds, unsigned int space) {
    snd_hctl_poll_descriptors_INDEXED *packed_data = malloc(sizeof(snd_hctl_poll_descriptors_INDEXED));
    packed_data->func = snd_hctl_poll_descriptors_INDEX;
    packed_data->args.a1 = hctl;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = space;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_poll_descriptors_count
int snd_hctl_poll_descriptors_count(snd_hctl_t * hctl) {
    snd_hctl_poll_descriptors_count_INDEXED *packed_data = malloc(sizeof(snd_hctl_poll_descriptors_count_INDEXED));
    packed_data->func = snd_hctl_poll_descriptors_count_INDEX;
    packed_data->args.a1 = hctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_poll_descriptors_revents
int snd_hctl_poll_descriptors_revents(snd_hctl_t * ctl, struct pollfd * pfds, unsigned int nfds, unsigned short * revents) {
    snd_hctl_poll_descriptors_revents_INDEXED *packed_data = malloc(sizeof(snd_hctl_poll_descriptors_revents_INDEXED));
    packed_data->func = snd_hctl_poll_descriptors_revents_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = nfds;
    packed_data->args.a4 = revents;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_set_callback
void snd_hctl_set_callback(snd_hctl_t * hctl, snd_hctl_callback_t callback) {
    snd_hctl_set_callback_INDEXED *packed_data = malloc(sizeof(snd_hctl_set_callback_INDEXED));
    packed_data->func = snd_hctl_set_callback_INDEX;
    packed_data->args.a1 = hctl;
    packed_data->args.a2 = callback;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hctl_set_callback_private
void snd_hctl_set_callback_private(snd_hctl_t * hctl, void * data) {
    snd_hctl_set_callback_private_INDEXED *packed_data = malloc(sizeof(snd_hctl_set_callback_private_INDEXED));
    packed_data->func = snd_hctl_set_callback_private_INDEX;
    packed_data->args.a1 = hctl;
    packed_data->args.a2 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hctl_set_compare
int snd_hctl_set_compare(snd_hctl_t * hctl, snd_hctl_compare_t hsort) {
    snd_hctl_set_compare_INDEXED *packed_data = malloc(sizeof(snd_hctl_set_compare_INDEXED));
    packed_data->func = snd_hctl_set_compare_INDEX;
    packed_data->args.a1 = hctl;
    packed_data->args.a2 = hsort;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hctl_wait
int snd_hctl_wait(snd_hctl_t * hctl, int timeout) {
    snd_hctl_wait_INDEXED *packed_data = malloc(sizeof(snd_hctl_wait_INDEXED));
    packed_data->func = snd_hctl_wait_INDEX;
    packed_data->args.a1 = hctl;
    packed_data->args.a2 = timeout;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_close
int snd_hwdep_close(snd_hwdep_t * hwdep) {
    snd_hwdep_close_INDEXED *packed_data = malloc(sizeof(snd_hwdep_close_INDEXED));
    packed_data->func = snd_hwdep_close_INDEX;
    packed_data->args.a1 = hwdep;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_copy
void snd_hwdep_dsp_image_copy(snd_hwdep_dsp_image_t * dst, const snd_hwdep_dsp_image_t * src) {
    snd_hwdep_dsp_image_copy_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_copy_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_free
void snd_hwdep_dsp_image_free(snd_hwdep_dsp_image_t * obj) {
    snd_hwdep_dsp_image_free_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_free_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_get_image
const void * snd_hwdep_dsp_image_get_image(const snd_hwdep_dsp_image_t * obj) {
    snd_hwdep_dsp_image_get_image_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_get_image_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_get_image_INDEX;
    packed_data->args.a1 = obj;
    const void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_get_index
unsigned int snd_hwdep_dsp_image_get_index(const snd_hwdep_dsp_image_t * obj) {
    snd_hwdep_dsp_image_get_index_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_get_index_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_get_index_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_get_length
size_t snd_hwdep_dsp_image_get_length(const snd_hwdep_dsp_image_t * obj) {
    snd_hwdep_dsp_image_get_length_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_get_length_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_get_length_INDEX;
    packed_data->args.a1 = obj;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_get_name
const char * snd_hwdep_dsp_image_get_name(const snd_hwdep_dsp_image_t * obj) {
    snd_hwdep_dsp_image_get_name_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_get_name_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_malloc
int snd_hwdep_dsp_image_malloc(snd_hwdep_dsp_image_t ** ptr) {
    snd_hwdep_dsp_image_malloc_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_malloc_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_set_image
void snd_hwdep_dsp_image_set_image(snd_hwdep_dsp_image_t * obj, void * buffer) {
    snd_hwdep_dsp_image_set_image_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_set_image_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_set_image_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_set_index
void snd_hwdep_dsp_image_set_index(snd_hwdep_dsp_image_t * obj, unsigned int _index) {
    snd_hwdep_dsp_image_set_index_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_set_index_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_set_index_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = _index;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_set_length
void snd_hwdep_dsp_image_set_length(snd_hwdep_dsp_image_t * obj, size_t length) {
    snd_hwdep_dsp_image_set_length_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_set_length_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_set_length_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = length;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_set_name
void snd_hwdep_dsp_image_set_name(snd_hwdep_dsp_image_t * obj, const char * name) {
    snd_hwdep_dsp_image_set_name_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_set_name_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_set_name_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hwdep_dsp_image_sizeof
size_t snd_hwdep_dsp_image_sizeof() {
    snd_hwdep_dsp_image_sizeof_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_image_sizeof_INDEXED));
    packed_data->func = snd_hwdep_dsp_image_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_load
int snd_hwdep_dsp_load(snd_hwdep_t * hwdep, snd_hwdep_dsp_image_t * block) {
    snd_hwdep_dsp_load_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_load_INDEXED));
    packed_data->func = snd_hwdep_dsp_load_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = block;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status
int snd_hwdep_dsp_status(snd_hwdep_t * hwdep, snd_hwdep_dsp_status_t * status) {
    snd_hwdep_dsp_status_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = status;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_copy
void snd_hwdep_dsp_status_copy(snd_hwdep_dsp_status_t * dst, const snd_hwdep_dsp_status_t * src) {
    snd_hwdep_dsp_status_copy_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_copy_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_free
void snd_hwdep_dsp_status_free(snd_hwdep_dsp_status_t * obj) {
    snd_hwdep_dsp_status_free_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_free_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_get_chip_ready
unsigned int snd_hwdep_dsp_status_get_chip_ready(const snd_hwdep_dsp_status_t * obj) {
    snd_hwdep_dsp_status_get_chip_ready_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_get_chip_ready_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_get_chip_ready_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_get_dsp_loaded
unsigned int snd_hwdep_dsp_status_get_dsp_loaded(const snd_hwdep_dsp_status_t * obj) {
    snd_hwdep_dsp_status_get_dsp_loaded_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_get_dsp_loaded_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_get_dsp_loaded_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_get_id
const char * snd_hwdep_dsp_status_get_id(const snd_hwdep_dsp_status_t * obj) {
    snd_hwdep_dsp_status_get_id_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_get_id_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_get_id_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_get_num_dsps
unsigned int snd_hwdep_dsp_status_get_num_dsps(const snd_hwdep_dsp_status_t * obj) {
    snd_hwdep_dsp_status_get_num_dsps_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_get_num_dsps_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_get_num_dsps_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_get_version
unsigned int snd_hwdep_dsp_status_get_version(const snd_hwdep_dsp_status_t * obj) {
    snd_hwdep_dsp_status_get_version_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_get_version_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_get_version_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_malloc
int snd_hwdep_dsp_status_malloc(snd_hwdep_dsp_status_t ** ptr) {
    snd_hwdep_dsp_status_malloc_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_malloc_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_dsp_status_sizeof
size_t snd_hwdep_dsp_status_sizeof() {
    snd_hwdep_dsp_status_sizeof_INDEXED *packed_data = malloc(sizeof(snd_hwdep_dsp_status_sizeof_INDEXED));
    packed_data->func = snd_hwdep_dsp_status_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_info
int snd_hwdep_info(snd_hwdep_t * hwdep, snd_hwdep_info_t * info) {
    snd_hwdep_info_INDEXED *packed_data = malloc(sizeof(snd_hwdep_info_INDEXED));
    packed_data->func = snd_hwdep_info_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_info_sizeof
size_t snd_hwdep_info_sizeof() {
    snd_hwdep_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_hwdep_info_sizeof_INDEXED));
    packed_data->func = snd_hwdep_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_ioctl
int snd_hwdep_ioctl(snd_hwdep_t * hwdep, unsigned int request, void * arg) {
    snd_hwdep_ioctl_INDEXED *packed_data = malloc(sizeof(snd_hwdep_ioctl_INDEXED));
    packed_data->func = snd_hwdep_ioctl_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = request;
    packed_data->args.a3 = arg;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_nonblock
int snd_hwdep_nonblock(snd_hwdep_t * hwdep, int nonblock) {
    snd_hwdep_nonblock_INDEXED *packed_data = malloc(sizeof(snd_hwdep_nonblock_INDEXED));
    packed_data->func = snd_hwdep_nonblock_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = nonblock;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_open
int snd_hwdep_open(snd_hwdep_t ** hwdep, const char * name, int mode) {
    snd_hwdep_open_INDEXED *packed_data = malloc(sizeof(snd_hwdep_open_INDEXED));
    packed_data->func = snd_hwdep_open_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = name;
    packed_data->args.a3 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_poll_descriptors
int snd_hwdep_poll_descriptors(snd_hwdep_t * hwdep, struct pollfd * pfds, unsigned int space) {
    snd_hwdep_poll_descriptors_INDEXED *packed_data = malloc(sizeof(snd_hwdep_poll_descriptors_INDEXED));
    packed_data->func = snd_hwdep_poll_descriptors_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = space;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_poll_descriptors_revents
int snd_hwdep_poll_descriptors_revents(snd_hwdep_t * hwdep, struct pollfd * pfds, unsigned int nfds, unsigned short * revents) {
    snd_hwdep_poll_descriptors_revents_INDEXED *packed_data = malloc(sizeof(snd_hwdep_poll_descriptors_revents_INDEXED));
    packed_data->func = snd_hwdep_poll_descriptors_revents_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = nfds;
    packed_data->args.a4 = revents;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_read
ssize_t snd_hwdep_read(snd_hwdep_t * hwdep, void * buffer, size_t size) {
    snd_hwdep_read_INDEXED *packed_data = malloc(sizeof(snd_hwdep_read_INDEXED));
    packed_data->func = snd_hwdep_read_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_hwdep_write
ssize_t snd_hwdep_write(snd_hwdep_t * hwdep, const void * buffer, size_t size) {
    snd_hwdep_write_INDEXED *packed_data = malloc(sizeof(snd_hwdep_write_INDEXED));
    packed_data->func = snd_hwdep_write_INDEX;
    packed_data->args.a1 = hwdep;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_input_buffer_open
int snd_input_buffer_open(snd_input_t ** inputp, const char * buffer, ssize_t size) {
    snd_input_buffer_open_INDEXED *packed_data = malloc(sizeof(snd_input_buffer_open_INDEXED));
    packed_data->func = snd_input_buffer_open_INDEX;
    packed_data->args.a1 = inputp;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_input_close
int snd_input_close(snd_input_t * input) {
    snd_input_close_INDEXED *packed_data = malloc(sizeof(snd_input_close_INDEXED));
    packed_data->func = snd_input_close_INDEX;
    packed_data->args.a1 = input;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_input_getc
int snd_input_getc(snd_input_t * input) {
    snd_input_getc_INDEXED *packed_data = malloc(sizeof(snd_input_getc_INDEXED));
    packed_data->func = snd_input_getc_INDEX;
    packed_data->args.a1 = input;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_input_gets
char * snd_input_gets(snd_input_t * input, char * str, size_t size) {
    snd_input_gets_INDEXED *packed_data = malloc(sizeof(snd_input_gets_INDEXED));
    packed_data->func = snd_input_gets_INDEX;
    packed_data->args.a1 = input;
    packed_data->args.a2 = str;
    packed_data->args.a3 = size;
    char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_input_stdio_attach
int snd_input_stdio_attach(snd_input_t ** inputp, FILE * fp, int _close) {
    snd_input_stdio_attach_INDEXED *packed_data = malloc(sizeof(snd_input_stdio_attach_INDEXED));
    packed_data->func = snd_input_stdio_attach_INDEX;
    packed_data->args.a1 = inputp;
    packed_data->args.a2 = fp;
    packed_data->args.a3 = _close;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_input_stdio_open
int snd_input_stdio_open(snd_input_t ** inputp, const char * file, const char * mode) {
    snd_input_stdio_open_INDEXED *packed_data = malloc(sizeof(snd_input_stdio_open_INDEXED));
    packed_data->func = snd_input_stdio_open_INDEX;
    packed_data->args.a1 = inputp;
    packed_data->args.a2 = file;
    packed_data->args.a3 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_input_ungetc
int snd_input_ungetc(snd_input_t * input, int c) {
    snd_input_ungetc_INDEXED *packed_data = malloc(sizeof(snd_input_ungetc_INDEXED));
    packed_data->func = snd_input_ungetc_INDEX;
    packed_data->args.a1 = input;
    packed_data->args.a2 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_lib_error_set_handler
int snd_lib_error_set_handler(snd_lib_error_handler_t handler) {
    snd_lib_error_set_handler_INDEXED *packed_data = malloc(sizeof(snd_lib_error_set_handler_INDEXED));
    packed_data->func = snd_lib_error_set_handler_INDEX;
    packed_data->args.a1 = handler;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_midi_event_decode
long snd_midi_event_decode(snd_midi_event_t * dev, unsigned char * buf, long count, const snd_seq_event_t * ev) {
    snd_midi_event_decode_INDEXED *packed_data = malloc(sizeof(snd_midi_event_decode_INDEXED));
    packed_data->func = snd_midi_event_decode_INDEX;
    packed_data->args.a1 = dev;
    packed_data->args.a2 = buf;
    packed_data->args.a3 = count;
    packed_data->args.a4 = ev;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_midi_event_encode
long snd_midi_event_encode(snd_midi_event_t * dev, const unsigned char * buf, long count, snd_seq_event_t * ev) {
    snd_midi_event_encode_INDEXED *packed_data = malloc(sizeof(snd_midi_event_encode_INDEXED));
    packed_data->func = snd_midi_event_encode_INDEX;
    packed_data->args.a1 = dev;
    packed_data->args.a2 = buf;
    packed_data->args.a3 = count;
    packed_data->args.a4 = ev;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_midi_event_encode_byte
int snd_midi_event_encode_byte(snd_midi_event_t * dev, int c, snd_seq_event_t * ev) {
    snd_midi_event_encode_byte_INDEXED *packed_data = malloc(sizeof(snd_midi_event_encode_byte_INDEXED));
    packed_data->func = snd_midi_event_encode_byte_INDEX;
    packed_data->args.a1 = dev;
    packed_data->args.a2 = c;
    packed_data->args.a3 = ev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_midi_event_free
void snd_midi_event_free(snd_midi_event_t * dev) {
    snd_midi_event_free_INDEXED *packed_data = malloc(sizeof(snd_midi_event_free_INDEXED));
    packed_data->func = snd_midi_event_free_INDEX;
    packed_data->args.a1 = dev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_midi_event_init
void snd_midi_event_init(snd_midi_event_t * dev) {
    snd_midi_event_init_INDEXED *packed_data = malloc(sizeof(snd_midi_event_init_INDEXED));
    packed_data->func = snd_midi_event_init_INDEX;
    packed_data->args.a1 = dev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_midi_event_new
int snd_midi_event_new(size_t bufsize, snd_midi_event_t ** rdev) {
    snd_midi_event_new_INDEXED *packed_data = malloc(sizeof(snd_midi_event_new_INDEXED));
    packed_data->func = snd_midi_event_new_INDEX;
    packed_data->args.a1 = bufsize;
    packed_data->args.a2 = rdev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_midi_event_no_status
void snd_midi_event_no_status(snd_midi_event_t * dev, int on) {
    snd_midi_event_no_status_INDEXED *packed_data = malloc(sizeof(snd_midi_event_no_status_INDEXED));
    packed_data->func = snd_midi_event_no_status_INDEX;
    packed_data->args.a1 = dev;
    packed_data->args.a2 = on;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_midi_event_reset_decode
void snd_midi_event_reset_decode(snd_midi_event_t * dev) {
    snd_midi_event_reset_decode_INDEXED *packed_data = malloc(sizeof(snd_midi_event_reset_decode_INDEXED));
    packed_data->func = snd_midi_event_reset_decode_INDEX;
    packed_data->args.a1 = dev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_midi_event_reset_encode
void snd_midi_event_reset_encode(snd_midi_event_t * dev) {
    snd_midi_event_reset_encode_INDEXED *packed_data = malloc(sizeof(snd_midi_event_reset_encode_INDEXED));
    packed_data->func = snd_midi_event_reset_encode_INDEX;
    packed_data->args.a1 = dev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_midi_event_resize_buffer
int snd_midi_event_resize_buffer(snd_midi_event_t * dev, size_t bufsize) {
    snd_midi_event_resize_buffer_INDEXED *packed_data = malloc(sizeof(snd_midi_event_resize_buffer_INDEXED));
    packed_data->func = snd_midi_event_resize_buffer_INDEX;
    packed_data->args.a1 = dev;
    packed_data->args.a2 = bufsize;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_add_elem
int snd_mixer_add_elem(snd_mixer_t * mixer, snd_mixer_elem_t * elem) {
    snd_mixer_add_elem_INDEXED *packed_data = malloc(sizeof(snd_mixer_add_elem_INDEXED));
    packed_data->func = snd_mixer_add_elem_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_attach
int snd_mixer_attach(snd_mixer_t * mixer, const char * name) {
    snd_mixer_attach_INDEXED *packed_data = malloc(sizeof(snd_mixer_attach_INDEXED));
    packed_data->func = snd_mixer_attach_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_attach_hctl
int snd_mixer_attach_hctl(snd_mixer_t * mixer, snd_hctl_t * hctl) {
    snd_mixer_attach_hctl_INDEXED *packed_data = malloc(sizeof(snd_mixer_attach_hctl_INDEXED));
    packed_data->func = snd_mixer_attach_hctl_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = hctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_copy
void snd_mixer_class_copy(snd_mixer_class_t * dst, const snd_mixer_class_t * src) {
    snd_mixer_class_copy_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_copy_INDEXED));
    packed_data->func = snd_mixer_class_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_class_free
void snd_mixer_class_free(snd_mixer_class_t * obj) {
    snd_mixer_class_free_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_free_INDEXED));
    packed_data->func = snd_mixer_class_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_class_get_compare
snd_mixer_compare_t snd_mixer_class_get_compare(const snd_mixer_class_t * class_) {
    snd_mixer_class_get_compare_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_get_compare_INDEXED));
    packed_data->func = snd_mixer_class_get_compare_INDEX;
    packed_data->args.a1 = class_;
    snd_mixer_compare_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_get_event
snd_mixer_event_t snd_mixer_class_get_event(const snd_mixer_class_t * class_) {
    snd_mixer_class_get_event_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_get_event_INDEXED));
    packed_data->func = snd_mixer_class_get_event_INDEX;
    packed_data->args.a1 = class_;
    snd_mixer_event_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_get_mixer
snd_mixer_t * snd_mixer_class_get_mixer(const snd_mixer_class_t * class_) {
    snd_mixer_class_get_mixer_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_get_mixer_INDEXED));
    packed_data->func = snd_mixer_class_get_mixer_INDEX;
    packed_data->args.a1 = class_;
    snd_mixer_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_get_private
void * snd_mixer_class_get_private(const snd_mixer_class_t * class_) {
    snd_mixer_class_get_private_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_get_private_INDEXED));
    packed_data->func = snd_mixer_class_get_private_INDEX;
    packed_data->args.a1 = class_;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_malloc
int snd_mixer_class_malloc(snd_mixer_class_t ** ptr) {
    snd_mixer_class_malloc_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_malloc_INDEXED));
    packed_data->func = snd_mixer_class_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_register
int snd_mixer_class_register(snd_mixer_class_t * class_, snd_mixer_t * mixer) {
    snd_mixer_class_register_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_register_INDEXED));
    packed_data->func = snd_mixer_class_register_INDEX;
    packed_data->args.a1 = class_;
    packed_data->args.a2 = mixer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_set_compare
int snd_mixer_class_set_compare(snd_mixer_class_t * class_, snd_mixer_compare_t compare) {
    snd_mixer_class_set_compare_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_set_compare_INDEXED));
    packed_data->func = snd_mixer_class_set_compare_INDEX;
    packed_data->args.a1 = class_;
    packed_data->args.a2 = compare;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_set_event
int snd_mixer_class_set_event(snd_mixer_class_t * class_, snd_mixer_event_t event) {
    snd_mixer_class_set_event_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_set_event_INDEXED));
    packed_data->func = snd_mixer_class_set_event_INDEX;
    packed_data->args.a1 = class_;
    packed_data->args.a2 = event;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_set_private
int snd_mixer_class_set_private(snd_mixer_class_t * class_, void * private_data) {
    snd_mixer_class_set_private_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_set_private_INDEXED));
    packed_data->func = snd_mixer_class_set_private_INDEX;
    packed_data->args.a1 = class_;
    packed_data->args.a2 = private_data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_sizeof
size_t snd_mixer_class_sizeof() {
    snd_mixer_class_sizeof_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_sizeof_INDEXED));
    packed_data->func = snd_mixer_class_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_class_unregister
int snd_mixer_class_unregister(snd_mixer_class_t * clss) {
    snd_mixer_class_unregister_INDEXED *packed_data = malloc(sizeof(snd_mixer_class_unregister_INDEXED));
    packed_data->func = snd_mixer_class_unregister_INDEX;
    packed_data->args.a1 = clss;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_close
int snd_mixer_close(snd_mixer_t * mixer) {
    snd_mixer_close_INDEXED *packed_data = malloc(sizeof(snd_mixer_close_INDEXED));
    packed_data->func = snd_mixer_close_INDEX;
    packed_data->args.a1 = mixer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_detach
int snd_mixer_detach(snd_mixer_t * mixer, const char * name) {
    snd_mixer_detach_INDEXED *packed_data = malloc(sizeof(snd_mixer_detach_INDEXED));
    packed_data->func = snd_mixer_detach_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_detach_hctl
int snd_mixer_detach_hctl(snd_mixer_t * mixer, snd_hctl_t * hctl) {
    snd_mixer_detach_hctl_INDEXED *packed_data = malloc(sizeof(snd_mixer_detach_hctl_INDEXED));
    packed_data->func = snd_mixer_detach_hctl_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = hctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_add
int snd_mixer_elem_add(snd_mixer_elem_t * elem, snd_mixer_class_t * class_) {
    snd_mixer_elem_add_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_add_INDEXED));
    packed_data->func = snd_mixer_elem_add_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = class_;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_attach
int snd_mixer_elem_attach(snd_mixer_elem_t * melem, snd_hctl_elem_t * helem) {
    snd_mixer_elem_attach_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_attach_INDEXED));
    packed_data->func = snd_mixer_elem_attach_INDEX;
    packed_data->args.a1 = melem;
    packed_data->args.a2 = helem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_detach
int snd_mixer_elem_detach(snd_mixer_elem_t * melem, snd_hctl_elem_t * helem) {
    snd_mixer_elem_detach_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_detach_INDEXED));
    packed_data->func = snd_mixer_elem_detach_INDEX;
    packed_data->args.a1 = melem;
    packed_data->args.a2 = helem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_empty
int snd_mixer_elem_empty(snd_mixer_elem_t * melem) {
    snd_mixer_elem_empty_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_empty_INDEXED));
    packed_data->func = snd_mixer_elem_empty_INDEX;
    packed_data->args.a1 = melem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_free
void snd_mixer_elem_free(snd_mixer_elem_t * elem) {
    snd_mixer_elem_free_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_free_INDEXED));
    packed_data->func = snd_mixer_elem_free_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_elem_get_callback_private
void * snd_mixer_elem_get_callback_private(const snd_mixer_elem_t * obj) {
    snd_mixer_elem_get_callback_private_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_get_callback_private_INDEXED));
    packed_data->func = snd_mixer_elem_get_callback_private_INDEX;
    packed_data->args.a1 = obj;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_get_private
void * snd_mixer_elem_get_private(const snd_mixer_elem_t * melem) {
    snd_mixer_elem_get_private_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_get_private_INDEXED));
    packed_data->func = snd_mixer_elem_get_private_INDEX;
    packed_data->args.a1 = melem;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_get_type
snd_mixer_elem_type_t snd_mixer_elem_get_type(const snd_mixer_elem_t * obj) {
    snd_mixer_elem_get_type_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_get_type_INDEXED));
    packed_data->func = snd_mixer_elem_get_type_INDEX;
    packed_data->args.a1 = obj;
    snd_mixer_elem_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_info
int snd_mixer_elem_info(snd_mixer_elem_t * elem) {
    snd_mixer_elem_info_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_info_INDEXED));
    packed_data->func = snd_mixer_elem_info_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_next
snd_mixer_elem_t * snd_mixer_elem_next(snd_mixer_elem_t * elem) {
    snd_mixer_elem_next_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_next_INDEXED));
    packed_data->func = snd_mixer_elem_next_INDEX;
    packed_data->args.a1 = elem;
    snd_mixer_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_prev
snd_mixer_elem_t * snd_mixer_elem_prev(snd_mixer_elem_t * elem) {
    snd_mixer_elem_prev_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_prev_INDEXED));
    packed_data->func = snd_mixer_elem_prev_INDEX;
    packed_data->args.a1 = elem;
    snd_mixer_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_remove
int snd_mixer_elem_remove(snd_mixer_elem_t * elem) {
    snd_mixer_elem_remove_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_remove_INDEXED));
    packed_data->func = snd_mixer_elem_remove_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_elem_set_callback
void snd_mixer_elem_set_callback(snd_mixer_elem_t * obj, snd_mixer_elem_callback_t val) {
    snd_mixer_elem_set_callback_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_set_callback_INDEXED));
    packed_data->func = snd_mixer_elem_set_callback_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_elem_set_callback_private
void snd_mixer_elem_set_callback_private(snd_mixer_elem_t * obj, void * val) {
    snd_mixer_elem_set_callback_private_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_set_callback_private_INDEXED));
    packed_data->func = snd_mixer_elem_set_callback_private_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_elem_value
int snd_mixer_elem_value(snd_mixer_elem_t * elem) {
    snd_mixer_elem_value_INDEXED *packed_data = malloc(sizeof(snd_mixer_elem_value_INDEXED));
    packed_data->func = snd_mixer_elem_value_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_find_selem
snd_mixer_elem_t * snd_mixer_find_selem(snd_mixer_t * mixer, const snd_mixer_selem_id_t * id) {
    snd_mixer_find_selem_INDEXED *packed_data = malloc(sizeof(snd_mixer_find_selem_INDEXED));
    packed_data->func = snd_mixer_find_selem_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = id;
    snd_mixer_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_first_elem
snd_mixer_elem_t * snd_mixer_first_elem(snd_mixer_t * mixer) {
    snd_mixer_first_elem_INDEXED *packed_data = malloc(sizeof(snd_mixer_first_elem_INDEXED));
    packed_data->func = snd_mixer_first_elem_INDEX;
    packed_data->args.a1 = mixer;
    snd_mixer_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_free
void snd_mixer_free(snd_mixer_t * mixer) {
    snd_mixer_free_INDEXED *packed_data = malloc(sizeof(snd_mixer_free_INDEXED));
    packed_data->func = snd_mixer_free_INDEX;
    packed_data->args.a1 = mixer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_get_callback_private
void * snd_mixer_get_callback_private(const snd_mixer_t * obj) {
    snd_mixer_get_callback_private_INDEXED *packed_data = malloc(sizeof(snd_mixer_get_callback_private_INDEXED));
    packed_data->func = snd_mixer_get_callback_private_INDEX;
    packed_data->args.a1 = obj;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_get_count
unsigned int snd_mixer_get_count(const snd_mixer_t * obj) {
    snd_mixer_get_count_INDEXED *packed_data = malloc(sizeof(snd_mixer_get_count_INDEXED));
    packed_data->func = snd_mixer_get_count_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_get_hctl
int snd_mixer_get_hctl(snd_mixer_t * mixer, const char * name, snd_hctl_t ** hctl) {
    snd_mixer_get_hctl_INDEXED *packed_data = malloc(sizeof(snd_mixer_get_hctl_INDEXED));
    packed_data->func = snd_mixer_get_hctl_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = name;
    packed_data->args.a3 = hctl;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_handle_events
int snd_mixer_handle_events(snd_mixer_t * mixer) {
    snd_mixer_handle_events_INDEXED *packed_data = malloc(sizeof(snd_mixer_handle_events_INDEXED));
    packed_data->func = snd_mixer_handle_events_INDEX;
    packed_data->args.a1 = mixer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_last_elem
snd_mixer_elem_t * snd_mixer_last_elem(snd_mixer_t * mixer) {
    snd_mixer_last_elem_INDEXED *packed_data = malloc(sizeof(snd_mixer_last_elem_INDEXED));
    packed_data->func = snd_mixer_last_elem_INDEX;
    packed_data->args.a1 = mixer;
    snd_mixer_elem_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_load
int snd_mixer_load(snd_mixer_t * mixer) {
    snd_mixer_load_INDEXED *packed_data = malloc(sizeof(snd_mixer_load_INDEXED));
    packed_data->func = snd_mixer_load_INDEX;
    packed_data->args.a1 = mixer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_open
int snd_mixer_open(snd_mixer_t ** mixer, int mode) {
    snd_mixer_open_INDEXED *packed_data = malloc(sizeof(snd_mixer_open_INDEXED));
    packed_data->func = snd_mixer_open_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_poll_descriptors
int snd_mixer_poll_descriptors(snd_mixer_t * mixer, struct pollfd * pfds, unsigned int space) {
    snd_mixer_poll_descriptors_INDEXED *packed_data = malloc(sizeof(snd_mixer_poll_descriptors_INDEXED));
    packed_data->func = snd_mixer_poll_descriptors_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = space;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_poll_descriptors_count
int snd_mixer_poll_descriptors_count(snd_mixer_t * mixer) {
    snd_mixer_poll_descriptors_count_INDEXED *packed_data = malloc(sizeof(snd_mixer_poll_descriptors_count_INDEXED));
    packed_data->func = snd_mixer_poll_descriptors_count_INDEX;
    packed_data->args.a1 = mixer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_poll_descriptors_revents
int snd_mixer_poll_descriptors_revents(snd_mixer_t * mixer, struct pollfd * pfds, unsigned int nfds, unsigned short * revents) {
    snd_mixer_poll_descriptors_revents_INDEXED *packed_data = malloc(sizeof(snd_mixer_poll_descriptors_revents_INDEXED));
    packed_data->func = snd_mixer_poll_descriptors_revents_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = nfds;
    packed_data->args.a4 = revents;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_remove_elem
int snd_mixer_remove_elem(snd_mixer_t * mixer, snd_mixer_elem_t * elem) {
    snd_mixer_remove_elem_INDEXED *packed_data = malloc(sizeof(snd_mixer_remove_elem_INDEXED));
    packed_data->func = snd_mixer_remove_elem_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_channel_name
const char * snd_mixer_selem_channel_name(snd_mixer_selem_channel_id_t channel) {
    snd_mixer_selem_channel_name_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_channel_name_INDEXED));
    packed_data->func = snd_mixer_selem_channel_name_INDEX;
    packed_data->args.a1 = channel;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_capture_dB
int snd_mixer_selem_get_capture_dB(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, long * value) {
    snd_mixer_selem_get_capture_dB_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_capture_dB_INDEXED));
    packed_data->func = snd_mixer_selem_get_capture_dB_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_capture_dB_range
int snd_mixer_selem_get_capture_dB_range(snd_mixer_elem_t * elem, long * min, long * max) {
    snd_mixer_selem_get_capture_dB_range_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_capture_dB_range_INDEXED));
    packed_data->func = snd_mixer_selem_get_capture_dB_range_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = min;
    packed_data->args.a3 = max;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_capture_group
int snd_mixer_selem_get_capture_group(snd_mixer_elem_t * elem) {
    snd_mixer_selem_get_capture_group_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_capture_group_INDEXED));
    packed_data->func = snd_mixer_selem_get_capture_group_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_capture_switch
int snd_mixer_selem_get_capture_switch(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, int * value) {
    snd_mixer_selem_get_capture_switch_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_capture_switch_INDEXED));
    packed_data->func = snd_mixer_selem_get_capture_switch_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_capture_volume
int snd_mixer_selem_get_capture_volume(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, long * value) {
    snd_mixer_selem_get_capture_volume_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_capture_volume_INDEXED));
    packed_data->func = snd_mixer_selem_get_capture_volume_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_capture_volume_range
int snd_mixer_selem_get_capture_volume_range(snd_mixer_elem_t * elem, long * min, long * max) {
    snd_mixer_selem_get_capture_volume_range_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_capture_volume_range_INDEXED));
    packed_data->func = snd_mixer_selem_get_capture_volume_range_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = min;
    packed_data->args.a3 = max;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_enum_item
int snd_mixer_selem_get_enum_item(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, unsigned int * idxp) {
    snd_mixer_selem_get_enum_item_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_enum_item_INDEXED));
    packed_data->func = snd_mixer_selem_get_enum_item_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = idxp;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_enum_item_name
int snd_mixer_selem_get_enum_item_name(snd_mixer_elem_t * elem, unsigned int idx, size_t maxlen, char * str) {
    snd_mixer_selem_get_enum_item_name_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_enum_item_name_INDEXED));
    packed_data->func = snd_mixer_selem_get_enum_item_name_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = idx;
    packed_data->args.a3 = maxlen;
    packed_data->args.a4 = str;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_enum_items
int snd_mixer_selem_get_enum_items(snd_mixer_elem_t * elem) {
    snd_mixer_selem_get_enum_items_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_enum_items_INDEXED));
    packed_data->func = snd_mixer_selem_get_enum_items_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_id
void snd_mixer_selem_get_id(snd_mixer_elem_t * element, snd_mixer_selem_id_t * id) {
    snd_mixer_selem_get_id_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_id_INDEXED));
    packed_data->func = snd_mixer_selem_get_id_INDEX;
    packed_data->args.a1 = element;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_selem_get_index
unsigned int snd_mixer_selem_get_index(snd_mixer_elem_t * elem) {
    snd_mixer_selem_get_index_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_index_INDEXED));
    packed_data->func = snd_mixer_selem_get_index_INDEX;
    packed_data->args.a1 = elem;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_name
const char * snd_mixer_selem_get_name(snd_mixer_elem_t * elem) {
    snd_mixer_selem_get_name_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_name_INDEXED));
    packed_data->func = snd_mixer_selem_get_name_INDEX;
    packed_data->args.a1 = elem;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_playback_dB
int snd_mixer_selem_get_playback_dB(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, long * value) {
    snd_mixer_selem_get_playback_dB_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_playback_dB_INDEXED));
    packed_data->func = snd_mixer_selem_get_playback_dB_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_playback_dB_range
int snd_mixer_selem_get_playback_dB_range(snd_mixer_elem_t * elem, long * min, long * max) {
    snd_mixer_selem_get_playback_dB_range_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_playback_dB_range_INDEXED));
    packed_data->func = snd_mixer_selem_get_playback_dB_range_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = min;
    packed_data->args.a3 = max;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_playback_switch
int snd_mixer_selem_get_playback_switch(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, int * value) {
    snd_mixer_selem_get_playback_switch_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_playback_switch_INDEXED));
    packed_data->func = snd_mixer_selem_get_playback_switch_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_playback_volume
int snd_mixer_selem_get_playback_volume(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, long * value) {
    snd_mixer_selem_get_playback_volume_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_playback_volume_INDEXED));
    packed_data->func = snd_mixer_selem_get_playback_volume_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_get_playback_volume_range
int snd_mixer_selem_get_playback_volume_range(snd_mixer_elem_t * elem, long * min, long * max) {
    snd_mixer_selem_get_playback_volume_range_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_get_playback_volume_range_INDEXED));
    packed_data->func = snd_mixer_selem_get_playback_volume_range_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = min;
    packed_data->args.a3 = max;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_capture_channel
int snd_mixer_selem_has_capture_channel(snd_mixer_elem_t * obj, snd_mixer_selem_channel_id_t channel) {
    snd_mixer_selem_has_capture_channel_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_capture_channel_INDEXED));
    packed_data->func = snd_mixer_selem_has_capture_channel_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = channel;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_capture_switch
int snd_mixer_selem_has_capture_switch(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_capture_switch_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_capture_switch_INDEXED));
    packed_data->func = snd_mixer_selem_has_capture_switch_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_capture_switch_exclusive
int snd_mixer_selem_has_capture_switch_exclusive(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_capture_switch_exclusive_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_capture_switch_exclusive_INDEXED));
    packed_data->func = snd_mixer_selem_has_capture_switch_exclusive_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_capture_switch_joined
int snd_mixer_selem_has_capture_switch_joined(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_capture_switch_joined_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_capture_switch_joined_INDEXED));
    packed_data->func = snd_mixer_selem_has_capture_switch_joined_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_capture_volume
int snd_mixer_selem_has_capture_volume(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_capture_volume_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_capture_volume_INDEXED));
    packed_data->func = snd_mixer_selem_has_capture_volume_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_capture_volume_joined
int snd_mixer_selem_has_capture_volume_joined(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_capture_volume_joined_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_capture_volume_joined_INDEXED));
    packed_data->func = snd_mixer_selem_has_capture_volume_joined_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_common_switch
int snd_mixer_selem_has_common_switch(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_common_switch_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_common_switch_INDEXED));
    packed_data->func = snd_mixer_selem_has_common_switch_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_common_volume
int snd_mixer_selem_has_common_volume(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_common_volume_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_common_volume_INDEXED));
    packed_data->func = snd_mixer_selem_has_common_volume_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_playback_channel
int snd_mixer_selem_has_playback_channel(snd_mixer_elem_t * obj, snd_mixer_selem_channel_id_t channel) {
    snd_mixer_selem_has_playback_channel_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_playback_channel_INDEXED));
    packed_data->func = snd_mixer_selem_has_playback_channel_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = channel;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_playback_switch
int snd_mixer_selem_has_playback_switch(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_playback_switch_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_playback_switch_INDEXED));
    packed_data->func = snd_mixer_selem_has_playback_switch_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_playback_switch_joined
int snd_mixer_selem_has_playback_switch_joined(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_playback_switch_joined_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_playback_switch_joined_INDEXED));
    packed_data->func = snd_mixer_selem_has_playback_switch_joined_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_playback_volume
int snd_mixer_selem_has_playback_volume(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_playback_volume_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_playback_volume_INDEXED));
    packed_data->func = snd_mixer_selem_has_playback_volume_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_has_playback_volume_joined
int snd_mixer_selem_has_playback_volume_joined(snd_mixer_elem_t * elem) {
    snd_mixer_selem_has_playback_volume_joined_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_has_playback_volume_joined_INDEXED));
    packed_data->func = snd_mixer_selem_has_playback_volume_joined_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_id_copy
void snd_mixer_selem_id_copy(snd_mixer_selem_id_t * dst, const snd_mixer_selem_id_t * src) {
    snd_mixer_selem_id_copy_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_id_copy_INDEXED));
    packed_data->func = snd_mixer_selem_id_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_selem_id_free
void snd_mixer_selem_id_free(snd_mixer_selem_id_t * obj) {
    snd_mixer_selem_id_free_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_id_free_INDEXED));
    packed_data->func = snd_mixer_selem_id_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_selem_id_get_index
unsigned int snd_mixer_selem_id_get_index(const snd_mixer_selem_id_t * obj) {
    snd_mixer_selem_id_get_index_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_id_get_index_INDEXED));
    packed_data->func = snd_mixer_selem_id_get_index_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_id_get_name
const char * snd_mixer_selem_id_get_name(const snd_mixer_selem_id_t * obj) {
    snd_mixer_selem_id_get_name_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_id_get_name_INDEXED));
    packed_data->func = snd_mixer_selem_id_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_id_malloc
int snd_mixer_selem_id_malloc(snd_mixer_selem_id_t ** ptr) {
    snd_mixer_selem_id_malloc_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_id_malloc_INDEXED));
    packed_data->func = snd_mixer_selem_id_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_id_set_index
void snd_mixer_selem_id_set_index(snd_mixer_selem_id_t * obj, unsigned int val) {
    snd_mixer_selem_id_set_index_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_id_set_index_INDEXED));
    packed_data->func = snd_mixer_selem_id_set_index_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_selem_id_set_name
void snd_mixer_selem_id_set_name(snd_mixer_selem_id_t * obj, const char * val) {
    snd_mixer_selem_id_set_name_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_id_set_name_INDEXED));
    packed_data->func = snd_mixer_selem_id_set_name_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_selem_id_sizeof
size_t snd_mixer_selem_id_sizeof() {
    snd_mixer_selem_id_sizeof_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_id_sizeof_INDEXED));
    packed_data->func = snd_mixer_selem_id_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_is_active
int snd_mixer_selem_is_active(snd_mixer_elem_t * elem) {
    snd_mixer_selem_is_active_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_is_active_INDEXED));
    packed_data->func = snd_mixer_selem_is_active_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_is_capture_mono
int snd_mixer_selem_is_capture_mono(snd_mixer_elem_t * elem) {
    snd_mixer_selem_is_capture_mono_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_is_capture_mono_INDEXED));
    packed_data->func = snd_mixer_selem_is_capture_mono_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_is_enum_capture
int snd_mixer_selem_is_enum_capture(snd_mixer_elem_t * elem) {
    snd_mixer_selem_is_enum_capture_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_is_enum_capture_INDEXED));
    packed_data->func = snd_mixer_selem_is_enum_capture_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_is_enum_playback
int snd_mixer_selem_is_enum_playback(snd_mixer_elem_t * elem) {
    snd_mixer_selem_is_enum_playback_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_is_enum_playback_INDEXED));
    packed_data->func = snd_mixer_selem_is_enum_playback_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_is_enumerated
int snd_mixer_selem_is_enumerated(snd_mixer_elem_t * elem) {
    snd_mixer_selem_is_enumerated_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_is_enumerated_INDEXED));
    packed_data->func = snd_mixer_selem_is_enumerated_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_is_playback_mono
int snd_mixer_selem_is_playback_mono(snd_mixer_elem_t * elem) {
    snd_mixer_selem_is_playback_mono_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_is_playback_mono_INDEXED));
    packed_data->func = snd_mixer_selem_is_playback_mono_INDEX;
    packed_data->args.a1 = elem;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_register
int snd_mixer_selem_register(snd_mixer_t * mixer, struct snd_mixer_selem_regopt * options, snd_mixer_class_t ** classp) {
    snd_mixer_selem_register_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_register_INDEXED));
    packed_data->func = snd_mixer_selem_register_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = options;
    packed_data->args.a3 = classp;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_capture_dB
int snd_mixer_selem_set_capture_dB(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, long value, int dir) {
    snd_mixer_selem_set_capture_dB_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_capture_dB_INDEXED));
    packed_data->func = snd_mixer_selem_set_capture_dB_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_capture_dB_all
int snd_mixer_selem_set_capture_dB_all(snd_mixer_elem_t * elem, long value, int dir) {
    snd_mixer_selem_set_capture_dB_all_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_capture_dB_all_INDEXED));
    packed_data->func = snd_mixer_selem_set_capture_dB_all_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = value;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_capture_switch
int snd_mixer_selem_set_capture_switch(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, int value) {
    snd_mixer_selem_set_capture_switch_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_capture_switch_INDEXED));
    packed_data->func = snd_mixer_selem_set_capture_switch_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_capture_switch_all
int snd_mixer_selem_set_capture_switch_all(snd_mixer_elem_t * elem, int value) {
    snd_mixer_selem_set_capture_switch_all_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_capture_switch_all_INDEXED));
    packed_data->func = snd_mixer_selem_set_capture_switch_all_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_capture_volume
int snd_mixer_selem_set_capture_volume(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, long value) {
    snd_mixer_selem_set_capture_volume_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_capture_volume_INDEXED));
    packed_data->func = snd_mixer_selem_set_capture_volume_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_capture_volume_all
int snd_mixer_selem_set_capture_volume_all(snd_mixer_elem_t * elem, long value) {
    snd_mixer_selem_set_capture_volume_all_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_capture_volume_all_INDEXED));
    packed_data->func = snd_mixer_selem_set_capture_volume_all_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_capture_volume_range
int snd_mixer_selem_set_capture_volume_range(snd_mixer_elem_t * elem, long min, long max) {
    snd_mixer_selem_set_capture_volume_range_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_capture_volume_range_INDEXED));
    packed_data->func = snd_mixer_selem_set_capture_volume_range_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = min;
    packed_data->args.a3 = max;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_enum_item
int snd_mixer_selem_set_enum_item(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, unsigned int idx) {
    snd_mixer_selem_set_enum_item_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_enum_item_INDEXED));
    packed_data->func = snd_mixer_selem_set_enum_item_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = idx;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_playback_dB
int snd_mixer_selem_set_playback_dB(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, long value, int dir) {
    snd_mixer_selem_set_playback_dB_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_playback_dB_INDEXED));
    packed_data->func = snd_mixer_selem_set_playback_dB_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_playback_dB_all
int snd_mixer_selem_set_playback_dB_all(snd_mixer_elem_t * elem, long value, int dir) {
    snd_mixer_selem_set_playback_dB_all_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_playback_dB_all_INDEXED));
    packed_data->func = snd_mixer_selem_set_playback_dB_all_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = value;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_playback_switch
int snd_mixer_selem_set_playback_switch(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, int value) {
    snd_mixer_selem_set_playback_switch_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_playback_switch_INDEXED));
    packed_data->func = snd_mixer_selem_set_playback_switch_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_playback_switch_all
int snd_mixer_selem_set_playback_switch_all(snd_mixer_elem_t * elem, int value) {
    snd_mixer_selem_set_playback_switch_all_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_playback_switch_all_INDEXED));
    packed_data->func = snd_mixer_selem_set_playback_switch_all_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_playback_volume
int snd_mixer_selem_set_playback_volume(snd_mixer_elem_t * elem, snd_mixer_selem_channel_id_t channel, long value) {
    snd_mixer_selem_set_playback_volume_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_playback_volume_INDEXED));
    packed_data->func = snd_mixer_selem_set_playback_volume_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = channel;
    packed_data->args.a3 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_playback_volume_all
int snd_mixer_selem_set_playback_volume_all(snd_mixer_elem_t * elem, long value) {
    snd_mixer_selem_set_playback_volume_all_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_playback_volume_all_INDEXED));
    packed_data->func = snd_mixer_selem_set_playback_volume_all_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_selem_set_playback_volume_range
int snd_mixer_selem_set_playback_volume_range(snd_mixer_elem_t * elem, long min, long max) {
    snd_mixer_selem_set_playback_volume_range_INDEXED *packed_data = malloc(sizeof(snd_mixer_selem_set_playback_volume_range_INDEXED));
    packed_data->func = snd_mixer_selem_set_playback_volume_range_INDEX;
    packed_data->args.a1 = elem;
    packed_data->args.a2 = min;
    packed_data->args.a3 = max;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_set_callback
void snd_mixer_set_callback(snd_mixer_t * obj, snd_mixer_callback_t val) {
    snd_mixer_set_callback_INDEXED *packed_data = malloc(sizeof(snd_mixer_set_callback_INDEXED));
    packed_data->func = snd_mixer_set_callback_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_set_callback_private
void snd_mixer_set_callback_private(snd_mixer_t * obj, void * val) {
    snd_mixer_set_callback_private_INDEXED *packed_data = malloc(sizeof(snd_mixer_set_callback_private_INDEXED));
    packed_data->func = snd_mixer_set_callback_private_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_mixer_set_compare
int snd_mixer_set_compare(snd_mixer_t * mixer, snd_mixer_compare_t msort) {
    snd_mixer_set_compare_INDEXED *packed_data = malloc(sizeof(snd_mixer_set_compare_INDEXED));
    packed_data->func = snd_mixer_set_compare_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = msort;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_mixer_wait
int snd_mixer_wait(snd_mixer_t * mixer, int timeout) {
    snd_mixer_wait_INDEXED *packed_data = malloc(sizeof(snd_mixer_wait_INDEXED));
    packed_data->func = snd_mixer_wait_INDEX;
    packed_data->args.a1 = mixer;
    packed_data->args.a2 = timeout;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_names_list
int snd_names_list(const char * iface, snd_devname_t ** list) {
    snd_names_list_INDEXED *packed_data = malloc(sizeof(snd_names_list_INDEXED));
    packed_data->func = snd_names_list_INDEX;
    packed_data->args.a1 = iface;
    packed_data->args.a2 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_names_list_free
void snd_names_list_free(snd_devname_t * list) {
    snd_names_list_free_INDEXED *packed_data = malloc(sizeof(snd_names_list_free_INDEXED));
    packed_data->func = snd_names_list_free_INDEX;
    packed_data->args.a1 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_output_buffer_open
int snd_output_buffer_open(snd_output_t ** outputp) {
    snd_output_buffer_open_INDEXED *packed_data = malloc(sizeof(snd_output_buffer_open_INDEXED));
    packed_data->func = snd_output_buffer_open_INDEX;
    packed_data->args.a1 = outputp;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_output_buffer_string
size_t snd_output_buffer_string(snd_output_t * output, char ** buf) {
    snd_output_buffer_string_INDEXED *packed_data = malloc(sizeof(snd_output_buffer_string_INDEXED));
    packed_data->func = snd_output_buffer_string_INDEX;
    packed_data->args.a1 = output;
    packed_data->args.a2 = buf;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_output_close
int snd_output_close(snd_output_t * output) {
    snd_output_close_INDEXED *packed_data = malloc(sizeof(snd_output_close_INDEXED));
    packed_data->func = snd_output_close_INDEX;
    packed_data->args.a1 = output;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_output_flush
int snd_output_flush(snd_output_t * output) {
    snd_output_flush_INDEXED *packed_data = malloc(sizeof(snd_output_flush_INDEXED));
    packed_data->func = snd_output_flush_INDEX;
    packed_data->args.a1 = output;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_output_putc
int snd_output_putc(snd_output_t * output, int c) {
    snd_output_putc_INDEXED *packed_data = malloc(sizeof(snd_output_putc_INDEXED));
    packed_data->func = snd_output_putc_INDEX;
    packed_data->args.a1 = output;
    packed_data->args.a2 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_output_puts
int snd_output_puts(snd_output_t * output, const char * str) {
    snd_output_puts_INDEXED *packed_data = malloc(sizeof(snd_output_puts_INDEXED));
    packed_data->func = snd_output_puts_INDEX;
    packed_data->args.a1 = output;
    packed_data->args.a2 = str;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_output_stdio_attach
int snd_output_stdio_attach(snd_output_t ** outputp, FILE * fp, int _close) {
    snd_output_stdio_attach_INDEXED *packed_data = malloc(sizeof(snd_output_stdio_attach_INDEXED));
    packed_data->func = snd_output_stdio_attach_INDEX;
    packed_data->args.a1 = outputp;
    packed_data->args.a2 = fp;
    packed_data->args.a3 = _close;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_output_stdio_open
int snd_output_stdio_open(snd_output_t ** outputp, const char * file, const char * mode) {
    snd_output_stdio_open_INDEXED *packed_data = malloc(sizeof(snd_output_stdio_open_INDEXED));
    packed_data->func = snd_output_stdio_open_INDEX;
    packed_data->args.a1 = outputp;
    packed_data->args.a2 = file;
    packed_data->args.a3 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_output_vprintf
int snd_output_vprintf(snd_output_t * output, const char * format, va_list args) {
    snd_output_vprintf_INDEXED *packed_data = malloc(sizeof(snd_output_vprintf_INDEXED));
    packed_data->func = snd_output_vprintf_INDEX;
    packed_data->args.a1 = output;
    packed_data->args.a2 = format;
    packed_data->args.a3 = args;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_access_mask_any
void snd_pcm_access_mask_any(snd_pcm_access_mask_t * mask) {
    snd_pcm_access_mask_any_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_any_INDEXED));
    packed_data->func = snd_pcm_access_mask_any_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_access_mask_copy
void snd_pcm_access_mask_copy(snd_pcm_access_mask_t * dst, const snd_pcm_access_mask_t * src) {
    snd_pcm_access_mask_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_copy_INDEXED));
    packed_data->func = snd_pcm_access_mask_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_access_mask_empty
int snd_pcm_access_mask_empty(const snd_pcm_access_mask_t * mask) {
    snd_pcm_access_mask_empty_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_empty_INDEXED));
    packed_data->func = snd_pcm_access_mask_empty_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_access_mask_free
void snd_pcm_access_mask_free(snd_pcm_access_mask_t * obj) {
    snd_pcm_access_mask_free_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_free_INDEXED));
    packed_data->func = snd_pcm_access_mask_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_access_mask_malloc
int snd_pcm_access_mask_malloc(snd_pcm_access_mask_t ** ptr) {
    snd_pcm_access_mask_malloc_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_malloc_INDEXED));
    packed_data->func = snd_pcm_access_mask_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_access_mask_none
void snd_pcm_access_mask_none(snd_pcm_access_mask_t * mask) {
    snd_pcm_access_mask_none_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_none_INDEXED));
    packed_data->func = snd_pcm_access_mask_none_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_access_mask_reset
void snd_pcm_access_mask_reset(snd_pcm_access_mask_t * mask, snd_pcm_access_t val) {
    snd_pcm_access_mask_reset_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_reset_INDEXED));
    packed_data->func = snd_pcm_access_mask_reset_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_access_mask_set
void snd_pcm_access_mask_set(snd_pcm_access_mask_t * mask, snd_pcm_access_t val) {
    snd_pcm_access_mask_set_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_set_INDEXED));
    packed_data->func = snd_pcm_access_mask_set_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_access_mask_test
int snd_pcm_access_mask_test(const snd_pcm_access_mask_t * mask, snd_pcm_access_t val) {
    snd_pcm_access_mask_test_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_mask_test_INDEXED));
    packed_data->func = snd_pcm_access_mask_test_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_access_name
const char * snd_pcm_access_name(const snd_pcm_access_t _access) {
    snd_pcm_access_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_access_name_INDEXED));
    packed_data->func = snd_pcm_access_name_INDEX;
    packed_data->args.a1 = _access;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_area_copy
int snd_pcm_area_copy(const snd_pcm_channel_area_t * dst_channel, snd_pcm_uframes_t dst_offset, const snd_pcm_channel_area_t * src_channel, snd_pcm_uframes_t src_offset, unsigned int samples, snd_pcm_format_t format) {
    snd_pcm_area_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_area_copy_INDEXED));
    packed_data->func = snd_pcm_area_copy_INDEX;
    packed_data->args.a1 = dst_channel;
    packed_data->args.a2 = dst_offset;
    packed_data->args.a3 = src_channel;
    packed_data->args.a4 = src_offset;
    packed_data->args.a5 = samples;
    packed_data->args.a6 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_area_silence
int snd_pcm_area_silence(const snd_pcm_channel_area_t * dst_channel, snd_pcm_uframes_t dst_offset, unsigned int samples, snd_pcm_format_t format) {
    snd_pcm_area_silence_INDEXED *packed_data = malloc(sizeof(snd_pcm_area_silence_INDEXED));
    packed_data->func = snd_pcm_area_silence_INDEX;
    packed_data->args.a1 = dst_channel;
    packed_data->args.a2 = dst_offset;
    packed_data->args.a3 = samples;
    packed_data->args.a4 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_areas_copy
int snd_pcm_areas_copy(const snd_pcm_channel_area_t * dst_channels, snd_pcm_uframes_t dst_offset, const snd_pcm_channel_area_t * src_channels, snd_pcm_uframes_t src_offset, unsigned int channels, snd_pcm_uframes_t frames, snd_pcm_format_t format) {
    snd_pcm_areas_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_areas_copy_INDEXED));
    packed_data->func = snd_pcm_areas_copy_INDEX;
    packed_data->args.a1 = dst_channels;
    packed_data->args.a2 = dst_offset;
    packed_data->args.a3 = src_channels;
    packed_data->args.a4 = src_offset;
    packed_data->args.a5 = channels;
    packed_data->args.a6 = frames;
    packed_data->args.a7 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_areas_silence
int snd_pcm_areas_silence(const snd_pcm_channel_area_t * dst_channels, snd_pcm_uframes_t dst_offset, unsigned int channels, snd_pcm_uframes_t frames, snd_pcm_format_t format) {
    snd_pcm_areas_silence_INDEXED *packed_data = malloc(sizeof(snd_pcm_areas_silence_INDEXED));
    packed_data->func = snd_pcm_areas_silence_INDEX;
    packed_data->args.a1 = dst_channels;
    packed_data->args.a2 = dst_offset;
    packed_data->args.a3 = channels;
    packed_data->args.a4 = frames;
    packed_data->args.a5 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_avail_update
snd_pcm_sframes_t snd_pcm_avail_update(snd_pcm_t * pcm) {
    snd_pcm_avail_update_INDEXED *packed_data = malloc(sizeof(snd_pcm_avail_update_INDEXED));
    packed_data->func = snd_pcm_avail_update_INDEX;
    packed_data->args.a1 = pcm;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_build_linear_format
snd_pcm_format_t snd_pcm_build_linear_format(int width, int pwidth, int unsignd, int big_endian) {
    snd_pcm_build_linear_format_INDEXED *packed_data = malloc(sizeof(snd_pcm_build_linear_format_INDEXED));
    packed_data->func = snd_pcm_build_linear_format_INDEX;
    packed_data->args.a1 = width;
    packed_data->args.a2 = pwidth;
    packed_data->args.a3 = unsignd;
    packed_data->args.a4 = big_endian;
    snd_pcm_format_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_bytes_to_frames
snd_pcm_sframes_t snd_pcm_bytes_to_frames(snd_pcm_t * pcm, ssize_t bytes) {
    snd_pcm_bytes_to_frames_INDEXED *packed_data = malloc(sizeof(snd_pcm_bytes_to_frames_INDEXED));
    packed_data->func = snd_pcm_bytes_to_frames_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = bytes;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_bytes_to_samples
long snd_pcm_bytes_to_samples(snd_pcm_t * pcm, ssize_t bytes) {
    snd_pcm_bytes_to_samples_INDEXED *packed_data = malloc(sizeof(snd_pcm_bytes_to_samples_INDEXED));
    packed_data->func = snd_pcm_bytes_to_samples_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = bytes;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_close
int snd_pcm_close(snd_pcm_t * pcm) {
    snd_pcm_close_INDEXED *packed_data = malloc(sizeof(snd_pcm_close_INDEXED));
    packed_data->func = snd_pcm_close_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_delay
int snd_pcm_delay(snd_pcm_t * pcm, snd_pcm_sframes_t * delayp) {
    snd_pcm_delay_INDEXED *packed_data = malloc(sizeof(snd_pcm_delay_INDEXED));
    packed_data->func = snd_pcm_delay_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = delayp;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_drain
int snd_pcm_drain(snd_pcm_t * pcm) {
    snd_pcm_drain_INDEXED *packed_data = malloc(sizeof(snd_pcm_drain_INDEXED));
    packed_data->func = snd_pcm_drain_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_drop
int snd_pcm_drop(snd_pcm_t * pcm) {
    snd_pcm_drop_INDEXED *packed_data = malloc(sizeof(snd_pcm_drop_INDEXED));
    packed_data->func = snd_pcm_drop_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_dump
int snd_pcm_dump(snd_pcm_t * pcm, snd_output_t * out) {
    snd_pcm_dump_INDEXED *packed_data = malloc(sizeof(snd_pcm_dump_INDEXED));
    packed_data->func = snd_pcm_dump_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = out;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_dump_hw_setup
int snd_pcm_dump_hw_setup(snd_pcm_t * pcm, snd_output_t * out) {
    snd_pcm_dump_hw_setup_INDEXED *packed_data = malloc(sizeof(snd_pcm_dump_hw_setup_INDEXED));
    packed_data->func = snd_pcm_dump_hw_setup_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = out;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_dump_setup
int snd_pcm_dump_setup(snd_pcm_t * pcm, snd_output_t * out) {
    snd_pcm_dump_setup_INDEXED *packed_data = malloc(sizeof(snd_pcm_dump_setup_INDEXED));
    packed_data->func = snd_pcm_dump_setup_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = out;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_dump_sw_setup
int snd_pcm_dump_sw_setup(snd_pcm_t * pcm, snd_output_t * out) {
    snd_pcm_dump_sw_setup_INDEXED *packed_data = malloc(sizeof(snd_pcm_dump_sw_setup_INDEXED));
    packed_data->func = snd_pcm_dump_sw_setup_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = out;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_big_endian
int snd_pcm_format_big_endian(snd_pcm_format_t format) {
    snd_pcm_format_big_endian_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_big_endian_INDEXED));
    packed_data->func = snd_pcm_format_big_endian_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_cpu_endian
int snd_pcm_format_cpu_endian(snd_pcm_format_t format) {
    snd_pcm_format_cpu_endian_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_cpu_endian_INDEXED));
    packed_data->func = snd_pcm_format_cpu_endian_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_description
const char * snd_pcm_format_description(const snd_pcm_format_t format) {
    snd_pcm_format_description_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_description_INDEXED));
    packed_data->func = snd_pcm_format_description_INDEX;
    packed_data->args.a1 = format;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_float
int snd_pcm_format_float(snd_pcm_format_t format) {
    snd_pcm_format_float_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_float_INDEXED));
    packed_data->func = snd_pcm_format_float_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_linear
int snd_pcm_format_linear(snd_pcm_format_t format) {
    snd_pcm_format_linear_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_linear_INDEXED));
    packed_data->func = snd_pcm_format_linear_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_little_endian
int snd_pcm_format_little_endian(snd_pcm_format_t format) {
    snd_pcm_format_little_endian_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_little_endian_INDEXED));
    packed_data->func = snd_pcm_format_little_endian_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_mask_any
void snd_pcm_format_mask_any(snd_pcm_format_mask_t * mask) {
    snd_pcm_format_mask_any_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_any_INDEXED));
    packed_data->func = snd_pcm_format_mask_any_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_format_mask_copy
void snd_pcm_format_mask_copy(snd_pcm_format_mask_t * dst, const snd_pcm_format_mask_t * src) {
    snd_pcm_format_mask_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_copy_INDEXED));
    packed_data->func = snd_pcm_format_mask_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_format_mask_empty
int snd_pcm_format_mask_empty(const snd_pcm_format_mask_t * mask) {
    snd_pcm_format_mask_empty_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_empty_INDEXED));
    packed_data->func = snd_pcm_format_mask_empty_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_mask_free
void snd_pcm_format_mask_free(snd_pcm_format_mask_t * obj) {
    snd_pcm_format_mask_free_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_free_INDEXED));
    packed_data->func = snd_pcm_format_mask_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_format_mask_malloc
int snd_pcm_format_mask_malloc(snd_pcm_format_mask_t ** ptr) {
    snd_pcm_format_mask_malloc_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_malloc_INDEXED));
    packed_data->func = snd_pcm_format_mask_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_mask_none
void snd_pcm_format_mask_none(snd_pcm_format_mask_t * mask) {
    snd_pcm_format_mask_none_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_none_INDEXED));
    packed_data->func = snd_pcm_format_mask_none_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_format_mask_reset
void snd_pcm_format_mask_reset(snd_pcm_format_mask_t * mask, snd_pcm_format_t val) {
    snd_pcm_format_mask_reset_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_reset_INDEXED));
    packed_data->func = snd_pcm_format_mask_reset_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_format_mask_set
void snd_pcm_format_mask_set(snd_pcm_format_mask_t * mask, snd_pcm_format_t val) {
    snd_pcm_format_mask_set_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_set_INDEXED));
    packed_data->func = snd_pcm_format_mask_set_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_format_mask_test
int snd_pcm_format_mask_test(const snd_pcm_format_mask_t * mask, snd_pcm_format_t val) {
    snd_pcm_format_mask_test_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_mask_test_INDEXED));
    packed_data->func = snd_pcm_format_mask_test_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_name
const char * snd_pcm_format_name(const snd_pcm_format_t format) {
    snd_pcm_format_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_name_INDEXED));
    packed_data->func = snd_pcm_format_name_INDEX;
    packed_data->args.a1 = format;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_physical_width
int snd_pcm_format_physical_width(snd_pcm_format_t format) {
    snd_pcm_format_physical_width_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_physical_width_INDEXED));
    packed_data->func = snd_pcm_format_physical_width_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_set_silence
int snd_pcm_format_set_silence(snd_pcm_format_t format, void * buf, unsigned int samples) {
    snd_pcm_format_set_silence_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_set_silence_INDEXED));
    packed_data->func = snd_pcm_format_set_silence_INDEX;
    packed_data->args.a1 = format;
    packed_data->args.a2 = buf;
    packed_data->args.a3 = samples;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_signed
int snd_pcm_format_signed(snd_pcm_format_t format) {
    snd_pcm_format_signed_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_signed_INDEXED));
    packed_data->func = snd_pcm_format_signed_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_silence
u_int8_t snd_pcm_format_silence(snd_pcm_format_t format) {
    snd_pcm_format_silence_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_silence_INDEXED));
    packed_data->func = snd_pcm_format_silence_INDEX;
    packed_data->args.a1 = format;
    u_int8_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_silence_16
u_int16_t snd_pcm_format_silence_16(snd_pcm_format_t format) {
    snd_pcm_format_silence_16_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_silence_16_INDEXED));
    packed_data->func = snd_pcm_format_silence_16_INDEX;
    packed_data->args.a1 = format;
    u_int16_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_silence_32
u_int32_t snd_pcm_format_silence_32(snd_pcm_format_t format) {
    snd_pcm_format_silence_32_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_silence_32_INDEXED));
    packed_data->func = snd_pcm_format_silence_32_INDEX;
    packed_data->args.a1 = format;
    u_int32_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_silence_64
u_int64_t snd_pcm_format_silence_64(snd_pcm_format_t format) {
    snd_pcm_format_silence_64_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_silence_64_INDEXED));
    packed_data->func = snd_pcm_format_silence_64_INDEX;
    packed_data->args.a1 = format;
    u_int64_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_size
ssize_t snd_pcm_format_size(snd_pcm_format_t format, size_t samples) {
    snd_pcm_format_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_size_INDEXED));
    packed_data->func = snd_pcm_format_size_INDEX;
    packed_data->args.a1 = format;
    packed_data->args.a2 = samples;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_unsigned
int snd_pcm_format_unsigned(snd_pcm_format_t format) {
    snd_pcm_format_unsigned_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_unsigned_INDEXED));
    packed_data->func = snd_pcm_format_unsigned_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_value
snd_pcm_format_t snd_pcm_format_value(const char* name) {
    snd_pcm_format_value_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_value_INDEXED));
    packed_data->func = snd_pcm_format_value_INDEX;
    packed_data->args.a1 = name;
    snd_pcm_format_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_format_width
int snd_pcm_format_width(snd_pcm_format_t format) {
    snd_pcm_format_width_INDEXED *packed_data = malloc(sizeof(snd_pcm_format_width_INDEXED));
    packed_data->func = snd_pcm_format_width_INDEX;
    packed_data->args.a1 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_forward
snd_pcm_sframes_t snd_pcm_forward(snd_pcm_t * pcm, snd_pcm_uframes_t frames) {
    snd_pcm_forward_INDEXED *packed_data = malloc(sizeof(snd_pcm_forward_INDEXED));
    packed_data->func = snd_pcm_forward_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = frames;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_frames_to_bytes
ssize_t snd_pcm_frames_to_bytes(snd_pcm_t * pcm, snd_pcm_sframes_t frames) {
    snd_pcm_frames_to_bytes_INDEXED *packed_data = malloc(sizeof(snd_pcm_frames_to_bytes_INDEXED));
    packed_data->func = snd_pcm_frames_to_bytes_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = frames;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_get_params
int snd_pcm_get_params(snd_pcm_t * pcm, snd_pcm_uframes_t * buffer_size, snd_pcm_uframes_t * period_size) {
    snd_pcm_get_params_INDEXED *packed_data = malloc(sizeof(snd_pcm_get_params_INDEXED));
    packed_data->func = snd_pcm_get_params_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = buffer_size;
    packed_data->args.a3 = period_size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hook_add
int snd_pcm_hook_add(snd_pcm_hook_t ** hookp, snd_pcm_t * pcm, snd_pcm_hook_type_t type, snd_pcm_hook_func_t func, void * private_data) {
    snd_pcm_hook_add_INDEXED *packed_data = malloc(sizeof(snd_pcm_hook_add_INDEXED));
    packed_data->func = snd_pcm_hook_add_INDEX;
    packed_data->args.a1 = hookp;
    packed_data->args.a2 = pcm;
    packed_data->args.a3 = type;
    packed_data->args.a4 = func;
    packed_data->args.a5 = private_data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hook_get_pcm
snd_pcm_t * snd_pcm_hook_get_pcm(snd_pcm_hook_t * hook) {
    snd_pcm_hook_get_pcm_INDEXED *packed_data = malloc(sizeof(snd_pcm_hook_get_pcm_INDEXED));
    packed_data->func = snd_pcm_hook_get_pcm_INDEX;
    packed_data->args.a1 = hook;
    snd_pcm_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hook_get_private
void * snd_pcm_hook_get_private(snd_pcm_hook_t * hook) {
    snd_pcm_hook_get_private_INDEXED *packed_data = malloc(sizeof(snd_pcm_hook_get_private_INDEXED));
    packed_data->func = snd_pcm_hook_get_private_INDEX;
    packed_data->args.a1 = hook;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hook_remove
int snd_pcm_hook_remove(snd_pcm_hook_t * hook) {
    snd_pcm_hook_remove_INDEXED *packed_data = malloc(sizeof(snd_pcm_hook_remove_INDEXED));
    packed_data->func = snd_pcm_hook_remove_INDEX;
    packed_data->args.a1 = hook;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hook_set_private
void snd_pcm_hook_set_private(snd_pcm_hook_t * hook, void * private_data) {
    snd_pcm_hook_set_private_INDEXED *packed_data = malloc(sizeof(snd_pcm_hook_set_private_INDEXED));
    packed_data->func = snd_pcm_hook_set_private_INDEX;
    packed_data->args.a1 = hook;
    packed_data->args.a2 = private_data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_hw_free
int snd_pcm_hw_free(snd_pcm_t * pcm) {
    snd_pcm_hw_free_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_free_INDEXED));
    packed_data->func = snd_pcm_hw_free_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params
int snd_pcm_hw_params(snd_pcm_t * pcm, snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_INDEXED));
    packed_data->func = snd_pcm_hw_params_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_any
int snd_pcm_hw_params_any(snd_pcm_t * pcm, snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_any_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_any_INDEXED));
    packed_data->func = snd_pcm_hw_params_any_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_can_mmap_sample_resolution
int snd_pcm_hw_params_can_mmap_sample_resolution(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_can_mmap_sample_resolution_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_can_mmap_sample_resolution_INDEXED));
    packed_data->func = snd_pcm_hw_params_can_mmap_sample_resolution_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_can_overrange
int snd_pcm_hw_params_can_overrange(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_can_overrange_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_can_overrange_INDEXED));
    packed_data->func = snd_pcm_hw_params_can_overrange_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_can_pause
int snd_pcm_hw_params_can_pause(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_can_pause_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_can_pause_INDEXED));
    packed_data->func = snd_pcm_hw_params_can_pause_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_can_resume
int snd_pcm_hw_params_can_resume(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_can_resume_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_can_resume_INDEXED));
    packed_data->func = snd_pcm_hw_params_can_resume_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_can_sync_start
int snd_pcm_hw_params_can_sync_start(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_can_sync_start_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_can_sync_start_INDEXED));
    packed_data->func = snd_pcm_hw_params_can_sync_start_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_copy
void snd_pcm_hw_params_copy(snd_pcm_hw_params_t * dst, const snd_pcm_hw_params_t * src) {
    snd_pcm_hw_params_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_copy_INDEXED));
    packed_data->func = snd_pcm_hw_params_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_hw_params_current
int snd_pcm_hw_params_current(snd_pcm_t * pcm, snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_current_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_current_INDEXED));
    packed_data->func = snd_pcm_hw_params_current_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_dump
int snd_pcm_hw_params_dump(snd_pcm_hw_params_t * params, snd_output_t * out) {
    snd_pcm_hw_params_dump_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_dump_INDEXED));
    packed_data->func = snd_pcm_hw_params_dump_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = out;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_free
void snd_pcm_hw_params_free(snd_pcm_hw_params_t * obj) {
    snd_pcm_hw_params_free_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_free_INDEXED));
    packed_data->func = snd_pcm_hw_params_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_access
int snd_pcm_hw_params_get_access(const snd_pcm_hw_params_t * params, snd_pcm_access_t * _access) {
    snd_pcm_hw_params_get_access_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_access_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_access_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = _access;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_access_mask
int snd_pcm_hw_params_get_access_mask(snd_pcm_hw_params_t * params, snd_pcm_access_mask_t * mask) {
    snd_pcm_hw_params_get_access_mask_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_access_mask_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_access_mask_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_buffer_size
int snd_pcm_hw_params_get_buffer_size(const snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_get_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_buffer_size_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_buffer_size_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_buffer_size_max
int snd_pcm_hw_params_get_buffer_size_max(const snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_get_buffer_size_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_buffer_size_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_buffer_size_max_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_buffer_size_min
int snd_pcm_hw_params_get_buffer_size_min(const snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_get_buffer_size_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_buffer_size_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_buffer_size_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_buffer_time
int snd_pcm_hw_params_get_buffer_time(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_buffer_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_buffer_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_buffer_time_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_buffer_time_max
int snd_pcm_hw_params_get_buffer_time_max(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_buffer_time_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_buffer_time_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_buffer_time_max_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_buffer_time_min
int snd_pcm_hw_params_get_buffer_time_min(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_buffer_time_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_buffer_time_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_buffer_time_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_channels
int snd_pcm_hw_params_get_channels(const snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_get_channels_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_channels_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_channels_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_channels_max
int snd_pcm_hw_params_get_channels_max(const snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_get_channels_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_channels_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_channels_max_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_channels_min
int snd_pcm_hw_params_get_channels_min(const snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_get_channels_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_channels_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_channels_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_export_buffer
int snd_pcm_hw_params_get_export_buffer(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_get_export_buffer_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_export_buffer_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_export_buffer_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_fifo_size
int snd_pcm_hw_params_get_fifo_size(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_get_fifo_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_fifo_size_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_fifo_size_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_format
int snd_pcm_hw_params_get_format(const snd_pcm_hw_params_t * params, snd_pcm_format_t * val) {
    snd_pcm_hw_params_get_format_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_format_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_format_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_format_mask
void snd_pcm_hw_params_get_format_mask(snd_pcm_hw_params_t * params, snd_pcm_format_mask_t * mask) {
    snd_pcm_hw_params_get_format_mask_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_format_mask_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_format_mask_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_min_align
int snd_pcm_hw_params_get_min_align(const snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_get_min_align_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_min_align_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_min_align_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_period_size
int snd_pcm_hw_params_get_period_size(const snd_pcm_hw_params_t * params, snd_pcm_uframes_t * frames, int * dir) {
    snd_pcm_hw_params_get_period_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_period_size_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_period_size_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = frames;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_period_size_max
int snd_pcm_hw_params_get_period_size_max(const snd_pcm_hw_params_t * params, snd_pcm_uframes_t * frames, int * dir) {
    snd_pcm_hw_params_get_period_size_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_period_size_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_period_size_max_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = frames;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_period_size_min
int snd_pcm_hw_params_get_period_size_min(const snd_pcm_hw_params_t * params, snd_pcm_uframes_t * frames, int * dir) {
    snd_pcm_hw_params_get_period_size_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_period_size_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_period_size_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = frames;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_period_time
int snd_pcm_hw_params_get_period_time(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_period_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_period_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_period_time_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_period_time_max
int snd_pcm_hw_params_get_period_time_max(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_period_time_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_period_time_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_period_time_max_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_period_time_min
int snd_pcm_hw_params_get_period_time_min(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_period_time_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_period_time_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_period_time_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_periods
int snd_pcm_hw_params_get_periods(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_periods_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_periods_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_periods_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_periods_max
int snd_pcm_hw_params_get_periods_max(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_periods_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_periods_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_periods_max_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_periods_min
int snd_pcm_hw_params_get_periods_min(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_periods_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_periods_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_periods_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_rate
int snd_pcm_hw_params_get_rate(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_rate_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_rate_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_rate_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_rate_max
int snd_pcm_hw_params_get_rate_max(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_rate_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_rate_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_rate_max_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_rate_min
int snd_pcm_hw_params_get_rate_min(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_rate_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_rate_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_rate_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_rate_numden
int snd_pcm_hw_params_get_rate_numden(const snd_pcm_hw_params_t * params, unsigned int * rate_num, unsigned int * rate_den) {
    snd_pcm_hw_params_get_rate_numden_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_rate_numden_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_rate_numden_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = rate_num;
    packed_data->args.a3 = rate_den;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_rate_resample
int snd_pcm_hw_params_get_rate_resample(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_get_rate_resample_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_rate_resample_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_rate_resample_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_sbits
int snd_pcm_hw_params_get_sbits(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_get_sbits_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_sbits_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_sbits_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_subformat
int snd_pcm_hw_params_get_subformat(const snd_pcm_hw_params_t * params, snd_pcm_subformat_t * subformat) {
    snd_pcm_hw_params_get_subformat_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_subformat_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_subformat_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = subformat;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_subformat_mask
void snd_pcm_hw_params_get_subformat_mask(snd_pcm_hw_params_t * params, snd_pcm_subformat_mask_t * mask) {
    snd_pcm_hw_params_get_subformat_mask_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_subformat_mask_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_subformat_mask_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_tick_time
int snd_pcm_hw_params_get_tick_time(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_tick_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_tick_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_tick_time_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_tick_time_max
int snd_pcm_hw_params_get_tick_time_max(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_tick_time_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_tick_time_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_tick_time_max_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_get_tick_time_min
int snd_pcm_hw_params_get_tick_time_min(const snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_get_tick_time_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_get_tick_time_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_get_tick_time_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    packed_data->args.a3 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_is_batch
int snd_pcm_hw_params_is_batch(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_is_batch_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_is_batch_INDEXED));
    packed_data->func = snd_pcm_hw_params_is_batch_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_is_block_transfer
int snd_pcm_hw_params_is_block_transfer(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_is_block_transfer_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_is_block_transfer_INDEXED));
    packed_data->func = snd_pcm_hw_params_is_block_transfer_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_is_double
int snd_pcm_hw_params_is_double(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_is_double_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_is_double_INDEXED));
    packed_data->func = snd_pcm_hw_params_is_double_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_is_half_duplex
int snd_pcm_hw_params_is_half_duplex(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_is_half_duplex_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_is_half_duplex_INDEXED));
    packed_data->func = snd_pcm_hw_params_is_half_duplex_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_is_joint_duplex
int snd_pcm_hw_params_is_joint_duplex(const snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_is_joint_duplex_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_is_joint_duplex_INDEXED));
    packed_data->func = snd_pcm_hw_params_is_joint_duplex_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_malloc
int snd_pcm_hw_params_malloc(snd_pcm_hw_params_t ** ptr) {
    snd_pcm_hw_params_malloc_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_malloc_INDEXED));
    packed_data->func = snd_pcm_hw_params_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_access
int snd_pcm_hw_params_set_access(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_access_t _access) {
    snd_pcm_hw_params_set_access_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_access_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_access_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = _access;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_access_first
int snd_pcm_hw_params_set_access_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_access_t * _access) {
    snd_pcm_hw_params_set_access_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_access_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_access_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = _access;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_access_last
int snd_pcm_hw_params_set_access_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_access_t * _access) {
    snd_pcm_hw_params_set_access_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_access_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_access_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = _access;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_access_mask
int snd_pcm_hw_params_set_access_mask(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_access_mask_t * mask) {
    snd_pcm_hw_params_set_access_mask_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_access_mask_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_access_mask_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_size
int snd_pcm_hw_params_set_buffer_size(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t val) {
    snd_pcm_hw_params_set_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_size_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_size_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_size_first
int snd_pcm_hw_params_set_buffer_size_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_set_buffer_size_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_size_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_size_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_size_last
int snd_pcm_hw_params_set_buffer_size_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_set_buffer_size_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_size_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_size_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_size_max
int snd_pcm_hw_params_set_buffer_size_max(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_set_buffer_size_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_size_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_size_max_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_size_min
int snd_pcm_hw_params_set_buffer_size_min(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_set_buffer_size_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_size_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_size_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_size_minmax
int snd_pcm_hw_params_set_buffer_size_minmax(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * min, snd_pcm_uframes_t * max) {
    snd_pcm_hw_params_set_buffer_size_minmax_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_size_minmax_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_size_minmax_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = min;
    packed_data->args.a4 = max;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_size_near
int snd_pcm_hw_params_set_buffer_size_near(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_hw_params_set_buffer_size_near_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_size_near_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_size_near_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_time
int snd_pcm_hw_params_set_buffer_time(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_set_buffer_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_time_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_time_first
int snd_pcm_hw_params_set_buffer_time_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_buffer_time_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_time_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_time_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_time_last
int snd_pcm_hw_params_set_buffer_time_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_buffer_time_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_time_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_time_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_time_max
int snd_pcm_hw_params_set_buffer_time_max(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_buffer_time_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_time_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_time_max_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_time_min
int snd_pcm_hw_params_set_buffer_time_min(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_buffer_time_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_time_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_time_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_time_minmax
int snd_pcm_hw_params_set_buffer_time_minmax(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * min, int * mindir, unsigned int * max, int * maxdir) {
    snd_pcm_hw_params_set_buffer_time_minmax_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_time_minmax_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_time_minmax_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = min;
    packed_data->args.a4 = mindir;
    packed_data->args.a5 = max;
    packed_data->args.a6 = maxdir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_buffer_time_near
int snd_pcm_hw_params_set_buffer_time_near(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_buffer_time_near_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_buffer_time_near_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_buffer_time_near_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_channels
int snd_pcm_hw_params_set_channels(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val) {
    snd_pcm_hw_params_set_channels_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_channels_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_channels_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_channels_first
int snd_pcm_hw_params_set_channels_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_set_channels_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_channels_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_channels_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_channels_last
int snd_pcm_hw_params_set_channels_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_set_channels_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_channels_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_channels_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_channels_max
int snd_pcm_hw_params_set_channels_max(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_set_channels_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_channels_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_channels_max_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_channels_min
int snd_pcm_hw_params_set_channels_min(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_set_channels_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_channels_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_channels_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_channels_minmax
int snd_pcm_hw_params_set_channels_minmax(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * min, unsigned int * max) {
    snd_pcm_hw_params_set_channels_minmax_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_channels_minmax_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_channels_minmax_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = min;
    packed_data->args.a4 = max;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_channels_near
int snd_pcm_hw_params_set_channels_near(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val) {
    snd_pcm_hw_params_set_channels_near_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_channels_near_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_channels_near_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_export_buffer
int snd_pcm_hw_params_set_export_buffer(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val) {
    snd_pcm_hw_params_set_export_buffer_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_export_buffer_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_export_buffer_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_format
int snd_pcm_hw_params_set_format(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_format_t val) {
    snd_pcm_hw_params_set_format_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_format_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_format_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_format_first
int snd_pcm_hw_params_set_format_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_format_t * format) {
    snd_pcm_hw_params_set_format_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_format_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_format_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_format_last
int snd_pcm_hw_params_set_format_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_format_t * format) {
    snd_pcm_hw_params_set_format_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_format_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_format_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = format;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_format_mask
int snd_pcm_hw_params_set_format_mask(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_format_mask_t * mask) {
    snd_pcm_hw_params_set_format_mask_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_format_mask_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_format_mask_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_size
int snd_pcm_hw_params_set_period_size(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t val, int dir) {
    snd_pcm_hw_params_set_period_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_size_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_size_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_size_first
int snd_pcm_hw_params_set_period_size_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val, int * dir) {
    snd_pcm_hw_params_set_period_size_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_size_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_size_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_size_integer
int snd_pcm_hw_params_set_period_size_integer(snd_pcm_t * pcm, snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_set_period_size_integer_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_size_integer_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_size_integer_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_size_last
int snd_pcm_hw_params_set_period_size_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val, int * dir) {
    snd_pcm_hw_params_set_period_size_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_size_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_size_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_size_max
int snd_pcm_hw_params_set_period_size_max(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val, int * dir) {
    snd_pcm_hw_params_set_period_size_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_size_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_size_max_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_size_min
int snd_pcm_hw_params_set_period_size_min(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val, int * dir) {
    snd_pcm_hw_params_set_period_size_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_size_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_size_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_size_minmax
int snd_pcm_hw_params_set_period_size_minmax(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * min, int * mindir, snd_pcm_uframes_t * max, int * maxdir) {
    snd_pcm_hw_params_set_period_size_minmax_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_size_minmax_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_size_minmax_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = min;
    packed_data->args.a4 = mindir;
    packed_data->args.a5 = max;
    packed_data->args.a6 = maxdir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_size_near
int snd_pcm_hw_params_set_period_size_near(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t * val, int * dir) {
    snd_pcm_hw_params_set_period_size_near_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_size_near_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_size_near_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_time
int snd_pcm_hw_params_set_period_time(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_set_period_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_time_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_time_first
int snd_pcm_hw_params_set_period_time_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_period_time_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_time_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_time_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_time_last
int snd_pcm_hw_params_set_period_time_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_period_time_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_time_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_time_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_time_max
int snd_pcm_hw_params_set_period_time_max(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_period_time_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_time_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_time_max_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_time_min
int snd_pcm_hw_params_set_period_time_min(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_period_time_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_time_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_time_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_time_minmax
int snd_pcm_hw_params_set_period_time_minmax(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * min, int * mindir, unsigned int * max, int * maxdir) {
    snd_pcm_hw_params_set_period_time_minmax_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_time_minmax_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_time_minmax_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = min;
    packed_data->args.a4 = mindir;
    packed_data->args.a5 = max;
    packed_data->args.a6 = maxdir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_period_time_near
int snd_pcm_hw_params_set_period_time_near(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_period_time_near_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_period_time_near_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_period_time_near_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_periods
int snd_pcm_hw_params_set_periods(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_set_periods_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_periods_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_periods_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_periods_first
int snd_pcm_hw_params_set_periods_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_periods_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_periods_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_periods_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_periods_integer
int snd_pcm_hw_params_set_periods_integer(snd_pcm_t * pcm, snd_pcm_hw_params_t * params) {
    snd_pcm_hw_params_set_periods_integer_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_periods_integer_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_periods_integer_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_periods_last
int snd_pcm_hw_params_set_periods_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_periods_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_periods_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_periods_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_periods_max
int snd_pcm_hw_params_set_periods_max(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_periods_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_periods_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_periods_max_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_periods_min
int snd_pcm_hw_params_set_periods_min(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_periods_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_periods_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_periods_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_periods_minmax
int snd_pcm_hw_params_set_periods_minmax(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * min, int * mindir, unsigned int * max, int * maxdir) {
    snd_pcm_hw_params_set_periods_minmax_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_periods_minmax_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_periods_minmax_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = min;
    packed_data->args.a4 = mindir;
    packed_data->args.a5 = max;
    packed_data->args.a6 = maxdir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_periods_near
int snd_pcm_hw_params_set_periods_near(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_periods_near_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_periods_near_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_periods_near_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_rate
int snd_pcm_hw_params_set_rate(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_set_rate_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_rate_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_rate_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_rate_first
int snd_pcm_hw_params_set_rate_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_rate_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_rate_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_rate_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_rate_last
int snd_pcm_hw_params_set_rate_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_rate_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_rate_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_rate_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_rate_max
int snd_pcm_hw_params_set_rate_max(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_rate_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_rate_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_rate_max_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_rate_min
int snd_pcm_hw_params_set_rate_min(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_rate_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_rate_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_rate_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_rate_minmax
int snd_pcm_hw_params_set_rate_minmax(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * min, int * mindir, unsigned int * max, int * maxdir) {
    snd_pcm_hw_params_set_rate_minmax_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_rate_minmax_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_rate_minmax_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = min;
    packed_data->args.a4 = mindir;
    packed_data->args.a5 = max;
    packed_data->args.a6 = maxdir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_rate_near
int snd_pcm_hw_params_set_rate_near(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_rate_near_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_rate_near_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_rate_near_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_rate_resample
int snd_pcm_hw_params_set_rate_resample(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val) {
    snd_pcm_hw_params_set_rate_resample_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_rate_resample_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_rate_resample_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_subformat
int snd_pcm_hw_params_set_subformat(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_subformat_t subformat) {
    snd_pcm_hw_params_set_subformat_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_subformat_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_subformat_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = subformat;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_subformat_first
int snd_pcm_hw_params_set_subformat_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_subformat_t * subformat) {
    snd_pcm_hw_params_set_subformat_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_subformat_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_subformat_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = subformat;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_subformat_last
int snd_pcm_hw_params_set_subformat_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_subformat_t * subformat) {
    snd_pcm_hw_params_set_subformat_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_subformat_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_subformat_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = subformat;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_subformat_mask
int snd_pcm_hw_params_set_subformat_mask(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_subformat_mask_t * mask) {
    snd_pcm_hw_params_set_subformat_mask_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_subformat_mask_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_subformat_mask_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_tick_time
int snd_pcm_hw_params_set_tick_time(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_set_tick_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_tick_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_tick_time_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_tick_time_first
int snd_pcm_hw_params_set_tick_time_first(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_tick_time_first_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_tick_time_first_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_tick_time_first_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_tick_time_last
int snd_pcm_hw_params_set_tick_time_last(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_tick_time_last_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_tick_time_last_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_tick_time_last_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_tick_time_max
int snd_pcm_hw_params_set_tick_time_max(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_tick_time_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_tick_time_max_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_tick_time_max_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_tick_time_min
int snd_pcm_hw_params_set_tick_time_min(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_tick_time_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_tick_time_min_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_tick_time_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_tick_time_minmax
int snd_pcm_hw_params_set_tick_time_minmax(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * min, int * mindir, unsigned int * max, int * maxdir) {
    snd_pcm_hw_params_set_tick_time_minmax_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_tick_time_minmax_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_tick_time_minmax_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = min;
    packed_data->args.a4 = mindir;
    packed_data->args.a5 = max;
    packed_data->args.a6 = maxdir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_set_tick_time_near
int snd_pcm_hw_params_set_tick_time_near(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int * val, int * dir) {
    snd_pcm_hw_params_set_tick_time_near_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_set_tick_time_near_INDEXED));
    packed_data->func = snd_pcm_hw_params_set_tick_time_near_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_access
int snd_pcm_hw_params_test_access(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_access_t _access) {
    snd_pcm_hw_params_test_access_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_access_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_access_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = _access;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_buffer_size
int snd_pcm_hw_params_test_buffer_size(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t val) {
    snd_pcm_hw_params_test_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_buffer_size_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_buffer_size_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_buffer_time
int snd_pcm_hw_params_test_buffer_time(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_test_buffer_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_buffer_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_buffer_time_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_channels
int snd_pcm_hw_params_test_channels(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val) {
    snd_pcm_hw_params_test_channels_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_channels_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_channels_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_format
int snd_pcm_hw_params_test_format(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_format_t val) {
    snd_pcm_hw_params_test_format_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_format_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_format_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_period_size
int snd_pcm_hw_params_test_period_size(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_uframes_t val, int dir) {
    snd_pcm_hw_params_test_period_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_period_size_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_period_size_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_period_time
int snd_pcm_hw_params_test_period_time(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_test_period_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_period_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_period_time_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_periods
int snd_pcm_hw_params_test_periods(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_test_periods_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_periods_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_periods_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_rate
int snd_pcm_hw_params_test_rate(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_test_rate_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_rate_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_rate_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_subformat
int snd_pcm_hw_params_test_subformat(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, snd_pcm_subformat_t subformat) {
    snd_pcm_hw_params_test_subformat_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_subformat_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_subformat_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = subformat;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hw_params_test_tick_time
int snd_pcm_hw_params_test_tick_time(snd_pcm_t * pcm, snd_pcm_hw_params_t * params, unsigned int val, int dir) {
    snd_pcm_hw_params_test_tick_time_INDEXED *packed_data = malloc(sizeof(snd_pcm_hw_params_test_tick_time_INDEXED));
    packed_data->func = snd_pcm_hw_params_test_tick_time_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    packed_data->args.a4 = dir;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_hwsync
int snd_pcm_hwsync(snd_pcm_t * pcm) {
    snd_pcm_hwsync_INDEXED *packed_data = malloc(sizeof(snd_pcm_hwsync_INDEXED));
    packed_data->func = snd_pcm_hwsync_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info
int snd_pcm_info(snd_pcm_t * pcm, snd_pcm_info_t * info) {
    snd_pcm_info_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_INDEXED));
    packed_data->func = snd_pcm_info_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_copy
void snd_pcm_info_copy(snd_pcm_info_t * dst, const snd_pcm_info_t * src) {
    snd_pcm_info_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_copy_INDEXED));
    packed_data->func = snd_pcm_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_info_free
void snd_pcm_info_free(snd_pcm_info_t * obj) {
    snd_pcm_info_free_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_free_INDEXED));
    packed_data->func = snd_pcm_info_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_info_get_card
int snd_pcm_info_get_card(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_card_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_card_INDEXED));
    packed_data->func = snd_pcm_info_get_card_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_class
snd_pcm_class_t snd_pcm_info_get_class(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_class_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_class_INDEXED));
    packed_data->func = snd_pcm_info_get_class_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_class_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_device
unsigned int snd_pcm_info_get_device(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_device_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_device_INDEXED));
    packed_data->func = snd_pcm_info_get_device_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_id
const char * snd_pcm_info_get_id(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_id_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_id_INDEXED));
    packed_data->func = snd_pcm_info_get_id_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_name
const char * snd_pcm_info_get_name(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_name_INDEXED));
    packed_data->func = snd_pcm_info_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_stream
snd_pcm_stream_t snd_pcm_info_get_stream(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_stream_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_stream_INDEXED));
    packed_data->func = snd_pcm_info_get_stream_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_stream_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_subclass
snd_pcm_subclass_t snd_pcm_info_get_subclass(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_subclass_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_subclass_INDEXED));
    packed_data->func = snd_pcm_info_get_subclass_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_subclass_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_subdevice
unsigned int snd_pcm_info_get_subdevice(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_subdevice_INDEXED));
    packed_data->func = snd_pcm_info_get_subdevice_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_subdevice_name
const char * snd_pcm_info_get_subdevice_name(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_subdevice_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_subdevice_name_INDEXED));
    packed_data->func = snd_pcm_info_get_subdevice_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_subdevices_avail
unsigned int snd_pcm_info_get_subdevices_avail(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_subdevices_avail_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_subdevices_avail_INDEXED));
    packed_data->func = snd_pcm_info_get_subdevices_avail_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_subdevices_count
unsigned int snd_pcm_info_get_subdevices_count(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_subdevices_count_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_subdevices_count_INDEXED));
    packed_data->func = snd_pcm_info_get_subdevices_count_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_get_sync
snd_pcm_sync_id_t snd_pcm_info_get_sync(const snd_pcm_info_t * obj) {
    snd_pcm_info_get_sync_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_get_sync_INDEXED));
    packed_data->func = snd_pcm_info_get_sync_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_sync_id_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_malloc
int snd_pcm_info_malloc(snd_pcm_info_t ** ptr) {
    snd_pcm_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_malloc_INDEXED));
    packed_data->func = snd_pcm_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_info_set_device
void snd_pcm_info_set_device(snd_pcm_info_t * obj, unsigned int val) {
    snd_pcm_info_set_device_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_set_device_INDEXED));
    packed_data->func = snd_pcm_info_set_device_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_info_set_stream
void snd_pcm_info_set_stream(snd_pcm_info_t * obj, snd_pcm_stream_t val) {
    snd_pcm_info_set_stream_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_set_stream_INDEXED));
    packed_data->func = snd_pcm_info_set_stream_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_info_set_subdevice
void snd_pcm_info_set_subdevice(snd_pcm_info_t * obj, unsigned int val) {
    snd_pcm_info_set_subdevice_INDEXED *packed_data = malloc(sizeof(snd_pcm_info_set_subdevice_INDEXED));
    packed_data->func = snd_pcm_info_set_subdevice_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_link
int snd_pcm_link(snd_pcm_t * pcm1, snd_pcm_t * pcm2) {
    snd_pcm_link_INDEXED *packed_data = malloc(sizeof(snd_pcm_link_INDEXED));
    packed_data->func = snd_pcm_link_INDEX;
    packed_data->args.a1 = pcm1;
    packed_data->args.a2 = pcm2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_meter_add_scope
int snd_pcm_meter_add_scope(snd_pcm_t * pcm, snd_pcm_scope_t * scope) {
    snd_pcm_meter_add_scope_INDEXED *packed_data = malloc(sizeof(snd_pcm_meter_add_scope_INDEXED));
    packed_data->func = snd_pcm_meter_add_scope_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = scope;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_meter_get_boundary
snd_pcm_uframes_t snd_pcm_meter_get_boundary(snd_pcm_t * pcm) {
    snd_pcm_meter_get_boundary_INDEXED *packed_data = malloc(sizeof(snd_pcm_meter_get_boundary_INDEXED));
    packed_data->func = snd_pcm_meter_get_boundary_INDEX;
    packed_data->args.a1 = pcm;
    snd_pcm_uframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_meter_get_bufsize
snd_pcm_uframes_t snd_pcm_meter_get_bufsize(snd_pcm_t * pcm) {
    snd_pcm_meter_get_bufsize_INDEXED *packed_data = malloc(sizeof(snd_pcm_meter_get_bufsize_INDEXED));
    packed_data->func = snd_pcm_meter_get_bufsize_INDEX;
    packed_data->args.a1 = pcm;
    snd_pcm_uframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_meter_get_channels
unsigned int snd_pcm_meter_get_channels(snd_pcm_t * pcm) {
    snd_pcm_meter_get_channels_INDEXED *packed_data = malloc(sizeof(snd_pcm_meter_get_channels_INDEXED));
    packed_data->func = snd_pcm_meter_get_channels_INDEX;
    packed_data->args.a1 = pcm;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_meter_get_now
snd_pcm_uframes_t snd_pcm_meter_get_now(snd_pcm_t * pcm) {
    snd_pcm_meter_get_now_INDEXED *packed_data = malloc(sizeof(snd_pcm_meter_get_now_INDEXED));
    packed_data->func = snd_pcm_meter_get_now_INDEX;
    packed_data->args.a1 = pcm;
    snd_pcm_uframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_meter_get_rate
unsigned int snd_pcm_meter_get_rate(snd_pcm_t * pcm) {
    snd_pcm_meter_get_rate_INDEXED *packed_data = malloc(sizeof(snd_pcm_meter_get_rate_INDEXED));
    packed_data->func = snd_pcm_meter_get_rate_INDEX;
    packed_data->args.a1 = pcm;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_meter_search_scope
snd_pcm_scope_t * snd_pcm_meter_search_scope(snd_pcm_t * pcm, const char * name) {
    snd_pcm_meter_search_scope_INDEXED *packed_data = malloc(sizeof(snd_pcm_meter_search_scope_INDEXED));
    packed_data->func = snd_pcm_meter_search_scope_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = name;
    snd_pcm_scope_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_mmap_begin
int snd_pcm_mmap_begin(snd_pcm_t * pcm, const snd_pcm_channel_area_t ** areas, snd_pcm_uframes_t * offset, snd_pcm_uframes_t * frames) {
    snd_pcm_mmap_begin_INDEXED *packed_data = malloc(sizeof(snd_pcm_mmap_begin_INDEXED));
    packed_data->func = snd_pcm_mmap_begin_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = areas;
    packed_data->args.a3 = offset;
    packed_data->args.a4 = frames;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_mmap_commit
snd_pcm_sframes_t snd_pcm_mmap_commit(snd_pcm_t * pcm, snd_pcm_uframes_t offset, snd_pcm_uframes_t frames) {
    snd_pcm_mmap_commit_INDEXED *packed_data = malloc(sizeof(snd_pcm_mmap_commit_INDEXED));
    packed_data->func = snd_pcm_mmap_commit_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = frames;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_mmap_readi
snd_pcm_sframes_t snd_pcm_mmap_readi(snd_pcm_t * pcm, void * buffer, snd_pcm_uframes_t size) {
    snd_pcm_mmap_readi_INDEXED *packed_data = malloc(sizeof(snd_pcm_mmap_readi_INDEXED));
    packed_data->func = snd_pcm_mmap_readi_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_mmap_readn
snd_pcm_sframes_t snd_pcm_mmap_readn(snd_pcm_t * pcm, void ** bufs, snd_pcm_uframes_t size) {
    snd_pcm_mmap_readn_INDEXED *packed_data = malloc(sizeof(snd_pcm_mmap_readn_INDEXED));
    packed_data->func = snd_pcm_mmap_readn_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = bufs;
    packed_data->args.a3 = size;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_mmap_writei
snd_pcm_sframes_t snd_pcm_mmap_writei(snd_pcm_t * pcm, const void * buffer, snd_pcm_uframes_t size) {
    snd_pcm_mmap_writei_INDEXED *packed_data = malloc(sizeof(snd_pcm_mmap_writei_INDEXED));
    packed_data->func = snd_pcm_mmap_writei_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_mmap_writen
snd_pcm_sframes_t snd_pcm_mmap_writen(snd_pcm_t * pcm, void ** bufs, snd_pcm_uframes_t size) {
    snd_pcm_mmap_writen_INDEXED *packed_data = malloc(sizeof(snd_pcm_mmap_writen_INDEXED));
    packed_data->func = snd_pcm_mmap_writen_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = bufs;
    packed_data->args.a3 = size;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_name
const char * snd_pcm_name(snd_pcm_t * pcm) {
    snd_pcm_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_name_INDEXED));
    packed_data->func = snd_pcm_name_INDEX;
    packed_data->args.a1 = pcm;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_nonblock
int snd_pcm_nonblock(snd_pcm_t * pcm, int nonblock) {
    snd_pcm_nonblock_INDEXED *packed_data = malloc(sizeof(snd_pcm_nonblock_INDEXED));
    packed_data->func = snd_pcm_nonblock_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = nonblock;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_open
int snd_pcm_open(snd_pcm_t ** pcm, const char * name, snd_pcm_stream_t stream, int mode) {
    snd_pcm_open_INDEXED *packed_data = malloc(sizeof(snd_pcm_open_INDEXED));
    packed_data->func = snd_pcm_open_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = name;
    packed_data->args.a3 = stream;
    packed_data->args.a4 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_open_lconf
int snd_pcm_open_lconf(snd_pcm_t ** pcm, const char * name, snd_pcm_stream_t stream, int mode, snd_config_t * lconf) {
    snd_pcm_open_lconf_INDEXED *packed_data = malloc(sizeof(snd_pcm_open_lconf_INDEXED));
    packed_data->func = snd_pcm_open_lconf_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = name;
    packed_data->args.a3 = stream;
    packed_data->args.a4 = mode;
    packed_data->args.a5 = lconf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_pause
int snd_pcm_pause(snd_pcm_t * pcm, int enable) {
    snd_pcm_pause_INDEXED *packed_data = malloc(sizeof(snd_pcm_pause_INDEXED));
    packed_data->func = snd_pcm_pause_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = enable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_poll_descriptors
int snd_pcm_poll_descriptors(snd_pcm_t * pcm, struct pollfd * pfds, unsigned int space) {
    snd_pcm_poll_descriptors_INDEXED *packed_data = malloc(sizeof(snd_pcm_poll_descriptors_INDEXED));
    packed_data->func = snd_pcm_poll_descriptors_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = space;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_poll_descriptors_count
int snd_pcm_poll_descriptors_count(snd_pcm_t * pcm) {
    snd_pcm_poll_descriptors_count_INDEXED *packed_data = malloc(sizeof(snd_pcm_poll_descriptors_count_INDEXED));
    packed_data->func = snd_pcm_poll_descriptors_count_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_poll_descriptors_revents
int snd_pcm_poll_descriptors_revents(snd_pcm_t * pcm, struct pollfd * pfds, unsigned int nfds, unsigned short * revents) {
    snd_pcm_poll_descriptors_revents_INDEXED *packed_data = malloc(sizeof(snd_pcm_poll_descriptors_revents_INDEXED));
    packed_data->func = snd_pcm_poll_descriptors_revents_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = nfds;
    packed_data->args.a4 = revents;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_prepare
int snd_pcm_prepare(snd_pcm_t * pcm) {
    snd_pcm_prepare_INDEXED *packed_data = malloc(sizeof(snd_pcm_prepare_INDEXED));
    packed_data->func = snd_pcm_prepare_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_readi
snd_pcm_sframes_t snd_pcm_readi(snd_pcm_t * pcm, void * buffer, snd_pcm_uframes_t size) {
    snd_pcm_readi_INDEXED *packed_data = malloc(sizeof(snd_pcm_readi_INDEXED));
    packed_data->func = snd_pcm_readi_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_readn
snd_pcm_sframes_t snd_pcm_readn(snd_pcm_t * pcm, void ** bufs, snd_pcm_uframes_t size) {
    snd_pcm_readn_INDEXED *packed_data = malloc(sizeof(snd_pcm_readn_INDEXED));
    packed_data->func = snd_pcm_readn_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = bufs;
    packed_data->args.a3 = size;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_recover
int snd_pcm_recover(snd_pcm_t * pcm, int err, int silent) {
    snd_pcm_recover_INDEXED *packed_data = malloc(sizeof(snd_pcm_recover_INDEXED));
    packed_data->func = snd_pcm_recover_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = err;
    packed_data->args.a3 = silent;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_reset
int snd_pcm_reset(snd_pcm_t * pcm) {
    snd_pcm_reset_INDEXED *packed_data = malloc(sizeof(snd_pcm_reset_INDEXED));
    packed_data->func = snd_pcm_reset_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_resume
int snd_pcm_resume(snd_pcm_t * pcm) {
    snd_pcm_resume_INDEXED *packed_data = malloc(sizeof(snd_pcm_resume_INDEXED));
    packed_data->func = snd_pcm_resume_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_rewind
snd_pcm_sframes_t snd_pcm_rewind(snd_pcm_t * pcm, snd_pcm_uframes_t frames) {
    snd_pcm_rewind_INDEXED *packed_data = malloc(sizeof(snd_pcm_rewind_INDEXED));
    packed_data->func = snd_pcm_rewind_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = frames;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_samples_to_bytes
ssize_t snd_pcm_samples_to_bytes(snd_pcm_t * pcm, long samples) {
    snd_pcm_samples_to_bytes_INDEXED *packed_data = malloc(sizeof(snd_pcm_samples_to_bytes_INDEXED));
    packed_data->func = snd_pcm_samples_to_bytes_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = samples;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_scope_get_callback_private
void * snd_pcm_scope_get_callback_private(snd_pcm_scope_t * scope) {
    snd_pcm_scope_get_callback_private_INDEXED *packed_data = malloc(sizeof(snd_pcm_scope_get_callback_private_INDEXED));
    packed_data->func = snd_pcm_scope_get_callback_private_INDEX;
    packed_data->args.a1 = scope;
    void * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_scope_get_name
const char * snd_pcm_scope_get_name(snd_pcm_scope_t * scope) {
    snd_pcm_scope_get_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_scope_get_name_INDEXED));
    packed_data->func = snd_pcm_scope_get_name_INDEX;
    packed_data->args.a1 = scope;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_scope_malloc
int snd_pcm_scope_malloc(snd_pcm_scope_t ** ptr) {
    snd_pcm_scope_malloc_INDEXED *packed_data = malloc(sizeof(snd_pcm_scope_malloc_INDEXED));
    packed_data->func = snd_pcm_scope_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_scope_s16_get_channel_buffer
int16_t * snd_pcm_scope_s16_get_channel_buffer(snd_pcm_scope_t * scope, unsigned int channel) {
    snd_pcm_scope_s16_get_channel_buffer_INDEXED *packed_data = malloc(sizeof(snd_pcm_scope_s16_get_channel_buffer_INDEXED));
    packed_data->func = snd_pcm_scope_s16_get_channel_buffer_INDEX;
    packed_data->args.a1 = scope;
    packed_data->args.a2 = channel;
    int16_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_scope_s16_open
int snd_pcm_scope_s16_open(snd_pcm_t * pcm, const char * name, snd_pcm_scope_t ** scopep) {
    snd_pcm_scope_s16_open_INDEXED *packed_data = malloc(sizeof(snd_pcm_scope_s16_open_INDEXED));
    packed_data->func = snd_pcm_scope_s16_open_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = name;
    packed_data->args.a3 = scopep;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_scope_set_callback_private
void snd_pcm_scope_set_callback_private(snd_pcm_scope_t * scope, void * val) {
    snd_pcm_scope_set_callback_private_INDEXED *packed_data = malloc(sizeof(snd_pcm_scope_set_callback_private_INDEXED));
    packed_data->func = snd_pcm_scope_set_callback_private_INDEX;
    packed_data->args.a1 = scope;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_scope_set_name
void snd_pcm_scope_set_name(snd_pcm_scope_t * scope, const char * val) {
    snd_pcm_scope_set_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_scope_set_name_INDEXED));
    packed_data->func = snd_pcm_scope_set_name_INDEX;
    packed_data->args.a1 = scope;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_scope_set_ops
void snd_pcm_scope_set_ops(snd_pcm_scope_t * scope, snd_pcm_scope_ops_t * val) {
    snd_pcm_scope_set_ops_INDEXED *packed_data = malloc(sizeof(snd_pcm_scope_set_ops_INDEXED));
    packed_data->func = snd_pcm_scope_set_ops_INDEX;
    packed_data->args.a1 = scope;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_set_params
int snd_pcm_set_params(snd_pcm_t * pcm, snd_pcm_format_t format, snd_pcm_access_t access, unsigned int channels, unsigned int rate, int soft_resample, unsigned int latency) {
    snd_pcm_set_params_INDEXED *packed_data = malloc(sizeof(snd_pcm_set_params_INDEXED));
    packed_data->func = snd_pcm_set_params_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = format;
    packed_data->args.a3 = access;
    packed_data->args.a4 = channels;
    packed_data->args.a5 = rate;
    packed_data->args.a6 = soft_resample;
    packed_data->args.a7 = latency;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_start
int snd_pcm_start(snd_pcm_t * pcm) {
    snd_pcm_start_INDEXED *packed_data = malloc(sizeof(snd_pcm_start_INDEXED));
    packed_data->func = snd_pcm_start_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_start_mode_name
const char * snd_pcm_start_mode_name(snd_pcm_start_t mode) {
    snd_pcm_start_mode_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_start_mode_name_INDEXED));
    packed_data->func = snd_pcm_start_mode_name_INDEX;
    packed_data->args.a1 = mode;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_state
snd_pcm_state_t snd_pcm_state(snd_pcm_t * pcm) {
    snd_pcm_state_INDEXED *packed_data = malloc(sizeof(snd_pcm_state_INDEXED));
    packed_data->func = snd_pcm_state_INDEX;
    packed_data->args.a1 = pcm;
    snd_pcm_state_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_state_name
const char * snd_pcm_state_name(const snd_pcm_state_t state) {
    snd_pcm_state_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_state_name_INDEXED));
    packed_data->func = snd_pcm_state_name_INDEX;
    packed_data->args.a1 = state;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_status
int snd_pcm_status(snd_pcm_t * pcm, snd_pcm_status_t * status) {
    snd_pcm_status_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_INDEXED));
    packed_data->func = snd_pcm_status_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = status;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_status_copy
void snd_pcm_status_copy(snd_pcm_status_t * dst, const snd_pcm_status_t * src) {
    snd_pcm_status_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_copy_INDEXED));
    packed_data->func = snd_pcm_status_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_status_dump
int snd_pcm_status_dump(snd_pcm_status_t * status, snd_output_t * out) {
    snd_pcm_status_dump_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_dump_INDEXED));
    packed_data->func = snd_pcm_status_dump_INDEX;
    packed_data->args.a1 = status;
    packed_data->args.a2 = out;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_status_free
void snd_pcm_status_free(snd_pcm_status_t * obj) {
    snd_pcm_status_free_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_free_INDEXED));
    packed_data->func = snd_pcm_status_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_status_get_avail
snd_pcm_uframes_t snd_pcm_status_get_avail(const snd_pcm_status_t * obj) {
    snd_pcm_status_get_avail_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_avail_INDEXED));
    packed_data->func = snd_pcm_status_get_avail_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_uframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_status_get_avail_max
snd_pcm_uframes_t snd_pcm_status_get_avail_max(const snd_pcm_status_t * obj) {
    snd_pcm_status_get_avail_max_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_avail_max_INDEXED));
    packed_data->func = snd_pcm_status_get_avail_max_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_uframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_status_get_delay
snd_pcm_sframes_t snd_pcm_status_get_delay(const snd_pcm_status_t * obj) {
    snd_pcm_status_get_delay_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_delay_INDEXED));
    packed_data->func = snd_pcm_status_get_delay_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_status_get_htstamp
void snd_pcm_status_get_htstamp(const snd_pcm_status_t * obj, snd_htimestamp_t * ptr) {
    snd_pcm_status_get_htstamp_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_htstamp_INDEXED));
    packed_data->func = snd_pcm_status_get_htstamp_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_status_get_overrange
snd_pcm_uframes_t snd_pcm_status_get_overrange(const snd_pcm_status_t * obj) {
    snd_pcm_status_get_overrange_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_overrange_INDEXED));
    packed_data->func = snd_pcm_status_get_overrange_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_uframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_status_get_state
snd_pcm_state_t snd_pcm_status_get_state(const snd_pcm_status_t * obj) {
    snd_pcm_status_get_state_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_state_INDEXED));
    packed_data->func = snd_pcm_status_get_state_INDEX;
    packed_data->args.a1 = obj;
    snd_pcm_state_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_status_get_trigger_htstamp
void snd_pcm_status_get_trigger_htstamp(const snd_pcm_status_t * obj, snd_htimestamp_t * ptr) {
    snd_pcm_status_get_trigger_htstamp_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_trigger_htstamp_INDEXED));
    packed_data->func = snd_pcm_status_get_trigger_htstamp_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_status_get_trigger_tstamp
void snd_pcm_status_get_trigger_tstamp(const snd_pcm_status_t * obj, snd_timestamp_t * ptr) {
    snd_pcm_status_get_trigger_tstamp_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_trigger_tstamp_INDEXED));
    packed_data->func = snd_pcm_status_get_trigger_tstamp_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_status_get_tstamp
void snd_pcm_status_get_tstamp(const snd_pcm_status_t * obj, snd_timestamp_t * ptr) {
    snd_pcm_status_get_tstamp_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_get_tstamp_INDEXED));
    packed_data->func = snd_pcm_status_get_tstamp_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_status_malloc
int snd_pcm_status_malloc(snd_pcm_status_t ** ptr) {
    snd_pcm_status_malloc_INDEXED *packed_data = malloc(sizeof(snd_pcm_status_malloc_INDEXED));
    packed_data->func = snd_pcm_status_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_stream
snd_pcm_stream_t snd_pcm_stream(snd_pcm_t * pcm) {
    snd_pcm_stream_INDEXED *packed_data = malloc(sizeof(snd_pcm_stream_INDEXED));
    packed_data->func = snd_pcm_stream_INDEX;
    packed_data->args.a1 = pcm;
    snd_pcm_stream_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_stream_name
const char * snd_pcm_stream_name(const snd_pcm_stream_t stream) {
    snd_pcm_stream_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_stream_name_INDEXED));
    packed_data->func = snd_pcm_stream_name_INDEX;
    packed_data->args.a1 = stream;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_subformat_description
const char * snd_pcm_subformat_description(const snd_pcm_subformat_t subformat) {
    snd_pcm_subformat_description_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_description_INDEXED));
    packed_data->func = snd_pcm_subformat_description_INDEX;
    packed_data->args.a1 = subformat;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_any
void snd_pcm_subformat_mask_any(snd_pcm_subformat_mask_t * mask) {
    snd_pcm_subformat_mask_any_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_any_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_any_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_copy
void snd_pcm_subformat_mask_copy(snd_pcm_subformat_mask_t * dst, const snd_pcm_subformat_mask_t * src) {
    snd_pcm_subformat_mask_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_copy_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_empty
int snd_pcm_subformat_mask_empty(const snd_pcm_subformat_mask_t * mask) {
    snd_pcm_subformat_mask_empty_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_empty_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_empty_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_free
void snd_pcm_subformat_mask_free(snd_pcm_subformat_mask_t * obj) {
    snd_pcm_subformat_mask_free_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_free_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_malloc
int snd_pcm_subformat_mask_malloc(snd_pcm_subformat_mask_t ** ptr) {
    snd_pcm_subformat_mask_malloc_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_malloc_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_none
void snd_pcm_subformat_mask_none(snd_pcm_subformat_mask_t * mask) {
    snd_pcm_subformat_mask_none_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_none_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_none_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_reset
void snd_pcm_subformat_mask_reset(snd_pcm_subformat_mask_t * mask, snd_pcm_subformat_t val) {
    snd_pcm_subformat_mask_reset_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_reset_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_reset_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_set
void snd_pcm_subformat_mask_set(snd_pcm_subformat_mask_t * mask, snd_pcm_subformat_t val) {
    snd_pcm_subformat_mask_set_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_set_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_set_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_subformat_mask_test
int snd_pcm_subformat_mask_test(const snd_pcm_subformat_mask_t * mask, snd_pcm_subformat_t val) {
    snd_pcm_subformat_mask_test_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_mask_test_INDEXED));
    packed_data->func = snd_pcm_subformat_mask_test_INDEX;
    packed_data->args.a1 = mask;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_subformat_name
const char * snd_pcm_subformat_name(const snd_pcm_subformat_t subformat) {
    snd_pcm_subformat_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_subformat_name_INDEXED));
    packed_data->func = snd_pcm_subformat_name_INDEX;
    packed_data->args.a1 = subformat;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params
int snd_pcm_sw_params(snd_pcm_t * pcm, snd_pcm_sw_params_t * params) {
    snd_pcm_sw_params_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_INDEXED));
    packed_data->func = snd_pcm_sw_params_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_copy
void snd_pcm_sw_params_copy(snd_pcm_sw_params_t * dst, const snd_pcm_sw_params_t * src) {
    snd_pcm_sw_params_copy_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_copy_INDEXED));
    packed_data->func = snd_pcm_sw_params_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_sw_params_current
int snd_pcm_sw_params_current(snd_pcm_t * pcm, snd_pcm_sw_params_t * params) {
    snd_pcm_sw_params_current_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_current_INDEXED));
    packed_data->func = snd_pcm_sw_params_current_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_dump
int snd_pcm_sw_params_dump(snd_pcm_sw_params_t * params, snd_output_t * out) {
    snd_pcm_sw_params_dump_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_dump_INDEXED));
    packed_data->func = snd_pcm_sw_params_dump_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = out;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_free
void snd_pcm_sw_params_free(snd_pcm_sw_params_t * obj) {
    snd_pcm_sw_params_free_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_free_INDEXED));
    packed_data->func = snd_pcm_sw_params_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_avail_min
int snd_pcm_sw_params_get_avail_min(const snd_pcm_sw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_sw_params_get_avail_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_avail_min_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_avail_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_boundary
int snd_pcm_sw_params_get_boundary(const snd_pcm_sw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_sw_params_get_boundary_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_boundary_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_boundary_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_silence_size
int snd_pcm_sw_params_get_silence_size(const snd_pcm_sw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_sw_params_get_silence_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_silence_size_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_silence_size_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_silence_threshold
int snd_pcm_sw_params_get_silence_threshold(const snd_pcm_sw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_sw_params_get_silence_threshold_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_silence_threshold_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_silence_threshold_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_sleep_min
int snd_pcm_sw_params_get_sleep_min(const snd_pcm_sw_params_t * params, unsigned int * val) {
    snd_pcm_sw_params_get_sleep_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_sleep_min_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_sleep_min_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_start_mode
snd_pcm_start_t snd_pcm_sw_params_get_start_mode(const snd_pcm_sw_params_t * params) {
    snd_pcm_sw_params_get_start_mode_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_start_mode_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_start_mode_INDEX;
    packed_data->args.a1 = params;
    snd_pcm_start_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_start_threshold
int snd_pcm_sw_params_get_start_threshold(const snd_pcm_sw_params_t * paramsm, snd_pcm_uframes_t * val) {
    snd_pcm_sw_params_get_start_threshold_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_start_threshold_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_start_threshold_INDEX;
    packed_data->args.a1 = paramsm;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_stop_threshold
int snd_pcm_sw_params_get_stop_threshold(const snd_pcm_sw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_sw_params_get_stop_threshold_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_stop_threshold_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_stop_threshold_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_tstamp_mode
int snd_pcm_sw_params_get_tstamp_mode(const snd_pcm_sw_params_t * params, snd_pcm_tstamp_t * val) {
    snd_pcm_sw_params_get_tstamp_mode_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_tstamp_mode_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_tstamp_mode_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_xfer_align
int snd_pcm_sw_params_get_xfer_align(const snd_pcm_sw_params_t * params, snd_pcm_uframes_t * val) {
    snd_pcm_sw_params_get_xfer_align_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_xfer_align_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_xfer_align_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_get_xrun_mode
snd_pcm_xrun_t snd_pcm_sw_params_get_xrun_mode(const snd_pcm_sw_params_t * params) {
    snd_pcm_sw_params_get_xrun_mode_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_get_xrun_mode_INDEXED));
    packed_data->func = snd_pcm_sw_params_get_xrun_mode_INDEX;
    packed_data->args.a1 = params;
    snd_pcm_xrun_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_malloc
int snd_pcm_sw_params_malloc(snd_pcm_sw_params_t ** ptr) {
    snd_pcm_sw_params_malloc_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_malloc_INDEXED));
    packed_data->func = snd_pcm_sw_params_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_avail_min
int snd_pcm_sw_params_set_avail_min(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_uframes_t val) {
    snd_pcm_sw_params_set_avail_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_avail_min_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_avail_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_silence_size
int snd_pcm_sw_params_set_silence_size(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_uframes_t val) {
    snd_pcm_sw_params_set_silence_size_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_silence_size_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_silence_size_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_silence_threshold
int snd_pcm_sw_params_set_silence_threshold(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_uframes_t val) {
    snd_pcm_sw_params_set_silence_threshold_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_silence_threshold_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_silence_threshold_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_sleep_min
int snd_pcm_sw_params_set_sleep_min(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, unsigned int val) {
    snd_pcm_sw_params_set_sleep_min_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_sleep_min_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_sleep_min_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_start_mode
int snd_pcm_sw_params_set_start_mode(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_start_t val) {
    snd_pcm_sw_params_set_start_mode_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_start_mode_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_start_mode_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_start_threshold
int snd_pcm_sw_params_set_start_threshold(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_uframes_t val) {
    snd_pcm_sw_params_set_start_threshold_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_start_threshold_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_start_threshold_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_stop_threshold
int snd_pcm_sw_params_set_stop_threshold(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_uframes_t val) {
    snd_pcm_sw_params_set_stop_threshold_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_stop_threshold_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_stop_threshold_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_tstamp_mode
int snd_pcm_sw_params_set_tstamp_mode(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_tstamp_t val) {
    snd_pcm_sw_params_set_tstamp_mode_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_tstamp_mode_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_tstamp_mode_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_xfer_align
int snd_pcm_sw_params_set_xfer_align(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_uframes_t val) {
    snd_pcm_sw_params_set_xfer_align_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_xfer_align_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_xfer_align_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_sw_params_set_xrun_mode
int snd_pcm_sw_params_set_xrun_mode(snd_pcm_t * pcm, snd_pcm_sw_params_t * params, snd_pcm_xrun_t val) {
    snd_pcm_sw_params_set_xrun_mode_INDEXED *packed_data = malloc(sizeof(snd_pcm_sw_params_set_xrun_mode_INDEXED));
    packed_data->func = snd_pcm_sw_params_set_xrun_mode_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_tstamp_mode_name
const char * snd_pcm_tstamp_mode_name(const snd_pcm_tstamp_t mode) {
    snd_pcm_tstamp_mode_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_tstamp_mode_name_INDEXED));
    packed_data->func = snd_pcm_tstamp_mode_name_INDEX;
    packed_data->args.a1 = mode;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_type
snd_pcm_type_t snd_pcm_type(snd_pcm_t * pcm) {
    snd_pcm_type_INDEXED *packed_data = malloc(sizeof(snd_pcm_type_INDEXED));
    packed_data->func = snd_pcm_type_INDEX;
    packed_data->args.a1 = pcm;
    snd_pcm_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_type_name
const char * snd_pcm_type_name(snd_pcm_type_t type) {
    snd_pcm_type_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_type_name_INDEXED));
    packed_data->func = snd_pcm_type_name_INDEX;
    packed_data->args.a1 = type;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_unlink
int snd_pcm_unlink(snd_pcm_t * pcm) {
    snd_pcm_unlink_INDEXED *packed_data = malloc(sizeof(snd_pcm_unlink_INDEXED));
    packed_data->func = snd_pcm_unlink_INDEX;
    packed_data->args.a1 = pcm;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_wait
int snd_pcm_wait(snd_pcm_t * pcm, int timeout) {
    snd_pcm_wait_INDEXED *packed_data = malloc(sizeof(snd_pcm_wait_INDEXED));
    packed_data->func = snd_pcm_wait_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = timeout;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_writei
snd_pcm_sframes_t snd_pcm_writei(snd_pcm_t * pcm, const void * buffer, snd_pcm_uframes_t size) {
    snd_pcm_writei_INDEXED *packed_data = malloc(sizeof(snd_pcm_writei_INDEXED));
    packed_data->func = snd_pcm_writei_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_writen
snd_pcm_sframes_t snd_pcm_writen(snd_pcm_t * pcm, void ** bufs, snd_pcm_uframes_t size) {
    snd_pcm_writen_INDEXED *packed_data = malloc(sizeof(snd_pcm_writen_INDEXED));
    packed_data->func = snd_pcm_writen_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = bufs;
    packed_data->args.a3 = size;
    snd_pcm_sframes_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_pcm_xrun_mode_name
const char * snd_pcm_xrun_mode_name(snd_pcm_xrun_t mode) {
    snd_pcm_xrun_mode_name_INDEXED *packed_data = malloc(sizeof(snd_pcm_xrun_mode_name_INDEXED));
    packed_data->func = snd_pcm_xrun_mode_name_INDEX;
    packed_data->args.a1 = mode;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_close
int snd_rawmidi_close(snd_rawmidi_t * rmidi) {
    snd_rawmidi_close_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_close_INDEXED));
    packed_data->func = snd_rawmidi_close_INDEX;
    packed_data->args.a1 = rmidi;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_drain
int snd_rawmidi_drain(snd_rawmidi_t * rmidi) {
    snd_rawmidi_drain_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_drain_INDEXED));
    packed_data->func = snd_rawmidi_drain_INDEX;
    packed_data->args.a1 = rmidi;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_drop
int snd_rawmidi_drop(snd_rawmidi_t * rmidi) {
    snd_rawmidi_drop_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_drop_INDEXED));
    packed_data->func = snd_rawmidi_drop_INDEX;
    packed_data->args.a1 = rmidi;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info
int snd_rawmidi_info(snd_rawmidi_t * rmidi, snd_rawmidi_info_t * info) {
    snd_rawmidi_info_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_INDEXED));
    packed_data->func = snd_rawmidi_info_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_copy
void snd_rawmidi_info_copy(snd_rawmidi_info_t * dst, const snd_rawmidi_info_t * src) {
    snd_rawmidi_info_copy_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_copy_INDEXED));
    packed_data->func = snd_rawmidi_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_info_free
void snd_rawmidi_info_free(snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_free_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_free_INDEXED));
    packed_data->func = snd_rawmidi_info_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_card
int snd_rawmidi_info_get_card(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_card_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_card_INDEXED));
    packed_data->func = snd_rawmidi_info_get_card_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_device
unsigned int snd_rawmidi_info_get_device(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_device_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_device_INDEXED));
    packed_data->func = snd_rawmidi_info_get_device_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_flags
unsigned int snd_rawmidi_info_get_flags(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_flags_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_flags_INDEXED));
    packed_data->func = snd_rawmidi_info_get_flags_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_id
const char * snd_rawmidi_info_get_id(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_id_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_id_INDEXED));
    packed_data->func = snd_rawmidi_info_get_id_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_name
const char * snd_rawmidi_info_get_name(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_name_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_name_INDEXED));
    packed_data->func = snd_rawmidi_info_get_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_stream
snd_rawmidi_stream_t snd_rawmidi_info_get_stream(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_stream_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_stream_INDEXED));
    packed_data->func = snd_rawmidi_info_get_stream_INDEX;
    packed_data->args.a1 = obj;
    snd_rawmidi_stream_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_subdevice
unsigned int snd_rawmidi_info_get_subdevice(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_subdevice_INDEXED));
    packed_data->func = snd_rawmidi_info_get_subdevice_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_subdevice_name
const char * snd_rawmidi_info_get_subdevice_name(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_subdevice_name_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_subdevice_name_INDEXED));
    packed_data->func = snd_rawmidi_info_get_subdevice_name_INDEX;
    packed_data->args.a1 = obj;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_subdevices_avail
unsigned int snd_rawmidi_info_get_subdevices_avail(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_subdevices_avail_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_subdevices_avail_INDEXED));
    packed_data->func = snd_rawmidi_info_get_subdevices_avail_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_get_subdevices_count
unsigned int snd_rawmidi_info_get_subdevices_count(const snd_rawmidi_info_t * obj) {
    snd_rawmidi_info_get_subdevices_count_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_get_subdevices_count_INDEXED));
    packed_data->func = snd_rawmidi_info_get_subdevices_count_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_malloc
int snd_rawmidi_info_malloc(snd_rawmidi_info_t ** ptr) {
    snd_rawmidi_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_malloc_INDEXED));
    packed_data->func = snd_rawmidi_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_info_set_device
void snd_rawmidi_info_set_device(snd_rawmidi_info_t * obj, unsigned int val) {
    snd_rawmidi_info_set_device_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_set_device_INDEXED));
    packed_data->func = snd_rawmidi_info_set_device_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_info_set_stream
void snd_rawmidi_info_set_stream(snd_rawmidi_info_t * obj, snd_rawmidi_stream_t val) {
    snd_rawmidi_info_set_stream_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_set_stream_INDEXED));
    packed_data->func = snd_rawmidi_info_set_stream_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_info_set_subdevice
void snd_rawmidi_info_set_subdevice(snd_rawmidi_info_t * obj, unsigned int val) {
    snd_rawmidi_info_set_subdevice_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_set_subdevice_INDEXED));
    packed_data->func = snd_rawmidi_info_set_subdevice_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_info_sizeof
size_t snd_rawmidi_info_sizeof() {
    snd_rawmidi_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_info_sizeof_INDEXED));
    packed_data->func = snd_rawmidi_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_name
const char * snd_rawmidi_name(snd_rawmidi_t * rmidi) {
    snd_rawmidi_name_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_name_INDEXED));
    packed_data->func = snd_rawmidi_name_INDEX;
    packed_data->args.a1 = rmidi;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_nonblock
int snd_rawmidi_nonblock(snd_rawmidi_t * rmidi, int nonblock) {
    snd_rawmidi_nonblock_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_nonblock_INDEXED));
    packed_data->func = snd_rawmidi_nonblock_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = nonblock;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_open
int snd_rawmidi_open(snd_rawmidi_t ** in_rmidi, snd_rawmidi_t ** out_rmidi, const char * name, int mode) {
    snd_rawmidi_open_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_open_INDEXED));
    packed_data->func = snd_rawmidi_open_INDEX;
    packed_data->args.a1 = in_rmidi;
    packed_data->args.a2 = out_rmidi;
    packed_data->args.a3 = name;
    packed_data->args.a4 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_open_lconf
int snd_rawmidi_open_lconf(snd_rawmidi_t ** in_rmidi, snd_rawmidi_t ** out_rmidi, const char * name, int mode, snd_config_t * lconf) {
    snd_rawmidi_open_lconf_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_open_lconf_INDEXED));
    packed_data->func = snd_rawmidi_open_lconf_INDEX;
    packed_data->args.a1 = in_rmidi;
    packed_data->args.a2 = out_rmidi;
    packed_data->args.a3 = name;
    packed_data->args.a4 = mode;
    packed_data->args.a5 = lconf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params
int snd_rawmidi_params(snd_rawmidi_t * rmidi, snd_rawmidi_params_t * params) {
    snd_rawmidi_params_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_INDEXED));
    packed_data->func = snd_rawmidi_params_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_copy
void snd_rawmidi_params_copy(snd_rawmidi_params_t * dst, const snd_rawmidi_params_t * src) {
    snd_rawmidi_params_copy_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_copy_INDEXED));
    packed_data->func = snd_rawmidi_params_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_params_current
int snd_rawmidi_params_current(snd_rawmidi_t * rmidi, snd_rawmidi_params_t * params) {
    snd_rawmidi_params_current_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_current_INDEXED));
    packed_data->func = snd_rawmidi_params_current_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_free
void snd_rawmidi_params_free(snd_rawmidi_params_t * obj) {
    snd_rawmidi_params_free_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_free_INDEXED));
    packed_data->func = snd_rawmidi_params_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_params_get_avail_min
size_t snd_rawmidi_params_get_avail_min(const snd_rawmidi_params_t * params) {
    snd_rawmidi_params_get_avail_min_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_get_avail_min_INDEXED));
    packed_data->func = snd_rawmidi_params_get_avail_min_INDEX;
    packed_data->args.a1 = params;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_get_buffer_size
size_t snd_rawmidi_params_get_buffer_size(const snd_rawmidi_params_t * params) {
    snd_rawmidi_params_get_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_get_buffer_size_INDEXED));
    packed_data->func = snd_rawmidi_params_get_buffer_size_INDEX;
    packed_data->args.a1 = params;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_get_no_active_sensing
int snd_rawmidi_params_get_no_active_sensing(const snd_rawmidi_params_t * params) {
    snd_rawmidi_params_get_no_active_sensing_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_get_no_active_sensing_INDEXED));
    packed_data->func = snd_rawmidi_params_get_no_active_sensing_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_malloc
int snd_rawmidi_params_malloc(snd_rawmidi_params_t ** ptr) {
    snd_rawmidi_params_malloc_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_malloc_INDEXED));
    packed_data->func = snd_rawmidi_params_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_set_avail_min
int snd_rawmidi_params_set_avail_min(snd_rawmidi_t * rmidi, snd_rawmidi_params_t * params, size_t val) {
    snd_rawmidi_params_set_avail_min_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_set_avail_min_INDEXED));
    packed_data->func = snd_rawmidi_params_set_avail_min_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_set_buffer_size
int snd_rawmidi_params_set_buffer_size(snd_rawmidi_t * rmidi, snd_rawmidi_params_t * params, size_t val) {
    snd_rawmidi_params_set_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_set_buffer_size_INDEXED));
    packed_data->func = snd_rawmidi_params_set_buffer_size_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_set_no_active_sensing
int snd_rawmidi_params_set_no_active_sensing(snd_rawmidi_t * rmidi, snd_rawmidi_params_t * params, int val) {
    snd_rawmidi_params_set_no_active_sensing_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_set_no_active_sensing_INDEXED));
    packed_data->func = snd_rawmidi_params_set_no_active_sensing_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = params;
    packed_data->args.a3 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_params_sizeof
size_t snd_rawmidi_params_sizeof() {
    snd_rawmidi_params_sizeof_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_params_sizeof_INDEXED));
    packed_data->func = snd_rawmidi_params_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_poll_descriptors
int snd_rawmidi_poll_descriptors(snd_rawmidi_t * rmidi, struct pollfd * pfds, unsigned int space) {
    snd_rawmidi_poll_descriptors_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_poll_descriptors_INDEXED));
    packed_data->func = snd_rawmidi_poll_descriptors_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = space;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_poll_descriptors_count
int snd_rawmidi_poll_descriptors_count(snd_rawmidi_t * rmidi) {
    snd_rawmidi_poll_descriptors_count_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_poll_descriptors_count_INDEXED));
    packed_data->func = snd_rawmidi_poll_descriptors_count_INDEX;
    packed_data->args.a1 = rmidi;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_poll_descriptors_revents
int snd_rawmidi_poll_descriptors_revents(snd_rawmidi_t * rawmidi, struct pollfd * pfds, unsigned int nfds, unsigned short * revent) {
    snd_rawmidi_poll_descriptors_revents_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_poll_descriptors_revents_INDEXED));
    packed_data->func = snd_rawmidi_poll_descriptors_revents_INDEX;
    packed_data->args.a1 = rawmidi;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = nfds;
    packed_data->args.a4 = revent;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_read
ssize_t snd_rawmidi_read(snd_rawmidi_t * rmidi, void * buffer, size_t size) {
    snd_rawmidi_read_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_read_INDEXED));
    packed_data->func = snd_rawmidi_read_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_status
int snd_rawmidi_status(snd_rawmidi_t * rmidi, snd_rawmidi_status_t * status) {
    snd_rawmidi_status_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_status_INDEXED));
    packed_data->func = snd_rawmidi_status_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = status;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_status_copy
void snd_rawmidi_status_copy(snd_rawmidi_status_t * dst, const snd_rawmidi_status_t * src) {
    snd_rawmidi_status_copy_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_status_copy_INDEXED));
    packed_data->func = snd_rawmidi_status_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_status_free
void snd_rawmidi_status_free(snd_rawmidi_status_t * obj) {
    snd_rawmidi_status_free_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_status_free_INDEXED));
    packed_data->func = snd_rawmidi_status_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_status_get_avail
size_t snd_rawmidi_status_get_avail(const snd_rawmidi_status_t * obj) {
    snd_rawmidi_status_get_avail_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_status_get_avail_INDEXED));
    packed_data->func = snd_rawmidi_status_get_avail_INDEX;
    packed_data->args.a1 = obj;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_status_get_tstamp
void snd_rawmidi_status_get_tstamp(const snd_rawmidi_status_t * obj, snd_htimestamp_t * ptr) {
    snd_rawmidi_status_get_tstamp_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_status_get_tstamp_INDEXED));
    packed_data->func = snd_rawmidi_status_get_tstamp_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_rawmidi_status_get_xruns
size_t snd_rawmidi_status_get_xruns(const snd_rawmidi_status_t * obj) {
    snd_rawmidi_status_get_xruns_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_status_get_xruns_INDEXED));
    packed_data->func = snd_rawmidi_status_get_xruns_INDEX;
    packed_data->args.a1 = obj;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_status_malloc
int snd_rawmidi_status_malloc(snd_rawmidi_status_t ** ptr) {
    snd_rawmidi_status_malloc_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_status_malloc_INDEXED));
    packed_data->func = snd_rawmidi_status_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_status_sizeof
size_t snd_rawmidi_status_sizeof() {
    snd_rawmidi_status_sizeof_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_status_sizeof_INDEXED));
    packed_data->func = snd_rawmidi_status_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_stream
snd_rawmidi_stream_t snd_rawmidi_stream(snd_rawmidi_t * rawmidi) {
    snd_rawmidi_stream_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_stream_INDEXED));
    packed_data->func = snd_rawmidi_stream_INDEX;
    packed_data->args.a1 = rawmidi;
    snd_rawmidi_stream_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_type
snd_rawmidi_type_t snd_rawmidi_type(snd_rawmidi_t * rmidi) {
    snd_rawmidi_type_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_type_INDEXED));
    packed_data->func = snd_rawmidi_type_INDEX;
    packed_data->args.a1 = rmidi;
    snd_rawmidi_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_rawmidi_write
ssize_t snd_rawmidi_write(snd_rawmidi_t * rmidi, const void * buffer, size_t size) {
    snd_rawmidi_write_INDEXED *packed_data = malloc(sizeof(snd_rawmidi_write_INDEXED));
    packed_data->func = snd_rawmidi_write_INDEX;
    packed_data->args.a1 = rmidi;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_sctl_build
int snd_sctl_build(snd_sctl_t ** ctl, snd_ctl_t * handle, snd_config_t * config, snd_config_t * private_data, int mode) {
    snd_sctl_build_INDEXED *packed_data = malloc(sizeof(snd_sctl_build_INDEXED));
    packed_data->func = snd_sctl_build_INDEX;
    packed_data->args.a1 = ctl;
    packed_data->args.a2 = handle;
    packed_data->args.a3 = config;
    packed_data->args.a4 = private_data;
    packed_data->args.a5 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_sctl_free
int snd_sctl_free(snd_sctl_t * handle) {
    snd_sctl_free_INDEXED *packed_data = malloc(sizeof(snd_sctl_free_INDEXED));
    packed_data->func = snd_sctl_free_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_sctl_install
int snd_sctl_install(snd_sctl_t * handle) {
    snd_sctl_install_INDEXED *packed_data = malloc(sizeof(snd_sctl_install_INDEXED));
    packed_data->func = snd_sctl_install_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_sctl_remove
int snd_sctl_remove(snd_sctl_t * handle) {
    snd_sctl_remove_INDEXED *packed_data = malloc(sizeof(snd_sctl_remove_INDEXED));
    packed_data->func = snd_sctl_remove_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_alloc_named_queue
int snd_seq_alloc_named_queue(snd_seq_t * seq, const char * name) {
    snd_seq_alloc_named_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_alloc_named_queue_INDEXED));
    packed_data->func = snd_seq_alloc_named_queue_INDEX;
    packed_data->args.a1 = seq;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_alloc_queue
int snd_seq_alloc_queue(snd_seq_t * handle) {
    snd_seq_alloc_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_alloc_queue_INDEXED));
    packed_data->func = snd_seq_alloc_queue_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_change_bit
int snd_seq_change_bit(int nr, void * array) {
    snd_seq_change_bit_INDEXED *packed_data = malloc(sizeof(snd_seq_change_bit_INDEXED));
    packed_data->func = snd_seq_change_bit_INDEX;
    packed_data->args.a1 = nr;
    packed_data->args.a2 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_id
int snd_seq_client_id(snd_seq_t * handle) {
    snd_seq_client_id_INDEXED *packed_data = malloc(sizeof(snd_seq_client_id_INDEXED));
    packed_data->func = snd_seq_client_id_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_copy
void snd_seq_client_info_copy(snd_seq_client_info_t * dst, const snd_seq_client_info_t * src) {
    snd_seq_client_info_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_copy_INDEXED));
    packed_data->func = snd_seq_client_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_info_free
void snd_seq_client_info_free(snd_seq_client_info_t * ptr) {
    snd_seq_client_info_free_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_free_INDEXED));
    packed_data->func = snd_seq_client_info_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_info_get_broadcast_filter
int snd_seq_client_info_get_broadcast_filter(const snd_seq_client_info_t * info) {
    snd_seq_client_info_get_broadcast_filter_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_get_broadcast_filter_INDEXED));
    packed_data->func = snd_seq_client_info_get_broadcast_filter_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_get_client
int snd_seq_client_info_get_client(const snd_seq_client_info_t * info) {
    snd_seq_client_info_get_client_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_get_client_INDEXED));
    packed_data->func = snd_seq_client_info_get_client_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_get_error_bounce
int snd_seq_client_info_get_error_bounce(const snd_seq_client_info_t * info) {
    snd_seq_client_info_get_error_bounce_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_get_error_bounce_INDEXED));
    packed_data->func = snd_seq_client_info_get_error_bounce_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_get_event_filter
const unsigned char * snd_seq_client_info_get_event_filter(const snd_seq_client_info_t * info) {
    snd_seq_client_info_get_event_filter_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_get_event_filter_INDEXED));
    packed_data->func = snd_seq_client_info_get_event_filter_INDEX;
    packed_data->args.a1 = info;
    const unsigned char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_get_event_lost
int snd_seq_client_info_get_event_lost(const snd_seq_client_info_t * info) {
    snd_seq_client_info_get_event_lost_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_get_event_lost_INDEXED));
    packed_data->func = snd_seq_client_info_get_event_lost_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_get_name
const char * snd_seq_client_info_get_name(snd_seq_client_info_t * info) {
    snd_seq_client_info_get_name_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_get_name_INDEXED));
    packed_data->func = snd_seq_client_info_get_name_INDEX;
    packed_data->args.a1 = info;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_get_num_ports
int snd_seq_client_info_get_num_ports(const snd_seq_client_info_t * info) {
    snd_seq_client_info_get_num_ports_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_get_num_ports_INDEXED));
    packed_data->func = snd_seq_client_info_get_num_ports_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_get_type
snd_seq_client_type_t snd_seq_client_info_get_type(const snd_seq_client_info_t * info) {
    snd_seq_client_info_get_type_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_get_type_INDEXED));
    packed_data->func = snd_seq_client_info_get_type_INDEX;
    packed_data->args.a1 = info;
    snd_seq_client_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_malloc
int snd_seq_client_info_malloc(snd_seq_client_info_t ** ptr) {
    snd_seq_client_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_malloc_INDEXED));
    packed_data->func = snd_seq_client_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_info_set_broadcast_filter
void snd_seq_client_info_set_broadcast_filter(snd_seq_client_info_t * info, int val) {
    snd_seq_client_info_set_broadcast_filter_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_set_broadcast_filter_INDEXED));
    packed_data->func = snd_seq_client_info_set_broadcast_filter_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_info_set_client
void snd_seq_client_info_set_client(snd_seq_client_info_t * info, int client) {
    snd_seq_client_info_set_client_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_set_client_INDEXED));
    packed_data->func = snd_seq_client_info_set_client_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = client;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_info_set_error_bounce
void snd_seq_client_info_set_error_bounce(snd_seq_client_info_t * info, int val) {
    snd_seq_client_info_set_error_bounce_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_set_error_bounce_INDEXED));
    packed_data->func = snd_seq_client_info_set_error_bounce_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_info_set_event_filter
void snd_seq_client_info_set_event_filter(snd_seq_client_info_t * info, unsigned char * filter) {
    snd_seq_client_info_set_event_filter_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_set_event_filter_INDEXED));
    packed_data->func = snd_seq_client_info_set_event_filter_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = filter;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_info_set_name
void snd_seq_client_info_set_name(snd_seq_client_info_t * info, const char * name) {
    snd_seq_client_info_set_name_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_set_name_INDEXED));
    packed_data->func = snd_seq_client_info_set_name_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_info_sizeof
size_t snd_seq_client_info_sizeof() {
    snd_seq_client_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_client_info_sizeof_INDEXED));
    packed_data->func = snd_seq_client_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_pool_copy
void snd_seq_client_pool_copy(snd_seq_client_pool_t * dst, const snd_seq_client_pool_t * src) {
    snd_seq_client_pool_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_copy_INDEXED));
    packed_data->func = snd_seq_client_pool_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_pool_free
void snd_seq_client_pool_free(snd_seq_client_pool_t * ptr) {
    snd_seq_client_pool_free_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_free_INDEXED));
    packed_data->func = snd_seq_client_pool_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_pool_get_client
int snd_seq_client_pool_get_client(const snd_seq_client_pool_t * info) {
    snd_seq_client_pool_get_client_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_get_client_INDEXED));
    packed_data->func = snd_seq_client_pool_get_client_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_pool_get_input_free
size_t snd_seq_client_pool_get_input_free(const snd_seq_client_pool_t * info) {
    snd_seq_client_pool_get_input_free_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_get_input_free_INDEXED));
    packed_data->func = snd_seq_client_pool_get_input_free_INDEX;
    packed_data->args.a1 = info;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_pool_get_input_pool
size_t snd_seq_client_pool_get_input_pool(const snd_seq_client_pool_t * info) {
    snd_seq_client_pool_get_input_pool_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_get_input_pool_INDEXED));
    packed_data->func = snd_seq_client_pool_get_input_pool_INDEX;
    packed_data->args.a1 = info;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_pool_get_output_free
size_t snd_seq_client_pool_get_output_free(const snd_seq_client_pool_t * info) {
    snd_seq_client_pool_get_output_free_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_get_output_free_INDEXED));
    packed_data->func = snd_seq_client_pool_get_output_free_INDEX;
    packed_data->args.a1 = info;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_pool_get_output_pool
size_t snd_seq_client_pool_get_output_pool(const snd_seq_client_pool_t * info) {
    snd_seq_client_pool_get_output_pool_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_get_output_pool_INDEXED));
    packed_data->func = snd_seq_client_pool_get_output_pool_INDEX;
    packed_data->args.a1 = info;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_pool_get_output_room
size_t snd_seq_client_pool_get_output_room(const snd_seq_client_pool_t * info) {
    snd_seq_client_pool_get_output_room_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_get_output_room_INDEXED));
    packed_data->func = snd_seq_client_pool_get_output_room_INDEX;
    packed_data->args.a1 = info;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_pool_malloc
int snd_seq_client_pool_malloc(snd_seq_client_pool_t ** ptr) {
    snd_seq_client_pool_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_malloc_INDEXED));
    packed_data->func = snd_seq_client_pool_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_client_pool_set_input_pool
void snd_seq_client_pool_set_input_pool(snd_seq_client_pool_t * info, size_t size) {
    snd_seq_client_pool_set_input_pool_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_set_input_pool_INDEXED));
    packed_data->func = snd_seq_client_pool_set_input_pool_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_pool_set_output_pool
void snd_seq_client_pool_set_output_pool(snd_seq_client_pool_t * info, size_t size) {
    snd_seq_client_pool_set_output_pool_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_set_output_pool_INDEXED));
    packed_data->func = snd_seq_client_pool_set_output_pool_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_pool_set_output_room
void snd_seq_client_pool_set_output_room(snd_seq_client_pool_t * info, size_t size) {
    snd_seq_client_pool_set_output_room_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_set_output_room_INDEXED));
    packed_data->func = snd_seq_client_pool_set_output_room_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_client_pool_sizeof
size_t snd_seq_client_pool_sizeof() {
    snd_seq_client_pool_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_client_pool_sizeof_INDEXED));
    packed_data->func = snd_seq_client_pool_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_close
int snd_seq_close(snd_seq_t * handle) {
    snd_seq_close_INDEXED *packed_data = malloc(sizeof(snd_seq_close_INDEXED));
    packed_data->func = snd_seq_close_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_create_port
int snd_seq_create_port(snd_seq_t * handle, snd_seq_port_info_t * info) {
    snd_seq_create_port_INDEXED *packed_data = malloc(sizeof(snd_seq_create_port_INDEXED));
    packed_data->func = snd_seq_create_port_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_create_queue
int snd_seq_create_queue(snd_seq_t * seq, snd_seq_queue_info_t * info) {
    snd_seq_create_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_create_queue_INDEXED));
    packed_data->func = snd_seq_create_queue_INDEX;
    packed_data->args.a1 = seq;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_delete_port
int snd_seq_delete_port(snd_seq_t * handle, int port) {
    snd_seq_delete_port_INDEXED *packed_data = malloc(sizeof(snd_seq_delete_port_INDEXED));
    packed_data->func = snd_seq_delete_port_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = port;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_drain_output
int snd_seq_drain_output(snd_seq_t * handle) {
    snd_seq_drain_output_INDEXED *packed_data = malloc(sizeof(snd_seq_drain_output_INDEXED));
    packed_data->func = snd_seq_drain_output_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_drop_input
int snd_seq_drop_input(snd_seq_t * handle) {
    snd_seq_drop_input_INDEXED *packed_data = malloc(sizeof(snd_seq_drop_input_INDEXED));
    packed_data->func = snd_seq_drop_input_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_drop_input_buffer
int snd_seq_drop_input_buffer(snd_seq_t * handle) {
    snd_seq_drop_input_buffer_INDEXED *packed_data = malloc(sizeof(snd_seq_drop_input_buffer_INDEXED));
    packed_data->func = snd_seq_drop_input_buffer_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_drop_output
int snd_seq_drop_output(snd_seq_t * handle) {
    snd_seq_drop_output_INDEXED *packed_data = malloc(sizeof(snd_seq_drop_output_INDEXED));
    packed_data->func = snd_seq_drop_output_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_drop_output_buffer
int snd_seq_drop_output_buffer(snd_seq_t * handle) {
    snd_seq_drop_output_buffer_INDEXED *packed_data = malloc(sizeof(snd_seq_drop_output_buffer_INDEXED));
    packed_data->func = snd_seq_drop_output_buffer_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_event_input
int snd_seq_event_input(snd_seq_t * handle, snd_seq_event_t ** ev) {
    snd_seq_event_input_INDEXED *packed_data = malloc(sizeof(snd_seq_event_input_INDEXED));
    packed_data->func = snd_seq_event_input_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = ev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_event_input_pending
int snd_seq_event_input_pending(snd_seq_t * seq, int fetch_sequencer) {
    snd_seq_event_input_pending_INDEXED *packed_data = malloc(sizeof(snd_seq_event_input_pending_INDEXED));
    packed_data->func = snd_seq_event_input_pending_INDEX;
    packed_data->args.a1 = seq;
    packed_data->args.a2 = fetch_sequencer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_event_length
ssize_t snd_seq_event_length(snd_seq_event_t * ev) {
    snd_seq_event_length_INDEXED *packed_data = malloc(sizeof(snd_seq_event_length_INDEXED));
    packed_data->func = snd_seq_event_length_INDEX;
    packed_data->args.a1 = ev;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_event_output
int snd_seq_event_output(snd_seq_t * handle, snd_seq_event_t * ev) {
    snd_seq_event_output_INDEXED *packed_data = malloc(sizeof(snd_seq_event_output_INDEXED));
    packed_data->func = snd_seq_event_output_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = ev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_event_output_buffer
int snd_seq_event_output_buffer(snd_seq_t * handle, snd_seq_event_t * ev) {
    snd_seq_event_output_buffer_INDEXED *packed_data = malloc(sizeof(snd_seq_event_output_buffer_INDEXED));
    packed_data->func = snd_seq_event_output_buffer_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = ev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_event_output_direct
int snd_seq_event_output_direct(snd_seq_t * handle, snd_seq_event_t * ev) {
    snd_seq_event_output_direct_INDEXED *packed_data = malloc(sizeof(snd_seq_event_output_direct_INDEXED));
    packed_data->func = snd_seq_event_output_direct_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = ev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_event_output_pending
int snd_seq_event_output_pending(snd_seq_t * seq) {
    snd_seq_event_output_pending_INDEXED *packed_data = malloc(sizeof(snd_seq_event_output_pending_INDEXED));
    packed_data->func = snd_seq_event_output_pending_INDEX;
    packed_data->args.a1 = seq;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_extract_output
int snd_seq_extract_output(snd_seq_t * handle, snd_seq_event_t ** ev) {
    snd_seq_extract_output_INDEXED *packed_data = malloc(sizeof(snd_seq_extract_output_INDEXED));
    packed_data->func = snd_seq_extract_output_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = ev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_free_event
int snd_seq_free_event(snd_seq_event_t * ev) {
    snd_seq_free_event_INDEXED *packed_data = malloc(sizeof(snd_seq_free_event_INDEXED));
    packed_data->func = snd_seq_free_event_INDEX;
    packed_data->args.a1 = ev;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_free_queue
int snd_seq_free_queue(snd_seq_t * handle, int q) {
    snd_seq_free_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_free_queue_INDEXED));
    packed_data->func = snd_seq_free_queue_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_any_client_info
int snd_seq_get_any_client_info(snd_seq_t * handle, int client, snd_seq_client_info_t * info) {
    snd_seq_get_any_client_info_INDEXED *packed_data = malloc(sizeof(snd_seq_get_any_client_info_INDEXED));
    packed_data->func = snd_seq_get_any_client_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = client;
    packed_data->args.a3 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_any_port_info
int snd_seq_get_any_port_info(snd_seq_t * handle, int client, int port, snd_seq_port_info_t * info) {
    snd_seq_get_any_port_info_INDEXED *packed_data = malloc(sizeof(snd_seq_get_any_port_info_INDEXED));
    packed_data->func = snd_seq_get_any_port_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = client;
    packed_data->args.a3 = port;
    packed_data->args.a4 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_bit
int snd_seq_get_bit(int nr, void * array) {
    snd_seq_get_bit_INDEXED *packed_data = malloc(sizeof(snd_seq_get_bit_INDEXED));
    packed_data->func = snd_seq_get_bit_INDEX;
    packed_data->args.a1 = nr;
    packed_data->args.a2 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_client_info
int snd_seq_get_client_info(snd_seq_t * handle, snd_seq_client_info_t * info) {
    snd_seq_get_client_info_INDEXED *packed_data = malloc(sizeof(snd_seq_get_client_info_INDEXED));
    packed_data->func = snd_seq_get_client_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_client_pool
int snd_seq_get_client_pool(snd_seq_t * handle, snd_seq_client_pool_t * info) {
    snd_seq_get_client_pool_INDEXED *packed_data = malloc(sizeof(snd_seq_get_client_pool_INDEXED));
    packed_data->func = snd_seq_get_client_pool_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_input_buffer_size
size_t snd_seq_get_input_buffer_size(snd_seq_t * handle) {
    snd_seq_get_input_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_seq_get_input_buffer_size_INDEXED));
    packed_data->func = snd_seq_get_input_buffer_size_INDEX;
    packed_data->args.a1 = handle;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_output_buffer_size
size_t snd_seq_get_output_buffer_size(snd_seq_t * handle) {
    snd_seq_get_output_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_seq_get_output_buffer_size_INDEXED));
    packed_data->func = snd_seq_get_output_buffer_size_INDEX;
    packed_data->args.a1 = handle;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_port_info
int snd_seq_get_port_info(snd_seq_t * handle, int port, snd_seq_port_info_t * info) {
    snd_seq_get_port_info_INDEXED *packed_data = malloc(sizeof(snd_seq_get_port_info_INDEXED));
    packed_data->func = snd_seq_get_port_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = port;
    packed_data->args.a3 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_port_subscription
int snd_seq_get_port_subscription(snd_seq_t * handle, snd_seq_port_subscribe_t * sub) {
    snd_seq_get_port_subscription_INDEXED *packed_data = malloc(sizeof(snd_seq_get_port_subscription_INDEXED));
    packed_data->func = snd_seq_get_port_subscription_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = sub;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_queue_info
int snd_seq_get_queue_info(snd_seq_t * seq, int q, snd_seq_queue_info_t * info) {
    snd_seq_get_queue_info_INDEXED *packed_data = malloc(sizeof(snd_seq_get_queue_info_INDEXED));
    packed_data->func = snd_seq_get_queue_info_INDEX;
    packed_data->args.a1 = seq;
    packed_data->args.a2 = q;
    packed_data->args.a3 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_queue_status
int snd_seq_get_queue_status(snd_seq_t * handle, int q, snd_seq_queue_status_t * status) {
    snd_seq_get_queue_status_INDEXED *packed_data = malloc(sizeof(snd_seq_get_queue_status_INDEXED));
    packed_data->func = snd_seq_get_queue_status_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = q;
    packed_data->args.a3 = status;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_queue_tempo
int snd_seq_get_queue_tempo(snd_seq_t * handle, int q, snd_seq_queue_tempo_t * tempo) {
    snd_seq_get_queue_tempo_INDEXED *packed_data = malloc(sizeof(snd_seq_get_queue_tempo_INDEXED));
    packed_data->func = snd_seq_get_queue_tempo_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = q;
    packed_data->args.a3 = tempo;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_queue_timer
int snd_seq_get_queue_timer(snd_seq_t * handle, int q, snd_seq_queue_timer_t * timer) {
    snd_seq_get_queue_timer_INDEXED *packed_data = malloc(sizeof(snd_seq_get_queue_timer_INDEXED));
    packed_data->func = snd_seq_get_queue_timer_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = q;
    packed_data->args.a3 = timer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_get_queue_usage
int snd_seq_get_queue_usage(snd_seq_t * handle, int q) {
    snd_seq_get_queue_usage_INDEXED *packed_data = malloc(sizeof(snd_seq_get_queue_usage_INDEXED));
    packed_data->func = snd_seq_get_queue_usage_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_name
const char * snd_seq_name(snd_seq_t * seq) {
    snd_seq_name_INDEXED *packed_data = malloc(sizeof(snd_seq_name_INDEXED));
    packed_data->func = snd_seq_name_INDEX;
    packed_data->args.a1 = seq;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_nonblock
int snd_seq_nonblock(snd_seq_t * handle, int nonblock) {
    snd_seq_nonblock_INDEXED *packed_data = malloc(sizeof(snd_seq_nonblock_INDEXED));
    packed_data->func = snd_seq_nonblock_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = nonblock;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_open
int snd_seq_open(snd_seq_t ** handle, const char * name, int streams, int mode) {
    snd_seq_open_INDEXED *packed_data = malloc(sizeof(snd_seq_open_INDEXED));
    packed_data->func = snd_seq_open_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = name;
    packed_data->args.a3 = streams;
    packed_data->args.a4 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_open_lconf
int snd_seq_open_lconf(snd_seq_t ** handle, const char * name, int streams, int mode, snd_config_t * lconf) {
    snd_seq_open_lconf_INDEXED *packed_data = malloc(sizeof(snd_seq_open_lconf_INDEXED));
    packed_data->func = snd_seq_open_lconf_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = name;
    packed_data->args.a3 = streams;
    packed_data->args.a4 = mode;
    packed_data->args.a5 = lconf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_poll_descriptors
int snd_seq_poll_descriptors(snd_seq_t * handle, struct pollfd * pfds, unsigned int space, short events) {
    snd_seq_poll_descriptors_INDEXED *packed_data = malloc(sizeof(snd_seq_poll_descriptors_INDEXED));
    packed_data->func = snd_seq_poll_descriptors_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = space;
    packed_data->args.a4 = events;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_poll_descriptors_count
int snd_seq_poll_descriptors_count(snd_seq_t * handle, short events) {
    snd_seq_poll_descriptors_count_INDEXED *packed_data = malloc(sizeof(snd_seq_poll_descriptors_count_INDEXED));
    packed_data->func = snd_seq_poll_descriptors_count_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = events;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_poll_descriptors_revents
int snd_seq_poll_descriptors_revents(snd_seq_t * seq, struct pollfd * pfds, unsigned int nfds, unsigned short * revents) {
    snd_seq_poll_descriptors_revents_INDEXED *packed_data = malloc(sizeof(snd_seq_poll_descriptors_revents_INDEXED));
    packed_data->func = snd_seq_poll_descriptors_revents_INDEX;
    packed_data->args.a1 = seq;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = nfds;
    packed_data->args.a4 = revents;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_copy
void snd_seq_port_info_copy(snd_seq_port_info_t * dst, const snd_seq_port_info_t * src) {
    snd_seq_port_info_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_copy_INDEXED));
    packed_data->func = snd_seq_port_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_free
void snd_seq_port_info_free(snd_seq_port_info_t * ptr) {
    snd_seq_port_info_free_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_free_INDEXED));
    packed_data->func = snd_seq_port_info_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_get_addr
const snd_seq_addr_t * snd_seq_port_info_get_addr(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_addr_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_addr_INDEXED));
    packed_data->func = snd_seq_port_info_get_addr_INDEX;
    packed_data->args.a1 = info;
    const snd_seq_addr_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_capability
unsigned int snd_seq_port_info_get_capability(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_capability_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_capability_INDEXED));
    packed_data->func = snd_seq_port_info_get_capability_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_client
int snd_seq_port_info_get_client(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_client_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_client_INDEXED));
    packed_data->func = snd_seq_port_info_get_client_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_midi_channels
int snd_seq_port_info_get_midi_channels(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_midi_channels_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_midi_channels_INDEXED));
    packed_data->func = snd_seq_port_info_get_midi_channels_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_midi_voices
int snd_seq_port_info_get_midi_voices(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_midi_voices_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_midi_voices_INDEXED));
    packed_data->func = snd_seq_port_info_get_midi_voices_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_name
const char * snd_seq_port_info_get_name(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_name_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_name_INDEXED));
    packed_data->func = snd_seq_port_info_get_name_INDEX;
    packed_data->args.a1 = info;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_port
int snd_seq_port_info_get_port(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_port_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_port_INDEXED));
    packed_data->func = snd_seq_port_info_get_port_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_port_specified
int snd_seq_port_info_get_port_specified(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_port_specified_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_port_specified_INDEXED));
    packed_data->func = snd_seq_port_info_get_port_specified_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_read_use
int snd_seq_port_info_get_read_use(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_read_use_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_read_use_INDEXED));
    packed_data->func = snd_seq_port_info_get_read_use_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_synth_voices
int snd_seq_port_info_get_synth_voices(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_synth_voices_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_synth_voices_INDEXED));
    packed_data->func = snd_seq_port_info_get_synth_voices_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_timestamp_queue
int snd_seq_port_info_get_timestamp_queue(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_timestamp_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_timestamp_queue_INDEXED));
    packed_data->func = snd_seq_port_info_get_timestamp_queue_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_timestamp_real
int snd_seq_port_info_get_timestamp_real(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_timestamp_real_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_timestamp_real_INDEXED));
    packed_data->func = snd_seq_port_info_get_timestamp_real_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_timestamping
int snd_seq_port_info_get_timestamping(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_timestamping_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_timestamping_INDEXED));
    packed_data->func = snd_seq_port_info_get_timestamping_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_type
unsigned int snd_seq_port_info_get_type(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_type_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_type_INDEXED));
    packed_data->func = snd_seq_port_info_get_type_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_get_write_use
int snd_seq_port_info_get_write_use(const snd_seq_port_info_t * info) {
    snd_seq_port_info_get_write_use_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_get_write_use_INDEXED));
    packed_data->func = snd_seq_port_info_get_write_use_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_malloc
int snd_seq_port_info_malloc(snd_seq_port_info_t ** ptr) {
    snd_seq_port_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_malloc_INDEXED));
    packed_data->func = snd_seq_port_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_info_set_addr
void snd_seq_port_info_set_addr(snd_seq_port_info_t * info, const snd_seq_addr_t * addr) {
    snd_seq_port_info_set_addr_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_addr_INDEXED));
    packed_data->func = snd_seq_port_info_set_addr_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = addr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_capability
void snd_seq_port_info_set_capability(snd_seq_port_info_t * info, unsigned int capability) {
    snd_seq_port_info_set_capability_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_capability_INDEXED));
    packed_data->func = snd_seq_port_info_set_capability_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = capability;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_client
void snd_seq_port_info_set_client(snd_seq_port_info_t * info, int client) {
    snd_seq_port_info_set_client_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_client_INDEXED));
    packed_data->func = snd_seq_port_info_set_client_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = client;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_midi_channels
void snd_seq_port_info_set_midi_channels(snd_seq_port_info_t * info, int channels) {
    snd_seq_port_info_set_midi_channels_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_midi_channels_INDEXED));
    packed_data->func = snd_seq_port_info_set_midi_channels_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = channels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_midi_voices
void snd_seq_port_info_set_midi_voices(snd_seq_port_info_t * info, int voices) {
    snd_seq_port_info_set_midi_voices_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_midi_voices_INDEXED));
    packed_data->func = snd_seq_port_info_set_midi_voices_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = voices;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_name
void snd_seq_port_info_set_name(snd_seq_port_info_t * info, const char * name) {
    snd_seq_port_info_set_name_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_name_INDEXED));
    packed_data->func = snd_seq_port_info_set_name_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_port
void snd_seq_port_info_set_port(snd_seq_port_info_t * info, int port) {
    snd_seq_port_info_set_port_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_port_INDEXED));
    packed_data->func = snd_seq_port_info_set_port_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = port;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_port_specified
void snd_seq_port_info_set_port_specified(snd_seq_port_info_t * info, int val) {
    snd_seq_port_info_set_port_specified_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_port_specified_INDEXED));
    packed_data->func = snd_seq_port_info_set_port_specified_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_synth_voices
void snd_seq_port_info_set_synth_voices(snd_seq_port_info_t * info, int voices) {
    snd_seq_port_info_set_synth_voices_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_synth_voices_INDEXED));
    packed_data->func = snd_seq_port_info_set_synth_voices_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = voices;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_timestamp_queue
void snd_seq_port_info_set_timestamp_queue(snd_seq_port_info_t * info, int queue) {
    snd_seq_port_info_set_timestamp_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_timestamp_queue_INDEXED));
    packed_data->func = snd_seq_port_info_set_timestamp_queue_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = queue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_timestamp_real
void snd_seq_port_info_set_timestamp_real(snd_seq_port_info_t * info, int realtime) {
    snd_seq_port_info_set_timestamp_real_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_timestamp_real_INDEXED));
    packed_data->func = snd_seq_port_info_set_timestamp_real_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = realtime;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_timestamping
void snd_seq_port_info_set_timestamping(snd_seq_port_info_t * info, int enable) {
    snd_seq_port_info_set_timestamping_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_timestamping_INDEXED));
    packed_data->func = snd_seq_port_info_set_timestamping_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = enable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_set_type
void snd_seq_port_info_set_type(snd_seq_port_info_t * info, unsigned int type) {
    snd_seq_port_info_set_type_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_set_type_INDEXED));
    packed_data->func = snd_seq_port_info_set_type_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_info_sizeof
size_t snd_seq_port_info_sizeof() {
    snd_seq_port_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_port_info_sizeof_INDEXED));
    packed_data->func = snd_seq_port_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_copy
void snd_seq_port_subscribe_copy(snd_seq_port_subscribe_t * dst, const snd_seq_port_subscribe_t * src) {
    snd_seq_port_subscribe_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_copy_INDEXED));
    packed_data->func = snd_seq_port_subscribe_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_free
void snd_seq_port_subscribe_free(snd_seq_port_subscribe_t * ptr) {
    snd_seq_port_subscribe_free_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_free_INDEXED));
    packed_data->func = snd_seq_port_subscribe_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_get_dest
const snd_seq_addr_t * snd_seq_port_subscribe_get_dest(const snd_seq_port_subscribe_t * info) {
    snd_seq_port_subscribe_get_dest_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_get_dest_INDEXED));
    packed_data->func = snd_seq_port_subscribe_get_dest_INDEX;
    packed_data->args.a1 = info;
    const snd_seq_addr_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_get_exclusive
int snd_seq_port_subscribe_get_exclusive(const snd_seq_port_subscribe_t * info) {
    snd_seq_port_subscribe_get_exclusive_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_get_exclusive_INDEXED));
    packed_data->func = snd_seq_port_subscribe_get_exclusive_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_get_queue
int snd_seq_port_subscribe_get_queue(const snd_seq_port_subscribe_t * info) {
    snd_seq_port_subscribe_get_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_get_queue_INDEXED));
    packed_data->func = snd_seq_port_subscribe_get_queue_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_get_sender
const snd_seq_addr_t * snd_seq_port_subscribe_get_sender(const snd_seq_port_subscribe_t * info) {
    snd_seq_port_subscribe_get_sender_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_get_sender_INDEXED));
    packed_data->func = snd_seq_port_subscribe_get_sender_INDEX;
    packed_data->args.a1 = info;
    const snd_seq_addr_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_get_time_real
int snd_seq_port_subscribe_get_time_real(const snd_seq_port_subscribe_t * info) {
    snd_seq_port_subscribe_get_time_real_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_get_time_real_INDEXED));
    packed_data->func = snd_seq_port_subscribe_get_time_real_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_get_time_update
int snd_seq_port_subscribe_get_time_update(const snd_seq_port_subscribe_t * info) {
    snd_seq_port_subscribe_get_time_update_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_get_time_update_INDEXED));
    packed_data->func = snd_seq_port_subscribe_get_time_update_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_malloc
int snd_seq_port_subscribe_malloc(snd_seq_port_subscribe_t ** ptr) {
    snd_seq_port_subscribe_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_malloc_INDEXED));
    packed_data->func = snd_seq_port_subscribe_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_set_dest
void snd_seq_port_subscribe_set_dest(snd_seq_port_subscribe_t * info, const snd_seq_addr_t * addr) {
    snd_seq_port_subscribe_set_dest_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_set_dest_INDEXED));
    packed_data->func = snd_seq_port_subscribe_set_dest_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = addr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_set_exclusive
void snd_seq_port_subscribe_set_exclusive(snd_seq_port_subscribe_t * info, int val) {
    snd_seq_port_subscribe_set_exclusive_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_set_exclusive_INDEXED));
    packed_data->func = snd_seq_port_subscribe_set_exclusive_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_set_queue
void snd_seq_port_subscribe_set_queue(snd_seq_port_subscribe_t * info, int q) {
    snd_seq_port_subscribe_set_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_set_queue_INDEXED));
    packed_data->func = snd_seq_port_subscribe_set_queue_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_set_sender
void snd_seq_port_subscribe_set_sender(snd_seq_port_subscribe_t * info, const snd_seq_addr_t * addr) {
    snd_seq_port_subscribe_set_sender_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_set_sender_INDEXED));
    packed_data->func = snd_seq_port_subscribe_set_sender_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = addr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_set_time_real
void snd_seq_port_subscribe_set_time_real(snd_seq_port_subscribe_t * info, int val) {
    snd_seq_port_subscribe_set_time_real_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_set_time_real_INDEXED));
    packed_data->func = snd_seq_port_subscribe_set_time_real_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_set_time_update
void snd_seq_port_subscribe_set_time_update(snd_seq_port_subscribe_t * info, int val) {
    snd_seq_port_subscribe_set_time_update_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_set_time_update_INDEXED));
    packed_data->func = snd_seq_port_subscribe_set_time_update_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = val;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_port_subscribe_sizeof
size_t snd_seq_port_subscribe_sizeof() {
    snd_seq_port_subscribe_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_port_subscribe_sizeof_INDEXED));
    packed_data->func = snd_seq_port_subscribe_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_named_queue
int snd_seq_query_named_queue(snd_seq_t * seq, const char * name) {
    snd_seq_query_named_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_query_named_queue_INDEXED));
    packed_data->func = snd_seq_query_named_queue_INDEX;
    packed_data->args.a1 = seq;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_next_client
int snd_seq_query_next_client(snd_seq_t * handle, snd_seq_client_info_t * info) {
    snd_seq_query_next_client_INDEXED *packed_data = malloc(sizeof(snd_seq_query_next_client_INDEXED));
    packed_data->func = snd_seq_query_next_client_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_next_port
int snd_seq_query_next_port(snd_seq_t * handle, snd_seq_port_info_t * info) {
    snd_seq_query_next_port_INDEXED *packed_data = malloc(sizeof(snd_seq_query_next_port_INDEXED));
    packed_data->func = snd_seq_query_next_port_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_port_subscribers
int snd_seq_query_port_subscribers(snd_seq_t * seq, snd_seq_query_subscribe_t * subs) {
    snd_seq_query_port_subscribers_INDEXED *packed_data = malloc(sizeof(snd_seq_query_port_subscribers_INDEXED));
    packed_data->func = snd_seq_query_port_subscribers_INDEX;
    packed_data->args.a1 = seq;
    packed_data->args.a2 = subs;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_copy
void snd_seq_query_subscribe_copy(snd_seq_query_subscribe_t * dst, const snd_seq_query_subscribe_t * src) {
    snd_seq_query_subscribe_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_copy_INDEXED));
    packed_data->func = snd_seq_query_subscribe_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_free
void snd_seq_query_subscribe_free(snd_seq_query_subscribe_t * ptr) {
    snd_seq_query_subscribe_free_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_free_INDEXED));
    packed_data->func = snd_seq_query_subscribe_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_addr
const snd_seq_addr_t * snd_seq_query_subscribe_get_addr(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_addr_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_addr_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_addr_INDEX;
    packed_data->args.a1 = info;
    const snd_seq_addr_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_client
int snd_seq_query_subscribe_get_client(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_client_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_client_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_client_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_exclusive
int snd_seq_query_subscribe_get_exclusive(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_exclusive_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_exclusive_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_exclusive_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_index
int snd_seq_query_subscribe_get_index(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_index_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_index_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_index_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_num_subs
int snd_seq_query_subscribe_get_num_subs(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_num_subs_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_num_subs_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_num_subs_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_port
int snd_seq_query_subscribe_get_port(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_port_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_port_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_port_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_queue
int snd_seq_query_subscribe_get_queue(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_queue_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_queue_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_root
const snd_seq_addr_t * snd_seq_query_subscribe_get_root(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_root_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_root_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_root_INDEX;
    packed_data->args.a1 = info;
    const snd_seq_addr_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_time_real
int snd_seq_query_subscribe_get_time_real(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_time_real_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_time_real_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_time_real_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_time_update
int snd_seq_query_subscribe_get_time_update(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_time_update_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_time_update_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_time_update_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_get_type
snd_seq_query_subs_type_t snd_seq_query_subscribe_get_type(const snd_seq_query_subscribe_t * info) {
    snd_seq_query_subscribe_get_type_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_get_type_INDEXED));
    packed_data->func = snd_seq_query_subscribe_get_type_INDEX;
    packed_data->args.a1 = info;
    snd_seq_query_subs_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_malloc
int snd_seq_query_subscribe_malloc(snd_seq_query_subscribe_t ** ptr) {
    snd_seq_query_subscribe_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_malloc_INDEXED));
    packed_data->func = snd_seq_query_subscribe_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_set_client
void snd_seq_query_subscribe_set_client(snd_seq_query_subscribe_t * info, int client) {
    snd_seq_query_subscribe_set_client_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_set_client_INDEXED));
    packed_data->func = snd_seq_query_subscribe_set_client_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = client;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_set_index
void snd_seq_query_subscribe_set_index(snd_seq_query_subscribe_t * info, int _index) {
    snd_seq_query_subscribe_set_index_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_set_index_INDEXED));
    packed_data->func = snd_seq_query_subscribe_set_index_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = _index;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_set_port
void snd_seq_query_subscribe_set_port(snd_seq_query_subscribe_t * info, int port) {
    snd_seq_query_subscribe_set_port_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_set_port_INDEXED));
    packed_data->func = snd_seq_query_subscribe_set_port_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = port;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_set_root
void snd_seq_query_subscribe_set_root(snd_seq_query_subscribe_t * info, const snd_seq_addr_t * addr) {
    snd_seq_query_subscribe_set_root_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_set_root_INDEXED));
    packed_data->func = snd_seq_query_subscribe_set_root_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = addr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_set_type
void snd_seq_query_subscribe_set_type(snd_seq_query_subscribe_t * info, snd_seq_query_subs_type_t type) {
    snd_seq_query_subscribe_set_type_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_set_type_INDEXED));
    packed_data->func = snd_seq_query_subscribe_set_type_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_query_subscribe_sizeof
size_t snd_seq_query_subscribe_sizeof() {
    snd_seq_query_subscribe_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_query_subscribe_sizeof_INDEXED));
    packed_data->func = snd_seq_query_subscribe_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_info_copy
void snd_seq_queue_info_copy(snd_seq_queue_info_t * dst, const snd_seq_queue_info_t * src) {
    snd_seq_queue_info_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_copy_INDEXED));
    packed_data->func = snd_seq_queue_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_info_free
void snd_seq_queue_info_free(snd_seq_queue_info_t * ptr) {
    snd_seq_queue_info_free_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_free_INDEXED));
    packed_data->func = snd_seq_queue_info_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_info_get_flags
unsigned int snd_seq_queue_info_get_flags(const snd_seq_queue_info_t * info) {
    snd_seq_queue_info_get_flags_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_get_flags_INDEXED));
    packed_data->func = snd_seq_queue_info_get_flags_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_info_get_locked
int snd_seq_queue_info_get_locked(const snd_seq_queue_info_t * info) {
    snd_seq_queue_info_get_locked_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_get_locked_INDEXED));
    packed_data->func = snd_seq_queue_info_get_locked_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_info_get_name
const char * snd_seq_queue_info_get_name(const snd_seq_queue_info_t * info) {
    snd_seq_queue_info_get_name_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_get_name_INDEXED));
    packed_data->func = snd_seq_queue_info_get_name_INDEX;
    packed_data->args.a1 = info;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_info_get_owner
int snd_seq_queue_info_get_owner(const snd_seq_queue_info_t * info) {
    snd_seq_queue_info_get_owner_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_get_owner_INDEXED));
    packed_data->func = snd_seq_queue_info_get_owner_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_info_get_queue
int snd_seq_queue_info_get_queue(const snd_seq_queue_info_t * info) {
    snd_seq_queue_info_get_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_get_queue_INDEXED));
    packed_data->func = snd_seq_queue_info_get_queue_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_info_malloc
int snd_seq_queue_info_malloc(snd_seq_queue_info_t ** ptr) {
    snd_seq_queue_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_malloc_INDEXED));
    packed_data->func = snd_seq_queue_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_info_set_flags
void snd_seq_queue_info_set_flags(snd_seq_queue_info_t * info, unsigned int flags) {
    snd_seq_queue_info_set_flags_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_set_flags_INDEXED));
    packed_data->func = snd_seq_queue_info_set_flags_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = flags;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_info_set_locked
void snd_seq_queue_info_set_locked(snd_seq_queue_info_t * info, int locked) {
    snd_seq_queue_info_set_locked_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_set_locked_INDEXED));
    packed_data->func = snd_seq_queue_info_set_locked_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = locked;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_info_set_name
void snd_seq_queue_info_set_name(snd_seq_queue_info_t * info, const char * name) {
    snd_seq_queue_info_set_name_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_set_name_INDEXED));
    packed_data->func = snd_seq_queue_info_set_name_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_info_set_owner
void snd_seq_queue_info_set_owner(snd_seq_queue_info_t * info, int owner) {
    snd_seq_queue_info_set_owner_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_set_owner_INDEXED));
    packed_data->func = snd_seq_queue_info_set_owner_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = owner;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_info_sizeof
size_t snd_seq_queue_info_sizeof() {
    snd_seq_queue_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_info_sizeof_INDEXED));
    packed_data->func = snd_seq_queue_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_status_copy
void snd_seq_queue_status_copy(snd_seq_queue_status_t * dst, const snd_seq_queue_status_t * src) {
    snd_seq_queue_status_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_copy_INDEXED));
    packed_data->func = snd_seq_queue_status_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_status_free
void snd_seq_queue_status_free(snd_seq_queue_status_t * ptr) {
    snd_seq_queue_status_free_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_free_INDEXED));
    packed_data->func = snd_seq_queue_status_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_status_get_events
int snd_seq_queue_status_get_events(const snd_seq_queue_status_t * info) {
    snd_seq_queue_status_get_events_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_get_events_INDEXED));
    packed_data->func = snd_seq_queue_status_get_events_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_status_get_queue
int snd_seq_queue_status_get_queue(const snd_seq_queue_status_t * info) {
    snd_seq_queue_status_get_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_get_queue_INDEXED));
    packed_data->func = snd_seq_queue_status_get_queue_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_status_get_real_time
const snd_seq_real_time_t * snd_seq_queue_status_get_real_time(const snd_seq_queue_status_t * info) {
    snd_seq_queue_status_get_real_time_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_get_real_time_INDEXED));
    packed_data->func = snd_seq_queue_status_get_real_time_INDEX;
    packed_data->args.a1 = info;
    const snd_seq_real_time_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_status_get_status
unsigned int snd_seq_queue_status_get_status(const snd_seq_queue_status_t * info) {
    snd_seq_queue_status_get_status_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_get_status_INDEXED));
    packed_data->func = snd_seq_queue_status_get_status_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_status_get_tick_time
snd_seq_tick_time_t snd_seq_queue_status_get_tick_time(const snd_seq_queue_status_t * info) {
    snd_seq_queue_status_get_tick_time_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_get_tick_time_INDEXED));
    packed_data->func = snd_seq_queue_status_get_tick_time_INDEX;
    packed_data->args.a1 = info;
    snd_seq_tick_time_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_status_malloc
int snd_seq_queue_status_malloc(snd_seq_queue_status_t ** ptr) {
    snd_seq_queue_status_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_malloc_INDEXED));
    packed_data->func = snd_seq_queue_status_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_status_sizeof
size_t snd_seq_queue_status_sizeof() {
    snd_seq_queue_status_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_status_sizeof_INDEXED));
    packed_data->func = snd_seq_queue_status_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_copy
void snd_seq_queue_tempo_copy(snd_seq_queue_tempo_t * dst, const snd_seq_queue_tempo_t * src) {
    snd_seq_queue_tempo_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_copy_INDEXED));
    packed_data->func = snd_seq_queue_tempo_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_free
void snd_seq_queue_tempo_free(snd_seq_queue_tempo_t * ptr) {
    snd_seq_queue_tempo_free_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_free_INDEXED));
    packed_data->func = snd_seq_queue_tempo_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_get_ppq
int snd_seq_queue_tempo_get_ppq(const snd_seq_queue_tempo_t * info) {
    snd_seq_queue_tempo_get_ppq_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_get_ppq_INDEXED));
    packed_data->func = snd_seq_queue_tempo_get_ppq_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_get_queue
int snd_seq_queue_tempo_get_queue(const snd_seq_queue_tempo_t * info) {
    snd_seq_queue_tempo_get_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_get_queue_INDEXED));
    packed_data->func = snd_seq_queue_tempo_get_queue_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_get_skew
unsigned int snd_seq_queue_tempo_get_skew(const snd_seq_queue_tempo_t * info) {
    snd_seq_queue_tempo_get_skew_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_get_skew_INDEXED));
    packed_data->func = snd_seq_queue_tempo_get_skew_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_get_skew_base
unsigned int snd_seq_queue_tempo_get_skew_base(const snd_seq_queue_tempo_t * info) {
    snd_seq_queue_tempo_get_skew_base_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_get_skew_base_INDEXED));
    packed_data->func = snd_seq_queue_tempo_get_skew_base_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_get_tempo
unsigned int snd_seq_queue_tempo_get_tempo(const snd_seq_queue_tempo_t * info) {
    snd_seq_queue_tempo_get_tempo_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_get_tempo_INDEXED));
    packed_data->func = snd_seq_queue_tempo_get_tempo_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_malloc
int snd_seq_queue_tempo_malloc(snd_seq_queue_tempo_t ** ptr) {
    snd_seq_queue_tempo_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_malloc_INDEXED));
    packed_data->func = snd_seq_queue_tempo_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_set_ppq
void snd_seq_queue_tempo_set_ppq(snd_seq_queue_tempo_t * info, int ppq) {
    snd_seq_queue_tempo_set_ppq_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_set_ppq_INDEXED));
    packed_data->func = snd_seq_queue_tempo_set_ppq_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = ppq;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_set_skew
void snd_seq_queue_tempo_set_skew(snd_seq_queue_tempo_t * info, unsigned int skew) {
    snd_seq_queue_tempo_set_skew_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_set_skew_INDEXED));
    packed_data->func = snd_seq_queue_tempo_set_skew_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = skew;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_set_skew_base
void snd_seq_queue_tempo_set_skew_base(snd_seq_queue_tempo_t * info, unsigned int base) {
    snd_seq_queue_tempo_set_skew_base_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_set_skew_base_INDEXED));
    packed_data->func = snd_seq_queue_tempo_set_skew_base_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = base;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_set_tempo
void snd_seq_queue_tempo_set_tempo(snd_seq_queue_tempo_t * info, unsigned int tempo) {
    snd_seq_queue_tempo_set_tempo_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_set_tempo_INDEXED));
    packed_data->func = snd_seq_queue_tempo_set_tempo_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = tempo;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_tempo_sizeof
size_t snd_seq_queue_tempo_sizeof() {
    snd_seq_queue_tempo_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_tempo_sizeof_INDEXED));
    packed_data->func = snd_seq_queue_tempo_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_timer_copy
void snd_seq_queue_timer_copy(snd_seq_queue_timer_t * dst, const snd_seq_queue_timer_t * src) {
    snd_seq_queue_timer_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_copy_INDEXED));
    packed_data->func = snd_seq_queue_timer_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_timer_free
void snd_seq_queue_timer_free(snd_seq_queue_timer_t * ptr) {
    snd_seq_queue_timer_free_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_free_INDEXED));
    packed_data->func = snd_seq_queue_timer_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_timer_get_id
const snd_timer_id_t * snd_seq_queue_timer_get_id(const snd_seq_queue_timer_t * info) {
    snd_seq_queue_timer_get_id_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_get_id_INDEXED));
    packed_data->func = snd_seq_queue_timer_get_id_INDEX;
    packed_data->args.a1 = info;
    const snd_timer_id_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_timer_get_queue
int snd_seq_queue_timer_get_queue(const snd_seq_queue_timer_t * info) {
    snd_seq_queue_timer_get_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_get_queue_INDEXED));
    packed_data->func = snd_seq_queue_timer_get_queue_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_timer_get_resolution
unsigned int snd_seq_queue_timer_get_resolution(const snd_seq_queue_timer_t * info) {
    snd_seq_queue_timer_get_resolution_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_get_resolution_INDEXED));
    packed_data->func = snd_seq_queue_timer_get_resolution_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_timer_get_type
snd_seq_queue_timer_type_t snd_seq_queue_timer_get_type(const snd_seq_queue_timer_t * info) {
    snd_seq_queue_timer_get_type_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_get_type_INDEXED));
    packed_data->func = snd_seq_queue_timer_get_type_INDEX;
    packed_data->args.a1 = info;
    snd_seq_queue_timer_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_timer_malloc
int snd_seq_queue_timer_malloc(snd_seq_queue_timer_t ** ptr) {
    snd_seq_queue_timer_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_malloc_INDEXED));
    packed_data->func = snd_seq_queue_timer_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_queue_timer_set_id
void snd_seq_queue_timer_set_id(snd_seq_queue_timer_t * info, const snd_timer_id_t * id) {
    snd_seq_queue_timer_set_id_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_set_id_INDEXED));
    packed_data->func = snd_seq_queue_timer_set_id_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_timer_set_resolution
void snd_seq_queue_timer_set_resolution(snd_seq_queue_timer_t * info, unsigned int resolution) {
    snd_seq_queue_timer_set_resolution_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_set_resolution_INDEXED));
    packed_data->func = snd_seq_queue_timer_set_resolution_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = resolution;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_timer_set_type
void snd_seq_queue_timer_set_type(snd_seq_queue_timer_t * info, snd_seq_queue_timer_type_t type) {
    snd_seq_queue_timer_set_type_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_set_type_INDEXED));
    packed_data->func = snd_seq_queue_timer_set_type_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_queue_timer_sizeof
size_t snd_seq_queue_timer_sizeof() {
    snd_seq_queue_timer_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_queue_timer_sizeof_INDEXED));
    packed_data->func = snd_seq_queue_timer_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events
int snd_seq_remove_events(snd_seq_t * handle, snd_seq_remove_events_t * info) {
    snd_seq_remove_events_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_INDEXED));
    packed_data->func = snd_seq_remove_events_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_copy
void snd_seq_remove_events_copy(snd_seq_remove_events_t * dst, const snd_seq_remove_events_t * src) {
    snd_seq_remove_events_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_copy_INDEXED));
    packed_data->func = snd_seq_remove_events_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_free
void snd_seq_remove_events_free(snd_seq_remove_events_t * ptr) {
    snd_seq_remove_events_free_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_free_INDEXED));
    packed_data->func = snd_seq_remove_events_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_get_channel
int snd_seq_remove_events_get_channel(const snd_seq_remove_events_t * info) {
    snd_seq_remove_events_get_channel_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_get_channel_INDEXED));
    packed_data->func = snd_seq_remove_events_get_channel_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_get_condition
unsigned int snd_seq_remove_events_get_condition(const snd_seq_remove_events_t * info) {
    snd_seq_remove_events_get_condition_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_get_condition_INDEXED));
    packed_data->func = snd_seq_remove_events_get_condition_INDEX;
    packed_data->args.a1 = info;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_get_dest
const snd_seq_addr_t * snd_seq_remove_events_get_dest(const snd_seq_remove_events_t * info) {
    snd_seq_remove_events_get_dest_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_get_dest_INDEXED));
    packed_data->func = snd_seq_remove_events_get_dest_INDEX;
    packed_data->args.a1 = info;
    const snd_seq_addr_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_get_event_type
int snd_seq_remove_events_get_event_type(const snd_seq_remove_events_t * info) {
    snd_seq_remove_events_get_event_type_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_get_event_type_INDEXED));
    packed_data->func = snd_seq_remove_events_get_event_type_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_get_queue
int snd_seq_remove_events_get_queue(const snd_seq_remove_events_t * info) {
    snd_seq_remove_events_get_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_get_queue_INDEXED));
    packed_data->func = snd_seq_remove_events_get_queue_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_get_tag
int snd_seq_remove_events_get_tag(const snd_seq_remove_events_t * info) {
    snd_seq_remove_events_get_tag_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_get_tag_INDEXED));
    packed_data->func = snd_seq_remove_events_get_tag_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_get_time
const snd_seq_timestamp_t * snd_seq_remove_events_get_time(const snd_seq_remove_events_t * info) {
    snd_seq_remove_events_get_time_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_get_time_INDEXED));
    packed_data->func = snd_seq_remove_events_get_time_INDEX;
    packed_data->args.a1 = info;
    const snd_seq_timestamp_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_malloc
int snd_seq_remove_events_malloc(snd_seq_remove_events_t ** ptr) {
    snd_seq_remove_events_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_malloc_INDEXED));
    packed_data->func = snd_seq_remove_events_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_remove_events_set_channel
void snd_seq_remove_events_set_channel(snd_seq_remove_events_t * info, int channel) {
    snd_seq_remove_events_set_channel_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_set_channel_INDEXED));
    packed_data->func = snd_seq_remove_events_set_channel_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = channel;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_set_condition
void snd_seq_remove_events_set_condition(snd_seq_remove_events_t * info, unsigned int flags) {
    snd_seq_remove_events_set_condition_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_set_condition_INDEXED));
    packed_data->func = snd_seq_remove_events_set_condition_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = flags;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_set_dest
void snd_seq_remove_events_set_dest(snd_seq_remove_events_t * info, const snd_seq_addr_t * addr) {
    snd_seq_remove_events_set_dest_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_set_dest_INDEXED));
    packed_data->func = snd_seq_remove_events_set_dest_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = addr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_set_event_type
void snd_seq_remove_events_set_event_type(snd_seq_remove_events_t * info, int type) {
    snd_seq_remove_events_set_event_type_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_set_event_type_INDEXED));
    packed_data->func = snd_seq_remove_events_set_event_type_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_set_queue
void snd_seq_remove_events_set_queue(snd_seq_remove_events_t * info, int queue) {
    snd_seq_remove_events_set_queue_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_set_queue_INDEXED));
    packed_data->func = snd_seq_remove_events_set_queue_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = queue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_set_tag
void snd_seq_remove_events_set_tag(snd_seq_remove_events_t * info, int tag) {
    snd_seq_remove_events_set_tag_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_set_tag_INDEXED));
    packed_data->func = snd_seq_remove_events_set_tag_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = tag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_set_time
void snd_seq_remove_events_set_time(snd_seq_remove_events_t * info, const snd_seq_timestamp_t * time) {
    snd_seq_remove_events_set_time_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_set_time_INDEXED));
    packed_data->func = snd_seq_remove_events_set_time_INDEX;
    packed_data->args.a1 = info;
    packed_data->args.a2 = time;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_remove_events_sizeof
size_t snd_seq_remove_events_sizeof() {
    snd_seq_remove_events_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_remove_events_sizeof_INDEXED));
    packed_data->func = snd_seq_remove_events_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_bit
void snd_seq_set_bit(int nr, void * array) {
    snd_seq_set_bit_INDEXED *packed_data = malloc(sizeof(snd_seq_set_bit_INDEXED));
    packed_data->func = snd_seq_set_bit_INDEX;
    packed_data->args.a1 = nr;
    packed_data->args.a2 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_set_client_info
int snd_seq_set_client_info(snd_seq_t * handle, snd_seq_client_info_t * info) {
    snd_seq_set_client_info_INDEXED *packed_data = malloc(sizeof(snd_seq_set_client_info_INDEXED));
    packed_data->func = snd_seq_set_client_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_client_pool
int snd_seq_set_client_pool(snd_seq_t * handle, snd_seq_client_pool_t * info) {
    snd_seq_set_client_pool_INDEXED *packed_data = malloc(sizeof(snd_seq_set_client_pool_INDEXED));
    packed_data->func = snd_seq_set_client_pool_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_input_buffer_size
int snd_seq_set_input_buffer_size(snd_seq_t * handle, size_t size) {
    snd_seq_set_input_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_seq_set_input_buffer_size_INDEXED));
    packed_data->func = snd_seq_set_input_buffer_size_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_output_buffer_size
int snd_seq_set_output_buffer_size(snd_seq_t * handle, size_t size) {
    snd_seq_set_output_buffer_size_INDEXED *packed_data = malloc(sizeof(snd_seq_set_output_buffer_size_INDEXED));
    packed_data->func = snd_seq_set_output_buffer_size_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_port_info
int snd_seq_set_port_info(snd_seq_t * handle, int port, snd_seq_port_info_t * info) {
    snd_seq_set_port_info_INDEXED *packed_data = malloc(sizeof(snd_seq_set_port_info_INDEXED));
    packed_data->func = snd_seq_set_port_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = port;
    packed_data->args.a3 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_queue_info
int snd_seq_set_queue_info(snd_seq_t * seq, int q, snd_seq_queue_info_t * info) {
    snd_seq_set_queue_info_INDEXED *packed_data = malloc(sizeof(snd_seq_set_queue_info_INDEXED));
    packed_data->func = snd_seq_set_queue_info_INDEX;
    packed_data->args.a1 = seq;
    packed_data->args.a2 = q;
    packed_data->args.a3 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_queue_tempo
int snd_seq_set_queue_tempo(snd_seq_t * handle, int q, snd_seq_queue_tempo_t * tempo) {
    snd_seq_set_queue_tempo_INDEXED *packed_data = malloc(sizeof(snd_seq_set_queue_tempo_INDEXED));
    packed_data->func = snd_seq_set_queue_tempo_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = q;
    packed_data->args.a3 = tempo;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_queue_timer
int snd_seq_set_queue_timer(snd_seq_t * handle, int q, snd_seq_queue_timer_t * timer) {
    snd_seq_set_queue_timer_INDEXED *packed_data = malloc(sizeof(snd_seq_set_queue_timer_INDEXED));
    packed_data->func = snd_seq_set_queue_timer_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = q;
    packed_data->args.a3 = timer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_set_queue_usage
int snd_seq_set_queue_usage(snd_seq_t * handle, int q, int used) {
    snd_seq_set_queue_usage_INDEXED *packed_data = malloc(sizeof(snd_seq_set_queue_usage_INDEXED));
    packed_data->func = snd_seq_set_queue_usage_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = q;
    packed_data->args.a3 = used;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_subscribe_port
int snd_seq_subscribe_port(snd_seq_t * handle, snd_seq_port_subscribe_t * sub) {
    snd_seq_subscribe_port_INDEXED *packed_data = malloc(sizeof(snd_seq_subscribe_port_INDEXED));
    packed_data->func = snd_seq_subscribe_port_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = sub;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info
int snd_seq_system_info(snd_seq_t * handle, snd_seq_system_info_t * info) {
    snd_seq_system_info_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_INDEXED));
    packed_data->func = snd_seq_system_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info_copy
void snd_seq_system_info_copy(snd_seq_system_info_t * dst, const snd_seq_system_info_t * src) {
    snd_seq_system_info_copy_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_copy_INDEXED));
    packed_data->func = snd_seq_system_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_system_info_free
void snd_seq_system_info_free(snd_seq_system_info_t * ptr) {
    snd_seq_system_info_free_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_free_INDEXED));
    packed_data->func = snd_seq_system_info_free_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_seq_system_info_get_channels
int snd_seq_system_info_get_channels(const snd_seq_system_info_t * info) {
    snd_seq_system_info_get_channels_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_get_channels_INDEXED));
    packed_data->func = snd_seq_system_info_get_channels_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info_get_clients
int snd_seq_system_info_get_clients(const snd_seq_system_info_t * info) {
    snd_seq_system_info_get_clients_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_get_clients_INDEXED));
    packed_data->func = snd_seq_system_info_get_clients_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info_get_cur_clients
int snd_seq_system_info_get_cur_clients(const snd_seq_system_info_t * info) {
    snd_seq_system_info_get_cur_clients_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_get_cur_clients_INDEXED));
    packed_data->func = snd_seq_system_info_get_cur_clients_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info_get_cur_queues
int snd_seq_system_info_get_cur_queues(const snd_seq_system_info_t * info) {
    snd_seq_system_info_get_cur_queues_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_get_cur_queues_INDEXED));
    packed_data->func = snd_seq_system_info_get_cur_queues_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info_get_ports
int snd_seq_system_info_get_ports(const snd_seq_system_info_t * info) {
    snd_seq_system_info_get_ports_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_get_ports_INDEXED));
    packed_data->func = snd_seq_system_info_get_ports_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info_get_queues
int snd_seq_system_info_get_queues(const snd_seq_system_info_t * info) {
    snd_seq_system_info_get_queues_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_get_queues_INDEXED));
    packed_data->func = snd_seq_system_info_get_queues_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info_malloc
int snd_seq_system_info_malloc(snd_seq_system_info_t ** ptr) {
    snd_seq_system_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_malloc_INDEXED));
    packed_data->func = snd_seq_system_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_system_info_sizeof
size_t snd_seq_system_info_sizeof() {
    snd_seq_system_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_seq_system_info_sizeof_INDEXED));
    packed_data->func = snd_seq_system_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_type
snd_seq_type_t snd_seq_type(snd_seq_t * seq) {
    snd_seq_type_INDEXED *packed_data = malloc(sizeof(snd_seq_type_INDEXED));
    packed_data->func = snd_seq_type_INDEX;
    packed_data->args.a1 = seq;
    snd_seq_type_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_seq_unsubscribe_port
int snd_seq_unsubscribe_port(snd_seq_t * handle, snd_seq_port_subscribe_t * sub) {
    snd_seq_unsubscribe_port_INDEXED *packed_data = malloc(sizeof(snd_seq_unsubscribe_port_INDEXED));
    packed_data->func = snd_seq_unsubscribe_port_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = sub;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_shm_area_create
struct snd_shm_area * snd_shm_area_create(int shmid, void * ptr) {
    snd_shm_area_create_INDEXED *packed_data = malloc(sizeof(snd_shm_area_create_INDEXED));
    packed_data->func = snd_shm_area_create_INDEX;
    packed_data->args.a1 = shmid;
    packed_data->args.a2 = ptr;
    struct snd_shm_area * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_shm_area_destroy
int snd_shm_area_destroy(struct snd_shm_area * area) {
    snd_shm_area_destroy_INDEXED *packed_data = malloc(sizeof(snd_shm_area_destroy_INDEXED));
    packed_data->func = snd_shm_area_destroy_INDEX;
    packed_data->args.a1 = area;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_shm_area_share
struct snd_shm_area * snd_shm_area_share(struct snd_shm_area * area) {
    snd_shm_area_share_INDEXED *packed_data = malloc(sizeof(snd_shm_area_share_INDEXED));
    packed_data->func = snd_shm_area_share_INDEX;
    packed_data->args.a1 = area;
    struct snd_shm_area * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_spcm_init
int snd_spcm_init(snd_pcm_t * pcm, unsigned int rate, unsigned int channels, snd_pcm_format_t format, snd_pcm_subformat_t subformat, snd_spcm_latency_t latency, snd_pcm_access_t _access, snd_spcm_xrun_type_t xrun_type) {
    snd_spcm_init_INDEXED *packed_data = malloc(sizeof(snd_spcm_init_INDEXED));
    packed_data->func = snd_spcm_init_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = rate;
    packed_data->args.a3 = channels;
    packed_data->args.a4 = format;
    packed_data->args.a5 = subformat;
    packed_data->args.a6 = latency;
    packed_data->args.a7 = _access;
    packed_data->args.a8 = xrun_type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_spcm_init_duplex
int snd_spcm_init_duplex(snd_pcm_t * playback_pcm, snd_pcm_t * capture_pcm, unsigned int rate, unsigned int channels, snd_pcm_format_t format, snd_pcm_subformat_t subformat, snd_spcm_latency_t latency, snd_pcm_access_t _access, snd_spcm_xrun_type_t xrun_type, snd_spcm_duplex_type_t duplex_type) {
    snd_spcm_init_duplex_INDEXED *packed_data = malloc(sizeof(snd_spcm_init_duplex_INDEXED));
    packed_data->func = snd_spcm_init_duplex_INDEX;
    packed_data->args.a1 = playback_pcm;
    packed_data->args.a2 = capture_pcm;
    packed_data->args.a3 = rate;
    packed_data->args.a4 = channels;
    packed_data->args.a5 = format;
    packed_data->args.a6 = subformat;
    packed_data->args.a7 = latency;
    packed_data->args.a8 = _access;
    packed_data->args.a9 = xrun_type;
    packed_data->args.a10 = duplex_type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_spcm_init_get_params
int snd_spcm_init_get_params(snd_pcm_t * pcm, unsigned int * rate, snd_pcm_uframes_t * buffer_size, snd_pcm_uframes_t * period_size) {
    snd_spcm_init_get_params_INDEXED *packed_data = malloc(sizeof(snd_spcm_init_get_params_INDEXED));
    packed_data->func = snd_spcm_init_get_params_INDEX;
    packed_data->args.a1 = pcm;
    packed_data->args.a2 = rate;
    packed_data->args.a3 = buffer_size;
    packed_data->args.a4 = period_size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_close
int snd_timer_close(snd_timer_t * handle) {
    snd_timer_close_INDEXED *packed_data = malloc(sizeof(snd_timer_close_INDEXED));
    packed_data->func = snd_timer_close_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_continue
int snd_timer_continue(snd_timer_t * handle) {
    snd_timer_continue_INDEXED *packed_data = malloc(sizeof(snd_timer_continue_INDEXED));
    packed_data->func = snd_timer_continue_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_copy
void snd_timer_ginfo_copy(snd_timer_ginfo_t * dst, const snd_timer_ginfo_t * src) {
    snd_timer_ginfo_copy_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_copy_INDEXED));
    packed_data->func = snd_timer_ginfo_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_ginfo_free
void snd_timer_ginfo_free(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_free_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_free_INDEXED));
    packed_data->func = snd_timer_ginfo_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_card
int snd_timer_ginfo_get_card(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_card_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_card_INDEXED));
    packed_data->func = snd_timer_ginfo_get_card_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_clients
unsigned int snd_timer_ginfo_get_clients(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_clients_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_clients_INDEXED));
    packed_data->func = snd_timer_ginfo_get_clients_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_flags
unsigned int snd_timer_ginfo_get_flags(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_flags_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_flags_INDEXED));
    packed_data->func = snd_timer_ginfo_get_flags_INDEX;
    packed_data->args.a1 = obj;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_id
char * snd_timer_ginfo_get_id(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_id_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_id_INDEXED));
    packed_data->func = snd_timer_ginfo_get_id_INDEX;
    packed_data->args.a1 = obj;
    char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_name
char * snd_timer_ginfo_get_name(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_name_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_name_INDEXED));
    packed_data->func = snd_timer_ginfo_get_name_INDEX;
    packed_data->args.a1 = obj;
    char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_resolution
unsigned long snd_timer_ginfo_get_resolution(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_resolution_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_resolution_INDEXED));
    packed_data->func = snd_timer_ginfo_get_resolution_INDEX;
    packed_data->args.a1 = obj;
    unsigned long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_resolution_max
unsigned long snd_timer_ginfo_get_resolution_max(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_resolution_max_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_resolution_max_INDEXED));
    packed_data->func = snd_timer_ginfo_get_resolution_max_INDEX;
    packed_data->args.a1 = obj;
    unsigned long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_resolution_min
unsigned long snd_timer_ginfo_get_resolution_min(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_resolution_min_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_resolution_min_INDEXED));
    packed_data->func = snd_timer_ginfo_get_resolution_min_INDEX;
    packed_data->args.a1 = obj;
    unsigned long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_get_tid
snd_timer_id_t * snd_timer_ginfo_get_tid(snd_timer_ginfo_t * obj) {
    snd_timer_ginfo_get_tid_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_get_tid_INDEXED));
    packed_data->func = snd_timer_ginfo_get_tid_INDEX;
    packed_data->args.a1 = obj;
    snd_timer_id_t * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_malloc
int snd_timer_ginfo_malloc(snd_timer_ginfo_t ** ptr) {
    snd_timer_ginfo_malloc_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_malloc_INDEXED));
    packed_data->func = snd_timer_ginfo_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_set_tid
int snd_timer_ginfo_set_tid(snd_timer_ginfo_t * obj, snd_timer_id_t * tid) {
    snd_timer_ginfo_set_tid_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_set_tid_INDEXED));
    packed_data->func = snd_timer_ginfo_set_tid_INDEX;
    packed_data->args.a1 = obj;
    packed_data->args.a2 = tid;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_ginfo_sizeof
size_t snd_timer_ginfo_sizeof() {
    snd_timer_ginfo_sizeof_INDEXED *packed_data = malloc(sizeof(snd_timer_ginfo_sizeof_INDEXED));
    packed_data->func = snd_timer_ginfo_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_id_copy
void snd_timer_id_copy(snd_timer_id_t * dst, const snd_timer_id_t * src) {
    snd_timer_id_copy_INDEXED *packed_data = malloc(sizeof(snd_timer_id_copy_INDEXED));
    packed_data->func = snd_timer_id_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_id_free
void snd_timer_id_free(snd_timer_id_t * obj) {
    snd_timer_id_free_INDEXED *packed_data = malloc(sizeof(snd_timer_id_free_INDEXED));
    packed_data->func = snd_timer_id_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_id_get_card
int snd_timer_id_get_card(snd_timer_id_t * id) {
    snd_timer_id_get_card_INDEXED *packed_data = malloc(sizeof(snd_timer_id_get_card_INDEXED));
    packed_data->func = snd_timer_id_get_card_INDEX;
    packed_data->args.a1 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_id_get_class
int snd_timer_id_get_class(snd_timer_id_t * id) {
    snd_timer_id_get_class_INDEXED *packed_data = malloc(sizeof(snd_timer_id_get_class_INDEXED));
    packed_data->func = snd_timer_id_get_class_INDEX;
    packed_data->args.a1 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_id_get_device
int snd_timer_id_get_device(snd_timer_id_t * id) {
    snd_timer_id_get_device_INDEXED *packed_data = malloc(sizeof(snd_timer_id_get_device_INDEXED));
    packed_data->func = snd_timer_id_get_device_INDEX;
    packed_data->args.a1 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_id_get_sclass
int snd_timer_id_get_sclass(snd_timer_id_t * id) {
    snd_timer_id_get_sclass_INDEXED *packed_data = malloc(sizeof(snd_timer_id_get_sclass_INDEXED));
    packed_data->func = snd_timer_id_get_sclass_INDEX;
    packed_data->args.a1 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_id_get_subdevice
int snd_timer_id_get_subdevice(snd_timer_id_t * id) {
    snd_timer_id_get_subdevice_INDEXED *packed_data = malloc(sizeof(snd_timer_id_get_subdevice_INDEXED));
    packed_data->func = snd_timer_id_get_subdevice_INDEX;
    packed_data->args.a1 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_id_malloc
int snd_timer_id_malloc(snd_timer_id_t ** ptr) {
    snd_timer_id_malloc_INDEXED *packed_data = malloc(sizeof(snd_timer_id_malloc_INDEXED));
    packed_data->func = snd_timer_id_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_id_set_card
void snd_timer_id_set_card(snd_timer_id_t * id, int card) {
    snd_timer_id_set_card_INDEXED *packed_data = malloc(sizeof(snd_timer_id_set_card_INDEXED));
    packed_data->func = snd_timer_id_set_card_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = card;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_id_set_class
void snd_timer_id_set_class(snd_timer_id_t * id, int dev_class) {
    snd_timer_id_set_class_INDEXED *packed_data = malloc(sizeof(snd_timer_id_set_class_INDEXED));
    packed_data->func = snd_timer_id_set_class_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = dev_class;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_id_set_device
void snd_timer_id_set_device(snd_timer_id_t * id, int device) {
    snd_timer_id_set_device_INDEXED *packed_data = malloc(sizeof(snd_timer_id_set_device_INDEXED));
    packed_data->func = snd_timer_id_set_device_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = device;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_id_set_sclass
void snd_timer_id_set_sclass(snd_timer_id_t * id, int dev_sclass) {
    snd_timer_id_set_sclass_INDEXED *packed_data = malloc(sizeof(snd_timer_id_set_sclass_INDEXED));
    packed_data->func = snd_timer_id_set_sclass_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = dev_sclass;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_id_set_subdevice
void snd_timer_id_set_subdevice(snd_timer_id_t * id, int subdevice) {
    snd_timer_id_set_subdevice_INDEXED *packed_data = malloc(sizeof(snd_timer_id_set_subdevice_INDEXED));
    packed_data->func = snd_timer_id_set_subdevice_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = subdevice;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_id_sizeof
size_t snd_timer_id_sizeof() {
    snd_timer_id_sizeof_INDEXED *packed_data = malloc(sizeof(snd_timer_id_sizeof_INDEXED));
    packed_data->func = snd_timer_id_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info
int snd_timer_info(snd_timer_t * handle, snd_timer_info_t * timer) {
    snd_timer_info_INDEXED *packed_data = malloc(sizeof(snd_timer_info_INDEXED));
    packed_data->func = snd_timer_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = timer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info_copy
void snd_timer_info_copy(snd_timer_info_t * dst, const snd_timer_info_t * src) {
    snd_timer_info_copy_INDEXED *packed_data = malloc(sizeof(snd_timer_info_copy_INDEXED));
    packed_data->func = snd_timer_info_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_info_free
void snd_timer_info_free(snd_timer_info_t * obj) {
    snd_timer_info_free_INDEXED *packed_data = malloc(sizeof(snd_timer_info_free_INDEXED));
    packed_data->func = snd_timer_info_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_info_get_card
int snd_timer_info_get_card(snd_timer_info_t * info) {
    snd_timer_info_get_card_INDEXED *packed_data = malloc(sizeof(snd_timer_info_get_card_INDEXED));
    packed_data->func = snd_timer_info_get_card_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info_get_id
const char * snd_timer_info_get_id(snd_timer_info_t * info) {
    snd_timer_info_get_id_INDEXED *packed_data = malloc(sizeof(snd_timer_info_get_id_INDEXED));
    packed_data->func = snd_timer_info_get_id_INDEX;
    packed_data->args.a1 = info;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info_get_name
const char * snd_timer_info_get_name(snd_timer_info_t * info) {
    snd_timer_info_get_name_INDEXED *packed_data = malloc(sizeof(snd_timer_info_get_name_INDEXED));
    packed_data->func = snd_timer_info_get_name_INDEX;
    packed_data->args.a1 = info;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info_get_resolution
long snd_timer_info_get_resolution(snd_timer_info_t * info) {
    snd_timer_info_get_resolution_INDEXED *packed_data = malloc(sizeof(snd_timer_info_get_resolution_INDEXED));
    packed_data->func = snd_timer_info_get_resolution_INDEX;
    packed_data->args.a1 = info;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info_get_ticks
long snd_timer_info_get_ticks(snd_timer_info_t * info) {
    snd_timer_info_get_ticks_INDEXED *packed_data = malloc(sizeof(snd_timer_info_get_ticks_INDEXED));
    packed_data->func = snd_timer_info_get_ticks_INDEX;
    packed_data->args.a1 = info;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info_is_slave
int snd_timer_info_is_slave(snd_timer_info_t * info) {
    snd_timer_info_is_slave_INDEXED *packed_data = malloc(sizeof(snd_timer_info_is_slave_INDEXED));
    packed_data->func = snd_timer_info_is_slave_INDEX;
    packed_data->args.a1 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info_malloc
int snd_timer_info_malloc(snd_timer_info_t ** ptr) {
    snd_timer_info_malloc_INDEXED *packed_data = malloc(sizeof(snd_timer_info_malloc_INDEXED));
    packed_data->func = snd_timer_info_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_info_sizeof
size_t snd_timer_info_sizeof() {
    snd_timer_info_sizeof_INDEXED *packed_data = malloc(sizeof(snd_timer_info_sizeof_INDEXED));
    packed_data->func = snd_timer_info_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_open
int snd_timer_open(snd_timer_t ** handle, const char * name, int mode) {
    snd_timer_open_INDEXED *packed_data = malloc(sizeof(snd_timer_open_INDEXED));
    packed_data->func = snd_timer_open_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = name;
    packed_data->args.a3 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_open_lconf
int snd_timer_open_lconf(snd_timer_t ** handle, const char * name, int mode, snd_config_t * lconf) {
    snd_timer_open_lconf_INDEXED *packed_data = malloc(sizeof(snd_timer_open_lconf_INDEXED));
    packed_data->func = snd_timer_open_lconf_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = name;
    packed_data->args.a3 = mode;
    packed_data->args.a4 = lconf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params
int snd_timer_params(snd_timer_t * handle, snd_timer_params_t * params) {
    snd_timer_params_INDEXED *packed_data = malloc(sizeof(snd_timer_params_INDEXED));
    packed_data->func = snd_timer_params_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_copy
void snd_timer_params_copy(snd_timer_params_t * dst, const snd_timer_params_t * src) {
    snd_timer_params_copy_INDEXED *packed_data = malloc(sizeof(snd_timer_params_copy_INDEXED));
    packed_data->func = snd_timer_params_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_params_free
void snd_timer_params_free(snd_timer_params_t * obj) {
    snd_timer_params_free_INDEXED *packed_data = malloc(sizeof(snd_timer_params_free_INDEXED));
    packed_data->func = snd_timer_params_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_params_get_auto_start
int snd_timer_params_get_auto_start(snd_timer_params_t * params) {
    snd_timer_params_get_auto_start_INDEXED *packed_data = malloc(sizeof(snd_timer_params_get_auto_start_INDEXED));
    packed_data->func = snd_timer_params_get_auto_start_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_get_early_event
int snd_timer_params_get_early_event(snd_timer_params_t * params) {
    snd_timer_params_get_early_event_INDEXED *packed_data = malloc(sizeof(snd_timer_params_get_early_event_INDEXED));
    packed_data->func = snd_timer_params_get_early_event_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_get_exclusive
int snd_timer_params_get_exclusive(snd_timer_params_t * params) {
    snd_timer_params_get_exclusive_INDEXED *packed_data = malloc(sizeof(snd_timer_params_get_exclusive_INDEXED));
    packed_data->func = snd_timer_params_get_exclusive_INDEX;
    packed_data->args.a1 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_get_filter
unsigned int snd_timer_params_get_filter(snd_timer_params_t * params) {
    snd_timer_params_get_filter_INDEXED *packed_data = malloc(sizeof(snd_timer_params_get_filter_INDEXED));
    packed_data->func = snd_timer_params_get_filter_INDEX;
    packed_data->args.a1 = params;
    unsigned int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_get_queue_size
long snd_timer_params_get_queue_size(snd_timer_params_t * params) {
    snd_timer_params_get_queue_size_INDEXED *packed_data = malloc(sizeof(snd_timer_params_get_queue_size_INDEXED));
    packed_data->func = snd_timer_params_get_queue_size_INDEX;
    packed_data->args.a1 = params;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_get_ticks
long snd_timer_params_get_ticks(snd_timer_params_t * params) {
    snd_timer_params_get_ticks_INDEXED *packed_data = malloc(sizeof(snd_timer_params_get_ticks_INDEXED));
    packed_data->func = snd_timer_params_get_ticks_INDEX;
    packed_data->args.a1 = params;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_malloc
int snd_timer_params_malloc(snd_timer_params_t ** ptr) {
    snd_timer_params_malloc_INDEXED *packed_data = malloc(sizeof(snd_timer_params_malloc_INDEXED));
    packed_data->func = snd_timer_params_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_set_auto_start
int snd_timer_params_set_auto_start(snd_timer_params_t * params, int auto_start) {
    snd_timer_params_set_auto_start_INDEXED *packed_data = malloc(sizeof(snd_timer_params_set_auto_start_INDEXED));
    packed_data->func = snd_timer_params_set_auto_start_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = auto_start;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_set_early_event
int snd_timer_params_set_early_event(snd_timer_params_t * params, int early_event) {
    snd_timer_params_set_early_event_INDEXED *packed_data = malloc(sizeof(snd_timer_params_set_early_event_INDEXED));
    packed_data->func = snd_timer_params_set_early_event_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = early_event;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_set_exclusive
int snd_timer_params_set_exclusive(snd_timer_params_t * params, int exclusive) {
    snd_timer_params_set_exclusive_INDEXED *packed_data = malloc(sizeof(snd_timer_params_set_exclusive_INDEXED));
    packed_data->func = snd_timer_params_set_exclusive_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = exclusive;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_params_set_filter
void snd_timer_params_set_filter(snd_timer_params_t * params, unsigned int filter) {
    snd_timer_params_set_filter_INDEXED *packed_data = malloc(sizeof(snd_timer_params_set_filter_INDEXED));
    packed_data->func = snd_timer_params_set_filter_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = filter;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_params_set_queue_size
void snd_timer_params_set_queue_size(snd_timer_params_t * params, long queue_size) {
    snd_timer_params_set_queue_size_INDEXED *packed_data = malloc(sizeof(snd_timer_params_set_queue_size_INDEXED));
    packed_data->func = snd_timer_params_set_queue_size_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = queue_size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_params_set_ticks
void snd_timer_params_set_ticks(snd_timer_params_t * params, long ticks) {
    snd_timer_params_set_ticks_INDEXED *packed_data = malloc(sizeof(snd_timer_params_set_ticks_INDEXED));
    packed_data->func = snd_timer_params_set_ticks_INDEX;
    packed_data->args.a1 = params;
    packed_data->args.a2 = ticks;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_params_sizeof
size_t snd_timer_params_sizeof() {
    snd_timer_params_sizeof_INDEXED *packed_data = malloc(sizeof(snd_timer_params_sizeof_INDEXED));
    packed_data->func = snd_timer_params_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_poll_descriptors
int snd_timer_poll_descriptors(snd_timer_t * handle, struct pollfd * pfds, unsigned int space) {
    snd_timer_poll_descriptors_INDEXED *packed_data = malloc(sizeof(snd_timer_poll_descriptors_INDEXED));
    packed_data->func = snd_timer_poll_descriptors_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = space;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_poll_descriptors_count
int snd_timer_poll_descriptors_count(snd_timer_t * handle) {
    snd_timer_poll_descriptors_count_INDEXED *packed_data = malloc(sizeof(snd_timer_poll_descriptors_count_INDEXED));
    packed_data->func = snd_timer_poll_descriptors_count_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_poll_descriptors_revents
int snd_timer_poll_descriptors_revents(snd_timer_t * timer, struct pollfd * pfds, unsigned int nfds, unsigned short * revents) {
    snd_timer_poll_descriptors_revents_INDEXED *packed_data = malloc(sizeof(snd_timer_poll_descriptors_revents_INDEXED));
    packed_data->func = snd_timer_poll_descriptors_revents_INDEX;
    packed_data->args.a1 = timer;
    packed_data->args.a2 = pfds;
    packed_data->args.a3 = nfds;
    packed_data->args.a4 = revents;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_query_close
int snd_timer_query_close(snd_timer_query_t * handle) {
    snd_timer_query_close_INDEXED *packed_data = malloc(sizeof(snd_timer_query_close_INDEXED));
    packed_data->func = snd_timer_query_close_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_query_info
int snd_timer_query_info(snd_timer_query_t * handle, snd_timer_ginfo_t * info) {
    snd_timer_query_info_INDEXED *packed_data = malloc(sizeof(snd_timer_query_info_INDEXED));
    packed_data->func = snd_timer_query_info_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = info;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_query_next_device
int snd_timer_query_next_device(snd_timer_query_t * handle, snd_timer_id_t * tid) {
    snd_timer_query_next_device_INDEXED *packed_data = malloc(sizeof(snd_timer_query_next_device_INDEXED));
    packed_data->func = snd_timer_query_next_device_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = tid;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_query_open
int snd_timer_query_open(snd_timer_query_t ** handle, const char * name, int mode) {
    snd_timer_query_open_INDEXED *packed_data = malloc(sizeof(snd_timer_query_open_INDEXED));
    packed_data->func = snd_timer_query_open_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = name;
    packed_data->args.a3 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_query_open_lconf
int snd_timer_query_open_lconf(snd_timer_query_t ** handle, const char * name, int mode, snd_config_t * lconf) {
    snd_timer_query_open_lconf_INDEXED *packed_data = malloc(sizeof(snd_timer_query_open_lconf_INDEXED));
    packed_data->func = snd_timer_query_open_lconf_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = name;
    packed_data->args.a3 = mode;
    packed_data->args.a4 = lconf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_query_params
int snd_timer_query_params(snd_timer_query_t * handle, snd_timer_gparams_t * params) {
    snd_timer_query_params_INDEXED *packed_data = malloc(sizeof(snd_timer_query_params_INDEXED));
    packed_data->func = snd_timer_query_params_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_query_status
int snd_timer_query_status(snd_timer_query_t * handle, snd_timer_gstatus_t * status) {
    snd_timer_query_status_INDEXED *packed_data = malloc(sizeof(snd_timer_query_status_INDEXED));
    packed_data->func = snd_timer_query_status_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = status;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_read
ssize_t snd_timer_read(snd_timer_t * handle, void * buffer, size_t size) {
    snd_timer_read_INDEXED *packed_data = malloc(sizeof(snd_timer_read_INDEXED));
    packed_data->func = snd_timer_read_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = buffer;
    packed_data->args.a3 = size;
    ssize_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_start
int snd_timer_start(snd_timer_t * handle) {
    snd_timer_start_INDEXED *packed_data = malloc(sizeof(snd_timer_start_INDEXED));
    packed_data->func = snd_timer_start_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_status
int snd_timer_status(snd_timer_t * handle, snd_timer_status_t * status) {
    snd_timer_status_INDEXED *packed_data = malloc(sizeof(snd_timer_status_INDEXED));
    packed_data->func = snd_timer_status_INDEX;
    packed_data->args.a1 = handle;
    packed_data->args.a2 = status;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_status_copy
void snd_timer_status_copy(snd_timer_status_t * dst, const snd_timer_status_t * src) {
    snd_timer_status_copy_INDEXED *packed_data = malloc(sizeof(snd_timer_status_copy_INDEXED));
    packed_data->func = snd_timer_status_copy_INDEX;
    packed_data->args.a1 = dst;
    packed_data->args.a2 = src;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_status_free
void snd_timer_status_free(snd_timer_status_t * obj) {
    snd_timer_status_free_INDEXED *packed_data = malloc(sizeof(snd_timer_status_free_INDEXED));
    packed_data->func = snd_timer_status_free_INDEX;
    packed_data->args.a1 = obj;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
}
#endif
#ifndef skip_client_snd_timer_status_get_lost
long snd_timer_status_get_lost(snd_timer_status_t * status) {
    snd_timer_status_get_lost_INDEXED *packed_data = malloc(sizeof(snd_timer_status_get_lost_INDEXED));
    packed_data->func = snd_timer_status_get_lost_INDEX;
    packed_data->args.a1 = status;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_status_get_overrun
long snd_timer_status_get_overrun(snd_timer_status_t * status) {
    snd_timer_status_get_overrun_INDEXED *packed_data = malloc(sizeof(snd_timer_status_get_overrun_INDEXED));
    packed_data->func = snd_timer_status_get_overrun_INDEX;
    packed_data->args.a1 = status;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_status_get_queue
long snd_timer_status_get_queue(snd_timer_status_t * status) {
    snd_timer_status_get_queue_INDEXED *packed_data = malloc(sizeof(snd_timer_status_get_queue_INDEXED));
    packed_data->func = snd_timer_status_get_queue_INDEX;
    packed_data->args.a1 = status;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_status_get_resolution
long snd_timer_status_get_resolution(snd_timer_status_t * status) {
    snd_timer_status_get_resolution_INDEXED *packed_data = malloc(sizeof(snd_timer_status_get_resolution_INDEXED));
    packed_data->func = snd_timer_status_get_resolution_INDEX;
    packed_data->args.a1 = status;
    long ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_status_get_timestamp
snd_htimestamp_t snd_timer_status_get_timestamp(snd_timer_status_t * status) {
    snd_timer_status_get_timestamp_INDEXED *packed_data = malloc(sizeof(snd_timer_status_get_timestamp_INDEXED));
    packed_data->func = snd_timer_status_get_timestamp_INDEX;
    packed_data->args.a1 = status;
    snd_htimestamp_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_status_malloc
int snd_timer_status_malloc(snd_timer_status_t ** ptr) {
    snd_timer_status_malloc_INDEXED *packed_data = malloc(sizeof(snd_timer_status_malloc_INDEXED));
    packed_data->func = snd_timer_status_malloc_INDEX;
    packed_data->args.a1 = ptr;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_status_sizeof
size_t snd_timer_status_sizeof() {
    snd_timer_status_sizeof_INDEXED *packed_data = malloc(sizeof(snd_timer_status_sizeof_INDEXED));
    packed_data->func = snd_timer_status_sizeof_INDEX;
    size_t ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_timer_stop
int snd_timer_stop(snd_timer_t * handle) {
    snd_timer_stop_INDEXED *packed_data = malloc(sizeof(snd_timer_stop_INDEXED));
    packed_data->func = snd_timer_stop_INDEX;
    packed_data->args.a1 = handle;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
}
#endif
#ifndef skip_client_snd_user_file
int snd_user_file(const char * file, char ** result) {
    snd_user_file_INDEXED *packed_data = malloc(sizeof(snd_user_file_INDEXED));
    packed_data->func = snd_user_file_INDEX;
    packed_data->args.a1 = file;
    packed_data->args.a2 = result;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    free(packed_data);
    return ret;
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
    if (strcmp(name, "snd_asoundlib_version") == 0) {
        return (void *)snd_asoundlib_version;
    }
    if (strcmp(name, "snd_async_add_ctl_handler") == 0) {
        return (void *)snd_async_add_ctl_handler;
    }
    if (strcmp(name, "snd_async_add_handler") == 0) {
        return (void *)snd_async_add_handler;
    }
    if (strcmp(name, "snd_async_add_pcm_handler") == 0) {
        return (void *)snd_async_add_pcm_handler;
    }
    if (strcmp(name, "snd_async_add_timer_handler") == 0) {
        return (void *)snd_async_add_timer_handler;
    }
    if (strcmp(name, "snd_async_del_handler") == 0) {
        return (void *)snd_async_del_handler;
    }
    if (strcmp(name, "snd_async_handler_get_callback_private") == 0) {
        return (void *)snd_async_handler_get_callback_private;
    }
    if (strcmp(name, "snd_async_handler_get_ctl") == 0) {
        return (void *)snd_async_handler_get_ctl;
    }
    if (strcmp(name, "snd_async_handler_get_fd") == 0) {
        return (void *)snd_async_handler_get_fd;
    }
    if (strcmp(name, "snd_async_handler_get_pcm") == 0) {
        return (void *)snd_async_handler_get_pcm;
    }
    if (strcmp(name, "snd_async_handler_get_signo") == 0) {
        return (void *)snd_async_handler_get_signo;
    }
    if (strcmp(name, "snd_async_handler_get_timer") == 0) {
        return (void *)snd_async_handler_get_timer;
    }
    if (strcmp(name, "snd_card_get_index") == 0) {
        return (void *)snd_card_get_index;
    }
    if (strcmp(name, "snd_card_get_longname") == 0) {
        return (void *)snd_card_get_longname;
    }
    if (strcmp(name, "snd_card_get_name") == 0) {
        return (void *)snd_card_get_name;
    }
    if (strcmp(name, "snd_card_load") == 0) {
        return (void *)snd_card_load;
    }
    if (strcmp(name, "snd_card_next") == 0) {
        return (void *)snd_card_next;
    }
    if (strcmp(name, "snd_config_add") == 0) {
        return (void *)snd_config_add;
    }
    if (strcmp(name, "snd_config_copy") == 0) {
        return (void *)snd_config_copy;
    }
    if (strcmp(name, "snd_config_delete") == 0) {
        return (void *)snd_config_delete;
    }
    if (strcmp(name, "snd_config_delete_compound_members") == 0) {
        return (void *)snd_config_delete_compound_members;
    }
    if (strcmp(name, "snd_config_evaluate") == 0) {
        return (void *)snd_config_evaluate;
    }
    if (strcmp(name, "snd_config_expand") == 0) {
        return (void *)snd_config_expand;
    }
    if (strcmp(name, "snd_config_get_ascii") == 0) {
        return (void *)snd_config_get_ascii;
    }
    if (strcmp(name, "snd_config_get_bool") == 0) {
        return (void *)snd_config_get_bool;
    }
    if (strcmp(name, "snd_config_get_bool_ascii") == 0) {
        return (void *)snd_config_get_bool_ascii;
    }
    if (strcmp(name, "snd_config_get_ctl_iface") == 0) {
        return (void *)snd_config_get_ctl_iface;
    }
    if (strcmp(name, "snd_config_get_ctl_iface_ascii") == 0) {
        return (void *)snd_config_get_ctl_iface_ascii;
    }
    if (strcmp(name, "snd_config_get_id") == 0) {
        return (void *)snd_config_get_id;
    }
    if (strcmp(name, "snd_config_get_integer") == 0) {
        return (void *)snd_config_get_integer;
    }
    if (strcmp(name, "snd_config_get_integer64") == 0) {
        return (void *)snd_config_get_integer64;
    }
    if (strcmp(name, "snd_config_get_ireal") == 0) {
        return (void *)snd_config_get_ireal;
    }
    if (strcmp(name, "snd_config_get_pointer") == 0) {
        return (void *)snd_config_get_pointer;
    }
    if (strcmp(name, "snd_config_get_real") == 0) {
        return (void *)snd_config_get_real;
    }
    if (strcmp(name, "snd_config_get_string") == 0) {
        return (void *)snd_config_get_string;
    }
    if (strcmp(name, "snd_config_get_type") == 0) {
        return (void *)snd_config_get_type;
    }
    if (strcmp(name, "snd_config_imake_integer") == 0) {
        return (void *)snd_config_imake_integer;
    }
    if (strcmp(name, "snd_config_imake_integer64") == 0) {
        return (void *)snd_config_imake_integer64;
    }
    if (strcmp(name, "snd_config_imake_pointer") == 0) {
        return (void *)snd_config_imake_pointer;
    }
    if (strcmp(name, "snd_config_imake_real") == 0) {
        return (void *)snd_config_imake_real;
    }
    if (strcmp(name, "snd_config_imake_string") == 0) {
        return (void *)snd_config_imake_string;
    }
    if (strcmp(name, "snd_config_iterator_end") == 0) {
        return (void *)snd_config_iterator_end;
    }
    if (strcmp(name, "snd_config_iterator_entry") == 0) {
        return (void *)snd_config_iterator_entry;
    }
    if (strcmp(name, "snd_config_iterator_first") == 0) {
        return (void *)snd_config_iterator_first;
    }
    if (strcmp(name, "snd_config_iterator_next") == 0) {
        return (void *)snd_config_iterator_next;
    }
    if (strcmp(name, "snd_config_load") == 0) {
        return (void *)snd_config_load;
    }
    if (strcmp(name, "snd_config_load_override") == 0) {
        return (void *)snd_config_load_override;
    }
    if (strcmp(name, "snd_config_make") == 0) {
        return (void *)snd_config_make;
    }
    if (strcmp(name, "snd_config_make_compound") == 0) {
        return (void *)snd_config_make_compound;
    }
    if (strcmp(name, "snd_config_make_integer") == 0) {
        return (void *)snd_config_make_integer;
    }
    if (strcmp(name, "snd_config_make_integer64") == 0) {
        return (void *)snd_config_make_integer64;
    }
    if (strcmp(name, "snd_config_make_pointer") == 0) {
        return (void *)snd_config_make_pointer;
    }
    if (strcmp(name, "snd_config_make_real") == 0) {
        return (void *)snd_config_make_real;
    }
    if (strcmp(name, "snd_config_make_string") == 0) {
        return (void *)snd_config_make_string;
    }
    if (strcmp(name, "snd_config_save") == 0) {
        return (void *)snd_config_save;
    }
    if (strcmp(name, "snd_config_search") == 0) {
        return (void *)snd_config_search;
    }
    if (strcmp(name, "snd_config_search_definition") == 0) {
        return (void *)snd_config_search_definition;
    }
    if (strcmp(name, "snd_config_set_ascii") == 0) {
        return (void *)snd_config_set_ascii;
    }
    if (strcmp(name, "snd_config_set_id") == 0) {
        return (void *)snd_config_set_id;
    }
    if (strcmp(name, "snd_config_set_integer") == 0) {
        return (void *)snd_config_set_integer;
    }
    if (strcmp(name, "snd_config_set_integer64") == 0) {
        return (void *)snd_config_set_integer64;
    }
    if (strcmp(name, "snd_config_set_pointer") == 0) {
        return (void *)snd_config_set_pointer;
    }
    if (strcmp(name, "snd_config_set_real") == 0) {
        return (void *)snd_config_set_real;
    }
    if (strcmp(name, "snd_config_set_string") == 0) {
        return (void *)snd_config_set_string;
    }
    if (strcmp(name, "snd_config_test_id") == 0) {
        return (void *)snd_config_test_id;
    }
    if (strcmp(name, "snd_config_top") == 0) {
        return (void *)snd_config_top;
    }
    if (strcmp(name, "snd_config_update") == 0) {
        return (void *)snd_config_update;
    }
    if (strcmp(name, "snd_config_update_free") == 0) {
        return (void *)snd_config_update_free;
    }
    if (strcmp(name, "snd_config_update_free_global") == 0) {
        return (void *)snd_config_update_free_global;
    }
    if (strcmp(name, "snd_config_update_r") == 0) {
        return (void *)snd_config_update_r;
    }
    if (strcmp(name, "snd_ctl_card_info") == 0) {
        return (void *)snd_ctl_card_info;
    }
    if (strcmp(name, "snd_ctl_card_info_clear") == 0) {
        return (void *)snd_ctl_card_info_clear;
    }
    if (strcmp(name, "snd_ctl_card_info_copy") == 0) {
        return (void *)snd_ctl_card_info_copy;
    }
    if (strcmp(name, "snd_ctl_card_info_free") == 0) {
        return (void *)snd_ctl_card_info_free;
    }
    if (strcmp(name, "snd_ctl_card_info_get_card") == 0) {
        return (void *)snd_ctl_card_info_get_card;
    }
    if (strcmp(name, "snd_ctl_card_info_get_components") == 0) {
        return (void *)snd_ctl_card_info_get_components;
    }
    if (strcmp(name, "snd_ctl_card_info_get_driver") == 0) {
        return (void *)snd_ctl_card_info_get_driver;
    }
    if (strcmp(name, "snd_ctl_card_info_get_id") == 0) {
        return (void *)snd_ctl_card_info_get_id;
    }
    if (strcmp(name, "snd_ctl_card_info_get_longname") == 0) {
        return (void *)snd_ctl_card_info_get_longname;
    }
    if (strcmp(name, "snd_ctl_card_info_get_mixername") == 0) {
        return (void *)snd_ctl_card_info_get_mixername;
    }
    if (strcmp(name, "snd_ctl_card_info_get_name") == 0) {
        return (void *)snd_ctl_card_info_get_name;
    }
    if (strcmp(name, "snd_ctl_card_info_malloc") == 0) {
        return (void *)snd_ctl_card_info_malloc;
    }
    if (strcmp(name, "snd_ctl_card_info_sizeof") == 0) {
        return (void *)snd_ctl_card_info_sizeof;
    }
    if (strcmp(name, "snd_ctl_close") == 0) {
        return (void *)snd_ctl_close;
    }
    if (strcmp(name, "snd_ctl_elem_add_boolean") == 0) {
        return (void *)snd_ctl_elem_add_boolean;
    }
    if (strcmp(name, "snd_ctl_elem_add_iec958") == 0) {
        return (void *)snd_ctl_elem_add_iec958;
    }
    if (strcmp(name, "snd_ctl_elem_add_integer") == 0) {
        return (void *)snd_ctl_elem_add_integer;
    }
    if (strcmp(name, "snd_ctl_elem_add_integer64") == 0) {
        return (void *)snd_ctl_elem_add_integer64;
    }
    if (strcmp(name, "snd_ctl_elem_id_clear") == 0) {
        return (void *)snd_ctl_elem_id_clear;
    }
    if (strcmp(name, "snd_ctl_elem_id_copy") == 0) {
        return (void *)snd_ctl_elem_id_copy;
    }
    if (strcmp(name, "snd_ctl_elem_id_free") == 0) {
        return (void *)snd_ctl_elem_id_free;
    }
    if (strcmp(name, "snd_ctl_elem_id_get_device") == 0) {
        return (void *)snd_ctl_elem_id_get_device;
    }
    if (strcmp(name, "snd_ctl_elem_id_get_index") == 0) {
        return (void *)snd_ctl_elem_id_get_index;
    }
    if (strcmp(name, "snd_ctl_elem_id_get_interface") == 0) {
        return (void *)snd_ctl_elem_id_get_interface;
    }
    if (strcmp(name, "snd_ctl_elem_id_get_name") == 0) {
        return (void *)snd_ctl_elem_id_get_name;
    }
    if (strcmp(name, "snd_ctl_elem_id_get_numid") == 0) {
        return (void *)snd_ctl_elem_id_get_numid;
    }
    if (strcmp(name, "snd_ctl_elem_id_get_subdevice") == 0) {
        return (void *)snd_ctl_elem_id_get_subdevice;
    }
    if (strcmp(name, "snd_ctl_elem_id_malloc") == 0) {
        return (void *)snd_ctl_elem_id_malloc;
    }
    if (strcmp(name, "snd_ctl_elem_id_set_device") == 0) {
        return (void *)snd_ctl_elem_id_set_device;
    }
    if (strcmp(name, "snd_ctl_elem_id_set_index") == 0) {
        return (void *)snd_ctl_elem_id_set_index;
    }
    if (strcmp(name, "snd_ctl_elem_id_set_interface") == 0) {
        return (void *)snd_ctl_elem_id_set_interface;
    }
    if (strcmp(name, "snd_ctl_elem_id_set_name") == 0) {
        return (void *)snd_ctl_elem_id_set_name;
    }
    if (strcmp(name, "snd_ctl_elem_id_set_numid") == 0) {
        return (void *)snd_ctl_elem_id_set_numid;
    }
    if (strcmp(name, "snd_ctl_elem_id_set_subdevice") == 0) {
        return (void *)snd_ctl_elem_id_set_subdevice;
    }
    if (strcmp(name, "snd_ctl_elem_id_sizeof") == 0) {
        return (void *)snd_ctl_elem_id_sizeof;
    }
    if (strcmp(name, "snd_ctl_elem_iface_name") == 0) {
        return (void *)snd_ctl_elem_iface_name;
    }
    if (strcmp(name, "snd_ctl_elem_info") == 0) {
        return (void *)snd_ctl_elem_info;
    }
    if (strcmp(name, "snd_ctl_elem_info_clear") == 0) {
        return (void *)snd_ctl_elem_info_clear;
    }
    if (strcmp(name, "snd_ctl_elem_info_copy") == 0) {
        return (void *)snd_ctl_elem_info_copy;
    }
    if (strcmp(name, "snd_ctl_elem_info_free") == 0) {
        return (void *)snd_ctl_elem_info_free;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_count") == 0) {
        return (void *)snd_ctl_elem_info_get_count;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_device") == 0) {
        return (void *)snd_ctl_elem_info_get_device;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_dimension") == 0) {
        return (void *)snd_ctl_elem_info_get_dimension;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_dimensions") == 0) {
        return (void *)snd_ctl_elem_info_get_dimensions;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_id") == 0) {
        return (void *)snd_ctl_elem_info_get_id;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_index") == 0) {
        return (void *)snd_ctl_elem_info_get_index;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_interface") == 0) {
        return (void *)snd_ctl_elem_info_get_interface;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_item_name") == 0) {
        return (void *)snd_ctl_elem_info_get_item_name;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_items") == 0) {
        return (void *)snd_ctl_elem_info_get_items;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_max") == 0) {
        return (void *)snd_ctl_elem_info_get_max;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_max64") == 0) {
        return (void *)snd_ctl_elem_info_get_max64;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_min") == 0) {
        return (void *)snd_ctl_elem_info_get_min;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_min64") == 0) {
        return (void *)snd_ctl_elem_info_get_min64;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_name") == 0) {
        return (void *)snd_ctl_elem_info_get_name;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_numid") == 0) {
        return (void *)snd_ctl_elem_info_get_numid;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_owner") == 0) {
        return (void *)snd_ctl_elem_info_get_owner;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_step") == 0) {
        return (void *)snd_ctl_elem_info_get_step;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_step64") == 0) {
        return (void *)snd_ctl_elem_info_get_step64;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_subdevice") == 0) {
        return (void *)snd_ctl_elem_info_get_subdevice;
    }
    if (strcmp(name, "snd_ctl_elem_info_get_type") == 0) {
        return (void *)snd_ctl_elem_info_get_type;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_inactive") == 0) {
        return (void *)snd_ctl_elem_info_is_inactive;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_locked") == 0) {
        return (void *)snd_ctl_elem_info_is_locked;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_owner") == 0) {
        return (void *)snd_ctl_elem_info_is_owner;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_readable") == 0) {
        return (void *)snd_ctl_elem_info_is_readable;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_tlv_commandable") == 0) {
        return (void *)snd_ctl_elem_info_is_tlv_commandable;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_tlv_readable") == 0) {
        return (void *)snd_ctl_elem_info_is_tlv_readable;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_tlv_writable") == 0) {
        return (void *)snd_ctl_elem_info_is_tlv_writable;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_user") == 0) {
        return (void *)snd_ctl_elem_info_is_user;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_volatile") == 0) {
        return (void *)snd_ctl_elem_info_is_volatile;
    }
    if (strcmp(name, "snd_ctl_elem_info_is_writable") == 0) {
        return (void *)snd_ctl_elem_info_is_writable;
    }
    if (strcmp(name, "snd_ctl_elem_info_malloc") == 0) {
        return (void *)snd_ctl_elem_info_malloc;
    }
    if (strcmp(name, "snd_ctl_elem_info_set_device") == 0) {
        return (void *)snd_ctl_elem_info_set_device;
    }
    if (strcmp(name, "snd_ctl_elem_info_set_id") == 0) {
        return (void *)snd_ctl_elem_info_set_id;
    }
    if (strcmp(name, "snd_ctl_elem_info_set_index") == 0) {
        return (void *)snd_ctl_elem_info_set_index;
    }
    if (strcmp(name, "snd_ctl_elem_info_set_interface") == 0) {
        return (void *)snd_ctl_elem_info_set_interface;
    }
    if (strcmp(name, "snd_ctl_elem_info_set_item") == 0) {
        return (void *)snd_ctl_elem_info_set_item;
    }
    if (strcmp(name, "snd_ctl_elem_info_set_name") == 0) {
        return (void *)snd_ctl_elem_info_set_name;
    }
    if (strcmp(name, "snd_ctl_elem_info_set_numid") == 0) {
        return (void *)snd_ctl_elem_info_set_numid;
    }
    if (strcmp(name, "snd_ctl_elem_info_set_subdevice") == 0) {
        return (void *)snd_ctl_elem_info_set_subdevice;
    }
    if (strcmp(name, "snd_ctl_elem_info_sizeof") == 0) {
        return (void *)snd_ctl_elem_info_sizeof;
    }
    if (strcmp(name, "snd_ctl_elem_list") == 0) {
        return (void *)snd_ctl_elem_list;
    }
    if (strcmp(name, "snd_ctl_elem_list_alloc_space") == 0) {
        return (void *)snd_ctl_elem_list_alloc_space;
    }
    if (strcmp(name, "snd_ctl_elem_list_clear") == 0) {
        return (void *)snd_ctl_elem_list_clear;
    }
    if (strcmp(name, "snd_ctl_elem_list_copy") == 0) {
        return (void *)snd_ctl_elem_list_copy;
    }
    if (strcmp(name, "snd_ctl_elem_list_free") == 0) {
        return (void *)snd_ctl_elem_list_free;
    }
    if (strcmp(name, "snd_ctl_elem_list_free_space") == 0) {
        return (void *)snd_ctl_elem_list_free_space;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_count") == 0) {
        return (void *)snd_ctl_elem_list_get_count;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_device") == 0) {
        return (void *)snd_ctl_elem_list_get_device;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_id") == 0) {
        return (void *)snd_ctl_elem_list_get_id;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_index") == 0) {
        return (void *)snd_ctl_elem_list_get_index;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_interface") == 0) {
        return (void *)snd_ctl_elem_list_get_interface;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_name") == 0) {
        return (void *)snd_ctl_elem_list_get_name;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_numid") == 0) {
        return (void *)snd_ctl_elem_list_get_numid;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_subdevice") == 0) {
        return (void *)snd_ctl_elem_list_get_subdevice;
    }
    if (strcmp(name, "snd_ctl_elem_list_get_used") == 0) {
        return (void *)snd_ctl_elem_list_get_used;
    }
    if (strcmp(name, "snd_ctl_elem_list_malloc") == 0) {
        return (void *)snd_ctl_elem_list_malloc;
    }
    if (strcmp(name, "snd_ctl_elem_list_set_offset") == 0) {
        return (void *)snd_ctl_elem_list_set_offset;
    }
    if (strcmp(name, "snd_ctl_elem_list_sizeof") == 0) {
        return (void *)snd_ctl_elem_list_sizeof;
    }
    if (strcmp(name, "snd_ctl_elem_lock") == 0) {
        return (void *)snd_ctl_elem_lock;
    }
    if (strcmp(name, "snd_ctl_elem_read") == 0) {
        return (void *)snd_ctl_elem_read;
    }
    if (strcmp(name, "snd_ctl_elem_remove") == 0) {
        return (void *)snd_ctl_elem_remove;
    }
    if (strcmp(name, "snd_ctl_elem_set_bytes") == 0) {
        return (void *)snd_ctl_elem_set_bytes;
    }
    if (strcmp(name, "snd_ctl_elem_tlv_command") == 0) {
        return (void *)snd_ctl_elem_tlv_command;
    }
    if (strcmp(name, "snd_ctl_elem_tlv_read") == 0) {
        return (void *)snd_ctl_elem_tlv_read;
    }
    if (strcmp(name, "snd_ctl_elem_tlv_write") == 0) {
        return (void *)snd_ctl_elem_tlv_write;
    }
    if (strcmp(name, "snd_ctl_elem_type_name") == 0) {
        return (void *)snd_ctl_elem_type_name;
    }
    if (strcmp(name, "snd_ctl_elem_unlock") == 0) {
        return (void *)snd_ctl_elem_unlock;
    }
    if (strcmp(name, "snd_ctl_elem_value_clear") == 0) {
        return (void *)snd_ctl_elem_value_clear;
    }
    if (strcmp(name, "snd_ctl_elem_value_copy") == 0) {
        return (void *)snd_ctl_elem_value_copy;
    }
    if (strcmp(name, "snd_ctl_elem_value_free") == 0) {
        return (void *)snd_ctl_elem_value_free;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_boolean") == 0) {
        return (void *)snd_ctl_elem_value_get_boolean;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_byte") == 0) {
        return (void *)snd_ctl_elem_value_get_byte;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_bytes") == 0) {
        return (void *)snd_ctl_elem_value_get_bytes;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_device") == 0) {
        return (void *)snd_ctl_elem_value_get_device;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_enumerated") == 0) {
        return (void *)snd_ctl_elem_value_get_enumerated;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_id") == 0) {
        return (void *)snd_ctl_elem_value_get_id;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_iec958") == 0) {
        return (void *)snd_ctl_elem_value_get_iec958;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_index") == 0) {
        return (void *)snd_ctl_elem_value_get_index;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_integer") == 0) {
        return (void *)snd_ctl_elem_value_get_integer;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_integer64") == 0) {
        return (void *)snd_ctl_elem_value_get_integer64;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_interface") == 0) {
        return (void *)snd_ctl_elem_value_get_interface;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_name") == 0) {
        return (void *)snd_ctl_elem_value_get_name;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_numid") == 0) {
        return (void *)snd_ctl_elem_value_get_numid;
    }
    if (strcmp(name, "snd_ctl_elem_value_get_subdevice") == 0) {
        return (void *)snd_ctl_elem_value_get_subdevice;
    }
    if (strcmp(name, "snd_ctl_elem_value_malloc") == 0) {
        return (void *)snd_ctl_elem_value_malloc;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_boolean") == 0) {
        return (void *)snd_ctl_elem_value_set_boolean;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_byte") == 0) {
        return (void *)snd_ctl_elem_value_set_byte;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_device") == 0) {
        return (void *)snd_ctl_elem_value_set_device;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_enumerated") == 0) {
        return (void *)snd_ctl_elem_value_set_enumerated;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_id") == 0) {
        return (void *)snd_ctl_elem_value_set_id;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_iec958") == 0) {
        return (void *)snd_ctl_elem_value_set_iec958;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_index") == 0) {
        return (void *)snd_ctl_elem_value_set_index;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_integer") == 0) {
        return (void *)snd_ctl_elem_value_set_integer;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_integer64") == 0) {
        return (void *)snd_ctl_elem_value_set_integer64;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_interface") == 0) {
        return (void *)snd_ctl_elem_value_set_interface;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_name") == 0) {
        return (void *)snd_ctl_elem_value_set_name;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_numid") == 0) {
        return (void *)snd_ctl_elem_value_set_numid;
    }
    if (strcmp(name, "snd_ctl_elem_value_set_subdevice") == 0) {
        return (void *)snd_ctl_elem_value_set_subdevice;
    }
    if (strcmp(name, "snd_ctl_elem_value_sizeof") == 0) {
        return (void *)snd_ctl_elem_value_sizeof;
    }
    if (strcmp(name, "snd_ctl_elem_write") == 0) {
        return (void *)snd_ctl_elem_write;
    }
    if (strcmp(name, "snd_ctl_event_clear") == 0) {
        return (void *)snd_ctl_event_clear;
    }
    if (strcmp(name, "snd_ctl_event_copy") == 0) {
        return (void *)snd_ctl_event_copy;
    }
    if (strcmp(name, "snd_ctl_event_elem_get_device") == 0) {
        return (void *)snd_ctl_event_elem_get_device;
    }
    if (strcmp(name, "snd_ctl_event_elem_get_id") == 0) {
        return (void *)snd_ctl_event_elem_get_id;
    }
    if (strcmp(name, "snd_ctl_event_elem_get_index") == 0) {
        return (void *)snd_ctl_event_elem_get_index;
    }
    if (strcmp(name, "snd_ctl_event_elem_get_interface") == 0) {
        return (void *)snd_ctl_event_elem_get_interface;
    }
    if (strcmp(name, "snd_ctl_event_elem_get_mask") == 0) {
        return (void *)snd_ctl_event_elem_get_mask;
    }
    if (strcmp(name, "snd_ctl_event_elem_get_name") == 0) {
        return (void *)snd_ctl_event_elem_get_name;
    }
    if (strcmp(name, "snd_ctl_event_elem_get_numid") == 0) {
        return (void *)snd_ctl_event_elem_get_numid;
    }
    if (strcmp(name, "snd_ctl_event_elem_get_subdevice") == 0) {
        return (void *)snd_ctl_event_elem_get_subdevice;
    }
    if (strcmp(name, "snd_ctl_event_free") == 0) {
        return (void *)snd_ctl_event_free;
    }
    if (strcmp(name, "snd_ctl_event_get_type") == 0) {
        return (void *)snd_ctl_event_get_type;
    }
    if (strcmp(name, "snd_ctl_event_malloc") == 0) {
        return (void *)snd_ctl_event_malloc;
    }
    if (strcmp(name, "snd_ctl_event_sizeof") == 0) {
        return (void *)snd_ctl_event_sizeof;
    }
    if (strcmp(name, "snd_ctl_event_type_name") == 0) {
        return (void *)snd_ctl_event_type_name;
    }
    if (strcmp(name, "snd_ctl_get_power_state") == 0) {
        return (void *)snd_ctl_get_power_state;
    }
    if (strcmp(name, "snd_ctl_hwdep_info") == 0) {
        return (void *)snd_ctl_hwdep_info;
    }
    if (strcmp(name, "snd_ctl_hwdep_next_device") == 0) {
        return (void *)snd_ctl_hwdep_next_device;
    }
    if (strcmp(name, "snd_ctl_name") == 0) {
        return (void *)snd_ctl_name;
    }
    if (strcmp(name, "snd_ctl_nonblock") == 0) {
        return (void *)snd_ctl_nonblock;
    }
    if (strcmp(name, "snd_ctl_open") == 0) {
        return (void *)snd_ctl_open;
    }
    if (strcmp(name, "snd_ctl_open_lconf") == 0) {
        return (void *)snd_ctl_open_lconf;
    }
    if (strcmp(name, "snd_ctl_pcm_info") == 0) {
        return (void *)snd_ctl_pcm_info;
    }
    if (strcmp(name, "snd_ctl_pcm_next_device") == 0) {
        return (void *)snd_ctl_pcm_next_device;
    }
    if (strcmp(name, "snd_ctl_pcm_prefer_subdevice") == 0) {
        return (void *)snd_ctl_pcm_prefer_subdevice;
    }
    if (strcmp(name, "snd_ctl_poll_descriptors") == 0) {
        return (void *)snd_ctl_poll_descriptors;
    }
    if (strcmp(name, "snd_ctl_poll_descriptors_count") == 0) {
        return (void *)snd_ctl_poll_descriptors_count;
    }
    if (strcmp(name, "snd_ctl_poll_descriptors_revents") == 0) {
        return (void *)snd_ctl_poll_descriptors_revents;
    }
    if (strcmp(name, "snd_ctl_rawmidi_info") == 0) {
        return (void *)snd_ctl_rawmidi_info;
    }
    if (strcmp(name, "snd_ctl_rawmidi_next_device") == 0) {
        return (void *)snd_ctl_rawmidi_next_device;
    }
    if (strcmp(name, "snd_ctl_rawmidi_prefer_subdevice") == 0) {
        return (void *)snd_ctl_rawmidi_prefer_subdevice;
    }
    if (strcmp(name, "snd_ctl_read") == 0) {
        return (void *)snd_ctl_read;
    }
    if (strcmp(name, "snd_ctl_set_power_state") == 0) {
        return (void *)snd_ctl_set_power_state;
    }
    if (strcmp(name, "snd_ctl_subscribe_events") == 0) {
        return (void *)snd_ctl_subscribe_events;
    }
    if (strcmp(name, "snd_ctl_type") == 0) {
        return (void *)snd_ctl_type;
    }
    if (strcmp(name, "snd_ctl_wait") == 0) {
        return (void *)snd_ctl_wait;
    }
    if (strcmp(name, "snd_dlclose") == 0) {
        return (void *)snd_dlclose;
    }
    if (strcmp(name, "snd_dlopen") == 0) {
        return (void *)snd_dlopen;
    }
    if (strcmp(name, "snd_dlsym") == 0) {
        return (void *)snd_dlsym;
    }
    if (strcmp(name, "snd_hctl_close") == 0) {
        return (void *)snd_hctl_close;
    }
    if (strcmp(name, "snd_hctl_compare_fast") == 0) {
        return (void *)snd_hctl_compare_fast;
    }
    if (strcmp(name, "snd_hctl_ctl") == 0) {
        return (void *)snd_hctl_ctl;
    }
    if (strcmp(name, "snd_hctl_elem_get_callback_private") == 0) {
        return (void *)snd_hctl_elem_get_callback_private;
    }
    if (strcmp(name, "snd_hctl_elem_get_device") == 0) {
        return (void *)snd_hctl_elem_get_device;
    }
    if (strcmp(name, "snd_hctl_elem_get_hctl") == 0) {
        return (void *)snd_hctl_elem_get_hctl;
    }
    if (strcmp(name, "snd_hctl_elem_get_id") == 0) {
        return (void *)snd_hctl_elem_get_id;
    }
    if (strcmp(name, "snd_hctl_elem_get_index") == 0) {
        return (void *)snd_hctl_elem_get_index;
    }
    if (strcmp(name, "snd_hctl_elem_get_interface") == 0) {
        return (void *)snd_hctl_elem_get_interface;
    }
    if (strcmp(name, "snd_hctl_elem_get_name") == 0) {
        return (void *)snd_hctl_elem_get_name;
    }
    if (strcmp(name, "snd_hctl_elem_get_numid") == 0) {
        return (void *)snd_hctl_elem_get_numid;
    }
    if (strcmp(name, "snd_hctl_elem_get_subdevice") == 0) {
        return (void *)snd_hctl_elem_get_subdevice;
    }
    if (strcmp(name, "snd_hctl_elem_info") == 0) {
        return (void *)snd_hctl_elem_info;
    }
    if (strcmp(name, "snd_hctl_elem_next") == 0) {
        return (void *)snd_hctl_elem_next;
    }
    if (strcmp(name, "snd_hctl_elem_prev") == 0) {
        return (void *)snd_hctl_elem_prev;
    }
    if (strcmp(name, "snd_hctl_elem_read") == 0) {
        return (void *)snd_hctl_elem_read;
    }
    if (strcmp(name, "snd_hctl_elem_set_callback") == 0) {
        return (void *)snd_hctl_elem_set_callback;
    }
    if (strcmp(name, "snd_hctl_elem_set_callback_private") == 0) {
        return (void *)snd_hctl_elem_set_callback_private;
    }
    if (strcmp(name, "snd_hctl_elem_tlv_command") == 0) {
        return (void *)snd_hctl_elem_tlv_command;
    }
    if (strcmp(name, "snd_hctl_elem_tlv_read") == 0) {
        return (void *)snd_hctl_elem_tlv_read;
    }
    if (strcmp(name, "snd_hctl_elem_tlv_write") == 0) {
        return (void *)snd_hctl_elem_tlv_write;
    }
    if (strcmp(name, "snd_hctl_elem_write") == 0) {
        return (void *)snd_hctl_elem_write;
    }
    if (strcmp(name, "snd_hctl_find_elem") == 0) {
        return (void *)snd_hctl_find_elem;
    }
    if (strcmp(name, "snd_hctl_first_elem") == 0) {
        return (void *)snd_hctl_first_elem;
    }
    if (strcmp(name, "snd_hctl_free") == 0) {
        return (void *)snd_hctl_free;
    }
    if (strcmp(name, "snd_hctl_get_callback_private") == 0) {
        return (void *)snd_hctl_get_callback_private;
    }
    if (strcmp(name, "snd_hctl_get_count") == 0) {
        return (void *)snd_hctl_get_count;
    }
    if (strcmp(name, "snd_hctl_handle_events") == 0) {
        return (void *)snd_hctl_handle_events;
    }
    if (strcmp(name, "snd_hctl_last_elem") == 0) {
        return (void *)snd_hctl_last_elem;
    }
    if (strcmp(name, "snd_hctl_load") == 0) {
        return (void *)snd_hctl_load;
    }
    if (strcmp(name, "snd_hctl_name") == 0) {
        return (void *)snd_hctl_name;
    }
    if (strcmp(name, "snd_hctl_nonblock") == 0) {
        return (void *)snd_hctl_nonblock;
    }
    if (strcmp(name, "snd_hctl_open") == 0) {
        return (void *)snd_hctl_open;
    }
    if (strcmp(name, "snd_hctl_open_ctl") == 0) {
        return (void *)snd_hctl_open_ctl;
    }
    if (strcmp(name, "snd_hctl_poll_descriptors") == 0) {
        return (void *)snd_hctl_poll_descriptors;
    }
    if (strcmp(name, "snd_hctl_poll_descriptors_count") == 0) {
        return (void *)snd_hctl_poll_descriptors_count;
    }
    if (strcmp(name, "snd_hctl_poll_descriptors_revents") == 0) {
        return (void *)snd_hctl_poll_descriptors_revents;
    }
    if (strcmp(name, "snd_hctl_set_callback") == 0) {
        return (void *)snd_hctl_set_callback;
    }
    if (strcmp(name, "snd_hctl_set_callback_private") == 0) {
        return (void *)snd_hctl_set_callback_private;
    }
    if (strcmp(name, "snd_hctl_set_compare") == 0) {
        return (void *)snd_hctl_set_compare;
    }
    if (strcmp(name, "snd_hctl_wait") == 0) {
        return (void *)snd_hctl_wait;
    }
    if (strcmp(name, "snd_hwdep_close") == 0) {
        return (void *)snd_hwdep_close;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_copy") == 0) {
        return (void *)snd_hwdep_dsp_image_copy;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_free") == 0) {
        return (void *)snd_hwdep_dsp_image_free;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_get_image") == 0) {
        return (void *)snd_hwdep_dsp_image_get_image;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_get_index") == 0) {
        return (void *)snd_hwdep_dsp_image_get_index;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_get_length") == 0) {
        return (void *)snd_hwdep_dsp_image_get_length;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_get_name") == 0) {
        return (void *)snd_hwdep_dsp_image_get_name;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_malloc") == 0) {
        return (void *)snd_hwdep_dsp_image_malloc;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_set_image") == 0) {
        return (void *)snd_hwdep_dsp_image_set_image;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_set_index") == 0) {
        return (void *)snd_hwdep_dsp_image_set_index;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_set_length") == 0) {
        return (void *)snd_hwdep_dsp_image_set_length;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_set_name") == 0) {
        return (void *)snd_hwdep_dsp_image_set_name;
    }
    if (strcmp(name, "snd_hwdep_dsp_image_sizeof") == 0) {
        return (void *)snd_hwdep_dsp_image_sizeof;
    }
    if (strcmp(name, "snd_hwdep_dsp_load") == 0) {
        return (void *)snd_hwdep_dsp_load;
    }
    if (strcmp(name, "snd_hwdep_dsp_status") == 0) {
        return (void *)snd_hwdep_dsp_status;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_copy") == 0) {
        return (void *)snd_hwdep_dsp_status_copy;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_free") == 0) {
        return (void *)snd_hwdep_dsp_status_free;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_get_chip_ready") == 0) {
        return (void *)snd_hwdep_dsp_status_get_chip_ready;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_get_dsp_loaded") == 0) {
        return (void *)snd_hwdep_dsp_status_get_dsp_loaded;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_get_id") == 0) {
        return (void *)snd_hwdep_dsp_status_get_id;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_get_num_dsps") == 0) {
        return (void *)snd_hwdep_dsp_status_get_num_dsps;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_get_version") == 0) {
        return (void *)snd_hwdep_dsp_status_get_version;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_malloc") == 0) {
        return (void *)snd_hwdep_dsp_status_malloc;
    }
    if (strcmp(name, "snd_hwdep_dsp_status_sizeof") == 0) {
        return (void *)snd_hwdep_dsp_status_sizeof;
    }
    if (strcmp(name, "snd_hwdep_info") == 0) {
        return (void *)snd_hwdep_info;
    }
    if (strcmp(name, "snd_hwdep_info_sizeof") == 0) {
        return (void *)snd_hwdep_info_sizeof;
    }
    if (strcmp(name, "snd_hwdep_ioctl") == 0) {
        return (void *)snd_hwdep_ioctl;
    }
    if (strcmp(name, "snd_hwdep_nonblock") == 0) {
        return (void *)snd_hwdep_nonblock;
    }
    if (strcmp(name, "snd_hwdep_open") == 0) {
        return (void *)snd_hwdep_open;
    }
    if (strcmp(name, "snd_hwdep_poll_descriptors") == 0) {
        return (void *)snd_hwdep_poll_descriptors;
    }
    if (strcmp(name, "snd_hwdep_poll_descriptors_revents") == 0) {
        return (void *)snd_hwdep_poll_descriptors_revents;
    }
    if (strcmp(name, "snd_hwdep_read") == 0) {
        return (void *)snd_hwdep_read;
    }
    if (strcmp(name, "snd_hwdep_write") == 0) {
        return (void *)snd_hwdep_write;
    }
    if (strcmp(name, "snd_input_buffer_open") == 0) {
        return (void *)snd_input_buffer_open;
    }
    if (strcmp(name, "snd_input_close") == 0) {
        return (void *)snd_input_close;
    }
    if (strcmp(name, "snd_input_getc") == 0) {
        return (void *)snd_input_getc;
    }
    if (strcmp(name, "snd_input_gets") == 0) {
        return (void *)snd_input_gets;
    }
    if (strcmp(name, "snd_input_stdio_attach") == 0) {
        return (void *)snd_input_stdio_attach;
    }
    if (strcmp(name, "snd_input_stdio_open") == 0) {
        return (void *)snd_input_stdio_open;
    }
    if (strcmp(name, "snd_input_ungetc") == 0) {
        return (void *)snd_input_ungetc;
    }
    if (strcmp(name, "snd_lib_error_set_handler") == 0) {
        return (void *)snd_lib_error_set_handler;
    }
    if (strcmp(name, "snd_midi_event_decode") == 0) {
        return (void *)snd_midi_event_decode;
    }
    if (strcmp(name, "snd_midi_event_encode") == 0) {
        return (void *)snd_midi_event_encode;
    }
    if (strcmp(name, "snd_midi_event_encode_byte") == 0) {
        return (void *)snd_midi_event_encode_byte;
    }
    if (strcmp(name, "snd_midi_event_free") == 0) {
        return (void *)snd_midi_event_free;
    }
    if (strcmp(name, "snd_midi_event_init") == 0) {
        return (void *)snd_midi_event_init;
    }
    if (strcmp(name, "snd_midi_event_new") == 0) {
        return (void *)snd_midi_event_new;
    }
    if (strcmp(name, "snd_midi_event_no_status") == 0) {
        return (void *)snd_midi_event_no_status;
    }
    if (strcmp(name, "snd_midi_event_reset_decode") == 0) {
        return (void *)snd_midi_event_reset_decode;
    }
    if (strcmp(name, "snd_midi_event_reset_encode") == 0) {
        return (void *)snd_midi_event_reset_encode;
    }
    if (strcmp(name, "snd_midi_event_resize_buffer") == 0) {
        return (void *)snd_midi_event_resize_buffer;
    }
    if (strcmp(name, "snd_mixer_add_elem") == 0) {
        return (void *)snd_mixer_add_elem;
    }
    if (strcmp(name, "snd_mixer_attach") == 0) {
        return (void *)snd_mixer_attach;
    }
    if (strcmp(name, "snd_mixer_attach_hctl") == 0) {
        return (void *)snd_mixer_attach_hctl;
    }
    if (strcmp(name, "snd_mixer_class_copy") == 0) {
        return (void *)snd_mixer_class_copy;
    }
    if (strcmp(name, "snd_mixer_class_free") == 0) {
        return (void *)snd_mixer_class_free;
    }
    if (strcmp(name, "snd_mixer_class_get_compare") == 0) {
        return (void *)snd_mixer_class_get_compare;
    }
    if (strcmp(name, "snd_mixer_class_get_event") == 0) {
        return (void *)snd_mixer_class_get_event;
    }
    if (strcmp(name, "snd_mixer_class_get_mixer") == 0) {
        return (void *)snd_mixer_class_get_mixer;
    }
    if (strcmp(name, "snd_mixer_class_get_private") == 0) {
        return (void *)snd_mixer_class_get_private;
    }
    if (strcmp(name, "snd_mixer_class_malloc") == 0) {
        return (void *)snd_mixer_class_malloc;
    }
    if (strcmp(name, "snd_mixer_class_register") == 0) {
        return (void *)snd_mixer_class_register;
    }
    if (strcmp(name, "snd_mixer_class_set_compare") == 0) {
        return (void *)snd_mixer_class_set_compare;
    }
    if (strcmp(name, "snd_mixer_class_set_event") == 0) {
        return (void *)snd_mixer_class_set_event;
    }
    if (strcmp(name, "snd_mixer_class_set_private") == 0) {
        return (void *)snd_mixer_class_set_private;
    }
    if (strcmp(name, "snd_mixer_class_sizeof") == 0) {
        return (void *)snd_mixer_class_sizeof;
    }
    if (strcmp(name, "snd_mixer_class_unregister") == 0) {
        return (void *)snd_mixer_class_unregister;
    }
    if (strcmp(name, "snd_mixer_close") == 0) {
        return (void *)snd_mixer_close;
    }
    if (strcmp(name, "snd_mixer_detach") == 0) {
        return (void *)snd_mixer_detach;
    }
    if (strcmp(name, "snd_mixer_detach_hctl") == 0) {
        return (void *)snd_mixer_detach_hctl;
    }
    if (strcmp(name, "snd_mixer_elem_add") == 0) {
        return (void *)snd_mixer_elem_add;
    }
    if (strcmp(name, "snd_mixer_elem_attach") == 0) {
        return (void *)snd_mixer_elem_attach;
    }
    if (strcmp(name, "snd_mixer_elem_detach") == 0) {
        return (void *)snd_mixer_elem_detach;
    }
    if (strcmp(name, "snd_mixer_elem_empty") == 0) {
        return (void *)snd_mixer_elem_empty;
    }
    if (strcmp(name, "snd_mixer_elem_free") == 0) {
        return (void *)snd_mixer_elem_free;
    }
    if (strcmp(name, "snd_mixer_elem_get_callback_private") == 0) {
        return (void *)snd_mixer_elem_get_callback_private;
    }
    if (strcmp(name, "snd_mixer_elem_get_private") == 0) {
        return (void *)snd_mixer_elem_get_private;
    }
    if (strcmp(name, "snd_mixer_elem_get_type") == 0) {
        return (void *)snd_mixer_elem_get_type;
    }
    if (strcmp(name, "snd_mixer_elem_info") == 0) {
        return (void *)snd_mixer_elem_info;
    }
    if (strcmp(name, "snd_mixer_elem_next") == 0) {
        return (void *)snd_mixer_elem_next;
    }
    if (strcmp(name, "snd_mixer_elem_prev") == 0) {
        return (void *)snd_mixer_elem_prev;
    }
    if (strcmp(name, "snd_mixer_elem_remove") == 0) {
        return (void *)snd_mixer_elem_remove;
    }
    if (strcmp(name, "snd_mixer_elem_set_callback") == 0) {
        return (void *)snd_mixer_elem_set_callback;
    }
    if (strcmp(name, "snd_mixer_elem_set_callback_private") == 0) {
        return (void *)snd_mixer_elem_set_callback_private;
    }
    if (strcmp(name, "snd_mixer_elem_value") == 0) {
        return (void *)snd_mixer_elem_value;
    }
    if (strcmp(name, "snd_mixer_find_selem") == 0) {
        return (void *)snd_mixer_find_selem;
    }
    if (strcmp(name, "snd_mixer_first_elem") == 0) {
        return (void *)snd_mixer_first_elem;
    }
    if (strcmp(name, "snd_mixer_free") == 0) {
        return (void *)snd_mixer_free;
    }
    if (strcmp(name, "snd_mixer_get_callback_private") == 0) {
        return (void *)snd_mixer_get_callback_private;
    }
    if (strcmp(name, "snd_mixer_get_count") == 0) {
        return (void *)snd_mixer_get_count;
    }
    if (strcmp(name, "snd_mixer_get_hctl") == 0) {
        return (void *)snd_mixer_get_hctl;
    }
    if (strcmp(name, "snd_mixer_handle_events") == 0) {
        return (void *)snd_mixer_handle_events;
    }
    if (strcmp(name, "snd_mixer_last_elem") == 0) {
        return (void *)snd_mixer_last_elem;
    }
    if (strcmp(name, "snd_mixer_load") == 0) {
        return (void *)snd_mixer_load;
    }
    if (strcmp(name, "snd_mixer_open") == 0) {
        return (void *)snd_mixer_open;
    }
    if (strcmp(name, "snd_mixer_poll_descriptors") == 0) {
        return (void *)snd_mixer_poll_descriptors;
    }
    if (strcmp(name, "snd_mixer_poll_descriptors_count") == 0) {
        return (void *)snd_mixer_poll_descriptors_count;
    }
    if (strcmp(name, "snd_mixer_poll_descriptors_revents") == 0) {
        return (void *)snd_mixer_poll_descriptors_revents;
    }
    if (strcmp(name, "snd_mixer_remove_elem") == 0) {
        return (void *)snd_mixer_remove_elem;
    }
    if (strcmp(name, "snd_mixer_selem_channel_name") == 0) {
        return (void *)snd_mixer_selem_channel_name;
    }
    if (strcmp(name, "snd_mixer_selem_get_capture_dB") == 0) {
        return (void *)snd_mixer_selem_get_capture_dB;
    }
    if (strcmp(name, "snd_mixer_selem_get_capture_dB_range") == 0) {
        return (void *)snd_mixer_selem_get_capture_dB_range;
    }
    if (strcmp(name, "snd_mixer_selem_get_capture_group") == 0) {
        return (void *)snd_mixer_selem_get_capture_group;
    }
    if (strcmp(name, "snd_mixer_selem_get_capture_switch") == 0) {
        return (void *)snd_mixer_selem_get_capture_switch;
    }
    if (strcmp(name, "snd_mixer_selem_get_capture_volume") == 0) {
        return (void *)snd_mixer_selem_get_capture_volume;
    }
    if (strcmp(name, "snd_mixer_selem_get_capture_volume_range") == 0) {
        return (void *)snd_mixer_selem_get_capture_volume_range;
    }
    if (strcmp(name, "snd_mixer_selem_get_enum_item") == 0) {
        return (void *)snd_mixer_selem_get_enum_item;
    }
    if (strcmp(name, "snd_mixer_selem_get_enum_item_name") == 0) {
        return (void *)snd_mixer_selem_get_enum_item_name;
    }
    if (strcmp(name, "snd_mixer_selem_get_enum_items") == 0) {
        return (void *)snd_mixer_selem_get_enum_items;
    }
    if (strcmp(name, "snd_mixer_selem_get_id") == 0) {
        return (void *)snd_mixer_selem_get_id;
    }
    if (strcmp(name, "snd_mixer_selem_get_index") == 0) {
        return (void *)snd_mixer_selem_get_index;
    }
    if (strcmp(name, "snd_mixer_selem_get_name") == 0) {
        return (void *)snd_mixer_selem_get_name;
    }
    if (strcmp(name, "snd_mixer_selem_get_playback_dB") == 0) {
        return (void *)snd_mixer_selem_get_playback_dB;
    }
    if (strcmp(name, "snd_mixer_selem_get_playback_dB_range") == 0) {
        return (void *)snd_mixer_selem_get_playback_dB_range;
    }
    if (strcmp(name, "snd_mixer_selem_get_playback_switch") == 0) {
        return (void *)snd_mixer_selem_get_playback_switch;
    }
    if (strcmp(name, "snd_mixer_selem_get_playback_volume") == 0) {
        return (void *)snd_mixer_selem_get_playback_volume;
    }
    if (strcmp(name, "snd_mixer_selem_get_playback_volume_range") == 0) {
        return (void *)snd_mixer_selem_get_playback_volume_range;
    }
    if (strcmp(name, "snd_mixer_selem_has_capture_channel") == 0) {
        return (void *)snd_mixer_selem_has_capture_channel;
    }
    if (strcmp(name, "snd_mixer_selem_has_capture_switch") == 0) {
        return (void *)snd_mixer_selem_has_capture_switch;
    }
    if (strcmp(name, "snd_mixer_selem_has_capture_switch_exclusive") == 0) {
        return (void *)snd_mixer_selem_has_capture_switch_exclusive;
    }
    if (strcmp(name, "snd_mixer_selem_has_capture_switch_joined") == 0) {
        return (void *)snd_mixer_selem_has_capture_switch_joined;
    }
    if (strcmp(name, "snd_mixer_selem_has_capture_volume") == 0) {
        return (void *)snd_mixer_selem_has_capture_volume;
    }
    if (strcmp(name, "snd_mixer_selem_has_capture_volume_joined") == 0) {
        return (void *)snd_mixer_selem_has_capture_volume_joined;
    }
    if (strcmp(name, "snd_mixer_selem_has_common_switch") == 0) {
        return (void *)snd_mixer_selem_has_common_switch;
    }
    if (strcmp(name, "snd_mixer_selem_has_common_volume") == 0) {
        return (void *)snd_mixer_selem_has_common_volume;
    }
    if (strcmp(name, "snd_mixer_selem_has_playback_channel") == 0) {
        return (void *)snd_mixer_selem_has_playback_channel;
    }
    if (strcmp(name, "snd_mixer_selem_has_playback_switch") == 0) {
        return (void *)snd_mixer_selem_has_playback_switch;
    }
    if (strcmp(name, "snd_mixer_selem_has_playback_switch_joined") == 0) {
        return (void *)snd_mixer_selem_has_playback_switch_joined;
    }
    if (strcmp(name, "snd_mixer_selem_has_playback_volume") == 0) {
        return (void *)snd_mixer_selem_has_playback_volume;
    }
    if (strcmp(name, "snd_mixer_selem_has_playback_volume_joined") == 0) {
        return (void *)snd_mixer_selem_has_playback_volume_joined;
    }
    if (strcmp(name, "snd_mixer_selem_id_copy") == 0) {
        return (void *)snd_mixer_selem_id_copy;
    }
    if (strcmp(name, "snd_mixer_selem_id_free") == 0) {
        return (void *)snd_mixer_selem_id_free;
    }
    if (strcmp(name, "snd_mixer_selem_id_get_index") == 0) {
        return (void *)snd_mixer_selem_id_get_index;
    }
    if (strcmp(name, "snd_mixer_selem_id_get_name") == 0) {
        return (void *)snd_mixer_selem_id_get_name;
    }
    if (strcmp(name, "snd_mixer_selem_id_malloc") == 0) {
        return (void *)snd_mixer_selem_id_malloc;
    }
    if (strcmp(name, "snd_mixer_selem_id_set_index") == 0) {
        return (void *)snd_mixer_selem_id_set_index;
    }
    if (strcmp(name, "snd_mixer_selem_id_set_name") == 0) {
        return (void *)snd_mixer_selem_id_set_name;
    }
    if (strcmp(name, "snd_mixer_selem_id_sizeof") == 0) {
        return (void *)snd_mixer_selem_id_sizeof;
    }
    if (strcmp(name, "snd_mixer_selem_is_active") == 0) {
        return (void *)snd_mixer_selem_is_active;
    }
    if (strcmp(name, "snd_mixer_selem_is_capture_mono") == 0) {
        return (void *)snd_mixer_selem_is_capture_mono;
    }
    if (strcmp(name, "snd_mixer_selem_is_enum_capture") == 0) {
        return (void *)snd_mixer_selem_is_enum_capture;
    }
    if (strcmp(name, "snd_mixer_selem_is_enum_playback") == 0) {
        return (void *)snd_mixer_selem_is_enum_playback;
    }
    if (strcmp(name, "snd_mixer_selem_is_enumerated") == 0) {
        return (void *)snd_mixer_selem_is_enumerated;
    }
    if (strcmp(name, "snd_mixer_selem_is_playback_mono") == 0) {
        return (void *)snd_mixer_selem_is_playback_mono;
    }
    if (strcmp(name, "snd_mixer_selem_register") == 0) {
        return (void *)snd_mixer_selem_register;
    }
    if (strcmp(name, "snd_mixer_selem_set_capture_dB") == 0) {
        return (void *)snd_mixer_selem_set_capture_dB;
    }
    if (strcmp(name, "snd_mixer_selem_set_capture_dB_all") == 0) {
        return (void *)snd_mixer_selem_set_capture_dB_all;
    }
    if (strcmp(name, "snd_mixer_selem_set_capture_switch") == 0) {
        return (void *)snd_mixer_selem_set_capture_switch;
    }
    if (strcmp(name, "snd_mixer_selem_set_capture_switch_all") == 0) {
        return (void *)snd_mixer_selem_set_capture_switch_all;
    }
    if (strcmp(name, "snd_mixer_selem_set_capture_volume") == 0) {
        return (void *)snd_mixer_selem_set_capture_volume;
    }
    if (strcmp(name, "snd_mixer_selem_set_capture_volume_all") == 0) {
        return (void *)snd_mixer_selem_set_capture_volume_all;
    }
    if (strcmp(name, "snd_mixer_selem_set_capture_volume_range") == 0) {
        return (void *)snd_mixer_selem_set_capture_volume_range;
    }
    if (strcmp(name, "snd_mixer_selem_set_enum_item") == 0) {
        return (void *)snd_mixer_selem_set_enum_item;
    }
    if (strcmp(name, "snd_mixer_selem_set_playback_dB") == 0) {
        return (void *)snd_mixer_selem_set_playback_dB;
    }
    if (strcmp(name, "snd_mixer_selem_set_playback_dB_all") == 0) {
        return (void *)snd_mixer_selem_set_playback_dB_all;
    }
    if (strcmp(name, "snd_mixer_selem_set_playback_switch") == 0) {
        return (void *)snd_mixer_selem_set_playback_switch;
    }
    if (strcmp(name, "snd_mixer_selem_set_playback_switch_all") == 0) {
        return (void *)snd_mixer_selem_set_playback_switch_all;
    }
    if (strcmp(name, "snd_mixer_selem_set_playback_volume") == 0) {
        return (void *)snd_mixer_selem_set_playback_volume;
    }
    if (strcmp(name, "snd_mixer_selem_set_playback_volume_all") == 0) {
        return (void *)snd_mixer_selem_set_playback_volume_all;
    }
    if (strcmp(name, "snd_mixer_selem_set_playback_volume_range") == 0) {
        return (void *)snd_mixer_selem_set_playback_volume_range;
    }
    if (strcmp(name, "snd_mixer_set_callback") == 0) {
        return (void *)snd_mixer_set_callback;
    }
    if (strcmp(name, "snd_mixer_set_callback_private") == 0) {
        return (void *)snd_mixer_set_callback_private;
    }
    if (strcmp(name, "snd_mixer_set_compare") == 0) {
        return (void *)snd_mixer_set_compare;
    }
    if (strcmp(name, "snd_mixer_wait") == 0) {
        return (void *)snd_mixer_wait;
    }
    if (strcmp(name, "snd_names_list") == 0) {
        return (void *)snd_names_list;
    }
    if (strcmp(name, "snd_names_list_free") == 0) {
        return (void *)snd_names_list_free;
    }
    if (strcmp(name, "snd_output_buffer_open") == 0) {
        return (void *)snd_output_buffer_open;
    }
    if (strcmp(name, "snd_output_buffer_string") == 0) {
        return (void *)snd_output_buffer_string;
    }
    if (strcmp(name, "snd_output_close") == 0) {
        return (void *)snd_output_close;
    }
    if (strcmp(name, "snd_output_flush") == 0) {
        return (void *)snd_output_flush;
    }
    if (strcmp(name, "snd_output_putc") == 0) {
        return (void *)snd_output_putc;
    }
    if (strcmp(name, "snd_output_puts") == 0) {
        return (void *)snd_output_puts;
    }
    if (strcmp(name, "snd_output_stdio_attach") == 0) {
        return (void *)snd_output_stdio_attach;
    }
    if (strcmp(name, "snd_output_stdio_open") == 0) {
        return (void *)snd_output_stdio_open;
    }
    if (strcmp(name, "snd_output_vprintf") == 0) {
        return (void *)snd_output_vprintf;
    }
    if (strcmp(name, "snd_pcm_access_mask_any") == 0) {
        return (void *)snd_pcm_access_mask_any;
    }
    if (strcmp(name, "snd_pcm_access_mask_copy") == 0) {
        return (void *)snd_pcm_access_mask_copy;
    }
    if (strcmp(name, "snd_pcm_access_mask_empty") == 0) {
        return (void *)snd_pcm_access_mask_empty;
    }
    if (strcmp(name, "snd_pcm_access_mask_free") == 0) {
        return (void *)snd_pcm_access_mask_free;
    }
    if (strcmp(name, "snd_pcm_access_mask_malloc") == 0) {
        return (void *)snd_pcm_access_mask_malloc;
    }
    if (strcmp(name, "snd_pcm_access_mask_none") == 0) {
        return (void *)snd_pcm_access_mask_none;
    }
    if (strcmp(name, "snd_pcm_access_mask_reset") == 0) {
        return (void *)snd_pcm_access_mask_reset;
    }
    if (strcmp(name, "snd_pcm_access_mask_set") == 0) {
        return (void *)snd_pcm_access_mask_set;
    }
    if (strcmp(name, "snd_pcm_access_mask_test") == 0) {
        return (void *)snd_pcm_access_mask_test;
    }
    if (strcmp(name, "snd_pcm_access_name") == 0) {
        return (void *)snd_pcm_access_name;
    }
    if (strcmp(name, "snd_pcm_area_copy") == 0) {
        return (void *)snd_pcm_area_copy;
    }
    if (strcmp(name, "snd_pcm_area_silence") == 0) {
        return (void *)snd_pcm_area_silence;
    }
    if (strcmp(name, "snd_pcm_areas_copy") == 0) {
        return (void *)snd_pcm_areas_copy;
    }
    if (strcmp(name, "snd_pcm_areas_silence") == 0) {
        return (void *)snd_pcm_areas_silence;
    }
    if (strcmp(name, "snd_pcm_avail_update") == 0) {
        return (void *)snd_pcm_avail_update;
    }
    if (strcmp(name, "snd_pcm_build_linear_format") == 0) {
        return (void *)snd_pcm_build_linear_format;
    }
    if (strcmp(name, "snd_pcm_bytes_to_frames") == 0) {
        return (void *)snd_pcm_bytes_to_frames;
    }
    if (strcmp(name, "snd_pcm_bytes_to_samples") == 0) {
        return (void *)snd_pcm_bytes_to_samples;
    }
    if (strcmp(name, "snd_pcm_close") == 0) {
        return (void *)snd_pcm_close;
    }
    if (strcmp(name, "snd_pcm_delay") == 0) {
        return (void *)snd_pcm_delay;
    }
    if (strcmp(name, "snd_pcm_drain") == 0) {
        return (void *)snd_pcm_drain;
    }
    if (strcmp(name, "snd_pcm_drop") == 0) {
        return (void *)snd_pcm_drop;
    }
    if (strcmp(name, "snd_pcm_dump") == 0) {
        return (void *)snd_pcm_dump;
    }
    if (strcmp(name, "snd_pcm_dump_hw_setup") == 0) {
        return (void *)snd_pcm_dump_hw_setup;
    }
    if (strcmp(name, "snd_pcm_dump_setup") == 0) {
        return (void *)snd_pcm_dump_setup;
    }
    if (strcmp(name, "snd_pcm_dump_sw_setup") == 0) {
        return (void *)snd_pcm_dump_sw_setup;
    }
    if (strcmp(name, "snd_pcm_format_big_endian") == 0) {
        return (void *)snd_pcm_format_big_endian;
    }
    if (strcmp(name, "snd_pcm_format_cpu_endian") == 0) {
        return (void *)snd_pcm_format_cpu_endian;
    }
    if (strcmp(name, "snd_pcm_format_description") == 0) {
        return (void *)snd_pcm_format_description;
    }
    if (strcmp(name, "snd_pcm_format_float") == 0) {
        return (void *)snd_pcm_format_float;
    }
    if (strcmp(name, "snd_pcm_format_linear") == 0) {
        return (void *)snd_pcm_format_linear;
    }
    if (strcmp(name, "snd_pcm_format_little_endian") == 0) {
        return (void *)snd_pcm_format_little_endian;
    }
    if (strcmp(name, "snd_pcm_format_mask_any") == 0) {
        return (void *)snd_pcm_format_mask_any;
    }
    if (strcmp(name, "snd_pcm_format_mask_copy") == 0) {
        return (void *)snd_pcm_format_mask_copy;
    }
    if (strcmp(name, "snd_pcm_format_mask_empty") == 0) {
        return (void *)snd_pcm_format_mask_empty;
    }
    if (strcmp(name, "snd_pcm_format_mask_free") == 0) {
        return (void *)snd_pcm_format_mask_free;
    }
    if (strcmp(name, "snd_pcm_format_mask_malloc") == 0) {
        return (void *)snd_pcm_format_mask_malloc;
    }
    if (strcmp(name, "snd_pcm_format_mask_none") == 0) {
        return (void *)snd_pcm_format_mask_none;
    }
    if (strcmp(name, "snd_pcm_format_mask_reset") == 0) {
        return (void *)snd_pcm_format_mask_reset;
    }
    if (strcmp(name, "snd_pcm_format_mask_set") == 0) {
        return (void *)snd_pcm_format_mask_set;
    }
    if (strcmp(name, "snd_pcm_format_mask_test") == 0) {
        return (void *)snd_pcm_format_mask_test;
    }
    if (strcmp(name, "snd_pcm_format_name") == 0) {
        return (void *)snd_pcm_format_name;
    }
    if (strcmp(name, "snd_pcm_format_physical_width") == 0) {
        return (void *)snd_pcm_format_physical_width;
    }
    if (strcmp(name, "snd_pcm_format_set_silence") == 0) {
        return (void *)snd_pcm_format_set_silence;
    }
    if (strcmp(name, "snd_pcm_format_signed") == 0) {
        return (void *)snd_pcm_format_signed;
    }
    if (strcmp(name, "snd_pcm_format_silence") == 0) {
        return (void *)snd_pcm_format_silence;
    }
    if (strcmp(name, "snd_pcm_format_silence_16") == 0) {
        return (void *)snd_pcm_format_silence_16;
    }
    if (strcmp(name, "snd_pcm_format_silence_32") == 0) {
        return (void *)snd_pcm_format_silence_32;
    }
    if (strcmp(name, "snd_pcm_format_silence_64") == 0) {
        return (void *)snd_pcm_format_silence_64;
    }
    if (strcmp(name, "snd_pcm_format_size") == 0) {
        return (void *)snd_pcm_format_size;
    }
    if (strcmp(name, "snd_pcm_format_unsigned") == 0) {
        return (void *)snd_pcm_format_unsigned;
    }
    if (strcmp(name, "snd_pcm_format_value") == 0) {
        return (void *)snd_pcm_format_value;
    }
    if (strcmp(name, "snd_pcm_format_width") == 0) {
        return (void *)snd_pcm_format_width;
    }
    if (strcmp(name, "snd_pcm_forward") == 0) {
        return (void *)snd_pcm_forward;
    }
    if (strcmp(name, "snd_pcm_frames_to_bytes") == 0) {
        return (void *)snd_pcm_frames_to_bytes;
    }
    if (strcmp(name, "snd_pcm_get_params") == 0) {
        return (void *)snd_pcm_get_params;
    }
    if (strcmp(name, "snd_pcm_hook_add") == 0) {
        return (void *)snd_pcm_hook_add;
    }
    if (strcmp(name, "snd_pcm_hook_get_pcm") == 0) {
        return (void *)snd_pcm_hook_get_pcm;
    }
    if (strcmp(name, "snd_pcm_hook_get_private") == 0) {
        return (void *)snd_pcm_hook_get_private;
    }
    if (strcmp(name, "snd_pcm_hook_remove") == 0) {
        return (void *)snd_pcm_hook_remove;
    }
    if (strcmp(name, "snd_pcm_hook_set_private") == 0) {
        return (void *)snd_pcm_hook_set_private;
    }
    if (strcmp(name, "snd_pcm_hw_free") == 0) {
        return (void *)snd_pcm_hw_free;
    }
    if (strcmp(name, "snd_pcm_hw_params") == 0) {
        return (void *)snd_pcm_hw_params;
    }
    if (strcmp(name, "snd_pcm_hw_params_any") == 0) {
        return (void *)snd_pcm_hw_params_any;
    }
    if (strcmp(name, "snd_pcm_hw_params_can_mmap_sample_resolution") == 0) {
        return (void *)snd_pcm_hw_params_can_mmap_sample_resolution;
    }
    if (strcmp(name, "snd_pcm_hw_params_can_overrange") == 0) {
        return (void *)snd_pcm_hw_params_can_overrange;
    }
    if (strcmp(name, "snd_pcm_hw_params_can_pause") == 0) {
        return (void *)snd_pcm_hw_params_can_pause;
    }
    if (strcmp(name, "snd_pcm_hw_params_can_resume") == 0) {
        return (void *)snd_pcm_hw_params_can_resume;
    }
    if (strcmp(name, "snd_pcm_hw_params_can_sync_start") == 0) {
        return (void *)snd_pcm_hw_params_can_sync_start;
    }
    if (strcmp(name, "snd_pcm_hw_params_copy") == 0) {
        return (void *)snd_pcm_hw_params_copy;
    }
    if (strcmp(name, "snd_pcm_hw_params_current") == 0) {
        return (void *)snd_pcm_hw_params_current;
    }
    if (strcmp(name, "snd_pcm_hw_params_dump") == 0) {
        return (void *)snd_pcm_hw_params_dump;
    }
    if (strcmp(name, "snd_pcm_hw_params_free") == 0) {
        return (void *)snd_pcm_hw_params_free;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_access") == 0) {
        return (void *)snd_pcm_hw_params_get_access;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_access_mask") == 0) {
        return (void *)snd_pcm_hw_params_get_access_mask;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_buffer_size") == 0) {
        return (void *)snd_pcm_hw_params_get_buffer_size;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_buffer_size_max") == 0) {
        return (void *)snd_pcm_hw_params_get_buffer_size_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_buffer_size_min") == 0) {
        return (void *)snd_pcm_hw_params_get_buffer_size_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_buffer_time") == 0) {
        return (void *)snd_pcm_hw_params_get_buffer_time;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_buffer_time_max") == 0) {
        return (void *)snd_pcm_hw_params_get_buffer_time_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_buffer_time_min") == 0) {
        return (void *)snd_pcm_hw_params_get_buffer_time_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_channels") == 0) {
        return (void *)snd_pcm_hw_params_get_channels;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_channels_max") == 0) {
        return (void *)snd_pcm_hw_params_get_channels_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_channels_min") == 0) {
        return (void *)snd_pcm_hw_params_get_channels_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_export_buffer") == 0) {
        return (void *)snd_pcm_hw_params_get_export_buffer;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_fifo_size") == 0) {
        return (void *)snd_pcm_hw_params_get_fifo_size;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_format") == 0) {
        return (void *)snd_pcm_hw_params_get_format;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_format_mask") == 0) {
        return (void *)snd_pcm_hw_params_get_format_mask;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_min_align") == 0) {
        return (void *)snd_pcm_hw_params_get_min_align;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_period_size") == 0) {
        return (void *)snd_pcm_hw_params_get_period_size;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_period_size_max") == 0) {
        return (void *)snd_pcm_hw_params_get_period_size_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_period_size_min") == 0) {
        return (void *)snd_pcm_hw_params_get_period_size_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_period_time") == 0) {
        return (void *)snd_pcm_hw_params_get_period_time;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_period_time_max") == 0) {
        return (void *)snd_pcm_hw_params_get_period_time_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_period_time_min") == 0) {
        return (void *)snd_pcm_hw_params_get_period_time_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_periods") == 0) {
        return (void *)snd_pcm_hw_params_get_periods;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_periods_max") == 0) {
        return (void *)snd_pcm_hw_params_get_periods_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_periods_min") == 0) {
        return (void *)snd_pcm_hw_params_get_periods_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_rate") == 0) {
        return (void *)snd_pcm_hw_params_get_rate;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_rate_max") == 0) {
        return (void *)snd_pcm_hw_params_get_rate_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_rate_min") == 0) {
        return (void *)snd_pcm_hw_params_get_rate_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_rate_numden") == 0) {
        return (void *)snd_pcm_hw_params_get_rate_numden;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_rate_resample") == 0) {
        return (void *)snd_pcm_hw_params_get_rate_resample;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_sbits") == 0) {
        return (void *)snd_pcm_hw_params_get_sbits;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_subformat") == 0) {
        return (void *)snd_pcm_hw_params_get_subformat;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_subformat_mask") == 0) {
        return (void *)snd_pcm_hw_params_get_subformat_mask;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_tick_time") == 0) {
        return (void *)snd_pcm_hw_params_get_tick_time;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_tick_time_max") == 0) {
        return (void *)snd_pcm_hw_params_get_tick_time_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_get_tick_time_min") == 0) {
        return (void *)snd_pcm_hw_params_get_tick_time_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_is_batch") == 0) {
        return (void *)snd_pcm_hw_params_is_batch;
    }
    if (strcmp(name, "snd_pcm_hw_params_is_block_transfer") == 0) {
        return (void *)snd_pcm_hw_params_is_block_transfer;
    }
    if (strcmp(name, "snd_pcm_hw_params_is_double") == 0) {
        return (void *)snd_pcm_hw_params_is_double;
    }
    if (strcmp(name, "snd_pcm_hw_params_is_half_duplex") == 0) {
        return (void *)snd_pcm_hw_params_is_half_duplex;
    }
    if (strcmp(name, "snd_pcm_hw_params_is_joint_duplex") == 0) {
        return (void *)snd_pcm_hw_params_is_joint_duplex;
    }
    if (strcmp(name, "snd_pcm_hw_params_malloc") == 0) {
        return (void *)snd_pcm_hw_params_malloc;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_access") == 0) {
        return (void *)snd_pcm_hw_params_set_access;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_access_first") == 0) {
        return (void *)snd_pcm_hw_params_set_access_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_access_last") == 0) {
        return (void *)snd_pcm_hw_params_set_access_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_access_mask") == 0) {
        return (void *)snd_pcm_hw_params_set_access_mask;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_size") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_size;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_size_first") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_size_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_size_last") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_size_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_size_max") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_size_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_size_min") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_size_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_size_minmax") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_size_minmax;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_size_near") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_size_near;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_time") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_time;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_time_first") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_time_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_time_last") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_time_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_time_max") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_time_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_time_min") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_time_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_time_minmax") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_time_minmax;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_buffer_time_near") == 0) {
        return (void *)snd_pcm_hw_params_set_buffer_time_near;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_channels") == 0) {
        return (void *)snd_pcm_hw_params_set_channels;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_channels_first") == 0) {
        return (void *)snd_pcm_hw_params_set_channels_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_channels_last") == 0) {
        return (void *)snd_pcm_hw_params_set_channels_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_channels_max") == 0) {
        return (void *)snd_pcm_hw_params_set_channels_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_channels_min") == 0) {
        return (void *)snd_pcm_hw_params_set_channels_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_channels_minmax") == 0) {
        return (void *)snd_pcm_hw_params_set_channels_minmax;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_channels_near") == 0) {
        return (void *)snd_pcm_hw_params_set_channels_near;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_export_buffer") == 0) {
        return (void *)snd_pcm_hw_params_set_export_buffer;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_format") == 0) {
        return (void *)snd_pcm_hw_params_set_format;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_format_first") == 0) {
        return (void *)snd_pcm_hw_params_set_format_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_format_last") == 0) {
        return (void *)snd_pcm_hw_params_set_format_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_format_mask") == 0) {
        return (void *)snd_pcm_hw_params_set_format_mask;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_size") == 0) {
        return (void *)snd_pcm_hw_params_set_period_size;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_size_first") == 0) {
        return (void *)snd_pcm_hw_params_set_period_size_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_size_integer") == 0) {
        return (void *)snd_pcm_hw_params_set_period_size_integer;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_size_last") == 0) {
        return (void *)snd_pcm_hw_params_set_period_size_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_size_max") == 0) {
        return (void *)snd_pcm_hw_params_set_period_size_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_size_min") == 0) {
        return (void *)snd_pcm_hw_params_set_period_size_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_size_minmax") == 0) {
        return (void *)snd_pcm_hw_params_set_period_size_minmax;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_size_near") == 0) {
        return (void *)snd_pcm_hw_params_set_period_size_near;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_time") == 0) {
        return (void *)snd_pcm_hw_params_set_period_time;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_time_first") == 0) {
        return (void *)snd_pcm_hw_params_set_period_time_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_time_last") == 0) {
        return (void *)snd_pcm_hw_params_set_period_time_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_time_max") == 0) {
        return (void *)snd_pcm_hw_params_set_period_time_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_time_min") == 0) {
        return (void *)snd_pcm_hw_params_set_period_time_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_time_minmax") == 0) {
        return (void *)snd_pcm_hw_params_set_period_time_minmax;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_period_time_near") == 0) {
        return (void *)snd_pcm_hw_params_set_period_time_near;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_periods") == 0) {
        return (void *)snd_pcm_hw_params_set_periods;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_periods_first") == 0) {
        return (void *)snd_pcm_hw_params_set_periods_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_periods_integer") == 0) {
        return (void *)snd_pcm_hw_params_set_periods_integer;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_periods_last") == 0) {
        return (void *)snd_pcm_hw_params_set_periods_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_periods_max") == 0) {
        return (void *)snd_pcm_hw_params_set_periods_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_periods_min") == 0) {
        return (void *)snd_pcm_hw_params_set_periods_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_periods_minmax") == 0) {
        return (void *)snd_pcm_hw_params_set_periods_minmax;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_periods_near") == 0) {
        return (void *)snd_pcm_hw_params_set_periods_near;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_rate") == 0) {
        return (void *)snd_pcm_hw_params_set_rate;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_rate_first") == 0) {
        return (void *)snd_pcm_hw_params_set_rate_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_rate_last") == 0) {
        return (void *)snd_pcm_hw_params_set_rate_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_rate_max") == 0) {
        return (void *)snd_pcm_hw_params_set_rate_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_rate_min") == 0) {
        return (void *)snd_pcm_hw_params_set_rate_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_rate_minmax") == 0) {
        return (void *)snd_pcm_hw_params_set_rate_minmax;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_rate_near") == 0) {
        return (void *)snd_pcm_hw_params_set_rate_near;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_rate_resample") == 0) {
        return (void *)snd_pcm_hw_params_set_rate_resample;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_subformat") == 0) {
        return (void *)snd_pcm_hw_params_set_subformat;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_subformat_first") == 0) {
        return (void *)snd_pcm_hw_params_set_subformat_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_subformat_last") == 0) {
        return (void *)snd_pcm_hw_params_set_subformat_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_subformat_mask") == 0) {
        return (void *)snd_pcm_hw_params_set_subformat_mask;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_tick_time") == 0) {
        return (void *)snd_pcm_hw_params_set_tick_time;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_tick_time_first") == 0) {
        return (void *)snd_pcm_hw_params_set_tick_time_first;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_tick_time_last") == 0) {
        return (void *)snd_pcm_hw_params_set_tick_time_last;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_tick_time_max") == 0) {
        return (void *)snd_pcm_hw_params_set_tick_time_max;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_tick_time_min") == 0) {
        return (void *)snd_pcm_hw_params_set_tick_time_min;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_tick_time_minmax") == 0) {
        return (void *)snd_pcm_hw_params_set_tick_time_minmax;
    }
    if (strcmp(name, "snd_pcm_hw_params_set_tick_time_near") == 0) {
        return (void *)snd_pcm_hw_params_set_tick_time_near;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_access") == 0) {
        return (void *)snd_pcm_hw_params_test_access;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_buffer_size") == 0) {
        return (void *)snd_pcm_hw_params_test_buffer_size;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_buffer_time") == 0) {
        return (void *)snd_pcm_hw_params_test_buffer_time;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_channels") == 0) {
        return (void *)snd_pcm_hw_params_test_channels;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_format") == 0) {
        return (void *)snd_pcm_hw_params_test_format;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_period_size") == 0) {
        return (void *)snd_pcm_hw_params_test_period_size;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_period_time") == 0) {
        return (void *)snd_pcm_hw_params_test_period_time;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_periods") == 0) {
        return (void *)snd_pcm_hw_params_test_periods;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_rate") == 0) {
        return (void *)snd_pcm_hw_params_test_rate;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_subformat") == 0) {
        return (void *)snd_pcm_hw_params_test_subformat;
    }
    if (strcmp(name, "snd_pcm_hw_params_test_tick_time") == 0) {
        return (void *)snd_pcm_hw_params_test_tick_time;
    }
    if (strcmp(name, "snd_pcm_hwsync") == 0) {
        return (void *)snd_pcm_hwsync;
    }
    if (strcmp(name, "snd_pcm_info") == 0) {
        return (void *)snd_pcm_info;
    }
    if (strcmp(name, "snd_pcm_info_copy") == 0) {
        return (void *)snd_pcm_info_copy;
    }
    if (strcmp(name, "snd_pcm_info_free") == 0) {
        return (void *)snd_pcm_info_free;
    }
    if (strcmp(name, "snd_pcm_info_get_card") == 0) {
        return (void *)snd_pcm_info_get_card;
    }
    if (strcmp(name, "snd_pcm_info_get_class") == 0) {
        return (void *)snd_pcm_info_get_class;
    }
    if (strcmp(name, "snd_pcm_info_get_device") == 0) {
        return (void *)snd_pcm_info_get_device;
    }
    if (strcmp(name, "snd_pcm_info_get_id") == 0) {
        return (void *)snd_pcm_info_get_id;
    }
    if (strcmp(name, "snd_pcm_info_get_name") == 0) {
        return (void *)snd_pcm_info_get_name;
    }
    if (strcmp(name, "snd_pcm_info_get_stream") == 0) {
        return (void *)snd_pcm_info_get_stream;
    }
    if (strcmp(name, "snd_pcm_info_get_subclass") == 0) {
        return (void *)snd_pcm_info_get_subclass;
    }
    if (strcmp(name, "snd_pcm_info_get_subdevice") == 0) {
        return (void *)snd_pcm_info_get_subdevice;
    }
    if (strcmp(name, "snd_pcm_info_get_subdevice_name") == 0) {
        return (void *)snd_pcm_info_get_subdevice_name;
    }
    if (strcmp(name, "snd_pcm_info_get_subdevices_avail") == 0) {
        return (void *)snd_pcm_info_get_subdevices_avail;
    }
    if (strcmp(name, "snd_pcm_info_get_subdevices_count") == 0) {
        return (void *)snd_pcm_info_get_subdevices_count;
    }
    if (strcmp(name, "snd_pcm_info_get_sync") == 0) {
        return (void *)snd_pcm_info_get_sync;
    }
    if (strcmp(name, "snd_pcm_info_malloc") == 0) {
        return (void *)snd_pcm_info_malloc;
    }
    if (strcmp(name, "snd_pcm_info_set_device") == 0) {
        return (void *)snd_pcm_info_set_device;
    }
    if (strcmp(name, "snd_pcm_info_set_stream") == 0) {
        return (void *)snd_pcm_info_set_stream;
    }
    if (strcmp(name, "snd_pcm_info_set_subdevice") == 0) {
        return (void *)snd_pcm_info_set_subdevice;
    }
    if (strcmp(name, "snd_pcm_link") == 0) {
        return (void *)snd_pcm_link;
    }
    if (strcmp(name, "snd_pcm_meter_add_scope") == 0) {
        return (void *)snd_pcm_meter_add_scope;
    }
    if (strcmp(name, "snd_pcm_meter_get_boundary") == 0) {
        return (void *)snd_pcm_meter_get_boundary;
    }
    if (strcmp(name, "snd_pcm_meter_get_bufsize") == 0) {
        return (void *)snd_pcm_meter_get_bufsize;
    }
    if (strcmp(name, "snd_pcm_meter_get_channels") == 0) {
        return (void *)snd_pcm_meter_get_channels;
    }
    if (strcmp(name, "snd_pcm_meter_get_now") == 0) {
        return (void *)snd_pcm_meter_get_now;
    }
    if (strcmp(name, "snd_pcm_meter_get_rate") == 0) {
        return (void *)snd_pcm_meter_get_rate;
    }
    if (strcmp(name, "snd_pcm_meter_search_scope") == 0) {
        return (void *)snd_pcm_meter_search_scope;
    }
    if (strcmp(name, "snd_pcm_mmap_begin") == 0) {
        return (void *)snd_pcm_mmap_begin;
    }
    if (strcmp(name, "snd_pcm_mmap_commit") == 0) {
        return (void *)snd_pcm_mmap_commit;
    }
    if (strcmp(name, "snd_pcm_mmap_readi") == 0) {
        return (void *)snd_pcm_mmap_readi;
    }
    if (strcmp(name, "snd_pcm_mmap_readn") == 0) {
        return (void *)snd_pcm_mmap_readn;
    }
    if (strcmp(name, "snd_pcm_mmap_writei") == 0) {
        return (void *)snd_pcm_mmap_writei;
    }
    if (strcmp(name, "snd_pcm_mmap_writen") == 0) {
        return (void *)snd_pcm_mmap_writen;
    }
    if (strcmp(name, "snd_pcm_name") == 0) {
        return (void *)snd_pcm_name;
    }
    if (strcmp(name, "snd_pcm_nonblock") == 0) {
        return (void *)snd_pcm_nonblock;
    }
    if (strcmp(name, "snd_pcm_open") == 0) {
        return (void *)snd_pcm_open;
    }
    if (strcmp(name, "snd_pcm_open_lconf") == 0) {
        return (void *)snd_pcm_open_lconf;
    }
    if (strcmp(name, "snd_pcm_pause") == 0) {
        return (void *)snd_pcm_pause;
    }
    if (strcmp(name, "snd_pcm_poll_descriptors") == 0) {
        return (void *)snd_pcm_poll_descriptors;
    }
    if (strcmp(name, "snd_pcm_poll_descriptors_count") == 0) {
        return (void *)snd_pcm_poll_descriptors_count;
    }
    if (strcmp(name, "snd_pcm_poll_descriptors_revents") == 0) {
        return (void *)snd_pcm_poll_descriptors_revents;
    }
    if (strcmp(name, "snd_pcm_prepare") == 0) {
        return (void *)snd_pcm_prepare;
    }
    if (strcmp(name, "snd_pcm_readi") == 0) {
        return (void *)snd_pcm_readi;
    }
    if (strcmp(name, "snd_pcm_readn") == 0) {
        return (void *)snd_pcm_readn;
    }
    if (strcmp(name, "snd_pcm_recover") == 0) {
        return (void *)snd_pcm_recover;
    }
    if (strcmp(name, "snd_pcm_reset") == 0) {
        return (void *)snd_pcm_reset;
    }
    if (strcmp(name, "snd_pcm_resume") == 0) {
        return (void *)snd_pcm_resume;
    }
    if (strcmp(name, "snd_pcm_rewind") == 0) {
        return (void *)snd_pcm_rewind;
    }
    if (strcmp(name, "snd_pcm_samples_to_bytes") == 0) {
        return (void *)snd_pcm_samples_to_bytes;
    }
    if (strcmp(name, "snd_pcm_scope_get_callback_private") == 0) {
        return (void *)snd_pcm_scope_get_callback_private;
    }
    if (strcmp(name, "snd_pcm_scope_get_name") == 0) {
        return (void *)snd_pcm_scope_get_name;
    }
    if (strcmp(name, "snd_pcm_scope_malloc") == 0) {
        return (void *)snd_pcm_scope_malloc;
    }
    if (strcmp(name, "snd_pcm_scope_s16_get_channel_buffer") == 0) {
        return (void *)snd_pcm_scope_s16_get_channel_buffer;
    }
    if (strcmp(name, "snd_pcm_scope_s16_open") == 0) {
        return (void *)snd_pcm_scope_s16_open;
    }
    if (strcmp(name, "snd_pcm_scope_set_callback_private") == 0) {
        return (void *)snd_pcm_scope_set_callback_private;
    }
    if (strcmp(name, "snd_pcm_scope_set_name") == 0) {
        return (void *)snd_pcm_scope_set_name;
    }
    if (strcmp(name, "snd_pcm_scope_set_ops") == 0) {
        return (void *)snd_pcm_scope_set_ops;
    }
    if (strcmp(name, "snd_pcm_set_params") == 0) {
        return (void *)snd_pcm_set_params;
    }
    if (strcmp(name, "snd_pcm_start") == 0) {
        return (void *)snd_pcm_start;
    }
    if (strcmp(name, "snd_pcm_start_mode_name") == 0) {
        return (void *)snd_pcm_start_mode_name;
    }
    if (strcmp(name, "snd_pcm_state") == 0) {
        return (void *)snd_pcm_state;
    }
    if (strcmp(name, "snd_pcm_state_name") == 0) {
        return (void *)snd_pcm_state_name;
    }
    if (strcmp(name, "snd_pcm_status") == 0) {
        return (void *)snd_pcm_status;
    }
    if (strcmp(name, "snd_pcm_status_copy") == 0) {
        return (void *)snd_pcm_status_copy;
    }
    if (strcmp(name, "snd_pcm_status_dump") == 0) {
        return (void *)snd_pcm_status_dump;
    }
    if (strcmp(name, "snd_pcm_status_free") == 0) {
        return (void *)snd_pcm_status_free;
    }
    if (strcmp(name, "snd_pcm_status_get_avail") == 0) {
        return (void *)snd_pcm_status_get_avail;
    }
    if (strcmp(name, "snd_pcm_status_get_avail_max") == 0) {
        return (void *)snd_pcm_status_get_avail_max;
    }
    if (strcmp(name, "snd_pcm_status_get_delay") == 0) {
        return (void *)snd_pcm_status_get_delay;
    }
    if (strcmp(name, "snd_pcm_status_get_htstamp") == 0) {
        return (void *)snd_pcm_status_get_htstamp;
    }
    if (strcmp(name, "snd_pcm_status_get_overrange") == 0) {
        return (void *)snd_pcm_status_get_overrange;
    }
    if (strcmp(name, "snd_pcm_status_get_state") == 0) {
        return (void *)snd_pcm_status_get_state;
    }
    if (strcmp(name, "snd_pcm_status_get_trigger_htstamp") == 0) {
        return (void *)snd_pcm_status_get_trigger_htstamp;
    }
    if (strcmp(name, "snd_pcm_status_get_trigger_tstamp") == 0) {
        return (void *)snd_pcm_status_get_trigger_tstamp;
    }
    if (strcmp(name, "snd_pcm_status_get_tstamp") == 0) {
        return (void *)snd_pcm_status_get_tstamp;
    }
    if (strcmp(name, "snd_pcm_status_malloc") == 0) {
        return (void *)snd_pcm_status_malloc;
    }
    if (strcmp(name, "snd_pcm_stream") == 0) {
        return (void *)snd_pcm_stream;
    }
    if (strcmp(name, "snd_pcm_stream_name") == 0) {
        return (void *)snd_pcm_stream_name;
    }
    if (strcmp(name, "snd_pcm_subformat_description") == 0) {
        return (void *)snd_pcm_subformat_description;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_any") == 0) {
        return (void *)snd_pcm_subformat_mask_any;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_copy") == 0) {
        return (void *)snd_pcm_subformat_mask_copy;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_empty") == 0) {
        return (void *)snd_pcm_subformat_mask_empty;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_free") == 0) {
        return (void *)snd_pcm_subformat_mask_free;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_malloc") == 0) {
        return (void *)snd_pcm_subformat_mask_malloc;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_none") == 0) {
        return (void *)snd_pcm_subformat_mask_none;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_reset") == 0) {
        return (void *)snd_pcm_subformat_mask_reset;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_set") == 0) {
        return (void *)snd_pcm_subformat_mask_set;
    }
    if (strcmp(name, "snd_pcm_subformat_mask_test") == 0) {
        return (void *)snd_pcm_subformat_mask_test;
    }
    if (strcmp(name, "snd_pcm_subformat_name") == 0) {
        return (void *)snd_pcm_subformat_name;
    }
    if (strcmp(name, "snd_pcm_sw_params") == 0) {
        return (void *)snd_pcm_sw_params;
    }
    if (strcmp(name, "snd_pcm_sw_params_copy") == 0) {
        return (void *)snd_pcm_sw_params_copy;
    }
    if (strcmp(name, "snd_pcm_sw_params_current") == 0) {
        return (void *)snd_pcm_sw_params_current;
    }
    if (strcmp(name, "snd_pcm_sw_params_dump") == 0) {
        return (void *)snd_pcm_sw_params_dump;
    }
    if (strcmp(name, "snd_pcm_sw_params_free") == 0) {
        return (void *)snd_pcm_sw_params_free;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_avail_min") == 0) {
        return (void *)snd_pcm_sw_params_get_avail_min;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_boundary") == 0) {
        return (void *)snd_pcm_sw_params_get_boundary;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_silence_size") == 0) {
        return (void *)snd_pcm_sw_params_get_silence_size;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_silence_threshold") == 0) {
        return (void *)snd_pcm_sw_params_get_silence_threshold;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_sleep_min") == 0) {
        return (void *)snd_pcm_sw_params_get_sleep_min;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_start_mode") == 0) {
        return (void *)snd_pcm_sw_params_get_start_mode;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_start_threshold") == 0) {
        return (void *)snd_pcm_sw_params_get_start_threshold;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_stop_threshold") == 0) {
        return (void *)snd_pcm_sw_params_get_stop_threshold;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_tstamp_mode") == 0) {
        return (void *)snd_pcm_sw_params_get_tstamp_mode;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_xfer_align") == 0) {
        return (void *)snd_pcm_sw_params_get_xfer_align;
    }
    if (strcmp(name, "snd_pcm_sw_params_get_xrun_mode") == 0) {
        return (void *)snd_pcm_sw_params_get_xrun_mode;
    }
    if (strcmp(name, "snd_pcm_sw_params_malloc") == 0) {
        return (void *)snd_pcm_sw_params_malloc;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_avail_min") == 0) {
        return (void *)snd_pcm_sw_params_set_avail_min;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_silence_size") == 0) {
        return (void *)snd_pcm_sw_params_set_silence_size;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_silence_threshold") == 0) {
        return (void *)snd_pcm_sw_params_set_silence_threshold;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_sleep_min") == 0) {
        return (void *)snd_pcm_sw_params_set_sleep_min;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_start_mode") == 0) {
        return (void *)snd_pcm_sw_params_set_start_mode;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_start_threshold") == 0) {
        return (void *)snd_pcm_sw_params_set_start_threshold;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_stop_threshold") == 0) {
        return (void *)snd_pcm_sw_params_set_stop_threshold;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_tstamp_mode") == 0) {
        return (void *)snd_pcm_sw_params_set_tstamp_mode;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_xfer_align") == 0) {
        return (void *)snd_pcm_sw_params_set_xfer_align;
    }
    if (strcmp(name, "snd_pcm_sw_params_set_xrun_mode") == 0) {
        return (void *)snd_pcm_sw_params_set_xrun_mode;
    }
    if (strcmp(name, "snd_pcm_tstamp_mode_name") == 0) {
        return (void *)snd_pcm_tstamp_mode_name;
    }
    if (strcmp(name, "snd_pcm_type") == 0) {
        return (void *)snd_pcm_type;
    }
    if (strcmp(name, "snd_pcm_type_name") == 0) {
        return (void *)snd_pcm_type_name;
    }
    if (strcmp(name, "snd_pcm_unlink") == 0) {
        return (void *)snd_pcm_unlink;
    }
    if (strcmp(name, "snd_pcm_wait") == 0) {
        return (void *)snd_pcm_wait;
    }
    if (strcmp(name, "snd_pcm_writei") == 0) {
        return (void *)snd_pcm_writei;
    }
    if (strcmp(name, "snd_pcm_writen") == 0) {
        return (void *)snd_pcm_writen;
    }
    if (strcmp(name, "snd_pcm_xrun_mode_name") == 0) {
        return (void *)snd_pcm_xrun_mode_name;
    }
    if (strcmp(name, "snd_rawmidi_close") == 0) {
        return (void *)snd_rawmidi_close;
    }
    if (strcmp(name, "snd_rawmidi_drain") == 0) {
        return (void *)snd_rawmidi_drain;
    }
    if (strcmp(name, "snd_rawmidi_drop") == 0) {
        return (void *)snd_rawmidi_drop;
    }
    if (strcmp(name, "snd_rawmidi_info") == 0) {
        return (void *)snd_rawmidi_info;
    }
    if (strcmp(name, "snd_rawmidi_info_copy") == 0) {
        return (void *)snd_rawmidi_info_copy;
    }
    if (strcmp(name, "snd_rawmidi_info_free") == 0) {
        return (void *)snd_rawmidi_info_free;
    }
    if (strcmp(name, "snd_rawmidi_info_get_card") == 0) {
        return (void *)snd_rawmidi_info_get_card;
    }
    if (strcmp(name, "snd_rawmidi_info_get_device") == 0) {
        return (void *)snd_rawmidi_info_get_device;
    }
    if (strcmp(name, "snd_rawmidi_info_get_flags") == 0) {
        return (void *)snd_rawmidi_info_get_flags;
    }
    if (strcmp(name, "snd_rawmidi_info_get_id") == 0) {
        return (void *)snd_rawmidi_info_get_id;
    }
    if (strcmp(name, "snd_rawmidi_info_get_name") == 0) {
        return (void *)snd_rawmidi_info_get_name;
    }
    if (strcmp(name, "snd_rawmidi_info_get_stream") == 0) {
        return (void *)snd_rawmidi_info_get_stream;
    }
    if (strcmp(name, "snd_rawmidi_info_get_subdevice") == 0) {
        return (void *)snd_rawmidi_info_get_subdevice;
    }
    if (strcmp(name, "snd_rawmidi_info_get_subdevice_name") == 0) {
        return (void *)snd_rawmidi_info_get_subdevice_name;
    }
    if (strcmp(name, "snd_rawmidi_info_get_subdevices_avail") == 0) {
        return (void *)snd_rawmidi_info_get_subdevices_avail;
    }
    if (strcmp(name, "snd_rawmidi_info_get_subdevices_count") == 0) {
        return (void *)snd_rawmidi_info_get_subdevices_count;
    }
    if (strcmp(name, "snd_rawmidi_info_malloc") == 0) {
        return (void *)snd_rawmidi_info_malloc;
    }
    if (strcmp(name, "snd_rawmidi_info_set_device") == 0) {
        return (void *)snd_rawmidi_info_set_device;
    }
    if (strcmp(name, "snd_rawmidi_info_set_stream") == 0) {
        return (void *)snd_rawmidi_info_set_stream;
    }
    if (strcmp(name, "snd_rawmidi_info_set_subdevice") == 0) {
        return (void *)snd_rawmidi_info_set_subdevice;
    }
    if (strcmp(name, "snd_rawmidi_info_sizeof") == 0) {
        return (void *)snd_rawmidi_info_sizeof;
    }
    if (strcmp(name, "snd_rawmidi_name") == 0) {
        return (void *)snd_rawmidi_name;
    }
    if (strcmp(name, "snd_rawmidi_nonblock") == 0) {
        return (void *)snd_rawmidi_nonblock;
    }
    if (strcmp(name, "snd_rawmidi_open") == 0) {
        return (void *)snd_rawmidi_open;
    }
    if (strcmp(name, "snd_rawmidi_open_lconf") == 0) {
        return (void *)snd_rawmidi_open_lconf;
    }
    if (strcmp(name, "snd_rawmidi_params") == 0) {
        return (void *)snd_rawmidi_params;
    }
    if (strcmp(name, "snd_rawmidi_params_copy") == 0) {
        return (void *)snd_rawmidi_params_copy;
    }
    if (strcmp(name, "snd_rawmidi_params_current") == 0) {
        return (void *)snd_rawmidi_params_current;
    }
    if (strcmp(name, "snd_rawmidi_params_free") == 0) {
        return (void *)snd_rawmidi_params_free;
    }
    if (strcmp(name, "snd_rawmidi_params_get_avail_min") == 0) {
        return (void *)snd_rawmidi_params_get_avail_min;
    }
    if (strcmp(name, "snd_rawmidi_params_get_buffer_size") == 0) {
        return (void *)snd_rawmidi_params_get_buffer_size;
    }
    if (strcmp(name, "snd_rawmidi_params_get_no_active_sensing") == 0) {
        return (void *)snd_rawmidi_params_get_no_active_sensing;
    }
    if (strcmp(name, "snd_rawmidi_params_malloc") == 0) {
        return (void *)snd_rawmidi_params_malloc;
    }
    if (strcmp(name, "snd_rawmidi_params_set_avail_min") == 0) {
        return (void *)snd_rawmidi_params_set_avail_min;
    }
    if (strcmp(name, "snd_rawmidi_params_set_buffer_size") == 0) {
        return (void *)snd_rawmidi_params_set_buffer_size;
    }
    if (strcmp(name, "snd_rawmidi_params_set_no_active_sensing") == 0) {
        return (void *)snd_rawmidi_params_set_no_active_sensing;
    }
    if (strcmp(name, "snd_rawmidi_params_sizeof") == 0) {
        return (void *)snd_rawmidi_params_sizeof;
    }
    if (strcmp(name, "snd_rawmidi_poll_descriptors") == 0) {
        return (void *)snd_rawmidi_poll_descriptors;
    }
    if (strcmp(name, "snd_rawmidi_poll_descriptors_count") == 0) {
        return (void *)snd_rawmidi_poll_descriptors_count;
    }
    if (strcmp(name, "snd_rawmidi_poll_descriptors_revents") == 0) {
        return (void *)snd_rawmidi_poll_descriptors_revents;
    }
    if (strcmp(name, "snd_rawmidi_read") == 0) {
        return (void *)snd_rawmidi_read;
    }
    if (strcmp(name, "snd_rawmidi_status") == 0) {
        return (void *)snd_rawmidi_status;
    }
    if (strcmp(name, "snd_rawmidi_status_copy") == 0) {
        return (void *)snd_rawmidi_status_copy;
    }
    if (strcmp(name, "snd_rawmidi_status_free") == 0) {
        return (void *)snd_rawmidi_status_free;
    }
    if (strcmp(name, "snd_rawmidi_status_get_avail") == 0) {
        return (void *)snd_rawmidi_status_get_avail;
    }
    if (strcmp(name, "snd_rawmidi_status_get_tstamp") == 0) {
        return (void *)snd_rawmidi_status_get_tstamp;
    }
    if (strcmp(name, "snd_rawmidi_status_get_xruns") == 0) {
        return (void *)snd_rawmidi_status_get_xruns;
    }
    if (strcmp(name, "snd_rawmidi_status_malloc") == 0) {
        return (void *)snd_rawmidi_status_malloc;
    }
    if (strcmp(name, "snd_rawmidi_status_sizeof") == 0) {
        return (void *)snd_rawmidi_status_sizeof;
    }
    if (strcmp(name, "snd_rawmidi_stream") == 0) {
        return (void *)snd_rawmidi_stream;
    }
    if (strcmp(name, "snd_rawmidi_type") == 0) {
        return (void *)snd_rawmidi_type;
    }
    if (strcmp(name, "snd_rawmidi_write") == 0) {
        return (void *)snd_rawmidi_write;
    }
    if (strcmp(name, "snd_sctl_build") == 0) {
        return (void *)snd_sctl_build;
    }
    if (strcmp(name, "snd_sctl_free") == 0) {
        return (void *)snd_sctl_free;
    }
    if (strcmp(name, "snd_sctl_install") == 0) {
        return (void *)snd_sctl_install;
    }
    if (strcmp(name, "snd_sctl_remove") == 0) {
        return (void *)snd_sctl_remove;
    }
    if (strcmp(name, "snd_seq_alloc_named_queue") == 0) {
        return (void *)snd_seq_alloc_named_queue;
    }
    if (strcmp(name, "snd_seq_alloc_queue") == 0) {
        return (void *)snd_seq_alloc_queue;
    }
    if (strcmp(name, "snd_seq_change_bit") == 0) {
        return (void *)snd_seq_change_bit;
    }
    if (strcmp(name, "snd_seq_client_id") == 0) {
        return (void *)snd_seq_client_id;
    }
    if (strcmp(name, "snd_seq_client_info_copy") == 0) {
        return (void *)snd_seq_client_info_copy;
    }
    if (strcmp(name, "snd_seq_client_info_free") == 0) {
        return (void *)snd_seq_client_info_free;
    }
    if (strcmp(name, "snd_seq_client_info_get_broadcast_filter") == 0) {
        return (void *)snd_seq_client_info_get_broadcast_filter;
    }
    if (strcmp(name, "snd_seq_client_info_get_client") == 0) {
        return (void *)snd_seq_client_info_get_client;
    }
    if (strcmp(name, "snd_seq_client_info_get_error_bounce") == 0) {
        return (void *)snd_seq_client_info_get_error_bounce;
    }
    if (strcmp(name, "snd_seq_client_info_get_event_filter") == 0) {
        return (void *)snd_seq_client_info_get_event_filter;
    }
    if (strcmp(name, "snd_seq_client_info_get_event_lost") == 0) {
        return (void *)snd_seq_client_info_get_event_lost;
    }
    if (strcmp(name, "snd_seq_client_info_get_name") == 0) {
        return (void *)snd_seq_client_info_get_name;
    }
    if (strcmp(name, "snd_seq_client_info_get_num_ports") == 0) {
        return (void *)snd_seq_client_info_get_num_ports;
    }
    if (strcmp(name, "snd_seq_client_info_get_type") == 0) {
        return (void *)snd_seq_client_info_get_type;
    }
    if (strcmp(name, "snd_seq_client_info_malloc") == 0) {
        return (void *)snd_seq_client_info_malloc;
    }
    if (strcmp(name, "snd_seq_client_info_set_broadcast_filter") == 0) {
        return (void *)snd_seq_client_info_set_broadcast_filter;
    }
    if (strcmp(name, "snd_seq_client_info_set_client") == 0) {
        return (void *)snd_seq_client_info_set_client;
    }
    if (strcmp(name, "snd_seq_client_info_set_error_bounce") == 0) {
        return (void *)snd_seq_client_info_set_error_bounce;
    }
    if (strcmp(name, "snd_seq_client_info_set_event_filter") == 0) {
        return (void *)snd_seq_client_info_set_event_filter;
    }
    if (strcmp(name, "snd_seq_client_info_set_name") == 0) {
        return (void *)snd_seq_client_info_set_name;
    }
    if (strcmp(name, "snd_seq_client_info_sizeof") == 0) {
        return (void *)snd_seq_client_info_sizeof;
    }
    if (strcmp(name, "snd_seq_client_pool_copy") == 0) {
        return (void *)snd_seq_client_pool_copy;
    }
    if (strcmp(name, "snd_seq_client_pool_free") == 0) {
        return (void *)snd_seq_client_pool_free;
    }
    if (strcmp(name, "snd_seq_client_pool_get_client") == 0) {
        return (void *)snd_seq_client_pool_get_client;
    }
    if (strcmp(name, "snd_seq_client_pool_get_input_free") == 0) {
        return (void *)snd_seq_client_pool_get_input_free;
    }
    if (strcmp(name, "snd_seq_client_pool_get_input_pool") == 0) {
        return (void *)snd_seq_client_pool_get_input_pool;
    }
    if (strcmp(name, "snd_seq_client_pool_get_output_free") == 0) {
        return (void *)snd_seq_client_pool_get_output_free;
    }
    if (strcmp(name, "snd_seq_client_pool_get_output_pool") == 0) {
        return (void *)snd_seq_client_pool_get_output_pool;
    }
    if (strcmp(name, "snd_seq_client_pool_get_output_room") == 0) {
        return (void *)snd_seq_client_pool_get_output_room;
    }
    if (strcmp(name, "snd_seq_client_pool_malloc") == 0) {
        return (void *)snd_seq_client_pool_malloc;
    }
    if (strcmp(name, "snd_seq_client_pool_set_input_pool") == 0) {
        return (void *)snd_seq_client_pool_set_input_pool;
    }
    if (strcmp(name, "snd_seq_client_pool_set_output_pool") == 0) {
        return (void *)snd_seq_client_pool_set_output_pool;
    }
    if (strcmp(name, "snd_seq_client_pool_set_output_room") == 0) {
        return (void *)snd_seq_client_pool_set_output_room;
    }
    if (strcmp(name, "snd_seq_client_pool_sizeof") == 0) {
        return (void *)snd_seq_client_pool_sizeof;
    }
    if (strcmp(name, "snd_seq_close") == 0) {
        return (void *)snd_seq_close;
    }
    if (strcmp(name, "snd_seq_create_port") == 0) {
        return (void *)snd_seq_create_port;
    }
    if (strcmp(name, "snd_seq_create_queue") == 0) {
        return (void *)snd_seq_create_queue;
    }
    if (strcmp(name, "snd_seq_delete_port") == 0) {
        return (void *)snd_seq_delete_port;
    }
    if (strcmp(name, "snd_seq_drain_output") == 0) {
        return (void *)snd_seq_drain_output;
    }
    if (strcmp(name, "snd_seq_drop_input") == 0) {
        return (void *)snd_seq_drop_input;
    }
    if (strcmp(name, "snd_seq_drop_input_buffer") == 0) {
        return (void *)snd_seq_drop_input_buffer;
    }
    if (strcmp(name, "snd_seq_drop_output") == 0) {
        return (void *)snd_seq_drop_output;
    }
    if (strcmp(name, "snd_seq_drop_output_buffer") == 0) {
        return (void *)snd_seq_drop_output_buffer;
    }
    if (strcmp(name, "snd_seq_event_input") == 0) {
        return (void *)snd_seq_event_input;
    }
    if (strcmp(name, "snd_seq_event_input_pending") == 0) {
        return (void *)snd_seq_event_input_pending;
    }
    if (strcmp(name, "snd_seq_event_length") == 0) {
        return (void *)snd_seq_event_length;
    }
    if (strcmp(name, "snd_seq_event_output") == 0) {
        return (void *)snd_seq_event_output;
    }
    if (strcmp(name, "snd_seq_event_output_buffer") == 0) {
        return (void *)snd_seq_event_output_buffer;
    }
    if (strcmp(name, "snd_seq_event_output_direct") == 0) {
        return (void *)snd_seq_event_output_direct;
    }
    if (strcmp(name, "snd_seq_event_output_pending") == 0) {
        return (void *)snd_seq_event_output_pending;
    }
    if (strcmp(name, "snd_seq_extract_output") == 0) {
        return (void *)snd_seq_extract_output;
    }
    if (strcmp(name, "snd_seq_free_event") == 0) {
        return (void *)snd_seq_free_event;
    }
    if (strcmp(name, "snd_seq_free_queue") == 0) {
        return (void *)snd_seq_free_queue;
    }
    if (strcmp(name, "snd_seq_get_any_client_info") == 0) {
        return (void *)snd_seq_get_any_client_info;
    }
    if (strcmp(name, "snd_seq_get_any_port_info") == 0) {
        return (void *)snd_seq_get_any_port_info;
    }
    if (strcmp(name, "snd_seq_get_bit") == 0) {
        return (void *)snd_seq_get_bit;
    }
    if (strcmp(name, "snd_seq_get_client_info") == 0) {
        return (void *)snd_seq_get_client_info;
    }
    if (strcmp(name, "snd_seq_get_client_pool") == 0) {
        return (void *)snd_seq_get_client_pool;
    }
    if (strcmp(name, "snd_seq_get_input_buffer_size") == 0) {
        return (void *)snd_seq_get_input_buffer_size;
    }
    if (strcmp(name, "snd_seq_get_output_buffer_size") == 0) {
        return (void *)snd_seq_get_output_buffer_size;
    }
    if (strcmp(name, "snd_seq_get_port_info") == 0) {
        return (void *)snd_seq_get_port_info;
    }
    if (strcmp(name, "snd_seq_get_port_subscription") == 0) {
        return (void *)snd_seq_get_port_subscription;
    }
    if (strcmp(name, "snd_seq_get_queue_info") == 0) {
        return (void *)snd_seq_get_queue_info;
    }
    if (strcmp(name, "snd_seq_get_queue_status") == 0) {
        return (void *)snd_seq_get_queue_status;
    }
    if (strcmp(name, "snd_seq_get_queue_tempo") == 0) {
        return (void *)snd_seq_get_queue_tempo;
    }
    if (strcmp(name, "snd_seq_get_queue_timer") == 0) {
        return (void *)snd_seq_get_queue_timer;
    }
    if (strcmp(name, "snd_seq_get_queue_usage") == 0) {
        return (void *)snd_seq_get_queue_usage;
    }
    if (strcmp(name, "snd_seq_name") == 0) {
        return (void *)snd_seq_name;
    }
    if (strcmp(name, "snd_seq_nonblock") == 0) {
        return (void *)snd_seq_nonblock;
    }
    if (strcmp(name, "snd_seq_open") == 0) {
        return (void *)snd_seq_open;
    }
    if (strcmp(name, "snd_seq_open_lconf") == 0) {
        return (void *)snd_seq_open_lconf;
    }
    if (strcmp(name, "snd_seq_poll_descriptors") == 0) {
        return (void *)snd_seq_poll_descriptors;
    }
    if (strcmp(name, "snd_seq_poll_descriptors_count") == 0) {
        return (void *)snd_seq_poll_descriptors_count;
    }
    if (strcmp(name, "snd_seq_poll_descriptors_revents") == 0) {
        return (void *)snd_seq_poll_descriptors_revents;
    }
    if (strcmp(name, "snd_seq_port_info_copy") == 0) {
        return (void *)snd_seq_port_info_copy;
    }
    if (strcmp(name, "snd_seq_port_info_free") == 0) {
        return (void *)snd_seq_port_info_free;
    }
    if (strcmp(name, "snd_seq_port_info_get_addr") == 0) {
        return (void *)snd_seq_port_info_get_addr;
    }
    if (strcmp(name, "snd_seq_port_info_get_capability") == 0) {
        return (void *)snd_seq_port_info_get_capability;
    }
    if (strcmp(name, "snd_seq_port_info_get_client") == 0) {
        return (void *)snd_seq_port_info_get_client;
    }
    if (strcmp(name, "snd_seq_port_info_get_midi_channels") == 0) {
        return (void *)snd_seq_port_info_get_midi_channels;
    }
    if (strcmp(name, "snd_seq_port_info_get_midi_voices") == 0) {
        return (void *)snd_seq_port_info_get_midi_voices;
    }
    if (strcmp(name, "snd_seq_port_info_get_name") == 0) {
        return (void *)snd_seq_port_info_get_name;
    }
    if (strcmp(name, "snd_seq_port_info_get_port") == 0) {
        return (void *)snd_seq_port_info_get_port;
    }
    if (strcmp(name, "snd_seq_port_info_get_port_specified") == 0) {
        return (void *)snd_seq_port_info_get_port_specified;
    }
    if (strcmp(name, "snd_seq_port_info_get_read_use") == 0) {
        return (void *)snd_seq_port_info_get_read_use;
    }
    if (strcmp(name, "snd_seq_port_info_get_synth_voices") == 0) {
        return (void *)snd_seq_port_info_get_synth_voices;
    }
    if (strcmp(name, "snd_seq_port_info_get_timestamp_queue") == 0) {
        return (void *)snd_seq_port_info_get_timestamp_queue;
    }
    if (strcmp(name, "snd_seq_port_info_get_timestamp_real") == 0) {
        return (void *)snd_seq_port_info_get_timestamp_real;
    }
    if (strcmp(name, "snd_seq_port_info_get_timestamping") == 0) {
        return (void *)snd_seq_port_info_get_timestamping;
    }
    if (strcmp(name, "snd_seq_port_info_get_type") == 0) {
        return (void *)snd_seq_port_info_get_type;
    }
    if (strcmp(name, "snd_seq_port_info_get_write_use") == 0) {
        return (void *)snd_seq_port_info_get_write_use;
    }
    if (strcmp(name, "snd_seq_port_info_malloc") == 0) {
        return (void *)snd_seq_port_info_malloc;
    }
    if (strcmp(name, "snd_seq_port_info_set_addr") == 0) {
        return (void *)snd_seq_port_info_set_addr;
    }
    if (strcmp(name, "snd_seq_port_info_set_capability") == 0) {
        return (void *)snd_seq_port_info_set_capability;
    }
    if (strcmp(name, "snd_seq_port_info_set_client") == 0) {
        return (void *)snd_seq_port_info_set_client;
    }
    if (strcmp(name, "snd_seq_port_info_set_midi_channels") == 0) {
        return (void *)snd_seq_port_info_set_midi_channels;
    }
    if (strcmp(name, "snd_seq_port_info_set_midi_voices") == 0) {
        return (void *)snd_seq_port_info_set_midi_voices;
    }
    if (strcmp(name, "snd_seq_port_info_set_name") == 0) {
        return (void *)snd_seq_port_info_set_name;
    }
    if (strcmp(name, "snd_seq_port_info_set_port") == 0) {
        return (void *)snd_seq_port_info_set_port;
    }
    if (strcmp(name, "snd_seq_port_info_set_port_specified") == 0) {
        return (void *)snd_seq_port_info_set_port_specified;
    }
    if (strcmp(name, "snd_seq_port_info_set_synth_voices") == 0) {
        return (void *)snd_seq_port_info_set_synth_voices;
    }
    if (strcmp(name, "snd_seq_port_info_set_timestamp_queue") == 0) {
        return (void *)snd_seq_port_info_set_timestamp_queue;
    }
    if (strcmp(name, "snd_seq_port_info_set_timestamp_real") == 0) {
        return (void *)snd_seq_port_info_set_timestamp_real;
    }
    if (strcmp(name, "snd_seq_port_info_set_timestamping") == 0) {
        return (void *)snd_seq_port_info_set_timestamping;
    }
    if (strcmp(name, "snd_seq_port_info_set_type") == 0) {
        return (void *)snd_seq_port_info_set_type;
    }
    if (strcmp(name, "snd_seq_port_info_sizeof") == 0) {
        return (void *)snd_seq_port_info_sizeof;
    }
    if (strcmp(name, "snd_seq_port_subscribe_copy") == 0) {
        return (void *)snd_seq_port_subscribe_copy;
    }
    if (strcmp(name, "snd_seq_port_subscribe_free") == 0) {
        return (void *)snd_seq_port_subscribe_free;
    }
    if (strcmp(name, "snd_seq_port_subscribe_get_dest") == 0) {
        return (void *)snd_seq_port_subscribe_get_dest;
    }
    if (strcmp(name, "snd_seq_port_subscribe_get_exclusive") == 0) {
        return (void *)snd_seq_port_subscribe_get_exclusive;
    }
    if (strcmp(name, "snd_seq_port_subscribe_get_queue") == 0) {
        return (void *)snd_seq_port_subscribe_get_queue;
    }
    if (strcmp(name, "snd_seq_port_subscribe_get_sender") == 0) {
        return (void *)snd_seq_port_subscribe_get_sender;
    }
    if (strcmp(name, "snd_seq_port_subscribe_get_time_real") == 0) {
        return (void *)snd_seq_port_subscribe_get_time_real;
    }
    if (strcmp(name, "snd_seq_port_subscribe_get_time_update") == 0) {
        return (void *)snd_seq_port_subscribe_get_time_update;
    }
    if (strcmp(name, "snd_seq_port_subscribe_malloc") == 0) {
        return (void *)snd_seq_port_subscribe_malloc;
    }
    if (strcmp(name, "snd_seq_port_subscribe_set_dest") == 0) {
        return (void *)snd_seq_port_subscribe_set_dest;
    }
    if (strcmp(name, "snd_seq_port_subscribe_set_exclusive") == 0) {
        return (void *)snd_seq_port_subscribe_set_exclusive;
    }
    if (strcmp(name, "snd_seq_port_subscribe_set_queue") == 0) {
        return (void *)snd_seq_port_subscribe_set_queue;
    }
    if (strcmp(name, "snd_seq_port_subscribe_set_sender") == 0) {
        return (void *)snd_seq_port_subscribe_set_sender;
    }
    if (strcmp(name, "snd_seq_port_subscribe_set_time_real") == 0) {
        return (void *)snd_seq_port_subscribe_set_time_real;
    }
    if (strcmp(name, "snd_seq_port_subscribe_set_time_update") == 0) {
        return (void *)snd_seq_port_subscribe_set_time_update;
    }
    if (strcmp(name, "snd_seq_port_subscribe_sizeof") == 0) {
        return (void *)snd_seq_port_subscribe_sizeof;
    }
    if (strcmp(name, "snd_seq_query_named_queue") == 0) {
        return (void *)snd_seq_query_named_queue;
    }
    if (strcmp(name, "snd_seq_query_next_client") == 0) {
        return (void *)snd_seq_query_next_client;
    }
    if (strcmp(name, "snd_seq_query_next_port") == 0) {
        return (void *)snd_seq_query_next_port;
    }
    if (strcmp(name, "snd_seq_query_port_subscribers") == 0) {
        return (void *)snd_seq_query_port_subscribers;
    }
    if (strcmp(name, "snd_seq_query_subscribe_copy") == 0) {
        return (void *)snd_seq_query_subscribe_copy;
    }
    if (strcmp(name, "snd_seq_query_subscribe_free") == 0) {
        return (void *)snd_seq_query_subscribe_free;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_addr") == 0) {
        return (void *)snd_seq_query_subscribe_get_addr;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_client") == 0) {
        return (void *)snd_seq_query_subscribe_get_client;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_exclusive") == 0) {
        return (void *)snd_seq_query_subscribe_get_exclusive;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_index") == 0) {
        return (void *)snd_seq_query_subscribe_get_index;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_num_subs") == 0) {
        return (void *)snd_seq_query_subscribe_get_num_subs;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_port") == 0) {
        return (void *)snd_seq_query_subscribe_get_port;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_queue") == 0) {
        return (void *)snd_seq_query_subscribe_get_queue;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_root") == 0) {
        return (void *)snd_seq_query_subscribe_get_root;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_time_real") == 0) {
        return (void *)snd_seq_query_subscribe_get_time_real;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_time_update") == 0) {
        return (void *)snd_seq_query_subscribe_get_time_update;
    }
    if (strcmp(name, "snd_seq_query_subscribe_get_type") == 0) {
        return (void *)snd_seq_query_subscribe_get_type;
    }
    if (strcmp(name, "snd_seq_query_subscribe_malloc") == 0) {
        return (void *)snd_seq_query_subscribe_malloc;
    }
    if (strcmp(name, "snd_seq_query_subscribe_set_client") == 0) {
        return (void *)snd_seq_query_subscribe_set_client;
    }
    if (strcmp(name, "snd_seq_query_subscribe_set_index") == 0) {
        return (void *)snd_seq_query_subscribe_set_index;
    }
    if (strcmp(name, "snd_seq_query_subscribe_set_port") == 0) {
        return (void *)snd_seq_query_subscribe_set_port;
    }
    if (strcmp(name, "snd_seq_query_subscribe_set_root") == 0) {
        return (void *)snd_seq_query_subscribe_set_root;
    }
    if (strcmp(name, "snd_seq_query_subscribe_set_type") == 0) {
        return (void *)snd_seq_query_subscribe_set_type;
    }
    if (strcmp(name, "snd_seq_query_subscribe_sizeof") == 0) {
        return (void *)snd_seq_query_subscribe_sizeof;
    }
    if (strcmp(name, "snd_seq_queue_info_copy") == 0) {
        return (void *)snd_seq_queue_info_copy;
    }
    if (strcmp(name, "snd_seq_queue_info_free") == 0) {
        return (void *)snd_seq_queue_info_free;
    }
    if (strcmp(name, "snd_seq_queue_info_get_flags") == 0) {
        return (void *)snd_seq_queue_info_get_flags;
    }
    if (strcmp(name, "snd_seq_queue_info_get_locked") == 0) {
        return (void *)snd_seq_queue_info_get_locked;
    }
    if (strcmp(name, "snd_seq_queue_info_get_name") == 0) {
        return (void *)snd_seq_queue_info_get_name;
    }
    if (strcmp(name, "snd_seq_queue_info_get_owner") == 0) {
        return (void *)snd_seq_queue_info_get_owner;
    }
    if (strcmp(name, "snd_seq_queue_info_get_queue") == 0) {
        return (void *)snd_seq_queue_info_get_queue;
    }
    if (strcmp(name, "snd_seq_queue_info_malloc") == 0) {
        return (void *)snd_seq_queue_info_malloc;
    }
    if (strcmp(name, "snd_seq_queue_info_set_flags") == 0) {
        return (void *)snd_seq_queue_info_set_flags;
    }
    if (strcmp(name, "snd_seq_queue_info_set_locked") == 0) {
        return (void *)snd_seq_queue_info_set_locked;
    }
    if (strcmp(name, "snd_seq_queue_info_set_name") == 0) {
        return (void *)snd_seq_queue_info_set_name;
    }
    if (strcmp(name, "snd_seq_queue_info_set_owner") == 0) {
        return (void *)snd_seq_queue_info_set_owner;
    }
    if (strcmp(name, "snd_seq_queue_info_sizeof") == 0) {
        return (void *)snd_seq_queue_info_sizeof;
    }
    if (strcmp(name, "snd_seq_queue_status_copy") == 0) {
        return (void *)snd_seq_queue_status_copy;
    }
    if (strcmp(name, "snd_seq_queue_status_free") == 0) {
        return (void *)snd_seq_queue_status_free;
    }
    if (strcmp(name, "snd_seq_queue_status_get_events") == 0) {
        return (void *)snd_seq_queue_status_get_events;
    }
    if (strcmp(name, "snd_seq_queue_status_get_queue") == 0) {
        return (void *)snd_seq_queue_status_get_queue;
    }
    if (strcmp(name, "snd_seq_queue_status_get_real_time") == 0) {
        return (void *)snd_seq_queue_status_get_real_time;
    }
    if (strcmp(name, "snd_seq_queue_status_get_status") == 0) {
        return (void *)snd_seq_queue_status_get_status;
    }
    if (strcmp(name, "snd_seq_queue_status_get_tick_time") == 0) {
        return (void *)snd_seq_queue_status_get_tick_time;
    }
    if (strcmp(name, "snd_seq_queue_status_malloc") == 0) {
        return (void *)snd_seq_queue_status_malloc;
    }
    if (strcmp(name, "snd_seq_queue_status_sizeof") == 0) {
        return (void *)snd_seq_queue_status_sizeof;
    }
    if (strcmp(name, "snd_seq_queue_tempo_copy") == 0) {
        return (void *)snd_seq_queue_tempo_copy;
    }
    if (strcmp(name, "snd_seq_queue_tempo_free") == 0) {
        return (void *)snd_seq_queue_tempo_free;
    }
    if (strcmp(name, "snd_seq_queue_tempo_get_ppq") == 0) {
        return (void *)snd_seq_queue_tempo_get_ppq;
    }
    if (strcmp(name, "snd_seq_queue_tempo_get_queue") == 0) {
        return (void *)snd_seq_queue_tempo_get_queue;
    }
    if (strcmp(name, "snd_seq_queue_tempo_get_skew") == 0) {
        return (void *)snd_seq_queue_tempo_get_skew;
    }
    if (strcmp(name, "snd_seq_queue_tempo_get_skew_base") == 0) {
        return (void *)snd_seq_queue_tempo_get_skew_base;
    }
    if (strcmp(name, "snd_seq_queue_tempo_get_tempo") == 0) {
        return (void *)snd_seq_queue_tempo_get_tempo;
    }
    if (strcmp(name, "snd_seq_queue_tempo_malloc") == 0) {
        return (void *)snd_seq_queue_tempo_malloc;
    }
    if (strcmp(name, "snd_seq_queue_tempo_set_ppq") == 0) {
        return (void *)snd_seq_queue_tempo_set_ppq;
    }
    if (strcmp(name, "snd_seq_queue_tempo_set_skew") == 0) {
        return (void *)snd_seq_queue_tempo_set_skew;
    }
    if (strcmp(name, "snd_seq_queue_tempo_set_skew_base") == 0) {
        return (void *)snd_seq_queue_tempo_set_skew_base;
    }
    if (strcmp(name, "snd_seq_queue_tempo_set_tempo") == 0) {
        return (void *)snd_seq_queue_tempo_set_tempo;
    }
    if (strcmp(name, "snd_seq_queue_tempo_sizeof") == 0) {
        return (void *)snd_seq_queue_tempo_sizeof;
    }
    if (strcmp(name, "snd_seq_queue_timer_copy") == 0) {
        return (void *)snd_seq_queue_timer_copy;
    }
    if (strcmp(name, "snd_seq_queue_timer_free") == 0) {
        return (void *)snd_seq_queue_timer_free;
    }
    if (strcmp(name, "snd_seq_queue_timer_get_id") == 0) {
        return (void *)snd_seq_queue_timer_get_id;
    }
    if (strcmp(name, "snd_seq_queue_timer_get_queue") == 0) {
        return (void *)snd_seq_queue_timer_get_queue;
    }
    if (strcmp(name, "snd_seq_queue_timer_get_resolution") == 0) {
        return (void *)snd_seq_queue_timer_get_resolution;
    }
    if (strcmp(name, "snd_seq_queue_timer_get_type") == 0) {
        return (void *)snd_seq_queue_timer_get_type;
    }
    if (strcmp(name, "snd_seq_queue_timer_malloc") == 0) {
        return (void *)snd_seq_queue_timer_malloc;
    }
    if (strcmp(name, "snd_seq_queue_timer_set_id") == 0) {
        return (void *)snd_seq_queue_timer_set_id;
    }
    if (strcmp(name, "snd_seq_queue_timer_set_resolution") == 0) {
        return (void *)snd_seq_queue_timer_set_resolution;
    }
    if (strcmp(name, "snd_seq_queue_timer_set_type") == 0) {
        return (void *)snd_seq_queue_timer_set_type;
    }
    if (strcmp(name, "snd_seq_queue_timer_sizeof") == 0) {
        return (void *)snd_seq_queue_timer_sizeof;
    }
    if (strcmp(name, "snd_seq_remove_events") == 0) {
        return (void *)snd_seq_remove_events;
    }
    if (strcmp(name, "snd_seq_remove_events_copy") == 0) {
        return (void *)snd_seq_remove_events_copy;
    }
    if (strcmp(name, "snd_seq_remove_events_free") == 0) {
        return (void *)snd_seq_remove_events_free;
    }
    if (strcmp(name, "snd_seq_remove_events_get_channel") == 0) {
        return (void *)snd_seq_remove_events_get_channel;
    }
    if (strcmp(name, "snd_seq_remove_events_get_condition") == 0) {
        return (void *)snd_seq_remove_events_get_condition;
    }
    if (strcmp(name, "snd_seq_remove_events_get_dest") == 0) {
        return (void *)snd_seq_remove_events_get_dest;
    }
    if (strcmp(name, "snd_seq_remove_events_get_event_type") == 0) {
        return (void *)snd_seq_remove_events_get_event_type;
    }
    if (strcmp(name, "snd_seq_remove_events_get_queue") == 0) {
        return (void *)snd_seq_remove_events_get_queue;
    }
    if (strcmp(name, "snd_seq_remove_events_get_tag") == 0) {
        return (void *)snd_seq_remove_events_get_tag;
    }
    if (strcmp(name, "snd_seq_remove_events_get_time") == 0) {
        return (void *)snd_seq_remove_events_get_time;
    }
    if (strcmp(name, "snd_seq_remove_events_malloc") == 0) {
        return (void *)snd_seq_remove_events_malloc;
    }
    if (strcmp(name, "snd_seq_remove_events_set_channel") == 0) {
        return (void *)snd_seq_remove_events_set_channel;
    }
    if (strcmp(name, "snd_seq_remove_events_set_condition") == 0) {
        return (void *)snd_seq_remove_events_set_condition;
    }
    if (strcmp(name, "snd_seq_remove_events_set_dest") == 0) {
        return (void *)snd_seq_remove_events_set_dest;
    }
    if (strcmp(name, "snd_seq_remove_events_set_event_type") == 0) {
        return (void *)snd_seq_remove_events_set_event_type;
    }
    if (strcmp(name, "snd_seq_remove_events_set_queue") == 0) {
        return (void *)snd_seq_remove_events_set_queue;
    }
    if (strcmp(name, "snd_seq_remove_events_set_tag") == 0) {
        return (void *)snd_seq_remove_events_set_tag;
    }
    if (strcmp(name, "snd_seq_remove_events_set_time") == 0) {
        return (void *)snd_seq_remove_events_set_time;
    }
    if (strcmp(name, "snd_seq_remove_events_sizeof") == 0) {
        return (void *)snd_seq_remove_events_sizeof;
    }
    if (strcmp(name, "snd_seq_set_bit") == 0) {
        return (void *)snd_seq_set_bit;
    }
    if (strcmp(name, "snd_seq_set_client_info") == 0) {
        return (void *)snd_seq_set_client_info;
    }
    if (strcmp(name, "snd_seq_set_client_pool") == 0) {
        return (void *)snd_seq_set_client_pool;
    }
    if (strcmp(name, "snd_seq_set_input_buffer_size") == 0) {
        return (void *)snd_seq_set_input_buffer_size;
    }
    if (strcmp(name, "snd_seq_set_output_buffer_size") == 0) {
        return (void *)snd_seq_set_output_buffer_size;
    }
    if (strcmp(name, "snd_seq_set_port_info") == 0) {
        return (void *)snd_seq_set_port_info;
    }
    if (strcmp(name, "snd_seq_set_queue_info") == 0) {
        return (void *)snd_seq_set_queue_info;
    }
    if (strcmp(name, "snd_seq_set_queue_tempo") == 0) {
        return (void *)snd_seq_set_queue_tempo;
    }
    if (strcmp(name, "snd_seq_set_queue_timer") == 0) {
        return (void *)snd_seq_set_queue_timer;
    }
    if (strcmp(name, "snd_seq_set_queue_usage") == 0) {
        return (void *)snd_seq_set_queue_usage;
    }
    if (strcmp(name, "snd_seq_subscribe_port") == 0) {
        return (void *)snd_seq_subscribe_port;
    }
    if (strcmp(name, "snd_seq_system_info") == 0) {
        return (void *)snd_seq_system_info;
    }
    if (strcmp(name, "snd_seq_system_info_copy") == 0) {
        return (void *)snd_seq_system_info_copy;
    }
    if (strcmp(name, "snd_seq_system_info_free") == 0) {
        return (void *)snd_seq_system_info_free;
    }
    if (strcmp(name, "snd_seq_system_info_get_channels") == 0) {
        return (void *)snd_seq_system_info_get_channels;
    }
    if (strcmp(name, "snd_seq_system_info_get_clients") == 0) {
        return (void *)snd_seq_system_info_get_clients;
    }
    if (strcmp(name, "snd_seq_system_info_get_cur_clients") == 0) {
        return (void *)snd_seq_system_info_get_cur_clients;
    }
    if (strcmp(name, "snd_seq_system_info_get_cur_queues") == 0) {
        return (void *)snd_seq_system_info_get_cur_queues;
    }
    if (strcmp(name, "snd_seq_system_info_get_ports") == 0) {
        return (void *)snd_seq_system_info_get_ports;
    }
    if (strcmp(name, "snd_seq_system_info_get_queues") == 0) {
        return (void *)snd_seq_system_info_get_queues;
    }
    if (strcmp(name, "snd_seq_system_info_malloc") == 0) {
        return (void *)snd_seq_system_info_malloc;
    }
    if (strcmp(name, "snd_seq_system_info_sizeof") == 0) {
        return (void *)snd_seq_system_info_sizeof;
    }
    if (strcmp(name, "snd_seq_type") == 0) {
        return (void *)snd_seq_type;
    }
    if (strcmp(name, "snd_seq_unsubscribe_port") == 0) {
        return (void *)snd_seq_unsubscribe_port;
    }
    if (strcmp(name, "snd_shm_area_create") == 0) {
        return (void *)snd_shm_area_create;
    }
    if (strcmp(name, "snd_shm_area_destroy") == 0) {
        return (void *)snd_shm_area_destroy;
    }
    if (strcmp(name, "snd_shm_area_share") == 0) {
        return (void *)snd_shm_area_share;
    }
    if (strcmp(name, "snd_spcm_init") == 0) {
        return (void *)snd_spcm_init;
    }
    if (strcmp(name, "snd_spcm_init_duplex") == 0) {
        return (void *)snd_spcm_init_duplex;
    }
    if (strcmp(name, "snd_spcm_init_get_params") == 0) {
        return (void *)snd_spcm_init_get_params;
    }
    if (strcmp(name, "snd_timer_close") == 0) {
        return (void *)snd_timer_close;
    }
    if (strcmp(name, "snd_timer_continue") == 0) {
        return (void *)snd_timer_continue;
    }
    if (strcmp(name, "snd_timer_ginfo_copy") == 0) {
        return (void *)snd_timer_ginfo_copy;
    }
    if (strcmp(name, "snd_timer_ginfo_free") == 0) {
        return (void *)snd_timer_ginfo_free;
    }
    if (strcmp(name, "snd_timer_ginfo_get_card") == 0) {
        return (void *)snd_timer_ginfo_get_card;
    }
    if (strcmp(name, "snd_timer_ginfo_get_clients") == 0) {
        return (void *)snd_timer_ginfo_get_clients;
    }
    if (strcmp(name, "snd_timer_ginfo_get_flags") == 0) {
        return (void *)snd_timer_ginfo_get_flags;
    }
    if (strcmp(name, "snd_timer_ginfo_get_id") == 0) {
        return (void *)snd_timer_ginfo_get_id;
    }
    if (strcmp(name, "snd_timer_ginfo_get_name") == 0) {
        return (void *)snd_timer_ginfo_get_name;
    }
    if (strcmp(name, "snd_timer_ginfo_get_resolution") == 0) {
        return (void *)snd_timer_ginfo_get_resolution;
    }
    if (strcmp(name, "snd_timer_ginfo_get_resolution_max") == 0) {
        return (void *)snd_timer_ginfo_get_resolution_max;
    }
    if (strcmp(name, "snd_timer_ginfo_get_resolution_min") == 0) {
        return (void *)snd_timer_ginfo_get_resolution_min;
    }
    if (strcmp(name, "snd_timer_ginfo_get_tid") == 0) {
        return (void *)snd_timer_ginfo_get_tid;
    }
    if (strcmp(name, "snd_timer_ginfo_malloc") == 0) {
        return (void *)snd_timer_ginfo_malloc;
    }
    if (strcmp(name, "snd_timer_ginfo_set_tid") == 0) {
        return (void *)snd_timer_ginfo_set_tid;
    }
    if (strcmp(name, "snd_timer_ginfo_sizeof") == 0) {
        return (void *)snd_timer_ginfo_sizeof;
    }
    if (strcmp(name, "snd_timer_id_copy") == 0) {
        return (void *)snd_timer_id_copy;
    }
    if (strcmp(name, "snd_timer_id_free") == 0) {
        return (void *)snd_timer_id_free;
    }
    if (strcmp(name, "snd_timer_id_get_card") == 0) {
        return (void *)snd_timer_id_get_card;
    }
    if (strcmp(name, "snd_timer_id_get_class") == 0) {
        return (void *)snd_timer_id_get_class;
    }
    if (strcmp(name, "snd_timer_id_get_device") == 0) {
        return (void *)snd_timer_id_get_device;
    }
    if (strcmp(name, "snd_timer_id_get_sclass") == 0) {
        return (void *)snd_timer_id_get_sclass;
    }
    if (strcmp(name, "snd_timer_id_get_subdevice") == 0) {
        return (void *)snd_timer_id_get_subdevice;
    }
    if (strcmp(name, "snd_timer_id_malloc") == 0) {
        return (void *)snd_timer_id_malloc;
    }
    if (strcmp(name, "snd_timer_id_set_card") == 0) {
        return (void *)snd_timer_id_set_card;
    }
    if (strcmp(name, "snd_timer_id_set_class") == 0) {
        return (void *)snd_timer_id_set_class;
    }
    if (strcmp(name, "snd_timer_id_set_device") == 0) {
        return (void *)snd_timer_id_set_device;
    }
    if (strcmp(name, "snd_timer_id_set_sclass") == 0) {
        return (void *)snd_timer_id_set_sclass;
    }
    if (strcmp(name, "snd_timer_id_set_subdevice") == 0) {
        return (void *)snd_timer_id_set_subdevice;
    }
    if (strcmp(name, "snd_timer_id_sizeof") == 0) {
        return (void *)snd_timer_id_sizeof;
    }
    if (strcmp(name, "snd_timer_info") == 0) {
        return (void *)snd_timer_info;
    }
    if (strcmp(name, "snd_timer_info_copy") == 0) {
        return (void *)snd_timer_info_copy;
    }
    if (strcmp(name, "snd_timer_info_free") == 0) {
        return (void *)snd_timer_info_free;
    }
    if (strcmp(name, "snd_timer_info_get_card") == 0) {
        return (void *)snd_timer_info_get_card;
    }
    if (strcmp(name, "snd_timer_info_get_id") == 0) {
        return (void *)snd_timer_info_get_id;
    }
    if (strcmp(name, "snd_timer_info_get_name") == 0) {
        return (void *)snd_timer_info_get_name;
    }
    if (strcmp(name, "snd_timer_info_get_resolution") == 0) {
        return (void *)snd_timer_info_get_resolution;
    }
    if (strcmp(name, "snd_timer_info_get_ticks") == 0) {
        return (void *)snd_timer_info_get_ticks;
    }
    if (strcmp(name, "snd_timer_info_is_slave") == 0) {
        return (void *)snd_timer_info_is_slave;
    }
    if (strcmp(name, "snd_timer_info_malloc") == 0) {
        return (void *)snd_timer_info_malloc;
    }
    if (strcmp(name, "snd_timer_info_sizeof") == 0) {
        return (void *)snd_timer_info_sizeof;
    }
    if (strcmp(name, "snd_timer_open") == 0) {
        return (void *)snd_timer_open;
    }
    if (strcmp(name, "snd_timer_open_lconf") == 0) {
        return (void *)snd_timer_open_lconf;
    }
    if (strcmp(name, "snd_timer_params") == 0) {
        return (void *)snd_timer_params;
    }
    if (strcmp(name, "snd_timer_params_copy") == 0) {
        return (void *)snd_timer_params_copy;
    }
    if (strcmp(name, "snd_timer_params_free") == 0) {
        return (void *)snd_timer_params_free;
    }
    if (strcmp(name, "snd_timer_params_get_auto_start") == 0) {
        return (void *)snd_timer_params_get_auto_start;
    }
    if (strcmp(name, "snd_timer_params_get_early_event") == 0) {
        return (void *)snd_timer_params_get_early_event;
    }
    if (strcmp(name, "snd_timer_params_get_exclusive") == 0) {
        return (void *)snd_timer_params_get_exclusive;
    }
    if (strcmp(name, "snd_timer_params_get_filter") == 0) {
        return (void *)snd_timer_params_get_filter;
    }
    if (strcmp(name, "snd_timer_params_get_queue_size") == 0) {
        return (void *)snd_timer_params_get_queue_size;
    }
    if (strcmp(name, "snd_timer_params_get_ticks") == 0) {
        return (void *)snd_timer_params_get_ticks;
    }
    if (strcmp(name, "snd_timer_params_malloc") == 0) {
        return (void *)snd_timer_params_malloc;
    }
    if (strcmp(name, "snd_timer_params_set_auto_start") == 0) {
        return (void *)snd_timer_params_set_auto_start;
    }
    if (strcmp(name, "snd_timer_params_set_early_event") == 0) {
        return (void *)snd_timer_params_set_early_event;
    }
    if (strcmp(name, "snd_timer_params_set_exclusive") == 0) {
        return (void *)snd_timer_params_set_exclusive;
    }
    if (strcmp(name, "snd_timer_params_set_filter") == 0) {
        return (void *)snd_timer_params_set_filter;
    }
    if (strcmp(name, "snd_timer_params_set_queue_size") == 0) {
        return (void *)snd_timer_params_set_queue_size;
    }
    if (strcmp(name, "snd_timer_params_set_ticks") == 0) {
        return (void *)snd_timer_params_set_ticks;
    }
    if (strcmp(name, "snd_timer_params_sizeof") == 0) {
        return (void *)snd_timer_params_sizeof;
    }
    if (strcmp(name, "snd_timer_poll_descriptors") == 0) {
        return (void *)snd_timer_poll_descriptors;
    }
    if (strcmp(name, "snd_timer_poll_descriptors_count") == 0) {
        return (void *)snd_timer_poll_descriptors_count;
    }
    if (strcmp(name, "snd_timer_poll_descriptors_revents") == 0) {
        return (void *)snd_timer_poll_descriptors_revents;
    }
    if (strcmp(name, "snd_timer_query_close") == 0) {
        return (void *)snd_timer_query_close;
    }
    if (strcmp(name, "snd_timer_query_info") == 0) {
        return (void *)snd_timer_query_info;
    }
    if (strcmp(name, "snd_timer_query_next_device") == 0) {
        return (void *)snd_timer_query_next_device;
    }
    if (strcmp(name, "snd_timer_query_open") == 0) {
        return (void *)snd_timer_query_open;
    }
    if (strcmp(name, "snd_timer_query_open_lconf") == 0) {
        return (void *)snd_timer_query_open_lconf;
    }
    if (strcmp(name, "snd_timer_query_params") == 0) {
        return (void *)snd_timer_query_params;
    }
    if (strcmp(name, "snd_timer_query_status") == 0) {
        return (void *)snd_timer_query_status;
    }
    if (strcmp(name, "snd_timer_read") == 0) {
        return (void *)snd_timer_read;
    }
    if (strcmp(name, "snd_timer_start") == 0) {
        return (void *)snd_timer_start;
    }
    if (strcmp(name, "snd_timer_status") == 0) {
        return (void *)snd_timer_status;
    }
    if (strcmp(name, "snd_timer_status_copy") == 0) {
        return (void *)snd_timer_status_copy;
    }
    if (strcmp(name, "snd_timer_status_free") == 0) {
        return (void *)snd_timer_status_free;
    }
    if (strcmp(name, "snd_timer_status_get_lost") == 0) {
        return (void *)snd_timer_status_get_lost;
    }
    if (strcmp(name, "snd_timer_status_get_overrun") == 0) {
        return (void *)snd_timer_status_get_overrun;
    }
    if (strcmp(name, "snd_timer_status_get_queue") == 0) {
        return (void *)snd_timer_status_get_queue;
    }
    if (strcmp(name, "snd_timer_status_get_resolution") == 0) {
        return (void *)snd_timer_status_get_resolution;
    }
    if (strcmp(name, "snd_timer_status_get_timestamp") == 0) {
        return (void *)snd_timer_status_get_timestamp;
    }
    if (strcmp(name, "snd_timer_status_malloc") == 0) {
        return (void *)snd_timer_status_malloc;
    }
    if (strcmp(name, "snd_timer_status_sizeof") == 0) {
        return (void *)snd_timer_status_sizeof;
    }
    if (strcmp(name, "snd_timer_stop") == 0) {
        return (void *)snd_timer_stop;
    }
    if (strcmp(name, "snd_user_file") == 0) {
        return (void *)snd_user_file;
    }
    printf("glXGetProcAddress(%s) not found\n", name);
    return NULL;
}

__GLXextFuncPtr glXGetProcAddress(const GLubyte *name) {
    return glXGetProcAddressARB(name);
}
