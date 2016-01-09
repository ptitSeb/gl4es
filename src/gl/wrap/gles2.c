#ifdef USE_ES2
#include "gles2.h"
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
#ifndef skip_glAttachShader
void glshim_glAttachShader(GLuint program, GLuint shader) {
    LOAD_GLES(glAttachShader);
#ifndef direct_glAttachShader
    PUSH_IF_COMPILING(glAttachShader)
#endif
    gles_glAttachShader(program, shader);
}
void glAttachShader(GLuint program, GLuint shader) __attribute__((alias("glshim_glAttachShader")));
#endif
#ifndef skip_glBindAttribLocation
void glshim_glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    LOAD_GLES(glBindAttribLocation);
#ifndef direct_glBindAttribLocation
    PUSH_IF_COMPILING(glBindAttribLocation)
#endif
    gles_glBindAttribLocation(program, index, name);
}
void glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) __attribute__((alias("glshim_glBindAttribLocation")));
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
#ifndef skip_glBindFramebuffer
void glshim_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    LOAD_GLES(glBindFramebuffer);
#ifndef direct_glBindFramebuffer
    PUSH_IF_COMPILING(glBindFramebuffer)
#endif
    gles_glBindFramebuffer(target, framebuffer);
}
void glBindFramebuffer(GLenum target, GLuint framebuffer) __attribute__((alias("glshim_glBindFramebuffer")));
#endif
#ifndef skip_glBindRenderbuffer
void glshim_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    LOAD_GLES(glBindRenderbuffer);
#ifndef direct_glBindRenderbuffer
    PUSH_IF_COMPILING(glBindRenderbuffer)
#endif
    gles_glBindRenderbuffer(target, renderbuffer);
}
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) __attribute__((alias("glshim_glBindRenderbuffer")));
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
#ifndef skip_glBlendColor
void glshim_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    LOAD_GLES(glBlendColor);
#ifndef direct_glBlendColor
    PUSH_IF_COMPILING(glBlendColor)
#endif
    gles_glBlendColor(red, green, blue, alpha);
}
void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) __attribute__((alias("glshim_glBlendColor")));
#endif
#ifndef skip_glBlendEquation
void glshim_glBlendEquation(GLenum mode) {
    LOAD_GLES(glBlendEquation);
#ifndef direct_glBlendEquation
    PUSH_IF_COMPILING(glBlendEquation)
#endif
    gles_glBlendEquation(mode);
}
void glBlendEquation(GLenum mode) __attribute__((alias("glshim_glBlendEquation")));
#endif
#ifndef skip_glBlendEquationSeparate
void glshim_glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    LOAD_GLES(glBlendEquationSeparate);
#ifndef direct_glBlendEquationSeparate
    PUSH_IF_COMPILING(glBlendEquationSeparate)
#endif
    gles_glBlendEquationSeparate(modeRGB, modeA);
}
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) __attribute__((alias("glshim_glBlendEquationSeparate")));
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
#ifndef skip_glBlendFuncSeparate
void glshim_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    LOAD_GLES(glBlendFuncSeparate);
#ifndef direct_glBlendFuncSeparate
    PUSH_IF_COMPILING(glBlendFuncSeparate)
