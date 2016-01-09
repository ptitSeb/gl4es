#ifndef USE_ES2
#include "gles.h"
#ifndef skip_glActiveTexture
void glshim_glActiveTexture(GLenum texture) {
    LOAD_GLES(glActiveTexture);
#ifndef direct_glActiveTexture
    PUSH_IF_COMPILING(glActiveTexture)
#endif
    gles_glActiveTexture(texture);
}
void glActiveTexture(GLenum texture) __attribute__((alias("glshim_glActiveTexture")));
#endif
#ifndef skip_glAlphaFunc
void glshim_glAlphaFunc(GLenum func, GLclampf ref) {
    LOAD_GLES(glAlphaFunc);
#ifndef direct_glAlphaFunc
    PUSH_IF_COMPILING(glAlphaFunc)
#endif
    gles_glAlphaFunc(func, ref);
}
void glAlphaFunc(GLenum func, GLclampf ref) __attribute__((alias("glshim_glAlphaFunc")));
#endif
#ifndef skip_glAlphaFuncx
void glshim_glAlphaFuncx(GLenum func, GLclampx ref) {
    LOAD_GLES(glAlphaFuncx);
#ifndef direct_glAlphaFuncx
    PUSH_IF_COMPILING(glAlphaFuncx)
#endif
    gles_glAlphaFuncx(func, ref);
}
void glAlphaFuncx(GLenum func, GLclampx ref) __attribute__((alias("glshim_glAlphaFuncx")));
#endif
#ifndef skip_glBindBuffer
void glshim_glBindBuffer(GLenum target, GLuint buffer) {
    LOAD_GLES(glBindBuffer);
#ifndef direct_glBindBuffer
    PUSH_IF_COMPILING(glBindBuffer)
#endif
    gles_glBindBuffer(target, buffer);
}
void glBindBuffer(GLenum target, GLuint buffer) __attribute__((alias("glshim_glBindBuffer")));
#endif
#ifndef skip_glBindTexture
void glshim_glBindTexture(GLenum target, GLuint texture) {
    LOAD_GLES(glBindTexture);
#ifndef direct_glBindTexture
    PUSH_IF_COMPILING(glBindTexture)
#endif
    gles_glBindTexture(target, texture);
}
void glBindTexture(GLenum target, GLuint texture) __attribute__((alias("glshim_glBindTexture")));
#endif
#ifndef skip_glBlendFunc
void glshim_glBlendFunc(GLenum sfactor, GLenum dfactor) {
    LOAD_GLES(glBlendFunc);
#ifndef direct_glBlendFunc
    PUSH_IF_COMPILING(glBlendFunc)
#endif
    gles_glBlendFunc(sfactor, dfactor);
}
void glBlendFunc(GLenum sfactor, GLenum dfactor) __attribute__((alias("glshim_glBlendFunc")));
#endif
#ifndef skip_glBufferData
void glshim_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    LOAD_GLES(glBufferData);
#ifndef direct_glBufferData
    PUSH_IF_COMPILING(glBufferData)
#endif
    gles_glBufferData(target, size, data, usage);
}
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) __attribute__((alias("glshim_glBufferData")));
#endif
#ifndef skip_glBufferSubData
void glshim_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    LOAD_GLES(glBufferSubData);
#ifndef direct_glBufferSubData
    PUSH_IF_COMPILING(glBufferSubData)
#endif
    gles_glBufferSubData(target, offset, size, data);
}
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) __attribute__((alias("glshim_glBufferSubData")));
#endif
#ifndef skip_glClear
void glshim_glClear(GLbitfield mask) {
    LOAD_GLES(glClear);
#ifndef direct_glClear
    PUSH_IF_COMPILING(glClear)
#endif
    gles_glClear(mask);
}
void glClear(GLbitfield mask) __attribute__((alias("glshim_glClear")));
#endif
#ifndef skip_glClearColor
void glshim_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    LOAD_GLES(glClearColor);
#ifndef direct_glClearColor
    PUSH_IF_COMPILING(glClearColor)
#endif
    gles_glClearColor(red, green, blue, alpha);
}
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) __attribute__((alias("glshim_glClearColor")));
#endif
#ifndef skip_glClearColorx
void glshim_glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) {
    LOAD_GLES(glClearColorx);
#ifndef direct_glClearColorx
    PUSH_IF_COMPILING(glClearColorx)
#endif
    gles_glClearColorx(red, green, blue, alpha);
}
void glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) __attribute__((alias("glshim_glClearColorx")));
#endif
#ifndef skip_glClearDepthf
void glshim_glClearDepthf(GLclampf depth) {
    LOAD_GLES(glClearDepthf);
#ifndef direct_glClearDepthf
    PUSH_IF_COMPILING(glClearDepthf)
#endif
    gles_glClearDepthf(depth);
}
void glClearDepthf(GLclampf depth) __attribute__((alias("glshim_glClearDepthf")));
#endif
#ifndef skip_glClearDepthx
void glshim_glClearDepthx(GLclampx depth) {
    LOAD_GLES(glClearDepthx);
#ifndef direct_glClearDepthx
    PUSH_IF_COMPILING(glClearDepthx)
#endif
    gles_glClearDepthx(depth);
}
void glClearDepthx(GLclampx depth) __attribute__((alias("glshim_glClearDepthx")));
#endif
#ifndef skip_glClearStencil
void glshim_glClearStencil(GLint s) {
    LOAD_GLES(glClearStencil);
#ifndef direct_glClearStencil
    PUSH_IF_COMPILING(glClearStencil)
#endif
    gles_glClearStencil(s);
}
void glClearStencil(GLint s) __attribute__((alias("glshim_glClearStencil")));
#endif
#ifndef skip_glClientActiveTexture
void glshim_glClientActiveTexture(GLenum texture) {
    LOAD_GLES(glClientActiveTexture);
#ifndef direct_glClientActiveTexture
    PUSH_IF_COMPILING(glClientActiveTexture)
#endif
    gles_glClientActiveTexture(texture);
}
void glClientActiveTexture(GLenum texture) __attribute__((alias("glshim_glClientActiveTexture")));
#endif
#ifndef skip_glClipPlanef
void glshim_glClipPlanef(GLenum plane, const GLfloat * equation) {
    LOAD_GLES(glClipPlanef);
#ifndef direct_glClipPlanef
    PUSH_IF_COMPILING(glClipPlanef)
#endif
    gles_glClipPlanef(plane, equation);
}
void glClipPlanef(GLenum plane, const GLfloat * equation) __attribute__((alias("glshim_glClipPlanef")));
#endif
#ifndef skip_glClipPlanex
void glshim_glClipPlanex(GLenum plane, const GLfixed * equation) {
    LOAD_GLES(glClipPlanex);
#ifndef direct_glClipPlanex
    PUSH_IF_COMPILING(glClipPlanex)
#endif
    gles_glClipPlanex(plane, equation);
}
void glClipPlanex(GLenum plane, const GLfixed * equation) __attribute__((alias("glshim_glClipPlanex")));
#endif
#ifndef skip_glColor4f
void glshim_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    LOAD_GLES(glColor4f);
#ifndef direct_glColor4f
    PUSH_IF_COMPILING(glColor4f)
#endif
    gles_glColor4f(red, green, blue, alpha);
}
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) __attribute__((alias("glshim_glColor4f")));
#endif
#ifndef skip_glColor4ub
void glshim_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    LOAD_GLES(glColor4ub);
#ifndef direct_glColor4ub
    PUSH_IF_COMPILING(glColor4ub)
