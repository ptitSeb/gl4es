#include "gles.h"
#include "../gl4es.h"
#include "../loader.h"
#include "skips.h"
#ifndef skip_glActiveTexture
void gl4es_glActiveTexture(GLenum texture) {
    LOAD_GLES(glActiveTexture);
#ifndef direct_glActiveTexture
    PUSH_IF_COMPILING(glActiveTexture)
#endif
    gles_glActiveTexture(texture);
}
void glActiveTexture(GLenum texture) AliasExport("gl4es_glActiveTexture");
#endif
#ifndef skip_glAlphaFunc
void gl4es_glAlphaFunc(GLenum func, GLclampf ref) {
    LOAD_GLES(glAlphaFunc);
#ifndef direct_glAlphaFunc
    PUSH_IF_COMPILING(glAlphaFunc)
#endif
    gles_glAlphaFunc(func, ref);
}
void glAlphaFunc(GLenum func, GLclampf ref) AliasExport("gl4es_glAlphaFunc");
#endif
#ifndef skip_glAlphaFuncx
void gl4es_glAlphaFuncx(GLenum func, GLclampx ref) {
    LOAD_GLES(glAlphaFuncx);
#ifndef direct_glAlphaFuncx
    PUSH_IF_COMPILING(glAlphaFuncx)
#endif
    gles_glAlphaFuncx(func, ref);
}
void glAlphaFuncx(GLenum func, GLclampx ref) AliasExport("gl4es_glAlphaFuncx");
#endif
#ifndef skip_glAttachShader
void gl4es_glAttachShader(GLuint program, GLuint shader) {
    LOAD_GLES(glAttachShader);
#ifndef direct_glAttachShader
    PUSH_IF_COMPILING(glAttachShader)
#endif
    gles_glAttachShader(program, shader);
}
void glAttachShader(GLuint program, GLuint shader) AliasExport("gl4es_glAttachShader");
#endif
#ifndef skip_glBindAttribLocation
void gl4es_glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    LOAD_GLES(glBindAttribLocation);
#ifndef direct_glBindAttribLocation
    PUSH_IF_COMPILING(glBindAttribLocation)
#endif
    gles_glBindAttribLocation(program, index, name);
}
void glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) AliasExport("gl4es_glBindAttribLocation");
#endif
#ifndef skip_glBindBuffer
void gl4es_glBindBuffer(GLenum target, GLuint buffer) {
    LOAD_GLES(glBindBuffer);
#ifndef direct_glBindBuffer
    PUSH_IF_COMPILING(glBindBuffer)
#endif
    gles_glBindBuffer(target, buffer);
}
void glBindBuffer(GLenum target, GLuint buffer) AliasExport("gl4es_glBindBuffer");
#endif
#ifndef skip_glBindFramebuffer
void gl4es_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    LOAD_GLES_OES(glBindFramebuffer);
#ifndef direct_glBindFramebuffer
    PUSH_IF_COMPILING(glBindFramebuffer)
#endif
    gles_glBindFramebuffer(target, framebuffer);
}
void glBindFramebuffer(GLenum target, GLuint framebuffer) AliasExport("gl4es_glBindFramebuffer");
#endif
#ifndef skip_glBindRenderbuffer
void gl4es_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    LOAD_GLES_OES(glBindRenderbuffer);
#ifndef direct_glBindRenderbuffer
    PUSH_IF_COMPILING(glBindRenderbuffer)
#endif
    gles_glBindRenderbuffer(target, renderbuffer);
}
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) AliasExport("gl4es_glBindRenderbuffer");
#endif
#ifndef skip_glBindTexture
void gl4es_glBindTexture(GLenum target, GLuint texture) {
    LOAD_GLES(glBindTexture);
#ifndef direct_glBindTexture
    PUSH_IF_COMPILING(glBindTexture)
#endif
    gles_glBindTexture(target, texture);
}
void glBindTexture(GLenum target, GLuint texture) AliasExport("gl4es_glBindTexture");
#endif
#ifndef skip_glBlendColor
void gl4es_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    LOAD_GLES_OES(glBlendColor);
#ifndef direct_glBlendColor
    PUSH_IF_COMPILING(glBlendColor)
#endif
    gles_glBlendColor(red, green, blue, alpha);
}
void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) AliasExport("gl4es_glBlendColor");
#endif
#ifndef skip_glBlendEquation
void gl4es_glBlendEquation(GLenum mode) {
    LOAD_GLES_OES(glBlendEquation);
#ifndef direct_glBlendEquation
    PUSH_IF_COMPILING(glBlendEquation)
#endif
    gles_glBlendEquation(mode);
}
void glBlendEquation(GLenum mode) AliasExport("gl4es_glBlendEquation");
#endif
#ifndef skip_glBlendEquationSeparate
void gl4es_glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    LOAD_GLES_OES(glBlendEquationSeparate);
#ifndef direct_glBlendEquationSeparate
    PUSH_IF_COMPILING(glBlendEquationSeparate)
#endif
    gles_glBlendEquationSeparate(modeRGB, modeA);
}
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) AliasExport("gl4es_glBlendEquationSeparate");
#endif
#ifndef skip_glBlendFunc
void gl4es_glBlendFunc(GLenum sfactor, GLenum dfactor) {
    LOAD_GLES(glBlendFunc);
#ifndef direct_glBlendFunc
    PUSH_IF_COMPILING(glBlendFunc)
#endif
    gles_glBlendFunc(sfactor, dfactor);
}
void glBlendFunc(GLenum sfactor, GLenum dfactor) AliasExport("gl4es_glBlendFunc");
#endif
#ifndef skip_glBlendFuncSeparate
void gl4es_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    LOAD_GLES_OES(glBlendFuncSeparate);
#ifndef direct_glBlendFuncSeparate
    PUSH_IF_COMPILING(glBlendFuncSeparate)
#endif
    gles_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) AliasExport("gl4es_glBlendFuncSeparate");
#endif
#ifndef skip_glBufferData
void gl4es_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    LOAD_GLES(glBufferData);
#ifndef direct_glBufferData
    PUSH_IF_COMPILING(glBufferData)
#endif
    gles_glBufferData(target, size, data, usage);
}
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) AliasExport("gl4es_glBufferData");
#endif
#ifndef skip_glBufferSubData
void gl4es_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    LOAD_GLES(glBufferSubData);
#ifndef direct_glBufferSubData
    PUSH_IF_COMPILING(glBufferSubData)
#endif
    gles_glBufferSubData(target, offset, size, data);
}
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) AliasExport("gl4es_glBufferSubData");
#endif
#ifndef skip_glCheckFramebufferStatus
GLenum gl4es_glCheckFramebufferStatus(GLenum target) {
    LOAD_GLES_OES(glCheckFramebufferStatus);
#ifndef direct_glCheckFramebufferStatus
    PUSH_IF_COMPILING(glCheckFramebufferStatus)
#endif
    return gles_glCheckFramebufferStatus(target);
}
GLenum glCheckFramebufferStatus(GLenum target) AliasExport("gl4es_glCheckFramebufferStatus");
#endif
#ifndef skip_glClear
void gl4es_glClear(GLbitfield mask) {
    LOAD_GLES(glClear);
#ifndef direct_glClear
    PUSH_IF_COMPILING(glClear)
#endif
    gles_glClear(mask);
}
void glClear(GLbitfield mask) AliasExport("gl4es_glClear");
#endif
#ifndef skip_glClearColor
void gl4es_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    LOAD_GLES(glClearColor);
#ifndef direct_glClearColor
    PUSH_IF_COMPILING(glClearColor)
#endif
    gles_glClearColor(red, green, blue, alpha);
}
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) AliasExport("gl4es_glClearColor");
#endif
#ifndef skip_glClearColorx
void gl4es_glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) {
    LOAD_GLES(glClearColorx);
#ifndef direct_glClearColorx
    PUSH_IF_COMPILING(glClearColorx)
#endif
    gles_glClearColorx(red, green, blue, alpha);
}
void glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) AliasExport("gl4es_glClearColorx");
#endif
#ifndef skip_glClearDepthf
void gl4es_glClearDepthf(GLclampf depth) {
    LOAD_GLES(glClearDepthf);
#ifndef direct_glClearDepthf
    PUSH_IF_COMPILING(glClearDepthf)
#endif
    gles_glClearDepthf(depth);
}
void glClearDepthf(GLclampf depth) AliasExport("gl4es_glClearDepthf");
#endif
#ifndef skip_glClearDepthx
void gl4es_glClearDepthx(GLclampx depth) {
    LOAD_GLES(glClearDepthx);
#ifndef direct_glClearDepthx
    PUSH_IF_COMPILING(glClearDepthx)
#endif
    gles_glClearDepthx(depth);
}
void glClearDepthx(GLclampx depth) AliasExport("gl4es_glClearDepthx");
#endif
#ifndef skip_glClearStencil
void gl4es_glClearStencil(GLint s) {
    LOAD_GLES(glClearStencil);
#ifndef direct_glClearStencil
    PUSH_IF_COMPILING(glClearStencil)
#endif
    gles_glClearStencil(s);
}
void glClearStencil(GLint s) AliasExport("gl4es_glClearStencil");
#endif
#ifndef skip_glClientActiveTexture
void gl4es_glClientActiveTexture(GLenum texture) {
    LOAD_GLES(glClientActiveTexture);
#ifndef direct_glClientActiveTexture
    PUSH_IF_COMPILING(glClientActiveTexture)
#endif
    gles_glClientActiveTexture(texture);
}
void glClientActiveTexture(GLenum texture) AliasExport("gl4es_glClientActiveTexture");
#endif
#ifndef skip_glClipPlanef
void gl4es_glClipPlanef(GLenum plane, const GLfloat * equation) {
    LOAD_GLES(glClipPlanef);
#ifndef direct_glClipPlanef
    PUSH_IF_COMPILING(glClipPlanef)
#endif
    gles_glClipPlanef(plane, equation);
}
void glClipPlanef(GLenum plane, const GLfloat * equation) AliasExport("gl4es_glClipPlanef");
#endif
#ifndef skip_glClipPlanex
void gl4es_glClipPlanex(GLenum plane, const GLfixed * equation) {
    LOAD_GLES(glClipPlanex);
#ifndef direct_glClipPlanex
    PUSH_IF_COMPILING(glClipPlanex)
#endif
    gles_glClipPlanex(plane, equation);
}
void glClipPlanex(GLenum plane, const GLfixed * equation) AliasExport("gl4es_glClipPlanex");
#endif
#ifndef skip_glColor4f
void gl4es_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    LOAD_GLES(glColor4f);
#ifndef direct_glColor4f
    PUSH_IF_COMPILING(glColor4f)
#endif
    gles_glColor4f(red, green, blue, alpha);
}
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) AliasExport("gl4es_glColor4f");
#endif
#ifndef skip_glColor4ub
void gl4es_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    LOAD_GLES(glColor4ub);
#ifndef direct_glColor4ub
    PUSH_IF_COMPILING(glColor4ub)
#endif
    gles_glColor4ub(red, green, blue, alpha);
}
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) AliasExport("gl4es_glColor4ub");
#endif
#ifndef skip_glColor4x
void gl4es_glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    LOAD_GLES(glColor4x);
#ifndef direct_glColor4x
    PUSH_IF_COMPILING(glColor4x)
#endif
    gles_glColor4x(red, green, blue, alpha);
}
void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) AliasExport("gl4es_glColor4x");
#endif
#ifndef skip_glColorMask
void gl4es_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    LOAD_GLES(glColorMask);
#ifndef direct_glColorMask
    PUSH_IF_COMPILING(glColorMask)
#endif
    gles_glColorMask(red, green, blue, alpha);
}
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) AliasExport("gl4es_glColorMask");
#endif
#ifndef skip_glColorPointer
void gl4es_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glColorPointer);
#ifndef direct_glColorPointer
    PUSH_IF_COMPILING(glColorPointer)
#endif
    gles_glColorPointer(size, type, stride, pointer);
}
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glColorPointer");
#endif
#ifndef skip_glCompileShader
void gl4es_glCompileShader(GLuint shader) {
    LOAD_GLES(glCompileShader);
#ifndef direct_glCompileShader
    PUSH_IF_COMPILING(glCompileShader)
#endif
    gles_glCompileShader(shader);
}
void glCompileShader(GLuint shader) AliasExport("gl4es_glCompileShader");
#endif
#ifndef skip_glCompressedTexImage2D
void gl4es_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    LOAD_GLES(glCompressedTexImage2D);
#ifndef direct_glCompressedTexImage2D
    PUSH_IF_COMPILING(glCompressedTexImage2D)
#endif
    gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) AliasExport("gl4es_glCompressedTexImage2D");
#endif
#ifndef skip_glCompressedTexSubImage2D
void gl4es_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    LOAD_GLES(glCompressedTexSubImage2D);
#ifndef direct_glCompressedTexSubImage2D
    PUSH_IF_COMPILING(glCompressedTexSubImage2D)
#endif
    gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) AliasExport("gl4es_glCompressedTexSubImage2D");
#endif
#ifndef skip_glCopyTexImage2D
void gl4es_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    LOAD_GLES(glCopyTexImage2D);
#ifndef direct_glCopyTexImage2D
    PUSH_IF_COMPILING(glCopyTexImage2D)
#endif
    gles_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) AliasExport("gl4es_glCopyTexImage2D");
#endif
#ifndef skip_glCopyTexSubImage2D
void gl4es_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glCopyTexSubImage2D);
#ifndef direct_glCopyTexSubImage2D
    PUSH_IF_COMPILING(glCopyTexSubImage2D)
#endif
    gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyTexSubImage2D");