#endif
    gles_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) __attribute__((alias("glshim_glBlendFuncSeparate")));
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
#ifndef skip_glCheckFramebufferStatus
GLenum glshim_glCheckFramebufferStatus(GLenum target) {
    LOAD_GLES(glCheckFramebufferStatus);
#ifndef direct_glCheckFramebufferStatus
    PUSH_IF_COMPILING(glCheckFramebufferStatus)
#endif
    return gles_glCheckFramebufferStatus(target);
}
GLenum glCheckFramebufferStatus(GLenum target) __attribute__((alias("glshim_glCheckFramebufferStatus")));
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
#ifndef skip_glCompileShader
void glshim_glCompileShader(GLuint shader) {
    LOAD_GLES(glCompileShader);
#ifndef direct_glCompileShader
    PUSH_IF_COMPILING(glCompileShader)
#endif
    gles_glCompileShader(shader);
}
void glCompileShader(GLuint shader) __attribute__((alias("glshim_glCompileShader")));
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
#ifndef skip_glCreateProgram
GLuint glshim_glCreateProgram() {
    LOAD_GLES(glCreateProgram);
#ifndef direct_glCreateProgram
    PUSH_IF_COMPILING(glCreateProgram)
#endif
    return gles_glCreateProgram();
}
GLuint glCreateProgram() __attribute__((alias("glshim_glCreateProgram")));
#endif
#ifndef skip_glCreateShader
GLuint glshim_glCreateShader(GLenum type) {
    LOAD_GLES(glCreateShader);
#ifndef direct_glCreateShader
    PUSH_IF_COMPILING(glCreateShader)
#endif
    return gles_glCreateShader(type);
}
GLuint glCreateShader(GLenum type) __attribute__((alias("glshim_glCreateShader")));
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
void glshim_glDeleteBuffers(GLsizei n, const GLuint * buffer) {
    LOAD_GLES(glDeleteBuffers);
#ifndef direct_glDeleteBuffers
    PUSH_IF_COMPILING(glDeleteBuffers)
#endif
    gles_glDeleteBuffers(n, buffer);
}
void glDeleteBuffers(GLsizei n, const GLuint * buffer) __attribute__((alias("glshim_glDeleteBuffers")));
#endif
#ifndef skip_glDeleteFramebuffers
void glshim_glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers) {
    LOAD_GLES(glDeleteFramebuffers);
#ifndef direct_glDeleteFramebuffers
    PUSH_IF_COMPILING(glDeleteFramebuffers)
#endif
    gles_glDeleteFramebuffers(n, framebuffers);
}
void glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers) __attribute__((alias("glshim_glDeleteFramebuffers")));
#endif
#ifndef skip_glDeleteProgram
void glshim_glDeleteProgram(GLuint program) {
    LOAD_GLES(glDeleteProgram);
#ifndef direct_glDeleteProgram
    PUSH_IF_COMPILING(glDeleteProgram)
#endif
    gles_glDeleteProgram(program);
}
void glDeleteProgram(GLuint program) __attribute__((alias("glshim_glDeleteProgram")));
#endif
#ifndef skip_glDeleteRenderbuffers
void glshim_glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers) {
    LOAD_GLES(glDeleteRenderbuffers);
#ifndef direct_glDeleteRenderbuffers
    PUSH_IF_COMPILING(glDeleteRenderbuffers)
#endif
    gles_glDeleteRenderbuffers(n, renderbuffers);
}
void glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers) __attribute__((alias("glshim_glDeleteRenderbuffers")));
#endif
#ifndef skip_glDeleteShader
void glshim_glDeleteShader(GLuint program) {
    LOAD_GLES(glDeleteShader);
#ifndef direct_glDeleteShader
    PUSH_IF_COMPILING(glDeleteShader)
#endif
    gles_glDeleteShader(program);
}
void glDeleteShader(GLuint program) __attribute__((alias("glshim_glDeleteShader")));
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
void glshim_glDepthRangef(GLclampf zNear, GLclampf zFar) {
    LOAD_GLES(glDepthRangef);
#ifndef direct_glDepthRangef
    PUSH_IF_COMPILING(glDepthRangef)
#endif
    gles_glDepthRangef(zNear, zFar);
}
void glDepthRangef(GLclampf zNear, GLclampf zFar) __attribute__((alias("glshim_glDepthRangef")));
#endif
#ifndef skip_glDetachShader
void glshim_glDetachShader(GLuint program, GLuint shader) {
    LOAD_GLES(glDetachShader);
#ifndef direct_glDetachShader
    PUSH_IF_COMPILING(glDetachShader)
#endif
    gles_glDetachShader(program, shader);
}
void glDetachShader(GLuint program, GLuint shader) __attribute__((alias("glshim_glDetachShader")));
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
#ifndef skip_glDisableVertexAttribArray
void glshim_glDisableVertexAttribArray(GLuint index) {
    LOAD_GLES(glDisableVertexAttribArray);
#ifndef direct_glDisableVertexAttribArray
    PUSH_IF_COMPILING(glDisableVertexAttribArray)
#endif
    gles_glDisableVertexAttribArray(index);
}
void glDisableVertexAttribArray(GLuint index) __attribute__((alias("glshim_glDisableVertexAttribArray")));
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
#ifndef skip_glEnableVertexAttribArray
void glshim_glEnableVertexAttribArray(GLuint index) {
    LOAD_GLES(glEnableVertexAttribArray);
#ifndef direct_glEnableVertexAttribArray
    PUSH_IF_COMPILING(glEnableVertexAttribArray)
#endif
    gles_glEnableVertexAttribArray(index);
}
void glEnableVertexAttribArray(GLuint index) __attribute__((alias("glshim_glEnableVertexAttribArray")));
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
#ifndef skip_glFramebufferRenderbuffer
void glshim_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    LOAD_GLES(glFramebufferRenderbuffer);
#ifndef direct_glFramebufferRenderbuffer
    PUSH_IF_COMPILING(glFramebufferRenderbuffer)