#endif
    gles_glColor4ub(red, green, blue, alpha);
}
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) __attribute__((alias("glshim_glColor4ub")));
#endif
#ifndef skip_glColor4x
void glshim_glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    LOAD_GLES(glColor4x);
#ifndef direct_glColor4x
    PUSH_IF_COMPILING(glColor4x)
#endif
    gles_glColor4x(red, green, blue, alpha);
}
void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) __attribute__((alias("glshim_glColor4x")));
#endif
#ifndef skip_glColorMask
void glshim_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    LOAD_GLES(glColorMask);
#ifndef direct_glColorMask
    PUSH_IF_COMPILING(glColorMask)
#endif
    gles_glColorMask(red, green, blue, alpha);
}
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) __attribute__((alias("glshim_glColorMask")));
#endif
#ifndef skip_glColorPointer
void glshim_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glColorPointer);
#ifndef direct_glColorPointer
    PUSH_IF_COMPILING(glColorPointer)
#endif
    gles_glColorPointer(size, type, stride, pointer);
}
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) __attribute__((alias("glshim_glColorPointer")));
#endif
#ifndef skip_glCompressedTexImage2D
void glshim_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    LOAD_GLES(glCompressedTexImage2D);
#ifndef direct_glCompressedTexImage2D
    PUSH_IF_COMPILING(glCompressedTexImage2D)
#endif
    gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) __attribute__((alias("glshim_glCompressedTexImage2D")));
#endif
#ifndef skip_glCompressedTexSubImage2D
void glshim_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    LOAD_GLES(glCompressedTexSubImage2D);
#ifndef direct_glCompressedTexSubImage2D
    PUSH_IF_COMPILING(glCompressedTexSubImage2D)
#endif
    gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) __attribute__((alias("glshim_glCompressedTexSubImage2D")));
#endif
#ifndef skip_glCopyTexImage2D
void glshim_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    LOAD_GLES(glCopyTexImage2D);
#ifndef direct_glCopyTexImage2D
    PUSH_IF_COMPILING(glCopyTexImage2D)
#endif
    gles_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) __attribute__((alias("glshim_glCopyTexImage2D")));
#endif
#ifndef skip_glCopyTexSubImage2D
void glshim_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glCopyTexSubImage2D);
#ifndef direct_glCopyTexSubImage2D
    PUSH_IF_COMPILING(glCopyTexSubImage2D)
#endif
    gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyTexSubImage2D")));
#endif
#ifndef skip_glCullFace
void glshim_glCullFace(GLenum mode) {
    LOAD_GLES(glCullFace);
#ifndef direct_glCullFace
    PUSH_IF_COMPILING(glCullFace)
#endif
    gles_glCullFace(mode);
}
void glCullFace(GLenum mode) __attribute__((alias("glshim_glCullFace")));
#endif
#ifndef skip_glDeleteBuffers
void glshim_glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    LOAD_GLES(glDeleteBuffers);
#ifndef direct_glDeleteBuffers
    PUSH_IF_COMPILING(glDeleteBuffers)
#endif
    gles_glDeleteBuffers(n, buffers);
}
void glDeleteBuffers(GLsizei n, const GLuint * buffers) __attribute__((alias("glshim_glDeleteBuffers")));
#endif
#ifndef skip_glDeleteTextures
void glshim_glDeleteTextures(GLsizei n, const GLuint * textures) {
    LOAD_GLES(glDeleteTextures);
#ifndef direct_glDeleteTextures
    PUSH_IF_COMPILING(glDeleteTextures)
#endif
    gles_glDeleteTextures(n, textures);
}
void glDeleteTextures(GLsizei n, const GLuint * textures) __attribute__((alias("glshim_glDeleteTextures")));
#endif
#ifndef skip_glDepthFunc
void glshim_glDepthFunc(GLenum func) {
    LOAD_GLES(glDepthFunc);
#ifndef direct_glDepthFunc
    PUSH_IF_COMPILING(glDepthFunc)
#endif
    gles_glDepthFunc(func);
}
void glDepthFunc(GLenum func) __attribute__((alias("glshim_glDepthFunc")));
#endif
#ifndef skip_glDepthMask
void glshim_glDepthMask(GLboolean flag) {
    LOAD_GLES(glDepthMask);
#ifndef direct_glDepthMask
    PUSH_IF_COMPILING(glDepthMask)
#endif
    gles_glDepthMask(flag);
}
void glDepthMask(GLboolean flag) __attribute__((alias("glshim_glDepthMask")));
#endif
#ifndef skip_glDepthRangef
void glshim_glDepthRangef(GLclampf near, GLclampf far) {
    LOAD_GLES(glDepthRangef);
#ifndef direct_glDepthRangef
    PUSH_IF_COMPILING(glDepthRangef)
#endif
    gles_glDepthRangef(near, far);
}
void glDepthRangef(GLclampf near, GLclampf far) __attribute__((alias("glshim_glDepthRangef")));
#endif
#ifndef skip_glDepthRangex
void glshim_glDepthRangex(GLclampx near, GLclampx far) {
    LOAD_GLES(glDepthRangex);
#ifndef direct_glDepthRangex
    PUSH_IF_COMPILING(glDepthRangex)
#endif
    gles_glDepthRangex(near, far);
}
void glDepthRangex(GLclampx near, GLclampx far) __attribute__((alias("glshim_glDepthRangex")));
#endif
#ifndef skip_glDisable
void glshim_glDisable(GLenum cap) {
    LOAD_GLES(glDisable);
#ifndef direct_glDisable
    PUSH_IF_COMPILING(glDisable)
#endif
    gles_glDisable(cap);
}
void glDisable(GLenum cap) __attribute__((alias("glshim_glDisable")));
#endif
#ifndef skip_glDisableClientState
void glshim_glDisableClientState(GLenum array) {
    LOAD_GLES(glDisableClientState);
#ifndef direct_glDisableClientState
    PUSH_IF_COMPILING(glDisableClientState)
#endif
    gles_glDisableClientState(array);
}
void glDisableClientState(GLenum array) __attribute__((alias("glshim_glDisableClientState")));
#endif
#ifndef skip_glDrawArrays
void glshim_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    LOAD_GLES(glDrawArrays);
#ifndef direct_glDrawArrays
    PUSH_IF_COMPILING(glDrawArrays)
#endif
    gles_glDrawArrays(mode, first, count);
}
void glDrawArrays(GLenum mode, GLint first, GLsizei count) __attribute__((alias("glshim_glDrawArrays")));
#endif
#ifndef skip_glDrawElements
void glshim_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    LOAD_GLES(glDrawElements);
#ifndef direct_glDrawElements
    PUSH_IF_COMPILING(glDrawElements)