#endif
#ifndef skip_glCreateProgram
GLuint gl4es_glCreateProgram() {
    LOAD_GLES(glCreateProgram);
#ifndef direct_glCreateProgram
    PUSH_IF_COMPILING(glCreateProgram)
#endif
    return gles_glCreateProgram();
}
GLuint glCreateProgram() AliasExport("gl4es_glCreateProgram");
#endif
#ifndef skip_glCreateShader
GLuint gl4es_glCreateShader(GLenum type) {
    LOAD_GLES(glCreateShader);
#ifndef direct_glCreateShader
    PUSH_IF_COMPILING(glCreateShader)
#endif
    return gles_glCreateShader(type);
}
GLuint glCreateShader(GLenum type) AliasExport("gl4es_glCreateShader");
#endif
#ifndef skip_glCullFace
void gl4es_glCullFace(GLenum mode) {
    LOAD_GLES(glCullFace);
#ifndef direct_glCullFace
    PUSH_IF_COMPILING(glCullFace)
#endif
    gles_glCullFace(mode);
}
void glCullFace(GLenum mode) AliasExport("gl4es_glCullFace");
#endif
#ifndef skip_glDeleteBuffers
void gl4es_glDeleteBuffers(GLsizei n, const GLuint * buffer) {
    LOAD_GLES(glDeleteBuffers);
#ifndef direct_glDeleteBuffers
    PUSH_IF_COMPILING(glDeleteBuffers)
#endif
    gles_glDeleteBuffers(n, buffer);
}
void glDeleteBuffers(GLsizei n, const GLuint * buffer) AliasExport("gl4es_glDeleteBuffers");
#endif
#ifndef skip_glDeleteFramebuffers
void gl4es_glDeleteFramebuffers(GLsizei n, GLuint * framebuffers) {
    LOAD_GLES_OES(glDeleteFramebuffers);
#ifndef direct_glDeleteFramebuffers
    PUSH_IF_COMPILING(glDeleteFramebuffers)
#endif
    gles_glDeleteFramebuffers(n, framebuffers);
}
void glDeleteFramebuffers(GLsizei n, GLuint * framebuffers) AliasExport("gl4es_glDeleteFramebuffers");
#endif
#ifndef skip_glDeleteProgram
void gl4es_glDeleteProgram(GLuint program) {
    LOAD_GLES(glDeleteProgram);
#ifndef direct_glDeleteProgram
    PUSH_IF_COMPILING(glDeleteProgram)
#endif
    gles_glDeleteProgram(program);
}
void glDeleteProgram(GLuint program) AliasExport("gl4es_glDeleteProgram");
#endif
#ifndef skip_glDeleteRenderbuffers
void gl4es_glDeleteRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    LOAD_GLES_OES(glDeleteRenderbuffers);
#ifndef direct_glDeleteRenderbuffers
    PUSH_IF_COMPILING(glDeleteRenderbuffers)
#endif
    gles_glDeleteRenderbuffers(n, renderbuffers);
}
void glDeleteRenderbuffers(GLsizei n, GLuint * renderbuffers) AliasExport("gl4es_glDeleteRenderbuffers");
#endif
#ifndef skip_glDeleteShader
void gl4es_glDeleteShader(GLuint shader) {
    LOAD_GLES(glDeleteShader);
#ifndef direct_glDeleteShader
    PUSH_IF_COMPILING(glDeleteShader)
#endif
    gles_glDeleteShader(shader);
}
void glDeleteShader(GLuint shader) AliasExport("gl4es_glDeleteShader");
#endif
#ifndef skip_glDeleteTextures
void gl4es_glDeleteTextures(GLsizei n, const GLuint * textures) {
    LOAD_GLES(glDeleteTextures);
#ifndef direct_glDeleteTextures
    PUSH_IF_COMPILING(glDeleteTextures)
#endif
    gles_glDeleteTextures(n, textures);
}
void glDeleteTextures(GLsizei n, const GLuint * textures) AliasExport("gl4es_glDeleteTextures");
#endif
#ifndef skip_glDepthFunc
void gl4es_glDepthFunc(GLenum func) {
    LOAD_GLES(glDepthFunc);
#ifndef direct_glDepthFunc
    PUSH_IF_COMPILING(glDepthFunc)
#endif
    gles_glDepthFunc(func);
}
void glDepthFunc(GLenum func) AliasExport("gl4es_glDepthFunc");
#endif
#ifndef skip_glDepthMask
void gl4es_glDepthMask(GLboolean flag) {
    LOAD_GLES(glDepthMask);
#ifndef direct_glDepthMask
    PUSH_IF_COMPILING(glDepthMask)
#endif
    gles_glDepthMask(flag);
}
void glDepthMask(GLboolean flag) AliasExport("gl4es_glDepthMask");
#endif
#ifndef skip_glDepthRangef
void gl4es_glDepthRangef(GLclampf near, GLclampf far) {
    LOAD_GLES(glDepthRangef);
#ifndef direct_glDepthRangef
    PUSH_IF_COMPILING(glDepthRangef)
#endif
    gles_glDepthRangef(near, far);
}
void glDepthRangef(GLclampf near, GLclampf far) AliasExport("gl4es_glDepthRangef");
#endif
#ifndef skip_glDepthRangex
void gl4es_glDepthRangex(GLclampx near, GLclampx far) {
    LOAD_GLES(glDepthRangex);
#ifndef direct_glDepthRangex
    PUSH_IF_COMPILING(glDepthRangex)
#endif
    gles_glDepthRangex(near, far);
}
void glDepthRangex(GLclampx near, GLclampx far) AliasExport("gl4es_glDepthRangex");
#endif
#ifndef skip_glDetachShader
void gl4es_glDetachShader(GLuint program, GLuint shader) {
    LOAD_GLES(glDetachShader);
#ifndef direct_glDetachShader
    PUSH_IF_COMPILING(glDetachShader)
#endif
    gles_glDetachShader(program, shader);
}
void glDetachShader(GLuint program, GLuint shader) AliasExport("gl4es_glDetachShader");
#endif
#ifndef skip_glDisable
void gl4es_glDisable(GLenum cap) {
    LOAD_GLES(glDisable);
#ifndef direct_glDisable
    PUSH_IF_COMPILING(glDisable)
#endif
    gles_glDisable(cap);
}
void glDisable(GLenum cap) AliasExport("gl4es_glDisable");
#endif
#ifndef skip_glDisableClientState
void gl4es_glDisableClientState(GLenum array) {
    LOAD_GLES(glDisableClientState);
#ifndef direct_glDisableClientState
    PUSH_IF_COMPILING(glDisableClientState)
#endif
    gles_glDisableClientState(array);
}
void glDisableClientState(GLenum array) AliasExport("gl4es_glDisableClientState");
#endif
#ifndef skip_glDisableVertexAttribArray
void gl4es_glDisableVertexAttribArray(GLuint index) {
    LOAD_GLES(glDisableVertexAttribArray);
#ifndef direct_glDisableVertexAttribArray
    PUSH_IF_COMPILING(glDisableVertexAttribArray)
#endif
    gles_glDisableVertexAttribArray(index);
}
void glDisableVertexAttribArray(GLuint index) AliasExport("gl4es_glDisableVertexAttribArray");
#endif
#ifndef skip_glDrawArrays
void gl4es_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    LOAD_GLES(glDrawArrays);
#ifndef direct_glDrawArrays
    PUSH_IF_COMPILING(glDrawArrays)
#endif
    gles_glDrawArrays(mode, first, count);
}
void glDrawArrays(GLenum mode, GLint first, GLsizei count) AliasExport("gl4es_glDrawArrays");
#endif
#ifndef skip_glDrawBuffers
void gl4es_glDrawBuffers(GLsizei n, const GLenum * bufs) {
    LOAD_GLES_EXT(glDrawBuffers);
#ifndef direct_glDrawBuffers
    PUSH_IF_COMPILING(glDrawBuffers)
#endif
    gles_glDrawBuffers(n, bufs);
}
void glDrawBuffers(GLsizei n, const GLenum * bufs) AliasExport("gl4es_glDrawBuffers");
#endif
#ifndef skip_glDrawElements
void gl4es_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    LOAD_GLES(glDrawElements);
#ifndef direct_glDrawElements
    PUSH_IF_COMPILING(glDrawElements)
#endif
    gles_glDrawElements(mode, count, type, indices);
}
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) AliasExport("gl4es_glDrawElements");
#endif
#ifndef skip_glDrawTexf
void gl4es_glDrawTexf(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height) {
    LOAD_GLES_OES(glDrawTexf);
#ifndef direct_glDrawTexf
    PUSH_IF_COMPILING(glDrawTexf)
#endif
    gles_glDrawTexf(x, y, z, width, height);
}
void glDrawTexf(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height) AliasExport("gl4es_glDrawTexf");
#endif
#ifndef skip_glDrawTexi
void gl4es_glDrawTexi(GLint x, GLint y, GLint z, GLint width, GLint height) {
    LOAD_GLES_OES(glDrawTexi);
#ifndef direct_glDrawTexi
    PUSH_IF_COMPILING(glDrawTexi)
#endif
    gles_glDrawTexi(x, y, z, width, height);
}
void glDrawTexi(GLint x, GLint y, GLint z, GLint width, GLint height) AliasExport("gl4es_glDrawTexi");
#endif
#ifndef skip_glEnable
void gl4es_glEnable(GLenum cap) {
    LOAD_GLES(glEnable);
#ifndef direct_glEnable
    PUSH_IF_COMPILING(glEnable)
#endif
    gles_glEnable(cap);
}
void glEnable(GLenum cap) AliasExport("gl4es_glEnable");
#endif
#ifndef skip_glEnableClientState
void gl4es_glEnableClientState(GLenum array) {
    LOAD_GLES(glEnableClientState);
#ifndef direct_glEnableClientState
    PUSH_IF_COMPILING(glEnableClientState)
#endif
    gles_glEnableClientState(array);
}
void glEnableClientState(GLenum array) AliasExport("gl4es_glEnableClientState");
#endif
#ifndef skip_glEnableVertexAttribArray
void gl4es_glEnableVertexAttribArray(GLuint index) {
    LOAD_GLES(glEnableVertexAttribArray);
#ifndef direct_glEnableVertexAttribArray
    PUSH_IF_COMPILING(glEnableVertexAttribArray)
#endif
    gles_glEnableVertexAttribArray(index);
}
void glEnableVertexAttribArray(GLuint index) AliasExport("gl4es_glEnableVertexAttribArray");
#endif
#ifndef skip_glFinish
void gl4es_glFinish() {
    LOAD_GLES(glFinish);
#ifndef direct_glFinish
    PUSH_IF_COMPILING(glFinish)
#endif
    gles_glFinish();
}
void glFinish() AliasExport("gl4es_glFinish");
#endif
#ifndef skip_glFlush
void gl4es_glFlush() {
    LOAD_GLES(glFlush);
#ifndef direct_glFlush
    PUSH_IF_COMPILING(glFlush)
#endif
    gles_glFlush();
}
void glFlush() AliasExport("gl4es_glFlush");
#endif
#ifndef skip_glFogCoordPointer
void gl4es_glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glFogCoordPointer);
#ifndef direct_glFogCoordPointer
    PUSH_IF_COMPILING(glFogCoordPointer)
#endif
    gles_glFogCoordPointer(type, stride, pointer);
}
void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glFogCoordPointer");
#endif
#ifndef skip_glFogCoordf
void gl4es_glFogCoordf(GLfloat coord) {
    LOAD_GLES(glFogCoordf);
#ifndef direct_glFogCoordf
    PUSH_IF_COMPILING(glFogCoordf)
#endif
    gles_glFogCoordf(coord);
}
void glFogCoordf(GLfloat coord) AliasExport("gl4es_glFogCoordf");
#endif
#ifndef skip_glFogCoordfv
void gl4es_glFogCoordfv(const GLfloat * coord) {
    LOAD_GLES(glFogCoordfv);
#ifndef direct_glFogCoordfv
    PUSH_IF_COMPILING(glFogCoordfv)
#endif
    gles_glFogCoordfv(coord);
}
void glFogCoordfv(const GLfloat * coord) AliasExport("gl4es_glFogCoordfv");
#endif
#ifndef skip_glFogf
void gl4es_glFogf(GLenum pname, GLfloat param) {
    LOAD_GLES(glFogf);
#ifndef direct_glFogf
    PUSH_IF_COMPILING(glFogf)
#endif
    gles_glFogf(pname, param);
}
void glFogf(GLenum pname, GLfloat param) AliasExport("gl4es_glFogf");
#endif
#ifndef skip_glFogfv
void gl4es_glFogfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glFogfv);
#ifndef direct_glFogfv
    PUSH_IF_COMPILING(glFogfv)
#endif
    gles_glFogfv(pname, params);
}
void glFogfv(GLenum pname, const GLfloat * params) AliasExport("gl4es_glFogfv");
#endif
#ifndef skip_glFogx
void gl4es_glFogx(GLenum pname, GLfixed param) {
    LOAD_GLES(glFogx);
#ifndef direct_glFogx
    PUSH_IF_COMPILING(glFogx)
#endif
    gles_glFogx(pname, param);
}
void glFogx(GLenum pname, GLfixed param) AliasExport("gl4es_glFogx");
#endif
#ifndef skip_glFogxv
void gl4es_glFogxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glFogxv);
#ifndef direct_glFogxv
    PUSH_IF_COMPILING(glFogxv)
#endif
    gles_glFogxv(pname, params);
}
void glFogxv(GLenum pname, const GLfixed * params) AliasExport("gl4es_glFogxv");
#endif
#ifndef skip_glFramebufferRenderbuffer
void gl4es_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    LOAD_GLES_OES(glFramebufferRenderbuffer);
#ifndef direct_glFramebufferRenderbuffer
    PUSH_IF_COMPILING(glFramebufferRenderbuffer)
#endif
    gles_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) AliasExport("gl4es_glFramebufferRenderbuffer");
#endif
#ifndef skip_glFramebufferTexture2D
void gl4es_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    LOAD_GLES_OES(glFramebufferTexture2D);
#ifndef direct_glFramebufferTexture2D
    PUSH_IF_COMPILING(glFramebufferTexture2D)
#endif
    gles_glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) AliasExport("gl4es_glFramebufferTexture2D");
