#include <sys/syscall.h>
#include <unistd.h>
#include "../proxy.h"


#define DISABLE_SKIP
#if !defined(skip_glAccum) || defined(DISABLE_SKIP)
void glAccum(GLenum op, GLfloat value) {
    glAccum_INDEXED *packed_data = malloc(sizeof(glAccum_INDEXED));
    packed_data->func = glAccum_INDEX;
    packed_data->args.a1 = op;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glActiveTexture) || defined(DISABLE_SKIP)
void glActiveTexture(GLenum texture) {
    glActiveTexture_INDEXED *packed_data = malloc(sizeof(glActiveTexture_INDEXED));
    packed_data->func = glActiveTexture_INDEX;
    packed_data->args.a1 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glAlphaFunc) || defined(DISABLE_SKIP)
void glAlphaFunc(GLenum func, GLfloat ref) {
    glAlphaFunc_INDEXED *packed_data = malloc(sizeof(glAlphaFunc_INDEXED));
    packed_data->func = glAlphaFunc_INDEX;
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glAreTexturesResident) || defined(DISABLE_SKIP)
GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences) {
    glAreTexturesResident_INDEXED *packed_data = malloc(sizeof(glAreTexturesResident_INDEXED));
    packed_data->func = glAreTexturesResident_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    packed_data->args.a3 = residences;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glArrayElement) || defined(DISABLE_SKIP)
void glArrayElement(GLint i) {
    glArrayElement_INDEXED *packed_data = malloc(sizeof(glArrayElement_INDEXED));
    packed_data->func = glArrayElement_INDEX;
    packed_data->args.a1 = i;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBegin) || defined(DISABLE_SKIP)
void glBegin(GLenum mode) {
    glBegin_INDEXED *packed_data = malloc(sizeof(glBegin_INDEXED));
    packed_data->func = glBegin_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBeginQuery) || defined(DISABLE_SKIP)
void glBeginQuery(GLenum target, GLuint id) {
    glBeginQuery_INDEXED *packed_data = malloc(sizeof(glBeginQuery_INDEXED));
    packed_data->func = glBeginQuery_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBindBuffer) || defined(DISABLE_SKIP)
void glBindBuffer(GLenum target, GLuint buffer) {
    glBindBuffer_INDEXED *packed_data = malloc(sizeof(glBindBuffer_INDEXED));
    packed_data->func = glBindBuffer_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBindTexture) || defined(DISABLE_SKIP)
void glBindTexture(GLenum target, GLuint texture) {
    glBindTexture_INDEXED *packed_data = malloc(sizeof(glBindTexture_INDEXED));
    packed_data->func = glBindTexture_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBitmap) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glBlendColor) || defined(DISABLE_SKIP)
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glBlendColor_INDEXED *packed_data = malloc(sizeof(glBlendColor_INDEXED));
    packed_data->func = glBlendColor_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBlendEquation) || defined(DISABLE_SKIP)
void glBlendEquation(GLenum mode) {
    glBlendEquation_INDEXED *packed_data = malloc(sizeof(glBlendEquation_INDEXED));
    packed_data->func = glBlendEquation_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBlendFunc) || defined(DISABLE_SKIP)
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    glBlendFunc_INDEXED *packed_data = malloc(sizeof(glBlendFunc_INDEXED));
    packed_data->func = glBlendFunc_INDEX;
    packed_data->args.a1 = sfactor;
    packed_data->args.a2 = dfactor;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBlendFuncSeparate) || defined(DISABLE_SKIP)
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    glBlendFuncSeparate_INDEXED *packed_data = malloc(sizeof(glBlendFuncSeparate_INDEXED));
    packed_data->func = glBlendFuncSeparate_INDEX;
    packed_data->args.a1 = sfactorRGB;
    packed_data->args.a2 = dfactorRGB;
    packed_data->args.a3 = sfactorAlpha;
    packed_data->args.a4 = dfactorAlpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBufferData) || defined(DISABLE_SKIP)
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    glBufferData_INDEXED *packed_data = malloc(sizeof(glBufferData_INDEXED));
    packed_data->func = glBufferData_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = size;
    packed_data->args.a3 = data;
    packed_data->args.a4 = usage;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glBufferSubData) || defined(DISABLE_SKIP)
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    glBufferSubData_INDEXED *packed_data = malloc(sizeof(glBufferSubData_INDEXED));
    packed_data->func = glBufferSubData_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = size;
    packed_data->args.a4 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glCallList) || defined(DISABLE_SKIP)
void glCallList(GLuint list) {
    glCallList_INDEXED *packed_data = malloc(sizeof(glCallList_INDEXED));
    packed_data->func = glCallList_INDEX;
    packed_data->args.a1 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glCallLists) || defined(DISABLE_SKIP)
void glCallLists(GLsizei n, GLenum type, const GLvoid * lists) {
    glCallLists_INDEXED *packed_data = malloc(sizeof(glCallLists_INDEXED));
    packed_data->func = glCallLists_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = type;
    packed_data->args.a3 = lists;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glClear) || defined(DISABLE_SKIP)
void glClear(GLbitfield mask) {
    glClear_INDEXED *packed_data = malloc(sizeof(glClear_INDEXED));
    packed_data->func = glClear_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glClearAccum) || defined(DISABLE_SKIP)
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glClearAccum_INDEXED *packed_data = malloc(sizeof(glClearAccum_INDEXED));
    packed_data->func = glClearAccum_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glClearColor) || defined(DISABLE_SKIP)
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glClearColor_INDEXED *packed_data = malloc(sizeof(glClearColor_INDEXED));
    packed_data->func = glClearColor_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glClearDepth) || defined(DISABLE_SKIP)
void glClearDepth(GLdouble depth) {
    glClearDepth_INDEXED *packed_data = malloc(sizeof(glClearDepth_INDEXED));
    packed_data->func = glClearDepth_INDEX;
    packed_data->args.a1 = depth;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glClearIndex) || defined(DISABLE_SKIP)
void glClearIndex(GLfloat c) {
    glClearIndex_INDEXED *packed_data = malloc(sizeof(glClearIndex_INDEXED));
    packed_data->func = glClearIndex_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glClearStencil) || defined(DISABLE_SKIP)
void glClearStencil(GLint s) {
    glClearStencil_INDEXED *packed_data = malloc(sizeof(glClearStencil_INDEXED));
    packed_data->func = glClearStencil_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glClientActiveTexture) || defined(DISABLE_SKIP)
void glClientActiveTexture(GLenum texture) {
    glClientActiveTexture_INDEXED *packed_data = malloc(sizeof(glClientActiveTexture_INDEXED));
    packed_data->func = glClientActiveTexture_INDEX;
    packed_data->args.a1 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glClipPlane) || defined(DISABLE_SKIP)
void glClipPlane(GLenum plane, const GLdouble * equation) {
    glClipPlane_INDEXED *packed_data = malloc(sizeof(glClipPlane_INDEXED));
    packed_data->func = glClipPlane_INDEX;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3b) || defined(DISABLE_SKIP)
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    glColor3b_INDEXED *packed_data = malloc(sizeof(glColor3b_INDEXED));
    packed_data->func = glColor3b_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3bv) || defined(DISABLE_SKIP)
void glColor3bv(const GLbyte * v) {
    glColor3bv_INDEXED *packed_data = malloc(sizeof(glColor3bv_INDEXED));
    packed_data->func = glColor3bv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3d) || defined(DISABLE_SKIP)
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    glColor3d_INDEXED *packed_data = malloc(sizeof(glColor3d_INDEXED));
    packed_data->func = glColor3d_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3dv) || defined(DISABLE_SKIP)
void glColor3dv(const GLdouble * v) {
    glColor3dv_INDEXED *packed_data = malloc(sizeof(glColor3dv_INDEXED));
    packed_data->func = glColor3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3f) || defined(DISABLE_SKIP)
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f_INDEXED *packed_data = malloc(sizeof(glColor3f_INDEXED));
    packed_data->func = glColor3f_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3fv) || defined(DISABLE_SKIP)
void glColor3fv(const GLfloat * v) {
    glColor3fv_INDEXED *packed_data = malloc(sizeof(glColor3fv_INDEXED));
    packed_data->func = glColor3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3i) || defined(DISABLE_SKIP)
void glColor3i(GLint red, GLint green, GLint blue) {
    glColor3i_INDEXED *packed_data = malloc(sizeof(glColor3i_INDEXED));
    packed_data->func = glColor3i_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3iv) || defined(DISABLE_SKIP)
void glColor3iv(const GLint * v) {
    glColor3iv_INDEXED *packed_data = malloc(sizeof(glColor3iv_INDEXED));
    packed_data->func = glColor3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3s) || defined(DISABLE_SKIP)
void glColor3s(GLshort red, GLshort green, GLshort blue) {
    glColor3s_INDEXED *packed_data = malloc(sizeof(glColor3s_INDEXED));
    packed_data->func = glColor3s_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3sv) || defined(DISABLE_SKIP)
void glColor3sv(const GLshort * v) {
    glColor3sv_INDEXED *packed_data = malloc(sizeof(glColor3sv_INDEXED));
    packed_data->func = glColor3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3ub) || defined(DISABLE_SKIP)
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    glColor3ub_INDEXED *packed_data = malloc(sizeof(glColor3ub_INDEXED));
    packed_data->func = glColor3ub_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3ubv) || defined(DISABLE_SKIP)
void glColor3ubv(const GLubyte * v) {
    glColor3ubv_INDEXED *packed_data = malloc(sizeof(glColor3ubv_INDEXED));
    packed_data->func = glColor3ubv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3ui) || defined(DISABLE_SKIP)
void glColor3ui(GLuint red, GLuint green, GLuint blue) {
    glColor3ui_INDEXED *packed_data = malloc(sizeof(glColor3ui_INDEXED));
    packed_data->func = glColor3ui_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3uiv) || defined(DISABLE_SKIP)
void glColor3uiv(const GLuint * v) {
    glColor3uiv_INDEXED *packed_data = malloc(sizeof(glColor3uiv_INDEXED));
    packed_data->func = glColor3uiv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3us) || defined(DISABLE_SKIP)
void glColor3us(GLushort red, GLushort green, GLushort blue) {
    glColor3us_INDEXED *packed_data = malloc(sizeof(glColor3us_INDEXED));
    packed_data->func = glColor3us_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor3usv) || defined(DISABLE_SKIP)
void glColor3usv(const GLushort * v) {
    glColor3usv_INDEXED *packed_data = malloc(sizeof(glColor3usv_INDEXED));
    packed_data->func = glColor3usv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4b) || defined(DISABLE_SKIP)
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    glColor4b_INDEXED *packed_data = malloc(sizeof(glColor4b_INDEXED));
    packed_data->func = glColor4b_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4bv) || defined(DISABLE_SKIP)
void glColor4bv(const GLbyte * v) {
    glColor4bv_INDEXED *packed_data = malloc(sizeof(glColor4bv_INDEXED));
    packed_data->func = glColor4bv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4d) || defined(DISABLE_SKIP)
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    glColor4d_INDEXED *packed_data = malloc(sizeof(glColor4d_INDEXED));
    packed_data->func = glColor4d_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4dv) || defined(DISABLE_SKIP)
void glColor4dv(const GLdouble * v) {
    glColor4dv_INDEXED *packed_data = malloc(sizeof(glColor4dv_INDEXED));
    packed_data->func = glColor4dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4f) || defined(DISABLE_SKIP)
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glColor4f_INDEXED *packed_data = malloc(sizeof(glColor4f_INDEXED));
    packed_data->func = glColor4f_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4fv) || defined(DISABLE_SKIP)
void glColor4fv(const GLfloat * v) {
    glColor4fv_INDEXED *packed_data = malloc(sizeof(glColor4fv_INDEXED));
    packed_data->func = glColor4fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4i) || defined(DISABLE_SKIP)
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
    glColor4i_INDEXED *packed_data = malloc(sizeof(glColor4i_INDEXED));
    packed_data->func = glColor4i_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4iv) || defined(DISABLE_SKIP)
void glColor4iv(const GLint * v) {
    glColor4iv_INDEXED *packed_data = malloc(sizeof(glColor4iv_INDEXED));
    packed_data->func = glColor4iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4s) || defined(DISABLE_SKIP)
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    glColor4s_INDEXED *packed_data = malloc(sizeof(glColor4s_INDEXED));
    packed_data->func = glColor4s_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4sv) || defined(DISABLE_SKIP)
void glColor4sv(const GLshort * v) {
    glColor4sv_INDEXED *packed_data = malloc(sizeof(glColor4sv_INDEXED));
    packed_data->func = glColor4sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4ub) || defined(DISABLE_SKIP)
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    glColor4ub_INDEXED *packed_data = malloc(sizeof(glColor4ub_INDEXED));
    packed_data->func = glColor4ub_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4ubv) || defined(DISABLE_SKIP)
void glColor4ubv(const GLubyte * v) {
    glColor4ubv_INDEXED *packed_data = malloc(sizeof(glColor4ubv_INDEXED));
    packed_data->func = glColor4ubv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4ui) || defined(DISABLE_SKIP)
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    glColor4ui_INDEXED *packed_data = malloc(sizeof(glColor4ui_INDEXED));
    packed_data->func = glColor4ui_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4uiv) || defined(DISABLE_SKIP)
void glColor4uiv(const GLuint * v) {
    glColor4uiv_INDEXED *packed_data = malloc(sizeof(glColor4uiv_INDEXED));
    packed_data->func = glColor4uiv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4us) || defined(DISABLE_SKIP)
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    glColor4us_INDEXED *packed_data = malloc(sizeof(glColor4us_INDEXED));
    packed_data->func = glColor4us_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColor4usv) || defined(DISABLE_SKIP)
void glColor4usv(const GLushort * v) {
    glColor4usv_INDEXED *packed_data = malloc(sizeof(glColor4usv_INDEXED));
    packed_data->func = glColor4usv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColorMask) || defined(DISABLE_SKIP)
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    glColorMask_INDEXED *packed_data = malloc(sizeof(glColorMask_INDEXED));
    packed_data->func = glColorMask_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColorMaterial) || defined(DISABLE_SKIP)
void glColorMaterial(GLenum face, GLenum mode) {
    glColorMaterial_INDEXED *packed_data = malloc(sizeof(glColorMaterial_INDEXED));
    packed_data->func = glColorMaterial_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColorPointer) || defined(DISABLE_SKIP)
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glColorPointer_INDEXED *packed_data = malloc(sizeof(glColorPointer_INDEXED));
    packed_data->func = glColorPointer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColorSubTable) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glColorTable) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glColorTableParameterfv) || defined(DISABLE_SKIP)
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glColorTableParameterfv_INDEXED *packed_data = malloc(sizeof(glColorTableParameterfv_INDEXED));
    packed_data->func = glColorTableParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glColorTableParameteriv) || defined(DISABLE_SKIP)
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glColorTableParameteriv_INDEXED *packed_data = malloc(sizeof(glColorTableParameteriv_INDEXED));
    packed_data->func = glColorTableParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glCompressedTexImage1D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCompressedTexImage2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCompressedTexImage3D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCompressedTexSubImage1D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCompressedTexSubImage2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCompressedTexSubImage3D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glConvolutionFilter1D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glConvolutionFilter2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glConvolutionParameterf) || defined(DISABLE_SKIP)
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
    glConvolutionParameterf_INDEXED *packed_data = malloc(sizeof(glConvolutionParameterf_INDEXED));
    packed_data->func = glConvolutionParameterf_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glConvolutionParameterfv) || defined(DISABLE_SKIP)
void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glConvolutionParameterfv_INDEXED *packed_data = malloc(sizeof(glConvolutionParameterfv_INDEXED));
    packed_data->func = glConvolutionParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glConvolutionParameteri) || defined(DISABLE_SKIP)
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
    glConvolutionParameteri_INDEXED *packed_data = malloc(sizeof(glConvolutionParameteri_INDEXED));
    packed_data->func = glConvolutionParameteri_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glConvolutionParameteriv) || defined(DISABLE_SKIP)