#endif
    gles_glDrawElements(mode, count, type, indices);
}
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) __attribute__((alias("glshim_glDrawElements")));
#endif
#ifndef skip_glEnable
void glshim_glEnable(GLenum cap) {
    LOAD_GLES(glEnable);
#ifndef direct_glEnable
    PUSH_IF_COMPILING(glEnable)
#endif
    gles_glEnable(cap);
}
void glEnable(GLenum cap) __attribute__((alias("glshim_glEnable")));
#endif
#ifndef skip_glEnableClientState
void glshim_glEnableClientState(GLenum array) {
    LOAD_GLES(glEnableClientState);
#ifndef direct_glEnableClientState
    PUSH_IF_COMPILING(glEnableClientState)
#endif
    gles_glEnableClientState(array);
}
void glEnableClientState(GLenum array) __attribute__((alias("glshim_glEnableClientState")));
#endif
#ifndef skip_glFinish
void glshim_glFinish() {
    LOAD_GLES(glFinish);
#ifndef direct_glFinish
    PUSH_IF_COMPILING(glFinish)
#endif
    gles_glFinish();
}
void glFinish() __attribute__((alias("glshim_glFinish")));
#endif
#ifndef skip_glFlush
void glshim_glFlush() {
    LOAD_GLES(glFlush);
#ifndef direct_glFlush
    PUSH_IF_COMPILING(glFlush)
#endif
    gles_glFlush();
}
void glFlush() __attribute__((alias("glshim_glFlush")));
#endif
#ifndef skip_glFogf
void glshim_glFogf(GLenum pname, GLfloat param) {
    LOAD_GLES(glFogf);
#ifndef direct_glFogf
    PUSH_IF_COMPILING(glFogf)
#endif
    gles_glFogf(pname, param);
}
void glFogf(GLenum pname, GLfloat param) __attribute__((alias("glshim_glFogf")));
#endif
#ifndef skip_glFogfv
void glshim_glFogfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glFogfv);
#ifndef direct_glFogfv
    PUSH_IF_COMPILING(glFogfv)
#endif
    gles_glFogfv(pname, params);
}
void glFogfv(GLenum pname, const GLfloat * params) __attribute__((alias("glshim_glFogfv")));
#endif
#ifndef skip_glFogx
void glshim_glFogx(GLenum pname, GLfixed param) {
    LOAD_GLES(glFogx);
#ifndef direct_glFogx
    PUSH_IF_COMPILING(glFogx)
#endif
    gles_glFogx(pname, param);
}
void glFogx(GLenum pname, GLfixed param) __attribute__((alias("glshim_glFogx")));
#endif
#ifndef skip_glFogxv
void glshim_glFogxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glFogxv);
#ifndef direct_glFogxv
    PUSH_IF_COMPILING(glFogxv)
#endif
    gles_glFogxv(pname, params);
}
void glFogxv(GLenum pname, const GLfixed * params) __attribute__((alias("glshim_glFogxv")));
#endif
#ifndef skip_glFrontFace
void glshim_glFrontFace(GLenum mode) {
    LOAD_GLES(glFrontFace);
#ifndef direct_glFrontFace
    PUSH_IF_COMPILING(glFrontFace)
#endif
    gles_glFrontFace(mode);
}
void glFrontFace(GLenum mode) __attribute__((alias("glshim_glFrontFace")));
#endif
#ifndef skip_glFrustumf
void glshim_glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    LOAD_GLES(glFrustumf);
#ifndef direct_glFrustumf
    PUSH_IF_COMPILING(glFrustumf)
#endif
    gles_glFrustumf(left, right, bottom, top, near, far);
}
void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) __attribute__((alias("glshim_glFrustumf")));
#endif
#ifndef skip_glFrustumx
void glshim_glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    LOAD_GLES(glFrustumx);
#ifndef direct_glFrustumx
    PUSH_IF_COMPILING(glFrustumx)
#endif
    gles_glFrustumx(left, right, bottom, top, near, far);
}
void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) __attribute__((alias("glshim_glFrustumx")));
#endif
#ifndef skip_glGenBuffers
void glshim_glGenBuffers(GLsizei n, GLuint * buffers) {
    LOAD_GLES(glGenBuffers);
#ifndef direct_glGenBuffers
    PUSH_IF_COMPILING(glGenBuffers)
#endif
    gles_glGenBuffers(n, buffers);
}
void glGenBuffers(GLsizei n, GLuint * buffers) __attribute__((alias("glshim_glGenBuffers")));
#endif
#ifndef skip_glGenTextures
void glshim_glGenTextures(GLsizei n, GLuint * textures) {
    LOAD_GLES(glGenTextures);
#ifndef direct_glGenTextures
    PUSH_IF_COMPILING(glGenTextures)
#endif
    gles_glGenTextures(n, textures);
}
void glGenTextures(GLsizei n, GLuint * textures) __attribute__((alias("glshim_glGenTextures")));
#endif
#ifndef skip_glGetBooleanv
void glshim_glGetBooleanv(GLenum pname, GLboolean * params) {
    LOAD_GLES(glGetBooleanv);
#ifndef direct_glGetBooleanv
    PUSH_IF_COMPILING(glGetBooleanv)
#endif
    gles_glGetBooleanv(pname, params);
}
void glGetBooleanv(GLenum pname, GLboolean * params) __attribute__((alias("glshim_glGetBooleanv")));
#endif
#ifndef skip_glGetBufferParameteriv
void glshim_glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetBufferParameteriv);
#ifndef direct_glGetBufferParameteriv
    PUSH_IF_COMPILING(glGetBufferParameteriv)
#endif
    gles_glGetBufferParameteriv(target, pname, params);
}
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetBufferParameteriv")));
#endif
#ifndef skip_glGetClipPlanef
void glshim_glGetClipPlanef(GLenum plane, GLfloat * equation) {
    LOAD_GLES(glGetClipPlanef);
#ifndef direct_glGetClipPlanef
    PUSH_IF_COMPILING(glGetClipPlanef)
#endif
    gles_glGetClipPlanef(plane, equation);
}
void glGetClipPlanef(GLenum plane, GLfloat * equation) __attribute__((alias("glshim_glGetClipPlanef")));
#endif
#ifndef skip_glGetClipPlanex
void glshim_glGetClipPlanex(GLenum plane, GLfixed * equation) {
    LOAD_GLES(glGetClipPlanex);
#ifndef direct_glGetClipPlanex
    PUSH_IF_COMPILING(glGetClipPlanex)
#endif
    gles_glGetClipPlanex(plane, equation);
}
void glGetClipPlanex(GLenum plane, GLfixed * equation) __attribute__((alias("glshim_glGetClipPlanex")));
#endif
#ifndef skip_glGetError
GLenum glshim_glGetError() {
    LOAD_GLES(glGetError);
#ifndef direct_glGetError
    PUSH_IF_COMPILING(glGetError)
#endif
    return gles_glGetError();
}
GLenum glGetError() __attribute__((alias("glshim_glGetError")));
#endif
#ifndef skip_glGetFixedv
void glshim_glGetFixedv(GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetFixedv);
#ifndef direct_glGetFixedv
    PUSH_IF_COMPILING(glGetFixedv)
#endif
    gles_glGetFixedv(pname, params);
}
void glGetFixedv(GLenum pname, GLfixed * params) __attribute__((alias("glshim_glGetFixedv")));
#endif
#ifndef skip_glGetFloatv
void glshim_glGetFloatv(GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetFloatv);
#ifndef direct_glGetFloatv
    PUSH_IF_COMPILING(glGetFloatv)
#endif
    gles_glGetFloatv(pname, params);
}
void glGetFloatv(GLenum pname, GLfloat * params) __attribute__((alias("glshim_glGetFloatv")));
#endif
#ifndef skip_glGetIntegerv
void glshim_glGetIntegerv(GLenum pname, GLint * params) {
    LOAD_GLES(glGetIntegerv);
#ifndef direct_glGetIntegerv
    PUSH_IF_COMPILING(glGetIntegerv)
#endif
    gles_glGetIntegerv(pname, params);
}
void glGetIntegerv(GLenum pname, GLint * params) __attribute__((alias("glshim_glGetIntegerv")));
#endif
#ifndef skip_glGetLightfv
void glshim_glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetLightfv);
#ifndef direct_glGetLightfv
    PUSH_IF_COMPILING(glGetLightfv)