#endif
    gles_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) __attribute__((alias("glshim_glFramebufferRenderbuffer")));
#endif
#ifndef skip_glFramebufferTexture2D
void glshim_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    LOAD_GLES(glFramebufferTexture2D);
#ifndef direct_glFramebufferTexture2D
    PUSH_IF_COMPILING(glFramebufferTexture2D)
#endif
    gles_glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) __attribute__((alias("glshim_glFramebufferTexture2D")));
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
#ifndef skip_glGenBuffers
void glshim_glGenBuffers(GLsizei n, GLuint * buffer) {
    LOAD_GLES(glGenBuffers);
#ifndef direct_glGenBuffers
    PUSH_IF_COMPILING(glGenBuffers)
#endif
    gles_glGenBuffers(n, buffer);
}
void glGenBuffers(GLsizei n, GLuint * buffer) __attribute__((alias("glshim_glGenBuffers")));
#endif
#ifndef skip_glGenFramebuffers
void glshim_glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
    LOAD_GLES(glGenFramebuffers);
#ifndef direct_glGenFramebuffers
    PUSH_IF_COMPILING(glGenFramebuffers)
#endif
    gles_glGenFramebuffers(n, framebuffers);
}
void glGenFramebuffers(GLsizei n, GLuint * framebuffers) __attribute__((alias("glshim_glGenFramebuffers")));
#endif
#ifndef skip_glGenRenderbuffers
void glshim_glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    LOAD_GLES(glGenRenderbuffers);
#ifndef direct_glGenRenderbuffers
    PUSH_IF_COMPILING(glGenRenderbuffers)
#endif
    gles_glGenRenderbuffers(n, renderbuffers);
}
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) __attribute__((alias("glshim_glGenRenderbuffers")));
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
#ifndef skip_glGenerateMipmap
void glshim_glGenerateMipmap(GLenum target) {
    LOAD_GLES(glGenerateMipmap);
#ifndef direct_glGenerateMipmap
    PUSH_IF_COMPILING(glGenerateMipmap)
#endif
    gles_glGenerateMipmap(target);
}
void glGenerateMipmap(GLenum target) __attribute__((alias("glshim_glGenerateMipmap")));
#endif
#ifndef skip_glGetActiveAttrib
void glshim_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    LOAD_GLES(glGetActiveAttrib);
#ifndef direct_glGetActiveAttrib
    PUSH_IF_COMPILING(glGetActiveAttrib)
#endif
    gles_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) __attribute__((alias("glshim_glGetActiveAttrib")));
#endif
#ifndef skip_glGetActiveUniform
void glshim_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    LOAD_GLES(glGetActiveUniform);
#ifndef direct_glGetActiveUniform
    PUSH_IF_COMPILING(glGetActiveUniform)
#endif
    gles_glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) __attribute__((alias("glshim_glGetActiveUniform")));
#endif
#ifndef skip_glGetAttachedShaders
void glshim_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj) {
    LOAD_GLES(glGetAttachedShaders);
#ifndef direct_glGetAttachedShaders
    PUSH_IF_COMPILING(glGetAttachedShaders)
#endif
    gles_glGetAttachedShaders(program, maxCount, count, obj);
}
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj) __attribute__((alias("glshim_glGetAttachedShaders")));
#endif
#ifndef skip_glGetAttribLocation
GLint glshim_glGetAttribLocation(GLuint program, const GLchar * name) {
    LOAD_GLES(glGetAttribLocation);
#ifndef direct_glGetAttribLocation
    PUSH_IF_COMPILING(glGetAttribLocation)
#endif
    return gles_glGetAttribLocation(program, name);
}
GLint glGetAttribLocation(GLuint program, const GLchar * name) __attribute__((alias("glshim_glGetAttribLocation")));
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
#ifndef skip_glGetFramebufferAttachmentParameteriv
void glshim_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    LOAD_GLES(glGetFramebufferAttachmentParameteriv);
#ifndef direct_glGetFramebufferAttachmentParameteriv
    PUSH_IF_COMPILING(glGetFramebufferAttachmentParameteriv)
#endif
    gles_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetFramebufferAttachmentParameteriv")));
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
#ifndef skip_glGetProgramInfoLog
void glshim_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    LOAD_GLES(glGetProgramInfoLog);
#ifndef direct_glGetProgramInfoLog
    PUSH_IF_COMPILING(glGetProgramInfoLog)