void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glConvolutionParameteriv_INDEXED *packed_data = malloc(sizeof(glConvolutionParameteriv_INDEXED));
    packed_data->func = glConvolutionParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glCopyColorSubTable) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyColorTable) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyConvolutionFilter1D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyConvolutionFilter2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyPixels) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyTexImage1D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyTexImage2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyTexSubImage1D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyTexSubImage2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCopyTexSubImage3D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glCullFace) || defined(DISABLE_SKIP)
void glCullFace(GLenum mode) {
    glCullFace_INDEXED *packed_data = malloc(sizeof(glCullFace_INDEXED));
    packed_data->func = glCullFace_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDeleteBuffers) || defined(DISABLE_SKIP)
void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    glDeleteBuffers_INDEXED *packed_data = malloc(sizeof(glDeleteBuffers_INDEXED));
    packed_data->func = glDeleteBuffers_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffers;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDeleteLists) || defined(DISABLE_SKIP)
void glDeleteLists(GLuint list, GLsizei range) {
    glDeleteLists_INDEXED *packed_data = malloc(sizeof(glDeleteLists_INDEXED));
    packed_data->func = glDeleteLists_INDEX;
    packed_data->args.a1 = list;
    packed_data->args.a2 = range;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDeleteQueries) || defined(DISABLE_SKIP)
void glDeleteQueries(GLsizei n, const GLuint * ids) {
    glDeleteQueries_INDEXED *packed_data = malloc(sizeof(glDeleteQueries_INDEXED));
    packed_data->func = glDeleteQueries_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = ids;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDeleteTextures) || defined(DISABLE_SKIP)
void glDeleteTextures(GLsizei n, const GLuint * textures) {
    glDeleteTextures_INDEXED *packed_data = malloc(sizeof(glDeleteTextures_INDEXED));
    packed_data->func = glDeleteTextures_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDepthFunc) || defined(DISABLE_SKIP)
void glDepthFunc(GLenum func) {
    glDepthFunc_INDEXED *packed_data = malloc(sizeof(glDepthFunc_INDEXED));
    packed_data->func = glDepthFunc_INDEX;
    packed_data->args.a1 = func;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDepthMask) || defined(DISABLE_SKIP)
void glDepthMask(GLboolean flag) {
    glDepthMask_INDEXED *packed_data = malloc(sizeof(glDepthMask_INDEXED));
    packed_data->func = glDepthMask_INDEX;
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDepthRange) || defined(DISABLE_SKIP)
void glDepthRange(GLdouble near, GLdouble far) {
    glDepthRange_INDEXED *packed_data = malloc(sizeof(glDepthRange_INDEXED));
    packed_data->func = glDepthRange_INDEX;
    packed_data->args.a1 = near;
    packed_data->args.a2 = far;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDisable) || defined(DISABLE_SKIP)
void glDisable(GLenum cap) {
    glDisable_INDEXED *packed_data = malloc(sizeof(glDisable_INDEXED));
    packed_data->func = glDisable_INDEX;
    packed_data->args.a1 = cap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDisableClientState) || defined(DISABLE_SKIP)
void glDisableClientState(GLenum array) {
    glDisableClientState_INDEXED *packed_data = malloc(sizeof(glDisableClientState_INDEXED));
    packed_data->func = glDisableClientState_INDEX;
    packed_data->args.a1 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDrawArrays) || defined(DISABLE_SKIP)
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    glDrawArrays_INDEXED *packed_data = malloc(sizeof(glDrawArrays_INDEXED));
    packed_data->func = glDrawArrays_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDrawBuffer) || defined(DISABLE_SKIP)
void glDrawBuffer(GLenum mode) {
    glDrawBuffer_INDEXED *packed_data = malloc(sizeof(glDrawBuffer_INDEXED));
    packed_data->func = glDrawBuffer_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDrawElements) || defined(DISABLE_SKIP)
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    glDrawElements_INDEXED *packed_data = malloc(sizeof(glDrawElements_INDEXED));
    packed_data->func = glDrawElements_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = count;
    packed_data->args.a3 = type;
    packed_data->args.a4 = indices;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glDrawPixels) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glDrawRangeElements) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glEdgeFlag) || defined(DISABLE_SKIP)
void glEdgeFlag(GLboolean flag) {
    glEdgeFlag_INDEXED *packed_data = malloc(sizeof(glEdgeFlag_INDEXED));
    packed_data->func = glEdgeFlag_INDEX;
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEdgeFlagPointer) || defined(DISABLE_SKIP)
void glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer) {
    glEdgeFlagPointer_INDEXED *packed_data = malloc(sizeof(glEdgeFlagPointer_INDEXED));
    packed_data->func = glEdgeFlagPointer_INDEX;
    packed_data->args.a1 = stride;
    packed_data->args.a2 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEdgeFlagv) || defined(DISABLE_SKIP)
void glEdgeFlagv(const GLboolean * flag) {
    glEdgeFlagv_INDEXED *packed_data = malloc(sizeof(glEdgeFlagv_INDEXED));
    packed_data->func = glEdgeFlagv_INDEX;
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEnable) || defined(DISABLE_SKIP)
void glEnable(GLenum cap) {
    glEnable_INDEXED *packed_data = malloc(sizeof(glEnable_INDEXED));
    packed_data->func = glEnable_INDEX;
    packed_data->args.a1 = cap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEnableClientState) || defined(DISABLE_SKIP)
void glEnableClientState(GLenum array) {
    glEnableClientState_INDEXED *packed_data = malloc(sizeof(glEnableClientState_INDEXED));
    packed_data->func = glEnableClientState_INDEX;
    packed_data->args.a1 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEnd) || defined(DISABLE_SKIP)
void glEnd() {
    glEnd_INDEXED *packed_data = malloc(sizeof(glEnd_INDEXED));
    packed_data->func = glEnd_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEndList) || defined(DISABLE_SKIP)
void glEndList() {
    glEndList_INDEXED *packed_data = malloc(sizeof(glEndList_INDEXED));
    packed_data->func = glEndList_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEndQuery) || defined(DISABLE_SKIP)
void glEndQuery(GLenum target) {
    glEndQuery_INDEXED *packed_data = malloc(sizeof(glEndQuery_INDEXED));
    packed_data->func = glEndQuery_INDEX;
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalCoord1d) || defined(DISABLE_SKIP)
void glEvalCoord1d(GLdouble u) {
    glEvalCoord1d_INDEXED *packed_data = malloc(sizeof(glEvalCoord1d_INDEXED));
    packed_data->func = glEvalCoord1d_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalCoord1dv) || defined(DISABLE_SKIP)
void glEvalCoord1dv(const GLdouble * u) {
    glEvalCoord1dv_INDEXED *packed_data = malloc(sizeof(glEvalCoord1dv_INDEXED));
    packed_data->func = glEvalCoord1dv_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalCoord1f) || defined(DISABLE_SKIP)
void glEvalCoord1f(GLfloat u) {
    glEvalCoord1f_INDEXED *packed_data = malloc(sizeof(glEvalCoord1f_INDEXED));
    packed_data->func = glEvalCoord1f_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalCoord1fv) || defined(DISABLE_SKIP)
void glEvalCoord1fv(const GLfloat * u) {
    glEvalCoord1fv_INDEXED *packed_data = malloc(sizeof(glEvalCoord1fv_INDEXED));
    packed_data->func = glEvalCoord1fv_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalCoord2d) || defined(DISABLE_SKIP)
void glEvalCoord2d(GLdouble u, GLdouble v) {
    glEvalCoord2d_INDEXED *packed_data = malloc(sizeof(glEvalCoord2d_INDEXED));
    packed_data->func = glEvalCoord2d_INDEX;
    packed_data->args.a1 = u;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalCoord2dv) || defined(DISABLE_SKIP)
void glEvalCoord2dv(const GLdouble * u) {
    glEvalCoord2dv_INDEXED *packed_data = malloc(sizeof(glEvalCoord2dv_INDEXED));
    packed_data->func = glEvalCoord2dv_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalCoord2f) || defined(DISABLE_SKIP)
void glEvalCoord2f(GLfloat u, GLfloat v) {
    glEvalCoord2f_INDEXED *packed_data = malloc(sizeof(glEvalCoord2f_INDEXED));
    packed_data->func = glEvalCoord2f_INDEX;
    packed_data->args.a1 = u;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalCoord2fv) || defined(DISABLE_SKIP)
void glEvalCoord2fv(const GLfloat * u) {
    glEvalCoord2fv_INDEXED *packed_data = malloc(sizeof(glEvalCoord2fv_INDEXED));
    packed_data->func = glEvalCoord2fv_INDEX;
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalMesh1) || defined(DISABLE_SKIP)
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    glEvalMesh1_INDEXED *packed_data = malloc(sizeof(glEvalMesh1_INDEXED));
    packed_data->func = glEvalMesh1_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = i1;
    packed_data->args.a3 = i2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalMesh2) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glEvalPoint1) || defined(DISABLE_SKIP)
void glEvalPoint1(GLint i) {
    glEvalPoint1_INDEXED *packed_data = malloc(sizeof(glEvalPoint1_INDEXED));
    packed_data->func = glEvalPoint1_INDEX;
    packed_data->args.a1 = i;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glEvalPoint2) || defined(DISABLE_SKIP)
void glEvalPoint2(GLint i, GLint j) {
    glEvalPoint2_INDEXED *packed_data = malloc(sizeof(glEvalPoint2_INDEXED));
    packed_data->func = glEvalPoint2_INDEX;
    packed_data->args.a1 = i;
    packed_data->args.a2 = j;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFeedbackBuffer) || defined(DISABLE_SKIP)
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
    glFeedbackBuffer_INDEXED *packed_data = malloc(sizeof(glFeedbackBuffer_INDEXED));
    packed_data->func = glFeedbackBuffer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFinish) || defined(DISABLE_SKIP)
void glFinish() {
    glFinish_INDEXED *packed_data = malloc(sizeof(glFinish_INDEXED));
    packed_data->func = glFinish_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFlush) || defined(DISABLE_SKIP)
void glFlush() {
    glFlush_INDEXED *packed_data = malloc(sizeof(glFlush_INDEXED));
    packed_data->func = glFlush_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogCoordPointer) || defined(DISABLE_SKIP)
void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glFogCoordPointer_INDEXED *packed_data = malloc(sizeof(glFogCoordPointer_INDEXED));
    packed_data->func = glFogCoordPointer_INDEX;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogCoordd) || defined(DISABLE_SKIP)
void glFogCoordd(GLdouble coord) {
    glFogCoordd_INDEXED *packed_data = malloc(sizeof(glFogCoordd_INDEXED));
    packed_data->func = glFogCoordd_INDEX;
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogCoorddv) || defined(DISABLE_SKIP)
void glFogCoorddv(const GLdouble * coord) {
    glFogCoorddv_INDEXED *packed_data = malloc(sizeof(glFogCoorddv_INDEXED));
    packed_data->func = glFogCoorddv_INDEX;
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogCoordf) || defined(DISABLE_SKIP)
void glFogCoordf(GLfloat coord) {
    glFogCoordf_INDEXED *packed_data = malloc(sizeof(glFogCoordf_INDEXED));
    packed_data->func = glFogCoordf_INDEX;
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogCoordfv) || defined(DISABLE_SKIP)
void glFogCoordfv(const GLfloat * coord) {
    glFogCoordfv_INDEXED *packed_data = malloc(sizeof(glFogCoordfv_INDEXED));
    packed_data->func = glFogCoordfv_INDEX;
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogf) || defined(DISABLE_SKIP)
void glFogf(GLenum pname, GLfloat param) {
    glFogf_INDEXED *packed_data = malloc(sizeof(glFogf_INDEXED));
    packed_data->func = glFogf_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogfv) || defined(DISABLE_SKIP)
void glFogfv(GLenum pname, const GLfloat * params) {
    glFogfv_INDEXED *packed_data = malloc(sizeof(glFogfv_INDEXED));
    packed_data->func = glFogfv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogi) || defined(DISABLE_SKIP)
void glFogi(GLenum pname, GLint param) {
    glFogi_INDEXED *packed_data = malloc(sizeof(glFogi_INDEXED));
    packed_data->func = glFogi_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFogiv) || defined(DISABLE_SKIP)
void glFogiv(GLenum pname, const GLint * params) {
    glFogiv_INDEXED *packed_data = malloc(sizeof(glFogiv_INDEXED));
    packed_data->func = glFogiv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFrontFace) || defined(DISABLE_SKIP)
void glFrontFace(GLenum mode) {
    glFrontFace_INDEXED *packed_data = malloc(sizeof(glFrontFace_INDEXED));
    packed_data->func = glFrontFace_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glFrustum) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glGenBuffers) || defined(DISABLE_SKIP)
void glGenBuffers(GLsizei n, GLuint * buffers) {
    glGenBuffers_INDEXED *packed_data = malloc(sizeof(glGenBuffers_INDEXED));
    packed_data->func = glGenBuffers_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffers;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGenLists) || defined(DISABLE_SKIP)
GLuint glGenLists(GLsizei range) {
    glGenLists_INDEXED *packed_data = malloc(sizeof(glGenLists_INDEXED));
    packed_data->func = glGenLists_INDEX;
    packed_data->args.a1 = range;
    GLuint ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glGenQueries) || defined(DISABLE_SKIP)
void glGenQueries(GLsizei n, GLuint * ids) {
    glGenQueries_INDEXED *packed_data = malloc(sizeof(glGenQueries_INDEXED));
    packed_data->func = glGenQueries_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = ids;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGenTextures) || defined(DISABLE_SKIP)
void glGenTextures(GLsizei n, GLuint * textures) {
    glGenTextures_INDEXED *packed_data = malloc(sizeof(glGenTextures_INDEXED));
    packed_data->func = glGenTextures_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetBooleanv) || defined(DISABLE_SKIP)
void glGetBooleanv(GLenum pname, GLboolean * params) {
    glGetBooleanv_INDEXED *packed_data = malloc(sizeof(glGetBooleanv_INDEXED));
    packed_data->func = glGetBooleanv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetBufferParameteriv) || defined(DISABLE_SKIP)
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetBufferParameteriv_INDEXED *packed_data = malloc(sizeof(glGetBufferParameteriv_INDEXED));
    packed_data->func = glGetBufferParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetBufferPointerv) || defined(DISABLE_SKIP)
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params) {
    glGetBufferPointerv_INDEXED *packed_data = malloc(sizeof(glGetBufferPointerv_INDEXED));
    packed_data->func = glGetBufferPointerv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetBufferSubData) || defined(DISABLE_SKIP)
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
    glGetBufferSubData_INDEXED *packed_data = malloc(sizeof(glGetBufferSubData_INDEXED));
    packed_data->func = glGetBufferSubData_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = size;
    packed_data->args.a4 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetClipPlane) || defined(DISABLE_SKIP)
void glGetClipPlane(GLenum plane, GLdouble * equation) {
    glGetClipPlane_INDEXED *packed_data = malloc(sizeof(glGetClipPlane_INDEXED));
    packed_data->func = glGetClipPlane_INDEX;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetColorTable) || defined(DISABLE_SKIP)
void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid * table) {
    glGetColorTable_INDEXED *packed_data = malloc(sizeof(glGetColorTable_INDEXED));
    packed_data->func = glGetColorTable_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = table;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetColorTableParameterfv) || defined(DISABLE_SKIP)
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetColorTableParameterfv_INDEXED *packed_data = malloc(sizeof(glGetColorTableParameterfv_INDEXED));
    packed_data->func = glGetColorTableParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetColorTableParameteriv) || defined(DISABLE_SKIP)
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetColorTableParameteriv_INDEXED *packed_data = malloc(sizeof(glGetColorTableParameteriv_INDEXED));
    packed_data->func = glGetColorTableParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetCompressedTexImage) || defined(DISABLE_SKIP)