#endif
    gles_glGetLightfv(light, pname, params);
}
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) __attribute__((alias("glshim_glGetLightfv")));
#endif
#ifndef skip_glGetLightxv
void glshim_glGetLightxv(GLenum light, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetLightxv);
#ifndef direct_glGetLightxv
    PUSH_IF_COMPILING(glGetLightxv)
#endif
    gles_glGetLightxv(light, pname, params);
}
void glGetLightxv(GLenum light, GLenum pname, GLfixed * params) __attribute__((alias("glshim_glGetLightxv")));
#endif
#ifndef skip_glGetMaterialfv
void glshim_glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetMaterialfv);
#ifndef direct_glGetMaterialfv
    PUSH_IF_COMPILING(glGetMaterialfv)
#endif
    gles_glGetMaterialfv(face, pname, params);
}
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) __attribute__((alias("glshim_glGetMaterialfv")));
#endif
#ifndef skip_glGetMaterialxv
void glshim_glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetMaterialxv);
#ifndef direct_glGetMaterialxv
    PUSH_IF_COMPILING(glGetMaterialxv)
#endif
    gles_glGetMaterialxv(face, pname, params);
}
void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) __attribute__((alias("glshim_glGetMaterialxv")));
#endif
#ifndef skip_glGetPointerv
void glshim_glGetPointerv(GLenum pname, GLvoid ** params) {
    LOAD_GLES(glGetPointerv);
#ifndef direct_glGetPointerv
    PUSH_IF_COMPILING(glGetPointerv)
#endif
    gles_glGetPointerv(pname, params);
}
void glGetPointerv(GLenum pname, GLvoid ** params) __attribute__((alias("glshim_glGetPointerv")));
#endif
#ifndef skip_glGetString
const GLubyte * glshim_glGetString(GLenum name) {
    LOAD_GLES(glGetString);
#ifndef direct_glGetString
    PUSH_IF_COMPILING(glGetString)
#endif
    return gles_glGetString(name);
}
const GLubyte * glGetString(GLenum name) __attribute__((alias("glshim_glGetString")));
#endif
#ifndef skip_glGetTexEnvfv
void glshim_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetTexEnvfv);
#ifndef direct_glGetTexEnvfv
    PUSH_IF_COMPILING(glGetTexEnvfv)
#endif
    gles_glGetTexEnvfv(target, pname, params);
}
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) __attribute__((alias("glshim_glGetTexEnvfv")));
#endif
#ifndef skip_glGetTexEnviv
void glshim_glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetTexEnviv);
#ifndef direct_glGetTexEnviv
    PUSH_IF_COMPILING(glGetTexEnviv)
#endif
    gles_glGetTexEnviv(target, pname, params);
}
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetTexEnviv")));
#endif
#ifndef skip_glGetTexEnvxv
void glshim_glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetTexEnvxv);
#ifndef direct_glGetTexEnvxv
    PUSH_IF_COMPILING(glGetTexEnvxv)
#endif
    gles_glGetTexEnvxv(target, pname, params);
}
void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) __attribute__((alias("glshim_glGetTexEnvxv")));
#endif
#ifndef skip_glGetTexParameterfv
void glshim_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetTexParameterfv);
#ifndef direct_glGetTexParameterfv
    PUSH_IF_COMPILING(glGetTexParameterfv)
#endif
    gles_glGetTexParameterfv(target, pname, params);
}
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) __attribute__((alias("glshim_glGetTexParameterfv")));
#endif
#ifndef skip_glGetTexParameteriv
void glshim_glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetTexParameteriv);
#ifndef direct_glGetTexParameteriv
    PUSH_IF_COMPILING(glGetTexParameteriv)
#endif
    gles_glGetTexParameteriv(target, pname, params);
}
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetTexParameteriv")));
#endif
#ifndef skip_glGetTexParameterxv
void glshim_glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetTexParameterxv);
#ifndef direct_glGetTexParameterxv
    PUSH_IF_COMPILING(glGetTexParameterxv)
#endif
    gles_glGetTexParameterxv(target, pname, params);
}
void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) __attribute__((alias("glshim_glGetTexParameterxv")));
#endif
#ifndef skip_glHint
void glshim_glHint(GLenum target, GLenum mode) {
    LOAD_GLES(glHint);
#ifndef direct_glHint
    PUSH_IF_COMPILING(glHint)
#endif
    gles_glHint(target, mode);
}
void glHint(GLenum target, GLenum mode) __attribute__((alias("glshim_glHint")));
#endif
#ifndef skip_glIsBuffer
GLboolean glshim_glIsBuffer(GLuint buffer) {
    LOAD_GLES(glIsBuffer);
#ifndef direct_glIsBuffer
    PUSH_IF_COMPILING(glIsBuffer)
#endif
    return gles_glIsBuffer(buffer);
}
GLboolean glIsBuffer(GLuint buffer) __attribute__((alias("glshim_glIsBuffer")));
#endif
#ifndef skip_glIsEnabled
GLboolean glshim_glIsEnabled(GLenum cap) {
    LOAD_GLES(glIsEnabled);
#ifndef direct_glIsEnabled
    PUSH_IF_COMPILING(glIsEnabled)
#endif
    return gles_glIsEnabled(cap);
}
GLboolean glIsEnabled(GLenum cap) __attribute__((alias("glshim_glIsEnabled")));
#endif
#ifndef skip_glIsTexture
GLboolean glshim_glIsTexture(GLuint texture) {
    LOAD_GLES(glIsTexture);
#ifndef direct_glIsTexture
    PUSH_IF_COMPILING(glIsTexture)
#endif
    return gles_glIsTexture(texture);
}
GLboolean glIsTexture(GLuint texture) __attribute__((alias("glshim_glIsTexture")));
#endif
#ifndef skip_glLightModelf
void glshim_glLightModelf(GLenum pname, GLfloat param) {
    LOAD_GLES(glLightModelf);
#ifndef direct_glLightModelf
    PUSH_IF_COMPILING(glLightModelf)
#endif
    gles_glLightModelf(pname, param);
}
void glLightModelf(GLenum pname, GLfloat param) __attribute__((alias("glshim_glLightModelf")));
#endif
#ifndef skip_glLightModelfv
void glshim_glLightModelfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glLightModelfv);
#ifndef direct_glLightModelfv
    PUSH_IF_COMPILING(glLightModelfv)
#endif
    gles_glLightModelfv(pname, params);
}
void glLightModelfv(GLenum pname, const GLfloat * params) __attribute__((alias("glshim_glLightModelfv")));
#endif
#ifndef skip_glLightModelx
void glshim_glLightModelx(GLenum pname, GLfixed param) {
    LOAD_GLES(glLightModelx);
#ifndef direct_glLightModelx
    PUSH_IF_COMPILING(glLightModelx)
#endif
    gles_glLightModelx(pname, param);
}
void glLightModelx(GLenum pname, GLfixed param) __attribute__((alias("glshim_glLightModelx")));
#endif
#ifndef skip_glLightModelxv
void glshim_glLightModelxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glLightModelxv);
#ifndef direct_glLightModelxv
    PUSH_IF_COMPILING(glLightModelxv)