#endif
#ifndef skip_glFrontFace
void gl4es_glFrontFace(GLenum mode) {
    LOAD_GLES(glFrontFace);
#ifndef direct_glFrontFace
    PUSH_IF_COMPILING(glFrontFace)
#endif
    gles_glFrontFace(mode);
}
void glFrontFace(GLenum mode) AliasExport("gl4es_glFrontFace");
#endif
#ifndef skip_glFrustumf
void gl4es_glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    LOAD_GLES(glFrustumf);
#ifndef direct_glFrustumf
    PUSH_IF_COMPILING(glFrustumf)
#endif
    gles_glFrustumf(left, right, bottom, top, near, far);
}
void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) AliasExport("gl4es_glFrustumf");
#endif
#ifndef skip_glFrustumx
void gl4es_glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    LOAD_GLES(glFrustumx);
#ifndef direct_glFrustumx
    PUSH_IF_COMPILING(glFrustumx)
#endif
    gles_glFrustumx(left, right, bottom, top, near, far);
}
void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) AliasExport("gl4es_glFrustumx");
#endif
#ifndef skip_glGenBuffers
void gl4es_glGenBuffers(GLsizei n, GLuint * buffer) {
    LOAD_GLES(glGenBuffers);
#ifndef direct_glGenBuffers
    PUSH_IF_COMPILING(glGenBuffers)
#endif
    gles_glGenBuffers(n, buffer);
}
void glGenBuffers(GLsizei n, GLuint * buffer) AliasExport("gl4es_glGenBuffers");
#endif
#ifndef skip_glGenFramebuffers
void gl4es_glGenFramebuffers(GLsizei n, GLuint * ids) {
    LOAD_GLES_OES(glGenFramebuffers);
#ifndef direct_glGenFramebuffers
    PUSH_IF_COMPILING(glGenFramebuffers)
#endif
    gles_glGenFramebuffers(n, ids);
}
void glGenFramebuffers(GLsizei n, GLuint * ids) AliasExport("gl4es_glGenFramebuffers");
#endif
#ifndef skip_glGenRenderbuffers
void gl4es_glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    LOAD_GLES_OES(glGenRenderbuffers);
#ifndef direct_glGenRenderbuffers
    PUSH_IF_COMPILING(glGenRenderbuffers)
#endif
    gles_glGenRenderbuffers(n, renderbuffers);
}
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) AliasExport("gl4es_glGenRenderbuffers");
#endif
#ifndef skip_glGenTextures
void gl4es_glGenTextures(GLsizei n, GLuint * textures) {
    LOAD_GLES(glGenTextures);
#ifndef direct_glGenTextures
    PUSH_IF_COMPILING(glGenTextures)
#endif
    gles_glGenTextures(n, textures);
}
void glGenTextures(GLsizei n, GLuint * textures) AliasExport("gl4es_glGenTextures");
#endif
#ifndef skip_glGenerateMipmap
void gl4es_glGenerateMipmap(GLenum target) {
    LOAD_GLES_OES(glGenerateMipmap);
#ifndef direct_glGenerateMipmap
    PUSH_IF_COMPILING(glGenerateMipmap)
#endif
    gles_glGenerateMipmap(target);
}
void glGenerateMipmap(GLenum target) AliasExport("gl4es_glGenerateMipmap");
#endif
#ifndef skip_glGetActiveAttrib
void gl4es_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    LOAD_GLES(glGetActiveAttrib);
#ifndef direct_glGetActiveAttrib
    PUSH_IF_COMPILING(glGetActiveAttrib)
#endif
    gles_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) AliasExport("gl4es_glGetActiveAttrib");
#endif
#ifndef skip_glGetActiveUniform
void gl4es_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    LOAD_GLES(glGetActiveUniform);
#ifndef direct_glGetActiveUniform
    PUSH_IF_COMPILING(glGetActiveUniform)
#endif
    gles_glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) AliasExport("gl4es_glGetActiveUniform");
#endif
#ifndef skip_glGetAttachedShaders
void gl4es_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj) {
    LOAD_GLES(glGetAttachedShaders);
#ifndef direct_glGetAttachedShaders
    PUSH_IF_COMPILING(glGetAttachedShaders)
#endif
    gles_glGetAttachedShaders(program, maxCount, count, obj);
}
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj) AliasExport("gl4es_glGetAttachedShaders");
#endif
#ifndef skip_glGetAttribLocation
GLint gl4es_glGetAttribLocation(GLuint program, const GLchar * name) {
    LOAD_GLES(glGetAttribLocation);
#ifndef direct_glGetAttribLocation
    PUSH_IF_COMPILING(glGetAttribLocation)
#endif
    return gles_glGetAttribLocation(program, name);
}
GLint glGetAttribLocation(GLuint program, const GLchar * name) AliasExport("gl4es_glGetAttribLocation");
#endif
#ifndef skip_glGetBooleanv
void gl4es_glGetBooleanv(GLenum pname, GLboolean * params) {
    LOAD_GLES(glGetBooleanv);
#ifndef direct_glGetBooleanv
    PUSH_IF_COMPILING(glGetBooleanv)
#endif
    gles_glGetBooleanv(pname, params);
}
void glGetBooleanv(GLenum pname, GLboolean * params) AliasExport("gl4es_glGetBooleanv");
#endif
#ifndef skip_glGetBufferParameteriv
void gl4es_glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetBufferParameteriv);
#ifndef direct_glGetBufferParameteriv
    PUSH_IF_COMPILING(glGetBufferParameteriv)
#endif
    gles_glGetBufferParameteriv(target, pname, params);
}
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) AliasExport("gl4es_glGetBufferParameteriv");
#endif
#ifndef skip_glGetClipPlanef
void gl4es_glGetClipPlanef(GLenum plane, GLfloat * equation) {
    LOAD_GLES(glGetClipPlanef);
#ifndef direct_glGetClipPlanef
    PUSH_IF_COMPILING(glGetClipPlanef)
#endif
    gles_glGetClipPlanef(plane, equation);
}
void glGetClipPlanef(GLenum plane, GLfloat * equation) AliasExport("gl4es_glGetClipPlanef");
#endif
#ifndef skip_glGetClipPlanex
void gl4es_glGetClipPlanex(GLenum plane, GLfixed * equation) {
    LOAD_GLES(glGetClipPlanex);
#ifndef direct_glGetClipPlanex
    PUSH_IF_COMPILING(glGetClipPlanex)
#endif
    gles_glGetClipPlanex(plane, equation);
}
void glGetClipPlanex(GLenum plane, GLfixed * equation) AliasExport("gl4es_glGetClipPlanex");
#endif
#ifndef skip_glGetError
GLenum gl4es_glGetError() {
    LOAD_GLES(glGetError);
#ifndef direct_glGetError
    PUSH_IF_COMPILING(glGetError)
#endif
    return gles_glGetError();
}
GLenum glGetError() AliasExport("gl4es_glGetError");
#endif
#ifndef skip_glGetFixedv
void gl4es_glGetFixedv(GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetFixedv);
#ifndef direct_glGetFixedv
    PUSH_IF_COMPILING(glGetFixedv)
#endif
    gles_glGetFixedv(pname, params);
}
void glGetFixedv(GLenum pname, GLfixed * params) AliasExport("gl4es_glGetFixedv");
#endif
#ifndef skip_glGetFloatv
void gl4es_glGetFloatv(GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetFloatv);
#ifndef direct_glGetFloatv
    PUSH_IF_COMPILING(glGetFloatv)
#endif
    gles_glGetFloatv(pname, params);
}
void glGetFloatv(GLenum pname, GLfloat * params) AliasExport("gl4es_glGetFloatv");
#endif
#ifndef skip_glGetFramebufferAttachmentParameteriv
void gl4es_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    LOAD_GLES_OES(glGetFramebufferAttachmentParameteriv);
#ifndef direct_glGetFramebufferAttachmentParameteriv
    PUSH_IF_COMPILING(glGetFramebufferAttachmentParameteriv)
#endif
    gles_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) AliasExport("gl4es_glGetFramebufferAttachmentParameteriv");
#endif
#ifndef skip_glGetIntegerv
void gl4es_glGetIntegerv(GLenum pname, GLint * params) {
    LOAD_GLES(glGetIntegerv);
#ifndef direct_glGetIntegerv
    PUSH_IF_COMPILING(glGetIntegerv)
#endif
    gles_glGetIntegerv(pname, params);
}
void glGetIntegerv(GLenum pname, GLint * params) AliasExport("gl4es_glGetIntegerv");
#endif
#ifndef skip_glGetLightfv
void gl4es_glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetLightfv);
#ifndef direct_glGetLightfv
    PUSH_IF_COMPILING(glGetLightfv)
#endif
    gles_glGetLightfv(light, pname, params);
}
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) AliasExport("gl4es_glGetLightfv");
#endif
#ifndef skip_glGetLightxv
void gl4es_glGetLightxv(GLenum light, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetLightxv);
#ifndef direct_glGetLightxv
    PUSH_IF_COMPILING(glGetLightxv)
#endif
    gles_glGetLightxv(light, pname, params);
}
void glGetLightxv(GLenum light, GLenum pname, GLfixed * params) AliasExport("gl4es_glGetLightxv");
#endif
#ifndef skip_glGetMaterialfv
void gl4es_glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetMaterialfv);
#ifndef direct_glGetMaterialfv
    PUSH_IF_COMPILING(glGetMaterialfv)
#endif
    gles_glGetMaterialfv(face, pname, params);
}
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) AliasExport("gl4es_glGetMaterialfv");
#endif
#ifndef skip_glGetMaterialxv
void gl4es_glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetMaterialxv);
#ifndef direct_glGetMaterialxv
    PUSH_IF_COMPILING(glGetMaterialxv)
#endif
    gles_glGetMaterialxv(face, pname, params);
}
void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) AliasExport("gl4es_glGetMaterialxv");
#endif
#ifndef skip_glGetPointerv
void gl4es_glGetPointerv(GLenum pname, GLvoid ** params) {
    LOAD_GLES(glGetPointerv);
#ifndef direct_glGetPointerv
    PUSH_IF_COMPILING(glGetPointerv)
#endif
    gles_glGetPointerv(pname, params);
}
void glGetPointerv(GLenum pname, GLvoid ** params) AliasExport("gl4es_glGetPointerv");
#endif
#ifndef skip_glGetProgramBinary
void gl4es_glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, GLvoid * binary) {
    LOAD_GLES_OES(glGetProgramBinary);
#ifndef direct_glGetProgramBinary
    PUSH_IF_COMPILING(glGetProgramBinary)
#endif
    gles_glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, GLvoid * binary) AliasExport("gl4es_glGetProgramBinary");
#endif
#ifndef skip_glGetProgramInfoLog
void gl4es_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    LOAD_GLES(glGetProgramInfoLog);
#ifndef direct_glGetProgramInfoLog
    PUSH_IF_COMPILING(glGetProgramInfoLog)
#endif
    gles_glGetProgramInfoLog(program, bufSize, length, infoLog);
}
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) AliasExport("gl4es_glGetProgramInfoLog");
#endif
#ifndef skip_glGetProgramiv
void gl4es_glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    LOAD_GLES(glGetProgramiv);
#ifndef direct_glGetProgramiv
    PUSH_IF_COMPILING(glGetProgramiv)
#endif
    gles_glGetProgramiv(program, pname, params);
}
void glGetProgramiv(GLuint program, GLenum pname, GLint * params) AliasExport("gl4es_glGetProgramiv");
#endif
#ifndef skip_glGetRenderbufferParameteriv
void gl4es_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES_OES(glGetRenderbufferParameteriv);
#ifndef direct_glGetRenderbufferParameteriv
    PUSH_IF_COMPILING(glGetRenderbufferParameteriv)
#endif
    gles_glGetRenderbufferParameteriv(target, pname, params);
}
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) AliasExport("gl4es_glGetRenderbufferParameteriv");
#endif
#ifndef skip_glGetShaderInfoLog
void gl4es_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    LOAD_GLES(glGetShaderInfoLog);
#ifndef direct_glGetShaderInfoLog
    PUSH_IF_COMPILING(glGetShaderInfoLog)
#endif
    gles_glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) AliasExport("gl4es_glGetShaderInfoLog");
#endif
#ifndef skip_glGetShaderPrecisionFormat
void gl4es_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
    LOAD_GLES(glGetShaderPrecisionFormat);
#ifndef direct_glGetShaderPrecisionFormat
    PUSH_IF_COMPILING(glGetShaderPrecisionFormat)
#endif
    gles_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) AliasExport("gl4es_glGetShaderPrecisionFormat");
#endif
#ifndef skip_glGetShaderSource
void gl4es_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    LOAD_GLES(glGetShaderSource);
#ifndef direct_glGetShaderSource
    PUSH_IF_COMPILING(glGetShaderSource)
#endif
    gles_glGetShaderSource(shader, bufSize, length, source);
}
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) AliasExport("gl4es_glGetShaderSource");
#endif
#ifndef skip_glGetShaderiv
void gl4es_glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    LOAD_GLES(glGetShaderiv);
#ifndef direct_glGetShaderiv
    PUSH_IF_COMPILING(glGetShaderiv)
#endif
    gles_glGetShaderiv(shader, pname, params);
}
void glGetShaderiv(GLuint shader, GLenum pname, GLint * params) AliasExport("gl4es_glGetShaderiv");
#endif
#ifndef skip_glGetString
const GLubyte * gl4es_glGetString(GLenum name) {
    LOAD_GLES(glGetString);
#ifndef direct_glGetString
    PUSH_IF_COMPILING(glGetString)
#endif
    return gles_glGetString(name);
}
const GLubyte * glGetString(GLenum name) AliasExport("gl4es_glGetString");
#endif
#ifndef skip_glGetTexEnvfv
void gl4es_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetTexEnvfv);
#ifndef direct_glGetTexEnvfv
    PUSH_IF_COMPILING(glGetTexEnvfv)
#endif
    gles_glGetTexEnvfv(target, pname, params);
}
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) AliasExport("gl4es_glGetTexEnvfv");
#endif
#ifndef skip_glGetTexEnviv
void gl4es_glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetTexEnviv);
#ifndef direct_glGetTexEnviv
    PUSH_IF_COMPILING(glGetTexEnviv)