void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img) {
    glGetCompressedTexImage_INDEXED *packed_data = malloc(sizeof(glGetCompressedTexImage_INDEXED));
    packed_data->func = glGetCompressedTexImage_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = img;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetConvolutionFilter) || defined(DISABLE_SKIP)
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid * image) {
    glGetConvolutionFilter_INDEXED *packed_data = malloc(sizeof(glGetConvolutionFilter_INDEXED));
    packed_data->func = glGetConvolutionFilter_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = image;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetConvolutionParameterfv) || defined(DISABLE_SKIP)
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetConvolutionParameterfv_INDEXED *packed_data = malloc(sizeof(glGetConvolutionParameterfv_INDEXED));
    packed_data->func = glGetConvolutionParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetConvolutionParameteriv) || defined(DISABLE_SKIP)
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetConvolutionParameteriv_INDEXED *packed_data = malloc(sizeof(glGetConvolutionParameteriv_INDEXED));
    packed_data->func = glGetConvolutionParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetDoublev) || defined(DISABLE_SKIP)
void glGetDoublev(GLenum pname, GLdouble * params) {
    glGetDoublev_INDEXED *packed_data = malloc(sizeof(glGetDoublev_INDEXED));
    packed_data->func = glGetDoublev_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetError) || defined(DISABLE_SKIP)
GLenum glGetError() {
    glGetError_INDEXED *packed_data = malloc(sizeof(glGetError_INDEXED));
    packed_data->func = glGetError_INDEX;
    GLenum ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glGetFloatv) || defined(DISABLE_SKIP)
void glGetFloatv(GLenum pname, GLfloat * params) {
    glGetFloatv_INDEXED *packed_data = malloc(sizeof(glGetFloatv_INDEXED));
    packed_data->func = glGetFloatv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetHistogram) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glGetHistogramParameterfv) || defined(DISABLE_SKIP)
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetHistogramParameterfv_INDEXED *packed_data = malloc(sizeof(glGetHistogramParameterfv_INDEXED));
    packed_data->func = glGetHistogramParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetHistogramParameteriv) || defined(DISABLE_SKIP)
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetHistogramParameteriv_INDEXED *packed_data = malloc(sizeof(glGetHistogramParameteriv_INDEXED));
    packed_data->func = glGetHistogramParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetIntegerv) || defined(DISABLE_SKIP)
void glGetIntegerv(GLenum pname, GLint * params) {
    glGetIntegerv_INDEXED *packed_data = malloc(sizeof(glGetIntegerv_INDEXED));
    packed_data->func = glGetIntegerv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetLightfv) || defined(DISABLE_SKIP)
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    glGetLightfv_INDEXED *packed_data = malloc(sizeof(glGetLightfv_INDEXED));
    packed_data->func = glGetLightfv_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetLightiv) || defined(DISABLE_SKIP)
void glGetLightiv(GLenum light, GLenum pname, GLint * params) {
    glGetLightiv_INDEXED *packed_data = malloc(sizeof(glGetLightiv_INDEXED));
    packed_data->func = glGetLightiv_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetMapdv) || defined(DISABLE_SKIP)
void glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
    glGetMapdv_INDEXED *packed_data = malloc(sizeof(glGetMapdv_INDEXED));
    packed_data->func = glGetMapdv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetMapfv) || defined(DISABLE_SKIP)
void glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
    glGetMapfv_INDEXED *packed_data = malloc(sizeof(glGetMapfv_INDEXED));
    packed_data->func = glGetMapfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetMapiv) || defined(DISABLE_SKIP)
void glGetMapiv(GLenum target, GLenum query, GLint * v) {
    glGetMapiv_INDEXED *packed_data = malloc(sizeof(glGetMapiv_INDEXED));
    packed_data->func = glGetMapiv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetMaterialfv) || defined(DISABLE_SKIP)
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    glGetMaterialfv_INDEXED *packed_data = malloc(sizeof(glGetMaterialfv_INDEXED));
    packed_data->func = glGetMaterialfv_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetMaterialiv) || defined(DISABLE_SKIP)
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
    glGetMaterialiv_INDEXED *packed_data = malloc(sizeof(glGetMaterialiv_INDEXED));
    packed_data->func = glGetMaterialiv_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetMinmax) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glGetMinmaxParameterfv) || defined(DISABLE_SKIP)
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetMinmaxParameterfv_INDEXED *packed_data = malloc(sizeof(glGetMinmaxParameterfv_INDEXED));
    packed_data->func = glGetMinmaxParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetMinmaxParameteriv) || defined(DISABLE_SKIP)
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetMinmaxParameteriv_INDEXED *packed_data = malloc(sizeof(glGetMinmaxParameteriv_INDEXED));
    packed_data->func = glGetMinmaxParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetPixelMapfv) || defined(DISABLE_SKIP)
void glGetPixelMapfv(GLenum map, GLfloat * values) {
    glGetPixelMapfv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapfv_INDEXED));
    packed_data->func = glGetPixelMapfv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetPixelMapuiv) || defined(DISABLE_SKIP)
void glGetPixelMapuiv(GLenum map, GLuint * values) {
    glGetPixelMapuiv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapuiv_INDEXED));
    packed_data->func = glGetPixelMapuiv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetPixelMapusv) || defined(DISABLE_SKIP)
void glGetPixelMapusv(GLenum map, GLushort * values) {
    glGetPixelMapusv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapusv_INDEXED));
    packed_data->func = glGetPixelMapusv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetPointerv) || defined(DISABLE_SKIP)
void glGetPointerv(GLenum pname, GLvoid ** params) {
    glGetPointerv_INDEXED *packed_data = malloc(sizeof(glGetPointerv_INDEXED));
    packed_data->func = glGetPointerv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetPolygonStipple) || defined(DISABLE_SKIP)
void glGetPolygonStipple(GLubyte * mask) {
    glGetPolygonStipple_INDEXED *packed_data = malloc(sizeof(glGetPolygonStipple_INDEXED));
    packed_data->func = glGetPolygonStipple_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetQueryObjectiv) || defined(DISABLE_SKIP)
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    glGetQueryObjectiv_INDEXED *packed_data = malloc(sizeof(glGetQueryObjectiv_INDEXED));
    packed_data->func = glGetQueryObjectiv_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetQueryObjectuiv) || defined(DISABLE_SKIP)
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    glGetQueryObjectuiv_INDEXED *packed_data = malloc(sizeof(glGetQueryObjectuiv_INDEXED));
    packed_data->func = glGetQueryObjectuiv_INDEX;
    packed_data->args.a1 = id;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetQueryiv) || defined(DISABLE_SKIP)
void glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    glGetQueryiv_INDEXED *packed_data = malloc(sizeof(glGetQueryiv_INDEXED));
    packed_data->func = glGetQueryiv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetSeparableFilter) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glGetString) || defined(DISABLE_SKIP)
const GLubyte * glGetString(GLenum name) {
    glGetString_INDEXED *packed_data = malloc(sizeof(glGetString_INDEXED));
    packed_data->func = glGetString_INDEX;
    packed_data->args.a1 = name;
    const GLubyte * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glGetTexEnvfv) || defined(DISABLE_SKIP)
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetTexEnvfv_INDEXED *packed_data = malloc(sizeof(glGetTexEnvfv_INDEXED));
    packed_data->func = glGetTexEnvfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetTexEnviv) || defined(DISABLE_SKIP)
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    glGetTexEnviv_INDEXED *packed_data = malloc(sizeof(glGetTexEnviv_INDEXED));
    packed_data->func = glGetTexEnviv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetTexGendv) || defined(DISABLE_SKIP)
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
    glGetTexGendv_INDEXED *packed_data = malloc(sizeof(glGetTexGendv_INDEXED));
    packed_data->func = glGetTexGendv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetTexGenfv) || defined(DISABLE_SKIP)
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
    glGetTexGenfv_INDEXED *packed_data = malloc(sizeof(glGetTexGenfv_INDEXED));
    packed_data->func = glGetTexGenfv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetTexGeniv) || defined(DISABLE_SKIP)
void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
    glGetTexGeniv_INDEXED *packed_data = malloc(sizeof(glGetTexGeniv_INDEXED));
    packed_data->func = glGetTexGeniv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetTexImage) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glGetTexLevelParameterfv) || defined(DISABLE_SKIP)
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    glGetTexLevelParameterfv_INDEXED *packed_data = malloc(sizeof(glGetTexLevelParameterfv_INDEXED));
    packed_data->func = glGetTexLevelParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetTexLevelParameteriv) || defined(DISABLE_SKIP)
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    glGetTexLevelParameteriv_INDEXED *packed_data = malloc(sizeof(glGetTexLevelParameteriv_INDEXED));
    packed_data->func = glGetTexLevelParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetTexParameterfv) || defined(DISABLE_SKIP)
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetTexParameterfv_INDEXED *packed_data = malloc(sizeof(glGetTexParameterfv_INDEXED));
    packed_data->func = glGetTexParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glGetTexParameteriv) || defined(DISABLE_SKIP)
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetTexParameteriv_INDEXED *packed_data = malloc(sizeof(glGetTexParameteriv_INDEXED));
    packed_data->func = glGetTexParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glHint) || defined(DISABLE_SKIP)
void glHint(GLenum target, GLenum mode) {
    glHint_INDEXED *packed_data = malloc(sizeof(glHint_INDEXED));
    packed_data->func = glHint_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glHistogram) || defined(DISABLE_SKIP)
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    glHistogram_INDEXED *packed_data = malloc(sizeof(glHistogram_INDEXED));
    packed_data->func = glHistogram_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = width;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = sink;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexMask) || defined(DISABLE_SKIP)
void glIndexMask(GLuint mask) {
    glIndexMask_INDEXED *packed_data = malloc(sizeof(glIndexMask_INDEXED));
    packed_data->func = glIndexMask_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexPointer) || defined(DISABLE_SKIP)
void glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glIndexPointer_INDEXED *packed_data = malloc(sizeof(glIndexPointer_INDEXED));
    packed_data->func = glIndexPointer_INDEX;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexd) || defined(DISABLE_SKIP)
void glIndexd(GLdouble c) {
    glIndexd_INDEXED *packed_data = malloc(sizeof(glIndexd_INDEXED));
    packed_data->func = glIndexd_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexdv) || defined(DISABLE_SKIP)
void glIndexdv(const GLdouble * c) {
    glIndexdv_INDEXED *packed_data = malloc(sizeof(glIndexdv_INDEXED));
    packed_data->func = glIndexdv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexf) || defined(DISABLE_SKIP)
void glIndexf(GLfloat c) {
    glIndexf_INDEXED *packed_data = malloc(sizeof(glIndexf_INDEXED));
    packed_data->func = glIndexf_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexfv) || defined(DISABLE_SKIP)
void glIndexfv(const GLfloat * c) {
    glIndexfv_INDEXED *packed_data = malloc(sizeof(glIndexfv_INDEXED));
    packed_data->func = glIndexfv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexi) || defined(DISABLE_SKIP)
void glIndexi(GLint c) {
    glIndexi_INDEXED *packed_data = malloc(sizeof(glIndexi_INDEXED));
    packed_data->func = glIndexi_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexiv) || defined(DISABLE_SKIP)
void glIndexiv(const GLint * c) {
    glIndexiv_INDEXED *packed_data = malloc(sizeof(glIndexiv_INDEXED));
    packed_data->func = glIndexiv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexs) || defined(DISABLE_SKIP)
void glIndexs(GLshort c) {
    glIndexs_INDEXED *packed_data = malloc(sizeof(glIndexs_INDEXED));
    packed_data->func = glIndexs_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexsv) || defined(DISABLE_SKIP)
void glIndexsv(const GLshort * c) {
    glIndexsv_INDEXED *packed_data = malloc(sizeof(glIndexsv_INDEXED));
    packed_data->func = glIndexsv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexub) || defined(DISABLE_SKIP)
void glIndexub(GLubyte c) {
    glIndexub_INDEXED *packed_data = malloc(sizeof(glIndexub_INDEXED));
    packed_data->func = glIndexub_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIndexubv) || defined(DISABLE_SKIP)
void glIndexubv(const GLubyte * c) {
    glIndexubv_INDEXED *packed_data = malloc(sizeof(glIndexubv_INDEXED));
    packed_data->func = glIndexubv_INDEX;
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glInitNames) || defined(DISABLE_SKIP)
void glInitNames() {
    glInitNames_INDEXED *packed_data = malloc(sizeof(glInitNames_INDEXED));
    packed_data->func = glInitNames_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glInterleavedArrays) || defined(DISABLE_SKIP)
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid * pointer) {
    glInterleavedArrays_INDEXED *packed_data = malloc(sizeof(glInterleavedArrays_INDEXED));
    packed_data->func = glInterleavedArrays_INDEX;
    packed_data->args.a1 = format;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glIsBuffer) || defined(DISABLE_SKIP)
GLboolean glIsBuffer(GLuint buffer) {
    glIsBuffer_INDEXED *packed_data = malloc(sizeof(glIsBuffer_INDEXED));
    packed_data->func = glIsBuffer_INDEX;
    packed_data->args.a1 = buffer;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glIsEnabled) || defined(DISABLE_SKIP)
GLboolean glIsEnabled(GLenum cap) {
    glIsEnabled_INDEXED *packed_data = malloc(sizeof(glIsEnabled_INDEXED));
    packed_data->func = glIsEnabled_INDEX;
    packed_data->args.a1 = cap;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glIsList) || defined(DISABLE_SKIP)
GLboolean glIsList(GLuint list) {
    glIsList_INDEXED *packed_data = malloc(sizeof(glIsList_INDEXED));
    packed_data->func = glIsList_INDEX;
    packed_data->args.a1 = list;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glIsQuery) || defined(DISABLE_SKIP)
GLboolean glIsQuery(GLuint id) {
    glIsQuery_INDEXED *packed_data = malloc(sizeof(glIsQuery_INDEXED));
    packed_data->func = glIsQuery_INDEX;
    packed_data->args.a1 = id;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glIsTexture) || defined(DISABLE_SKIP)
GLboolean glIsTexture(GLuint texture) {
    glIsTexture_INDEXED *packed_data = malloc(sizeof(glIsTexture_INDEXED));
    packed_data->func = glIsTexture_INDEX;
    packed_data->args.a1 = texture;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glLightModelf) || defined(DISABLE_SKIP)
void glLightModelf(GLenum pname, GLfloat param) {
    glLightModelf_INDEXED *packed_data = malloc(sizeof(glLightModelf_INDEXED));
    packed_data->func = glLightModelf_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLightModelfv) || defined(DISABLE_SKIP)
void glLightModelfv(GLenum pname, const GLfloat * params) {
    glLightModelfv_INDEXED *packed_data = malloc(sizeof(glLightModelfv_INDEXED));
    packed_data->func = glLightModelfv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLightModeli) || defined(DISABLE_SKIP)
void glLightModeli(GLenum pname, GLint param) {
    glLightModeli_INDEXED *packed_data = malloc(sizeof(glLightModeli_INDEXED));
    packed_data->func = glLightModeli_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLightModeliv) || defined(DISABLE_SKIP)
void glLightModeliv(GLenum pname, const GLint * params) {
    glLightModeliv_INDEXED *packed_data = malloc(sizeof(glLightModeliv_INDEXED));
    packed_data->func = glLightModeliv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLightf) || defined(DISABLE_SKIP)
void glLightf(GLenum light, GLenum pname, GLfloat param) {
    glLightf_INDEXED *packed_data = malloc(sizeof(glLightf_INDEXED));
    packed_data->func = glLightf_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLightfv) || defined(DISABLE_SKIP)
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    glLightfv_INDEXED *packed_data = malloc(sizeof(glLightfv_INDEXED));
    packed_data->func = glLightfv_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLighti) || defined(DISABLE_SKIP)
void glLighti(GLenum light, GLenum pname, GLint param) {
    glLighti_INDEXED *packed_data = malloc(sizeof(glLighti_INDEXED));
    packed_data->func = glLighti_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLightiv) || defined(DISABLE_SKIP)
