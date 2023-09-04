#include "../host.h"
#include "gles.h"
#include "../gl4es.h"
#include "../loader.h"
#include "skips.h"
#ifndef skip_glActiveTexture
void APIENTRY_GL4ES gl4es_glActiveTexture(GLenum texture) {
    
#ifndef direct_glActiveTexture
    PUSH_IF_COMPILING(glActiveTexture)
#endif
    host_functions.glActiveTexture(texture);
}
AliasExport(void,glActiveTexture,,(GLenum texture));
#endif
#ifndef skip_glAlphaFunc
void APIENTRY_GL4ES gl4es_glAlphaFunc(GLenum func, GLclampf ref) {
    
#ifndef direct_glAlphaFunc
    PUSH_IF_COMPILING(glAlphaFunc)
#endif
    host_functions.glAlphaFunc(func, ref);
}
AliasExport(void,glAlphaFunc,,(GLenum func, GLclampf ref));
#endif
#ifndef skip_glAlphaFuncx
void APIENTRY_GL4ES gl4es_glAlphaFuncx(GLenum func, GLclampx ref) {
    
#ifndef direct_glAlphaFuncx
    PUSH_IF_COMPILING(glAlphaFuncx)
#endif
    host_functions.glAlphaFuncx(func, ref);
}
AliasExport(void,glAlphaFuncx,,(GLenum func, GLclampx ref));
#endif
#ifndef skip_glAttachShader
void APIENTRY_GL4ES gl4es_glAttachShader(GLuint program, GLuint shader) {
    
#ifndef direct_glAttachShader
    PUSH_IF_COMPILING(glAttachShader)
#endif
    host_functions.glAttachShader(program, shader);
}
AliasExport(void,glAttachShader,,(GLuint program, GLuint shader));
#endif
#ifndef skip_glBindAttribLocation
void APIENTRY_GL4ES gl4es_glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    
#ifndef direct_glBindAttribLocation
    PUSH_IF_COMPILING(glBindAttribLocation)
#endif
    host_functions.glBindAttribLocation(program, index, name);
}
AliasExport(void,glBindAttribLocation,,(GLuint program, GLuint index, const GLchar * name));
#endif
#ifndef skip_glBindBuffer
void APIENTRY_GL4ES gl4es_glBindBuffer(GLenum target, GLuint buffer) {
    
#ifndef direct_glBindBuffer
    PUSH_IF_COMPILING(glBindBuffer)
#endif
    host_functions.glBindBuffer(target, buffer);
}
AliasExport(void,glBindBuffer,,(GLenum target, GLuint buffer));
#endif
#ifndef skip_glBindFramebuffer
void APIENTRY_GL4ES gl4es_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    
#ifndef direct_glBindFramebuffer
    PUSH_IF_COMPILING(glBindFramebuffer)
#endif
    host_functions.glBindFramebuffer(target, framebuffer);
}
AliasExport(void,glBindFramebuffer,,(GLenum target, GLuint framebuffer));
#endif
#ifndef skip_glBindRenderbuffer
void APIENTRY_GL4ES gl4es_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    
#ifndef direct_glBindRenderbuffer
    PUSH_IF_COMPILING(glBindRenderbuffer)
#endif
    host_functions.glBindRenderbuffer(target, renderbuffer);
}
AliasExport(void,glBindRenderbuffer,,(GLenum target, GLuint renderbuffer));
#endif
#ifndef skip_glBindTexture
void APIENTRY_GL4ES gl4es_glBindTexture(GLenum target, GLuint texture) {
    
#ifndef direct_glBindTexture
    PUSH_IF_COMPILING(glBindTexture)
#endif
    host_functions.glBindTexture(target, texture);
}
AliasExport(void,glBindTexture,,(GLenum target, GLuint texture));
#endif
#ifndef skip_glBlendColor
void APIENTRY_GL4ES gl4es_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    
#ifndef direct_glBlendColor
    PUSH_IF_COMPILING(glBlendColor)
#endif
    host_functions.glBlendColor(red, green, blue, alpha);
}
AliasExport(void,glBlendColor,,(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha));
#endif
#ifndef skip_glBlendEquation
void APIENTRY_GL4ES gl4es_glBlendEquation(GLenum mode) {
    
#ifndef direct_glBlendEquation
    PUSH_IF_COMPILING(glBlendEquation)
#endif
    host_functions.glBlendEquation(mode);
}
AliasExport(void,glBlendEquation,,(GLenum mode));
#endif
#ifndef skip_glBlendEquationSeparate
void APIENTRY_GL4ES gl4es_glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    
#ifndef direct_glBlendEquationSeparate
    PUSH_IF_COMPILING(glBlendEquationSeparate)
#endif
    host_functions.glBlendEquationSeparate(modeRGB, modeA);
}
AliasExport(void,glBlendEquationSeparate,,(GLenum modeRGB, GLenum modeA));
#endif
#ifndef skip_glBlendFunc
void APIENTRY_GL4ES gl4es_glBlendFunc(GLenum sfactor, GLenum dfactor) {
    
#ifndef direct_glBlendFunc
    PUSH_IF_COMPILING(glBlendFunc)
#endif
    host_functions.glBlendFunc(sfactor, dfactor);
}
AliasExport(void,glBlendFunc,,(GLenum sfactor, GLenum dfactor));
#endif
#ifndef skip_glBlendFuncSeparate
void APIENTRY_GL4ES gl4es_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    
#ifndef direct_glBlendFuncSeparate
    PUSH_IF_COMPILING(glBlendFuncSeparate)
#endif
    host_functions.glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
AliasExport(void,glBlendFuncSeparate,,(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha));
#endif
#ifndef skip_glBufferData
void APIENTRY_GL4ES gl4es_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    
#ifndef direct_glBufferData
    PUSH_IF_COMPILING(glBufferData)
#endif
    host_functions.glBufferData(target, size, data, usage);
}
AliasExport(void,glBufferData,,(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage));
#endif
#ifndef skip_glBufferSubData
void APIENTRY_GL4ES gl4es_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    
#ifndef direct_glBufferSubData
    PUSH_IF_COMPILING(glBufferSubData)
#endif
    host_functions.glBufferSubData(target, offset, size, data);
}
AliasExport(void,glBufferSubData,,(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data));
#endif
#ifndef skip_glCheckFramebufferStatus
GLenum APIENTRY_GL4ES gl4es_glCheckFramebufferStatus(GLenum target) {
    
#ifndef direct_glCheckFramebufferStatus
    PUSH_IF_COMPILING(glCheckFramebufferStatus)
#endif
    return host_functions.glCheckFramebufferStatus(target);
}
AliasExport(GLenum,glCheckFramebufferStatus,,(GLenum target));
#endif
#ifndef skip_glClear
void APIENTRY_GL4ES gl4es_glClear(GLbitfield mask) {
    
#ifndef direct_glClear
    PUSH_IF_COMPILING(glClear)
#endif
    host_functions.glClear(mask);
}
AliasExport(void,glClear,,(GLbitfield mask));
#endif
#ifndef skip_glClearColor
void APIENTRY_GL4ES gl4es_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    
#ifndef direct_glClearColor
    PUSH_IF_COMPILING(glClearColor)
#endif
    host_functions.glClearColor(red, green, blue, alpha);
}
AliasExport(void,glClearColor,,(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha));
#endif
#ifndef skip_glClearColorx
void APIENTRY_GL4ES gl4es_glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) {
    
#ifndef direct_glClearColorx
    PUSH_IF_COMPILING(glClearColorx)
#endif
    host_functions.glClearColorx(red, green, blue, alpha);
}
AliasExport(void,glClearColorx,,(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha));
#endif
#ifndef skip_glClearDepthf
void APIENTRY_GL4ES gl4es_glClearDepthf(GLclampf depth) {
    
#ifndef direct_glClearDepthf
    PUSH_IF_COMPILING(glClearDepthf)
#endif
    host_functions.glClearDepthf(depth);
}
AliasExport(void,glClearDepthf,,(GLclampf depth));
#endif
#ifndef skip_glClearDepthx
void APIENTRY_GL4ES gl4es_glClearDepthx(GLclampx depth) {
    
#ifndef direct_glClearDepthx
    PUSH_IF_COMPILING(glClearDepthx)
#endif
    host_functions.glClearDepthx(depth);
}
AliasExport(void,glClearDepthx,,(GLclampx depth));
#endif
#ifndef skip_glClearStencil
void APIENTRY_GL4ES gl4es_glClearStencil(GLint s) {
    
#ifndef direct_glClearStencil
    PUSH_IF_COMPILING(glClearStencil)
#endif
    host_functions.glClearStencil(s);
}
AliasExport(void,glClearStencil,,(GLint s));
#endif
#ifndef skip_glClientActiveTexture
void APIENTRY_GL4ES gl4es_glClientActiveTexture(GLenum texture) {
    
#ifndef direct_glClientActiveTexture
    PUSH_IF_COMPILING(glClientActiveTexture)
#endif
    host_functions.glClientActiveTexture(texture);
}
AliasExport(void,glClientActiveTexture,,(GLenum texture));
#endif
#ifndef skip_glClipPlanef
void APIENTRY_GL4ES gl4es_glClipPlanef(GLenum plane, const GLfloat * equation) {
    
#ifndef direct_glClipPlanef
    PUSH_IF_COMPILING(glClipPlanef)
#endif
    host_functions.glClipPlanef(plane, equation);
}
AliasExport(void,glClipPlanef,,(GLenum plane, const GLfloat * equation));
#endif
#ifndef skip_glClipPlanex
void APIENTRY_GL4ES gl4es_glClipPlanex(GLenum plane, const GLfixed * equation) {
    
#ifndef direct_glClipPlanex
    PUSH_IF_COMPILING(glClipPlanex)
#endif
    host_functions.glClipPlanex(plane, equation);
}
AliasExport(void,glClipPlanex,,(GLenum plane, const GLfixed * equation));
#endif
#ifndef skip_glColor4f
void APIENTRY_GL4ES gl4es_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    
#ifndef direct_glColor4f
    PUSH_IF_COMPILING(glColor4f)
#endif
    host_functions.glColor4f(red, green, blue, alpha);
}
AliasExport(void,glColor4f,,(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha));
#endif
#ifndef skip_glColor4ub
void APIENTRY_GL4ES gl4es_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    
#ifndef direct_glColor4ub
    PUSH_IF_COMPILING(glColor4ub)
#endif
    host_functions.glColor4ub(red, green, blue, alpha);
}
AliasExport(void,glColor4ub,,(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha));
#endif
#ifndef skip_glColor4x
void APIENTRY_GL4ES gl4es_glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    
#ifndef direct_glColor4x
    PUSH_IF_COMPILING(glColor4x)
#endif
    host_functions.glColor4x(red, green, blue, alpha);
}
AliasExport(void,glColor4x,,(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha));
#endif
#ifndef skip_glColorMask
void APIENTRY_GL4ES gl4es_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    
#ifndef direct_glColorMask
    PUSH_IF_COMPILING(glColorMask)
#endif
    host_functions.glColorMask(red, green, blue, alpha);
}
AliasExport(void,glColorMask,,(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha));
#endif
#ifndef skip_glColorPointer
void APIENTRY_GL4ES gl4es_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    
#ifndef direct_glColorPointer
    PUSH_IF_COMPILING(glColorPointer)