#endif
    gles_glGetTexEnviv(target, pname, params);
}
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) AliasExport("gl4es_glGetTexEnviv");
#endif
#ifndef skip_glGetTexEnvxv
void gl4es_glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetTexEnvxv);
#ifndef direct_glGetTexEnvxv
    PUSH_IF_COMPILING(glGetTexEnvxv)
#endif
    gles_glGetTexEnvxv(target, pname, params);
}
void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) AliasExport("gl4es_glGetTexEnvxv");
#endif
#ifndef skip_glGetTexParameterfv
void gl4es_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetTexParameterfv);
#ifndef direct_glGetTexParameterfv
    PUSH_IF_COMPILING(glGetTexParameterfv)
#endif
    gles_glGetTexParameterfv(target, pname, params);
}
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) AliasExport("gl4es_glGetTexParameterfv");
#endif
#ifndef skip_glGetTexParameteriv
void gl4es_glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetTexParameteriv);
#ifndef direct_glGetTexParameteriv
    PUSH_IF_COMPILING(glGetTexParameteriv)
#endif
    gles_glGetTexParameteriv(target, pname, params);
}
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) AliasExport("gl4es_glGetTexParameteriv");
#endif
#ifndef skip_glGetTexParameterxv
void gl4es_glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetTexParameterxv);
#ifndef direct_glGetTexParameterxv
    PUSH_IF_COMPILING(glGetTexParameterxv)
#endif
    gles_glGetTexParameterxv(target, pname, params);
}
void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) AliasExport("gl4es_glGetTexParameterxv");
#endif
#ifndef skip_glGetUniformLocation
GLint gl4es_glGetUniformLocation(GLuint program, const GLchar * name) {
    LOAD_GLES(glGetUniformLocation);
#ifndef direct_glGetUniformLocation
    PUSH_IF_COMPILING(glGetUniformLocation)
#endif
    return gles_glGetUniformLocation(program, name);
}
GLint glGetUniformLocation(GLuint program, const GLchar * name) AliasExport("gl4es_glGetUniformLocation");
#endif
#ifndef skip_glGetUniformfv
void gl4es_glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    LOAD_GLES(glGetUniformfv);
#ifndef direct_glGetUniformfv
    PUSH_IF_COMPILING(glGetUniformfv)
#endif
    gles_glGetUniformfv(program, location, params);
}
void glGetUniformfv(GLuint program, GLint location, GLfloat * params) AliasExport("gl4es_glGetUniformfv");
#endif
#ifndef skip_glGetUniformiv
void gl4es_glGetUniformiv(GLuint program, GLint location, GLint * params) {
    LOAD_GLES(glGetUniformiv);
#ifndef direct_glGetUniformiv
    PUSH_IF_COMPILING(glGetUniformiv)
#endif
    gles_glGetUniformiv(program, location, params);
}
void glGetUniformiv(GLuint program, GLint location, GLint * params) AliasExport("gl4es_glGetUniformiv");
#endif
#ifndef skip_glGetVertexAttribPointerv
void gl4es_glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) {
    LOAD_GLES(glGetVertexAttribPointerv);
#ifndef direct_glGetVertexAttribPointerv
    PUSH_IF_COMPILING(glGetVertexAttribPointerv)
#endif
    gles_glGetVertexAttribPointerv(index, pname, pointer);
}
void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) AliasExport("gl4es_glGetVertexAttribPointerv");
#endif
#ifndef skip_glGetVertexAttribfv
void gl4es_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetVertexAttribfv);
#ifndef direct_glGetVertexAttribfv
    PUSH_IF_COMPILING(glGetVertexAttribfv)
#endif
    gles_glGetVertexAttribfv(index, pname, params);
}
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) AliasExport("gl4es_glGetVertexAttribfv");
#endif
#ifndef skip_glGetVertexAttribiv
void gl4es_glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    LOAD_GLES(glGetVertexAttribiv);
#ifndef direct_glGetVertexAttribiv
    PUSH_IF_COMPILING(glGetVertexAttribiv)
#endif
    gles_glGetVertexAttribiv(index, pname, params);
}
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) AliasExport("gl4es_glGetVertexAttribiv");
#endif
#ifndef skip_glHint
void gl4es_glHint(GLenum target, GLenum mode) {
    LOAD_GLES(glHint);
#ifndef direct_glHint
    PUSH_IF_COMPILING(glHint)
#endif
    gles_glHint(target, mode);
}
void glHint(GLenum target, GLenum mode) AliasExport("gl4es_glHint");
#endif
#ifndef skip_glIsBuffer
GLboolean gl4es_glIsBuffer(GLuint buffer) {
    LOAD_GLES(glIsBuffer);
#ifndef direct_glIsBuffer
    PUSH_IF_COMPILING(glIsBuffer)
#endif
    return gles_glIsBuffer(buffer);
}
GLboolean glIsBuffer(GLuint buffer) AliasExport("gl4es_glIsBuffer");
#endif
#ifndef skip_glIsEnabled
GLboolean gl4es_glIsEnabled(GLenum cap) {
    LOAD_GLES(glIsEnabled);
#ifndef direct_glIsEnabled
    PUSH_IF_COMPILING(glIsEnabled)
#endif
    return gles_glIsEnabled(cap);
}
GLboolean glIsEnabled(GLenum cap) AliasExport("gl4es_glIsEnabled");
#endif
#ifndef skip_glIsFramebuffer
GLboolean gl4es_glIsFramebuffer(GLuint framebuffer) {
    LOAD_GLES_OES(glIsFramebuffer);
#ifndef direct_glIsFramebuffer
    PUSH_IF_COMPILING(glIsFramebuffer)
#endif
    return gles_glIsFramebuffer(framebuffer);
}
GLboolean glIsFramebuffer(GLuint framebuffer) AliasExport("gl4es_glIsFramebuffer");
#endif
#ifndef skip_glIsProgram
GLboolean gl4es_glIsProgram(GLuint program) {
    LOAD_GLES(glIsProgram);
#ifndef direct_glIsProgram
    PUSH_IF_COMPILING(glIsProgram)
#endif
    return gles_glIsProgram(program);
}
GLboolean glIsProgram(GLuint program) AliasExport("gl4es_glIsProgram");
#endif
#ifndef skip_glIsRenderbuffer
GLboolean gl4es_glIsRenderbuffer(GLuint renderbuffer) {
    LOAD_GLES_OES(glIsRenderbuffer);
#ifndef direct_glIsRenderbuffer
    PUSH_IF_COMPILING(glIsRenderbuffer)
#endif
    return gles_glIsRenderbuffer(renderbuffer);
}
GLboolean glIsRenderbuffer(GLuint renderbuffer) AliasExport("gl4es_glIsRenderbuffer");
#endif
#ifndef skip_glIsShader
GLboolean gl4es_glIsShader(GLuint shader) {
    LOAD_GLES(glIsShader);
#ifndef direct_glIsShader
    PUSH_IF_COMPILING(glIsShader)
#endif
    return gles_glIsShader(shader);
}
GLboolean glIsShader(GLuint shader) AliasExport("gl4es_glIsShader");
#endif
#ifndef skip_glIsTexture
GLboolean gl4es_glIsTexture(GLuint texture) {
    LOAD_GLES(glIsTexture);
#ifndef direct_glIsTexture
    PUSH_IF_COMPILING(glIsTexture)
#endif
    return gles_glIsTexture(texture);
}
GLboolean glIsTexture(GLuint texture) AliasExport("gl4es_glIsTexture");
#endif
#ifndef skip_glLightModelf
void gl4es_glLightModelf(GLenum pname, GLfloat param) {
    LOAD_GLES(glLightModelf);
#ifndef direct_glLightModelf
    PUSH_IF_COMPILING(glLightModelf)
#endif
    gles_glLightModelf(pname, param);
}
void glLightModelf(GLenum pname, GLfloat param) AliasExport("gl4es_glLightModelf");
#endif
#ifndef skip_glLightModelfv
void gl4es_glLightModelfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glLightModelfv);
#ifndef direct_glLightModelfv
    PUSH_IF_COMPILING(glLightModelfv)
#endif
    gles_glLightModelfv(pname, params);
}
void glLightModelfv(GLenum pname, const GLfloat * params) AliasExport("gl4es_glLightModelfv");
#endif
#ifndef skip_glLightModelx
void gl4es_glLightModelx(GLenum pname, GLfixed param) {
    LOAD_GLES(glLightModelx);
#ifndef direct_glLightModelx
    PUSH_IF_COMPILING(glLightModelx)
#endif
    gles_glLightModelx(pname, param);
}
void glLightModelx(GLenum pname, GLfixed param) AliasExport("gl4es_glLightModelx");
#endif
#ifndef skip_glLightModelxv
void gl4es_glLightModelxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glLightModelxv);
#ifndef direct_glLightModelxv
    PUSH_IF_COMPILING(glLightModelxv)
#endif
    gles_glLightModelxv(pname, params);
}
void glLightModelxv(GLenum pname, const GLfixed * params) AliasExport("gl4es_glLightModelxv");
#endif
#ifndef skip_glLightf
void gl4es_glLightf(GLenum light, GLenum pname, GLfloat param) {
    LOAD_GLES(glLightf);
#ifndef direct_glLightf
    PUSH_IF_COMPILING(glLightf)
#endif
    gles_glLightf(light, pname, param);
}
void glLightf(GLenum light, GLenum pname, GLfloat param) AliasExport("gl4es_glLightf");
#endif
#ifndef skip_glLightfv
void gl4es_glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glLightfv);
#ifndef direct_glLightfv
    PUSH_IF_COMPILING(glLightfv)
#endif
    gles_glLightfv(light, pname, params);
}
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) AliasExport("gl4es_glLightfv");
#endif
#ifndef skip_glLightx
void gl4es_glLightx(GLenum light, GLenum pname, GLfixed param) {
    LOAD_GLES(glLightx);
#ifndef direct_glLightx
    PUSH_IF_COMPILING(glLightx)
#endif
    gles_glLightx(light, pname, param);
}
void glLightx(GLenum light, GLenum pname, GLfixed param) AliasExport("gl4es_glLightx");
#endif
#ifndef skip_glLightxv
void gl4es_glLightxv(GLenum light, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glLightxv);
#ifndef direct_glLightxv
    PUSH_IF_COMPILING(glLightxv)
#endif
    gles_glLightxv(light, pname, params);
}
void glLightxv(GLenum light, GLenum pname, const GLfixed * params) AliasExport("gl4es_glLightxv");
#endif
#ifndef skip_glLineWidth
void gl4es_glLineWidth(GLfloat width) {
    LOAD_GLES(glLineWidth);
#ifndef direct_glLineWidth
    PUSH_IF_COMPILING(glLineWidth)
#endif
    gles_glLineWidth(width);
}
void glLineWidth(GLfloat width) AliasExport("gl4es_glLineWidth");
#endif
#ifndef skip_glLineWidthx
void gl4es_glLineWidthx(GLfixed width) {
    LOAD_GLES(glLineWidthx);
#ifndef direct_glLineWidthx
    PUSH_IF_COMPILING(glLineWidthx)
#endif
    gles_glLineWidthx(width);
}
void glLineWidthx(GLfixed width) AliasExport("gl4es_glLineWidthx");
#endif
#ifndef skip_glLinkProgram
void gl4es_glLinkProgram(GLuint program) {
    LOAD_GLES(glLinkProgram);
#ifndef direct_glLinkProgram
    PUSH_IF_COMPILING(glLinkProgram)
#endif
    gles_glLinkProgram(program);
}
void glLinkProgram(GLuint program) AliasExport("gl4es_glLinkProgram");
#endif
#ifndef skip_glLoadIdentity
void gl4es_glLoadIdentity() {
    LOAD_GLES(glLoadIdentity);
#ifndef direct_glLoadIdentity
    PUSH_IF_COMPILING(glLoadIdentity)
#endif
    gles_glLoadIdentity();
}
void glLoadIdentity() AliasExport("gl4es_glLoadIdentity");
#endif
#ifndef skip_glLoadMatrixf
void gl4es_glLoadMatrixf(const GLfloat * m) {
    LOAD_GLES(glLoadMatrixf);
#ifndef direct_glLoadMatrixf
    PUSH_IF_COMPILING(glLoadMatrixf)
#endif
    gles_glLoadMatrixf(m);
}
void glLoadMatrixf(const GLfloat * m) AliasExport("gl4es_glLoadMatrixf");
#endif
#ifndef skip_glLoadMatrixx
void gl4es_glLoadMatrixx(const GLfixed * m) {
    LOAD_GLES(glLoadMatrixx);
#ifndef direct_glLoadMatrixx
    PUSH_IF_COMPILING(glLoadMatrixx)
#endif
    gles_glLoadMatrixx(m);
}
void glLoadMatrixx(const GLfixed * m) AliasExport("gl4es_glLoadMatrixx");
#endif
#ifndef skip_glLogicOp
void gl4es_glLogicOp(GLenum opcode) {
    LOAD_GLES(glLogicOp);
#ifndef direct_glLogicOp
    PUSH_IF_COMPILING(glLogicOp)
#endif
    gles_glLogicOp(opcode);
}
void glLogicOp(GLenum opcode) AliasExport("gl4es_glLogicOp");
#endif
#ifndef skip_glMaterialf
void gl4es_glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    LOAD_GLES(glMaterialf);
#ifndef direct_glMaterialf
    PUSH_IF_COMPILING(glMaterialf)
#endif
    gles_glMaterialf(face, pname, param);
}
void glMaterialf(GLenum face, GLenum pname, GLfloat param) AliasExport("gl4es_glMaterialf");
#endif
#ifndef skip_glMaterialfv
void gl4es_glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glMaterialfv);
#ifndef direct_glMaterialfv
    PUSH_IF_COMPILING(glMaterialfv)