void glLightiv(GLenum light, GLenum pname, const GLint * params) {
    glLightiv_INDEXED *packed_data = malloc(sizeof(glLightiv_INDEXED));
    packed_data->func = glLightiv_INDEX;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLineStipple) || defined(DISABLE_SKIP)
void glLineStipple(GLint factor, GLushort pattern) {
    glLineStipple_INDEXED *packed_data = malloc(sizeof(glLineStipple_INDEXED));
    packed_data->func = glLineStipple_INDEX;
    packed_data->args.a1 = factor;
    packed_data->args.a2 = pattern;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLineWidth) || defined(DISABLE_SKIP)
void glLineWidth(GLfloat width) {
    glLineWidth_INDEXED *packed_data = malloc(sizeof(glLineWidth_INDEXED));
    packed_data->func = glLineWidth_INDEX;
    packed_data->args.a1 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glListBase) || defined(DISABLE_SKIP)
void glListBase(GLuint base) {
    glListBase_INDEXED *packed_data = malloc(sizeof(glListBase_INDEXED));
    packed_data->func = glListBase_INDEX;
    packed_data->args.a1 = base;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLoadIdentity) || defined(DISABLE_SKIP)
void glLoadIdentity() {
    glLoadIdentity_INDEXED *packed_data = malloc(sizeof(glLoadIdentity_INDEXED));
    packed_data->func = glLoadIdentity_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLoadMatrixd) || defined(DISABLE_SKIP)
void glLoadMatrixd(const GLdouble * m) {
    glLoadMatrixd_INDEXED *packed_data = malloc(sizeof(glLoadMatrixd_INDEXED));
    packed_data->func = glLoadMatrixd_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLoadMatrixf) || defined(DISABLE_SKIP)
void glLoadMatrixf(const GLfloat * m) {
    glLoadMatrixf_INDEXED *packed_data = malloc(sizeof(glLoadMatrixf_INDEXED));
    packed_data->func = glLoadMatrixf_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLoadName) || defined(DISABLE_SKIP)
void glLoadName(GLuint name) {
    glLoadName_INDEXED *packed_data = malloc(sizeof(glLoadName_INDEXED));
    packed_data->func = glLoadName_INDEX;
    packed_data->args.a1 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLoadTransposeMatrixd) || defined(DISABLE_SKIP)
void glLoadTransposeMatrixd(const GLdouble * m) {
    glLoadTransposeMatrixd_INDEXED *packed_data = malloc(sizeof(glLoadTransposeMatrixd_INDEXED));
    packed_data->func = glLoadTransposeMatrixd_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLoadTransposeMatrixf) || defined(DISABLE_SKIP)
void glLoadTransposeMatrixf(const GLfloat * m) {
    glLoadTransposeMatrixf_INDEXED *packed_data = malloc(sizeof(glLoadTransposeMatrixf_INDEXED));
    packed_data->func = glLoadTransposeMatrixf_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glLogicOp) || defined(DISABLE_SKIP)
void glLogicOp(GLenum opcode) {
    glLogicOp_INDEXED *packed_data = malloc(sizeof(glLogicOp_INDEXED));
    packed_data->func = glLogicOp_INDEX;
    packed_data->args.a1 = opcode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMap1d) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMap1f) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMap2d) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMap2f) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMapBuffer) || defined(DISABLE_SKIP)
GLvoid * glMapBuffer(GLenum target, GLenum access) {
    glMapBuffer_INDEXED *packed_data = malloc(sizeof(glMapBuffer_INDEXED));
    packed_data->func = glMapBuffer_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = access;
    GLvoid * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glMapGrid1d) || defined(DISABLE_SKIP)
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    glMapGrid1d_INDEXED *packed_data = malloc(sizeof(glMapGrid1d_INDEXED));
    packed_data->func = glMapGrid1d_INDEX;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMapGrid1f) || defined(DISABLE_SKIP)
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    glMapGrid1f_INDEXED *packed_data = malloc(sizeof(glMapGrid1f_INDEXED));
    packed_data->func = glMapGrid1f_INDEX;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMapGrid2d) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMapGrid2f) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMaterialf) || defined(DISABLE_SKIP)
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    glMaterialf_INDEXED *packed_data = malloc(sizeof(glMaterialf_INDEXED));
    packed_data->func = glMaterialf_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMaterialfv) || defined(DISABLE_SKIP)
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    glMaterialfv_INDEXED *packed_data = malloc(sizeof(glMaterialfv_INDEXED));
    packed_data->func = glMaterialfv_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMateriali) || defined(DISABLE_SKIP)
void glMateriali(GLenum face, GLenum pname, GLint param) {
    glMateriali_INDEXED *packed_data = malloc(sizeof(glMateriali_INDEXED));
    packed_data->func = glMateriali_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMaterialiv) || defined(DISABLE_SKIP)
void glMaterialiv(GLenum face, GLenum pname, const GLint * params) {
    glMaterialiv_INDEXED *packed_data = malloc(sizeof(glMaterialiv_INDEXED));
    packed_data->func = glMaterialiv_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMatrixMode) || defined(DISABLE_SKIP)
void glMatrixMode(GLenum mode) {
    glMatrixMode_INDEXED *packed_data = malloc(sizeof(glMatrixMode_INDEXED));
    packed_data->func = glMatrixMode_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMinmax) || defined(DISABLE_SKIP)
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
    glMinmax_INDEXED *packed_data = malloc(sizeof(glMinmax_INDEXED));
    packed_data->func = glMinmax_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = sink;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultMatrixd) || defined(DISABLE_SKIP)
void glMultMatrixd(const GLdouble * m) {
    glMultMatrixd_INDEXED *packed_data = malloc(sizeof(glMultMatrixd_INDEXED));
    packed_data->func = glMultMatrixd_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultMatrixf) || defined(DISABLE_SKIP)
void glMultMatrixf(const GLfloat * m) {
    glMultMatrixf_INDEXED *packed_data = malloc(sizeof(glMultMatrixf_INDEXED));
    packed_data->func = glMultMatrixf_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultTransposeMatrixd) || defined(DISABLE_SKIP)
void glMultTransposeMatrixd(const GLdouble * m) {
    glMultTransposeMatrixd_INDEXED *packed_data = malloc(sizeof(glMultTransposeMatrixd_INDEXED));
    packed_data->func = glMultTransposeMatrixd_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultTransposeMatrixf) || defined(DISABLE_SKIP)
void glMultTransposeMatrixf(const GLfloat * m) {
    glMultTransposeMatrixf_INDEXED *packed_data = malloc(sizeof(glMultTransposeMatrixf_INDEXED));
    packed_data->func = glMultTransposeMatrixf_INDEX;
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiDrawArrays) || defined(DISABLE_SKIP)
void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    glMultiDrawArrays_INDEXED *packed_data = malloc(sizeof(glMultiDrawArrays_INDEXED));
    packed_data->func = glMultiDrawArrays_INDEX;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    packed_data->args.a4 = drawcount;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiDrawElements) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMultiTexCoord1d) || defined(DISABLE_SKIP)
void glMultiTexCoord1d(GLenum target, GLdouble s) {
    glMultiTexCoord1d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1d_INDEXED));
    packed_data->func = glMultiTexCoord1d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord1dv) || defined(DISABLE_SKIP)
void glMultiTexCoord1dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord1dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1dv_INDEXED));
    packed_data->func = glMultiTexCoord1dv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord1f) || defined(DISABLE_SKIP)
void glMultiTexCoord1f(GLenum target, GLfloat s) {
    glMultiTexCoord1f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1f_INDEXED));
    packed_data->func = glMultiTexCoord1f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord1fv) || defined(DISABLE_SKIP)
void glMultiTexCoord1fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord1fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1fv_INDEXED));
    packed_data->func = glMultiTexCoord1fv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord1i) || defined(DISABLE_SKIP)
void glMultiTexCoord1i(GLenum target, GLint s) {
    glMultiTexCoord1i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1i_INDEXED));
    packed_data->func = glMultiTexCoord1i_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord1iv) || defined(DISABLE_SKIP)
void glMultiTexCoord1iv(GLenum target, const GLint * v) {
    glMultiTexCoord1iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1iv_INDEXED));
    packed_data->func = glMultiTexCoord1iv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord1s) || defined(DISABLE_SKIP)
void glMultiTexCoord1s(GLenum target, GLshort s) {
    glMultiTexCoord1s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1s_INDEXED));
    packed_data->func = glMultiTexCoord1s_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord1sv) || defined(DISABLE_SKIP)
void glMultiTexCoord1sv(GLenum target, const GLshort * v) {
    glMultiTexCoord1sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1sv_INDEXED));
    packed_data->func = glMultiTexCoord1sv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord2d) || defined(DISABLE_SKIP)
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    glMultiTexCoord2d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2d_INDEXED));
    packed_data->func = glMultiTexCoord2d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord2dv) || defined(DISABLE_SKIP)
void glMultiTexCoord2dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord2dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2dv_INDEXED));
    packed_data->func = glMultiTexCoord2dv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord2f) || defined(DISABLE_SKIP)
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    glMultiTexCoord2f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2f_INDEXED));
    packed_data->func = glMultiTexCoord2f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord2fv) || defined(DISABLE_SKIP)
void glMultiTexCoord2fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord2fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2fv_INDEXED));
    packed_data->func = glMultiTexCoord2fv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord2i) || defined(DISABLE_SKIP)
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
    glMultiTexCoord2i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2i_INDEXED));
    packed_data->func = glMultiTexCoord2i_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord2iv) || defined(DISABLE_SKIP)
void glMultiTexCoord2iv(GLenum target, const GLint * v) {
    glMultiTexCoord2iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2iv_INDEXED));
    packed_data->func = glMultiTexCoord2iv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord2s) || defined(DISABLE_SKIP)
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    glMultiTexCoord2s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2s_INDEXED));
    packed_data->func = glMultiTexCoord2s_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord2sv) || defined(DISABLE_SKIP)
void glMultiTexCoord2sv(GLenum target, const GLshort * v) {
    glMultiTexCoord2sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2sv_INDEXED));
    packed_data->func = glMultiTexCoord2sv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord3d) || defined(DISABLE_SKIP)
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    glMultiTexCoord3d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3d_INDEXED));
    packed_data->func = glMultiTexCoord3d_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord3dv) || defined(DISABLE_SKIP)
void glMultiTexCoord3dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord3dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3dv_INDEXED));
    packed_data->func = glMultiTexCoord3dv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord3f) || defined(DISABLE_SKIP)
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    glMultiTexCoord3f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3f_INDEXED));
    packed_data->func = glMultiTexCoord3f_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord3fv) || defined(DISABLE_SKIP)
void glMultiTexCoord3fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord3fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3fv_INDEXED));
    packed_data->func = glMultiTexCoord3fv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord3i) || defined(DISABLE_SKIP)
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    glMultiTexCoord3i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3i_INDEXED));
    packed_data->func = glMultiTexCoord3i_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord3iv) || defined(DISABLE_SKIP)
void glMultiTexCoord3iv(GLenum target, const GLint * v) {
    glMultiTexCoord3iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3iv_INDEXED));
    packed_data->func = glMultiTexCoord3iv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord3s) || defined(DISABLE_SKIP)
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    glMultiTexCoord3s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3s_INDEXED));
    packed_data->func = glMultiTexCoord3s_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord3sv) || defined(DISABLE_SKIP)
void glMultiTexCoord3sv(GLenum target, const GLshort * v) {
    glMultiTexCoord3sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3sv_INDEXED));
    packed_data->func = glMultiTexCoord3sv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord4d) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMultiTexCoord4dv) || defined(DISABLE_SKIP)
void glMultiTexCoord4dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord4dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4dv_INDEXED));
    packed_data->func = glMultiTexCoord4dv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord4f) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMultiTexCoord4fv) || defined(DISABLE_SKIP)
void glMultiTexCoord4fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord4fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4fv_INDEXED));
    packed_data->func = glMultiTexCoord4fv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord4i) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMultiTexCoord4iv) || defined(DISABLE_SKIP)
void glMultiTexCoord4iv(GLenum target, const GLint * v) {
    glMultiTexCoord4iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4iv_INDEXED));
    packed_data->func = glMultiTexCoord4iv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glMultiTexCoord4s) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glMultiTexCoord4sv) || defined(DISABLE_SKIP)
void glMultiTexCoord4sv(GLenum target, const GLshort * v) {
    glMultiTexCoord4sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4sv_INDEXED));
    packed_data->func = glMultiTexCoord4sv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNewList) || defined(DISABLE_SKIP)
void glNewList(GLuint list, GLenum mode) {
    glNewList_INDEXED *packed_data = malloc(sizeof(glNewList_INDEXED));
    packed_data->func = glNewList_INDEX;
    packed_data->args.a1 = list;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3b) || defined(DISABLE_SKIP)
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    glNormal3b_INDEXED *packed_data = malloc(sizeof(glNormal3b_INDEXED));
    packed_data->func = glNormal3b_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3bv) || defined(DISABLE_SKIP)
void glNormal3bv(const GLbyte * v) {
    glNormal3bv_INDEXED *packed_data = malloc(sizeof(glNormal3bv_INDEXED));
    packed_data->func = glNormal3bv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3d) || defined(DISABLE_SKIP)
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    glNormal3d_INDEXED *packed_data = malloc(sizeof(glNormal3d_INDEXED));
    packed_data->func = glNormal3d_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3dv) || defined(DISABLE_SKIP)
void glNormal3dv(const GLdouble * v) {
    glNormal3dv_INDEXED *packed_data = malloc(sizeof(glNormal3dv_INDEXED));
    packed_data->func = glNormal3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3f) || defined(DISABLE_SKIP)
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    glNormal3f_INDEXED *packed_data = malloc(sizeof(glNormal3f_INDEXED));
    packed_data->func = glNormal3f_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3fv) || defined(DISABLE_SKIP)
void glNormal3fv(const GLfloat * v) {
    glNormal3fv_INDEXED *packed_data = malloc(sizeof(glNormal3fv_INDEXED));
    packed_data->func = glNormal3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3i) || defined(DISABLE_SKIP)
void glNormal3i(GLint nx, GLint ny, GLint nz) {
    glNormal3i_INDEXED *packed_data = malloc(sizeof(glNormal3i_INDEXED));
    packed_data->func = glNormal3i_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3iv) || defined(DISABLE_SKIP)
void glNormal3iv(const GLint * v) {
    glNormal3iv_INDEXED *packed_data = malloc(sizeof(glNormal3iv_INDEXED));
    packed_data->func = glNormal3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3s) || defined(DISABLE_SKIP)
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
    glNormal3s_INDEXED *packed_data = malloc(sizeof(glNormal3s_INDEXED));
    packed_data->func = glNormal3s_INDEX;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormal3sv) || defined(DISABLE_SKIP)
void glNormal3sv(const GLshort * v) {
    glNormal3sv_INDEXED *packed_data = malloc(sizeof(glNormal3sv_INDEXED));
    packed_data->func = glNormal3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glNormalPointer) || defined(DISABLE_SKIP)
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glNormalPointer_INDEXED *packed_data = malloc(sizeof(glNormalPointer_INDEXED));
    packed_data->func = glNormalPointer_INDEX;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glOrtho) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glPassThrough) || defined(DISABLE_SKIP)
void glPassThrough(GLfloat token) {
    glPassThrough_INDEXED *packed_data = malloc(sizeof(glPassThrough_INDEXED));
    packed_data->func = glPassThrough_INDEX;
    packed_data->args.a1 = token;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPixelMapfv) || defined(DISABLE_SKIP)
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values) {
    glPixelMapfv_INDEXED *packed_data = malloc(sizeof(glPixelMapfv_INDEXED));
    packed_data->func = glPixelMapfv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPixelMapuiv) || defined(DISABLE_SKIP)
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values) {
    glPixelMapuiv_INDEXED *packed_data = malloc(sizeof(glPixelMapuiv_INDEXED));
    packed_data->func = glPixelMapuiv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPixelMapusv) || defined(DISABLE_SKIP)
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values) {
    glPixelMapusv_INDEXED *packed_data = malloc(sizeof(glPixelMapusv_INDEXED));
    packed_data->func = glPixelMapusv_INDEX;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPixelStoref) || defined(DISABLE_SKIP)