#endif
    host_functions.glColorPointer(size, type, stride, pointer);
}
AliasExport(void,glColorPointer,,(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer));
#endif
#ifndef skip_glCompileShader
void APIENTRY_GL4ES gl4es_glCompileShader(GLuint shader) {
    
#ifndef direct_glCompileShader
    PUSH_IF_COMPILING(glCompileShader)
#endif
    host_functions.glCompileShader(shader);
}
AliasExport(void,glCompileShader,,(GLuint shader));
#endif
#ifndef skip_glCompressedTexImage2D
void APIENTRY_GL4ES gl4es_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    
#ifndef direct_glCompressedTexImage2D
    PUSH_IF_COMPILING(glCompressedTexImage2D)
#endif
    host_functions.glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
AliasExport(void,glCompressedTexImage2D,,(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data));
#endif
#ifndef skip_glCompressedTexSubImage2D
void APIENTRY_GL4ES gl4es_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    
#ifndef direct_glCompressedTexSubImage2D
    PUSH_IF_COMPILING(glCompressedTexSubImage2D)
#endif
    host_functions.glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
AliasExport(void,glCompressedTexSubImage2D,,(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data));
#endif
#ifndef skip_glCopyTexImage2D
void APIENTRY_GL4ES gl4es_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    
#ifndef direct_glCopyTexImage2D
    PUSH_IF_COMPILING(glCopyTexImage2D)
#endif
    host_functions.glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
AliasExport(void,glCopyTexImage2D,,(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border));
#endif
#ifndef skip_glCopyTexSubImage2D
void APIENTRY_GL4ES gl4es_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
#ifndef direct_glCopyTexSubImage2D
    PUSH_IF_COMPILING(glCopyTexSubImage2D)
#endif
    host_functions.glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
AliasExport(void,glCopyTexSubImage2D,,(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height));
#endif
#ifndef skip_glCreateProgram
GLuint APIENTRY_GL4ES gl4es_glCreateProgram() {
    
#ifndef direct_glCreateProgram
    PUSH_IF_COMPILING(glCreateProgram)
#endif
    return host_functions.glCreateProgram();
}
AliasExport(GLuint,glCreateProgram,,());
#endif
#ifndef skip_glCreateShader
GLuint APIENTRY_GL4ES gl4es_glCreateShader(GLenum type) {
    
#ifndef direct_glCreateShader
    PUSH_IF_COMPILING(glCreateShader)
#endif
    return host_functions.glCreateShader(type);
}
AliasExport(GLuint,glCreateShader,,(GLenum type));
#endif
#ifndef skip_glCullFace
void APIENTRY_GL4ES gl4es_glCullFace(GLenum mode) {
    
#ifndef direct_glCullFace
    PUSH_IF_COMPILING(glCullFace)
#endif
    host_functions.glCullFace(mode);
}
AliasExport(void,glCullFace,,(GLenum mode));
#endif
#ifndef skip_glDeleteBuffers
void APIENTRY_GL4ES gl4es_glDeleteBuffers(GLsizei n, const GLuint * buffer) {
    
#ifndef direct_glDeleteBuffers
    PUSH_IF_COMPILING(glDeleteBuffers)
#endif
    host_functions.glDeleteBuffers(n, buffer);
}
AliasExport(void,glDeleteBuffers,,(GLsizei n, const GLuint * buffer));
#endif
#ifndef skip_glDeleteFramebuffers
void APIENTRY_GL4ES gl4es_glDeleteFramebuffers(GLsizei n, GLuint * framebuffers) {
    
#ifndef direct_glDeleteFramebuffers
    PUSH_IF_COMPILING(glDeleteFramebuffers)
#endif
    host_functions.glDeleteFramebuffers(n, framebuffers);
}
AliasExport(void,glDeleteFramebuffers,,(GLsizei n, GLuint * framebuffers));
#endif
#ifndef skip_glDeleteProgram
void APIENTRY_GL4ES gl4es_glDeleteProgram(GLuint program) {
    
#ifndef direct_glDeleteProgram
    PUSH_IF_COMPILING(glDeleteProgram)
#endif
    host_functions.glDeleteProgram(program);
}
AliasExport(void,glDeleteProgram,,(GLuint program));
#endif
#ifndef skip_glDeleteRenderbuffers
void APIENTRY_GL4ES gl4es_glDeleteRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    
#ifndef direct_glDeleteRenderbuffers
    PUSH_IF_COMPILING(glDeleteRenderbuffers)
#endif
    host_functions.glDeleteRenderbuffers(n, renderbuffers);
}
AliasExport(void,glDeleteRenderbuffers,,(GLsizei n, GLuint * renderbuffers));
#endif
#ifndef skip_glDeleteShader
void APIENTRY_GL4ES gl4es_glDeleteShader(GLuint shader) {
    
#ifndef direct_glDeleteShader
    PUSH_IF_COMPILING(glDeleteShader)
#endif
    host_functions.glDeleteShader(shader);
}
AliasExport(void,glDeleteShader,,(GLuint shader));
#endif
#ifndef skip_glDeleteTextures
void APIENTRY_GL4ES gl4es_glDeleteTextures(GLsizei n, const GLuint * textures) {
    
#ifndef direct_glDeleteTextures
    PUSH_IF_COMPILING(glDeleteTextures)
#endif
    host_functions.glDeleteTextures(n, textures);
}
AliasExport(void,glDeleteTextures,,(GLsizei n, const GLuint * textures));
#endif
#ifndef skip_glDepthFunc
void APIENTRY_GL4ES gl4es_glDepthFunc(GLenum func) {
    
#ifndef direct_glDepthFunc
    PUSH_IF_COMPILING(glDepthFunc)
#endif
    host_functions.glDepthFunc(func);
}
AliasExport(void,glDepthFunc,,(GLenum func));
#endif
#ifndef skip_glDepthMask
void APIENTRY_GL4ES gl4es_glDepthMask(GLboolean flag) {
    
#ifndef direct_glDepthMask
    PUSH_IF_COMPILING(glDepthMask)
#endif
    host_functions.glDepthMask(flag);
}
AliasExport(void,glDepthMask,,(GLboolean flag));
#endif
#ifndef skip_glDepthRangef
void APIENTRY_GL4ES gl4es_glDepthRangef(GLclampf Near, GLclampf Far) {
    
#ifndef direct_glDepthRangef
    PUSH_IF_COMPILING(glDepthRangef)
#endif
    host_functions.glDepthRangef(Near, Far);
}
AliasExport(void,glDepthRangef,,(GLclampf Near, GLclampf Far));
#endif
#ifndef skip_glDepthRangex
void APIENTRY_GL4ES gl4es_glDepthRangex(GLclampx Near, GLclampx Far) {
    
#ifndef direct_glDepthRangex
    PUSH_IF_COMPILING(glDepthRangex)
#endif
    host_functions.glDepthRangex(Near, Far);
}
AliasExport(void,glDepthRangex,,(GLclampx Near, GLclampx Far));
#endif
#ifndef skip_glDetachShader
void APIENTRY_GL4ES gl4es_glDetachShader(GLuint program, GLuint shader) {
    
#ifndef direct_glDetachShader
    PUSH_IF_COMPILING(glDetachShader)
#endif
    host_functions.glDetachShader(program, shader);
}
AliasExport(void,glDetachShader,,(GLuint program, GLuint shader));
#endif
#ifndef skip_glDisable
void APIENTRY_GL4ES gl4es_glDisable(GLenum cap) {
    
#ifndef direct_glDisable
    PUSH_IF_COMPILING(glDisable)
#endif
    host_functions.glDisable(cap);
}
AliasExport(void,glDisable,,(GLenum cap));
#endif
#ifndef skip_glDisableClientState
void APIENTRY_GL4ES gl4es_glDisableClientState(GLenum array) {
    
#ifndef direct_glDisableClientState
    PUSH_IF_COMPILING(glDisableClientState)
#endif
    host_functions.glDisableClientState(array);
}
AliasExport(void,glDisableClientState,,(GLenum array));
#endif
#ifndef skip_glDisableVertexAttribArray
void APIENTRY_GL4ES gl4es_glDisableVertexAttribArray(GLuint index) {
    
#ifndef direct_glDisableVertexAttribArray
    PUSH_IF_COMPILING(glDisableVertexAttribArray)
#endif
    host_functions.glDisableVertexAttribArray(index);
}
AliasExport(void,glDisableVertexAttribArray,,(GLuint index));
#endif
#ifndef skip_glDrawArrays
void APIENTRY_GL4ES gl4es_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    
#ifndef direct_glDrawArrays
    PUSH_IF_COMPILING(glDrawArrays)
#endif
    host_functions.glDrawArrays(mode, first, count);
}
AliasExport(void,glDrawArrays,,(GLenum mode, GLint first, GLsizei count));
#endif
#ifndef skip_glDrawBuffers
void APIENTRY_GL4ES gl4es_glDrawBuffers(GLsizei n, const GLenum * bufs) {
    
#ifndef direct_glDrawBuffers
    PUSH_IF_COMPILING(glDrawBuffers)
#endif
    host_functions.glDrawBuffers(n, bufs);
}
AliasExport(void,glDrawBuffers(,,GLsizei n, const GLenum * bufs));
#endif
#ifndef skip_glDrawElements
void APIENTRY_GL4ES gl4es_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    
#ifndef direct_glDrawElements
    PUSH_IF_COMPILING(glDrawElements)
#endif
    host_functions.glDrawElements(mode, count, type, indices);
}
AliasExport(void,glDrawElements,,(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices));
#endif
#ifndef skip_glDrawTexf
void APIENTRY_GL4ES gl4es_glDrawTexf(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height) {
    
#ifndef direct_glDrawTexf
    PUSH_IF_COMPILING(glDrawTexf)
#endif
    host_functions.glDrawTexf(x, y, z, width, height);
}
AliasExport(void,glDrawTexf,,(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height));
#endif
#ifndef skip_glDrawTexi
void APIENTRY_GL4ES gl4es_glDrawTexi(GLint x, GLint y, GLint z, GLint width, GLint height) {
    
#ifndef direct_glDrawTexi
    PUSH_IF_COMPILING(glDrawTexi)
#endif
    host_functions.glDrawTexi(x, y, z, width, height);
}
AliasExport(void,glDrawTexi,,(GLint x, GLint y, GLint z, GLint width, GLint height));
#endif
#ifndef skip_glEnable
void APIENTRY_GL4ES gl4es_glEnable(GLenum cap) {
    
#ifndef direct_glEnable
    PUSH_IF_COMPILING(glEnable)
#endif
    host_functions.glEnable(cap);
}
AliasExport(void,glEnable,,(GLenum cap));
#endif
#ifndef skip_glEnableClientState
void APIENTRY_GL4ES gl4es_glEnableClientState(GLenum array) {
    
#ifndef direct_glEnableClientState
    PUSH_IF_COMPILING(glEnableClientState)
#endif
    host_functions.glEnableClientState(array);
}
AliasExport(void,glEnableClientState,,(GLenum array));
#endif
#ifndef skip_glEnableVertexAttribArray
void APIENTRY_GL4ES gl4es_glEnableVertexAttribArray(GLuint index) {
    
#ifndef direct_glEnableVertexAttribArray
    PUSH_IF_COMPILING(glEnableVertexAttribArray)
#endif
    host_functions.glEnableVertexAttribArray(index);
}
AliasExport(void,glEnableVertexAttribArray,,(GLuint index));
#endif
#ifndef skip_glFinish
void APIENTRY_GL4ES gl4es_glFinish() {
    
#ifndef direct_glFinish
    PUSH_IF_COMPILING(glFinish)
#endif
    host_functions.glFinish();
}
AliasExport(void,glFinish,,());
#endif
#ifndef skip_glFlush
void APIENTRY_GL4ES gl4es_glFlush() {
    
#ifndef direct_glFlush
    PUSH_IF_COMPILING(glFlush)
#endif
    host_functions.glFlush();
}
AliasExport(void,glFlush,,());
#endif
#ifndef skip_glFogCoordPointer
void APIENTRY_GL4ES gl4es_glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    
#ifndef direct_glFogCoordPointer
    PUSH_IF_COMPILING(glFogCoordPointer)
