#include <sys/syscall.h>
#include "../proxy.h"


#ifndef skip_glAccum
void glAccum(GLenum op, GLfloat value) {
    glAccum_INDEXED *packed_data = malloc(sizeof(glAccum_INDEXED));
    packed_data->args.a1 = op;
    packed_data->args.a2 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glActiveTexture
void glActiveTexture(GLenum texture) {
    glActiveTexture_INDEXED *packed_data = malloc(sizeof(glActiveTexture_INDEXED));
    packed_data->args.a1 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glAlphaFunc
void glAlphaFunc(GLenum func, GLfloat ref) {
    glAlphaFunc_INDEXED *packed_data = malloc(sizeof(glAlphaFunc_INDEXED));
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glAreTexturesResident
GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences) {
    glAreTexturesResident_INDEXED *packed_data = malloc(sizeof(glAreTexturesResident_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    packed_data->args.a3 = residences;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glArrayElement
void glArrayElement(GLint i) {
    glArrayElement_INDEXED *packed_data = malloc(sizeof(glArrayElement_INDEXED));
    packed_data->args.a1 = i;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBegin
void glBegin(GLenum mode) {
    glBegin_INDEXED *packed_data = malloc(sizeof(glBegin_INDEXED));
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBeginQuery
void glBeginQuery(GLenum target, GLuint id) {
    glBeginQuery_INDEXED *packed_data = malloc(sizeof(glBeginQuery_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = id;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBindBuffer
void glBindBuffer(GLenum target, GLuint buffer) {
    glBindBuffer_INDEXED *packed_data = malloc(sizeof(glBindBuffer_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBindTexture
void glBindTexture(GLenum target, GLuint texture) {
    glBindTexture_INDEXED *packed_data = malloc(sizeof(glBindTexture_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBitmap
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap) {
    glBitmap_INDEXED *packed_data = malloc(sizeof(glBitmap_INDEXED));
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
#ifndef skip_glBlendColor
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glBlendColor_INDEXED *packed_data = malloc(sizeof(glBlendColor_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBlendEquation
void glBlendEquation(GLenum mode) {
    glBlendEquation_INDEXED *packed_data = malloc(sizeof(glBlendEquation_INDEXED));
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBlendFunc
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    glBlendFunc_INDEXED *packed_data = malloc(sizeof(glBlendFunc_INDEXED));
    packed_data->args.a1 = sfactor;
    packed_data->args.a2 = dfactor;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBlendFuncSeparate
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    glBlendFuncSeparate_INDEXED *packed_data = malloc(sizeof(glBlendFuncSeparate_INDEXED));
    packed_data->args.a1 = sfactorRGB;
    packed_data->args.a2 = dfactorRGB;
    packed_data->args.a3 = sfactorAlpha;
    packed_data->args.a4 = dfactorAlpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBufferData
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    glBufferData_INDEXED *packed_data = malloc(sizeof(glBufferData_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = size;
    packed_data->args.a3 = data;
    packed_data->args.a4 = usage;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glBufferSubData
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    glBufferSubData_INDEXED *packed_data = malloc(sizeof(glBufferSubData_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = size;
    packed_data->args.a4 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glCallList
void glCallList(GLuint list) {
    glCallList_INDEXED *packed_data = malloc(sizeof(glCallList_INDEXED));
    packed_data->args.a1 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glCallLists
void glCallLists(GLsizei n, GLenum type, const GLvoid * lists) {
    glCallLists_INDEXED *packed_data = malloc(sizeof(glCallLists_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = type;
    packed_data->args.a3 = lists;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glClear
void glClear(GLbitfield mask) {
    glClear_INDEXED *packed_data = malloc(sizeof(glClear_INDEXED));
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glClearAccum
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glClearAccum_INDEXED *packed_data = malloc(sizeof(glClearAccum_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glClearColor
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glClearColor_INDEXED *packed_data = malloc(sizeof(glClearColor_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glClearDepth
void glClearDepth(GLdouble depth) {
    glClearDepth_INDEXED *packed_data = malloc(sizeof(glClearDepth_INDEXED));
    packed_data->args.a1 = depth;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glClearIndex
void glClearIndex(GLfloat c) {
    glClearIndex_INDEXED *packed_data = malloc(sizeof(glClearIndex_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glClearStencil
void glClearStencil(GLint s) {
    glClearStencil_INDEXED *packed_data = malloc(sizeof(glClearStencil_INDEXED));
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glClientActiveTexture
void glClientActiveTexture(GLenum texture) {
    glClientActiveTexture_INDEXED *packed_data = malloc(sizeof(glClientActiveTexture_INDEXED));
    packed_data->args.a1 = texture;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glClipPlane
void glClipPlane(GLenum plane, const GLdouble * equation) {
    glClipPlane_INDEXED *packed_data = malloc(sizeof(glClipPlane_INDEXED));
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3b
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    glColor3b_INDEXED *packed_data = malloc(sizeof(glColor3b_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3bv
void glColor3bv(const GLbyte * v) {
    glColor3bv_INDEXED *packed_data = malloc(sizeof(glColor3bv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3d
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    glColor3d_INDEXED *packed_data = malloc(sizeof(glColor3d_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3dv
void glColor3dv(const GLdouble * v) {
    glColor3dv_INDEXED *packed_data = malloc(sizeof(glColor3dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3f
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f_INDEXED *packed_data = malloc(sizeof(glColor3f_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3fv
void glColor3fv(const GLfloat * v) {
    glColor3fv_INDEXED *packed_data = malloc(sizeof(glColor3fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3i
void glColor3i(GLint red, GLint green, GLint blue) {
    glColor3i_INDEXED *packed_data = malloc(sizeof(glColor3i_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3iv
void glColor3iv(const GLint * v) {
    glColor3iv_INDEXED *packed_data = malloc(sizeof(glColor3iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3s
void glColor3s(GLshort red, GLshort green, GLshort blue) {
    glColor3s_INDEXED *packed_data = malloc(sizeof(glColor3s_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3sv
void glColor3sv(const GLshort * v) {
    glColor3sv_INDEXED *packed_data = malloc(sizeof(glColor3sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3ub
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    glColor3ub_INDEXED *packed_data = malloc(sizeof(glColor3ub_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3ubv
void glColor3ubv(const GLubyte * v) {
    glColor3ubv_INDEXED *packed_data = malloc(sizeof(glColor3ubv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3ui
void glColor3ui(GLuint red, GLuint green, GLuint blue) {
    glColor3ui_INDEXED *packed_data = malloc(sizeof(glColor3ui_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3uiv
void glColor3uiv(const GLuint * v) {
    glColor3uiv_INDEXED *packed_data = malloc(sizeof(glColor3uiv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3us
void glColor3us(GLushort red, GLushort green, GLushort blue) {
    glColor3us_INDEXED *packed_data = malloc(sizeof(glColor3us_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor3usv
void glColor3usv(const GLushort * v) {
    glColor3usv_INDEXED *packed_data = malloc(sizeof(glColor3usv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4b
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    glColor4b_INDEXED *packed_data = malloc(sizeof(glColor4b_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4bv
void glColor4bv(const GLbyte * v) {
    glColor4bv_INDEXED *packed_data = malloc(sizeof(glColor4bv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4d
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    glColor4d_INDEXED *packed_data = malloc(sizeof(glColor4d_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4dv
void glColor4dv(const GLdouble * v) {
    glColor4dv_INDEXED *packed_data = malloc(sizeof(glColor4dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4f
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glColor4f_INDEXED *packed_data = malloc(sizeof(glColor4f_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4fv
void glColor4fv(const GLfloat * v) {
    glColor4fv_INDEXED *packed_data = malloc(sizeof(glColor4fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4i
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
    glColor4i_INDEXED *packed_data = malloc(sizeof(glColor4i_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4iv
void glColor4iv(const GLint * v) {
    glColor4iv_INDEXED *packed_data = malloc(sizeof(glColor4iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4s
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    glColor4s_INDEXED *packed_data = malloc(sizeof(glColor4s_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4sv
void glColor4sv(const GLshort * v) {
    glColor4sv_INDEXED *packed_data = malloc(sizeof(glColor4sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4ub
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    glColor4ub_INDEXED *packed_data = malloc(sizeof(glColor4ub_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4ubv
void glColor4ubv(const GLubyte * v) {
    glColor4ubv_INDEXED *packed_data = malloc(sizeof(glColor4ubv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4ui
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    glColor4ui_INDEXED *packed_data = malloc(sizeof(glColor4ui_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4uiv
void glColor4uiv(const GLuint * v) {
    glColor4uiv_INDEXED *packed_data = malloc(sizeof(glColor4uiv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4us
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    glColor4us_INDEXED *packed_data = malloc(sizeof(glColor4us_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColor4usv
void glColor4usv(const GLushort * v) {
    glColor4usv_INDEXED *packed_data = malloc(sizeof(glColor4usv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColorMask
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    glColorMask_INDEXED *packed_data = malloc(sizeof(glColorMask_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColorMaterial
void glColorMaterial(GLenum face, GLenum mode) {
    glColorMaterial_INDEXED *packed_data = malloc(sizeof(glColorMaterial_INDEXED));
    packed_data->args.a1 = face;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColorPointer
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glColorPointer_INDEXED *packed_data = malloc(sizeof(glColorPointer_INDEXED));
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColorSubTable
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data) {
    glColorSubTable_INDEXED *packed_data = malloc(sizeof(glColorSubTable_INDEXED));
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
#ifndef skip_glColorTable
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table) {
    glColorTable_INDEXED *packed_data = malloc(sizeof(glColorTable_INDEXED));
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
#ifndef skip_glColorTableParameterfv
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glColorTableParameterfv_INDEXED *packed_data = malloc(sizeof(glColorTableParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glColorTableParameteriv
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glColorTableParameteriv_INDEXED *packed_data = malloc(sizeof(glColorTableParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glCompressedTexImage1D
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexImage1D_INDEXED *packed_data = malloc(sizeof(glCompressedTexImage1D_INDEXED));
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
#ifndef skip_glCompressedTexImage2D
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexImage2D_INDEXED *packed_data = malloc(sizeof(glCompressedTexImage2D_INDEXED));
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
#ifndef skip_glCompressedTexImage3D
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexImage3D_INDEXED *packed_data = malloc(sizeof(glCompressedTexImage3D_INDEXED));
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
#ifndef skip_glCompressedTexSubImage1D
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexSubImage1D_INDEXED *packed_data = malloc(sizeof(glCompressedTexSubImage1D_INDEXED));
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
#ifndef skip_glCompressedTexSubImage2D
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexSubImage2D_INDEXED *packed_data = malloc(sizeof(glCompressedTexSubImage2D_INDEXED));
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
#ifndef skip_glCompressedTexSubImage3D
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data) {
    glCompressedTexSubImage3D_INDEXED *packed_data = malloc(sizeof(glCompressedTexSubImage3D_INDEXED));
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
#ifndef skip_glConvolutionFilter1D
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image) {
    glConvolutionFilter1D_INDEXED *packed_data = malloc(sizeof(glConvolutionFilter1D_INDEXED));
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
#ifndef skip_glConvolutionFilter2D
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image) {
    glConvolutionFilter2D_INDEXED *packed_data = malloc(sizeof(glConvolutionFilter2D_INDEXED));
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
#ifndef skip_glConvolutionParameterf
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
    glConvolutionParameterf_INDEXED *packed_data = malloc(sizeof(glConvolutionParameterf_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glConvolutionParameterfv
void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glConvolutionParameterfv_INDEXED *packed_data = malloc(sizeof(glConvolutionParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glConvolutionParameteri
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
    glConvolutionParameteri_INDEXED *packed_data = malloc(sizeof(glConvolutionParameteri_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glConvolutionParameteriv
void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glConvolutionParameteriv_INDEXED *packed_data = malloc(sizeof(glConvolutionParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glCopyColorSubTable
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    glCopyColorSubTable_INDEXED *packed_data = malloc(sizeof(glCopyColorSubTable_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = start;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glCopyColorTable
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    glCopyColorTable_INDEXED *packed_data = malloc(sizeof(glCopyColorTable_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glCopyConvolutionFilter1D
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    glCopyConvolutionFilter1D_INDEXED *packed_data = malloc(sizeof(glCopyConvolutionFilter1D_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glCopyConvolutionFilter2D
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    glCopyConvolutionFilter2D_INDEXED *packed_data = malloc(sizeof(glCopyConvolutionFilter2D_INDEXED));
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
#ifndef skip_glCopyPixels
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
    glCopyPixels_INDEXED *packed_data = malloc(sizeof(glCopyPixels_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = type;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glCopyTexImage1D
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    glCopyTexImage1D_INDEXED *packed_data = malloc(sizeof(glCopyTexImage1D_INDEXED));
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
#ifndef skip_glCopyTexImage2D
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    glCopyTexImage2D_INDEXED *packed_data = malloc(sizeof(glCopyTexImage2D_INDEXED));
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
#ifndef skip_glCopyTexSubImage1D
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    glCopyTexSubImage1D_INDEXED *packed_data = malloc(sizeof(glCopyTexSubImage1D_INDEXED));
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
#ifndef skip_glCopyTexSubImage2D
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glCopyTexSubImage2D_INDEXED *packed_data = malloc(sizeof(glCopyTexSubImage2D_INDEXED));
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
#ifndef skip_glCopyTexSubImage3D
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glCopyTexSubImage3D_INDEXED *packed_data = malloc(sizeof(glCopyTexSubImage3D_INDEXED));
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
#ifndef skip_glCullFace
void glCullFace(GLenum mode) {
    glCullFace_INDEXED *packed_data = malloc(sizeof(glCullFace_INDEXED));
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDeleteBuffers
void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    glDeleteBuffers_INDEXED *packed_data = malloc(sizeof(glDeleteBuffers_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffers;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDeleteLists
void glDeleteLists(GLuint list, GLsizei range) {
    glDeleteLists_INDEXED *packed_data = malloc(sizeof(glDeleteLists_INDEXED));
    packed_data->args.a1 = list;
    packed_data->args.a2 = range;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDeleteQueries
void glDeleteQueries(GLsizei n, const GLuint * ids) {
    glDeleteQueries_INDEXED *packed_data = malloc(sizeof(glDeleteQueries_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = ids;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDeleteTextures
void glDeleteTextures(GLsizei n, const GLuint * textures) {
    glDeleteTextures_INDEXED *packed_data = malloc(sizeof(glDeleteTextures_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDepthFunc
void glDepthFunc(GLenum func) {
    glDepthFunc_INDEXED *packed_data = malloc(sizeof(glDepthFunc_INDEXED));
    packed_data->args.a1 = func;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDepthMask
void glDepthMask(GLboolean flag) {
    glDepthMask_INDEXED *packed_data = malloc(sizeof(glDepthMask_INDEXED));
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDepthRange
void glDepthRange(GLdouble near, GLdouble far) {
    glDepthRange_INDEXED *packed_data = malloc(sizeof(glDepthRange_INDEXED));
    packed_data->args.a1 = near;
    packed_data->args.a2 = far;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDisable
void glDisable(GLenum cap) {
    glDisable_INDEXED *packed_data = malloc(sizeof(glDisable_INDEXED));
    packed_data->args.a1 = cap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDisableClientState
void glDisableClientState(GLenum array) {
    glDisableClientState_INDEXED *packed_data = malloc(sizeof(glDisableClientState_INDEXED));
    packed_data->args.a1 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDrawArrays
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    glDrawArrays_INDEXED *packed_data = malloc(sizeof(glDrawArrays_INDEXED));
    packed_data->args.a1 = mode;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDrawBuffer
void glDrawBuffer(GLenum mode) {
    glDrawBuffer_INDEXED *packed_data = malloc(sizeof(glDrawBuffer_INDEXED));
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDrawElements
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    glDrawElements_INDEXED *packed_data = malloc(sizeof(glDrawElements_INDEXED));
    packed_data->args.a1 = mode;
    packed_data->args.a2 = count;
    packed_data->args.a3 = type;
    packed_data->args.a4 = indices;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDrawPixels
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    glDrawPixels_INDEXED *packed_data = malloc(sizeof(glDrawPixels_INDEXED));
    packed_data->args.a1 = width;
    packed_data->args.a2 = height;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glDrawRangeElements
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices) {
    glDrawRangeElements_INDEXED *packed_data = malloc(sizeof(glDrawRangeElements_INDEXED));
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
#ifndef skip_glEdgeFlag
void glEdgeFlag(GLboolean flag) {
    glEdgeFlag_INDEXED *packed_data = malloc(sizeof(glEdgeFlag_INDEXED));
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEdgeFlagPointer
void glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer) {
    glEdgeFlagPointer_INDEXED *packed_data = malloc(sizeof(glEdgeFlagPointer_INDEXED));
    packed_data->args.a1 = stride;
    packed_data->args.a2 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEdgeFlagv
void glEdgeFlagv(const GLboolean * flag) {
    glEdgeFlagv_INDEXED *packed_data = malloc(sizeof(glEdgeFlagv_INDEXED));
    packed_data->args.a1 = flag;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEnable
void glEnable(GLenum cap) {
    glEnable_INDEXED *packed_data = malloc(sizeof(glEnable_INDEXED));
    packed_data->args.a1 = cap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEnableClientState
void glEnableClientState(GLenum array) {
    glEnableClientState_INDEXED *packed_data = malloc(sizeof(glEnableClientState_INDEXED));
    packed_data->args.a1 = array;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEnd
void glEnd() {
    glEnd_INDEXED *packed_data = malloc(sizeof(glEnd_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEndList
void glEndList() {
    glEndList_INDEXED *packed_data = malloc(sizeof(glEndList_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEndQuery
void glEndQuery(GLenum target) {
    glEndQuery_INDEXED *packed_data = malloc(sizeof(glEndQuery_INDEXED));
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalCoord1d
void glEvalCoord1d(GLdouble u) {
    glEvalCoord1d_INDEXED *packed_data = malloc(sizeof(glEvalCoord1d_INDEXED));
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalCoord1dv
void glEvalCoord1dv(const GLdouble * u) {
    glEvalCoord1dv_INDEXED *packed_data = malloc(sizeof(glEvalCoord1dv_INDEXED));
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalCoord1f
void glEvalCoord1f(GLfloat u) {
    glEvalCoord1f_INDEXED *packed_data = malloc(sizeof(glEvalCoord1f_INDEXED));
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalCoord1fv
void glEvalCoord1fv(const GLfloat * u) {
    glEvalCoord1fv_INDEXED *packed_data = malloc(sizeof(glEvalCoord1fv_INDEXED));
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalCoord2d
void glEvalCoord2d(GLdouble u, GLdouble v) {
    glEvalCoord2d_INDEXED *packed_data = malloc(sizeof(glEvalCoord2d_INDEXED));
    packed_data->args.a1 = u;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalCoord2dv
void glEvalCoord2dv(const GLdouble * u) {
    glEvalCoord2dv_INDEXED *packed_data = malloc(sizeof(glEvalCoord2dv_INDEXED));
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalCoord2f
void glEvalCoord2f(GLfloat u, GLfloat v) {
    glEvalCoord2f_INDEXED *packed_data = malloc(sizeof(glEvalCoord2f_INDEXED));
    packed_data->args.a1 = u;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalCoord2fv
void glEvalCoord2fv(const GLfloat * u) {
    glEvalCoord2fv_INDEXED *packed_data = malloc(sizeof(glEvalCoord2fv_INDEXED));
    packed_data->args.a1 = u;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalMesh1
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    glEvalMesh1_INDEXED *packed_data = malloc(sizeof(glEvalMesh1_INDEXED));
    packed_data->args.a1 = mode;
    packed_data->args.a2 = i1;
    packed_data->args.a3 = i2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalMesh2
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    glEvalMesh2_INDEXED *packed_data = malloc(sizeof(glEvalMesh2_INDEXED));
    packed_data->args.a1 = mode;
    packed_data->args.a2 = i1;
    packed_data->args.a3 = i2;
    packed_data->args.a4 = j1;
    packed_data->args.a5 = j2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalPoint1
void glEvalPoint1(GLint i) {
    glEvalPoint1_INDEXED *packed_data = malloc(sizeof(glEvalPoint1_INDEXED));
    packed_data->args.a1 = i;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glEvalPoint2
void glEvalPoint2(GLint i, GLint j) {
    glEvalPoint2_INDEXED *packed_data = malloc(sizeof(glEvalPoint2_INDEXED));
    packed_data->args.a1 = i;
    packed_data->args.a2 = j;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFeedbackBuffer
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
    glFeedbackBuffer_INDEXED *packed_data = malloc(sizeof(glFeedbackBuffer_INDEXED));
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFinish
void glFinish() {
    glFinish_INDEXED *packed_data = malloc(sizeof(glFinish_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFlush
void glFlush() {
    glFlush_INDEXED *packed_data = malloc(sizeof(glFlush_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogCoordPointer
void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glFogCoordPointer_INDEXED *packed_data = malloc(sizeof(glFogCoordPointer_INDEXED));
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogCoordd
void glFogCoordd(GLdouble coord) {
    glFogCoordd_INDEXED *packed_data = malloc(sizeof(glFogCoordd_INDEXED));
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogCoorddv
void glFogCoorddv(const GLdouble * coord) {
    glFogCoorddv_INDEXED *packed_data = malloc(sizeof(glFogCoorddv_INDEXED));
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogCoordf
void glFogCoordf(GLfloat coord) {
    glFogCoordf_INDEXED *packed_data = malloc(sizeof(glFogCoordf_INDEXED));
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogCoordfv
void glFogCoordfv(const GLfloat * coord) {
    glFogCoordfv_INDEXED *packed_data = malloc(sizeof(glFogCoordfv_INDEXED));
    packed_data->args.a1 = coord;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogf
void glFogf(GLenum pname, GLfloat param) {
    glFogf_INDEXED *packed_data = malloc(sizeof(glFogf_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogfv
void glFogfv(GLenum pname, const GLfloat * params) {
    glFogfv_INDEXED *packed_data = malloc(sizeof(glFogfv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogi
void glFogi(GLenum pname, GLint param) {
    glFogi_INDEXED *packed_data = malloc(sizeof(glFogi_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFogiv
void glFogiv(GLenum pname, const GLint * params) {
    glFogiv_INDEXED *packed_data = malloc(sizeof(glFogiv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFrontFace
void glFrontFace(GLenum mode) {
    glFrontFace_INDEXED *packed_data = malloc(sizeof(glFrontFace_INDEXED));
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glFrustum
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    glFrustum_INDEXED *packed_data = malloc(sizeof(glFrustum_INDEXED));
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
#ifndef skip_glGenBuffers
void glGenBuffers(GLsizei n, GLuint * buffers) {
    glGenBuffers_INDEXED *packed_data = malloc(sizeof(glGenBuffers_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffers;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGenLists
GLuint glGenLists(GLsizei range) {
    glGenLists_INDEXED *packed_data = malloc(sizeof(glGenLists_INDEXED));
    packed_data->args.a1 = range;
    GLuint ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glGenQueries
void glGenQueries(GLsizei n, GLuint * ids) {
    glGenQueries_INDEXED *packed_data = malloc(sizeof(glGenQueries_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = ids;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGenTextures
void glGenTextures(GLsizei n, GLuint * textures) {
    glGenTextures_INDEXED *packed_data = malloc(sizeof(glGenTextures_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetBooleanv
void glGetBooleanv(GLenum pname, GLboolean * params) {
    glGetBooleanv_INDEXED *packed_data = malloc(sizeof(glGetBooleanv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetBufferParameteriv
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetBufferParameteriv_INDEXED *packed_data = malloc(sizeof(glGetBufferParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetBufferPointerv
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params) {
    glGetBufferPointerv_INDEXED *packed_data = malloc(sizeof(glGetBufferPointerv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetBufferSubData
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
    glGetBufferSubData_INDEXED *packed_data = malloc(sizeof(glGetBufferSubData_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = size;
    packed_data->args.a4 = data;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetClipPlane
void glGetClipPlane(GLenum plane, GLdouble * equation) {
    glGetClipPlane_INDEXED *packed_data = malloc(sizeof(glGetClipPlane_INDEXED));
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetColorTable
void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid * table) {
    glGetColorTable_INDEXED *packed_data = malloc(sizeof(glGetColorTable_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = table;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetColorTableParameterfv
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetColorTableParameterfv_INDEXED *packed_data = malloc(sizeof(glGetColorTableParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetColorTableParameteriv
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetColorTableParameteriv_INDEXED *packed_data = malloc(sizeof(glGetColorTableParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetCompressedTexImage
void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img) {
    glGetCompressedTexImage_INDEXED *packed_data = malloc(sizeof(glGetCompressedTexImage_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = img;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetConvolutionFilter
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid * image) {
    glGetConvolutionFilter_INDEXED *packed_data = malloc(sizeof(glGetConvolutionFilter_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = image;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetConvolutionParameterfv
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetConvolutionParameterfv_INDEXED *packed_data = malloc(sizeof(glGetConvolutionParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetConvolutionParameteriv
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetConvolutionParameteriv_INDEXED *packed_data = malloc(sizeof(glGetConvolutionParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetDoublev
void glGetDoublev(GLenum pname, GLdouble * params) {
    glGetDoublev_INDEXED *packed_data = malloc(sizeof(glGetDoublev_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetError
GLenum glGetError() {
    glGetError_INDEXED *packed_data = malloc(sizeof(glGetError_INDEXED));
    GLenum ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glGetFloatv
void glGetFloatv(GLenum pname, GLfloat * params) {
    glGetFloatv_INDEXED *packed_data = malloc(sizeof(glGetFloatv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetHistogram
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    glGetHistogram_INDEXED *packed_data = malloc(sizeof(glGetHistogram_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = reset;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetHistogramParameterfv
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetHistogramParameterfv_INDEXED *packed_data = malloc(sizeof(glGetHistogramParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetHistogramParameteriv
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetHistogramParameteriv_INDEXED *packed_data = malloc(sizeof(glGetHistogramParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetIntegerv
void glGetIntegerv(GLenum pname, GLint * params) {
    glGetIntegerv_INDEXED *packed_data = malloc(sizeof(glGetIntegerv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetLightfv
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    glGetLightfv_INDEXED *packed_data = malloc(sizeof(glGetLightfv_INDEXED));
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetLightiv
void glGetLightiv(GLenum light, GLenum pname, GLint * params) {
    glGetLightiv_INDEXED *packed_data = malloc(sizeof(glGetLightiv_INDEXED));
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetMapdv
void glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
    glGetMapdv_INDEXED *packed_data = malloc(sizeof(glGetMapdv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetMapfv
void glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
    glGetMapfv_INDEXED *packed_data = malloc(sizeof(glGetMapfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetMapiv
void glGetMapiv(GLenum target, GLenum query, GLint * v) {
    glGetMapiv_INDEXED *packed_data = malloc(sizeof(glGetMapiv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetMaterialfv
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    glGetMaterialfv_INDEXED *packed_data = malloc(sizeof(glGetMaterialfv_INDEXED));
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetMaterialiv
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
    glGetMaterialiv_INDEXED *packed_data = malloc(sizeof(glGetMaterialiv_INDEXED));
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetMinmax
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    glGetMinmax_INDEXED *packed_data = malloc(sizeof(glGetMinmax_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = reset;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetMinmaxParameterfv
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetMinmaxParameterfv_INDEXED *packed_data = malloc(sizeof(glGetMinmaxParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetMinmaxParameteriv
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetMinmaxParameteriv_INDEXED *packed_data = malloc(sizeof(glGetMinmaxParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetPixelMapfv
void glGetPixelMapfv(GLenum map, GLfloat * values) {
    glGetPixelMapfv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapfv_INDEXED));
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetPixelMapuiv
void glGetPixelMapuiv(GLenum map, GLuint * values) {
    glGetPixelMapuiv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapuiv_INDEXED));
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetPixelMapusv
void glGetPixelMapusv(GLenum map, GLushort * values) {
    glGetPixelMapusv_INDEXED *packed_data = malloc(sizeof(glGetPixelMapusv_INDEXED));
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetPointerv
void glGetPointerv(GLenum pname, GLvoid ** params) {
    glGetPointerv_INDEXED *packed_data = malloc(sizeof(glGetPointerv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetPolygonStipple
void glGetPolygonStipple(GLubyte * mask) {
    glGetPolygonStipple_INDEXED *packed_data = malloc(sizeof(glGetPolygonStipple_INDEXED));
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetQueryObjectiv
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    glGetQueryObjectiv_INDEXED *packed_data = malloc(sizeof(glGetQueryObjectiv_INDEXED));
    packed_data->args.a1 = id;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetQueryObjectuiv
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    glGetQueryObjectuiv_INDEXED *packed_data = malloc(sizeof(glGetQueryObjectuiv_INDEXED));
    packed_data->args.a1 = id;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetQueryiv
void glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    glGetQueryiv_INDEXED *packed_data = malloc(sizeof(glGetQueryiv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetSeparableFilter
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span) {
    glGetSeparableFilter_INDEXED *packed_data = malloc(sizeof(glGetSeparableFilter_INDEXED));
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
#ifndef skip_glGetString
const GLubyte * glGetString(GLenum name) {
    glGetString_INDEXED *packed_data = malloc(sizeof(glGetString_INDEXED));
    packed_data->args.a1 = name;
    const GLubyte * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glGetTexEnvfv
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetTexEnvfv_INDEXED *packed_data = malloc(sizeof(glGetTexEnvfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexEnviv
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    glGetTexEnviv_INDEXED *packed_data = malloc(sizeof(glGetTexEnviv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexGendv
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
    glGetTexGendv_INDEXED *packed_data = malloc(sizeof(glGetTexGendv_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexGenfv
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
    glGetTexGenfv_INDEXED *packed_data = malloc(sizeof(glGetTexGenfv_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexGeniv
void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
    glGetTexGeniv_INDEXED *packed_data = malloc(sizeof(glGetTexGeniv_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexImage
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels) {
    glGetTexImage_INDEXED *packed_data = malloc(sizeof(glGetTexImage_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = pixels;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexLevelParameterfv
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    glGetTexLevelParameterfv_INDEXED *packed_data = malloc(sizeof(glGetTexLevelParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexLevelParameteriv
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    glGetTexLevelParameteriv_INDEXED *packed_data = malloc(sizeof(glGetTexLevelParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexParameterfv
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glGetTexParameterfv_INDEXED *packed_data = malloc(sizeof(glGetTexParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glGetTexParameteriv
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    glGetTexParameteriv_INDEXED *packed_data = malloc(sizeof(glGetTexParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glHint
void glHint(GLenum target, GLenum mode) {
    glHint_INDEXED *packed_data = malloc(sizeof(glHint_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glHistogram
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    glHistogram_INDEXED *packed_data = malloc(sizeof(glHistogram_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = width;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = sink;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexMask
void glIndexMask(GLuint mask) {
    glIndexMask_INDEXED *packed_data = malloc(sizeof(glIndexMask_INDEXED));
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexPointer
void glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glIndexPointer_INDEXED *packed_data = malloc(sizeof(glIndexPointer_INDEXED));
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexd
void glIndexd(GLdouble c) {
    glIndexd_INDEXED *packed_data = malloc(sizeof(glIndexd_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexdv
void glIndexdv(const GLdouble * c) {
    glIndexdv_INDEXED *packed_data = malloc(sizeof(glIndexdv_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexf
void glIndexf(GLfloat c) {
    glIndexf_INDEXED *packed_data = malloc(sizeof(glIndexf_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexfv
void glIndexfv(const GLfloat * c) {
    glIndexfv_INDEXED *packed_data = malloc(sizeof(glIndexfv_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexi
void glIndexi(GLint c) {
    glIndexi_INDEXED *packed_data = malloc(sizeof(glIndexi_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexiv
void glIndexiv(const GLint * c) {
    glIndexiv_INDEXED *packed_data = malloc(sizeof(glIndexiv_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexs
void glIndexs(GLshort c) {
    glIndexs_INDEXED *packed_data = malloc(sizeof(glIndexs_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexsv
void glIndexsv(const GLshort * c) {
    glIndexsv_INDEXED *packed_data = malloc(sizeof(glIndexsv_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexub
void glIndexub(GLubyte c) {
    glIndexub_INDEXED *packed_data = malloc(sizeof(glIndexub_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIndexubv
void glIndexubv(const GLubyte * c) {
    glIndexubv_INDEXED *packed_data = malloc(sizeof(glIndexubv_INDEXED));
    packed_data->args.a1 = c;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glInitNames
void glInitNames() {
    glInitNames_INDEXED *packed_data = malloc(sizeof(glInitNames_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glInterleavedArrays
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid * pointer) {
    glInterleavedArrays_INDEXED *packed_data = malloc(sizeof(glInterleavedArrays_INDEXED));
    packed_data->args.a1 = format;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glIsBuffer
GLboolean glIsBuffer(GLuint buffer) {
    glIsBuffer_INDEXED *packed_data = malloc(sizeof(glIsBuffer_INDEXED));
    packed_data->args.a1 = buffer;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glIsEnabled
GLboolean glIsEnabled(GLenum cap) {
    glIsEnabled_INDEXED *packed_data = malloc(sizeof(glIsEnabled_INDEXED));
    packed_data->args.a1 = cap;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glIsList
GLboolean glIsList(GLuint list) {
    glIsList_INDEXED *packed_data = malloc(sizeof(glIsList_INDEXED));
    packed_data->args.a1 = list;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glIsQuery
GLboolean glIsQuery(GLuint id) {
    glIsQuery_INDEXED *packed_data = malloc(sizeof(glIsQuery_INDEXED));
    packed_data->args.a1 = id;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glIsTexture
GLboolean glIsTexture(GLuint texture) {
    glIsTexture_INDEXED *packed_data = malloc(sizeof(glIsTexture_INDEXED));
    packed_data->args.a1 = texture;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glLightModelf
void glLightModelf(GLenum pname, GLfloat param) {
    glLightModelf_INDEXED *packed_data = malloc(sizeof(glLightModelf_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLightModelfv
void glLightModelfv(GLenum pname, const GLfloat * params) {
    glLightModelfv_INDEXED *packed_data = malloc(sizeof(glLightModelfv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLightModeli
void glLightModeli(GLenum pname, GLint param) {
    glLightModeli_INDEXED *packed_data = malloc(sizeof(glLightModeli_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLightModeliv
void glLightModeliv(GLenum pname, const GLint * params) {
    glLightModeliv_INDEXED *packed_data = malloc(sizeof(glLightModeliv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLightf
void glLightf(GLenum light, GLenum pname, GLfloat param) {
    glLightf_INDEXED *packed_data = malloc(sizeof(glLightf_INDEXED));
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLightfv
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    glLightfv_INDEXED *packed_data = malloc(sizeof(glLightfv_INDEXED));
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLighti
void glLighti(GLenum light, GLenum pname, GLint param) {
    glLighti_INDEXED *packed_data = malloc(sizeof(glLighti_INDEXED));
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLightiv
void glLightiv(GLenum light, GLenum pname, const GLint * params) {
    glLightiv_INDEXED *packed_data = malloc(sizeof(glLightiv_INDEXED));
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLineStipple
void glLineStipple(GLint factor, GLushort pattern) {
    glLineStipple_INDEXED *packed_data = malloc(sizeof(glLineStipple_INDEXED));
    packed_data->args.a1 = factor;
    packed_data->args.a2 = pattern;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLineWidth
void glLineWidth(GLfloat width) {
    glLineWidth_INDEXED *packed_data = malloc(sizeof(glLineWidth_INDEXED));
    packed_data->args.a1 = width;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glListBase
void glListBase(GLuint base) {
    glListBase_INDEXED *packed_data = malloc(sizeof(glListBase_INDEXED));
    packed_data->args.a1 = base;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLoadIdentity
void glLoadIdentity() {
    glLoadIdentity_INDEXED *packed_data = malloc(sizeof(glLoadIdentity_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLoadMatrixd
void glLoadMatrixd(const GLdouble * m) {
    glLoadMatrixd_INDEXED *packed_data = malloc(sizeof(glLoadMatrixd_INDEXED));
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLoadMatrixf
void glLoadMatrixf(const GLfloat * m) {
    glLoadMatrixf_INDEXED *packed_data = malloc(sizeof(glLoadMatrixf_INDEXED));
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLoadName
void glLoadName(GLuint name) {
    glLoadName_INDEXED *packed_data = malloc(sizeof(glLoadName_INDEXED));
    packed_data->args.a1 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLoadTransposeMatrixd
void glLoadTransposeMatrixd(const GLdouble * m) {
    glLoadTransposeMatrixd_INDEXED *packed_data = malloc(sizeof(glLoadTransposeMatrixd_INDEXED));
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLoadTransposeMatrixf
void glLoadTransposeMatrixf(const GLfloat * m) {
    glLoadTransposeMatrixf_INDEXED *packed_data = malloc(sizeof(glLoadTransposeMatrixf_INDEXED));
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glLogicOp
void glLogicOp(GLenum opcode) {
    glLogicOp_INDEXED *packed_data = malloc(sizeof(glLogicOp_INDEXED));
    packed_data->args.a1 = opcode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMap1d
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points) {
    glMap1d_INDEXED *packed_data = malloc(sizeof(glMap1d_INDEXED));
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
#ifndef skip_glMap1f
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points) {
    glMap1f_INDEXED *packed_data = malloc(sizeof(glMap1f_INDEXED));
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
#ifndef skip_glMap2d
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points) {
    glMap2d_INDEXED *packed_data = malloc(sizeof(glMap2d_INDEXED));
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
#ifndef skip_glMap2f
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points) {
    glMap2f_INDEXED *packed_data = malloc(sizeof(glMap2f_INDEXED));
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
#ifndef skip_glMapBuffer
GLvoid * glMapBuffer(GLenum target, GLenum access) {
    glMapBuffer_INDEXED *packed_data = malloc(sizeof(glMapBuffer_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = access;
    GLvoid * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glMapGrid1d
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    glMapGrid1d_INDEXED *packed_data = malloc(sizeof(glMapGrid1d_INDEXED));
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMapGrid1f
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    glMapGrid1f_INDEXED *packed_data = malloc(sizeof(glMapGrid1f_INDEXED));
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMapGrid2d
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
    glMapGrid2d_INDEXED *packed_data = malloc(sizeof(glMapGrid2d_INDEXED));
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
#ifndef skip_glMapGrid2f
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
    glMapGrid2f_INDEXED *packed_data = malloc(sizeof(glMapGrid2f_INDEXED));
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
#ifndef skip_glMaterialf
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    glMaterialf_INDEXED *packed_data = malloc(sizeof(glMaterialf_INDEXED));
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMaterialfv
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    glMaterialfv_INDEXED *packed_data = malloc(sizeof(glMaterialfv_INDEXED));
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMateriali
void glMateriali(GLenum face, GLenum pname, GLint param) {
    glMateriali_INDEXED *packed_data = malloc(sizeof(glMateriali_INDEXED));
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMaterialiv
void glMaterialiv(GLenum face, GLenum pname, const GLint * params) {
    glMaterialiv_INDEXED *packed_data = malloc(sizeof(glMaterialiv_INDEXED));
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMatrixMode
void glMatrixMode(GLenum mode) {
    glMatrixMode_INDEXED *packed_data = malloc(sizeof(glMatrixMode_INDEXED));
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMinmax
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
    glMinmax_INDEXED *packed_data = malloc(sizeof(glMinmax_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = sink;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultMatrixd
void glMultMatrixd(const GLdouble * m) {
    glMultMatrixd_INDEXED *packed_data = malloc(sizeof(glMultMatrixd_INDEXED));
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultMatrixf
void glMultMatrixf(const GLfloat * m) {
    glMultMatrixf_INDEXED *packed_data = malloc(sizeof(glMultMatrixf_INDEXED));
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultTransposeMatrixd
void glMultTransposeMatrixd(const GLdouble * m) {
    glMultTransposeMatrixd_INDEXED *packed_data = malloc(sizeof(glMultTransposeMatrixd_INDEXED));
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultTransposeMatrixf
void glMultTransposeMatrixf(const GLfloat * m) {
    glMultTransposeMatrixf_INDEXED *packed_data = malloc(sizeof(glMultTransposeMatrixf_INDEXED));
    packed_data->args.a1 = m;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiDrawArrays
void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    glMultiDrawArrays_INDEXED *packed_data = malloc(sizeof(glMultiDrawArrays_INDEXED));
    packed_data->args.a1 = mode;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    packed_data->args.a4 = drawcount;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiDrawElements
void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, GLvoid*const * indices, GLsizei drawcount) {
    glMultiDrawElements_INDEXED *packed_data = malloc(sizeof(glMultiDrawElements_INDEXED));
    packed_data->args.a1 = mode;
    packed_data->args.a2 = count;
    packed_data->args.a3 = type;
    packed_data->args.a4 = indices;
    packed_data->args.a5 = drawcount;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord1d
void glMultiTexCoord1d(GLenum target, GLdouble s) {
    glMultiTexCoord1d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1d_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord1dv
void glMultiTexCoord1dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord1dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1dv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord1f
void glMultiTexCoord1f(GLenum target, GLfloat s) {
    glMultiTexCoord1f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1f_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord1fv
void glMultiTexCoord1fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord1fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1fv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord1i
void glMultiTexCoord1i(GLenum target, GLint s) {
    glMultiTexCoord1i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1i_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord1iv
void glMultiTexCoord1iv(GLenum target, const GLint * v) {
    glMultiTexCoord1iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1iv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord1s
void glMultiTexCoord1s(GLenum target, GLshort s) {
    glMultiTexCoord1s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1s_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord1sv
void glMultiTexCoord1sv(GLenum target, const GLshort * v) {
    glMultiTexCoord1sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord1sv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord2d
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    glMultiTexCoord2d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2d_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord2dv
void glMultiTexCoord2dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord2dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2dv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord2f
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    glMultiTexCoord2f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2f_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord2fv
void glMultiTexCoord2fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord2fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2fv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord2i
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
    glMultiTexCoord2i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2i_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord2iv
void glMultiTexCoord2iv(GLenum target, const GLint * v) {
    glMultiTexCoord2iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2iv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord2s
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    glMultiTexCoord2s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2s_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord2sv
void glMultiTexCoord2sv(GLenum target, const GLshort * v) {
    glMultiTexCoord2sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord2sv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord3d
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    glMultiTexCoord3d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3d_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord3dv
void glMultiTexCoord3dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord3dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3dv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord3f
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    glMultiTexCoord3f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3f_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord3fv
void glMultiTexCoord3fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord3fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3fv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord3i
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    glMultiTexCoord3i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3i_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord3iv
void glMultiTexCoord3iv(GLenum target, const GLint * v) {
    glMultiTexCoord3iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3iv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord3s
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    glMultiTexCoord3s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3s_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord3sv
void glMultiTexCoord3sv(GLenum target, const GLshort * v) {
    glMultiTexCoord3sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord3sv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord4d
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    glMultiTexCoord4d_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4d_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord4dv
void glMultiTexCoord4dv(GLenum target, const GLdouble * v) {
    glMultiTexCoord4dv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4dv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord4f
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    glMultiTexCoord4f_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4f_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord4fv
void glMultiTexCoord4fv(GLenum target, const GLfloat * v) {
    glMultiTexCoord4fv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4fv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord4i
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    glMultiTexCoord4i_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4i_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord4iv
void glMultiTexCoord4iv(GLenum target, const GLint * v) {
    glMultiTexCoord4iv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4iv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord4s
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    glMultiTexCoord4s_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4s_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glMultiTexCoord4sv
void glMultiTexCoord4sv(GLenum target, const GLshort * v) {
    glMultiTexCoord4sv_INDEXED *packed_data = malloc(sizeof(glMultiTexCoord4sv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNewList
void glNewList(GLuint list, GLenum mode) {
    glNewList_INDEXED *packed_data = malloc(sizeof(glNewList_INDEXED));
    packed_data->args.a1 = list;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3b
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    glNormal3b_INDEXED *packed_data = malloc(sizeof(glNormal3b_INDEXED));
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3bv
void glNormal3bv(const GLbyte * v) {
    glNormal3bv_INDEXED *packed_data = malloc(sizeof(glNormal3bv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3d
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    glNormal3d_INDEXED *packed_data = malloc(sizeof(glNormal3d_INDEXED));
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3dv
void glNormal3dv(const GLdouble * v) {
    glNormal3dv_INDEXED *packed_data = malloc(sizeof(glNormal3dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3f
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    glNormal3f_INDEXED *packed_data = malloc(sizeof(glNormal3f_INDEXED));
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3fv
void glNormal3fv(const GLfloat * v) {
    glNormal3fv_INDEXED *packed_data = malloc(sizeof(glNormal3fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3i
void glNormal3i(GLint nx, GLint ny, GLint nz) {
    glNormal3i_INDEXED *packed_data = malloc(sizeof(glNormal3i_INDEXED));
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3iv
void glNormal3iv(const GLint * v) {
    glNormal3iv_INDEXED *packed_data = malloc(sizeof(glNormal3iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3s
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
    glNormal3s_INDEXED *packed_data = malloc(sizeof(glNormal3s_INDEXED));
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormal3sv
void glNormal3sv(const GLshort * v) {
    glNormal3sv_INDEXED *packed_data = malloc(sizeof(glNormal3sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glNormalPointer
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    glNormalPointer_INDEXED *packed_data = malloc(sizeof(glNormalPointer_INDEXED));
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glOrtho
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    glOrtho_INDEXED *packed_data = malloc(sizeof(glOrtho_INDEXED));
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
#ifndef skip_glPassThrough
void glPassThrough(GLfloat token) {
    glPassThrough_INDEXED *packed_data = malloc(sizeof(glPassThrough_INDEXED));
    packed_data->args.a1 = token;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPixelMapfv
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values) {
    glPixelMapfv_INDEXED *packed_data = malloc(sizeof(glPixelMapfv_INDEXED));
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPixelMapuiv
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values) {
    glPixelMapuiv_INDEXED *packed_data = malloc(sizeof(glPixelMapuiv_INDEXED));
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPixelMapusv
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values) {
    glPixelMapusv_INDEXED *packed_data = malloc(sizeof(glPixelMapusv_INDEXED));
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPixelStoref
void glPixelStoref(GLenum pname, GLfloat param) {
    glPixelStoref_INDEXED *packed_data = malloc(sizeof(glPixelStoref_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPixelStorei
void glPixelStorei(GLenum pname, GLint param) {
    glPixelStorei_INDEXED *packed_data = malloc(sizeof(glPixelStorei_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPixelTransferf
void glPixelTransferf(GLenum pname, GLfloat param) {
    glPixelTransferf_INDEXED *packed_data = malloc(sizeof(glPixelTransferf_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPixelTransferi
void glPixelTransferi(GLenum pname, GLint param) {
    glPixelTransferi_INDEXED *packed_data = malloc(sizeof(glPixelTransferi_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPixelZoom
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    glPixelZoom_INDEXED *packed_data = malloc(sizeof(glPixelZoom_INDEXED));
    packed_data->args.a1 = xfactor;
    packed_data->args.a2 = yfactor;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPointParameterf
void glPointParameterf(GLenum pname, GLfloat param) {
    glPointParameterf_INDEXED *packed_data = malloc(sizeof(glPointParameterf_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPointParameterfv
void glPointParameterfv(GLenum pname, const GLfloat * params) {
    glPointParameterfv_INDEXED *packed_data = malloc(sizeof(glPointParameterfv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPointParameteri
void glPointParameteri(GLenum pname, GLint param) {
    glPointParameteri_INDEXED *packed_data = malloc(sizeof(glPointParameteri_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPointParameteriv
void glPointParameteriv(GLenum pname, const GLint * params) {
    glPointParameteriv_INDEXED *packed_data = malloc(sizeof(glPointParameteriv_INDEXED));
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPointSize
void glPointSize(GLfloat size) {
    glPointSize_INDEXED *packed_data = malloc(sizeof(glPointSize_INDEXED));
    packed_data->args.a1 = size;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPolygonMode
void glPolygonMode(GLenum face, GLenum mode) {
    glPolygonMode_INDEXED *packed_data = malloc(sizeof(glPolygonMode_INDEXED));
    packed_data->args.a1 = face;
    packed_data->args.a2 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPolygonOffset
void glPolygonOffset(GLfloat factor, GLfloat units) {
    glPolygonOffset_INDEXED *packed_data = malloc(sizeof(glPolygonOffset_INDEXED));
    packed_data->args.a1 = factor;
    packed_data->args.a2 = units;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPolygonStipple
void glPolygonStipple(const GLubyte * mask) {
    glPolygonStipple_INDEXED *packed_data = malloc(sizeof(glPolygonStipple_INDEXED));
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPopAttrib
void glPopAttrib() {
    glPopAttrib_INDEXED *packed_data = malloc(sizeof(glPopAttrib_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPopClientAttrib
void glPopClientAttrib() {
    glPopClientAttrib_INDEXED *packed_data = malloc(sizeof(glPopClientAttrib_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPopMatrix
void glPopMatrix() {
    glPopMatrix_INDEXED *packed_data = malloc(sizeof(glPopMatrix_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPopName
void glPopName() {
    glPopName_INDEXED *packed_data = malloc(sizeof(glPopName_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPrioritizeTextures
void glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities) {
    glPrioritizeTextures_INDEXED *packed_data = malloc(sizeof(glPrioritizeTextures_INDEXED));
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    packed_data->args.a3 = priorities;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPushAttrib
void glPushAttrib(GLbitfield mask) {
    glPushAttrib_INDEXED *packed_data = malloc(sizeof(glPushAttrib_INDEXED));
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPushClientAttrib
void glPushClientAttrib(GLbitfield mask) {
    glPushClientAttrib_INDEXED *packed_data = malloc(sizeof(glPushClientAttrib_INDEXED));
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPushMatrix
void glPushMatrix() {
    glPushMatrix_INDEXED *packed_data = malloc(sizeof(glPushMatrix_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glPushName
void glPushName(GLuint name) {
    glPushName_INDEXED *packed_data = malloc(sizeof(glPushName_INDEXED));
    packed_data->args.a1 = name;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos2d
void glRasterPos2d(GLdouble x, GLdouble y) {
    glRasterPos2d_INDEXED *packed_data = malloc(sizeof(glRasterPos2d_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos2dv
void glRasterPos2dv(const GLdouble * v) {
    glRasterPos2dv_INDEXED *packed_data = malloc(sizeof(glRasterPos2dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos2f
void glRasterPos2f(GLfloat x, GLfloat y) {
    glRasterPos2f_INDEXED *packed_data = malloc(sizeof(glRasterPos2f_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos2fv
void glRasterPos2fv(const GLfloat * v) {
    glRasterPos2fv_INDEXED *packed_data = malloc(sizeof(glRasterPos2fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos2i
void glRasterPos2i(GLint x, GLint y) {
    glRasterPos2i_INDEXED *packed_data = malloc(sizeof(glRasterPos2i_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos2iv
void glRasterPos2iv(const GLint * v) {
    glRasterPos2iv_INDEXED *packed_data = malloc(sizeof(glRasterPos2iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos2s
void glRasterPos2s(GLshort x, GLshort y) {
    glRasterPos2s_INDEXED *packed_data = malloc(sizeof(glRasterPos2s_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos2sv
void glRasterPos2sv(const GLshort * v) {
    glRasterPos2sv_INDEXED *packed_data = malloc(sizeof(glRasterPos2sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos3d
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    glRasterPos3d_INDEXED *packed_data = malloc(sizeof(glRasterPos3d_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos3dv
void glRasterPos3dv(const GLdouble * v) {
    glRasterPos3dv_INDEXED *packed_data = malloc(sizeof(glRasterPos3dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos3f
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    glRasterPos3f_INDEXED *packed_data = malloc(sizeof(glRasterPos3f_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos3fv
void glRasterPos3fv(const GLfloat * v) {
    glRasterPos3fv_INDEXED *packed_data = malloc(sizeof(glRasterPos3fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos3i
void glRasterPos3i(GLint x, GLint y, GLint z) {
    glRasterPos3i_INDEXED *packed_data = malloc(sizeof(glRasterPos3i_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos3iv
void glRasterPos3iv(const GLint * v) {
    glRasterPos3iv_INDEXED *packed_data = malloc(sizeof(glRasterPos3iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos3s
void glRasterPos3s(GLshort x, GLshort y, GLshort z) {
    glRasterPos3s_INDEXED *packed_data = malloc(sizeof(glRasterPos3s_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos3sv
void glRasterPos3sv(const GLshort * v) {
    glRasterPos3sv_INDEXED *packed_data = malloc(sizeof(glRasterPos3sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos4d
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glRasterPos4d_INDEXED *packed_data = malloc(sizeof(glRasterPos4d_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos4dv
void glRasterPos4dv(const GLdouble * v) {
    glRasterPos4dv_INDEXED *packed_data = malloc(sizeof(glRasterPos4dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos4f
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glRasterPos4f_INDEXED *packed_data = malloc(sizeof(glRasterPos4f_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos4fv
void glRasterPos4fv(const GLfloat * v) {
    glRasterPos4fv_INDEXED *packed_data = malloc(sizeof(glRasterPos4fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos4i
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    glRasterPos4i_INDEXED *packed_data = malloc(sizeof(glRasterPos4i_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos4iv
void glRasterPos4iv(const GLint * v) {
    glRasterPos4iv_INDEXED *packed_data = malloc(sizeof(glRasterPos4iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos4s
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    glRasterPos4s_INDEXED *packed_data = malloc(sizeof(glRasterPos4s_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRasterPos4sv
void glRasterPos4sv(const GLshort * v) {
    glRasterPos4sv_INDEXED *packed_data = malloc(sizeof(glRasterPos4sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glReadBuffer
void glReadBuffer(GLenum mode) {
    glReadBuffer_INDEXED *packed_data = malloc(sizeof(glReadBuffer_INDEXED));
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glReadPixels
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    glReadPixels_INDEXED *packed_data = malloc(sizeof(glReadPixels_INDEXED));
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
#ifndef skip_glRectd
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    glRectd_INDEXED *packed_data = malloc(sizeof(glRectd_INDEXED));
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRectdv
void glRectdv(const GLdouble * v1, const GLdouble * v2) {
    glRectdv_INDEXED *packed_data = malloc(sizeof(glRectdv_INDEXED));
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRectf
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glRectf_INDEXED *packed_data = malloc(sizeof(glRectf_INDEXED));
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRectfv
void glRectfv(const GLfloat * v1, const GLfloat * v2) {
    glRectfv_INDEXED *packed_data = malloc(sizeof(glRectfv_INDEXED));
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRecti
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
    glRecti_INDEXED *packed_data = malloc(sizeof(glRecti_INDEXED));
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRectiv
void glRectiv(const GLint * v1, const GLint * v2) {
    glRectiv_INDEXED *packed_data = malloc(sizeof(glRectiv_INDEXED));
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRects
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    glRects_INDEXED *packed_data = malloc(sizeof(glRects_INDEXED));
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRectsv
void glRectsv(const GLshort * v1, const GLshort * v2) {
    glRectsv_INDEXED *packed_data = malloc(sizeof(glRectsv_INDEXED));
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRenderMode
GLint glRenderMode(GLenum mode) {
    glRenderMode_INDEXED *packed_data = malloc(sizeof(glRenderMode_INDEXED));
    packed_data->args.a1 = mode;
    GLint ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glResetHistogram
void glResetHistogram(GLenum target) {
    glResetHistogram_INDEXED *packed_data = malloc(sizeof(glResetHistogram_INDEXED));
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glResetMinmax
void glResetMinmax(GLenum target) {
    glResetMinmax_INDEXED *packed_data = malloc(sizeof(glResetMinmax_INDEXED));
    packed_data->args.a1 = target;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRotated
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    glRotated_INDEXED *packed_data = malloc(sizeof(glRotated_INDEXED));
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glRotatef
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    glRotatef_INDEXED *packed_data = malloc(sizeof(glRotatef_INDEXED));
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSampleCoverage
void glSampleCoverage(GLfloat value, GLboolean invert) {
    glSampleCoverage_INDEXED *packed_data = malloc(sizeof(glSampleCoverage_INDEXED));
    packed_data->args.a1 = value;
    packed_data->args.a2 = invert;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glScaled
void glScaled(GLdouble x, GLdouble y, GLdouble z) {
    glScaled_INDEXED *packed_data = malloc(sizeof(glScaled_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glScalef
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
    glScalef_INDEXED *packed_data = malloc(sizeof(glScalef_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glScissor
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    glScissor_INDEXED *packed_data = malloc(sizeof(glScissor_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3b
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    glSecondaryColor3b_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3b_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3bv
void glSecondaryColor3bv(const GLbyte * v) {
    glSecondaryColor3bv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3bv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3d
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    glSecondaryColor3d_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3d_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3dv
void glSecondaryColor3dv(const GLdouble * v) {
    glSecondaryColor3dv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3f
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    glSecondaryColor3f_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3f_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3fv
void glSecondaryColor3fv(const GLfloat * v) {
    glSecondaryColor3fv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3i
void glSecondaryColor3i(GLint red, GLint green, GLint blue) {
    glSecondaryColor3i_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3i_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3iv
void glSecondaryColor3iv(const GLint * v) {
    glSecondaryColor3iv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3s
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    glSecondaryColor3s_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3s_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3sv
void glSecondaryColor3sv(const GLshort * v) {
    glSecondaryColor3sv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3ub
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    glSecondaryColor3ub_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ub_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3ubv
void glSecondaryColor3ubv(const GLubyte * v) {
    glSecondaryColor3ubv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ubv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3ui
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    glSecondaryColor3ui_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3ui_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3uiv
void glSecondaryColor3uiv(const GLuint * v) {
    glSecondaryColor3uiv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3uiv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3us
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    glSecondaryColor3us_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3us_INDEXED));
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColor3usv
void glSecondaryColor3usv(const GLushort * v) {
    glSecondaryColor3usv_INDEXED *packed_data = malloc(sizeof(glSecondaryColor3usv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSecondaryColorPointer
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glSecondaryColorPointer_INDEXED *packed_data = malloc(sizeof(glSecondaryColorPointer_INDEXED));
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSelectBuffer
void glSelectBuffer(GLsizei size, GLuint * buffer) {
    glSelectBuffer_INDEXED *packed_data = malloc(sizeof(glSelectBuffer_INDEXED));
    packed_data->args.a1 = size;
    packed_data->args.a2 = buffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glSeparableFilter2D
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column) {
    glSeparableFilter2D_INDEXED *packed_data = malloc(sizeof(glSeparableFilter2D_INDEXED));
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
#ifndef skip_glShadeModel
void glShadeModel(GLenum mode) {
    glShadeModel_INDEXED *packed_data = malloc(sizeof(glShadeModel_INDEXED));
    packed_data->args.a1 = mode;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glStencilFunc
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    glStencilFunc_INDEXED *packed_data = malloc(sizeof(glStencilFunc_INDEXED));
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    packed_data->args.a3 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glStencilMask
void glStencilMask(GLuint mask) {
    glStencilMask_INDEXED *packed_data = malloc(sizeof(glStencilMask_INDEXED));
    packed_data->args.a1 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glStencilOp
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    glStencilOp_INDEXED *packed_data = malloc(sizeof(glStencilOp_INDEXED));
    packed_data->args.a1 = fail;
    packed_data->args.a2 = zfail;
    packed_data->args.a3 = zpass;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord1d
void glTexCoord1d(GLdouble s) {
    glTexCoord1d_INDEXED *packed_data = malloc(sizeof(glTexCoord1d_INDEXED));
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord1dv
void glTexCoord1dv(const GLdouble * v) {
    glTexCoord1dv_INDEXED *packed_data = malloc(sizeof(glTexCoord1dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord1f
void glTexCoord1f(GLfloat s) {
    glTexCoord1f_INDEXED *packed_data = malloc(sizeof(glTexCoord1f_INDEXED));
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord1fv
void glTexCoord1fv(const GLfloat * v) {
    glTexCoord1fv_INDEXED *packed_data = malloc(sizeof(glTexCoord1fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord1i
void glTexCoord1i(GLint s) {
    glTexCoord1i_INDEXED *packed_data = malloc(sizeof(glTexCoord1i_INDEXED));
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord1iv
void glTexCoord1iv(const GLint * v) {
    glTexCoord1iv_INDEXED *packed_data = malloc(sizeof(glTexCoord1iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord1s
void glTexCoord1s(GLshort s) {
    glTexCoord1s_INDEXED *packed_data = malloc(sizeof(glTexCoord1s_INDEXED));
    packed_data->args.a1 = s;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord1sv
void glTexCoord1sv(const GLshort * v) {
    glTexCoord1sv_INDEXED *packed_data = malloc(sizeof(glTexCoord1sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord2d
void glTexCoord2d(GLdouble s, GLdouble t) {
    glTexCoord2d_INDEXED *packed_data = malloc(sizeof(glTexCoord2d_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord2dv
void glTexCoord2dv(const GLdouble * v) {
    glTexCoord2dv_INDEXED *packed_data = malloc(sizeof(glTexCoord2dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord2f
void glTexCoord2f(GLfloat s, GLfloat t) {
    glTexCoord2f_INDEXED *packed_data = malloc(sizeof(glTexCoord2f_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord2fv
void glTexCoord2fv(const GLfloat * v) {
    glTexCoord2fv_INDEXED *packed_data = malloc(sizeof(glTexCoord2fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord2i
void glTexCoord2i(GLint s, GLint t) {
    glTexCoord2i_INDEXED *packed_data = malloc(sizeof(glTexCoord2i_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord2iv
void glTexCoord2iv(const GLint * v) {
    glTexCoord2iv_INDEXED *packed_data = malloc(sizeof(glTexCoord2iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord2s
void glTexCoord2s(GLshort s, GLshort t) {
    glTexCoord2s_INDEXED *packed_data = malloc(sizeof(glTexCoord2s_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord2sv
void glTexCoord2sv(const GLshort * v) {
    glTexCoord2sv_INDEXED *packed_data = malloc(sizeof(glTexCoord2sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord3d
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    glTexCoord3d_INDEXED *packed_data = malloc(sizeof(glTexCoord3d_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord3dv
void glTexCoord3dv(const GLdouble * v) {
    glTexCoord3dv_INDEXED *packed_data = malloc(sizeof(glTexCoord3dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord3f
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    glTexCoord3f_INDEXED *packed_data = malloc(sizeof(glTexCoord3f_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord3fv
void glTexCoord3fv(const GLfloat * v) {
    glTexCoord3fv_INDEXED *packed_data = malloc(sizeof(glTexCoord3fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord3i
void glTexCoord3i(GLint s, GLint t, GLint r) {
    glTexCoord3i_INDEXED *packed_data = malloc(sizeof(glTexCoord3i_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord3iv
void glTexCoord3iv(const GLint * v) {
    glTexCoord3iv_INDEXED *packed_data = malloc(sizeof(glTexCoord3iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord3s
void glTexCoord3s(GLshort s, GLshort t, GLshort r) {
    glTexCoord3s_INDEXED *packed_data = malloc(sizeof(glTexCoord3s_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord3sv
void glTexCoord3sv(const GLshort * v) {
    glTexCoord3sv_INDEXED *packed_data = malloc(sizeof(glTexCoord3sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord4d
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    glTexCoord4d_INDEXED *packed_data = malloc(sizeof(glTexCoord4d_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord4dv
void glTexCoord4dv(const GLdouble * v) {
    glTexCoord4dv_INDEXED *packed_data = malloc(sizeof(glTexCoord4dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord4f
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    glTexCoord4f_INDEXED *packed_data = malloc(sizeof(glTexCoord4f_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord4fv
void glTexCoord4fv(const GLfloat * v) {
    glTexCoord4fv_INDEXED *packed_data = malloc(sizeof(glTexCoord4fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord4i
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    glTexCoord4i_INDEXED *packed_data = malloc(sizeof(glTexCoord4i_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord4iv
void glTexCoord4iv(const GLint * v) {
    glTexCoord4iv_INDEXED *packed_data = malloc(sizeof(glTexCoord4iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord4s
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    glTexCoord4s_INDEXED *packed_data = malloc(sizeof(glTexCoord4s_INDEXED));
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoord4sv
void glTexCoord4sv(const GLshort * v) {
    glTexCoord4sv_INDEXED *packed_data = malloc(sizeof(glTexCoord4sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexCoordPointer
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glTexCoordPointer_INDEXED *packed_data = malloc(sizeof(glTexCoordPointer_INDEXED));
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexEnvf
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    glTexEnvf_INDEXED *packed_data = malloc(sizeof(glTexEnvf_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexEnvfv
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    glTexEnvfv_INDEXED *packed_data = malloc(sizeof(glTexEnvfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexEnvi
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    glTexEnvi_INDEXED *packed_data = malloc(sizeof(glTexEnvi_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexEnviv
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    glTexEnviv_INDEXED *packed_data = malloc(sizeof(glTexEnviv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexGend
void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    glTexGend_INDEXED *packed_data = malloc(sizeof(glTexGend_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexGendv
void glTexGendv(GLenum coord, GLenum pname, const GLdouble * params) {
    glTexGendv_INDEXED *packed_data = malloc(sizeof(glTexGendv_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexGenf
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    glTexGenf_INDEXED *packed_data = malloc(sizeof(glTexGenf_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexGenfv
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    glTexGenfv_INDEXED *packed_data = malloc(sizeof(glTexGenfv_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexGeni
void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    glTexGeni_INDEXED *packed_data = malloc(sizeof(glTexGeni_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexGeniv
void glTexGeniv(GLenum coord, GLenum pname, const GLint * params) {
    glTexGeniv_INDEXED *packed_data = malloc(sizeof(glTexGeniv_INDEXED));
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexImage1D
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexImage1D_INDEXED *packed_data = malloc(sizeof(glTexImage1D_INDEXED));
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
#ifndef skip_glTexImage2D
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexImage2D_INDEXED *packed_data = malloc(sizeof(glTexImage2D_INDEXED));
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
#ifndef skip_glTexImage3D
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexImage3D_INDEXED *packed_data = malloc(sizeof(glTexImage3D_INDEXED));
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
#ifndef skip_glTexParameterf
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    glTexParameterf_INDEXED *packed_data = malloc(sizeof(glTexParameterf_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexParameterfv
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glTexParameterfv_INDEXED *packed_data = malloc(sizeof(glTexParameterfv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexParameteri
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    glTexParameteri_INDEXED *packed_data = malloc(sizeof(glTexParameteri_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexParameteriv
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glTexParameteriv_INDEXED *packed_data = malloc(sizeof(glTexParameteriv_INDEXED));
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTexSubImage1D
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexSubImage1D_INDEXED *packed_data = malloc(sizeof(glTexSubImage1D_INDEXED));
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
#ifndef skip_glTexSubImage2D
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexSubImage2D_INDEXED *packed_data = malloc(sizeof(glTexSubImage2D_INDEXED));
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
#ifndef skip_glTexSubImage3D
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels) {
    glTexSubImage3D_INDEXED *packed_data = malloc(sizeof(glTexSubImage3D_INDEXED));
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
#ifndef skip_glTranslated
void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    glTranslated_INDEXED *packed_data = malloc(sizeof(glTranslated_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glTranslatef
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    glTranslatef_INDEXED *packed_data = malloc(sizeof(glTranslatef_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glUnmapBuffer
GLboolean glUnmapBuffer(GLenum target) {
    glUnmapBuffer_INDEXED *packed_data = malloc(sizeof(glUnmapBuffer_INDEXED));
    packed_data->args.a1 = target;
    GLboolean ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glVertex2d
void glVertex2d(GLdouble x, GLdouble y) {
    glVertex2d_INDEXED *packed_data = malloc(sizeof(glVertex2d_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex2dv
void glVertex2dv(const GLdouble * v) {
    glVertex2dv_INDEXED *packed_data = malloc(sizeof(glVertex2dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex2f
void glVertex2f(GLfloat x, GLfloat y) {
    glVertex2f_INDEXED *packed_data = malloc(sizeof(glVertex2f_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex2fv
void glVertex2fv(const GLfloat * v) {
    glVertex2fv_INDEXED *packed_data = malloc(sizeof(glVertex2fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex2i
void glVertex2i(GLint x, GLint y) {
    glVertex2i_INDEXED *packed_data = malloc(sizeof(glVertex2i_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex2iv
void glVertex2iv(const GLint * v) {
    glVertex2iv_INDEXED *packed_data = malloc(sizeof(glVertex2iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex2s
void glVertex2s(GLshort x, GLshort y) {
    glVertex2s_INDEXED *packed_data = malloc(sizeof(glVertex2s_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex2sv
void glVertex2sv(const GLshort * v) {
    glVertex2sv_INDEXED *packed_data = malloc(sizeof(glVertex2sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex3d
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
    glVertex3d_INDEXED *packed_data = malloc(sizeof(glVertex3d_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex3dv
void glVertex3dv(const GLdouble * v) {
    glVertex3dv_INDEXED *packed_data = malloc(sizeof(glVertex3dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex3f
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    glVertex3f_INDEXED *packed_data = malloc(sizeof(glVertex3f_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex3fv
void glVertex3fv(const GLfloat * v) {
    glVertex3fv_INDEXED *packed_data = malloc(sizeof(glVertex3fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex3i
void glVertex3i(GLint x, GLint y, GLint z) {
    glVertex3i_INDEXED *packed_data = malloc(sizeof(glVertex3i_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex3iv
void glVertex3iv(const GLint * v) {
    glVertex3iv_INDEXED *packed_data = malloc(sizeof(glVertex3iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex3s
void glVertex3s(GLshort x, GLshort y, GLshort z) {
    glVertex3s_INDEXED *packed_data = malloc(sizeof(glVertex3s_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex3sv
void glVertex3sv(const GLshort * v) {
    glVertex3sv_INDEXED *packed_data = malloc(sizeof(glVertex3sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex4d
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glVertex4d_INDEXED *packed_data = malloc(sizeof(glVertex4d_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex4dv
void glVertex4dv(const GLdouble * v) {
    glVertex4dv_INDEXED *packed_data = malloc(sizeof(glVertex4dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex4f
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glVertex4f_INDEXED *packed_data = malloc(sizeof(glVertex4f_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex4fv
void glVertex4fv(const GLfloat * v) {
    glVertex4fv_INDEXED *packed_data = malloc(sizeof(glVertex4fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex4i
void glVertex4i(GLint x, GLint y, GLint z, GLint w) {
    glVertex4i_INDEXED *packed_data = malloc(sizeof(glVertex4i_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex4iv
void glVertex4iv(const GLint * v) {
    glVertex4iv_INDEXED *packed_data = malloc(sizeof(glVertex4iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex4s
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    glVertex4s_INDEXED *packed_data = malloc(sizeof(glVertex4s_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertex4sv
void glVertex4sv(const GLshort * v) {
    glVertex4sv_INDEXED *packed_data = malloc(sizeof(glVertex4sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glVertexPointer
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    glVertexPointer_INDEXED *packed_data = malloc(sizeof(glVertexPointer_INDEXED));
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glViewport
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    glViewport_INDEXED *packed_data = malloc(sizeof(glViewport_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos2d
void glWindowPos2d(GLdouble x, GLdouble y) {
    glWindowPos2d_INDEXED *packed_data = malloc(sizeof(glWindowPos2d_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos2dv
void glWindowPos2dv(const GLdouble * v) {
    glWindowPos2dv_INDEXED *packed_data = malloc(sizeof(glWindowPos2dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos2f
void glWindowPos2f(GLfloat x, GLfloat y) {
    glWindowPos2f_INDEXED *packed_data = malloc(sizeof(glWindowPos2f_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos2fv
void glWindowPos2fv(const GLfloat * v) {
    glWindowPos2fv_INDEXED *packed_data = malloc(sizeof(glWindowPos2fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos2i
void glWindowPos2i(GLint x, GLint y) {
    glWindowPos2i_INDEXED *packed_data = malloc(sizeof(glWindowPos2i_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos2iv
void glWindowPos2iv(const GLint * v) {
    glWindowPos2iv_INDEXED *packed_data = malloc(sizeof(glWindowPos2iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos2s
void glWindowPos2s(GLshort x, GLshort y) {
    glWindowPos2s_INDEXED *packed_data = malloc(sizeof(glWindowPos2s_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos2sv
void glWindowPos2sv(const GLshort * v) {
    glWindowPos2sv_INDEXED *packed_data = malloc(sizeof(glWindowPos2sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos3d
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    glWindowPos3d_INDEXED *packed_data = malloc(sizeof(glWindowPos3d_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos3dv
void glWindowPos3dv(const GLdouble * v) {
    glWindowPos3dv_INDEXED *packed_data = malloc(sizeof(glWindowPos3dv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos3f
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    glWindowPos3f_INDEXED *packed_data = malloc(sizeof(glWindowPos3f_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos3fv
void glWindowPos3fv(const GLfloat * v) {
    glWindowPos3fv_INDEXED *packed_data = malloc(sizeof(glWindowPos3fv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos3i
void glWindowPos3i(GLint x, GLint y, GLint z) {
    glWindowPos3i_INDEXED *packed_data = malloc(sizeof(glWindowPos3i_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos3iv
void glWindowPos3iv(const GLint * v) {
    glWindowPos3iv_INDEXED *packed_data = malloc(sizeof(glWindowPos3iv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos3s
void glWindowPos3s(GLshort x, GLshort y, GLshort z) {
    glWindowPos3s_INDEXED *packed_data = malloc(sizeof(glWindowPos3s_INDEXED));
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glWindowPos3sv
void glWindowPos3sv(const GLshort * v) {
    glWindowPos3sv_INDEXED *packed_data = malloc(sizeof(glWindowPos3sv_INDEXED));
    packed_data->args.a1 = v;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXBindHyperpipeSGIX
int glXBindHyperpipeSGIX(Display * dpy, int hpId) {
    glXBindHyperpipeSGIX_INDEXED *packed_data = malloc(sizeof(glXBindHyperpipeSGIX_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXBindSwapBarrierSGIX
void glXBindSwapBarrierSGIX(uint32_t window, uint32_t barrier) {
    glXBindSwapBarrierSGIX_INDEXED *packed_data = malloc(sizeof(glXBindSwapBarrierSGIX_INDEXED));
    packed_data->args.a1 = window;
    packed_data->args.a2 = barrier;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXChangeDrawableAttributes
void glXChangeDrawableAttributes(uint32_t drawable) {
    glXChangeDrawableAttributes_INDEXED *packed_data = malloc(sizeof(glXChangeDrawableAttributes_INDEXED));
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXChangeDrawableAttributesSGIX
void glXChangeDrawableAttributesSGIX(uint32_t drawable) {
    glXChangeDrawableAttributesSGIX_INDEXED *packed_data = malloc(sizeof(glXChangeDrawableAttributesSGIX_INDEXED));
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXChooseFBConfig
GLXFBConfig * glXChooseFBConfig(Display * dpy, int screen, const int * attrib_list, int * nelements) {
    glXChooseFBConfig_INDEXED *packed_data = malloc(sizeof(glXChooseFBConfig_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = attrib_list;
    packed_data->args.a4 = nelements;
    GLXFBConfig * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXChooseVisual
XVisualInfo * glXChooseVisual(Display * dpy, int screen, int * attribList) {
    glXChooseVisual_INDEXED *packed_data = malloc(sizeof(glXChooseVisual_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = attribList;
    XVisualInfo * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXClientInfo
void glXClientInfo() {
    glXClientInfo_INDEXED *packed_data = malloc(sizeof(glXClientInfo_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXCopyContext
void glXCopyContext(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask) {
    glXCopyContext_INDEXED *packed_data = malloc(sizeof(glXCopyContext_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = src;
    packed_data->args.a3 = dst;
    packed_data->args.a4 = mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXCreateContext
GLXContext glXCreateContext(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct) {
    glXCreateContext_INDEXED *packed_data = malloc(sizeof(glXCreateContext_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = vis;
    packed_data->args.a3 = shareList;
    packed_data->args.a4 = direct;
    GLXContext ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXCreateContextWithConfigSGIX
void glXCreateContextWithConfigSGIX(uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list) {
    glXCreateContextWithConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateContextWithConfigSGIX_INDEXED));
    packed_data->args.a1 = gc_id;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = config;
    packed_data->args.a4 = share_list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXCreateGLXPbufferSGIX
void glXCreateGLXPbufferSGIX(uint32_t config, uint32_t pbuffer) {
    glXCreateGLXPbufferSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPbufferSGIX_INDEXED));
    packed_data->args.a1 = config;
    packed_data->args.a2 = pbuffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXCreateGLXPixmap
GLXPixmap glXCreateGLXPixmap(Display * dpy, XVisualInfo * visual, Pixmap pixmap) {
    glXCreateGLXPixmap_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPixmap_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = visual;
    packed_data->args.a3 = pixmap;
    GLXPixmap ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXCreateGLXPixmapWithConfigSGIX
void glXCreateGLXPixmapWithConfigSGIX(uint32_t config, uint32_t pixmap, uint32_t glxpixmap) {
    glXCreateGLXPixmapWithConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateGLXPixmapWithConfigSGIX_INDEXED));
    packed_data->args.a1 = config;
    packed_data->args.a2 = pixmap;
    packed_data->args.a3 = glxpixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXCreateGLXVideoSourceSGIX
void glXCreateGLXVideoSourceSGIX(Display * dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node) {
    glXCreateGLXVideoSourceSGIX_INDEXED *packed_data = malloc(sizeof(glXCreateGLXVideoSourceSGIX_INDEXED));
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
#ifndef skip_glXCreateNewContext
GLXContext glXCreateNewContext(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct) {
    glXCreateNewContext_INDEXED *packed_data = malloc(sizeof(glXCreateNewContext_INDEXED));
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
#ifndef skip_glXCreatePbuffer
GLXPbuffer glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list) {
    glXCreatePbuffer_INDEXED *packed_data = malloc(sizeof(glXCreatePbuffer_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = attrib_list;
    GLXPbuffer ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXCreatePixmap
GLXPixmap glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list) {
    glXCreatePixmap_INDEXED *packed_data = malloc(sizeof(glXCreatePixmap_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = pixmap;
    packed_data->args.a4 = attrib_list;
    GLXPixmap ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXCreateWindow
GLXWindow glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list) {
    glXCreateWindow_INDEXED *packed_data = malloc(sizeof(glXCreateWindow_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = win;
    packed_data->args.a4 = attrib_list;
    GLXWindow ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXDestroyContext
void glXDestroyContext(Display * dpy, GLXContext ctx) {
    glXDestroyContext_INDEXED *packed_data = malloc(sizeof(glXDestroyContext_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXDestroyGLXPbufferSGIX
void glXDestroyGLXPbufferSGIX(uint32_t pbuffer) {
    glXDestroyGLXPbufferSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXPbufferSGIX_INDEXED));
    packed_data->args.a1 = pbuffer;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXDestroyGLXPixmap
void glXDestroyGLXPixmap(Display * dpy, GLXPixmap pixmap) {
    glXDestroyGLXPixmap_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXPixmap_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXDestroyGLXVideoSourceSGIX
void glXDestroyGLXVideoSourceSGIX(Display * dpy, uint32_t glxvideosource) {
    glXDestroyGLXVideoSourceSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyGLXVideoSourceSGIX_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = glxvideosource;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXDestroyHyperpipeConfigSGIX
int glXDestroyHyperpipeConfigSGIX(Display * dpy, int hpId) {
    glXDestroyHyperpipeConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXDestroyHyperpipeConfigSGIX_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXDestroyPbuffer
void glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf) {
    glXDestroyPbuffer_INDEXED *packed_data = malloc(sizeof(glXDestroyPbuffer_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pbuf;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXDestroyPixmap
void glXDestroyPixmap(Display * dpy, GLXPixmap pixmap) {
    glXDestroyPixmap_INDEXED *packed_data = malloc(sizeof(glXDestroyPixmap_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pixmap;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXDestroyWindow
void glXDestroyWindow(Display * dpy, GLXWindow win) {
    glXDestroyWindow_INDEXED *packed_data = malloc(sizeof(glXDestroyWindow_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = win;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXGetCurrentDisplay
Display * glXGetCurrentDisplay() {
    glXGetCurrentDisplay_INDEXED *packed_data = malloc(sizeof(glXGetCurrentDisplay_INDEXED));
    Display * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXGetCurrentReadDrawable
GLXDrawable glXGetCurrentReadDrawable() {
    glXGetCurrentReadDrawable_INDEXED *packed_data = malloc(sizeof(glXGetCurrentReadDrawable_INDEXED));
    GLXDrawable ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXGetDrawableAttributes
void glXGetDrawableAttributes(uint32_t drawable) {
    glXGetDrawableAttributes_INDEXED *packed_data = malloc(sizeof(glXGetDrawableAttributes_INDEXED));
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXGetDrawableAttributesSGIX
void glXGetDrawableAttributesSGIX(uint32_t drawable) {
    glXGetDrawableAttributesSGIX_INDEXED *packed_data = malloc(sizeof(glXGetDrawableAttributesSGIX_INDEXED));
    packed_data->args.a1 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXGetFBConfigAttrib
int glXGetFBConfigAttrib(Display * dpy, GLXFBConfig config, int attribute, int * value) {
    glXGetFBConfigAttrib_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigAttrib_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXGetFBConfigs
GLXFBConfig * glXGetFBConfigs(Display * dpy, int screen, int * nelements) {
    glXGetFBConfigs_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigs_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = nelements;
    GLXFBConfig * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXGetFBConfigsSGIX
void glXGetFBConfigsSGIX() {
    glXGetFBConfigsSGIX_INDEXED *packed_data = malloc(sizeof(glXGetFBConfigsSGIX_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXGetProcAddress
__GLXextFuncPtr glXGetProcAddress(const GLubyte * procName) {
    glXGetProcAddress_INDEXED *packed_data = malloc(sizeof(glXGetProcAddress_INDEXED));
    packed_data->args.a1 = procName;
    __GLXextFuncPtr ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXGetSelectedEvent
void glXGetSelectedEvent(Display * dpy, GLXDrawable draw, unsigned long * event_mask) {
    glXGetSelectedEvent_INDEXED *packed_data = malloc(sizeof(glXGetSelectedEvent_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = event_mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXGetVisualConfigs
void glXGetVisualConfigs() {
    glXGetVisualConfigs_INDEXED *packed_data = malloc(sizeof(glXGetVisualConfigs_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXGetVisualFromFBConfig
XVisualInfo * glXGetVisualFromFBConfig(Display * dpy, GLXFBConfig config) {
    glXGetVisualFromFBConfig_INDEXED *packed_data = malloc(sizeof(glXGetVisualFromFBConfig_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    XVisualInfo * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXHyperpipeAttribSGIX
int glXHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList) {
    glXHyperpipeAttribSGIX_INDEXED *packed_data = malloc(sizeof(glXHyperpipeAttribSGIX_INDEXED));
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
#ifndef skip_glXHyperpipeConfigSGIX
int glXHyperpipeConfigSGIX(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int * hpId) {
    glXHyperpipeConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXHyperpipeConfigSGIX_INDEXED));
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
#ifndef skip_glXIsDirect
Bool glXIsDirect(Display * dpy, GLXContext ctx) {
    glXIsDirect_INDEXED *packed_data = malloc(sizeof(glXIsDirect_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXJoinSwapGroupSGIX
void glXJoinSwapGroupSGIX(uint32_t window, uint32_t group) {
    glXJoinSwapGroupSGIX_INDEXED *packed_data = malloc(sizeof(glXJoinSwapGroupSGIX_INDEXED));
    packed_data->args.a1 = window;
    packed_data->args.a2 = group;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXMakeContextCurrent
Bool glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
    glXMakeContextCurrent_INDEXED *packed_data = malloc(sizeof(glXMakeContextCurrent_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = read;
    packed_data->args.a4 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXMakeCurrent
Bool glXMakeCurrent(Display * dpy, GLXDrawable drawable, GLXContext ctx) {
    glXMakeCurrent_INDEXED *packed_data = malloc(sizeof(glXMakeCurrent_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = drawable;
    packed_data->args.a3 = ctx;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXMakeCurrentReadSGI
void glXMakeCurrentReadSGI(uint32_t drawable, uint32_t readdrawable, uint32_t context) {
    glXMakeCurrentReadSGI_INDEXED *packed_data = malloc(sizeof(glXMakeCurrentReadSGI_INDEXED));
    packed_data->args.a1 = drawable;
    packed_data->args.a2 = readdrawable;
    packed_data->args.a3 = context;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXQueryContext
int glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value) {
    glXQueryContext_INDEXED *packed_data = malloc(sizeof(glXQueryContext_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXQueryContextInfoEXT
void glXQueryContextInfoEXT() {
    glXQueryContextInfoEXT_INDEXED *packed_data = malloc(sizeof(glXQueryContextInfoEXT_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXQueryDrawable
void glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value) {
    glXQueryDrawable_INDEXED *packed_data = malloc(sizeof(glXQueryDrawable_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXQueryExtensionsString
const char * glXQueryExtensionsString(Display * dpy, int screen) {
    glXQueryExtensionsString_INDEXED *packed_data = malloc(sizeof(glXQueryExtensionsString_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXQueryHyperpipeAttribSGIX
int glXQueryHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * returnAttribList) {
    glXQueryHyperpipeAttribSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeAttribSGIX_INDEXED));
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
#ifndef skip_glXQueryHyperpipeBestAttribSGIX
int glXQueryHyperpipeBestAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList, void * returnAttribList) {
    glXQueryHyperpipeBestAttribSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeBestAttribSGIX_INDEXED));
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
#ifndef skip_glXQueryHyperpipeConfigSGIX
GLXHyperpipeConfigSGIX * glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes) {
    glXQueryHyperpipeConfigSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeConfigSGIX_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    packed_data->args.a3 = npipes;
    GLXHyperpipeConfigSGIX * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXQueryHyperpipeNetworkSGIX
GLXHyperpipeNetworkSGIX * glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes) {
    glXQueryHyperpipeNetworkSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryHyperpipeNetworkSGIX_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = npipes;
    GLXHyperpipeNetworkSGIX * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXQueryMaxSwapBarriersSGIX
void glXQueryMaxSwapBarriersSGIX() {
    glXQueryMaxSwapBarriersSGIX_INDEXED *packed_data = malloc(sizeof(glXQueryMaxSwapBarriersSGIX_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXQueryServerString
const char * glXQueryServerString(Display * dpy, int screen, int name) {
    glXQueryServerString_INDEXED *packed_data = malloc(sizeof(glXQueryServerString_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = name;
    const char * ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXQueryVersion
Bool glXQueryVersion(Display * dpy, int * maj, int * min) {
    glXQueryVersion_INDEXED *packed_data = malloc(sizeof(glXQueryVersion_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = maj;
    packed_data->args.a3 = min;
    Bool ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
    return ret;
}
#endif
#ifndef skip_glXRender
void glXRender() {
    glXRender_INDEXED *packed_data = malloc(sizeof(glXRender_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXRenderLarge
void glXRenderLarge() {
    glXRenderLarge_INDEXED *packed_data = malloc(sizeof(glXRenderLarge_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXSelectEvent
void glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask) {
    glXSelectEvent_INDEXED *packed_data = malloc(sizeof(glXSelectEvent_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = event_mask;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXSwapBuffers
void glXSwapBuffers(Display * dpy, GLXDrawable drawable) {
    glXSwapBuffers_INDEXED *packed_data = malloc(sizeof(glXSwapBuffers_INDEXED));
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = drawable;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXSwapIntervalSGI
void glXSwapIntervalSGI() {
    glXSwapIntervalSGI_INDEXED *packed_data = malloc(sizeof(glXSwapIntervalSGI_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXUseXFont
void glXUseXFont(Font font, int first, int count, int list) {
    glXUseXFont_INDEXED *packed_data = malloc(sizeof(glXUseXFont_INDEXED));
    packed_data->args.a1 = font;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    packed_data->args.a4 = list;
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXVendorPrivate
void glXVendorPrivate() {
    glXVendorPrivate_INDEXED *packed_data = malloc(sizeof(glXVendorPrivate_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXVendorPrivateWithReply
void glXVendorPrivateWithReply() {
    glXVendorPrivateWithReply_INDEXED *packed_data = malloc(sizeof(glXVendorPrivateWithReply_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXWaitGL
void glXWaitGL() {
    glXWaitGL_INDEXED *packed_data = malloc(sizeof(glXWaitGL_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
#ifndef skip_glXWaitX
void glXWaitX() {
    glXWaitX_INDEXED *packed_data = malloc(sizeof(glXWaitX_INDEXED));
    int ret;
    syscall(SYS_proxy, (void *)packed_data, &ret);
}
#endif