void glPixelStoref(GLenum pname, GLfloat param) {
    glPixelStoref_INDEXED *packed_data = malloc(sizeof(glPixelStoref_INDEXED));
    packed_data->func = glPixelStoref_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPixelStorei) || defined(DISABLE_SKIP)
void glPixelStorei(GLenum pname, GLint param) {
    glPixelStorei_INDEXED *packed_data = malloc(sizeof(glPixelStorei_INDEXED));
    packed_data->func = glPixelStorei_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPixelTransferf) || defined(DISABLE_SKIP)
void glPixelTransferf(GLenum pname, GLfloat param) {
    glPixelTransferf_INDEXED *packed_data = malloc(sizeof(glPixelTransferf_INDEXED));
    packed_data->func = glPixelTransferf_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPixelTransferi) || defined(DISABLE_SKIP)
void glPixelTransferi(GLenum pname, GLint param) {
    glPixelTransferi_INDEXED *packed_data = malloc(sizeof(glPixelTransferi_INDEXED));
    packed_data->func = glPixelTransferi_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPixelZoom) || defined(DISABLE_SKIP)
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    glPixelZoom_INDEXED *packed_data = malloc(sizeof(glPixelZoom_INDEXED));
    packed_data->func = glPixelZoom_INDEX;
    packed_data->args.a1 = xfactor;
    packed_data->args.a2 = yfactor;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPointParameterf) || defined(DISABLE_SKIP)
void glPointParameterf(GLenum pname, GLfloat param) {
    glPointParameterf_INDEXED *packed_data = malloc(sizeof(glPointParameterf_INDEXED));
    packed_data->func = glPointParameterf_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPointParameterfv) || defined(DISABLE_SKIP)
void glPointParameterfv(GLenum pname, const GLfloat * params) {
    glPointParameterfv_INDEXED *packed_data = malloc(sizeof(glPointParameterfv_INDEXED));
    packed_data->func = glPointParameterfv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPointParameteri) || defined(DISABLE_SKIP)
void glPointParameteri(GLenum pname, GLint param) {
    glPointParameteri_INDEXED *packed_data = malloc(sizeof(glPointParameteri_INDEXED));
    packed_data->func = glPointParameteri_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPointParameteriv) || defined(DISABLE_SKIP)
void glPointParameteriv(GLenum pname, const GLint * params) {
    glPointParameteriv_INDEXED *packed_data = malloc(sizeof(glPointParameteriv_INDEXED));
    packed_data->func = glPointParameteriv_INDEX;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPointSize) || defined(DISABLE_SKIP)
void glPointSize(GLfloat size) {
    glPointSize_INDEXED *packed_data = malloc(sizeof(glPointSize_INDEXED));
    packed_data->func = glPointSize_INDEX;
    packed_data->args.a1 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPolygonMode) || defined(DISABLE_SKIP)
void glPolygonMode(GLenum face, GLenum mode) {
    glPolygonMode_INDEXED *packed_data = malloc(sizeof(glPolygonMode_INDEXED));
    packed_data->func = glPolygonMode_INDEX;
    packed_data->args.a1 = face;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPolygonOffset) || defined(DISABLE_SKIP)
void glPolygonOffset(GLfloat factor, GLfloat units) {
    glPolygonOffset_INDEXED *packed_data = malloc(sizeof(glPolygonOffset_INDEXED));
    packed_data->func = glPolygonOffset_INDEX;
    packed_data->args.a1 = factor;
    packed_data->args.a2 = units;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPolygonStipple) || defined(DISABLE_SKIP)
void glPolygonStipple(const GLubyte * mask) {
    glPolygonStipple_INDEXED *packed_data = malloc(sizeof(glPolygonStipple_INDEXED));
    packed_data->func = glPolygonStipple_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPopAttrib) || defined(DISABLE_SKIP)
void glPopAttrib() {
    glPopAttrib_INDEXED *packed_data = malloc(sizeof(glPopAttrib_INDEXED));
    packed_data->func = glPopAttrib_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPopClientAttrib) || defined(DISABLE_SKIP)
void glPopClientAttrib() {
    glPopClientAttrib_INDEXED *packed_data = malloc(sizeof(glPopClientAttrib_INDEXED));
    packed_data->func = glPopClientAttrib_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPopMatrix) || defined(DISABLE_SKIP)
void glPopMatrix() {
    glPopMatrix_INDEXED *packed_data = malloc(sizeof(glPopMatrix_INDEXED));
    packed_data->func = glPopMatrix_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPopName) || defined(DISABLE_SKIP)
void glPopName() {
    glPopName_INDEXED *packed_data = malloc(sizeof(glPopName_INDEXED));
    packed_data->func = glPopName_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPrioritizeTextures) || defined(DISABLE_SKIP)
void glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities) {
    glPrioritizeTextures_INDEXED *packed_data = malloc(sizeof(glPrioritizeTextures_INDEXED));
    packed_data->func = glPrioritizeTextures_INDEX;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    packed_data->args.a3 = priorities;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPushAttrib) || defined(DISABLE_SKIP)
void glPushAttrib(GLbitfield mask) {
    glPushAttrib_INDEXED *packed_data = malloc(sizeof(glPushAttrib_INDEXED));
    packed_data->func = glPushAttrib_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPushClientAttrib) || defined(DISABLE_SKIP)
void glPushClientAttrib(GLbitfield mask) {
    glPushClientAttrib_INDEXED *packed_data = malloc(sizeof(glPushClientAttrib_INDEXED));
    packed_data->func = glPushClientAttrib_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPushMatrix) || defined(DISABLE_SKIP)
void glPushMatrix() {
    glPushMatrix_INDEXED *packed_data = malloc(sizeof(glPushMatrix_INDEXED));
    packed_data->func = glPushMatrix_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glPushName) || defined(DISABLE_SKIP)
void glPushName(GLuint name) {
    glPushName_INDEXED *packed_data = malloc(sizeof(glPushName_INDEXED));
    packed_data->func = glPushName_INDEX;
    packed_data->args.a1 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos2d) || defined(DISABLE_SKIP)
void glRasterPos2d(GLdouble x, GLdouble y) {
    glRasterPos2d_INDEXED *packed_data = malloc(sizeof(glRasterPos2d_INDEXED));
    packed_data->func = glRasterPos2d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos2dv) || defined(DISABLE_SKIP)
void glRasterPos2dv(const GLdouble * v) {
    glRasterPos2dv_INDEXED *packed_data = malloc(sizeof(glRasterPos2dv_INDEXED));
    packed_data->func = glRasterPos2dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos2f) || defined(DISABLE_SKIP)
void glRasterPos2f(GLfloat x, GLfloat y) {
    glRasterPos2f_INDEXED *packed_data = malloc(sizeof(glRasterPos2f_INDEXED));
    packed_data->func = glRasterPos2f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos2fv) || defined(DISABLE_SKIP)
void glRasterPos2fv(const GLfloat * v) {
    glRasterPos2fv_INDEXED *packed_data = malloc(sizeof(glRasterPos2fv_INDEXED));
    packed_data->func = glRasterPos2fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos2i) || defined(DISABLE_SKIP)
void glRasterPos2i(GLint x, GLint y) {
    glRasterPos2i_INDEXED *packed_data = malloc(sizeof(glRasterPos2i_INDEXED));
    packed_data->func = glRasterPos2i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos2iv) || defined(DISABLE_SKIP)
void glRasterPos2iv(const GLint * v) {
    glRasterPos2iv_INDEXED *packed_data = malloc(sizeof(glRasterPos2iv_INDEXED));
    packed_data->func = glRasterPos2iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos2s) || defined(DISABLE_SKIP)
void glRasterPos2s(GLshort x, GLshort y) {
    glRasterPos2s_INDEXED *packed_data = malloc(sizeof(glRasterPos2s_INDEXED));
    packed_data->func = glRasterPos2s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos2sv) || defined(DISABLE_SKIP)
void glRasterPos2sv(const GLshort * v) {
    glRasterPos2sv_INDEXED *packed_data = malloc(sizeof(glRasterPos2sv_INDEXED));
    packed_data->func = glRasterPos2sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos3d) || defined(DISABLE_SKIP)
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    glRasterPos3d_INDEXED *packed_data = malloc(sizeof(glRasterPos3d_INDEXED));
    packed_data->func = glRasterPos3d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos3dv) || defined(DISABLE_SKIP)
void glRasterPos3dv(const GLdouble * v) {
    glRasterPos3dv_INDEXED *packed_data = malloc(sizeof(glRasterPos3dv_INDEXED));
    packed_data->func = glRasterPos3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos3f) || defined(DISABLE_SKIP)
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    glRasterPos3f_INDEXED *packed_data = malloc(sizeof(glRasterPos3f_INDEXED));
    packed_data->func = glRasterPos3f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos3fv) || defined(DISABLE_SKIP)
void glRasterPos3fv(const GLfloat * v) {
    glRasterPos3fv_INDEXED *packed_data = malloc(sizeof(glRasterPos3fv_INDEXED));
    packed_data->func = glRasterPos3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos3i) || defined(DISABLE_SKIP)
void glRasterPos3i(GLint x, GLint y, GLint z) {
    glRasterPos3i_INDEXED *packed_data = malloc(sizeof(glRasterPos3i_INDEXED));
    packed_data->func = glRasterPos3i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos3iv) || defined(DISABLE_SKIP)
void glRasterPos3iv(const GLint * v) {
    glRasterPos3iv_INDEXED *packed_data = malloc(sizeof(glRasterPos3iv_INDEXED));
    packed_data->func = glRasterPos3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos3s) || defined(DISABLE_SKIP)
void glRasterPos3s(GLshort x, GLshort y, GLshort z) {
    glRasterPos3s_INDEXED *packed_data = malloc(sizeof(glRasterPos3s_INDEXED));
    packed_data->func = glRasterPos3s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos3sv) || defined(DISABLE_SKIP)
void glRasterPos3sv(const GLshort * v) {
    glRasterPos3sv_INDEXED *packed_data = malloc(sizeof(glRasterPos3sv_INDEXED));
    packed_data->func = glRasterPos3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos4d) || defined(DISABLE_SKIP)
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glRasterPos4d_INDEXED *packed_data = malloc(sizeof(glRasterPos4d_INDEXED));
    packed_data->func = glRasterPos4d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos4dv) || defined(DISABLE_SKIP)
void glRasterPos4dv(const GLdouble * v) {
    glRasterPos4dv_INDEXED *packed_data = malloc(sizeof(glRasterPos4dv_INDEXED));
    packed_data->func = glRasterPos4dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos4f) || defined(DISABLE_SKIP)
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glRasterPos4f_INDEXED *packed_data = malloc(sizeof(glRasterPos4f_INDEXED));
    packed_data->func = glRasterPos4f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos4fv) || defined(DISABLE_SKIP)
void glRasterPos4fv(const GLfloat * v) {
    glRasterPos4fv_INDEXED *packed_data = malloc(sizeof(glRasterPos4fv_INDEXED));
    packed_data->func = glRasterPos4fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos4i) || defined(DISABLE_SKIP)
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    glRasterPos4i_INDEXED *packed_data = malloc(sizeof(glRasterPos4i_INDEXED));
    packed_data->func = glRasterPos4i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos4iv) || defined(DISABLE_SKIP)
void glRasterPos4iv(const GLint * v) {
    glRasterPos4iv_INDEXED *packed_data = malloc(sizeof(glRasterPos4iv_INDEXED));
    packed_data->func = glRasterPos4iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos4s) || defined(DISABLE_SKIP)
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    glRasterPos4s_INDEXED *packed_data = malloc(sizeof(glRasterPos4s_INDEXED));
    packed_data->func = glRasterPos4s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRasterPos4sv) || defined(DISABLE_SKIP)
void glRasterPos4sv(const GLshort * v) {
    glRasterPos4sv_INDEXED *packed_data = malloc(sizeof(glRasterPos4sv_INDEXED));
    packed_data->func = glRasterPos4sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glReadBuffer) || defined(DISABLE_SKIP)
void glReadBuffer(GLenum mode) {
    glReadBuffer_INDEXED *packed_data = malloc(sizeof(glReadBuffer_INDEXED));
    packed_data->func = glReadBuffer_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glReadPixels) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glRectd) || defined(DISABLE_SKIP)
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    glRectd_INDEXED *packed_data = malloc(sizeof(glRectd_INDEXED));
    packed_data->func = glRectd_INDEX;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRectdv) || defined(DISABLE_SKIP)
void glRectdv(const GLdouble * v1, const GLdouble * v2) {
    glRectdv_INDEXED *packed_data = malloc(sizeof(glRectdv_INDEXED));
    packed_data->func = glRectdv_INDEX;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRectf) || defined(DISABLE_SKIP)
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glRectf_INDEXED *packed_data = malloc(sizeof(glRectf_INDEXED));
    packed_data->func = glRectf_INDEX;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRectfv) || defined(DISABLE_SKIP)
void glRectfv(const GLfloat * v1, const GLfloat * v2) {
    glRectfv_INDEXED *packed_data = malloc(sizeof(glRectfv_INDEXED));
    packed_data->func = glRectfv_INDEX;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRecti) || defined(DISABLE_SKIP)
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
    glRecti_INDEXED *packed_data = malloc(sizeof(glRecti_INDEXED));
    packed_data->func = glRecti_INDEX;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRectiv) || defined(DISABLE_SKIP)
void glRectiv(const GLint * v1, const GLint * v2) {
    glRectiv_INDEXED *packed_data = malloc(sizeof(glRectiv_INDEXED));
    packed_data->func = glRectiv_INDEX;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRects) || defined(DISABLE_SKIP)
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    glRects_INDEXED *packed_data = malloc(sizeof(glRects_INDEXED));
    packed_data->func = glRects_INDEX;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRectsv) || defined(DISABLE_SKIP)
void glRectsv(const GLshort * v1, const GLshort * v2) {
    glRectsv_INDEXED *packed_data = malloc(sizeof(glRectsv_INDEXED));
    packed_data->func = glRectsv_INDEX;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRenderMode) || defined(DISABLE_SKIP)
GLint glRenderMode(GLenum mode) {
    glRenderMode_INDEXED *packed_data = malloc(sizeof(glRenderMode_INDEXED));
    packed_data->func = glRenderMode_INDEX;
    packed_data->args.a1 = mode;
    GLint ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glResetHistogram) || defined(DISABLE_SKIP)
void glResetHistogram(GLenum target) {
    glResetHistogram_INDEXED *packed_data = malloc(sizeof(glResetHistogram_INDEXED));
    packed_data->func = glResetHistogram_INDEX;
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glResetMinmax) || defined(DISABLE_SKIP)
void glResetMinmax(GLenum target) {
    glResetMinmax_INDEXED *packed_data = malloc(sizeof(glResetMinmax_INDEXED));
    packed_data->func = glResetMinmax_INDEX;
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRotated) || defined(DISABLE_SKIP)
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    glRotated_INDEXED *packed_data = malloc(sizeof(glRotated_INDEXED));
    packed_data->func = glRotated_INDEX;
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glRotatef) || defined(DISABLE_SKIP)
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    glRotatef_INDEXED *packed_data = malloc(sizeof(glRotatef_INDEXED));
    packed_data->func = glRotatef_INDEX;
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSampleCoverage) || defined(DISABLE_SKIP)
void glSampleCoverage(GLfloat value, GLboolean invert) {
    glSampleCoverage_INDEXED *packed_data = malloc(sizeof(glSampleCoverage_INDEXED));
    packed_data->func = glSampleCoverage_INDEX;
    packed_data->args.a1 = value;
    packed_data->args.a2 = invert;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glScaled) || defined(DISABLE_SKIP)