#endif
    host_functions.glFogCoordPointer(type, stride, pointer);
}
AliasExport(void,glFogCoordPointer,,(GLenum type, GLsizei stride, const GLvoid * pointer));
#endif
#ifndef skip_glFogCoordf
void APIENTRY_GL4ES gl4es_glFogCoordf(GLfloat coord) {
    
#ifndef direct_glFogCoordf
    PUSH_IF_COMPILING(glFogCoordf)
#endif
    host_functions.glFogCoordf(coord);
}
AliasExport(void,glFogCoordf,,(GLfloat coord));
#endif
#ifndef skip_glFogCoordfv
void APIENTRY_GL4ES gl4es_glFogCoordfv(const GLfloat * coord) {
    
#ifndef direct_glFogCoordfv
    PUSH_IF_COMPILING(glFogCoordfv)
#endif
    host_functions.glFogCoordfv(coord);
}
AliasExport(void,glFogCoordfv,,(const GLfloat * coord));
#endif
#ifndef skip_glFogf
void APIENTRY_GL4ES gl4es_glFogf(GLenum pname, GLfloat param) {
    
#ifndef direct_glFogf
    PUSH_IF_COMPILING(glFogf)
#endif
    host_functions.glFogf(pname, param);
}
AliasExport(void,glFogf,,(GLenum pname, GLfloat param));
#endif
#ifndef skip_glFogfv
void APIENTRY_GL4ES gl4es_glFogfv(GLenum pname, const GLfloat * params) {
    
#ifndef direct_glFogfv
    PUSH_IF_COMPILING(glFogfv)
#endif
    host_functions.glFogfv(pname, params);
}
AliasExport(void,glFogfv,,(GLenum pname, const GLfloat * params));
#endif
#ifndef skip_glFogx
void APIENTRY_GL4ES gl4es_glFogx(GLenum pname, GLfixed param) {
    
#ifndef direct_glFogx
    PUSH_IF_COMPILING(glFogx)
#endif
    host_functions.glFogx(pname, param);
}
AliasExport(void,glFogx,,(GLenum pname, GLfixed param));
#endif
#ifndef skip_glFogxv
void APIENTRY_GL4ES gl4es_glFogxv(GLenum pname, const GLfixed * params) {
    
#ifndef direct_glFogxv
    PUSH_IF_COMPILING(glFogxv)
#endif
    host_functions.glFogxv(pname, params);
}
AliasExport(void,glFogxv,,(GLenum pname, const GLfixed * params));
#endif
#ifndef skip_glFramebufferRenderbuffer
void APIENTRY_GL4ES gl4es_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    
#ifndef direct_glFramebufferRenderbuffer
    PUSH_IF_COMPILING(glFramebufferRenderbuffer)
#endif
    host_functions.glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
AliasExport(void,glFramebufferRenderbuffer,,(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer));
#endif
#ifndef skip_glFramebufferTexture2D
void APIENTRY_GL4ES gl4es_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    
#ifndef direct_glFramebufferTexture2D
    PUSH_IF_COMPILING(glFramebufferTexture2D)
#endif
    host_functions.glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
AliasExport(void,glFramebufferTexture2D,,(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level));
#endif
#ifndef skip_glFrontFace
void APIENTRY_GL4ES gl4es_glFrontFace(GLenum mode) {
    
#ifndef direct_glFrontFace
    PUSH_IF_COMPILING(glFrontFace)
#endif
    host_functions.glFrontFace(mode);
}
AliasExport(void,glFrontFace,,(GLenum mode));
#endif
#ifndef skip_glFrustumf
void APIENTRY_GL4ES gl4es_glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat Near, GLfloat Far) {
    
#ifndef direct_glFrustumf
    PUSH_IF_COMPILING(glFrustumf)
#endif
    host_functions.glFrustumf(left, right, bottom, top, Near, Far);
}
AliasExport(void,glFrustumf,,(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat Near, GLfloat Far));
#endif
#ifndef skip_glFrustumx
void APIENTRY_GL4ES gl4es_glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed Near, GLfixed Far) {
    
#ifndef direct_glFrustumx
    PUSH_IF_COMPILING(glFrustumx)
#endif
    host_functions.glFrustumx(left, right, bottom, top, Near, Far);
}
AliasExport(void,glFrustumx,,(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed Near, GLfixed Far));
#endif
#ifndef skip_glGenBuffers
void APIENTRY_GL4ES gl4es_glGenBuffers(GLsizei n, GLuint * buffer) {
    
#ifndef direct_glGenBuffers
    PUSH_IF_COMPILING(glGenBuffers)
#endif
    host_functions.glGenBuffers(n, buffer);
}
AliasExport(void,glGenBuffers,,(GLsizei n, GLuint * buffer));
#endif
#ifndef skip_glGenFramebuffers
void APIENTRY_GL4ES gl4es_glGenFramebuffers(GLsizei n, GLuint * ids) {
    
#ifndef direct_glGenFramebuffers
    PUSH_IF_COMPILING(glGenFramebuffers)
#endif
    host_functions.glGenFramebuffers(n, ids);
}
AliasExport(void,glGenFramebuffers,,(GLsizei n, GLuint * ids));
#endif
#ifndef skip_glGenRenderbuffers
void APIENTRY_GL4ES gl4es_glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    
#ifndef direct_glGenRenderbuffers
    PUSH_IF_COMPILING(glGenRenderbuffers)
#endif
    host_functions.glGenRenderbuffers(n, renderbuffers);
}
AliasExport(void,glGenRenderbuffers,,(GLsizei n, GLuint * renderbuffers));
#endif
#ifndef skip_glGenTextures
void APIENTRY_GL4ES gl4es_glGenTextures(GLsizei n, GLuint * textures) {
    
#ifndef direct_glGenTextures
    PUSH_IF_COMPILING(glGenTextures)
#endif
    host_functions.glGenTextures(n, textures);
}
AliasExport(void,glGenTextures,,(GLsizei n, GLuint * textures));
#endif
#ifndef skip_glGenerateMipmap
void APIENTRY_GL4ES gl4es_glGenerateMipmap(GLenum target) {
    
#ifndef direct_glGenerateMipmap
    PUSH_IF_COMPILING(glGenerateMipmap)
#endif
    host_functions.glGenerateMipmap(target);
}
AliasExport(void,glGenerateMipmap,,(GLenum target));
#endif
#ifndef skip_glGetActiveAttrib
void APIENTRY_GL4ES gl4es_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    
#ifndef direct_glGetActiveAttrib
    PUSH_IF_COMPILING(glGetActiveAttrib)
#endif
    host_functions.glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
AliasExport(void,glGetActiveAttrib,,(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name));
#endif
#ifndef skip_glGetActiveUniform
void APIENTRY_GL4ES gl4es_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    
#ifndef direct_glGetActiveUniform
    PUSH_IF_COMPILING(glGetActiveUniform)
#endif
    host_functions.glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
AliasExport(void,glGetActiveUniform,,(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name));
#endif
#ifndef skip_glGetAttachedShaders
void APIENTRY_GL4ES gl4es_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj) {
    
#ifndef direct_glGetAttachedShaders
    PUSH_IF_COMPILING(glGetAttachedShaders)
#endif
    host_functions.glGetAttachedShaders(program, maxCount, count, obj);
}
AliasExport(void,glGetAttachedShaders,,(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj));
#endif
#ifndef skip_glGetAttribLocation
GLint APIENTRY_GL4ES gl4es_glGetAttribLocation(GLuint program, const GLchar * name) {
    
#ifndef direct_glGetAttribLocation
    PUSH_IF_COMPILING(glGetAttribLocation)
#endif
    return host_functions.glGetAttribLocation(program, name);
}
AliasExport(GLint,glGetAttribLocation,,(GLuint program, const GLchar * name));
#endif
#ifndef skip_glGetBooleanv
void APIENTRY_GL4ES gl4es_glGetBooleanv(GLenum pname, GLboolean * params) {
    
#ifndef direct_glGetBooleanv
    PUSH_IF_COMPILING(glGetBooleanv)
#endif
    host_functions.glGetBooleanv(pname, params);
}
AliasExport(void,glGetBooleanv,,(GLenum pname, GLboolean * params));
#endif
#ifndef skip_glGetBufferParameteriv
void APIENTRY_GL4ES gl4es_glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    
#ifndef direct_glGetBufferParameteriv
    PUSH_IF_COMPILING(glGetBufferParameteriv)
#endif
    host_functions.glGetBufferParameteriv(target, pname, params);
}
AliasExport(void,glGetBufferParameteriv,,(GLenum target, GLenum pname, GLint * params));
#endif
#ifndef skip_glGetClipPlanef
void APIENTRY_GL4ES gl4es_glGetClipPlanef(GLenum plane, GLfloat * equation) {
    
#ifndef direct_glGetClipPlanef
    PUSH_IF_COMPILING(glGetClipPlanef)
#endif
    host_functions.glGetClipPlanef(plane, equation);
}
AliasExport(void,glGetClipPlanef,,(GLenum plane, GLfloat * equation));
#endif
#ifndef skip_glGetClipPlanex
void APIENTRY_GL4ES gl4es_glGetClipPlanex(GLenum plane, GLfixed * equation) {
    
#ifndef direct_glGetClipPlanex
    PUSH_IF_COMPILING(glGetClipPlanex)
#endif
    host_functions.glGetClipPlanex(plane, equation);
}
AliasExport(void,glGetClipPlanex,,(GLenum plane, GLfixed * equation));
#endif
#ifndef skip_glGetError
GLenum APIENTRY_GL4ES gl4es_glGetError(void) {
    
#ifndef direct_glGetError
    PUSH_IF_COMPILING(glGetError)
#endif
    return host_functions.glGetError();
}
AliasExport(GLenum,glGetError,,());
#endif
#ifndef skip_glGetFixedv
void APIENTRY_GL4ES gl4es_glGetFixedv(GLenum pname, GLfixed * params) {
    
#ifndef direct_glGetFixedv
    PUSH_IF_COMPILING(glGetFixedv)
#endif
    host_functions.glGetFixedv(pname, params);
}
AliasExport(void,glGetFixedv,,(GLenum pname, GLfixed * params));
#endif
#ifndef skip_glGetFloatv
void APIENTRY_GL4ES gl4es_glGetFloatv(GLenum pname, GLfloat * params) {
    
#ifndef direct_glGetFloatv
    PUSH_IF_COMPILING(glGetFloatv)
#endif
    host_functions.glGetFloatv(pname, params);
}
AliasExport(void,glGetFloatv,,(GLenum pname, GLfloat * params));
#endif
#ifndef skip_glGetFramebufferAttachmentParameteriv
void APIENTRY_GL4ES gl4es_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    
#ifndef direct_glGetFramebufferAttachmentParameteriv
    PUSH_IF_COMPILING(glGetFramebufferAttachmentParameteriv)
#endif
    host_functions.glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