#endif
    gles_glGetProgramInfoLog(program, bufSize, length, infoLog);
}
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) __attribute__((alias("glshim_glGetProgramInfoLog")));
#endif
#ifndef skip_glGetProgramiv
void glshim_glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    LOAD_GLES(glGetProgramiv);
#ifndef direct_glGetProgramiv
    PUSH_IF_COMPILING(glGetProgramiv)
#endif
    gles_glGetProgramiv(program, pname, params);
}
void glGetProgramiv(GLuint program, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetProgramiv")));
#endif
#ifndef skip_glGetRenderbufferParameteriv
void glshim_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetRenderbufferParameteriv);
#ifndef direct_glGetRenderbufferParameteriv
    PUSH_IF_COMPILING(glGetRenderbufferParameteriv)
#endif
    gles_glGetRenderbufferParameteriv(target, pname, params);
}
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetRenderbufferParameteriv")));
#endif
#ifndef skip_glGetShaderInfoLog
void glshim_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    LOAD_GLES(glGetShaderInfoLog);
#ifndef direct_glGetShaderInfoLog
    PUSH_IF_COMPILING(glGetShaderInfoLog)
#endif
    gles_glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) __attribute__((alias("glshim_glGetShaderInfoLog")));
#endif
#ifndef skip_glGetShaderPrecisionFormat
void glshim_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
    LOAD_GLES(glGetShaderPrecisionFormat);
#ifndef direct_glGetShaderPrecisionFormat
    PUSH_IF_COMPILING(glGetShaderPrecisionFormat)
#endif
    gles_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) __attribute__((alias("glshim_glGetShaderPrecisionFormat")));
#endif
#ifndef skip_glGetShaderSource
void glshim_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    LOAD_GLES(glGetShaderSource);
#ifndef direct_glGetShaderSource
    PUSH_IF_COMPILING(glGetShaderSource)
#endif
    gles_glGetShaderSource(shader, bufSize, length, source);
}
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) __attribute__((alias("glshim_glGetShaderSource")));
#endif
#ifndef skip_glGetShaderiv
void glshim_glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    LOAD_GLES(glGetShaderiv);
#ifndef direct_glGetShaderiv
    PUSH_IF_COMPILING(glGetShaderiv)
#endif
    gles_glGetShaderiv(shader, pname, params);
}
void glGetShaderiv(GLuint shader, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetShaderiv")));
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
#ifndef skip_glGetUniformLocation
GLint glshim_glGetUniformLocation(GLuint program, const GLchar * name) {
    LOAD_GLES(glGetUniformLocation);
#ifndef direct_glGetUniformLocation
    PUSH_IF_COMPILING(glGetUniformLocation)
#endif
    return gles_glGetUniformLocation(program, name);
}
GLint glGetUniformLocation(GLuint program, const GLchar * name) __attribute__((alias("glshim_glGetUniformLocation")));
#endif
#ifndef skip_glGetUniformfv
void glshim_glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    LOAD_GLES(glGetUniformfv);
#ifndef direct_glGetUniformfv
    PUSH_IF_COMPILING(glGetUniformfv)
#endif
    gles_glGetUniformfv(program, location, params);
}
void glGetUniformfv(GLuint program, GLint location, GLfloat * params) __attribute__((alias("glshim_glGetUniformfv")));
#endif
#ifndef skip_glGetUniformiv
void glshim_glGetUniformiv(GLuint program, GLint location, GLint * params) {
    LOAD_GLES(glGetUniformiv);
#ifndef direct_glGetUniformiv
    PUSH_IF_COMPILING(glGetUniformiv)
#endif
    gles_glGetUniformiv(program, location, params);
}
void glGetUniformiv(GLuint program, GLint location, GLint * params) __attribute__((alias("glshim_glGetUniformiv")));
#endif
#ifndef skip_glGetVertexAttribPointerv
void glshim_glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) {
    LOAD_GLES(glGetVertexAttribPointerv);
#ifndef direct_glGetVertexAttribPointerv
    PUSH_IF_COMPILING(glGetVertexAttribPointerv)
#endif
    gles_glGetVertexAttribPointerv(index, pname, pointer);
}
void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) __attribute__((alias("glshim_glGetVertexAttribPointerv")));
#endif
#ifndef skip_glGetVertexAttribfv
void glshim_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetVertexAttribfv);
#ifndef direct_glGetVertexAttribfv
    PUSH_IF_COMPILING(glGetVertexAttribfv)