#endif
    gles_glMaterialfv(face, pname, params);
}
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) AliasExport("gl4es_glMaterialfv");
#endif
#ifndef skip_glMaterialx
void gl4es_glMaterialx(GLenum face, GLenum pname, GLfixed param) {
    LOAD_GLES(glMaterialx);
#ifndef direct_glMaterialx
    PUSH_IF_COMPILING(glMaterialx)
#endif
    gles_glMaterialx(face, pname, param);
}
void glMaterialx(GLenum face, GLenum pname, GLfixed param) AliasExport("gl4es_glMaterialx");
#endif
#ifndef skip_glMaterialxv
void gl4es_glMaterialxv(GLenum face, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glMaterialxv);
#ifndef direct_glMaterialxv
    PUSH_IF_COMPILING(glMaterialxv)
#endif
    gles_glMaterialxv(face, pname, params);
}
void glMaterialxv(GLenum face, GLenum pname, const GLfixed * params) AliasExport("gl4es_glMaterialxv");
#endif
#ifndef skip_glMatrixMode
void gl4es_glMatrixMode(GLenum mode) {
    LOAD_GLES(glMatrixMode);
#ifndef direct_glMatrixMode
    PUSH_IF_COMPILING(glMatrixMode)
#endif
    gles_glMatrixMode(mode);
}
void glMatrixMode(GLenum mode) AliasExport("gl4es_glMatrixMode");
#endif
#ifndef skip_glMultMatrixf
void gl4es_glMultMatrixf(const GLfloat * m) {
    LOAD_GLES(glMultMatrixf);
#ifndef direct_glMultMatrixf
    PUSH_IF_COMPILING(glMultMatrixf)
#endif
    gles_glMultMatrixf(m);
}
void glMultMatrixf(const GLfloat * m) AliasExport("gl4es_glMultMatrixf");
#endif
#ifndef skip_glMultMatrixx
void gl4es_glMultMatrixx(const GLfixed * m) {
    LOAD_GLES(glMultMatrixx);
#ifndef direct_glMultMatrixx
    PUSH_IF_COMPILING(glMultMatrixx)
#endif
    gles_glMultMatrixx(m);
}
void glMultMatrixx(const GLfixed * m) AliasExport("gl4es_glMultMatrixx");
#endif
#ifndef skip_glMultiDrawArrays
void gl4es_glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount) {
    LOAD_GLES_OES(glMultiDrawArrays);
#ifndef direct_glMultiDrawArrays
    PUSH_IF_COMPILING(glMultiDrawArrays)
#endif
    gles_glMultiDrawArrays(mode, first, count, primcount);
}
void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount) AliasExport("gl4es_glMultiDrawArrays");
#endif
#ifndef skip_glMultiDrawElements
void gl4es_glMultiDrawElements(GLenum mode, GLsizei * count, GLenum type, const void * const * indices, GLsizei primcount) {
    LOAD_GLES_OES(glMultiDrawElements);
#ifndef direct_glMultiDrawElements
    PUSH_IF_COMPILING(glMultiDrawElements)
#endif
    gles_glMultiDrawElements(mode, count, type, indices, primcount);
}
void glMultiDrawElements(GLenum mode, GLsizei * count, GLenum type, const void * const * indices, GLsizei primcount) AliasExport("gl4es_glMultiDrawElements");
#endif
#ifndef skip_glMultiTexCoord4f
void gl4es_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    LOAD_GLES(glMultiTexCoord4f);
#ifndef direct_glMultiTexCoord4f
    PUSH_IF_COMPILING(glMultiTexCoord4f)
#endif
    gles_glMultiTexCoord4f(target, s, t, r, q);
}
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) AliasExport("gl4es_glMultiTexCoord4f");
#endif
#ifndef skip_glMultiTexCoord4x
void gl4es_glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    LOAD_GLES(glMultiTexCoord4x);
#ifndef direct_glMultiTexCoord4x
    PUSH_IF_COMPILING(glMultiTexCoord4x)
#endif
    gles_glMultiTexCoord4x(target, s, t, r, q);
}
void glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) AliasExport("gl4es_glMultiTexCoord4x");
#endif
#ifndef skip_glNormal3f
void gl4es_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    LOAD_GLES(glNormal3f);
#ifndef direct_glNormal3f
    PUSH_IF_COMPILING(glNormal3f)
#endif
    gles_glNormal3f(nx, ny, nz);
}
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) AliasExport("gl4es_glNormal3f");
#endif
#ifndef skip_glNormal3x
void gl4es_glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
    LOAD_GLES(glNormal3x);
#ifndef direct_glNormal3x
    PUSH_IF_COMPILING(glNormal3x)
#endif
    gles_glNormal3x(nx, ny, nz);
}
void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) AliasExport("gl4es_glNormal3x");
#endif
#ifndef skip_glNormalPointer
void gl4es_glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glNormalPointer);
#ifndef direct_glNormalPointer
    PUSH_IF_COMPILING(glNormalPointer)
#endif
    gles_glNormalPointer(type, stride, pointer);
}
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glNormalPointer");
#endif
#ifndef skip_glOrthof
void gl4es_glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    LOAD_GLES(glOrthof);
#ifndef direct_glOrthof
    PUSH_IF_COMPILING(glOrthof)
#endif
    gles_glOrthof(left, right, bottom, top, near, far);
}
void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) AliasExport("gl4es_glOrthof");
#endif
#ifndef skip_glOrthox
void gl4es_glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    LOAD_GLES(glOrthox);
#ifndef direct_glOrthox
    PUSH_IF_COMPILING(glOrthox)
#endif
    gles_glOrthox(left, right, bottom, top, near, far);
}
void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) AliasExport("gl4es_glOrthox");
#endif
#ifndef skip_glPixelStorei
void gl4es_glPixelStorei(GLenum pname, GLint param) {
    LOAD_GLES(glPixelStorei);
#ifndef direct_glPixelStorei
    PUSH_IF_COMPILING(glPixelStorei)
#endif
    gles_glPixelStorei(pname, param);
}
void glPixelStorei(GLenum pname, GLint param) AliasExport("gl4es_glPixelStorei");
#endif
#ifndef skip_glPointParameterf
void gl4es_glPointParameterf(GLenum pname, GLfloat param) {
    LOAD_GLES(glPointParameterf);
#ifndef direct_glPointParameterf
    PUSH_IF_COMPILING(glPointParameterf)
#endif
    gles_glPointParameterf(pname, param);
}
void glPointParameterf(GLenum pname, GLfloat param) AliasExport("gl4es_glPointParameterf");
#endif
#ifndef skip_glPointParameterfv
void gl4es_glPointParameterfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glPointParameterfv);
#ifndef direct_glPointParameterfv
    PUSH_IF_COMPILING(glPointParameterfv)
#endif
    gles_glPointParameterfv(pname, params);
}
void glPointParameterfv(GLenum pname, const GLfloat * params) AliasExport("gl4es_glPointParameterfv");
#endif
#ifndef skip_glPointParameterx
void gl4es_glPointParameterx(GLenum pname, GLfixed param) {
    LOAD_GLES(glPointParameterx);
#ifndef direct_glPointParameterx
    PUSH_IF_COMPILING(glPointParameterx)
#endif
    gles_glPointParameterx(pname, param);
}
void glPointParameterx(GLenum pname, GLfixed param) AliasExport("gl4es_glPointParameterx");
#endif
#ifndef skip_glPointParameterxv
void gl4es_glPointParameterxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glPointParameterxv);
#ifndef direct_glPointParameterxv
    PUSH_IF_COMPILING(glPointParameterxv)
#endif
    gles_glPointParameterxv(pname, params);
}
void glPointParameterxv(GLenum pname, const GLfixed * params) AliasExport("gl4es_glPointParameterxv");
#endif
#ifndef skip_glPointSize
void gl4es_glPointSize(GLfloat size) {
    LOAD_GLES(glPointSize);
#ifndef direct_glPointSize
    PUSH_IF_COMPILING(glPointSize)
#endif
    gles_glPointSize(size);
}
void glPointSize(GLfloat size) AliasExport("gl4es_glPointSize");
#endif
#ifndef skip_glPointSizePointerOES
void gl4es_glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glPointSizePointerOES);
#ifndef direct_glPointSizePointerOES
    PUSH_IF_COMPILING(glPointSizePointerOES)
#endif
    gles_glPointSizePointerOES(type, stride, pointer);
}
void glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glPointSizePointerOES");
#endif
#ifndef skip_glPointSizex
void gl4es_glPointSizex(GLfixed size) {
    LOAD_GLES(glPointSizex);
#ifndef direct_glPointSizex
    PUSH_IF_COMPILING(glPointSizex)
#endif
    gles_glPointSizex(size);
}
void glPointSizex(GLfixed size) AliasExport("gl4es_glPointSizex");
#endif
#ifndef skip_glPolygonOffset
void gl4es_glPolygonOffset(GLfloat factor, GLfloat units) {
    LOAD_GLES(glPolygonOffset);
#ifndef direct_glPolygonOffset
    PUSH_IF_COMPILING(glPolygonOffset)
#endif
    gles_glPolygonOffset(factor, units);
}
void glPolygonOffset(GLfloat factor, GLfloat units) AliasExport("gl4es_glPolygonOffset");
#endif
#ifndef skip_glPolygonOffsetx
void gl4es_glPolygonOffsetx(GLfixed factor, GLfixed units) {
    LOAD_GLES(glPolygonOffsetx);
#ifndef direct_glPolygonOffsetx
    PUSH_IF_COMPILING(glPolygonOffsetx)
#endif
    gles_glPolygonOffsetx(factor, units);
}
void glPolygonOffsetx(GLfixed factor, GLfixed units) AliasExport("gl4es_glPolygonOffsetx");
#endif
#ifndef skip_glPopMatrix
void gl4es_glPopMatrix() {
    LOAD_GLES(glPopMatrix);
#ifndef direct_glPopMatrix
    PUSH_IF_COMPILING(glPopMatrix)
#endif
    gles_glPopMatrix();
}
void glPopMatrix() AliasExport("gl4es_glPopMatrix");
#endif
#ifndef skip_glProgramBinary
void gl4es_glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid * binary, GLint length) {
    LOAD_GLES_OES(glProgramBinary);
#ifndef direct_glProgramBinary
    PUSH_IF_COMPILING(glProgramBinary)
#endif
    gles_glProgramBinary(program, binaryFormat, binary, length);
}
void glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid * binary, GLint length) AliasExport("gl4es_glProgramBinary");
#endif
#ifndef skip_glPushMatrix
void gl4es_glPushMatrix() {
    LOAD_GLES(glPushMatrix);
#ifndef direct_glPushMatrix
    PUSH_IF_COMPILING(glPushMatrix)
#endif
    gles_glPushMatrix();
}
void glPushMatrix() AliasExport("gl4es_glPushMatrix");
#endif
#ifndef skip_glReadPixels
void gl4es_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    LOAD_GLES(glReadPixels);
#ifndef direct_glReadPixels
    PUSH_IF_COMPILING(glReadPixels)
#endif
    gles_glReadPixels(x, y, width, height, format, type, pixels);
}
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) AliasExport("gl4es_glReadPixels");
#endif
#ifndef skip_glReleaseShaderCompiler
void gl4es_glReleaseShaderCompiler() {
    LOAD_GLES(glReleaseShaderCompiler);
#ifndef direct_glReleaseShaderCompiler
    PUSH_IF_COMPILING(glReleaseShaderCompiler)
#endif
    gles_glReleaseShaderCompiler();
}
void glReleaseShaderCompiler() AliasExport("gl4es_glReleaseShaderCompiler");
#endif
#ifndef skip_glRenderbufferStorage
void gl4es_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    LOAD_GLES_OES(glRenderbufferStorage);
#ifndef direct_glRenderbufferStorage
    PUSH_IF_COMPILING(glRenderbufferStorage)
#endif
    gles_glRenderbufferStorage(target, internalformat, width, height);
}
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) AliasExport("gl4es_glRenderbufferStorage");
#endif
#ifndef skip_glRotatef
void gl4es_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glRotatef);
#ifndef direct_glRotatef
    PUSH_IF_COMPILING(glRotatef)
#endif
    gles_glRotatef(angle, x, y, z);
}
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glRotatef");
#endif
#ifndef skip_glRotatex
void gl4es_glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glRotatex);
#ifndef direct_glRotatex
    PUSH_IF_COMPILING(glRotatex)
#endif
    gles_glRotatex(angle, x, y, z);
}
void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) AliasExport("gl4es_glRotatex");
#endif
#ifndef skip_glSampleCoverage
void gl4es_glSampleCoverage(GLclampf value, GLboolean invert) {
    LOAD_GLES(glSampleCoverage);
#ifndef direct_glSampleCoverage
    PUSH_IF_COMPILING(glSampleCoverage)
#endif
    gles_glSampleCoverage(value, invert);
}
void glSampleCoverage(GLclampf value, GLboolean invert) AliasExport("gl4es_glSampleCoverage");
#endif
#ifndef skip_glSampleCoveragex
void gl4es_glSampleCoveragex(GLclampx value, GLboolean invert) {
    LOAD_GLES(glSampleCoveragex);
#ifndef direct_glSampleCoveragex
    PUSH_IF_COMPILING(glSampleCoveragex)
#endif
    gles_glSampleCoveragex(value, invert);
}
void glSampleCoveragex(GLclampx value, GLboolean invert) AliasExport("gl4es_glSampleCoveragex");
#endif
#ifndef skip_glScalef
void gl4es_glScalef(GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glScalef);
#ifndef direct_glScalef
    PUSH_IF_COMPILING(glScalef)
#endif
    gles_glScalef(x, y, z);
}
void glScalef(GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glScalef");
#endif
#ifndef skip_glScalex
void gl4es_glScalex(GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glScalex);
#ifndef direct_glScalex
    PUSH_IF_COMPILING(glScalex)
#endif
    gles_glScalex(x, y, z);
}
void glScalex(GLfixed x, GLfixed y, GLfixed z) AliasExport("gl4es_glScalex");
#endif
#ifndef skip_glScissor
void gl4es_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glScissor);
#ifndef direct_glScissor
    PUSH_IF_COMPILING(glScissor)