AliasExport(void,glGetFramebufferAttachmentParameteriv,,(GLenum target, GLenum attachment, GLenum pname, GLint * params));
#endif
#ifndef skip_glGetIntegerv
void APIENTRY_GL4ES gl4es_glGetIntegerv(GLenum pname, GLint * params) {
    
#ifndef direct_glGetIntegerv
    PUSH_IF_COMPILING(glGetIntegerv)
#endif
    host_functions.glGetIntegerv(pname, params);
}
AliasExport(void,glGetIntegerv,,(GLenum pname, GLint * params));
#endif
#ifndef skip_glGetLightfv
void APIENTRY_GL4ES gl4es_glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    
#ifndef direct_glGetLightfv
    PUSH_IF_COMPILING(glGetLightfv)
#endif
    host_functions.glGetLightfv(light, pname, params);
}
AliasExport(void,glGetLightfv,,(GLenum light, GLenum pname, GLfloat * params));
#endif
#ifndef skip_glGetLightxv
void APIENTRY_GL4ES gl4es_glGetLightxv(GLenum light, GLenum pname, GLfixed * params) {
    
#ifndef direct_glGetLightxv
    PUSH_IF_COMPILING(glGetLightxv)
#endif
    host_functions.glGetLightxv(light, pname, params);
}
AliasExport(void,glGetLightxv,,(GLenum light, GLenum pname, GLfixed * params));
#endif
#ifndef skip_glGetMaterialfv
void APIENTRY_GL4ES gl4es_glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    
#ifndef direct_glGetMaterialfv
    PUSH_IF_COMPILING(glGetMaterialfv)
#endif
    host_functions.glGetMaterialfv(face, pname, params);
}
AliasExport(void,glGetMaterialfv,,(GLenum face, GLenum pname, GLfloat * params));
#endif
#ifndef skip_glGetMaterialxv
void APIENTRY_GL4ES gl4es_glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) {
    
#ifndef direct_glGetMaterialxv
    PUSH_IF_COMPILING(glGetMaterialxv)
#endif
    host_functions.glGetMaterialxv(face, pname, params);
}
AliasExport(void,glGetMaterialxv,,(GLenum face, GLenum pname, GLfixed * params));
#endif
#ifndef skip_glGetPointerv
void APIENTRY_GL4ES gl4es_glGetPointerv(GLenum pname, GLvoid ** params) {
    
#ifndef direct_glGetPointerv
    PUSH_IF_COMPILING(glGetPointerv)
#endif
    host_functions.glGetPointerv(pname, params);
}
AliasExport(void,glGetPointerv,,(GLenum pname, GLvoid ** params));
#endif
#ifndef skip_glGetProgramBinary
void APIENTRY_GL4ES gl4es_glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, GLvoid * binary) {
    
#ifndef direct_glGetProgramBinary
    PUSH_IF_COMPILING(glGetProgramBinary)
#endif
    host_functions.glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}
AliasExport(void,glGetProgramBinary,,(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, GLvoid * binary));
#endif
#ifndef skip_glGetProgramInfoLog
void APIENTRY_GL4ES gl4es_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    
#ifndef direct_glGetProgramInfoLog
    PUSH_IF_COMPILING(glGetProgramInfoLog)
#endif
    host_functions.glGetProgramInfoLog(program, bufSize, length, infoLog);
}
AliasExport(void,glGetProgramInfoLog,,(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog));
#endif
#ifndef skip_glGetProgramiv
void APIENTRY_GL4ES gl4es_glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    
#ifndef direct_glGetProgramiv
    PUSH_IF_COMPILING(glGetProgramiv)
#endif
    host_functions.glGetProgramiv(program, pname, params);
}
AliasExport(void,glGetProgramiv,,(GLuint program, GLenum pname, GLint * params));
#endif
#ifndef skip_glGetRenderbufferParameteriv
void APIENTRY_GL4ES gl4es_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    
#ifndef direct_glGetRenderbufferParameteriv
    PUSH_IF_COMPILING(glGetRenderbufferParameteriv)
#endif
    host_functions.glGetRenderbufferParameteriv(target, pname, params);
}
AliasExport(void,glGetRenderbufferParameteriv,,(GLenum target, GLenum pname, GLint * params));
#endif
#ifndef skip_glGetShaderInfoLog
void APIENTRY_GL4ES gl4es_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    
#ifndef direct_glGetShaderInfoLog
    PUSH_IF_COMPILING(glGetShaderInfoLog)
#endif
    host_functions.glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
AliasExport(void,glGetShaderInfoLog,,(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog));
#endif
#ifndef skip_glGetShaderPrecisionFormat
void APIENTRY_GL4ES gl4es_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
    
#ifndef direct_glGetShaderPrecisionFormat
    PUSH_IF_COMPILING(glGetShaderPrecisionFormat)
#endif
    host_functions.glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
AliasExport(void,glGetShaderPrecisionFormat,,(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision));
#endif
#ifndef skip_glGetShaderSource
void APIENTRY_GL4ES gl4es_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    
#ifndef direct_glGetShaderSource
    PUSH_IF_COMPILING(glGetShaderSource)
#endif
    host_functions.glGetShaderSource(shader, bufSize, length, source);
}
AliasExport(void,glGetShaderSource,,(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source));
#endif
#ifndef skip_glGetShaderiv
void APIENTRY_GL4ES gl4es_glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    
#ifndef direct_glGetShaderiv
    PUSH_IF_COMPILING(glGetShaderiv)
#endif
    host_functions.glGetShaderiv(shader, pname, params);
}
AliasExport(void,glGetShaderiv,,(GLuint shader, GLenum pname, GLint * params));
#endif
#ifndef skip_glGetString
const GLubyte * APIENTRY_GL4ES gl4es_glGetString(GLenum name) {
    
#ifndef direct_glGetString
    PUSH_IF_COMPILING(glGetString)
#endif
    return host_functions.glGetString(name);
}
AliasExport(const GLubyte*,glGetString,,(GLenum name));
#endif
#ifndef skip_glGetTexEnvfv
void APIENTRY_GL4ES gl4es_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    
#ifndef direct_glGetTexEnvfv
    PUSH_IF_COMPILING(glGetTexEnvfv)
#endif
    host_functions.glGetTexEnvfv(target, pname, params);
}
AliasExport(void,glGetTexEnvfv,,(GLenum target, GLenum pname, GLfloat * params));
#endif
#ifndef skip_glGetTexEnviv
void APIENTRY_GL4ES gl4es_glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    
#ifndef direct_glGetTexEnviv
    PUSH_IF_COMPILING(glGetTexEnviv)
#endif
    host_functions.glGetTexEnviv(target, pname, params);
}
AliasExport(void,glGetTexEnviv,,(GLenum target, GLenum pname, GLint * params));
#endif
#ifndef skip_glGetTexEnvxv
void APIENTRY_GL4ES gl4es_glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) {
    
#ifndef direct_glGetTexEnvxv
    PUSH_IF_COMPILING(glGetTexEnvxv)
#endif
    host_functions.glGetTexEnvxv(target, pname, params);
}
AliasExport(void,glGetTexEnvxv,,(GLenum target, GLenum pname, GLfixed * params));
#endif
#ifndef skip_glGetTexParameterfv
void APIENTRY_GL4ES gl4es_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    
#ifndef direct_glGetTexParameterfv
    PUSH_IF_COMPILING(glGetTexParameterfv)
#endif
    host_functions.glGetTexParameterfv(target, pname, params);
}
AliasExport(void,glGetTexParameterfv,,(GLenum target, GLenum pname, GLfloat * params));
#endif
#ifndef skip_glGetTexParameteriv
void APIENTRY_GL4ES gl4es_glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    
#ifndef direct_glGetTexParameteriv
    PUSH_IF_COMPILING(glGetTexParameteriv)
#endif
    host_functions.glGetTexParameteriv(target, pname, params);
}
AliasExport(void,glGetTexParameteriv,,(GLenum target, GLenum pname, GLint * params));
#endif
#ifndef skip_glGetTexParameterxv
void APIENTRY_GL4ES gl4es_glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) {
    
#ifndef direct_glGetTexParameterxv
    PUSH_IF_COMPILING(glGetTexParameterxv)
#endif
    host_functions.glGetTexParameterxv(target, pname, params);
}
AliasExport(void,glGetTexParameterxv,,(GLenum target, GLenum pname, GLfixed * params));
#endif
#ifndef skip_glGetUniformLocation
GLint APIENTRY_GL4ES gl4es_glGetUniformLocation(GLuint program, const GLchar * name) {
    
#ifndef direct_glGetUniformLocation
    PUSH_IF_COMPILING(glGetUniformLocation)
#endif
    return host_functions.glGetUniformLocation(program, name);
}
AliasExport(GLint,glGetUniformLocation,,(GLuint program, const GLchar * name));
#endif
#ifndef skip_glGetUniformfv
void APIENTRY_GL4ES gl4es_glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    
#ifndef direct_glGetUniformfv
    PUSH_IF_COMPILING(glGetUniformfv)
#endif
    host_functions.glGetUniformfv(program, location, params);
}
AliasExport(void,glGetUniformfv,,(GLuint program, GLint location, GLfloat * params));
#endif
#ifndef skip_glGetUniformiv
void APIENTRY_GL4ES gl4es_glGetUniformiv(GLuint program, GLint location, GLint * params) {
    
#ifndef direct_glGetUniformiv
    PUSH_IF_COMPILING(glGetUniformiv)
#endif
    host_functions.glGetUniformiv(program, location, params);
}
AliasExport(void,glGetUniformiv,,(GLuint program, GLint location, GLint * params));
#endif
#ifndef skip_glGetVertexAttribPointerv
void APIENTRY_GL4ES gl4es_glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) {
    
#ifndef direct_glGetVertexAttribPointerv
    PUSH_IF_COMPILING(glGetVertexAttribPointerv)
#endif
    host_functions.glGetVertexAttribPointerv(index, pname, pointer);
}
AliasExport(void,glGetVertexAttribPointerv,,(GLuint index, GLenum pname, GLvoid ** pointer));
#endif
#ifndef skip_glGetVertexAttribfv
void APIENTRY_GL4ES gl4es_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    
#ifndef direct_glGetVertexAttribfv
    PUSH_IF_COMPILING(glGetVertexAttribfv)
#endif
    host_functions.glGetVertexAttribfv(index, pname, params);
}
AliasExport(void,glGetVertexAttribfv,,(GLuint index, GLenum pname, GLfloat * params));
#endif
#ifndef skip_glGetVertexAttribiv
void APIENTRY_GL4ES gl4es_glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    
#ifndef direct_glGetVertexAttribiv
    PUSH_IF_COMPILING(glGetVertexAttribiv)