#endif
    gles_glGetVertexAttribfv(index, pname, params);
}
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) __attribute__((alias("glshim_glGetVertexAttribfv")));
#endif
#ifndef skip_glGetVertexAttribiv
void glshim_glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    LOAD_GLES(glGetVertexAttribiv);
#ifndef direct_glGetVertexAttribiv
    PUSH_IF_COMPILING(glGetVertexAttribiv)
#endif
    gles_glGetVertexAttribiv(index, pname, params);
}
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetVertexAttribiv")));
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
#ifndef skip_glIsFramebuffer
GLboolean glshim_glIsFramebuffer(GLuint framebuffer) {
    LOAD_GLES(glIsFramebuffer);
#ifndef direct_glIsFramebuffer
    PUSH_IF_COMPILING(glIsFramebuffer)
#endif
    return gles_glIsFramebuffer(framebuffer);
}
GLboolean glIsFramebuffer(GLuint framebuffer) __attribute__((alias("glshim_glIsFramebuffer")));
#endif
#ifndef skip_glIsProgram
GLboolean glshim_glIsProgram(GLuint program) {
    LOAD_GLES(glIsProgram);
#ifndef direct_glIsProgram
    PUSH_IF_COMPILING(glIsProgram)
#endif
    return gles_glIsProgram(program);
}
GLboolean glIsProgram(GLuint program) __attribute__((alias("glshim_glIsProgram")));
#endif
#ifndef skip_glIsRenderbuffer
GLboolean glshim_glIsRenderbuffer(GLuint renderbuffer) {
    LOAD_GLES(glIsRenderbuffer);
#ifndef direct_glIsRenderbuffer
    PUSH_IF_COMPILING(glIsRenderbuffer)
#endif
    return gles_glIsRenderbuffer(renderbuffer);
}
GLboolean glIsRenderbuffer(GLuint renderbuffer) __attribute__((alias("glshim_glIsRenderbuffer")));
#endif
#ifndef skip_glIsShader
GLboolean glshim_glIsShader(GLuint shader) {
    LOAD_GLES(glIsShader);
#ifndef direct_glIsShader
    PUSH_IF_COMPILING(glIsShader)
#endif
    return gles_glIsShader(shader);
}
GLboolean glIsShader(GLuint shader) __attribute__((alias("glshim_glIsShader")));
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
#ifndef skip_glLinkProgram
void glshim_glLinkProgram(GLuint program) {
    LOAD_GLES(glLinkProgram);
#ifndef direct_glLinkProgram
    PUSH_IF_COMPILING(glLinkProgram)
#endif
    gles_glLinkProgram(program);
}
void glLinkProgram(GLuint program) __attribute__((alias("glshim_glLinkProgram")));
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
#ifndef skip_glReleaseShaderCompiler
void glshim_glReleaseShaderCompiler() {
    LOAD_GLES(glReleaseShaderCompiler);
#ifndef direct_glReleaseShaderCompiler
    PUSH_IF_COMPILING(glReleaseShaderCompiler)
#endif
    gles_glReleaseShaderCompiler();
}
void glReleaseShaderCompiler() __attribute__((alias("glshim_glReleaseShaderCompiler")));
#endif
#ifndef skip_glRenderbufferStorage
void glshim_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    LOAD_GLES(glRenderbufferStorage);
#ifndef direct_glRenderbufferStorage
    PUSH_IF_COMPILING(glRenderbufferStorage)
#endif
    gles_glRenderbufferStorage(target, internalformat, width, height);
}
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) __attribute__((alias("glshim_glRenderbufferStorage")));
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
#ifndef skip_glShaderBinary
void glshim_glShaderBinary(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length) {
    LOAD_GLES(glShaderBinary);
#ifndef direct_glShaderBinary
    PUSH_IF_COMPILING(glShaderBinary)
#endif
    gles_glShaderBinary(n, shaders, binaryformat, binary, length);
}
void glShaderBinary(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length) __attribute__((alias("glshim_glShaderBinary")));
#endif
#ifndef skip_glShaderSource
void glshim_glShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length) {
    LOAD_GLES(glShaderSource);
#ifndef direct_glShaderSource
    PUSH_IF_COMPILING(glShaderSource)
#endif
    gles_glShaderSource(shader, count, string, length);
}
void glShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length) __attribute__((alias("glshim_glShaderSource")));
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
#ifndef skip_glStencilFuncSeparate
void glshim_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    LOAD_GLES(glStencilFuncSeparate);
#ifndef direct_glStencilFuncSeparate
    PUSH_IF_COMPILING(glStencilFuncSeparate)