#endif
    gles_glScissor(x, y, width, height);
}
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glScissor");
#endif
#ifndef skip_glShadeModel
void gl4es_glShadeModel(GLenum mode) {
    LOAD_GLES(glShadeModel);
#ifndef direct_glShadeModel
    PUSH_IF_COMPILING(glShadeModel)
#endif
    gles_glShadeModel(mode);
}
void glShadeModel(GLenum mode) AliasExport("gl4es_glShadeModel");
#endif
#ifndef skip_glShaderBinary
void gl4es_glShaderBinary(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length) {
    LOAD_GLES(glShaderBinary);
#ifndef direct_glShaderBinary
    PUSH_IF_COMPILING(glShaderBinary)
#endif
    gles_glShaderBinary(n, shaders, binaryformat, binary, length);
}
void glShaderBinary(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length) AliasExport("gl4es_glShaderBinary");
#endif
#ifndef skip_glShaderSource
void gl4es_glShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length) {
    LOAD_GLES(glShaderSource);
#ifndef direct_glShaderSource
    PUSH_IF_COMPILING(glShaderSource)
#endif
    gles_glShaderSource(shader, count, string, length);
}
void glShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length) AliasExport("gl4es_glShaderSource");
#endif
#ifndef skip_glStencilFunc
void gl4es_glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    LOAD_GLES(glStencilFunc);
#ifndef direct_glStencilFunc
    PUSH_IF_COMPILING(glStencilFunc)
#endif
    gles_glStencilFunc(func, ref, mask);
}
void glStencilFunc(GLenum func, GLint ref, GLuint mask) AliasExport("gl4es_glStencilFunc");
#endif
#ifndef skip_glStencilFuncSeparate
void gl4es_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    LOAD_GLES(glStencilFuncSeparate);
#ifndef direct_glStencilFuncSeparate
    PUSH_IF_COMPILING(glStencilFuncSeparate)
#endif
    gles_glStencilFuncSeparate(face, func, ref, mask);
}
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) AliasExport("gl4es_glStencilFuncSeparate");
#endif
#ifndef skip_glStencilMask
void gl4es_glStencilMask(GLuint mask) {
    LOAD_GLES(glStencilMask);
#ifndef direct_glStencilMask
    PUSH_IF_COMPILING(glStencilMask)
#endif
    gles_glStencilMask(mask);
}
void glStencilMask(GLuint mask) AliasExport("gl4es_glStencilMask");
#endif
#ifndef skip_glStencilMaskSeparate
void gl4es_glStencilMaskSeparate(GLenum face, GLuint mask) {
    LOAD_GLES(glStencilMaskSeparate);
#ifndef direct_glStencilMaskSeparate
    PUSH_IF_COMPILING(glStencilMaskSeparate)
#endif
    gles_glStencilMaskSeparate(face, mask);
}
void glStencilMaskSeparate(GLenum face, GLuint mask) AliasExport("gl4es_glStencilMaskSeparate");
#endif
#ifndef skip_glStencilOp
void gl4es_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    LOAD_GLES(glStencilOp);
#ifndef direct_glStencilOp
    PUSH_IF_COMPILING(glStencilOp)
#endif
    gles_glStencilOp(fail, zfail, zpass);
}
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) AliasExport("gl4es_glStencilOp");
#endif
#ifndef skip_glStencilOpSeparate
void gl4es_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass) {
    LOAD_GLES(glStencilOpSeparate);
#ifndef direct_glStencilOpSeparate
    PUSH_IF_COMPILING(glStencilOpSeparate)
#endif
    gles_glStencilOpSeparate(face, sfail, zfail, zpass);
}
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass) AliasExport("gl4es_glStencilOpSeparate");
#endif
#ifndef skip_glTexCoordPointer
void gl4es_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glTexCoordPointer);
#ifndef direct_glTexCoordPointer
    PUSH_IF_COMPILING(glTexCoordPointer)
#endif
    gles_glTexCoordPointer(size, type, stride, pointer);
}
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glTexCoordPointer");
#endif
#ifndef skip_glTexEnvf
void gl4es_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(glTexEnvf);
#ifndef direct_glTexEnvf
    PUSH_IF_COMPILING(glTexEnvf)
#endif
    gles_glTexEnvf(target, pname, param);
}
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glTexEnvf");
#endif
#ifndef skip_glTexEnvfv
void gl4es_glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glTexEnvfv);
#ifndef direct_glTexEnvfv
    PUSH_IF_COMPILING(glTexEnvfv)
#endif
    gles_glTexEnvfv(target, pname, params);
}
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) AliasExport("gl4es_glTexEnvfv");
#endif
#ifndef skip_glTexEnvi
void gl4es_glTexEnvi(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(glTexEnvi);
#ifndef direct_glTexEnvi
    PUSH_IF_COMPILING(glTexEnvi)
#endif
    gles_glTexEnvi(target, pname, param);
}
void glTexEnvi(GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glTexEnvi");
#endif
#ifndef skip_glTexEnviv
void gl4es_glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    LOAD_GLES(glTexEnviv);
#ifndef direct_glTexEnviv
    PUSH_IF_COMPILING(glTexEnviv)
#endif
    gles_glTexEnviv(target, pname, params);
}
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) AliasExport("gl4es_glTexEnviv");
#endif
#ifndef skip_glTexEnvx
void gl4es_glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
    LOAD_GLES(glTexEnvx);
#ifndef direct_glTexEnvx
    PUSH_IF_COMPILING(glTexEnvx)
#endif
    gles_glTexEnvx(target, pname, param);
}
void glTexEnvx(GLenum target, GLenum pname, GLfixed param) AliasExport("gl4es_glTexEnvx");
#endif
#ifndef skip_glTexEnvxv
void gl4es_glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glTexEnvxv);
#ifndef direct_glTexEnvxv
    PUSH_IF_COMPILING(glTexEnvxv)
#endif
    gles_glTexEnvxv(target, pname, params);
}
void glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params) AliasExport("gl4es_glTexEnvxv");
#endif
#ifndef skip_glTexGenfv
void gl4es_glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    LOAD_GLES_OES(glTexGenfv);
#ifndef direct_glTexGenfv
    PUSH_IF_COMPILING(glTexGenfv)
#endif
    gles_glTexGenfv(coord, pname, params);
}
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) AliasExport("gl4es_glTexGenfv");
#endif
#ifndef skip_glTexGeni
void gl4es_glTexGeni(GLenum coord, GLenum pname, GLint param) {
    LOAD_GLES_OES(glTexGeni);
#ifndef direct_glTexGeni
    PUSH_IF_COMPILING(glTexGeni)
#endif
    gles_glTexGeni(coord, pname, param);
}
void glTexGeni(GLenum coord, GLenum pname, GLint param) AliasExport("gl4es_glTexGeni");
#endif
#ifndef skip_glTexImage2D
void gl4es_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data) {
    LOAD_GLES(glTexImage2D);
#ifndef direct_glTexImage2D
    PUSH_IF_COMPILING(glTexImage2D)
#endif
    gles_glTexImage2D(target, level, internalformat, width, height, border, format, type, data);
}
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data) AliasExport("gl4es_glTexImage2D");
#endif
#ifndef skip_glTexParameterf
void gl4es_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(glTexParameterf);
#ifndef direct_glTexParameterf
    PUSH_IF_COMPILING(glTexParameterf)
#endif
    gles_glTexParameterf(target, pname, param);
}
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glTexParameterf");
#endif
#ifndef skip_glTexParameterfv
void gl4es_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glTexParameterfv);
#ifndef direct_glTexParameterfv
    PUSH_IF_COMPILING(glTexParameterfv)
#endif
    gles_glTexParameterfv(target, pname, params);
}
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) AliasExport("gl4es_glTexParameterfv");
#endif
#ifndef skip_glTexParameteri
void gl4es_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(glTexParameteri);
#ifndef direct_glTexParameteri
    PUSH_IF_COMPILING(glTexParameteri)
#endif
    gles_glTexParameteri(target, pname, param);
}
void glTexParameteri(GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glTexParameteri");
#endif
#ifndef skip_glTexParameteriv
void gl4es_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    LOAD_GLES(glTexParameteriv);
#ifndef direct_glTexParameteriv
    PUSH_IF_COMPILING(glTexParameteriv)
#endif
    gles_glTexParameteriv(target, pname, params);
}
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) AliasExport("gl4es_glTexParameteriv");
#endif
#ifndef skip_glTexParameterx
void gl4es_glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
    LOAD_GLES(glTexParameterx);
#ifndef direct_glTexParameterx
    PUSH_IF_COMPILING(glTexParameterx)
#endif
    gles_glTexParameterx(target, pname, param);
}
void glTexParameterx(GLenum target, GLenum pname, GLfixed param) AliasExport("gl4es_glTexParameterx");
#endif
#ifndef skip_glTexParameterxv
void gl4es_glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glTexParameterxv);
#ifndef direct_glTexParameterxv
    PUSH_IF_COMPILING(glTexParameterxv)
#endif
    gles_glTexParameterxv(target, pname, params);
}
void glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params) AliasExport("gl4es_glTexParameterxv");
#endif
#ifndef skip_glTexSubImage2D
void gl4es_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * data) {
    LOAD_GLES(glTexSubImage2D);
#ifndef direct_glTexSubImage2D
    PUSH_IF_COMPILING(glTexSubImage2D)
#endif
    gles_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, data);
}
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * data) AliasExport("gl4es_glTexSubImage2D");
#endif
#ifndef skip_glTranslatef
void gl4es_glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glTranslatef);
#ifndef direct_glTranslatef
    PUSH_IF_COMPILING(glTranslatef)
#endif
    gles_glTranslatef(x, y, z);
}
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glTranslatef");
#endif
#ifndef skip_glTranslatex
void gl4es_glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glTranslatex);
#ifndef direct_glTranslatex
    PUSH_IF_COMPILING(glTranslatex)
#endif
    gles_glTranslatex(x, y, z);
}
void glTranslatex(GLfixed x, GLfixed y, GLfixed z) AliasExport("gl4es_glTranslatex");
#endif
#ifndef skip_glUniform1f
void gl4es_glUniform1f(GLint location, GLfloat v0) {
    LOAD_GLES(glUniform1f);
#ifndef direct_glUniform1f
    PUSH_IF_COMPILING(glUniform1f)
#endif
    gles_glUniform1f(location, v0);
}
void glUniform1f(GLint location, GLfloat v0) AliasExport("gl4es_glUniform1f");
#endif
#ifndef skip_glUniform1fv
void gl4es_glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(glUniform1fv);
#ifndef direct_glUniform1fv
    PUSH_IF_COMPILING(glUniform1fv)
#endif
    gles_glUniform1fv(location, count, value);
}
void glUniform1fv(GLint location, GLsizei count, const GLfloat * value) AliasExport("gl4es_glUniform1fv");
#endif
#ifndef skip_glUniform1i
void gl4es_glUniform1i(GLint location, GLint v0) {
    LOAD_GLES(glUniform1i);
#ifndef direct_glUniform1i
    PUSH_IF_COMPILING(glUniform1i)
#endif
    gles_glUniform1i(location, v0);
}
void glUniform1i(GLint location, GLint v0) AliasExport("gl4es_glUniform1i");
#endif
#ifndef skip_glUniform1iv
void gl4es_glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(glUniform1iv);
#ifndef direct_glUniform1iv
    PUSH_IF_COMPILING(glUniform1iv)
#endif
    gles_glUniform1iv(location, count, value);
}
void glUniform1iv(GLint location, GLsizei count, const GLint * value) AliasExport("gl4es_glUniform1iv");
#endif
#ifndef skip_glUniform2f
void gl4es_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    LOAD_GLES(glUniform2f);
#ifndef direct_glUniform2f
    PUSH_IF_COMPILING(glUniform2f)
#endif
    gles_glUniform2f(location, v0, v1);
}
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) AliasExport("gl4es_glUniform2f");
#endif
#ifndef skip_glUniform2fv
void gl4es_glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(glUniform2fv);
#ifndef direct_glUniform2fv
    PUSH_IF_COMPILING(glUniform2fv)
#endif
    gles_glUniform2fv(location, count, value);
}
void glUniform2fv(GLint location, GLsizei count, const GLfloat * value) AliasExport("gl4es_glUniform2fv");
#endif
#ifndef skip_glUniform2i
void gl4es_glUniform2i(GLint location, GLint v0, GLint v1) {
    LOAD_GLES(glUniform2i);
#ifndef direct_glUniform2i
    PUSH_IF_COMPILING(glUniform2i)
#endif
    gles_glUniform2i(location, v0, v1);
}
void glUniform2i(GLint location, GLint v0, GLint v1) AliasExport("gl4es_glUniform2i");
#endif
#ifndef skip_glUniform2iv
void gl4es_glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(glUniform2iv);
#ifndef direct_glUniform2iv
    PUSH_IF_COMPILING(glUniform2iv)
#endif
    gles_glUniform2iv(location, count, value);
}
void glUniform2iv(GLint location, GLsizei count, const GLint * value) AliasExport("gl4es_glUniform2iv");
#endif
#ifndef skip_glUniform3f
void gl4es_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    LOAD_GLES(glUniform3f);
#ifndef direct_glUniform3f
    PUSH_IF_COMPILING(glUniform3f)
#endif
    gles_glUniform3f(location, v0, v1, v2);
}
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) AliasExport("gl4es_glUniform3f");
#endif
#ifndef skip_glUniform3fv
void gl4es_glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(glUniform3fv);
#ifndef direct_glUniform3fv
    PUSH_IF_COMPILING(glUniform3fv)
#endif
    gles_glUniform3fv(location, count, value);
}
void glUniform3fv(GLint location, GLsizei count, const GLfloat * value) AliasExport("gl4es_glUniform3fv");
#endif
#ifndef skip_glUniform3i
void gl4es_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    LOAD_GLES(glUniform3i);
#ifndef direct_glUniform3i
    PUSH_IF_COMPILING(glUniform3i)