#endif
    gles_glLightModelxv(pname, params);
}
void glLightModelxv(GLenum pname, const GLfixed * params) __attribute__((alias("glshim_glLightModelxv")));
#endif
#ifndef skip_glLightf
void glshim_glLightf(GLenum light, GLenum pname, GLfloat param) {
    LOAD_GLES(glLightf);
#ifndef direct_glLightf
    PUSH_IF_COMPILING(glLightf)
#endif
    gles_glLightf(light, pname, param);
}
void glLightf(GLenum light, GLenum pname, GLfloat param) __attribute__((alias("glshim_glLightf")));
#endif
#ifndef skip_glLightfv
void glshim_glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glLightfv);
#ifndef direct_glLightfv
    PUSH_IF_COMPILING(glLightfv)
#endif
    gles_glLightfv(light, pname, params);
}
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) __attribute__((alias("glshim_glLightfv")));
#endif
#ifndef skip_glLightx
void glshim_glLightx(GLenum light, GLenum pname, GLfixed param) {
    LOAD_GLES(glLightx);
#ifndef direct_glLightx
    PUSH_IF_COMPILING(glLightx)
#endif
    gles_glLightx(light, pname, param);
}
void glLightx(GLenum light, GLenum pname, GLfixed param) __attribute__((alias("glshim_glLightx")));
#endif
#ifndef skip_glLightxv
void glshim_glLightxv(GLenum light, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glLightxv);
#ifndef direct_glLightxv
    PUSH_IF_COMPILING(glLightxv)
#endif
    gles_glLightxv(light, pname, params);
}
void glLightxv(GLenum light, GLenum pname, const GLfixed * params) __attribute__((alias("glshim_glLightxv")));
#endif
#ifndef skip_glLineWidth
void glshim_glLineWidth(GLfloat width) {
    LOAD_GLES(glLineWidth);
#ifndef direct_glLineWidth
    PUSH_IF_COMPILING(glLineWidth)
#endif
    gles_glLineWidth(width);
}
void glLineWidth(GLfloat width) __attribute__((alias("glshim_glLineWidth")));
#endif
#ifndef skip_glLineWidthx
void glshim_glLineWidthx(GLfixed width) {
    LOAD_GLES(glLineWidthx);
#ifndef direct_glLineWidthx
    PUSH_IF_COMPILING(glLineWidthx)
#endif
    gles_glLineWidthx(width);
}
void glLineWidthx(GLfixed width) __attribute__((alias("glshim_glLineWidthx")));
#endif
#ifndef skip_glLoadIdentity
void glshim_glLoadIdentity() {
    LOAD_GLES(glLoadIdentity);
#ifndef direct_glLoadIdentity
    PUSH_IF_COMPILING(glLoadIdentity)
#endif
    gles_glLoadIdentity();
}
void glLoadIdentity() __attribute__((alias("glshim_glLoadIdentity")));
#endif
#ifndef skip_glLoadMatrixf
void glshim_glLoadMatrixf(const GLfloat * m) {
    LOAD_GLES(glLoadMatrixf);
#ifndef direct_glLoadMatrixf
    PUSH_IF_COMPILING(glLoadMatrixf)
#endif
    gles_glLoadMatrixf(m);
}
void glLoadMatrixf(const GLfloat * m) __attribute__((alias("glshim_glLoadMatrixf")));
#endif
#ifndef skip_glLoadMatrixx
void glshim_glLoadMatrixx(const GLfixed * m) {
    LOAD_GLES(glLoadMatrixx);
#ifndef direct_glLoadMatrixx
    PUSH_IF_COMPILING(glLoadMatrixx)
#endif
    gles_glLoadMatrixx(m);
}
void glLoadMatrixx(const GLfixed * m) __attribute__((alias("glshim_glLoadMatrixx")));
#endif
#ifndef skip_glLogicOp
void glshim_glLogicOp(GLenum opcode) {
    LOAD_GLES(glLogicOp);
#ifndef direct_glLogicOp
    PUSH_IF_COMPILING(glLogicOp)
#endif
    gles_glLogicOp(opcode);
}
void glLogicOp(GLenum opcode) __attribute__((alias("glshim_glLogicOp")));
#endif
#ifndef skip_glMaterialf
void glshim_glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    LOAD_GLES(glMaterialf);
#ifndef direct_glMaterialf
    PUSH_IF_COMPILING(glMaterialf)
#endif
    gles_glMaterialf(face, pname, param);
}
void glMaterialf(GLenum face, GLenum pname, GLfloat param) __attribute__((alias("glshim_glMaterialf")));
#endif
#ifndef skip_glMaterialfv
void glshim_glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glMaterialfv);
#ifndef direct_glMaterialfv
    PUSH_IF_COMPILING(glMaterialfv)
#endif
    gles_glMaterialfv(face, pname, params);
}
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) __attribute__((alias("glshim_glMaterialfv")));
#endif
#ifndef skip_glMaterialx
void glshim_glMaterialx(GLenum face, GLenum pname, GLfixed param) {
    LOAD_GLES(glMaterialx);
#ifndef direct_glMaterialx
    PUSH_IF_COMPILING(glMaterialx)
#endif
    gles_glMaterialx(face, pname, param);
}
void glMaterialx(GLenum face, GLenum pname, GLfixed param) __attribute__((alias("glshim_glMaterialx")));
#endif
#ifndef skip_glMaterialxv
void glshim_glMaterialxv(GLenum face, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glMaterialxv);
#ifndef direct_glMaterialxv
    PUSH_IF_COMPILING(glMaterialxv)
#endif
    gles_glMaterialxv(face, pname, params);
}
void glMaterialxv(GLenum face, GLenum pname, const GLfixed * params) __attribute__((alias("glshim_glMaterialxv")));
#endif
#ifndef skip_glMatrixMode
void glshim_glMatrixMode(GLenum mode) {
    LOAD_GLES(glMatrixMode);
#ifndef direct_glMatrixMode
    PUSH_IF_COMPILING(glMatrixMode)
#endif
    gles_glMatrixMode(mode);
}
void glMatrixMode(GLenum mode) __attribute__((alias("glshim_glMatrixMode")));
#endif
#ifndef skip_glMultMatrixf
void glshim_glMultMatrixf(const GLfloat * m) {
    LOAD_GLES(glMultMatrixf);
#ifndef direct_glMultMatrixf
    PUSH_IF_COMPILING(glMultMatrixf)
#endif
    gles_glMultMatrixf(m);
}
void glMultMatrixf(const GLfloat * m) __attribute__((alias("glshim_glMultMatrixf")));
#endif
#ifndef skip_glMultMatrixx
void glshim_glMultMatrixx(const GLfixed * m) {
    LOAD_GLES(glMultMatrixx);
#ifndef direct_glMultMatrixx
    PUSH_IF_COMPILING(glMultMatrixx)
#endif
    gles_glMultMatrixx(m);
}
void glMultMatrixx(const GLfixed * m) __attribute__((alias("glshim_glMultMatrixx")));
#endif
#ifndef skip_glMultiTexCoord4f
void glshim_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    LOAD_GLES(glMultiTexCoord4f);
#ifndef direct_glMultiTexCoord4f
    PUSH_IF_COMPILING(glMultiTexCoord4f)
#endif
    gles_glMultiTexCoord4f(target, s, t, r, q);
}
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) __attribute__((alias("glshim_glMultiTexCoord4f")));
#endif
#ifndef skip_glMultiTexCoord4x
void glshim_glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    LOAD_GLES(glMultiTexCoord4x);
#ifndef direct_glMultiTexCoord4x
    PUSH_IF_COMPILING(glMultiTexCoord4x)