#endif
    gles_glStencilFuncSeparate(face, func, ref, mask);
}
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) __attribute__((alias("glshim_glStencilFuncSeparate")));
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
#ifndef skip_glStencilMaskSeparate
void glshim_glStencilMaskSeparate(GLenum face, GLuint mask) {
    LOAD_GLES(glStencilMaskSeparate);
#ifndef direct_glStencilMaskSeparate
    PUSH_IF_COMPILING(glStencilMaskSeparate)
#endif
    gles_glStencilMaskSeparate(face, mask);
}
void glStencilMaskSeparate(GLenum face, GLuint mask) __attribute__((alias("glshim_glStencilMaskSeparate")));
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
#ifndef skip_glStencilOpSeparate
void glshim_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass) {
    LOAD_GLES(glStencilOpSeparate);
#ifndef direct_glStencilOpSeparate
    PUSH_IF_COMPILING(glStencilOpSeparate)
#endif
    gles_glStencilOpSeparate(face, sfail, zfail, zpass);
}
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass) __attribute__((alias("glshim_glStencilOpSeparate")));
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
#ifndef skip_glUniform1f
void glshim_glUniform1f(GLint location, GLfloat v0) {
    LOAD_GLES(glUniform1f);
#ifndef direct_glUniform1f
    PUSH_IF_COMPILING(glUniform1f)
#endif
    gles_glUniform1f(location, v0);
}
void glUniform1f(GLint location, GLfloat v0) __attribute__((alias("glshim_glUniform1f")));
#endif
#ifndef skip_glUniform1fv
void glshim_glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(glUniform1fv);
#ifndef direct_glUniform1fv
    PUSH_IF_COMPILING(glUniform1fv)
#endif
    gles_glUniform1fv(location, count, value);
}
void glUniform1fv(GLint location, GLsizei count, const GLfloat * value) __attribute__((alias("glshim_glUniform1fv")));
#endif
#ifndef skip_glUniform1i
void glshim_glUniform1i(GLint location, GLint v0) {
    LOAD_GLES(glUniform1i);
#ifndef direct_glUniform1i
    PUSH_IF_COMPILING(glUniform1i)
#endif
    gles_glUniform1i(location, v0);
}
void glUniform1i(GLint location, GLint v0) __attribute__((alias("glshim_glUniform1i")));
#endif
#ifndef skip_glUniform1iv
void glshim_glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(glUniform1iv);
#ifndef direct_glUniform1iv
    PUSH_IF_COMPILING(glUniform1iv)
#endif
    gles_glUniform1iv(location, count, value);
}
void glUniform1iv(GLint location, GLsizei count, const GLint * value) __attribute__((alias("glshim_glUniform1iv")));
#endif
#ifndef skip_glUniform2f
void glshim_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    LOAD_GLES(glUniform2f);
#ifndef direct_glUniform2f
    PUSH_IF_COMPILING(glUniform2f)
#endif
    gles_glUniform2f(location, v0, v1);
}
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) __attribute__((alias("glshim_glUniform2f")));
#endif
#ifndef skip_glUniform2fv
void glshim_glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(glUniform2fv);
#ifndef direct_glUniform2fv
    PUSH_IF_COMPILING(glUniform2fv)
#endif
    gles_glUniform2fv(location, count, value);
}
void glUniform2fv(GLint location, GLsizei count, const GLfloat * value) __attribute__((alias("glshim_glUniform2fv")));
#endif
#ifndef skip_glUniform2i
void glshim_glUniform2i(GLint location, GLint v0, GLint v1) {
    LOAD_GLES(glUniform2i);
#ifndef direct_glUniform2i
    PUSH_IF_COMPILING(glUniform2i)
#endif
    gles_glUniform2i(location, v0, v1);
}
void glUniform2i(GLint location, GLint v0, GLint v1) __attribute__((alias("glshim_glUniform2i")));
#endif
#ifndef skip_glUniform2iv
void glshim_glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(glUniform2iv);
#ifndef direct_glUniform2iv
    PUSH_IF_COMPILING(glUniform2iv)
#endif
    gles_glUniform2iv(location, count, value);
}
void glUniform2iv(GLint location, GLsizei count, const GLint * value) __attribute__((alias("glshim_glUniform2iv")));
#endif
#ifndef skip_glUniform3f
void glshim_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    LOAD_GLES(glUniform3f);
#ifndef direct_glUniform3f
    PUSH_IF_COMPILING(glUniform3f)