#endif
    gles_glUniform3i(location, v0, v1, v2);
}
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) AliasExport("gl4es_glUniform3i");
#endif
#ifndef skip_glUniform3iv
void gl4es_glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(glUniform3iv);
#ifndef direct_glUniform3iv
    PUSH_IF_COMPILING(glUniform3iv)
#endif
    gles_glUniform3iv(location, count, value);
}
void glUniform3iv(GLint location, GLsizei count, const GLint * value) AliasExport("gl4es_glUniform3iv");
#endif
#ifndef skip_glUniform4f
void gl4es_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    LOAD_GLES(glUniform4f);
#ifndef direct_glUniform4f
    PUSH_IF_COMPILING(glUniform4f)
#endif
    gles_glUniform4f(location, v0, v1, v2, v3);
}
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) AliasExport("gl4es_glUniform4f");
#endif
#ifndef skip_glUniform4fv
void gl4es_glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(glUniform4fv);
#ifndef direct_glUniform4fv
    PUSH_IF_COMPILING(glUniform4fv)
#endif
    gles_glUniform4fv(location, count, value);
}
void glUniform4fv(GLint location, GLsizei count, const GLfloat * value) AliasExport("gl4es_glUniform4fv");
#endif
#ifndef skip_glUniform4i
void gl4es_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    LOAD_GLES(glUniform4i);
#ifndef direct_glUniform4i
    PUSH_IF_COMPILING(glUniform4i)
#endif
    gles_glUniform4i(location, v0, v1, v2, v3);
}
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) AliasExport("gl4es_glUniform4i");
#endif
#ifndef skip_glUniform4iv
void gl4es_glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(glUniform4iv);
#ifndef direct_glUniform4iv
    PUSH_IF_COMPILING(glUniform4iv)
#endif
    gles_glUniform4iv(location, count, value);
}
void glUniform4iv(GLint location, GLsizei count, const GLint * value) AliasExport("gl4es_glUniform4iv");
#endif
#ifndef skip_glUniformMatrix2fv
void gl4es_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(glUniformMatrix2fv);
#ifndef direct_glUniformMatrix2fv
    PUSH_IF_COMPILING(glUniformMatrix2fv)
#endif
    gles_glUniformMatrix2fv(location, count, transpose, value);
}
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) AliasExport("gl4es_glUniformMatrix2fv");
#endif
#ifndef skip_glUniformMatrix3fv
void gl4es_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(glUniformMatrix3fv);
#ifndef direct_glUniformMatrix3fv
    PUSH_IF_COMPILING(glUniformMatrix3fv)
#endif
    gles_glUniformMatrix3fv(location, count, transpose, value);
}
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) AliasExport("gl4es_glUniformMatrix3fv");
#endif
#ifndef skip_glUniformMatrix4fv
void gl4es_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(glUniformMatrix4fv);
#ifndef direct_glUniformMatrix4fv
    PUSH_IF_COMPILING(glUniformMatrix4fv)
#endif
    gles_glUniformMatrix4fv(location, count, transpose, value);
}
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) AliasExport("gl4es_glUniformMatrix4fv");
#endif
#ifndef skip_glUseProgram
void gl4es_glUseProgram(GLuint program) {
    LOAD_GLES(glUseProgram);
#ifndef direct_glUseProgram
    PUSH_IF_COMPILING(glUseProgram)
#endif
    gles_glUseProgram(program);
}
void glUseProgram(GLuint program) AliasExport("gl4es_glUseProgram");
#endif
#ifndef skip_glValidateProgram
void gl4es_glValidateProgram(GLuint program) {
    LOAD_GLES(glValidateProgram);
#ifndef direct_glValidateProgram
    PUSH_IF_COMPILING(glValidateProgram)
#endif
    gles_glValidateProgram(program);
}
void glValidateProgram(GLuint program) AliasExport("gl4es_glValidateProgram");
#endif
#ifndef skip_glVertexAttrib1f
void gl4es_glVertexAttrib1f(GLuint index, GLfloat x) {
    LOAD_GLES(glVertexAttrib1f);
#ifndef direct_glVertexAttrib1f
    PUSH_IF_COMPILING(glVertexAttrib1f)
#endif
    gles_glVertexAttrib1f(index, x);
}
void glVertexAttrib1f(GLuint index, GLfloat x) AliasExport("gl4es_glVertexAttrib1f");
#endif
#ifndef skip_glVertexAttrib1fv
void gl4es_glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(glVertexAttrib1fv);
#ifndef direct_glVertexAttrib1fv
    PUSH_IF_COMPILING(glVertexAttrib1fv)
#endif
    gles_glVertexAttrib1fv(index, v);
}
void glVertexAttrib1fv(GLuint index, const GLfloat * v) AliasExport("gl4es_glVertexAttrib1fv");
#endif
#ifndef skip_glVertexAttrib2f
void gl4es_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    LOAD_GLES(glVertexAttrib2f);
#ifndef direct_glVertexAttrib2f
    PUSH_IF_COMPILING(glVertexAttrib2f)
#endif
    gles_glVertexAttrib2f(index, x, y);
}
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) AliasExport("gl4es_glVertexAttrib2f");
#endif
#ifndef skip_glVertexAttrib2fv
void gl4es_glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(glVertexAttrib2fv);
#ifndef direct_glVertexAttrib2fv
    PUSH_IF_COMPILING(glVertexAttrib2fv)
#endif
    gles_glVertexAttrib2fv(index, v);
}
void glVertexAttrib2fv(GLuint index, const GLfloat * v) AliasExport("gl4es_glVertexAttrib2fv");
#endif
#ifndef skip_glVertexAttrib3f
void gl4es_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glVertexAttrib3f);
#ifndef direct_glVertexAttrib3f
    PUSH_IF_COMPILING(glVertexAttrib3f)
#endif
    gles_glVertexAttrib3f(index, x, y, z);
}
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glVertexAttrib3f");
#endif
#ifndef skip_glVertexAttrib3fv
void gl4es_glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(glVertexAttrib3fv);
#ifndef direct_glVertexAttrib3fv
    PUSH_IF_COMPILING(glVertexAttrib3fv)
#endif
    gles_glVertexAttrib3fv(index, v);
}
void glVertexAttrib3fv(GLuint index, const GLfloat * v) AliasExport("gl4es_glVertexAttrib3fv");
#endif
#ifndef skip_glVertexAttrib4f
void gl4es_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    LOAD_GLES(glVertexAttrib4f);
#ifndef direct_glVertexAttrib4f
    PUSH_IF_COMPILING(glVertexAttrib4f)
#endif
    gles_glVertexAttrib4f(index, x, y, z, w);
}
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) AliasExport("gl4es_glVertexAttrib4f");
#endif
#ifndef skip_glVertexAttrib4fv
void gl4es_glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(glVertexAttrib4fv);
#ifndef direct_glVertexAttrib4fv
    PUSH_IF_COMPILING(glVertexAttrib4fv)
#endif
    gles_glVertexAttrib4fv(index, v);
}
void glVertexAttrib4fv(GLuint index, const GLfloat * v) AliasExport("gl4es_glVertexAttrib4fv");
#endif
#ifndef skip_glVertexAttribPointer
void gl4es_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glVertexAttribPointer);
#ifndef direct_glVertexAttribPointer
    PUSH_IF_COMPILING(glVertexAttribPointer)
#endif
    gles_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glVertexAttribPointer");
#endif
#ifndef skip_glVertexPointer
void gl4es_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glVertexPointer);
#ifndef direct_glVertexPointer
    PUSH_IF_COMPILING(glVertexPointer)
#endif
    gles_glVertexPointer(size, type, stride, pointer);
}
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glVertexPointer");
#endif
#ifndef skip_glViewport
void gl4es_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glViewport);
#ifndef direct_glViewport
    PUSH_IF_COMPILING(glViewport)