#endif
    gles_glMultiTexCoord4x(target, s, t, r, q);
}
void glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) __attribute__((alias("glshim_glMultiTexCoord4x")));
#endif
#ifndef skip_glNormal3f
void glshim_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    LOAD_GLES(glNormal3f);
#ifndef direct_glNormal3f
    PUSH_IF_COMPILING(glNormal3f)
#endif
    gles_glNormal3f(nx, ny, nz);
}
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) __attribute__((alias("glshim_glNormal3f")));
#endif
#ifndef skip_glNormal3x
void glshim_glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
    LOAD_GLES(glNormal3x);
#ifndef direct_glNormal3x
    PUSH_IF_COMPILING(glNormal3x)
#endif
    gles_glNormal3x(nx, ny, nz);
}
void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) __attribute__((alias("glshim_glNormal3x")));
#endif
#ifndef skip_glNormalPointer
void glshim_glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glNormalPointer);
#ifndef direct_glNormalPointer
    PUSH_IF_COMPILING(glNormalPointer)
#endif
    gles_glNormalPointer(type, stride, pointer);
}
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) __attribute__((alias("glshim_glNormalPointer")));
#endif
#ifndef skip_glOrthof
void glshim_glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    LOAD_GLES(glOrthof);
#ifndef direct_glOrthof
    PUSH_IF_COMPILING(glOrthof)
#endif
    gles_glOrthof(left, right, bottom, top, near, far);
}
void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) __attribute__((alias("glshim_glOrthof")));
#endif
#ifndef skip_glOrthox
void glshim_glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    LOAD_GLES(glOrthox);
#ifndef direct_glOrthox
    PUSH_IF_COMPILING(glOrthox)
#endif
    gles_glOrthox(left, right, bottom, top, near, far);
}
void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) __attribute__((alias("glshim_glOrthox")));
#endif
#ifndef skip_glPixelStorei
void glshim_glPixelStorei(GLenum pname, GLint param) {
    LOAD_GLES(glPixelStorei);
#ifndef direct_glPixelStorei
    PUSH_IF_COMPILING(glPixelStorei)
#endif
    gles_glPixelStorei(pname, param);
}
void glPixelStorei(GLenum pname, GLint param) __attribute__((alias("glshim_glPixelStorei")));
#endif
#ifndef skip_glPointParameterf
void glshim_glPointParameterf(GLenum pname, GLfloat param) {
    LOAD_GLES(glPointParameterf);
#ifndef direct_glPointParameterf
    PUSH_IF_COMPILING(glPointParameterf)
#endif
    gles_glPointParameterf(pname, param);
}
void glPointParameterf(GLenum pname, GLfloat param) __attribute__((alias("glshim_glPointParameterf")));
#endif
#ifndef skip_glPointParameterfv
void glshim_glPointParameterfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glPointParameterfv);
#ifndef direct_glPointParameterfv
    PUSH_IF_COMPILING(glPointParameterfv)
#endif
    gles_glPointParameterfv(pname, params);
}
void glPointParameterfv(GLenum pname, const GLfloat * params) __attribute__((alias("glshim_glPointParameterfv")));
#endif
#ifndef skip_glPointParameterx
void glshim_glPointParameterx(GLenum pname, GLfixed param) {
    LOAD_GLES(glPointParameterx);
#ifndef direct_glPointParameterx
    PUSH_IF_COMPILING(glPointParameterx)
#endif
    gles_glPointParameterx(pname, param);
}
void glPointParameterx(GLenum pname, GLfixed param) __attribute__((alias("glshim_glPointParameterx")));
#endif
#ifndef skip_glPointParameterxv
void glshim_glPointParameterxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glPointParameterxv);
#ifndef direct_glPointParameterxv
    PUSH_IF_COMPILING(glPointParameterxv)
#endif
    gles_glPointParameterxv(pname, params);
}
void glPointParameterxv(GLenum pname, const GLfixed * params) __attribute__((alias("glshim_glPointParameterxv")));
#endif
#ifndef skip_glPointSize
void glshim_glPointSize(GLfloat size) {
    LOAD_GLES(glPointSize);
#ifndef direct_glPointSize
    PUSH_IF_COMPILING(glPointSize)
#endif
    gles_glPointSize(size);
}
void glPointSize(GLfloat size) __attribute__((alias("glshim_glPointSize")));
#endif
#ifndef skip_glPointSizePointerOES
void glshim_glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glPointSizePointerOES);
#ifndef direct_glPointSizePointerOES
    PUSH_IF_COMPILING(glPointSizePointerOES)
#endif
    gles_glPointSizePointerOES(type, stride, pointer);
}
void glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer) __attribute__((alias("glshim_glPointSizePointerOES")));
#endif
#ifndef skip_glPointSizex
void glshim_glPointSizex(GLfixed size) {
    LOAD_GLES(glPointSizex);
#ifndef direct_glPointSizex
    PUSH_IF_COMPILING(glPointSizex)
#endif
    gles_glPointSizex(size);
}
void glPointSizex(GLfixed size) __attribute__((alias("glshim_glPointSizex")));
#endif
#ifndef skip_glPolygonOffset
void glshim_glPolygonOffset(GLfloat factor, GLfloat units) {
    LOAD_GLES(glPolygonOffset);
#ifndef direct_glPolygonOffset
    PUSH_IF_COMPILING(glPolygonOffset)
#endif
    gles_glPolygonOffset(factor, units);
}
void glPolygonOffset(GLfloat factor, GLfloat units) __attribute__((alias("glshim_glPolygonOffset")));
#endif
#ifndef skip_glPolygonOffsetx
void glshim_glPolygonOffsetx(GLfixed factor, GLfixed units) {
    LOAD_GLES(glPolygonOffsetx);
#ifndef direct_glPolygonOffsetx
    PUSH_IF_COMPILING(glPolygonOffsetx)
#endif
    gles_glPolygonOffsetx(factor, units);
}
void glPolygonOffsetx(GLfixed factor, GLfixed units) __attribute__((alias("glshim_glPolygonOffsetx")));
#endif
#ifndef skip_glPopMatrix
void glshim_glPopMatrix() {
    LOAD_GLES(glPopMatrix);
#ifndef direct_glPopMatrix
    PUSH_IF_COMPILING(glPopMatrix)
#endif
    gles_glPopMatrix();
}
void glPopMatrix() __attribute__((alias("glshim_glPopMatrix")));
#endif
#ifndef skip_glPushMatrix
void glshim_glPushMatrix() {
    LOAD_GLES(glPushMatrix);
#ifndef direct_glPushMatrix
    PUSH_IF_COMPILING(glPushMatrix)
#endif
    gles_glPushMatrix();
}
void glPushMatrix() __attribute__((alias("glshim_glPushMatrix")));
#endif
#ifndef skip_glReadPixels
void glshim_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    LOAD_GLES(glReadPixels);
#ifndef direct_glReadPixels
    PUSH_IF_COMPILING(glReadPixels)
#endif
    gles_glReadPixels(x, y, width, height, format, type, pixels);
}
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) __attribute__((alias("glshim_glReadPixels")));
#endif
#ifndef skip_glRotatef
void glshim_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glRotatef);
#ifndef direct_glRotatef
    PUSH_IF_COMPILING(glRotatef)