#endif
    gles_glUniform3f(location, v0, v1, v2);
}
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) __attribute__((alias("glshim_glUniform3f")));
#endif
#ifndef skip_glUniform3fv
void glshim_glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(glUniform3fv);
#ifndef direct_glUniform3fv
    PUSH_IF_COMPILING(glUniform3fv)
#endif
    gles_glUniform3fv(location, count, value);
}
void glUniform3fv(GLint location, GLsizei count, const GLfloat * value) __attribute__((alias("glshim_glUniform3fv")));
#endif
#ifndef skip_glUniform3i
void glshim_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    LOAD_GLES(glUniform3i);
#ifndef direct_glUniform3i
    PUSH_IF_COMPILING(glUniform3i)
#endif
    gles_glUniform3i(location, v0, v1, v2);
}
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) __attribute__((alias("glshim_glUniform3i")));
#endif
#ifndef skip_glUniform3iv
void glshim_glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(glUniform3iv);
#ifndef direct_glUniform3iv
    PUSH_IF_COMPILING(glUniform3iv)
#endif
    gles_glUniform3iv(location, count, value);
}
void glUniform3iv(GLint location, GLsizei count, const GLint * value) __attribute__((alias("glshim_glUniform3iv")));
#endif
#ifndef skip_glUniform4f
void glshim_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    LOAD_GLES(glUniform4f);
#ifndef direct_glUniform4f
    PUSH_IF_COMPILING(glUniform4f)
#endif
    gles_glUniform4f(location, v0, v1, v2, v3);
}
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) __attribute__((alias("glshim_glUniform4f")));
#endif
#ifndef skip_glUniform4fv
void glshim_glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(glUniform4fv);
#ifndef direct_glUniform4fv
    PUSH_IF_COMPILING(glUniform4fv)
#endif
    gles_glUniform4fv(location, count, value);
}
void glUniform4fv(GLint location, GLsizei count, const GLfloat * value) __attribute__((alias("glshim_glUniform4fv")));
#endif
#ifndef skip_glUniform4i
void glshim_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    LOAD_GLES(glUniform4i);
#ifndef direct_glUniform4i
    PUSH_IF_COMPILING(glUniform4i)
#endif
    gles_glUniform4i(location, v0, v1, v2, v3);
}
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) __attribute__((alias("glshim_glUniform4i")));
#endif
#ifndef skip_glUniform4iv
void glshim_glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(glUniform4iv);
#ifndef direct_glUniform4iv
    PUSH_IF_COMPILING(glUniform4iv)
#endif
    gles_glUniform4iv(location, count, value);
}
void glUniform4iv(GLint location, GLsizei count, const GLint * value) __attribute__((alias("glshim_glUniform4iv")));
#endif
#ifndef skip_glUniformMatrix2fv
void glshim_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(glUniformMatrix2fv);
#ifndef direct_glUniformMatrix2fv
    PUSH_IF_COMPILING(glUniformMatrix2fv)
#endif
    gles_glUniformMatrix2fv(location, count, transpose, value);
}
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) __attribute__((alias("glshim_glUniformMatrix2fv")));
#endif
#ifndef skip_glUniformMatrix3fv
void glshim_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(glUniformMatrix3fv);
#ifndef direct_glUniformMatrix3fv
    PUSH_IF_COMPILING(glUniformMatrix3fv)
#endif
    gles_glUniformMatrix3fv(location, count, transpose, value);
}
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) __attribute__((alias("glshim_glUniformMatrix3fv")));
#endif
#ifndef skip_glUniformMatrix4fv
void glshim_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(glUniformMatrix4fv);
#ifndef direct_glUniformMatrix4fv
    PUSH_IF_COMPILING(glUniformMatrix4fv)
#endif
    gles_glUniformMatrix4fv(location, count, transpose, value);
}
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) __attribute__((alias("glshim_glUniformMatrix4fv")));
#endif
#ifndef skip_glUseProgram
void glshim_glUseProgram(GLuint program) {
    LOAD_GLES(glUseProgram);
#ifndef direct_glUseProgram
    PUSH_IF_COMPILING(glUseProgram)
#endif
    gles_glUseProgram(program);
}
void glUseProgram(GLuint program) __attribute__((alias("glshim_glUseProgram")));
#endif
#ifndef skip_glValidateProgram
void glshim_glValidateProgram(GLuint program) {
    LOAD_GLES(glValidateProgram);
#ifndef direct_glValidateProgram
    PUSH_IF_COMPILING(glValidateProgram)
#endif
    gles_glValidateProgram(program);
}
void glValidateProgram(GLuint program) __attribute__((alias("glshim_glValidateProgram")));
#endif
#ifndef skip_glVertexAttrib1f
void glshim_glVertexAttrib1f(GLuint index, GLfloat x) {
    LOAD_GLES(glVertexAttrib1f);
#ifndef direct_glVertexAttrib1f
    PUSH_IF_COMPILING(glVertexAttrib1f)
#endif
    gles_glVertexAttrib1f(index, x);
}
void glVertexAttrib1f(GLuint index, GLfloat x) __attribute__((alias("glshim_glVertexAttrib1f")));
#endif
#ifndef skip_glVertexAttrib1fv
void glshim_glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(glVertexAttrib1fv);
#ifndef direct_glVertexAttrib1fv
    PUSH_IF_COMPILING(glVertexAttrib1fv)