void glScaled(GLdouble x, GLdouble y, GLdouble z) {
    glScaled_INDEXED *packed_data = malloc(sizeof(glScaled_INDEXED));
    packed_data->func = glScaled_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glScalef) || defined(DISABLE_SKIP)
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
    glScalef_INDEXED *packed_data = malloc(sizeof(glScalef_INDEXED));
    packed_data->func = glScalef_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glScissor) || defined(DISABLE_SKIP)
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    glScissor_INDEXED *packed_data = malloc(sizeof(glScissor_INDEXED));
    packed_data->func = glScissor_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3b) || defined(DISABLE_SKIP)
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    glSecondaryColor3b_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3b_INDEXED));
    packed_data->func = glSecondaryColor3b_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3bv) || defined(DISABLE_SKIP)
void glSecondaryColor3bv(const GLbyte * v) {
    glSecondaryColor3bv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3bv_INDEXED));
    packed_data->func = glSecondaryColor3bv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3d) || defined(DISABLE_SKIP)
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    glSecondaryColor3d_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3d_INDEXED));
    packed_data->func = glSecondaryColor3d_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3dv) || defined(DISABLE_SKIP)
void glSecondaryColor3dv(const GLdouble * v) {
    glSecondaryColor3dv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3dv_INDEXED));
    packed_data->func = glSecondaryColor3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3f) || defined(DISABLE_SKIP)
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    glSecondaryColor3f_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3f_INDEXED));
    packed_data->func = glSecondaryColor3f_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3fv) || defined(DISABLE_SKIP)
void glSecondaryColor3fv(const GLfloat * v) {
    glSecondaryColor3fv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3fv_INDEXED));
    packed_data->func = glSecondaryColor3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3i) || defined(DISABLE_SKIP)
void glSecondaryColor3i(GLint red, GLint green, GLint blue) {
    glSecondaryColor3i_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3i_INDEXED));
    packed_data->func = glSecondaryColor3i_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3iv) || defined(DISABLE_SKIP)
void glSecondaryColor3iv(const GLint * v) {
    glSecondaryColor3iv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3iv_INDEXED));
    packed_data->func = glSecondaryColor3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3s) || defined(DISABLE_SKIP)
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    glSecondaryColor3s_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3s_INDEXED));
    packed_data->func = glSecondaryColor3s_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3sv) || defined(DISABLE_SKIP)
void glSecondaryColor3sv(const GLshort * v) {
    glSecondaryColor3sv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3sv_INDEXED));
    packed_data->func = glSecondaryColor3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3ub) || defined(DISABLE_SKIP)
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    glSecondaryColor3ub_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ub_INDEXED));
    packed_data->func = glSecondaryColor3ub_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3ubv) || defined(DISABLE_SKIP)
void glSecondaryColor3ubv(const GLubyte * v) {
    glSecondaryColor3ubv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ubv_INDEXED));
    packed_data->func = glSecondaryColor3ubv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3ui) || defined(DISABLE_SKIP)
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    glSecondaryColor3ui_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ui_INDEXED));
    packed_data->func = glSecondaryColor3ui_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3uiv) || defined(DISABLE_SKIP)
void glSecondaryColor3uiv(const GLuint * v) {
    glSecondaryColor3uiv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3uiv_INDEXED));
    packed_data->func = glSecondaryColor3uiv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3us) || defined(DISABLE_SKIP)
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    glSecondaryColor3us_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3us_INDEXED));
    packed_data->func = glSecondaryColor3us_INDEX;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColor3usv) || defined(DISABLE_SKIP)
void glSecondaryColor3usv(const GLushort * v) {
    glSecondaryColor3usv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3usv_INDEXED));
    packed_data->func = glSecondaryColor3usv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSecondaryColorPointer) || defined(DISABLE_SKIP)
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glSecondaryColorPointer_INDEXED *packed_data = malloc(sizeof(glSecondaryColorPointer_INDEXED));
    packed_data->func = glSecondaryColorPointer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSelectBuffer) || defined(DISABLE_SKIP)
void glSelectBuffer(GLsizei size, GLuint * buffer) {
    glSelectBuffer_INDEXED *packed_data = malloc(sizeof(glSelectBuffer_INDEXED));
    packed_data->func = glSelectBuffer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glSeparableFilter2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glShadeModel) || defined(DISABLE_SKIP)
void glShadeModel(GLenum mode) {
    glShadeModel_INDEXED *packed_data = malloc(sizeof(glShadeModel_INDEXED));
    packed_data->func = glShadeModel_INDEX;
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glStencilFunc) || defined(DISABLE_SKIP)
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    glStencilFunc_INDEXED *packed_data = malloc(sizeof(glStencilFunc_INDEXED));
    packed_data->func = glStencilFunc_INDEX;
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    packed_data->args.a3 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glStencilMask) || defined(DISABLE_SKIP)
void glStencilMask(GLuint mask) {
    glStencilMask_INDEXED *packed_data = malloc(sizeof(glStencilMask_INDEXED));
    packed_data->func = glStencilMask_INDEX;
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glStencilOp) || defined(DISABLE_SKIP)
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    glStencilOp_INDEXED *packed_data = malloc(sizeof(glStencilOp_INDEXED));
    packed_data->func = glStencilOp_INDEX;
    packed_data->args.a1 = fail;
    packed_data->args.a2 = zfail;
    packed_data->args.a3 = zpass;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord1d) || defined(DISABLE_SKIP)
void glTexCoord1d(GLdouble s) {
    glTexCoord1d_INDEXED *packed_data = malloc(sizeof(glTexCoord1d_INDEXED));
    packed_data->func = glTexCoord1d_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord1dv) || defined(DISABLE_SKIP)
void glTexCoord1dv(const GLdouble * v) {
    glTexCoord1dv_INDEXED *packed_data = malloc(sizeof(glTexCoord1dv_INDEXED));
    packed_data->func = glTexCoord1dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord1f) || defined(DISABLE_SKIP)
void glTexCoord1f(GLfloat s) {
    glTexCoord1f_INDEXED *packed_data = malloc(sizeof(glTexCoord1f_INDEXED));
    packed_data->func = glTexCoord1f_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord1fv) || defined(DISABLE_SKIP)
void glTexCoord1fv(const GLfloat * v) {
    glTexCoord1fv_INDEXED *packed_data = malloc(sizeof(glTexCoord1fv_INDEXED));
    packed_data->func = glTexCoord1fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord1i) || defined(DISABLE_SKIP)
void glTexCoord1i(GLint s) {
    glTexCoord1i_INDEXED *packed_data = malloc(sizeof(glTexCoord1i_INDEXED));
    packed_data->func = glTexCoord1i_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord1iv) || defined(DISABLE_SKIP)
void glTexCoord1iv(const GLint * v) {
    glTexCoord1iv_INDEXED *packed_data = malloc(sizeof(glTexCoord1iv_INDEXED));
    packed_data->func = glTexCoord1iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord1s) || defined(DISABLE_SKIP)
void glTexCoord1s(GLshort s) {
    glTexCoord1s_INDEXED *packed_data = malloc(sizeof(glTexCoord1s_INDEXED));
    packed_data->func = glTexCoord1s_INDEX;
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord1sv) || defined(DISABLE_SKIP)
void glTexCoord1sv(const GLshort * v) {
    glTexCoord1sv_INDEXED *packed_data = malloc(sizeof(glTexCoord1sv_INDEXED));
    packed_data->func = glTexCoord1sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord2d) || defined(DISABLE_SKIP)
void glTexCoord2d(GLdouble s, GLdouble t) {
    glTexCoord2d_INDEXED *packed_data = malloc(sizeof(glTexCoord2d_INDEXED));
    packed_data->func = glTexCoord2d_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord2dv) || defined(DISABLE_SKIP)
void glTexCoord2dv(const GLdouble * v) {
    glTexCoord2dv_INDEXED *packed_data = malloc(sizeof(glTexCoord2dv_INDEXED));
    packed_data->func = glTexCoord2dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord2f) || defined(DISABLE_SKIP)
void glTexCoord2f(GLfloat s, GLfloat t) {
    glTexCoord2f_INDEXED *packed_data = malloc(sizeof(glTexCoord2f_INDEXED));
    packed_data->func = glTexCoord2f_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord2fv) || defined(DISABLE_SKIP)
void glTexCoord2fv(const GLfloat * v) {
    glTexCoord2fv_INDEXED *packed_data = malloc(sizeof(glTexCoord2fv_INDEXED));
    packed_data->func = glTexCoord2fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord2i) || defined(DISABLE_SKIP)
void glTexCoord2i(GLint s, GLint t) {
    glTexCoord2i_INDEXED *packed_data = malloc(sizeof(glTexCoord2i_INDEXED));
    packed_data->func = glTexCoord2i_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord2iv) || defined(DISABLE_SKIP)
void glTexCoord2iv(const GLint * v) {
    glTexCoord2iv_INDEXED *packed_data = malloc(sizeof(glTexCoord2iv_INDEXED));
    packed_data->func = glTexCoord2iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord2s) || defined(DISABLE_SKIP)
void glTexCoord2s(GLshort s, GLshort t) {
    glTexCoord2s_INDEXED *packed_data = malloc(sizeof(glTexCoord2s_INDEXED));
    packed_data->func = glTexCoord2s_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord2sv) || defined(DISABLE_SKIP)
void glTexCoord2sv(const GLshort * v) {
    glTexCoord2sv_INDEXED *packed_data = malloc(sizeof(glTexCoord2sv_INDEXED));
    packed_data->func = glTexCoord2sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord3d) || defined(DISABLE_SKIP)
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    glTexCoord3d_INDEXED *packed_data = malloc(sizeof(glTexCoord3d_INDEXED));
    packed_data->func = glTexCoord3d_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord3dv) || defined(DISABLE_SKIP)
void glTexCoord3dv(const GLdouble * v) {
    glTexCoord3dv_INDEXED *packed_data = malloc(sizeof(glTexCoord3dv_INDEXED));
    packed_data->func = glTexCoord3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord3f) || defined(DISABLE_SKIP)
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    glTexCoord3f_INDEXED *packed_data = malloc(sizeof(glTexCoord3f_INDEXED));
    packed_data->func = glTexCoord3f_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord3fv) || defined(DISABLE_SKIP)
void glTexCoord3fv(const GLfloat * v) {
    glTexCoord3fv_INDEXED *packed_data = malloc(sizeof(glTexCoord3fv_INDEXED));
    packed_data->func = glTexCoord3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord3i) || defined(DISABLE_SKIP)
void glTexCoord3i(GLint s, GLint t, GLint r) {
    glTexCoord3i_INDEXED *packed_data = malloc(sizeof(glTexCoord3i_INDEXED));
    packed_data->func = glTexCoord3i_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord3iv) || defined(DISABLE_SKIP)
void glTexCoord3iv(const GLint * v) {
    glTexCoord3iv_INDEXED *packed_data = malloc(sizeof(glTexCoord3iv_INDEXED));
    packed_data->func = glTexCoord3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord3s) || defined(DISABLE_SKIP)
void glTexCoord3s(GLshort s, GLshort t, GLshort r) {
    glTexCoord3s_INDEXED *packed_data = malloc(sizeof(glTexCoord3s_INDEXED));
    packed_data->func = glTexCoord3s_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord3sv) || defined(DISABLE_SKIP)
void glTexCoord3sv(const GLshort * v) {
    glTexCoord3sv_INDEXED *packed_data = malloc(sizeof(glTexCoord3sv_INDEXED));
    packed_data->func = glTexCoord3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord4d) || defined(DISABLE_SKIP)
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    glTexCoord4d_INDEXED *packed_data = malloc(sizeof(glTexCoord4d_INDEXED));
    packed_data->func = glTexCoord4d_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord4dv) || defined(DISABLE_SKIP)
void glTexCoord4dv(const GLdouble * v) {
    glTexCoord4dv_INDEXED *packed_data = malloc(sizeof(glTexCoord4dv_INDEXED));
    packed_data->func = glTexCoord4dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord4f) || defined(DISABLE_SKIP)
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    glTexCoord4f_INDEXED *packed_data = malloc(sizeof(glTexCoord4f_INDEXED));
    packed_data->func = glTexCoord4f_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord4fv) || defined(DISABLE_SKIP)
void glTexCoord4fv(const GLfloat * v) {
    glTexCoord4fv_INDEXED *packed_data = malloc(sizeof(glTexCoord4fv_INDEXED));
    packed_data->func = glTexCoord4fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord4i) || defined(DISABLE_SKIP)
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    glTexCoord4i_INDEXED *packed_data = malloc(sizeof(glTexCoord4i_INDEXED));
    packed_data->func = glTexCoord4i_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord4iv) || defined(DISABLE_SKIP)
void glTexCoord4iv(const GLint * v) {
    glTexCoord4iv_INDEXED *packed_data = malloc(sizeof(glTexCoord4iv_INDEXED));
    packed_data->func = glTexCoord4iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord4s) || defined(DISABLE_SKIP)
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    glTexCoord4s_INDEXED *packed_data = malloc(sizeof(glTexCoord4s_INDEXED));
    packed_data->func = glTexCoord4s_INDEX;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoord4sv) || defined(DISABLE_SKIP)
void glTexCoord4sv(const GLshort * v) {
    glTexCoord4sv_INDEXED *packed_data = malloc(sizeof(glTexCoord4sv_INDEXED));
    packed_data->func = glTexCoord4sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexCoordPointer) || defined(DISABLE_SKIP)
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glTexCoordPointer_INDEXED *packed_data = malloc(sizeof(glTexCoordPointer_INDEXED));
    packed_data->func = glTexCoordPointer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexEnvf) || defined(DISABLE_SKIP)
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    glTexEnvf_INDEXED *packed_data = malloc(sizeof(glTexEnvf_INDEXED));
    packed_data->func = glTexEnvf_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexEnvfv) || defined(DISABLE_SKIP)
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    glTexEnvfv_INDEXED *packed_data = malloc(sizeof(glTexEnvfv_INDEXED));
    packed_data->func = glTexEnvfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexEnvi) || defined(DISABLE_SKIP)
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    glTexEnvi_INDEXED *packed_data = malloc(sizeof(glTexEnvi_INDEXED));
    packed_data->func = glTexEnvi_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexEnviv) || defined(DISABLE_SKIP)
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    glTexEnviv_INDEXED *packed_data = malloc(sizeof(glTexEnviv_INDEXED));
    packed_data->func = glTexEnviv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexGend) || defined(DISABLE_SKIP)
void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    glTexGend_INDEXED *packed_data = malloc(sizeof(glTexGend_INDEXED));
    packed_data->func = glTexGend_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexGendv) || defined(DISABLE_SKIP)
void glTexGendv(GLenum coord, GLenum pname, const GLdouble * params) {
    glTexGendv_INDEXED *packed_data = malloc(sizeof(glTexGendv_INDEXED));
    packed_data->func = glTexGendv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexGenf) || defined(DISABLE_SKIP)
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    glTexGenf_INDEXED *packed_data = malloc(sizeof(glTexGenf_INDEXED));
    packed_data->func = glTexGenf_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexGenfv) || defined(DISABLE_SKIP)
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    glTexGenfv_INDEXED *packed_data = malloc(sizeof(glTexGenfv_INDEXED));
    packed_data->func = glTexGenfv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexGeni) || defined(DISABLE_SKIP)
void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    glTexGeni_INDEXED *packed_data = malloc(sizeof(glTexGeni_INDEXED));
    packed_data->func = glTexGeni_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexGeniv) || defined(DISABLE_SKIP)