#endif
    host_functions.glGetVertexAttribiv(index, pname, params);
}
AliasExport(void,glGetVertexAttribiv,,(GLuint index, GLenum pname, GLint * params));
#endif
#ifndef skip_glHint
void APIENTRY_GL4ES gl4es_glHint(GLenum target, GLenum mode) {
    
#ifndef direct_glHint
    PUSH_IF_COMPILING(glHint)
#endif
    host_functions.glHint(target, mode);
}
AliasExport(void,glHint,,(GLenum target, GLenum mode));
#endif
#ifndef skip_glIsBuffer
GLboolean APIENTRY_GL4ES gl4es_glIsBuffer(GLuint buffer) {
    
#ifndef direct_glIsBuffer
    PUSH_IF_COMPILING(glIsBuffer)
#endif
    return host_functions.glIsBuffer(buffer);
}
AliasExport(GLboolean,glIsBuffer,,(GLuint buffer));
#endif
#ifndef skip_glIsEnabled
GLboolean APIENTRY_GL4ES gl4es_glIsEnabled(GLenum cap) {
    
#ifndef direct_glIsEnabled
    PUSH_IF_COMPILING(glIsEnabled)
#endif
    return host_functions.glIsEnabled(cap);
}
AliasExport(GLboolean,glIsEnabled,,(GLenum cap));
#endif
#ifndef skip_glIsFramebuffer
GLboolean APIENTRY_GL4ES gl4es_glIsFramebuffer(GLuint framebuffer) {
    
#ifndef direct_glIsFramebuffer
    PUSH_IF_COMPILING(glIsFramebuffer)
#endif
    return host_functions.glIsFramebuffer(framebuffer);
}
AliasExport(GLboolean,glIsFramebuffer,,(GLuint framebuffer));
#endif
#ifndef skip_glIsProgram
GLboolean APIENTRY_GL4ES gl4es_glIsProgram(GLuint program) {
    
#ifndef direct_glIsProgram
    PUSH_IF_COMPILING(glIsProgram)
#endif
    return host_functions.glIsProgram(program);
}
AliasExport(GLboolean,glIsProgram,,(GLuint program));
#endif
#ifndef skip_glIsRenderbuffer
GLboolean APIENTRY_GL4ES gl4es_glIsRenderbuffer(GLuint renderbuffer) {
    
#ifndef direct_glIsRenderbuffer
    PUSH_IF_COMPILING(glIsRenderbuffer)
#endif
    return host_functions.glIsRenderbuffer(renderbuffer);
}
AliasExport(GLboolean,glIsRenderbuffer,,(GLuint renderbuffer));
#endif
#ifndef skip_glIsShader
GLboolean APIENTRY_GL4ES gl4es_glIsShader(GLuint shader) {
    
#ifndef direct_glIsShader
    PUSH_IF_COMPILING(glIsShader)
#endif
    return host_functions.glIsShader(shader);
}
AliasExport(GLboolean,glIsShader,,(GLuint shader));
#endif
#ifndef skip_glIsTexture
GLboolean APIENTRY_GL4ES gl4es_glIsTexture(GLuint texture) {
    
#ifndef direct_glIsTexture
    PUSH_IF_COMPILING(glIsTexture)
#endif
    return host_functions.glIsTexture(texture);
}
AliasExport(GLboolean,glIsTexture,,(GLuint texture));
#endif
#ifndef skip_glLightModelf
void APIENTRY_GL4ES gl4es_glLightModelf(GLenum pname, GLfloat param) {
    
#ifndef direct_glLightModelf
    PUSH_IF_COMPILING(glLightModelf)
#endif
    host_functions.glLightModelf(pname, param);
}
AliasExport(void,glLightModelf,,(GLenum pname, GLfloat param));
#endif
#ifndef skip_glLightModelfv
void APIENTRY_GL4ES gl4es_glLightModelfv(GLenum pname, const GLfloat * params) {
    
#ifndef direct_glLightModelfv
    PUSH_IF_COMPILING(glLightModelfv)
#endif
    host_functions.glLightModelfv(pname, params);
}
AliasExport(void,glLightModelfv,,(GLenum pname, const GLfloat * params));
#endif
#ifndef skip_glLightModelx
void APIENTRY_GL4ES gl4es_glLightModelx(GLenum pname, GLfixed param) {
    
#ifndef direct_glLightModelx
    PUSH_IF_COMPILING(glLightModelx)
#endif
    host_functions.glLightModelx(pname, param);
}
AliasExport(void,glLightModelx,,(GLenum pname, GLfixed param));
#endif
#ifndef skip_glLightModelxv
void APIENTRY_GL4ES gl4es_glLightModelxv(GLenum pname, const GLfixed * params) {
    
#ifndef direct_glLightModelxv
    PUSH_IF_COMPILING(glLightModelxv)
#endif
    host_functions.glLightModelxv(pname, params);
}
AliasExport(void,glLightModelxv,,(GLenum pname, const GLfixed * params));
#endif
#ifndef skip_glLightf
void APIENTRY_GL4ES gl4es_glLightf(GLenum light, GLenum pname, GLfloat param) {
    
#ifndef direct_glLightf
    PUSH_IF_COMPILING(glLightf)
#endif
    host_functions.glLightf(light, pname, param);
}
AliasExport(void,glLightf,,(GLenum light, GLenum pname, GLfloat param));
#endif
#ifndef skip_glLightfv
void APIENTRY_GL4ES gl4es_glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    
#ifndef direct_glLightfv
    PUSH_IF_COMPILING(glLightfv)
#endif
    host_functions.glLightfv(light, pname, params);
}
AliasExport(void,glLightfv,,(GLenum light, GLenum pname, const GLfloat * params));
#endif
#ifndef skip_glLightx
void APIENTRY_GL4ES gl4es_glLightx(GLenum light, GLenum pname, GLfixed param) {
    
#ifndef direct_glLightx
    PUSH_IF_COMPILING(glLightx)
#endif
    host_functions.glLightx(light, pname, param);
}
AliasExport(void,glLightx,,(GLenum light, GLenum pname, GLfixed param));
#endif
#ifndef skip_glLightxv
void APIENTRY_GL4ES gl4es_glLightxv(GLenum light, GLenum pname, const GLfixed * params) {
    
#ifndef direct_glLightxv
    PUSH_IF_COMPILING(glLightxv)
#endif
    host_functions.glLightxv(light, pname, params);
}
AliasExport(void,glLightxv,,(GLenum light, GLenum pname, const GLfixed * params));
#endif
#ifndef skip_glLineWidth
void APIENTRY_GL4ES gl4es_glLineWidth(GLfloat width) {
    
#ifndef direct_glLineWidth
    PUSH_IF_COMPILING(glLineWidth)
#endif
    host_functions.glLineWidth(width);
}
AliasExport(void,glLineWidth,,(GLfloat width));
#endif
#ifndef skip_glLineWidthx
void APIENTRY_GL4ES gl4es_glLineWidthx(GLfixed width) {
    
#ifndef direct_glLineWidthx
    PUSH_IF_COMPILING(glLineWidthx)
#endif
    host_functions.glLineWidthx(width);
}
AliasExport(void,glLineWidthx,,(GLfixed width));
#endif
#ifndef skip_glLinkProgram
void APIENTRY_GL4ES gl4es_glLinkProgram(GLuint program) {
    
#ifndef direct_glLinkProgram
    PUSH_IF_COMPILING(glLinkProgram)
#endif
    host_functions.glLinkProgram(program);
}
AliasExport(void,glLinkProgram,,(GLuint program));
#endif
#ifndef skip_glLoadIdentity
void APIENTRY_GL4ES gl4es_glLoadIdentity(void) {
    
#ifndef direct_glLoadIdentity
    PUSH_IF_COMPILING(glLoadIdentity)
#endif
    host_functions.glLoadIdentity();
}
AliasExport(void,glLoadIdentity,,());
#endif
#ifndef skip_glLoadMatrixf
void APIENTRY_GL4ES gl4es_glLoadMatrixf(const GLfloat * m) {
    
#ifndef direct_glLoadMatrixf
    PUSH_IF_COMPILING(glLoadMatrixf)
#endif
    host_functions.glLoadMatrixf(m);
}
AliasExport(void,glLoadMatrixf,,(const GLfloat * m));
#endif
#ifndef skip_glLoadMatrixx
void APIENTRY_GL4ES gl4es_glLoadMatrixx(const GLfixed * m) {
    
#ifndef direct_glLoadMatrixx
    PUSH_IF_COMPILING(glLoadMatrixx)
#endif
    host_functions.glLoadMatrixx(m);
}
AliasExport(void,glLoadMatrixx,,(const GLfixed * m));
#endif
#ifndef skip_glLogicOp
void APIENTRY_GL4ES gl4es_glLogicOp(GLenum opcode) {
    
#ifndef direct_glLogicOp
    PUSH_IF_COMPILING(glLogicOp)
#endif
    host_functions.glLogicOp(opcode);
}
AliasExport(void,glLogicOp,,(GLenum opcode));
#endif
#ifndef skip_glMaterialf
void APIENTRY_GL4ES gl4es_glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    
#ifndef direct_glMaterialf
    PUSH_IF_COMPILING(glMaterialf)
#endif
    host_functions.glMaterialf(face, pname, param);
}
AliasExport(void,glMaterialf,,(GLenum face, GLenum pname, GLfloat param));
#endif
#ifndef skip_glMaterialfv
void APIENTRY_GL4ES gl4es_glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    
#ifndef direct_glMaterialfv
    PUSH_IF_COMPILING(glMaterialfv)
#endif
    host_functions.glMaterialfv(face, pname, params);
}
AliasExport(void,glMaterialfv,,(GLenum face, GLenum pname, const GLfloat * params));
#endif
#ifndef skip_glMaterialx
void APIENTRY_GL4ES gl4es_glMaterialx(GLenum face, GLenum pname, GLfixed param) {
    
#ifndef direct_glMaterialx
    PUSH_IF_COMPILING(glMaterialx)
#endif
    host_functions.glMaterialx(face, pname, param);
}
AliasExport(void,glMaterialx,,(GLenum face, GLenum pname, GLfixed param));
#endif
#ifndef skip_glMaterialxv
void APIENTRY_GL4ES gl4es_glMaterialxv(GLenum face, GLenum pname, const GLfixed * params) {
    
#ifndef direct_glMaterialxv
    PUSH_IF_COMPILING(glMaterialxv)
#endif
    host_functions.glMaterialxv(face, pname, params);
}
AliasExport(void,glMaterialxv,,(GLenum face, GLenum pname, const GLfixed * params));
#endif
#ifndef skip_glMatrixMode
void APIENTRY_GL4ES gl4es_glMatrixMode(GLenum mode) {
    
#ifndef direct_glMatrixMode
    PUSH_IF_COMPILING(glMatrixMode)
#endif
    host_functions.glMatrixMode(mode);
}
AliasExport(void,glMatrixMode,,(GLenum mode));
#endif
#ifndef skip_glMultMatrixf
void APIENTRY_GL4ES gl4es_glMultMatrixf(const GLfloat * m) {
    
#ifndef direct_glMultMatrixf
    PUSH_IF_COMPILING(glMultMatrixf)
#endif
    host_functions.glMultMatrixf(m);
}
AliasExport(void,glMultMatrixf,,(const GLfloat * m));
#endif
#ifndef skip_glMultMatrixx
void APIENTRY_GL4ES gl4es_glMultMatrixx(const GLfixed * m) {
    
#ifndef direct_glMultMatrixx
    PUSH_IF_COMPILING(glMultMatrixx)
#endif
    host_functions.glMultMatrixx(m);
}
AliasExport(void,glMultMatrixx,,(const GLfixed * m));
#endif
#ifndef skip_glMultiDrawArrays
void APIENTRY_GL4ES gl4es_glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount) {
    
#ifndef direct_glMultiDrawArrays
    PUSH_IF_COMPILING(glMultiDrawArrays)
#endif
    host_functions.glMultiDrawArrays(mode, first, count, primcount);
}
AliasExport(void,glMultiDrawArrays,,(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount));
#endif
#ifndef skip_glMultiDrawElements
void APIENTRY_GL4ES gl4es_glMultiDrawElements(GLenum mode, GLsizei * count, GLenum type, const void * const * indices, GLsizei primcount) {
    
#ifndef direct_glMultiDrawElements
    PUSH_IF_COMPILING(glMultiDrawElements)
#endif
    host_functions.glMultiDrawElements(mode, count, type, indices, primcount);
}
AliasExport(void,glMultiDrawElements,,(GLenum mode, GLsizei * count, GLenum type, const void * const * indices, GLsizei primcount));
#endif
#ifndef skip_glMultiTexCoord4f
void APIENTRY_GL4ES gl4es_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    
#ifndef direct_glMultiTexCoord4f
    PUSH_IF_COMPILING(glMultiTexCoord4f)