#endif
    gles_glVertexAttrib1fv(index, v);
}
void glVertexAttrib1fv(GLuint index, const GLfloat * v) __attribute__((alias("glshim_glVertexAttrib1fv")));
#endif
#ifndef skip_glVertexAttrib2f
void glshim_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    LOAD_GLES(glVertexAttrib2f);
#ifndef direct_glVertexAttrib2f
    PUSH_IF_COMPILING(glVertexAttrib2f)
#endif
    gles_glVertexAttrib2f(index, x, y);
}
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) __attribute__((alias("glshim_glVertexAttrib2f")));
#endif
#ifndef skip_glVertexAttrib2fv
void glshim_glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(glVertexAttrib2fv);
#ifndef direct_glVertexAttrib2fv
    PUSH_IF_COMPILING(glVertexAttrib2fv)
#endif
    gles_glVertexAttrib2fv(index, v);
}
void glVertexAttrib2fv(GLuint index, const GLfloat * v) __attribute__((alias("glshim_glVertexAttrib2fv")));
#endif
#ifndef skip_glVertexAttrib3f
void glshim_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glVertexAttrib3f);
#ifndef direct_glVertexAttrib3f
    PUSH_IF_COMPILING(glVertexAttrib3f)
#endif
    gles_glVertexAttrib3f(index, x, y, z);
}
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) __attribute__((alias("glshim_glVertexAttrib3f")));
#endif
#ifndef skip_glVertexAttrib3fv
void glshim_glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(glVertexAttrib3fv);
#ifndef direct_glVertexAttrib3fv
    PUSH_IF_COMPILING(glVertexAttrib3fv)
#endif
    gles_glVertexAttrib3fv(index, v);
}
void glVertexAttrib3fv(GLuint index, const GLfloat * v) __attribute__((alias("glshim_glVertexAttrib3fv")));
#endif
#ifndef skip_glVertexAttrib4f
void glshim_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    LOAD_GLES(glVertexAttrib4f);
#ifndef direct_glVertexAttrib4f
    PUSH_IF_COMPILING(glVertexAttrib4f)
#endif
    gles_glVertexAttrib4f(index, x, y, z, w);
}
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) __attribute__((alias("glshim_glVertexAttrib4f")));
#endif
#ifndef skip_glVertexAttrib4fv
void glshim_glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(glVertexAttrib4fv);
#ifndef direct_glVertexAttrib4fv
    PUSH_IF_COMPILING(glVertexAttrib4fv)
#endif
    gles_glVertexAttrib4fv(index, v);
}
void glVertexAttrib4fv(GLuint index, const GLfloat * v) __attribute__((alias("glshim_glVertexAttrib4fv")));
#endif
#ifndef skip_glVertexAttribPointer
void glshim_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glVertexAttribPointer);
#ifndef direct_glVertexAttribPointer
    PUSH_IF_COMPILING(glVertexAttribPointer)
#endif
    gles_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) __attribute__((alias("glshim_glVertexAttribPointer")));
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
        case FORMAT_void_GLclampf: {
            PACKED_void_GLclampf *unpacked = (PACKED_void_GLclampf *)packed;
            ARGS_void_GLclampf args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLint: {
            PACKED_void_GLint *unpacked = (PACKED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean: {
            PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
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
        case FORMAT_void_GLsizei_GLuint___GENPT__: {
            PACKED_void_GLsizei_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
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
        case FORMAT_GLenum: {
            PACKED_GLenum *unpacked = (PACKED_GLenum *)packed;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
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
        case FORMAT_void_GLenum_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
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
        case FORMAT_void_GLfloat: {
            PACKED_void_GLfloat *unpacked = (PACKED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            unpacked->func(args.a1);
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
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
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
        case FORMAT_void_GLint_GLint_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint_GLint args = unpacked->args;
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
#endif