void glTexGeniv(GLenum coord, GLenum pname, const GLint * params) {
    glTexGeniv_INDEXED *packed_data = malloc(sizeof(glTexGeniv_INDEXED));
    packed_data->func = glTexGeniv_INDEX;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexImage1D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glTexImage2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glTexImage3D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glTexParameterf) || defined(DISABLE_SKIP)
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    glTexParameterf_INDEXED *packed_data = malloc(sizeof(glTexParameterf_INDEXED));
    packed_data->func = glTexParameterf_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexParameterfv) || defined(DISABLE_SKIP)
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glTexParameterfv_INDEXED *packed_data = malloc(sizeof(glTexParameterfv_INDEXED));
    packed_data->func = glTexParameterfv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexParameteri) || defined(DISABLE_SKIP)
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    glTexParameteri_INDEXED *packed_data = malloc(sizeof(glTexParameteri_INDEXED));
    packed_data->func = glTexParameteri_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexParameteriv) || defined(DISABLE_SKIP)
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glTexParameteriv_INDEXED *packed_data = malloc(sizeof(glTexParameteriv_INDEXED));
    packed_data->func = glTexParameteriv_INDEX;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTexSubImage1D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glTexSubImage2D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glTexSubImage3D) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glTranslated) || defined(DISABLE_SKIP)
void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    glTranslated_INDEXED *packed_data = malloc(sizeof(glTranslated_INDEXED));
    packed_data->func = glTranslated_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glTranslatef) || defined(DISABLE_SKIP)
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    glTranslatef_INDEXED *packed_data = malloc(sizeof(glTranslatef_INDEXED));
    packed_data->func = glTranslatef_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glUnmapBuffer) || defined(DISABLE_SKIP)
GLboolean glUnmapBuffer(GLenum target) {
    glUnmapBuffer_INDEXED *packed_data = malloc(sizeof(glUnmapBuffer_INDEXED));
    packed_data->func = glUnmapBuffer_INDEX;
    packed_data->args.a1 = target;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glVertex2d) || defined(DISABLE_SKIP)
void glVertex2d(GLdouble x, GLdouble y) {
    glVertex2d_INDEXED *packed_data = malloc(sizeof(glVertex2d_INDEXED));
    packed_data->func = glVertex2d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex2dv) || defined(DISABLE_SKIP)
void glVertex2dv(const GLdouble * v) {
    glVertex2dv_INDEXED *packed_data = malloc(sizeof(glVertex2dv_INDEXED));
    packed_data->func = glVertex2dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex2f) || defined(DISABLE_SKIP)
void glVertex2f(GLfloat x, GLfloat y) {
    glVertex2f_INDEXED *packed_data = malloc(sizeof(glVertex2f_INDEXED));
    packed_data->func = glVertex2f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex2fv) || defined(DISABLE_SKIP)
void glVertex2fv(const GLfloat * v) {
    glVertex2fv_INDEXED *packed_data = malloc(sizeof(glVertex2fv_INDEXED));
    packed_data->func = glVertex2fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex2i) || defined(DISABLE_SKIP)
void glVertex2i(GLint x, GLint y) {
    glVertex2i_INDEXED *packed_data = malloc(sizeof(glVertex2i_INDEXED));
    packed_data->func = glVertex2i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex2iv) || defined(DISABLE_SKIP)
void glVertex2iv(const GLint * v) {
    glVertex2iv_INDEXED *packed_data = malloc(sizeof(glVertex2iv_INDEXED));
    packed_data->func = glVertex2iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex2s) || defined(DISABLE_SKIP)
void glVertex2s(GLshort x, GLshort y) {
    glVertex2s_INDEXED *packed_data = malloc(sizeof(glVertex2s_INDEXED));
    packed_data->func = glVertex2s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex2sv) || defined(DISABLE_SKIP)
void glVertex2sv(const GLshort * v) {
    glVertex2sv_INDEXED *packed_data = malloc(sizeof(glVertex2sv_INDEXED));
    packed_data->func = glVertex2sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex3d) || defined(DISABLE_SKIP)
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
    glVertex3d_INDEXED *packed_data = malloc(sizeof(glVertex3d_INDEXED));
    packed_data->func = glVertex3d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex3dv) || defined(DISABLE_SKIP)
void glVertex3dv(const GLdouble * v) {
    glVertex3dv_INDEXED *packed_data = malloc(sizeof(glVertex3dv_INDEXED));
    packed_data->func = glVertex3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex3f) || defined(DISABLE_SKIP)
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    glVertex3f_INDEXED *packed_data = malloc(sizeof(glVertex3f_INDEXED));
    packed_data->func = glVertex3f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex3fv) || defined(DISABLE_SKIP)
void glVertex3fv(const GLfloat * v) {
    glVertex3fv_INDEXED *packed_data = malloc(sizeof(glVertex3fv_INDEXED));
    packed_data->func = glVertex3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex3i) || defined(DISABLE_SKIP)
void glVertex3i(GLint x, GLint y, GLint z) {
    glVertex3i_INDEXED *packed_data = malloc(sizeof(glVertex3i_INDEXED));
    packed_data->func = glVertex3i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex3iv) || defined(DISABLE_SKIP)
void glVertex3iv(const GLint * v) {
    glVertex3iv_INDEXED *packed_data = malloc(sizeof(glVertex3iv_INDEXED));
    packed_data->func = glVertex3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex3s) || defined(DISABLE_SKIP)
void glVertex3s(GLshort x, GLshort y, GLshort z) {
    glVertex3s_INDEXED *packed_data = malloc(sizeof(glVertex3s_INDEXED));
    packed_data->func = glVertex3s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex3sv) || defined(DISABLE_SKIP)
void glVertex3sv(const GLshort * v) {
    glVertex3sv_INDEXED *packed_data = malloc(sizeof(glVertex3sv_INDEXED));
    packed_data->func = glVertex3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex4d) || defined(DISABLE_SKIP)
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glVertex4d_INDEXED *packed_data = malloc(sizeof(glVertex4d_INDEXED));
    packed_data->func = glVertex4d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex4dv) || defined(DISABLE_SKIP)
void glVertex4dv(const GLdouble * v) {
    glVertex4dv_INDEXED *packed_data = malloc(sizeof(glVertex4dv_INDEXED));
    packed_data->func = glVertex4dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex4f) || defined(DISABLE_SKIP)
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glVertex4f_INDEXED *packed_data = malloc(sizeof(glVertex4f_INDEXED));
    packed_data->func = glVertex4f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex4fv) || defined(DISABLE_SKIP)
void glVertex4fv(const GLfloat * v) {
    glVertex4fv_INDEXED *packed_data = malloc(sizeof(glVertex4fv_INDEXED));
    packed_data->func = glVertex4fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex4i) || defined(DISABLE_SKIP)
void glVertex4i(GLint x, GLint y, GLint z, GLint w) {
    glVertex4i_INDEXED *packed_data = malloc(sizeof(glVertex4i_INDEXED));
    packed_data->func = glVertex4i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex4iv) || defined(DISABLE_SKIP)
void glVertex4iv(const GLint * v) {
    glVertex4iv_INDEXED *packed_data = malloc(sizeof(glVertex4iv_INDEXED));
    packed_data->func = glVertex4iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex4s) || defined(DISABLE_SKIP)
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    glVertex4s_INDEXED *packed_data = malloc(sizeof(glVertex4s_INDEXED));
    packed_data->func = glVertex4s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertex4sv) || defined(DISABLE_SKIP)
void glVertex4sv(const GLshort * v) {
    glVertex4sv_INDEXED *packed_data = malloc(sizeof(glVertex4sv_INDEXED));
    packed_data->func = glVertex4sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glVertexPointer) || defined(DISABLE_SKIP)
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glVertexPointer_INDEXED *packed_data = malloc(sizeof(glVertexPointer_INDEXED));
    packed_data->func = glVertexPointer_INDEX;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glViewport) || defined(DISABLE_SKIP)
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    glViewport_INDEXED *packed_data = malloc(sizeof(glViewport_INDEXED));
    packed_data->func = glViewport_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos2d) || defined(DISABLE_SKIP)
void glWindowPos2d(GLdouble x, GLdouble y) {
    glWindowPos2d_INDEXED *packed_data = malloc(sizeof(glWindowPos2d_INDEXED));
    packed_data->func = glWindowPos2d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos2dv) || defined(DISABLE_SKIP)
void glWindowPos2dv(const GLdouble * v) {
    glWindowPos2dv_INDEXED *packed_data = malloc(sizeof(glWindowPos2dv_INDEXED));
    packed_data->func = glWindowPos2dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos2f) || defined(DISABLE_SKIP)
void glWindowPos2f(GLfloat x, GLfloat y) {
    glWindowPos2f_INDEXED *packed_data = malloc(sizeof(glWindowPos2f_INDEXED));
    packed_data->func = glWindowPos2f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos2fv) || defined(DISABLE_SKIP)
void glWindowPos2fv(const GLfloat * v) {
    glWindowPos2fv_INDEXED *packed_data = malloc(sizeof(glWindowPos2fv_INDEXED));
    packed_data->func = glWindowPos2fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos2i) || defined(DISABLE_SKIP)
void glWindowPos2i(GLint x, GLint y) {
    glWindowPos2i_INDEXED *packed_data = malloc(sizeof(glWindowPos2i_INDEXED));
    packed_data->func = glWindowPos2i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos2iv) || defined(DISABLE_SKIP)
void glWindowPos2iv(const GLint * v) {
    glWindowPos2iv_INDEXED *packed_data = malloc(sizeof(glWindowPos2iv_INDEXED));
    packed_data->func = glWindowPos2iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos2s) || defined(DISABLE_SKIP)
void glWindowPos2s(GLshort x, GLshort y) {
    glWindowPos2s_INDEXED *packed_data = malloc(sizeof(glWindowPos2s_INDEXED));
    packed_data->func = glWindowPos2s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos2sv) || defined(DISABLE_SKIP)
void glWindowPos2sv(const GLshort * v) {
    glWindowPos2sv_INDEXED *packed_data = malloc(sizeof(glWindowPos2sv_INDEXED));
    packed_data->func = glWindowPos2sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos3d) || defined(DISABLE_SKIP)
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    glWindowPos3d_INDEXED *packed_data = malloc(sizeof(glWindowPos3d_INDEXED));
    packed_data->func = glWindowPos3d_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos3dv) || defined(DISABLE_SKIP)
void glWindowPos3dv(const GLdouble * v) {
    glWindowPos3dv_INDEXED *packed_data = malloc(sizeof(glWindowPos3dv_INDEXED));
    packed_data->func = glWindowPos3dv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos3f) || defined(DISABLE_SKIP)
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    glWindowPos3f_INDEXED *packed_data = malloc(sizeof(glWindowPos3f_INDEXED));
    packed_data->func = glWindowPos3f_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos3fv) || defined(DISABLE_SKIP)
void glWindowPos3fv(const GLfloat * v) {
    glWindowPos3fv_INDEXED *packed_data = malloc(sizeof(glWindowPos3fv_INDEXED));
    packed_data->func = glWindowPos3fv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos3i) || defined(DISABLE_SKIP)
void glWindowPos3i(GLint x, GLint y, GLint z) {
    glWindowPos3i_INDEXED *packed_data = malloc(sizeof(glWindowPos3i_INDEXED));
    packed_data->func = glWindowPos3i_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos3iv) || defined(DISABLE_SKIP)
void glWindowPos3iv(const GLint * v) {
    glWindowPos3iv_INDEXED *packed_data = malloc(sizeof(glWindowPos3iv_INDEXED));
    packed_data->func = glWindowPos3iv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos3s) || defined(DISABLE_SKIP)
void glWindowPos3s(GLshort x, GLshort y, GLshort z) {
    glWindowPos3s_INDEXED *packed_data = malloc(sizeof(glWindowPos3s_INDEXED));
    packed_data->func = glWindowPos3s_INDEX;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glWindowPos3sv) || defined(DISABLE_SKIP)
void glWindowPos3sv(const GLshort * v) {
    glWindowPos3sv_INDEXED *packed_data = malloc(sizeof(glWindowPos3sv_INDEXED));
    packed_data->func = glWindowPos3sv_INDEX;
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXBindHyperpipeSGIX) || defined(DISABLE_SKIP)
int glXBindHyperpipeSGIX(Display * dpy, int hpId) {
    glXBindHyperpipeSGIX_INDEXED *packed_data = malloc(sizeof(glXBindHyperpipeSGIX_INDEXED));
    packed_data->func = glXBindHyperpipeSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXBindSwapBarrierSGIX) || defined(DISABLE_SKIP)
void glXBindSwapBarrierSGIX(uint32_t window, uint32_t barrier) {
    glXBindSwapBarrierSGIX_INDEXED *packed_data = malloc(sizeof(glXBindSwapBarrierSGIX_INDEXED));
    packed_data->func = glXBindSwapBarrierSGIX_INDEX;
    packed_data->args.a1 = window;
    packed_data->args.a2 = barrier;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXChangeDrawableAttributes) || defined(DISABLE_SKIP)
void glXChangeDrawableAttributes(uint32_t drawable) {
    glXChangeDrawableAttributes_INDEXED *packed_data = malloc(sizeof(glXChangeDrawableAttributes_INDEXED));
    packed_data->func = glXChangeDrawableAttributes_INDEX;
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXChangeDrawableAttributesSGIX) || defined(DISABLE_SKIP)
void glXChangeDrawableAttributesSGIX(uint32_t drawable) {
    glXChangeDrawableAttributesSGIX_INDEXED *packed_data = malloc(sizeof(glXChangeDrawableAttributesSGIX_INDEXED));
    packed_data->func = glXChangeDrawableAttributesSGIX_INDEX;
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXChooseFBConfig) || defined(DISABLE_SKIP)
GLXFBConfig * glXChooseFBConfig(Display * dpy, int screen, const int * attrib_list, int * nelements) {
    glXChooseFBConfig_INDEXED *packed_data = malloc(sizeof(glXChooseFBConfig_INDEXED));
    packed_data->func = glXChooseFBConfig_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = attrib_list;
    packed_data->args.a4 = nelements;
    GLXFBConfig * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXChooseVisual) || defined(DISABLE_SKIP)
XVisualInfo * glXChooseVisual(Display * dpy, int screen, int * attribList) {
    glXChooseVisual_INDEXED *packed_data = malloc(sizeof(glXChooseVisual_INDEXED));
    packed_data->func = glXChooseVisual_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = attribList;
    XVisualInfo * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXClientInfo) || defined(DISABLE_SKIP)
void glXClientInfo() {
    glXClientInfo_INDEXED *packed_data = malloc(sizeof(glXClientInfo_INDEXED));
    packed_data->func = glXClientInfo_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXCopyContext) || defined(DISABLE_SKIP)
void glXCopyContext(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask) {
    glXCopyContext_INDEXED *packed_data = malloc(sizeof(glXCopyContext_INDEXED));
    packed_data->func = glXCopyContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = src;
    packed_data->args.a3 = dst;
    packed_data->args.a4 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXCreateContext) || defined(DISABLE_SKIP)
GLXContext glXCreateContext(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct) {
    glXCreateContext_INDEXED *packed_data = malloc(sizeof(glXCreateContext_INDEXED));
    packed_data->func = glXCreateContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = vis;
    packed_data->args.a3 = shareList;
    packed_data->args.a4 = direct;
    GLXContext ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXCreateContextWithConfigSGIX) || defined(DISABLE_SKIP)
void glXCreateContextWithConfigSGIX(uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list) {
    glXCreateContextWithConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateContextWithConfigSGIX_INDEXED));
    packed_data->func = glXCreateContextWithConfigSGIX_INDEX;
    packed_data->args.a1 = gc_id;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = config;
    packed_data->args.a4 = share_list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXCreateGLXPbufferSGIX) || defined(DISABLE_SKIP)
void glXCreateGLXPbufferSGIX(uint32_t config, uint32_t pbuffer) {
    glXCreateGLXPbufferSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPbufferSGIX_INDEXED));
    packed_data->func = glXCreateGLXPbufferSGIX_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = pbuffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXCreateGLXPixmap) || defined(DISABLE_SKIP)
GLXPixmap glXCreateGLXPixmap(Display * dpy, XVisualInfo * visual, Pixmap pixmap) {
    glXCreateGLXPixmap_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPixmap_INDEXED));
    packed_data->func = glXCreateGLXPixmap_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = visual;
    packed_data->args.a3 = pixmap;
    GLXPixmap ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXCreateGLXPixmapWithConfigSGIX) || defined(DISABLE_SKIP)