#endif
    gles_glRotatef(angle, x, y, z);
}
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) __attribute__((alias("glshim_glRotatef")));
#endif
#ifndef skip_glRotatex
void glshim_glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glRotatex);
#ifndef direct_glRotatex
    PUSH_IF_COMPILING(glRotatex)
#endif
    gles_glRotatex(angle, x, y, z);
}
void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) __attribute__((alias("glshim_glRotatex")));
#endif
#ifndef skip_glSampleCoverage
void glshim_glSampleCoverage(GLclampf value, GLboolean invert) {
    LOAD_GLES(glSampleCoverage);
#ifndef direct_glSampleCoverage
    PUSH_IF_COMPILING(glSampleCoverage)
#endif
    gles_glSampleCoverage(value, invert);
}
void glSampleCoverage(GLclampf value, GLboolean invert) __attribute__((alias("glshim_glSampleCoverage")));
#endif
#ifndef skip_glSampleCoveragex
void glshim_glSampleCoveragex(GLclampx value, GLboolean invert) {
    LOAD_GLES(glSampleCoveragex);
#ifndef direct_glSampleCoveragex
    PUSH_IF_COMPILING(glSampleCoveragex)
#endif
    gles_glSampleCoveragex(value, invert);
}
void glSampleCoveragex(GLclampx value, GLboolean invert) __attribute__((alias("glshim_glSampleCoveragex")));
#endif
#ifndef skip_glScalef
void glshim_glScalef(GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glScalef);
#ifndef direct_glScalef
    PUSH_IF_COMPILING(glScalef)
#endif
    gles_glScalef(x, y, z);
}
void glScalef(GLfloat x, GLfloat y, GLfloat z) __attribute__((alias("glshim_glScalef")));
#endif
#ifndef skip_glScalex
void glshim_glScalex(GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glScalex);
#ifndef direct_glScalex
    PUSH_IF_COMPILING(glScalex)
#endif
    gles_glScalex(x, y, z);
}
void glScalex(GLfixed x, GLfixed y, GLfixed z) __attribute__((alias("glshim_glScalex")));
#endif
#ifndef skip_glScissor
void glshim_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glScissor);
#ifndef direct_glScissor
    PUSH_IF_COMPILING(glScissor)
#endif
    gles_glScissor(x, y, width, height);
}
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glScissor")));
#endif
#ifndef skip_glShadeModel
void glshim_glShadeModel(GLenum mode) {
    LOAD_GLES(glShadeModel);
#ifndef direct_glShadeModel
    PUSH_IF_COMPILING(glShadeModel)
#endif
    gles_glShadeModel(mode);
}
void glShadeModel(GLenum mode) __attribute__((alias("glshim_glShadeModel")));
#endif
#ifndef skip_glStencilFunc
void glshim_glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    LOAD_GLES(glStencilFunc);
#ifndef direct_glStencilFunc
    PUSH_IF_COMPILING(glStencilFunc)
#endif
    gles_glStencilFunc(func, ref, mask);
}
void glStencilFunc(GLenum func, GLint ref, GLuint mask) __attribute__((alias("glshim_glStencilFunc")));
#endif
#ifndef skip_glStencilMask
void glshim_glStencilMask(GLuint mask) {
    LOAD_GLES(glStencilMask);
#ifndef direct_glStencilMask
    PUSH_IF_COMPILING(glStencilMask)
#endif
    gles_glStencilMask(mask);
}
void glStencilMask(GLuint mask) __attribute__((alias("glshim_glStencilMask")));
#endif
#ifndef skip_glStencilOp
void glshim_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    LOAD_GLES(glStencilOp);
#ifndef direct_glStencilOp
    PUSH_IF_COMPILING(glStencilOp)
#endif
    gles_glStencilOp(fail, zfail, zpass);
}
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) __attribute__((alias("glshim_glStencilOp")));
#endif
#ifndef skip_glTexCoordPointer
void glshim_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glTexCoordPointer);
#ifndef direct_glTexCoordPointer
    PUSH_IF_COMPILING(glTexCoordPointer)
#endif
    gles_glTexCoordPointer(size, type, stride, pointer);
}
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) __attribute__((alias("glshim_glTexCoordPointer")));
#endif
#ifndef skip_glTexEnvf
void glshim_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(glTexEnvf);
#ifndef direct_glTexEnvf
    PUSH_IF_COMPILING(glTexEnvf)
#endif
    gles_glTexEnvf(target, pname, param);
}
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) __attribute__((alias("glshim_glTexEnvf")));
#endif
#ifndef skip_glTexEnvfv
void glshim_glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glTexEnvfv);
#ifndef direct_glTexEnvfv
    PUSH_IF_COMPILING(glTexEnvfv)
#endif
    gles_glTexEnvfv(target, pname, params);
}
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) __attribute__((alias("glshim_glTexEnvfv")));
#endif
#ifndef skip_glTexEnvi
void glshim_glTexEnvi(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(glTexEnvi);
#ifndef direct_glTexEnvi
    PUSH_IF_COMPILING(glTexEnvi)
#endif
    gles_glTexEnvi(target, pname, param);
}
void glTexEnvi(GLenum target, GLenum pname, GLint param) __attribute__((alias("glshim_glTexEnvi")));
#endif
#ifndef skip_glTexEnviv
void glshim_glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    LOAD_GLES(glTexEnviv);
#ifndef direct_glTexEnviv
    PUSH_IF_COMPILING(glTexEnviv)
#endif
    gles_glTexEnviv(target, pname, params);
}
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) __attribute__((alias("glshim_glTexEnviv")));
#endif
#ifndef skip_glTexEnvx
void glshim_glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
    LOAD_GLES(glTexEnvx);
#ifndef direct_glTexEnvx
    PUSH_IF_COMPILING(glTexEnvx)
#endif
    gles_glTexEnvx(target, pname, param);
}
void glTexEnvx(GLenum target, GLenum pname, GLfixed param) __attribute__((alias("glshim_glTexEnvx")));
#endif
#ifndef skip_glTexEnvxv
void glshim_glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glTexEnvxv);
#ifndef direct_glTexEnvxv
    PUSH_IF_COMPILING(glTexEnvxv)
#endif
    gles_glTexEnvxv(target, pname, params);
}
void glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params) __attribute__((alias("glshim_glTexEnvxv")));
#endif
#ifndef skip_glTexImage2D
void glshim_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    LOAD_GLES(glTexImage2D);
#ifndef direct_glTexImage2D
    PUSH_IF_COMPILING(glTexImage2D)
#endif
    gles_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) __attribute__((alias("glshim_glTexImage2D")));
#endif
#ifndef skip_glTexParameterf
void glshim_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(glTexParameterf);
#ifndef direct_glTexParameterf
    PUSH_IF_COMPILING(glTexParameterf)
#endif
    gles_glTexParameterf(target, pname, param);
}
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) __attribute__((alias("glshim_glTexParameterf")));
#endif
#ifndef skip_glTexParameterfv
void glshim_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glTexParameterfv);
#ifndef direct_glTexParameterfv
    PUSH_IF_COMPILING(glTexParameterfv)
#endif
    gles_glTexParameterfv(target, pname, params);
}
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) __attribute__((alias("glshim_glTexParameterfv")));
#endif
#ifndef skip_glTexParameteri
void glshim_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(glTexParameteri);
#ifndef direct_glTexParameteri
    PUSH_IF_COMPILING(glTexParameteri)