#endif
    host_functions.glMultiTexCoord4f(target, s, t, r, q);
}
AliasExport(void,glMultiTexCoord4f,,(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q));
#endif
#ifndef skip_glMultiTexCoord4x
void APIENTRY_GL4ES gl4es_glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    
#ifndef direct_glMultiTexCoord4x
    PUSH_IF_COMPILING(glMultiTexCoord4x)
#endif
    host_functions.glMultiTexCoord4x(target, s, t, r, q);
}
AliasExport(void,glMultiTexCoord4x,,(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q));
#endif
#ifndef skip_glNormal3f
void APIENTRY_GL4ES gl4es_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    
#ifndef direct_glNormal3f
    PUSH_IF_COMPILING(glNormal3f)
#endif
    host_functions.glNormal3f(nx, ny, nz);
}
AliasExport(void,glNormal3f,,(GLfloat nx, GLfloat ny, GLfloat nz));
#endif
#ifndef skip_glNormal3x
void APIENTRY_GL4ES gl4es_glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
    
#ifndef direct_glNormal3x
    PUSH_IF_COMPILING(glNormal3x)
#endif
    host_functions.glNormal3x(nx, ny, nz);
}
AliasExport(void,glNormal3x,,(GLfixed nx, GLfixed ny, GLfixed nz));
#endif
#ifndef skip_glNormalPointer
void APIENTRY_GL4ES gl4es_glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    
#ifndef direct_glNormalPointer
    PUSH_IF_COMPILING(glNormalPointer)
#endif
    host_functions.glNormalPointer(type, stride, pointer);
}
AliasExport(void,glNormalPointer,,(GLenum type, GLsizei stride, const GLvoid * pointer));
#endif
#ifndef skip_glOrthof
void APIENTRY_GL4ES gl4es_glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat Near, GLfloat Far) {
    
#ifndef direct_glOrthof
    PUSH_IF_COMPILING(glOrthof)
#endif
    host_functions.glOrthof(left, right, bottom, top, Near, Far);
}
AliasExport(void,glOrthof,,(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat Near, GLfloat Far));
#endif
#ifndef skip_glOrthox
void APIENTRY_GL4ES gl4es_glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed Near, GLfixed Far) {
    
#ifndef direct_glOrthox
    PUSH_IF_COMPILING(glOrthox)
#endif
    host_functions.glOrthox(left, right, bottom, top, Near, Far);
}
AliasExport(void,glOrthox,,(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed Near, GLfixed Far));
#endif
#ifndef skip_glPixelStorei
void APIENTRY_GL4ES gl4es_glPixelStorei(GLenum pname, GLint param) {
    
#ifndef direct_glPixelStorei
    PUSH_IF_COMPILING(glPixelStorei)
#endif
    host_functions.glPixelStorei(pname, param);
}
AliasExport(void,glPixelStorei,,(GLenum pname, GLint param));
#endif
#ifndef skip_glPointParameterf
void APIENTRY_GL4ES gl4es_glPointParameterf(GLenum pname, GLfloat param) {
    
#ifndef direct_glPointParameterf
    PUSH_IF_COMPILING(glPointParameterf)
#endif
    host_functions.glPointParameterf(pname, param);
}
AliasExport(void,glPointParameterf,,(GLenum pname, GLfloat param));
#endif
#ifndef skip_glPointParameterfv
void APIENTRY_GL4ES gl4es_glPointParameterfv(GLenum pname, const GLfloat * params) {
    
#ifndef direct_glPointParameterfv
    PUSH_IF_COMPILING(glPointParameterfv)
#endif
    host_functions.glPointParameterfv(pname, params);
}
AliasExport(void,glPointParameterfv,,(GLenum pname, const GLfloat * params));
#endif
#ifndef skip_glPointParameterx
void APIENTRY_GL4ES gl4es_glPointParameterx(GLenum pname, GLfixed param) {
    
#ifndef direct_glPointParameterx
    PUSH_IF_COMPILING(glPointParameterx)
#endif
    host_functions.glPointParameterx(pname, param);
}
AliasExport(void,glPointParameterx,,(GLenum pname, GLfixed param));
#endif
#ifndef skip_glPointParameterxv
void APIENTRY_GL4ES gl4es_glPointParameterxv(GLenum pname, const GLfixed * params) {
    
#ifndef direct_glPointParameterxv
    PUSH_IF_COMPILING(glPointParameterxv)
#endif
    host_functions.glPointParameterxv(pname, params);
}
AliasExport(void,glPointParameterxv,,(GLenum pname, const GLfixed * params));
#endif
#ifndef skip_glPointSize
void APIENTRY_GL4ES gl4es_glPointSize(GLfloat size) {
    
#ifndef direct_glPointSize
    PUSH_IF_COMPILING(glPointSize)
#endif
    host_functions.glPointSize(size);
}
AliasExport(void,glPointSize,,(GLfloat size));
#endif
#ifndef skip_glPointSizePointerOES
void APIENTRY_GL4ES gl4es_glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer) {
    
#ifndef direct_glPointSizePointerOES
    PUSH_IF_COMPILING(glPointSizePointerOES)
#endif
    host_functions.glPointSizePointerOES(type, stride, pointer);
}
AliasExport(void,glPointSizePointerOES,,(GLenum type, GLsizei stride, const GLvoid * pointer));
#endif
#ifndef skip_glPointSizex
void APIENTRY_GL4ES gl4es_glPointSizex(GLfixed size) {
    
#ifndef direct_glPointSizex
    PUSH_IF_COMPILING(glPointSizex)
#endif
    host_functions.glPointSizex(size);
}
AliasExport(void,glPointSizex,,(GLfixed size));
#endif
#ifndef skip_glPolygonOffset
void APIENTRY_GL4ES gl4es_glPolygonOffset(GLfloat factor, GLfloat units) {
    
#ifndef direct_glPolygonOffset
    PUSH_IF_COMPILING(glPolygonOffset)
#endif
    host_functions.glPolygonOffset(factor, units);
}
AliasExport(void,glPolygonOffset,,(GLfloat factor, GLfloat units));
#endif
#ifndef skip_glPolygonOffsetx
void APIENTRY_GL4ES gl4es_glPolygonOffsetx(GLfixed factor, GLfixed units) {
    
#ifndef direct_glPolygonOffsetx
    PUSH_IF_COMPILING(glPolygonOffsetx)
#endif
    host_functions.glPolygonOffsetx(factor, units);
}
AliasExport(void,glPolygonOffsetx,,(GLfixed factor, GLfixed units));
#endif
#ifndef skip_glPopMatrix
void APIENTRY_GL4ES gl4es_glPopMatrix(void) {
    
#ifndef direct_glPopMatrix
    PUSH_IF_COMPILING(glPopMatrix)
#endif
    host_functions.glPopMatrix();
}
AliasExport(void,glPopMatrix,,());
#endif
#ifndef skip_glProgramBinary
void APIENTRY_GL4ES gl4es_glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid * binary, GLint length) {
    
#ifndef direct_glProgramBinary
    PUSH_IF_COMPILING(glProgramBinary)
#endif
    host_functions.glProgramBinary(program, binaryFormat, binary, length);
}
AliasExport(void,glProgramBinary,,(GLuint program, GLenum binaryFormat, const GLvoid * binary, GLint length));
#endif
#ifndef skip_glPushMatrix
void APIENTRY_GL4ES gl4es_glPushMatrix(void) {
    
#ifndef direct_glPushMatrix
    PUSH_IF_COMPILING(glPushMatrix)
#endif
    host_functions.glPushMatrix();
}
AliasExport(void,glPushMatrix,,());
#endif
#ifndef skip_glReadPixels
void APIENTRY_GL4ES gl4es_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    
#ifndef direct_glReadPixels
    PUSH_IF_COMPILING(glReadPixels)
#endif
    host_functions.glReadPixels(x, y, width, height, format, type, pixels);
}
AliasExport(void,glReadPixels,,(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels));
#endif
#ifndef skip_glReleaseShaderCompiler
void APIENTRY_GL4ES gl4es_glReleaseShaderCompiler() {
    
#ifndef direct_glReleaseShaderCompiler
    PUSH_IF_COMPILING(glReleaseShaderCompiler)
#endif
    host_functions.glReleaseShaderCompiler();
}
AliasExport(void,glReleaseShaderCompiler,,());
#endif
#ifndef skip_glRenderbufferStorage
void APIENTRY_GL4ES gl4es_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    
#ifndef direct_glRenderbufferStorage
    PUSH_IF_COMPILING(glRenderbufferStorage)
#endif
    host_functions.glRenderbufferStorage(target, internalformat, width, height);
}
AliasExport(void,glRenderbufferStorage,,(GLenum target, GLenum internalformat, GLsizei width, GLsizei height));
#endif
#ifndef skip_glRotatef
void APIENTRY_GL4ES gl4es_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    
#ifndef direct_glRotatef
    PUSH_IF_COMPILING(glRotatef)
#endif
    host_functions.glRotatef(angle, x, y, z);
}
AliasExport(void,glRotatef,,(GLfloat angle, GLfloat x, GLfloat y, GLfloat z));
#endif
#ifndef skip_glRotatex
void APIENTRY_GL4ES gl4es_glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
    
#ifndef direct_glRotatex
    PUSH_IF_COMPILING(glRotatex)
#endif
    host_functions.glRotatex(angle, x, y, z);
}
AliasExport(void,glRotatex,,(GLfixed angle, GLfixed x, GLfixed y, GLfixed z));
#endif
#ifndef skip_glSampleCoverage
void APIENTRY_GL4ES gl4es_glSampleCoverage(GLclampf value, GLboolean invert) {
    
#ifndef direct_glSampleCoverage
    PUSH_IF_COMPILING(glSampleCoverage)
#endif
    host_functions.glSampleCoverage(value, invert);
}
AliasExport(void,glSampleCoverage,,(GLclampf value, GLboolean invert));
#endif
#ifndef skip_glSampleCoveragex
void APIENTRY_GL4ES gl4es_glSampleCoveragex(GLclampx value, GLboolean invert) {
    
#ifndef direct_glSampleCoveragex
    PUSH_IF_COMPILING(glSampleCoveragex)
#endif
    host_functions.glSampleCoveragex(value, invert);
}
AliasExport(void,glSampleCoveragex,,(GLclampx value, GLboolean invert));
#endif
#ifndef skip_glScalef
void APIENTRY_GL4ES gl4es_glScalef(GLfloat x, GLfloat y, GLfloat z) {
    
#ifndef direct_glScalef
    PUSH_IF_COMPILING(glScalef)
#endif
    host_functions.glScalef(x, y, z);
}
AliasExport(void,glScalef,,(GLfloat x, GLfloat y, GLfloat z));
#endif
#ifndef skip_glScalex
void APIENTRY_GL4ES gl4es_glScalex(GLfixed x, GLfixed y, GLfixed z) {
    
#ifndef direct_glScalex
    PUSH_IF_COMPILING(glScalex)
#endif
    host_functions.glScalex(x, y, z);
}
AliasExport(void,glScalex,,(GLfixed x, GLfixed y, GLfixed z));
#endif
#ifndef skip_glScissor
void APIENTRY_GL4ES gl4es_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    
#ifndef direct_glScissor
    PUSH_IF_COMPILING(glScissor)