#endif
    gles_glViewport(x, y, width, height);
}
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glViewport");
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
        case FORMAT_void_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLuint_const_GLchar___GENPT__: {
            PACKED_void_GLuint_GLuint_const_GLchar___GENPT__ *unpacked = (PACKED_void_GLuint_GLuint_const_GLchar___GENPT__ *)packed;
            ARGS_void_GLuint_GLuint_const_GLchar___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint: {
            PACKED_void_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *)packed;
            ARGS_void_GLclampf_GLclampf_GLclampf_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
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
        case FORMAT_GLenum_GLenum: {
            PACKED_GLenum_GLenum *unpacked = (PACKED_GLenum_GLenum *)packed;
            ARGS_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLbitfield: {
            PACKED_void_GLbitfield *unpacked = (PACKED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            unpacked->func(args.a1);
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
        case FORMAT_void_GLuint: {
            PACKED_void_GLuint *unpacked = (PACKED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            unpacked->func(args.a1);
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
        case FORMAT_GLuint: {
            PACKED_GLuint *unpacked = (PACKED_GLuint *)packed;
            unpacked->func();
            break;
        }
        case FORMAT_GLuint_GLenum: {
            PACKED_GLuint_GLenum *unpacked = (PACKED_GLuint_GLenum *)packed;
            ARGS_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLsizei_const_GLuint___GENPT__: {
            PACKED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLsizei_GLuint___GENPT__: {
            PACKED_void_GLsizei_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
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
        case FORMAT_void_GLsizei_const_GLenum___GENPT__: {
            PACKED_void_GLsizei_const_GLenum___GENPT__ *unpacked = (PACKED_void_GLsizei_const_GLenum___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLenum___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void: {
            PACKED_void *unpacked = (PACKED_void *)packed;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLfloat: {
            PACKED_void_GLfloat *unpacked = (PACKED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_const_GLfloat___GENPT__: {
            PACKED_void_const_GLfloat___GENPT__ *unpacked = (PACKED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
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
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint: {
            PACKED_void_GLenum_GLenum_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint: {
            PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
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
        case FORMAT_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__: {
            PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ *unpacked = (PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ *)packed;
            ARGS_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__: {
            PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLint_GLuint_const_GLchar___GENPT__: {
            PACKED_GLint_GLuint_const_GLchar___GENPT__ *unpacked = (PACKED_GLint_GLuint_const_GLchar___GENPT__ *)packed;
            ARGS_GLint_GLuint_const_GLchar___GENPT__ args = unpacked->args;
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
        case FORMAT_void_GLenum_GLenum_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
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
        case FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLenum___GENPT___GLvoid___GENPT__: {
            PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLenum___GENPT___GLvoid___GENPT__ *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLenum___GENPT___GLvoid___GENPT__ *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLenum___GENPT___GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__: {
            PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint___GENPT__: {
            PACKED_void_GLuint_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_const_GLubyte___GENPT___GLenum: {
            PACKED_const_GLubyte___GENPT___GLenum *unpacked = (PACKED_const_GLubyte___GENPT___GLenum *)packed;
            ARGS_const_GLubyte___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLfloat___GENPT__: {
            PACKED_void_GLuint_GLint_GLfloat___GENPT__ *unpacked = (PACKED_void_GLuint_GLint_GLfloat___GENPT__ *)packed;
            ARGS_void_GLuint_GLint_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint___GENPT__: {
            PACKED_void_GLuint_GLint_GLint___GENPT__ *unpacked = (PACKED_void_GLuint_GLint_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLint_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLvoid___GENPT____GENPT__: {
            PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLuint_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
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
        case FORMAT_void_GLfixed: {
            PACKED_void_GLfixed *unpacked = (PACKED_void_GLfixed *)packed;
            ARGS_void_GLfixed args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_const_GLfixed___GENPT__: {
            PACKED_void_const_GLfixed___GENPT__ *unpacked = (PACKED_void_const_GLfixed___GENPT__ *)packed;
            ARGS_void_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei: {
            PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *unpacked = (PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei___GENPT___GLenum_const_void___GENPT___const___GENPT___GLsizei: {
            PACKED_void_GLenum_GLsizei___GENPT___GLenum_const_void___GENPT___const___GENPT___GLsizei *unpacked = (PACKED_void_GLenum_GLsizei___GENPT___GLenum_const_void___GENPT___const___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_GLsizei___GENPT___GLenum_const_void___GENPT___const___GENPT___GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
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
        case FORMAT_void_GLuint_GLenum_const_GLvoid___GENPT___GLint: {
            PACKED_void_GLuint_GLenum_const_GLvoid___GENPT___GLint *unpacked = (PACKED_void_GLuint_GLenum_const_GLvoid___GENPT___GLint *)packed;
            ARGS_void_GLuint_GLenum_const_GLvoid___GENPT___GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
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
        case FORMAT_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei: {
            PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei *unpacked = (PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__: {
            PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ *unpacked = (PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
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
        case FORMAT_void_GLint_GLfloat: {
            PACKED_void_GLint_GLfloat *unpacked = (PACKED_void_GLint_GLfloat *)packed;
            ARGS_void_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_const_GLfloat___GENPT__: {
            PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLint_GLsizei_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLint: {
            PACKED_void_GLint_GLint *unpacked = (PACKED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_const_GLint___GENPT__: {
            PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *unpacked = (PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *)packed;
            ARGS_void_GLint_GLsizei_const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__: {
            PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLfloat: {
            PACKED_void_GLuint_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_const_GLfloat___GENPT__: {
            PACKED_void_GLuint_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLuint_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLuint_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
    }
}
/*
packed_call_t* glCopyPackedCall(const packed_call_t *packed) {
    switch (packed->format) {
        case FORMAT_void_GLenum: {
            int sizeofpacked = sizeof(PACKED_void_GLenum);
            PACKED_void_GLenum *newpacked = (PACKED_void_GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLclampf: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLclampf);
            PACKED_void_GLenum_GLclampf *newpacked = (PACKED_void_GLenum_GLclampf*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLclampx: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLclampx);
            PACKED_void_GLenum_GLclampx *newpacked = (PACKED_void_GLenum_GLclampx*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLuint: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLuint);
            PACKED_void_GLuint_GLuint *newpacked = (PACKED_void_GLuint_GLuint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLuint_const_GLchar___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLuint_const_GLchar___GENPT__);
            PACKED_void_GLuint_GLuint_const_GLchar___GENPT__ *newpacked = (PACKED_void_GLuint_GLuint_const_GLchar___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLuint: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLuint);
            PACKED_void_GLenum_GLuint *newpacked = (PACKED_void_GLenum_GLuint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf: {
            int sizeofpacked = sizeof(PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf);
            PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *newpacked = (PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum);
            PACKED_void_GLenum_GLenum *newpacked = (PACKED_void_GLenum_GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLenum_GLenum);
            PACKED_void_GLenum_GLenum_GLenum_GLenum *newpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum);
            PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *newpacked = (PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__);
            PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_GLenum_GLenum: {
            int sizeofpacked = sizeof(PACKED_GLenum_GLenum);
            PACKED_GLenum_GLenum *newpacked = (PACKED_GLenum_GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLbitfield: {
            int sizeofpacked = sizeof(PACKED_void_GLbitfield);
            PACKED_void_GLbitfield *newpacked = (PACKED_void_GLbitfield*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLclampx_GLclampx_GLclampx_GLclampx: {
            int sizeofpacked = sizeof(PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx);
            PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *newpacked = (PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLclampf: {
            int sizeofpacked = sizeof(PACKED_void_GLclampf);
            PACKED_void_GLclampf *newpacked = (PACKED_void_GLclampf*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLclampx: {
            int sizeofpacked = sizeof(PACKED_void_GLclampx);
            PACKED_void_GLclampx *newpacked = (PACKED_void_GLclampx*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLint);
            PACKED_void_GLint *newpacked = (PACKED_void_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_const_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__);
            PACKED_void_GLenum_const_GLfloat___GENPT__ *newpacked = (PACKED_void_GLenum_const_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_const_GLfixed___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__);
            PACKED_void_GLenum_const_GLfixed___GENPT__ *newpacked = (PACKED_void_GLenum_const_GLfixed___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte: {
            int sizeofpacked = sizeof(PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte);
            PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *newpacked = (PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed: {
            int sizeofpacked = sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed);
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *newpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean: {
            int sizeofpacked = sizeof(PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean);
            PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *newpacked = (PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__);
            PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint: {
            int sizeofpacked = sizeof(PACKED_void_GLuint);
            PACKED_void_GLuint *newpacked = (PACKED_void_GLuint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__);
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__);
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint);
            PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *newpacked = (PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei);
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *newpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_GLuint: {
            int sizeofpacked = sizeof(PACKED_GLuint);
            PACKED_GLuint *newpacked = (PACKED_GLuint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_GLuint_GLenum: {
            int sizeofpacked = sizeof(PACKED_GLuint_GLenum);
            PACKED_GLuint_GLenum *newpacked = (PACKED_GLuint_GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLsizei_const_GLuint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__);
            PACKED_void_GLsizei_const_GLuint___GENPT__ *newpacked = (PACKED_void_GLsizei_const_GLuint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLsizei_GLuint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLsizei_GLuint___GENPT__);
            PACKED_void_GLsizei_GLuint___GENPT__ *newpacked = (PACKED_void_GLsizei_GLuint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLboolean: {
            int sizeofpacked = sizeof(PACKED_void_GLboolean);
            PACKED_void_GLboolean *newpacked = (PACKED_void_GLboolean*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLclampf_GLclampf: {
            int sizeofpacked = sizeof(PACKED_void_GLclampf_GLclampf);
            PACKED_void_GLclampf_GLclampf *newpacked = (PACKED_void_GLclampf_GLclampf*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLclampx_GLclampx: {
            int sizeofpacked = sizeof(PACKED_void_GLclampx_GLclampx);
            PACKED_void_GLclampx_GLclampx *newpacked = (PACKED_void_GLclampx_GLclampx*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint_GLsizei: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint_GLsizei);
            PACKED_void_GLenum_GLint_GLsizei *newpacked = (PACKED_void_GLenum_GLint_GLsizei*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLsizei_const_GLenum___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLsizei_const_GLenum___GENPT__);
            PACKED_void_GLsizei_const_GLenum___GENPT__ *newpacked = (PACKED_void_GLsizei_const_GLenum___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__);
            PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLint_GLint_GLint_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLint_GLint_GLint_GLint);
            PACKED_void_GLint_GLint_GLint_GLint_GLint *newpacked = (PACKED_void_GLint_GLint_GLint_GLint_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void: {
            int sizeofpacked = sizeof(PACKED_void);
            PACKED_void *newpacked = (PACKED_void*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__);
            PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLfloat);
            PACKED_void_GLfloat *newpacked = (PACKED_void_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_const_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_const_GLfloat___GENPT__);
            PACKED_void_const_GLfloat___GENPT__ *newpacked = (PACKED_void_const_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLfloat);
            PACKED_void_GLenum_GLfloat *newpacked = (PACKED_void_GLenum_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLfixed: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLfixed);
            PACKED_void_GLenum_GLfixed *newpacked = (PACKED_void_GLenum_GLfixed*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLenum_GLuint);
            PACKED_void_GLenum_GLenum_GLenum_GLuint *newpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint);
            PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint *newpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed: {
            int sizeofpacked = sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed);
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *newpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__);
            PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ *newpacked = (PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__);
            PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ *newpacked = (PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_GLint_GLuint_const_GLchar___GENPT__: {
            int sizeofpacked = sizeof(PACKED_GLint_GLuint_const_GLchar___GENPT__);
            PACKED_GLint_GLuint_const_GLchar___GENPT__ *newpacked = (PACKED_GLint_GLuint_const_GLchar___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLboolean___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLboolean___GENPT__);
            PACKED_void_GLenum_GLboolean___GENPT__ *newpacked = (PACKED_void_GLenum_GLboolean___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__);
            PACKED_void_GLenum_GLenum_GLint___GENPT__ *newpacked = (PACKED_void_GLenum_GLenum_GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLfloat___GENPT__);
            PACKED_void_GLenum_GLfloat___GENPT__ *newpacked = (PACKED_void_GLenum_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLfixed___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLfixed___GENPT__);
            PACKED_void_GLenum_GLfixed___GENPT__ *newpacked = (PACKED_void_GLenum_GLfixed___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_GLenum: {
            int sizeofpacked = sizeof(PACKED_GLenum);
            PACKED_GLenum *newpacked = (PACKED_GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__);
            PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__ *newpacked = (PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint___GENPT__);
            PACKED_void_GLenum_GLint___GENPT__ *newpacked = (PACKED_void_GLenum_GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__);
            PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *newpacked = (PACKED_void_GLenum_GLenum_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfixed___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__);
            PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *newpacked = (PACKED_void_GLenum_GLenum_GLfixed___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLvoid___GENPT____GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLvoid___GENPT____GENPT__);
            PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *newpacked = (PACKED_void_GLenum_GLvoid___GENPT____GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLenum___GENPT___GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLenum___GENPT___GLvoid___GENPT__);
            PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLenum___GENPT___GLvoid___GENPT__ *newpacked = (PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLenum___GENPT___GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__);
            PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ *newpacked = (PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLenum_GLint___GENPT__);
            PACKED_void_GLuint_GLenum_GLint___GENPT__ *newpacked = (PACKED_void_GLuint_GLenum_GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__);
            PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ *newpacked = (PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_const_GLubyte___GENPT___GLenum: {
            int sizeofpacked = sizeof(PACKED_const_GLubyte___GENPT___GLenum);
            PACKED_const_GLubyte___GENPT___GLenum *newpacked = (PACKED_const_GLubyte___GENPT___GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLint_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLint_GLfloat___GENPT__);
            PACKED_void_GLuint_GLint_GLfloat___GENPT__ *newpacked = (PACKED_void_GLuint_GLint_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLint_GLint___GENPT__);
            PACKED_void_GLuint_GLint_GLint___GENPT__ *newpacked = (PACKED_void_GLuint_GLint_GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLvoid___GENPT____GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__);
            PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ *newpacked = (PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLenum_GLfloat___GENPT__);
            PACKED_void_GLuint_GLenum_GLfloat___GENPT__ *newpacked = (PACKED_void_GLuint_GLenum_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_GLboolean_GLuint: {
            int sizeofpacked = sizeof(PACKED_GLboolean_GLuint);
            PACKED_GLboolean_GLuint *newpacked = (PACKED_GLboolean_GLuint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_GLboolean_GLenum: {
            int sizeofpacked = sizeof(PACKED_GLboolean_GLenum);
            PACKED_GLboolean_GLenum *newpacked = (PACKED_GLboolean_GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLfloat);
            PACKED_void_GLenum_GLenum_GLfloat *newpacked = (PACKED_void_GLenum_GLenum_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__);
            PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *newpacked = (PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfixed: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLfixed);
            PACKED_void_GLenum_GLenum_GLfixed *newpacked = (PACKED_void_GLenum_GLenum_GLfixed*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__);
            PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *newpacked = (PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfixed: {
            int sizeofpacked = sizeof(PACKED_void_GLfixed);
            PACKED_void_GLfixed *newpacked = (PACKED_void_GLfixed*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_const_GLfixed___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_const_GLfixed___GENPT__);
            PACKED_void_const_GLfixed___GENPT__ *newpacked = (PACKED_void_const_GLfixed___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei);
            PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *newpacked = (PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLsizei___GENPT___GLenum_const_void___GENPT___const___GENPT___GLsizei: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLsizei___GENPT___GLenum_const_void___GENPT___const___GENPT___GLsizei);
            PACKED_void_GLenum_GLsizei___GENPT___GLenum_const_void___GENPT___const___GENPT___GLsizei *newpacked = (PACKED_void_GLenum_GLsizei___GENPT___GLenum_const_void___GENPT___const___GENPT___GLsizei*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed);
            PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *newpacked = (PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed: {
            int sizeofpacked = sizeof(PACKED_void_GLfixed_GLfixed_GLfixed);
            PACKED_void_GLfixed_GLfixed_GLfixed *newpacked = (PACKED_void_GLfixed_GLfixed_GLfixed*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint);
            PACKED_void_GLenum_GLint *newpacked = (PACKED_void_GLenum_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLfloat_GLfloat);
            PACKED_void_GLfloat_GLfloat *newpacked = (PACKED_void_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLfixed_GLfixed: {
            int sizeofpacked = sizeof(PACKED_void_GLfixed_GLfixed);
            PACKED_void_GLfixed_GLfixed *newpacked = (PACKED_void_GLfixed_GLfixed*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLenum_const_GLvoid___GENPT___GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLenum_const_GLvoid___GENPT___GLint);
            PACKED_void_GLuint_GLenum_const_GLvoid___GENPT___GLint *newpacked = (PACKED_void_GLuint_GLenum_const_GLvoid___GENPT___GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__);
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *newpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLsizei_GLsizei);
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei *newpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLclampf_GLboolean: {
            int sizeofpacked = sizeof(PACKED_void_GLclampf_GLboolean);
            PACKED_void_GLclampf_GLboolean *newpacked = (PACKED_void_GLclampf_GLboolean*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLclampx_GLboolean: {
            int sizeofpacked = sizeof(PACKED_void_GLclampx_GLboolean);
            PACKED_void_GLclampx_GLboolean *newpacked = (PACKED_void_GLclampx_GLboolean*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei);
            PACKED_void_GLint_GLint_GLsizei_GLsizei *newpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei: {
            int sizeofpacked = sizeof(PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei);
            PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei *newpacked = (PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__);
            PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ *newpacked = (PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint_GLuint: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint_GLuint);
            PACKED_void_GLenum_GLint_GLuint *newpacked = (PACKED_void_GLenum_GLint_GLuint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLuint: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLint_GLuint);
            PACKED_void_GLenum_GLenum_GLint_GLuint *newpacked = (PACKED_void_GLenum_GLenum_GLint_GLuint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLenum);
            PACKED_void_GLenum_GLenum_GLenum *newpacked = (PACKED_void_GLenum_GLenum_GLenum*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_GLint);
            PACKED_void_GLenum_GLenum_GLint *newpacked = (PACKED_void_GLenum_GLenum_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__);
            PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *newpacked = (PACKED_void_GLenum_GLenum_const_GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__);
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__);
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLfloat);
            PACKED_void_GLint_GLfloat *newpacked = (PACKED_void_GLint_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLsizei_const_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__);
            PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *newpacked = (PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLint);
            PACKED_void_GLint_GLint *newpacked = (PACKED_void_GLint_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLsizei_const_GLint___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLsizei_const_GLint___GENPT__);
            PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *newpacked = (PACKED_void_GLint_GLsizei_const_GLint___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLfloat_GLfloat);
            PACKED_void_GLint_GLfloat_GLfloat *newpacked = (PACKED_void_GLint_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLint_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLint_GLint);
            PACKED_void_GLint_GLint_GLint *newpacked = (PACKED_void_GLint_GLint_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLint_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLint_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLint_GLint_GLint: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLint_GLint_GLint);
            PACKED_void_GLint_GLint_GLint_GLint *newpacked = (PACKED_void_GLint_GLint_GLint_GLint*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__);
            PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ *newpacked = (PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLfloat);
            PACKED_void_GLuint_GLfloat *newpacked = (PACKED_void_GLuint_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_const_GLfloat___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_const_GLfloat___GENPT__);
            PACKED_void_GLuint_const_GLfloat___GENPT__ *newpacked = (PACKED_void_GLuint_const_GLfloat___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLfloat_GLfloat);
            PACKED_void_GLuint_GLfloat_GLfloat *newpacked = (PACKED_void_GLuint_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat);
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *newpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__: {
            int sizeofpacked = sizeof(PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__);
            PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ *newpacked = (PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__*)malloc(sizeofpacked);
            memcpy(newpacked, packed, sizeofpacked);
            return (packed_call_t*)newpacked;
            break;
        }
    }
}*/