void glXCreateGLXPixmapWithConfigSGIX(uint32_t config, uint32_t pixmap, uint32_t glxpixmap) {
    glXCreateGLXPixmapWithConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPixmapWithConfigSGIX_INDEXED));
    packed_data->func = glXCreateGLXPixmapWithConfigSGIX_INDEX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = pixmap;
    packed_data->args.a3 = glxpixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXCreateGLXVideoSourceSGIX) || defined(DISABLE_SKIP)
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
}
#endif
#if !defined(skip_glXCreateNewContext) || defined(DISABLE_SKIP)
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
    return ret;
}
#endif
#if !defined(skip_glXCreatePbuffer) || defined(DISABLE_SKIP)
GLXPbuffer glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list) {
    glXCreatePbuffer_INDEXED *packed_data = malloc(sizeof(glXCreatePbuffer_INDEXED));
    packed_data->func = glXCreatePbuffer_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = attrib_list;
    GLXPbuffer ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXCreatePixmap) || defined(DISABLE_SKIP)
GLXPixmap glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list) {
    glXCreatePixmap_INDEXED *packed_data = malloc(sizeof(glXCreatePixmap_INDEXED));
    packed_data->func = glXCreatePixmap_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = pixmap;
    packed_data->args.a4 = attrib_list;
    GLXPixmap ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXCreateWindow) || defined(DISABLE_SKIP)
GLXWindow glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list) {
    glXCreateWindow_INDEXED *packed_data = malloc(sizeof(glXCreateWindow_INDEXED));
    packed_data->func = glXCreateWindow_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = win;
    packed_data->args.a4 = attrib_list;
    GLXWindow ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXDestroyContext) || defined(DISABLE_SKIP)
void glXDestroyContext(Display * dpy, GLXContext ctx) {
    glXDestroyContext_INDEXED *packed_data = malloc(sizeof(glXDestroyContext_INDEXED));
    packed_data->func = glXDestroyContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXDestroyGLXPbufferSGIX) || defined(DISABLE_SKIP)
void glXDestroyGLXPbufferSGIX(uint32_t pbuffer) {
    glXDestroyGLXPbufferSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXPbufferSGIX_INDEXED));
    packed_data->func = glXDestroyGLXPbufferSGIX_INDEX;
    packed_data->args.a1 = pbuffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXDestroyGLXPixmap) || defined(DISABLE_SKIP)
void glXDestroyGLXPixmap(Display * dpy, GLXPixmap pixmap) {
    glXDestroyGLXPixmap_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXPixmap_INDEXED));
    packed_data->func = glXDestroyGLXPixmap_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXDestroyGLXVideoSourceSGIX) || defined(DISABLE_SKIP)
void glXDestroyGLXVideoSourceSGIX(Display * dpy, uint32_t glxvideosource) {
    glXDestroyGLXVideoSourceSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXVideoSourceSGIX_INDEXED));
    packed_data->func = glXDestroyGLXVideoSourceSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = glxvideosource;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXDestroyHyperpipeConfigSGIX) || defined(DISABLE_SKIP)
int glXDestroyHyperpipeConfigSGIX(Display * dpy, int hpId) {
    glXDestroyHyperpipeConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyHyperpipeConfigSGIX_INDEXED));
    packed_data->func = glXDestroyHyperpipeConfigSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXDestroyPbuffer) || defined(DISABLE_SKIP)
void glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf) {
    glXDestroyPbuffer_INDEXED *packed_data = malloc(sizeof(glXDestroyPbuffer_INDEXED));
    packed_data->func = glXDestroyPbuffer_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pbuf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXDestroyPixmap) || defined(DISABLE_SKIP)
void glXDestroyPixmap(Display * dpy, GLXPixmap pixmap) {
    glXDestroyPixmap_INDEXED *packed_data = malloc(sizeof(glXDestroyPixmap_INDEXED));
    packed_data->func = glXDestroyPixmap_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXDestroyWindow) || defined(DISABLE_SKIP)
void glXDestroyWindow(Display * dpy, GLXWindow win) {
    glXDestroyWindow_INDEXED *packed_data = malloc(sizeof(glXDestroyWindow_INDEXED));
    packed_data->func = glXDestroyWindow_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = win;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXGetCurrentDisplay) || defined(DISABLE_SKIP)
Display * glXGetCurrentDisplay() {
    glXGetCurrentDisplay_INDEXED *packed_data = malloc(sizeof(glXGetCurrentDisplay_INDEXED));
    packed_data->func = glXGetCurrentDisplay_INDEX;
    Display * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXGetCurrentReadDrawable) || defined(DISABLE_SKIP)
GLXDrawable glXGetCurrentReadDrawable() {
    glXGetCurrentReadDrawable_INDEXED *packed_data = malloc(sizeof(glXGetCurrentReadDrawable_INDEXED));
    packed_data->func = glXGetCurrentReadDrawable_INDEX;
    GLXDrawable ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXGetDrawableAttributes) || defined(DISABLE_SKIP)
void glXGetDrawableAttributes(uint32_t drawable) {
    glXGetDrawableAttributes_INDEXED *packed_data = malloc(sizeof(glXGetDrawableAttributes_INDEXED));
    packed_data->func = glXGetDrawableAttributes_INDEX;
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXGetDrawableAttributesSGIX) || defined(DISABLE_SKIP)
void glXGetDrawableAttributesSGIX(uint32_t drawable) {
    glXGetDrawableAttributesSGIX_INDEXED *packed_data = malloc(sizeof(glXGetDrawableAttributesSGIX_INDEXED));
    packed_data->func = glXGetDrawableAttributesSGIX_INDEX;
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXGetFBConfigAttrib) || defined(DISABLE_SKIP)
int glXGetFBConfigAttrib(Display * dpy, GLXFBConfig config, int attribute, int * value) {
    glXGetFBConfigAttrib_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigAttrib_INDEXED));
    packed_data->func = glXGetFBConfigAttrib_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXGetFBConfigs) || defined(DISABLE_SKIP)
GLXFBConfig * glXGetFBConfigs(Display * dpy, int screen, int * nelements) {
    glXGetFBConfigs_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigs_INDEXED));
    packed_data->func = glXGetFBConfigs_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = nelements;
    GLXFBConfig * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXGetFBConfigsSGIX) || defined(DISABLE_SKIP)
void glXGetFBConfigsSGIX() {
    glXGetFBConfigsSGIX_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigsSGIX_INDEXED));
    packed_data->func = glXGetFBConfigsSGIX_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXGetProcAddress) || defined(DISABLE_SKIP)
__GLXextFuncPtr glXGetProcAddress(const GLubyte * procName) {
    glXGetProcAddress_INDEXED *packed_data = malloc(sizeof(glXGetProcAddress_INDEXED));
    packed_data->func = glXGetProcAddress_INDEX;
    packed_data->args.a1 = procName;
    __GLXextFuncPtr ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXGetSelectedEvent) || defined(DISABLE_SKIP)
void glXGetSelectedEvent(Display * dpy, GLXDrawable draw, unsigned long * event_mask) {
    glXGetSelectedEvent_INDEXED *packed_data = malloc(sizeof(glXGetSelectedEvent_INDEXED));
    packed_data->func = glXGetSelectedEvent_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = event_mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXGetVisualConfigs) || defined(DISABLE_SKIP)
void glXGetVisualConfigs() {
    glXGetVisualConfigs_INDEXED *packed_data = malloc(sizeof(glXGetVisualConfigs_INDEXED));
    packed_data->func = glXGetVisualConfigs_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXGetVisualFromFBConfig) || defined(DISABLE_SKIP)
XVisualInfo * glXGetVisualFromFBConfig(Display * dpy, GLXFBConfig config) {
    glXGetVisualFromFBConfig_INDEXED *packed_data = malloc(sizeof(glXGetVisualFromFBConfig_INDEXED));
    packed_data->func = glXGetVisualFromFBConfig_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    XVisualInfo * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXHyperpipeAttribSGIX) || defined(DISABLE_SKIP)
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
    return ret;
}
#endif
#if !defined(skip_glXHyperpipeConfigSGIX) || defined(DISABLE_SKIP)
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
    return ret;
}
#endif
#if !defined(skip_glXIsDirect) || defined(DISABLE_SKIP)
Bool glXIsDirect(Display * dpy, GLXContext ctx) {
    glXIsDirect_INDEXED *packed_data = malloc(sizeof(glXIsDirect_INDEXED));
    packed_data->func = glXIsDirect_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXJoinSwapGroupSGIX) || defined(DISABLE_SKIP)
void glXJoinSwapGroupSGIX(uint32_t window, uint32_t group) {
    glXJoinSwapGroupSGIX_INDEXED *packed_data = malloc(sizeof(glXJoinSwapGroupSGIX_INDEXED));
    packed_data->func = glXJoinSwapGroupSGIX_INDEX;
    packed_data->args.a1 = window;
    packed_data->args.a2 = group;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXMakeContextCurrent) || defined(DISABLE_SKIP)
Bool glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
    glXMakeContextCurrent_INDEXED *packed_data = malloc(sizeof(glXMakeContextCurrent_INDEXED));
    packed_data->func = glXMakeContextCurrent_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = read;
    packed_data->args.a4 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXMakeCurrent) || defined(DISABLE_SKIP)
Bool glXMakeCurrent(Display * dpy, GLXDrawable drawable, GLXContext ctx) {
    glXMakeCurrent_INDEXED *packed_data = malloc(sizeof(glXMakeCurrent_INDEXED));
    packed_data->func = glXMakeCurrent_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = drawable;
    packed_data->args.a3 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXMakeCurrentReadSGI) || defined(DISABLE_SKIP)
void glXMakeCurrentReadSGI(uint32_t drawable, uint32_t readdrawable, uint32_t context) {
    glXMakeCurrentReadSGI_INDEXED *packed_data = malloc(sizeof(glXMakeCurrentReadSGI_INDEXED));
    packed_data->func = glXMakeCurrentReadSGI_INDEX;
    packed_data->args.a1 = drawable;
    packed_data->args.a2 = readdrawable;
    packed_data->args.a3 = context;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXQueryContext) || defined(DISABLE_SKIP)
int glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value) {
    glXQueryContext_INDEXED *packed_data = malloc(sizeof(glXQueryContext_INDEXED));
    packed_data->func = glXQueryContext_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXQueryContextInfoEXT) || defined(DISABLE_SKIP)
void glXQueryContextInfoEXT() {
    glXQueryContextInfoEXT_INDEXED *packed_data = malloc(sizeof(glXQueryContextInfoEXT_INDEXED));
    packed_data->func = glXQueryContextInfoEXT_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXQueryDrawable) || defined(DISABLE_SKIP)
void glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value) {
    glXQueryDrawable_INDEXED *packed_data = malloc(sizeof(glXQueryDrawable_INDEXED));
    packed_data->func = glXQueryDrawable_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXQueryExtensionsString) || defined(DISABLE_SKIP)
const char * glXQueryExtensionsString(Display * dpy, int screen) {
    glXQueryExtensionsString_INDEXED *packed_data = malloc(sizeof(glXQueryExtensionsString_INDEXED));
    packed_data->func = glXQueryExtensionsString_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXQueryHyperpipeAttribSGIX) || defined(DISABLE_SKIP)
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
    return ret;
}
#endif
#if !defined(skip_glXQueryHyperpipeBestAttribSGIX) || defined(DISABLE_SKIP)
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
    return ret;
}
#endif
#if !defined(skip_glXQueryHyperpipeConfigSGIX) || defined(DISABLE_SKIP)
GLXHyperpipeConfigSGIX * glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes) {
    glXQueryHyperpipeConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeConfigSGIX_INDEXED));
    packed_data->func = glXQueryHyperpipeConfigSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    packed_data->args.a3 = npipes;
    GLXHyperpipeConfigSGIX * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXQueryHyperpipeNetworkSGIX) || defined(DISABLE_SKIP)
GLXHyperpipeNetworkSGIX * glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes) {
    glXQueryHyperpipeNetworkSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeNetworkSGIX_INDEXED));
    packed_data->func = glXQueryHyperpipeNetworkSGIX_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = npipes;
    GLXHyperpipeNetworkSGIX * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXQueryMaxSwapBarriersSGIX) || defined(DISABLE_SKIP)
void glXQueryMaxSwapBarriersSGIX() {
    glXQueryMaxSwapBarriersSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryMaxSwapBarriersSGIX_INDEXED));
    packed_data->func = glXQueryMaxSwapBarriersSGIX_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXQueryServerString) || defined(DISABLE_SKIP)
const char * glXQueryServerString(Display * dpy, int screen, int name) {
    glXQueryServerString_INDEXED *packed_data = malloc(sizeof(glXQueryServerString_INDEXED));
    packed_data->func = glXQueryServerString_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = name;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXQueryVersion) || defined(DISABLE_SKIP)
Bool glXQueryVersion(Display * dpy, int * maj, int * min) {
    glXQueryVersion_INDEXED *packed_data = malloc(sizeof(glXQueryVersion_INDEXED));
    packed_data->func = glXQueryVersion_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = maj;
    packed_data->args.a3 = min;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#if !defined(skip_glXRender) || defined(DISABLE_SKIP)
void glXRender() {
    glXRender_INDEXED *packed_data = malloc(sizeof(glXRender_INDEXED));
    packed_data->func = glXRender_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXRenderLarge) || defined(DISABLE_SKIP)
void glXRenderLarge() {
    glXRenderLarge_INDEXED *packed_data = malloc(sizeof(glXRenderLarge_INDEXED));
    packed_data->func = glXRenderLarge_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXSelectEvent) || defined(DISABLE_SKIP)
void glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask) {
    glXSelectEvent_INDEXED *packed_data = malloc(sizeof(glXSelectEvent_INDEXED));
    packed_data->func = glXSelectEvent_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = event_mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXSwapBuffers) || defined(DISABLE_SKIP)
void glXSwapBuffers(Display * dpy, GLXDrawable drawable) {
    glXSwapBuffers_INDEXED *packed_data = malloc(sizeof(glXSwapBuffers_INDEXED));
    packed_data->func = glXSwapBuffers_INDEX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXSwapIntervalSGI) || defined(DISABLE_SKIP)
void glXSwapIntervalSGI() {
    glXSwapIntervalSGI_INDEXED *packed_data = malloc(sizeof(glXSwapIntervalSGI_INDEXED));
    packed_data->func = glXSwapIntervalSGI_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXUseXFont) || defined(DISABLE_SKIP)
void glXUseXFont(Font font, int first, int count, int list) {
    glXUseXFont_INDEXED *packed_data = malloc(sizeof(glXUseXFont_INDEXED));
    packed_data->func = glXUseXFont_INDEX;
    packed_data->args.a1 = font;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    packed_data->args.a4 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXVendorPrivate) || defined(DISABLE_SKIP)
void glXVendorPrivate() {
    glXVendorPrivate_INDEXED *packed_data = malloc(sizeof(glXVendorPrivate_INDEXED));
    packed_data->func = glXVendorPrivate_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXVendorPrivateWithReply) || defined(DISABLE_SKIP)
void glXVendorPrivateWithReply() {
    glXVendorPrivateWithReply_INDEXED *packed_data = malloc(sizeof(glXVendorPrivateWithReply_INDEXED));
    packed_data->func = glXVendorPrivateWithReply_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXWaitGL) || defined(DISABLE_SKIP)
void glXWaitGL() {
    glXWaitGL_INDEXED *packed_data = malloc(sizeof(glXWaitGL_INDEXED));
    packed_data->func = glXWaitGL_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#if !defined(skip_glXWaitX) || defined(DISABLE_SKIP)
void glXWaitX() {
    glXWaitX_INDEXED *packed_data = malloc(sizeof(glXWaitX_INDEXED));
    packed_data->func = glXWaitX_INDEX;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