#endif
    host_functions.glScissor(x, y, width, height);
}
AliasExport(void,glScissor,,(GLint x, GLint y, GLsizei width, GLsizei height));
#endif
#ifndef skip_glShadeModel
void APIENTRY_GL4ES gl4es_glShadeModel(GLenum mode) {
    
#ifndef direct_glShadeModel
    PUSH_IF_COMPILING(glShadeModel)
#endif
    host_functions.glShadeModel(mode);
}
AliasExport(void,glShadeModel,,(GLenum mode));
#endif
#ifndef skip_glShaderBinary
void APIENTRY_GL4ES gl4es_glShaderBinary(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length) {
    
#ifndef direct_glShaderBinary
    PUSH_IF_COMPILING(glShaderBinary)
#endif
    host_functions.glShaderBinary(n, shaders, binaryformat, binary, length);
}
AliasExport(void,glShaderBinary,,(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length));
#endif
#ifndef skip_glShaderSource
void APIENTRY_GL4ES gl4es_glShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length) {
    
#ifndef direct_glShaderSource
    PUSH_IF_COMPILING(glShaderSource)
#endif
    host_functions.glShaderSource(shader, count, string, length);
}
AliasExport(void,glShaderSource,,(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length));
#endif
#ifndef skip_glStencilFunc
void APIENTRY_GL4ES gl4es_glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    
#ifndef direct_glStencilFunc
    PUSH_IF_COMPILING(glStencilFunc)
#endif
    host_functions.glStencilFunc(func, ref, mask);
}
AliasExport(void,glStencilFunc,,(GLenum func, GLint ref, GLuint mask));
#endif
#ifndef skip_glStencilFuncSeparate
void APIENTRY_GL4ES gl4es_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    
#ifndef direct_glStencilFuncSeparate
    PUSH_IF_COMPILING(glStencilFuncSeparate)
#endif
    host_functions.glStencilFuncSeparate(face, func, ref, mask);
}
AliasExport(void,glStencilFuncSeparate,,(GLenum face, GLenum func, GLint ref, GLuint mask));
#endif
#ifndef skip_glStencilMask
void APIENTRY_GL4ES gl4es_glStencilMask(GLuint mask) {
    
#ifndef direct_glStencilMask
    PUSH_IF_COMPILING(glStencilMask)
#endif
    host_functions.glStencilMask(mask);
}
AliasExport(void,glStencilMask,,(GLuint mask));
#endif
#ifndef skip_glStencilMaskSeparate
void APIENTRY_GL4ES gl4es_glStencilMaskSeparate(GLenum face, GLuint mask) {
    
#ifndef direct_glStencilMaskSeparate
    PUSH_IF_COMPILING(glStencilMaskSeparate)
#endif
    host_functions.glStencilMaskSeparate(face, mask);
}
AliasExport(void,glStencilMaskSeparate,,(GLenum face, GLuint mask));
#endif
#ifndef skip_glStencilOp
void APIENTRY_GL4ES gl4es_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    
#ifndef direct_glStencilOp
    PUSH_IF_COMPILING(glStencilOp)
#endif
    host_functions.glStencilOp(fail, zfail, zpass);
}
AliasExport(void,glStencilOp,,(GLenum fail, GLenum zfail, GLenum zpass));
#endif
#ifndef skip_glStencilOpSeparate
void APIENTRY_GL4ES gl4es_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass) {
    
#ifndef direct_glStencilOpSeparate
    PUSH_IF_COMPILING(glStencilOpSeparate)
#endif
    host_functions.glStencilOpSeparate(face, sfail, zfail, zpass);
}
AliasExport(void,glStencilOpSeparate,,(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass));
#endif
#ifndef skip_glTexCoordPointer
void APIENTRY_GL4ES gl4es_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    
#ifndef direct_glTexCoordPointer
    PUSH_IF_COMPILING(glTexCoordPointer)
#endif
    host_functions.glTexCoordPointer(size, type, stride, pointer);
}
AliasExport(void,glTexCoordPointer,,(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer));
#endif
#ifndef skip_glTexEnvf
void APIENTRY_GL4ES gl4es_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    
#ifndef direct_glTexEnvf
    PUSH_IF_COMPILING(glTexEnvf)
#endif
    host_functions.glTexEnvf(target, pname, param);
}
AliasExport(void,glTexEnvf,,(GLenum target, GLenum pname, GLfloat param));
#endif
#ifndef skip_glTexEnvfv
void APIENTRY_GL4ES gl4es_glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    
#ifndef direct_glTexEnvfv
    PUSH_IF_COMPILING(glTexEnvfv)
#endif
    host_functions.glTexEnvfv(target, pname, params);
}
AliasExport(void,glTexEnvfv,,(GLenum target, GLenum pname, const GLfloat * params));
#endif
#ifndef skip_glTexEnvi
void APIENTRY_GL4ES gl4es_glTexEnvi(GLenum target, GLenum pname, GLint param) {
    
#ifndef direct_glTexEnvi
    PUSH_IF_COMPILING(glTexEnvi)
#endif
    host_functions.glTexEnvi(target, pname, param);
}
AliasExport(void,glTexEnvi,,(GLenum target, GLenum pname, GLint param));
#endif
#ifndef skip_glTexEnviv
void APIENTRY_GL4ES gl4es_glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    
#ifndef direct_glTexEnviv
    PUSH_IF_COMPILING(glTexEnviv)
#endif
    host_functions.glTexEnviv(target, pname, params);
}
AliasExport(void,glTexEnviv,,(GLenum target, GLenum pname, const GLint * params));
#endif
#ifndef skip_glTexEnvx
void APIENTRY_GL4ES gl4es_glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
    
#ifndef direct_glTexEnvx
    PUSH_IF_COMPILING(glTexEnvx)
#endif
    host_functions.glTexEnvx(target, pname, param);
}
AliasExport(void,glTexEnvx,,(GLenum target, GLenum pname, GLfixed param));
#endif
#ifndef skip_glTexEnvxv
void APIENTRY_GL4ES gl4es_glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params) {
    
#ifndef direct_glTexEnvxv
    PUSH_IF_COMPILING(glTexEnvxv)
#endif
    host_functions.glTexEnvxv(target, pname, params);
}
AliasExport(void,glTexEnvxv,,(GLenum target, GLenum pname, const GLfixed * params));
#endif
#ifndef skip_glTexGenfv
void APIENTRY_GL4ES gl4es_glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    
#ifndef direct_glTexGenfv
    PUSH_IF_COMPILING(glTexGenfv)
#endif
    host_functions.glTexGenfv(coord, pname, params);
}
AliasExport(void,glTexGenfv,,(GLenum coord, GLenum pname, const GLfloat * params));
#endif
#ifndef skip_glTexGeni
void APIENTRY_GL4ES gl4es_glTexGeni(GLenum coord, GLenum pname, GLint param) {
    
#ifndef direct_glTexGeni
    PUSH_IF_COMPILING(glTexGeni)
#endif
    host_functions.glTexGeni(coord, pname, param);
}
AliasExport(void,glTexGeni,,(GLenum coord, GLenum pname, GLint param));
#endif
#ifndef skip_glTexImage2D
void APIENTRY_GL4ES gl4es_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data) {
    
#ifndef direct_glTexImage2D
    PUSH_IF_COMPILING(glTexImage2D)
#endif
    host_functions.glTexImage2D(target, level, internalformat, width, height, border, format, type, data);
}
AliasExport(void,glTexImage2D,,(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data));
#endif
#ifndef skip_glTexParameterf
void APIENTRY_GL4ES gl4es_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    
#ifndef direct_glTexParameterf
    PUSH_IF_COMPILING(glTexParameterf)
#endif
    host_functions.glTexParameterf(target, pname, param);
}
AliasExport(void,glTexParameterf,,(GLenum target, GLenum pname, GLfloat param));
#endif
#ifndef skip_glTexParameterfv
void APIENTRY_GL4ES gl4es_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    
#ifndef direct_glTexParameterfv
    PUSH_IF_COMPILING(glTexParameterfv)
#endif
    host_functions.glTexParameterfv(target, pname, params);
}
AliasExport(void,glTexParameterfv,,(GLenum target, GLenum pname, const GLfloat * params));
#endif
#ifndef skip_glTexParameteri
void APIENTRY_GL4ES gl4es_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    
#ifndef direct_glTexParameteri
    PUSH_IF_COMPILING(glTexParameteri)
#endif
    host_functions.glTexParameteri(target, pname, param);
}
AliasExport(void,glTexParameteri,,(GLenum target, GLenum pname, GLint param));
#endif
#ifndef skip_glTexParameteriv
void APIENTRY_GL4ES gl4es_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    
#ifndef direct_glTexParameteriv
    PUSH_IF_COMPILING(glTexParameteriv)
#endif
    host_functions.glTexParameteriv(target, pname, params);
}
AliasExport(void,glTexParameteriv,,(GLenum target, GLenum pname, const GLint * params));
#endif
#ifndef skip_glTexParameterx
void APIENTRY_GL4ES gl4es_glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
    
#ifndef direct_glTexParameterx
    PUSH_IF_COMPILING(glTexParameterx)
#endif
    host_functions.glTexParameterx(target, pname, param);
}
AliasExport(void,glTexParameterx,,(GLenum target, GLenum pname, GLfixed param));
#endif
#ifndef skip_glTexParameterxv
void APIENTRY_GL4ES gl4es_glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params) {
    
#ifndef direct_glTexParameterxv
    PUSH_IF_COMPILING(glTexParameterxv)
#endif
    host_functions.glTexParameterxv(target, pname, params);
}
AliasExport(void,glTexParameterxv,,(GLenum target, GLenum pname, const GLfixed * params));
#endif
#ifndef skip_glTexSubImage2D
void APIENTRY_GL4ES gl4es_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * data) {
    
#ifndef direct_glTexSubImage2D
    PUSH_IF_COMPILING(glTexSubImage2D)
#endif
    host_functions.glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, data);
}
AliasExport(void,glTexSubImage2D,,(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * data));
#endif
#ifndef skip_glTranslatef
void APIENTRY_GL4ES gl4es_glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    
#ifndef direct_glTranslatef
    PUSH_IF_COMPILING(glTranslatef)
#endif
    host_functions.glTranslatef(x, y, z);
}
AliasExport(void,glTranslatef,,(GLfloat x, GLfloat y, GLfloat z));
#endif
#ifndef skip_glTranslatex
void APIENTRY_GL4ES gl4es_glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
    
#ifndef direct_glTranslatex
    PUSH_IF_COMPILING(glTranslatex)
#endif
    host_functions.glTranslatex(x, y, z);
}
AliasExport(void,glTranslatex,,(GLfixed x, GLfixed y, GLfixed z));
#endif
#ifndef skip_glUniform1f
void APIENTRY_GL4ES gl4es_glUniform1f(GLint location, GLfloat v0) {
    
#ifndef direct_glUniform1f
    PUSH_IF_COMPILING(glUniform1f)
#endif
    host_functions.glUniform1f(location, v0);
}
AliasExport(void,glUniform1f,,(GLint location, GLfloat v0));
#endif
#ifndef skip_glUniform1fv
void APIENTRY_GL4ES gl4es_glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    
#ifndef direct_glUniform1fv
    PUSH_IF_COMPILING(glUniform1fv)