#endif
    gles_glTexParameteri(target, pname, param);
}
void glTexParameteri(GLenum target, GLenum pname, GLint param) __attribute__((alias("glshim_glTexParameteri")));
#endif
#ifndef skip_glTexParameteriv
void glshim_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    LOAD_GLES(glTexParameteriv);
#ifndef direct_glTexParameteriv
    PUSH_IF_COMPILING(glTexParameteriv)
#endif
    gles_glTexParameteriv(target, pname, params);
}
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) __attribute__((alias("glshim_glTexParameteriv")));
#endif
#ifndef skip_glTexParameterx
void glshim_glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
    LOAD_GLES(glTexParameterx);
#ifndef direct_glTexParameterx
    PUSH_IF_COMPILING(glTexParameterx)
#endif
    gles_glTexParameterx(target, pname, param);
}
void glTexParameterx(GLenum target, GLenum pname, GLfixed param) __attribute__((alias("glshim_glTexParameterx")));
#endif
#ifndef skip_glTexParameterxv
void glshim_glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glTexParameterxv);
#ifndef direct_glTexParameterxv
    PUSH_IF_COMPILING(glTexParameterxv)
#endif
    gles_glTexParameterxv(target, pname, params);
}
void glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params) __attribute__((alias("glshim_glTexParameterxv")));
#endif
#ifndef skip_glTexSubImage2D
void glshim_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    LOAD_GLES(glTexSubImage2D);
#ifndef direct_glTexSubImage2D
    PUSH_IF_COMPILING(glTexSubImage2D)
#endif
    gles_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) __attribute__((alias("glshim_glTexSubImage2D")));
#endif
#ifndef skip_glTranslatef
void glshim_glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glTranslatef);
#ifndef direct_glTranslatef
    PUSH_IF_COMPILING(glTranslatef)
#endif
    gles_glTranslatef(x, y, z);
}
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) __attribute__((alias("glshim_glTranslatef")));
#endif
#ifndef skip_glTranslatex
void glshim_glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glTranslatex);
#ifndef direct_glTranslatex
    PUSH_IF_COMPILING(glTranslatex)
#endif
    gles_glTranslatex(x, y, z);
}
void glTranslatex(GLfixed x, GLfixed y, GLfixed z) __attribute__((alias("glshim_glTranslatex")));
#endif
#ifndef skip_glVertexPointer
void glshim_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glVertexPointer);
#ifndef direct_glVertexPointer
    PUSH_IF_COMPILING(glVertexPointer)
#endif
    gles_glVertexPointer(size, type, stride, pointer);
}
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) __attribute__((alias("glshim_glVertexPointer")));
#endif
#ifndef skip_glViewport
void glshim_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glViewport);
#ifndef direct_glViewport
    PUSH_IF_COMPILING(glViewport)
#endif
    gles_glViewport(x, y, width, height);
}
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glViewport")));
#endif
void glPackedCall(const packed_call_t *packed) {
    switch (packed->format) {
        case FORMAT_void_GLenum: {
            PACKED_void_GLenum *unpacked = (PACKED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLclampf: {
            PACKED_void_GLenum_GLclampf *unpacked = (PACKED_void_GLenum_GLclampf *)packed;
            ARGS_void_GLenum_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLclampx: {
            PACKED_void_GLenum_GLclampx *unpacked = (PACKED_void_GLenum_GLclampx *)packed;
            ARGS_void_GLenum_GLclampx args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLuint: {
            PACKED_void_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum: {
            PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *unpacked = (PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *)packed;
            ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLbitfield: {
            PACKED_void_GLbitfield *unpacked = (PACKED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *)packed;
            ARGS_void_GLclampf_GLclampf_GLclampf_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLclampx_GLclampx_GLclampx_GLclampx: {
            PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *unpacked = (PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *)packed;
            ARGS_void_GLclampx_GLclampx_GLclampx_GLclampx args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLclampf: {
            PACKED_void_GLclampf *unpacked = (PACKED_void_GLclampf *)packed;
            ARGS_void_GLclampf args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLclampx: {
            PACKED_void_GLclampx *unpacked = (PACKED_void_GLclampx *)packed;
            ARGS_void_GLclampx args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLint: {
            PACKED_void_GLint *unpacked = (PACKED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_const_GLfixed___GENPT__: {
            PACKED_void_GLenum_const_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLfixed___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte: {
            PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *unpacked = (PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean: {
            PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint: {
            PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLsizei_const_GLuint___GENPT__: {
            PACKED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLboolean: {
            PACKED_void_GLboolean *unpacked = (PACKED_void_GLboolean *)packed;
            ARGS_void_GLboolean args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf *)packed;
            ARGS_void_GLclampf_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLclampx_GLclampx: {
            PACKED_void_GLclampx_GLclampx *unpacked = (PACKED_void_GLclampx_GLclampx *)packed;
            ARGS_void_GLclampx_GLclampx args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLsizei: {
            PACKED_void_GLenum_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void: {
            PACKED_void *unpacked = (PACKED_void *)packed;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLfloat: {
            PACKED_void_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLfixed: {
            PACKED_void_GLenum_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLsizei_GLuint___GENPT__: {
            PACKED_void_GLsizei_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLboolean___GENPT__: {
            PACKED_void_GLenum_GLboolean___GENPT__ *unpacked = (PACKED_void_GLenum_GLboolean___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLfixed___GENPT__ *)packed;
            ARGS_void_GLenum_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_GLenum: {
            PACKED_GLenum *unpacked = (PACKED_GLenum *)packed;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLvoid___GENPT____GENPT__: {
            PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *unpacked = (PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *)packed;
            ARGS_void_GLenum_GLvoid___GENPT____GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_const_GLubyte___GENPT___GLenum: {
            PACKED_const_GLubyte___GENPT___GLenum *unpacked = (PACKED_const_GLubyte___GENPT___GLenum *)packed;
            ARGS_const_GLubyte___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_GLboolean_GLuint: {
            PACKED_GLboolean_GLuint *unpacked = (PACKED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_GLboolean_GLenum: {
            PACKED_GLboolean_GLenum *unpacked = (PACKED_GLboolean_GLenum *)packed;
            ARGS_GLboolean_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat: {
            PACKED_void_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfixed: {
            PACKED_void_GLenum_GLenum_GLfixed *unpacked = (PACKED_void_GLenum_GLenum_GLfixed *)packed;
            ARGS_void_GLenum_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLfloat: {
            PACKED_void_GLfloat *unpacked = (PACKED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLfixed: {
            PACKED_void_GLfixed *unpacked = (PACKED_void_GLfixed *)packed;
            ARGS_void_GLfixed args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_const_GLfloat___GENPT__: {
            PACKED_void_const_GLfloat___GENPT__ *unpacked = (PACKED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_const_GLfixed___GENPT__: {
            PACKED_void_const_GLfixed___GENPT__ *unpacked = (PACKED_void_const_GLfixed___GENPT__ *)packed;
            ARGS_void_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint: {
            PACKED_void_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLclampf_GLboolean: {
            PACKED_void_GLclampf_GLboolean *unpacked = (PACKED_void_GLclampf_GLboolean *)packed;
            ARGS_void_GLclampf_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLclampx_GLboolean: {
            PACKED_void_GLclampx_GLboolean *unpacked = (PACKED_void_GLclampx_GLboolean *)packed;
            ARGS_void_GLclampx_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint: {
            PACKED_void_GLuint *unpacked = (PACKED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint: {
            PACKED_void_GLenum_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
    }
}
#endif