#endif
    host_functions.glUniform1fv(location, count, value);
}
AliasExport(void,glUniform1fv,,(GLint location, GLsizei count, const GLfloat * value));
#endif
#ifndef skip_glUniform1i
void APIENTRY_GL4ES gl4es_glUniform1i(GLint location, GLint v0) {
    
#ifndef direct_glUniform1i
    PUSH_IF_COMPILING(glUniform1i)
#endif
    host_functions.glUniform1i(location, v0);
}
AliasExport(void,glUniform1i,,(GLint location, GLint v0));
#endif
#ifndef skip_glUniform1iv
void APIENTRY_GL4ES gl4es_glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    
#ifndef direct_glUniform1iv
    PUSH_IF_COMPILING(glUniform1iv)
#endif
    host_functions.glUniform1iv(location, count, value);
}
AliasExport(void,glUniform1iv,,(GLint location, GLsizei count, const GLint * value));
#endif
#ifndef skip_glUniform2f
void APIENTRY_GL4ES gl4es_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    
#ifndef direct_glUniform2f
    PUSH_IF_COMPILING(glUniform2f)
#endif
    host_functions.glUniform2f(location, v0, v1);
}
AliasExport(void,glUniform2f,,(GLint location, GLfloat v0, GLfloat v1));
#endif
#ifndef skip_glUniform2fv
void APIENTRY_GL4ES gl4es_glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    
#ifndef direct_glUniform2fv
    PUSH_IF_COMPILING(glUniform2fv)
#endif
    host_functions.glUniform2fv(location, count, value);
}
AliasExport(void,glUniform2fv,,(GLint location, GLsizei count, const GLfloat * value));
#endif
#ifndef skip_glUniform2i
void APIENTRY_GL4ES gl4es_glUniform2i(GLint location, GLint v0, GLint v1) {
    
#ifndef direct_glUniform2i
    PUSH_IF_COMPILING(glUniform2i)
#endif
    host_functions.glUniform2i(location, v0, v1);
}
AliasExport(void,glUniform2i,,(GLint location, GLint v0, GLint v1));
#endif
#ifndef skip_glUniform2iv
void APIENTRY_GL4ES gl4es_glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    
#ifndef direct_glUniform2iv
    PUSH_IF_COMPILING(glUniform2iv)
#endif
    host_functions.glUniform2iv(location, count, value);
}
AliasExport(void,glUniform2iv,,(GLint location, GLsizei count, const GLint * value));
#endif
#ifndef skip_glUniform3f
void APIENTRY_GL4ES gl4es_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    
#ifndef direct_glUniform3f
    PUSH_IF_COMPILING(glUniform3f)
#endif
    host_functions.glUniform3f(location, v0, v1, v2);
}
AliasExport(void,glUniform3f,,(GLint location, GLfloat v0, GLfloat v1, GLfloat v2));
#endif
#ifndef skip_glUniform3fv
void APIENTRY_GL4ES gl4es_glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    
#ifndef direct_glUniform3fv
    PUSH_IF_COMPILING(glUniform3fv)
#endif
    host_functions.glUniform3fv(location, count, value);
}
AliasExport(void,glUniform3fv,,(GLint location, GLsizei count, const GLfloat * value));
#endif
#ifndef skip_glUniform3i
void APIENTRY_GL4ES gl4es_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    
#ifndef direct_glUniform3i
    PUSH_IF_COMPILING(glUniform3i)
#endif
    host_functions.glUniform3i(location, v0, v1, v2);
}
AliasExport(void,glUniform3i,,(GLint location, GLint v0, GLint v1, GLint v2));
#endif
#ifndef skip_glUniform3iv
void APIENTRY_GL4ES gl4es_glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    
#ifndef direct_glUniform3iv
    PUSH_IF_COMPILING(glUniform3iv)
#endif
    host_functions.glUniform3iv(location, count, value);
}
AliasExport(void,glUniform3iv,,(GLint location, GLsizei count, const GLint * value));
#endif
#ifndef skip_glUniform4f
void APIENTRY_GL4ES gl4es_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    
#ifndef direct_glUniform4f
    PUSH_IF_COMPILING(glUniform4f)
#endif
    host_functions.glUniform4f(location, v0, v1, v2, v3);
}
AliasExport(void,glUniform4f,,(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3));
#endif
#ifndef skip_glUniform4fv
void APIENTRY_GL4ES gl4es_glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    
#ifndef direct_glUniform4fv
    PUSH_IF_COMPILING(glUniform4fv)
#endif
    host_functions.glUniform4fv(location, count, value);
}
AliasExport(void,glUniform4fv,,(GLint location, GLsizei count, const GLfloat * value));
#endif
#ifndef skip_glUniform4i
void APIENTRY_GL4ES gl4es_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    
#ifndef direct_glUniform4i
    PUSH_IF_COMPILING(glUniform4i)
#endif
    host_functions.glUniform4i(location, v0, v1, v2, v3);
}
AliasExport(void,glUniform4i,,(GLint location, GLint v0, GLint v1, GLint v2, GLint v3));
#endif
#ifndef skip_glUniform4iv
void APIENTRY_GL4ES gl4es_glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    
#ifndef direct_glUniform4iv
    PUSH_IF_COMPILING(glUniform4iv)
#endif
    host_functions.glUniform4iv(location, count, value);
}
AliasExport(void,glUniform4iv,,(GLint location, GLsizei count, const GLint * value));
#endif
#ifndef skip_glUniformMatrix2fv
void APIENTRY_GL4ES gl4es_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    
#ifndef direct_glUniformMatrix2fv
    PUSH_IF_COMPILING(glUniformMatrix2fv)
#endif
    host_functions.glUniformMatrix2fv(location, count, transpose, value);
}
AliasExport(void,glUniformMatrix2fv,,(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value));
#endif
#ifndef skip_glUniformMatrix3fv
void APIENTRY_GL4ES gl4es_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    
#ifndef direct_glUniformMatrix3fv
    PUSH_IF_COMPILING(glUniformMatrix3fv)
#endif
    host_functions.glUniformMatrix3fv(location, count, transpose, value);
}
AliasExport(void,glUniformMatrix3fv,,(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value));
#endif
#ifndef skip_glUniformMatrix4fv
void APIENTRY_GL4ES gl4es_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    
#ifndef direct_glUniformMatrix4fv
    PUSH_IF_COMPILING(glUniformMatrix4fv)
#endif
    host_functions.glUniformMatrix4fv(location, count, transpose, value);
}
AliasExport(void,glUniformMatrix4fv,,(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value));
#endif
#ifndef skip_glUseProgram
void APIENTRY_GL4ES gl4es_glUseProgram(GLuint program) {
    
#ifndef direct_glUseProgram
    PUSH_IF_COMPILING(glUseProgram)
#endif
    host_functions.glUseProgram(program);
}
AliasExport(void,glUseProgram,,(GLuint program));
#endif
#ifndef skip_glValidateProgram
void APIENTRY_GL4ES gl4es_glValidateProgram(GLuint program) {
    
#ifndef direct_glValidateProgram
    PUSH_IF_COMPILING(glValidateProgram)
#endif
    host_functions.glValidateProgram(program);
}
AliasExport(void,glValidateProgram,,(GLuint program));
#endif
#ifndef skip_glVertexAttrib1f
void APIENTRY_GL4ES gl4es_glVertexAttrib1f(GLuint index, GLfloat x) {
    
#ifndef direct_glVertexAttrib1f
    PUSH_IF_COMPILING(glVertexAttrib1f)
#endif
    host_functions.glVertexAttrib1f(index, x);
}
AliasExport(void,glVertexAttrib1f,,(GLuint index, GLfloat x));
#endif
#ifndef skip_glVertexAttrib1fv
void APIENTRY_GL4ES gl4es_glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    
#ifndef direct_glVertexAttrib1fv
    PUSH_IF_COMPILING(glVertexAttrib1fv)
#endif
    host_functions.glVertexAttrib1fv(index, v);
}
AliasExport(void,glVertexAttrib1fv,,(GLuint index, const GLfloat * v));
#endif
#ifndef skip_glVertexAttrib2f
void APIENTRY_GL4ES gl4es_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    
#ifndef direct_glVertexAttrib2f
    PUSH_IF_COMPILING(glVertexAttrib2f)
#endif
    host_functions.glVertexAttrib2f(index, x, y);
}
AliasExport(void,glVertexAttrib2f,,(GLuint index, GLfloat x, GLfloat y));
#endif
#ifndef skip_glVertexAttrib2fv
void APIENTRY_GL4ES gl4es_glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    
#ifndef direct_glVertexAttrib2fv
    PUSH_IF_COMPILING(glVertexAttrib2fv)
#endif
    host_functions.glVertexAttrib2fv(index, v);
}
AliasExport(void,glVertexAttrib2fv,,(GLuint index, const GLfloat * v));
#endif
#ifndef skip_glVertexAttrib3f
void APIENTRY_GL4ES gl4es_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    
#ifndef direct_glVertexAttrib3f
    PUSH_IF_COMPILING(glVertexAttrib3f)
#endif
    host_functions.glVertexAttrib3f(index, x, y, z);
}
AliasExport(void,glVertexAttrib3f,,(GLuint index, GLfloat x, GLfloat y, GLfloat z));
#endif
#ifndef skip_glVertexAttrib3fv
void APIENTRY_GL4ES gl4es_glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    
#ifndef direct_glVertexAttrib3fv
    PUSH_IF_COMPILING(glVertexAttrib3fv)
#endif
    host_functions.glVertexAttrib3fv(index, v);
}
AliasExport(void,glVertexAttrib3fv,,(GLuint index, const GLfloat * v));
#endif
#ifndef skip_glVertexAttrib4f
void APIENTRY_GL4ES gl4es_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
#ifndef direct_glVertexAttrib4f
    PUSH_IF_COMPILING(glVertexAttrib4f)
#endif
    host_functions.glVertexAttrib4f(index, x, y, z, w);
}
AliasExport(void,glVertexAttrib4f,,(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w));
#endif
#ifndef skip_glVertexAttrib4fv
void APIENTRY_GL4ES gl4es_glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    
#ifndef direct_glVertexAttrib4fv
    PUSH_IF_COMPILING(glVertexAttrib4fv)
#endif
    host_functions.glVertexAttrib4fv(index, v);
}
AliasExport(void,glVertexAttrib4fv,,(GLuint index, const GLfloat * v));
#endif
#ifndef skip_glVertexAttribPointer
void APIENTRY_GL4ES gl4es_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
    
#ifndef direct_glVertexAttribPointer
    PUSH_IF_COMPILING(glVertexAttribPointer)
#endif
    host_functions.glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
AliasExport(void,glVertexAttribPointer,,(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer));
#endif
#ifndef skip_glVertexAttribIPointer
void APIENTRY_GL4ES gl4es_glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    
#ifndef direct_glVertexAttribIPointer
    PUSH_IF_COMPILING(glVertexAttribIPointer)
#endif
    host_functions.glVertexAttribIPointer(index, size, type, stride, pointer);
}
AliasExport(void,glVertexAttribIPointer,,(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer));
#endif
#ifndef skip_glVertexPointer
void APIENTRY_GL4ES gl4es_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    
#ifndef direct_glVertexPointer
    PUSH_IF_COMPILING(glVertexPointer)
#endif
    host_functions.glVertexPointer(size, type, stride, pointer);
}
AliasExport(void,glVertexPointer,,(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer));
#endif
#ifndef skip_glViewport
void APIENTRY_GL4ES gl4es_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    
#ifndef direct_glViewport
    PUSH_IF_COMPILING(glViewport)
#endif
    host_functions.glViewport(x, y, width, height);
}
AliasExport(void,glViewport,,(GLint x, GLint y, GLsizei width, GLsizei height));
#endif
void APIENTRY_GL4ES glPackedCall(const packed_call_t *packed) {
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
