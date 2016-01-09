#ifndef USE_ES2
#include "gles.h"
#ifndef skip_glBindFramebuffer
void glshim_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    LOAD_GLES_OES(glBindFramebuffer);
#ifndef direct_glBindFramebuffer
    PUSH_IF_COMPILING(glBindFramebuffer)
#endif
    gles_glBindFramebuffer(target, framebuffer);
}
void glBindFramebuffer(GLenum target, GLuint framebuffer) __attribute__((alias("glshim_glBindFramebuffer")));
#endif
#ifndef skip_glBindRenderbuffer
void glshim_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    LOAD_GLES_OES(glBindRenderbuffer);
#ifndef direct_glBindRenderbuffer
    PUSH_IF_COMPILING(glBindRenderbuffer)
#endif
    gles_glBindRenderbuffer(target, renderbuffer);
}
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) __attribute__((alias("glshim_glBindRenderbuffer")));
#endif
#ifndef skip_glBlendColor
void glshim_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    LOAD_GLES_OES(glBlendColor);
#ifndef direct_glBlendColor
    PUSH_IF_COMPILING(glBlendColor)
#endif
    gles_glBlendColor(red, green, blue, alpha);
}
void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) __attribute__((alias("glshim_glBlendColor")));
#endif
#ifndef skip_glBlendEquation
void glshim_glBlendEquation(GLenum mode) {
    LOAD_GLES_OES(glBlendEquation);
#ifndef direct_glBlendEquation
    PUSH_IF_COMPILING(glBlendEquation)
#endif
    gles_glBlendEquation(mode);
}
void glBlendEquation(GLenum mode) __attribute__((alias("glshim_glBlendEquation")));
#endif
#ifndef skip_glBlendEquationSeparate
void glshim_glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    LOAD_GLES_OES(glBlendEquationSeparate);
#ifndef direct_glBlendEquationSeparate
    PUSH_IF_COMPILING(glBlendEquationSeparate)
#endif
    gles_glBlendEquationSeparate(modeRGB, modeA);
}
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) __attribute__((alias("glshim_glBlendEquationSeparate")));
#endif
#ifndef skip_glBlendFuncSeparate
void glshim_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    LOAD_GLES_OES(glBlendFuncSeparate);
#ifndef direct_glBlendFuncSeparate
    PUSH_IF_COMPILING(glBlendFuncSeparate)
#endif
    gles_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) __attribute__((alias("glshim_glBlendFuncSeparate")));
#endif
#ifndef skip_glCheckFramebufferStatus
GLenum glshim_glCheckFramebufferStatus(GLenum target) {
    LOAD_GLES_OES(glCheckFramebufferStatus);
#ifndef direct_glCheckFramebufferStatus
    PUSH_IF_COMPILING(glCheckFramebufferStatus)
#endif
    return gles_glCheckFramebufferStatus(target);
}
GLenum glCheckFramebufferStatus(GLenum target) __attribute__((alias("glshim_glCheckFramebufferStatus")));
#endif
#ifndef skip_glDeleteFramebuffers
void glshim_glDeleteFramebuffers(GLsizei n, GLuint * framebuffers) {
    LOAD_GLES_OES(glDeleteFramebuffers);
#ifndef direct_glDeleteFramebuffers
    PUSH_IF_COMPILING(glDeleteFramebuffers)
#endif
    gles_glDeleteFramebuffers(n, framebuffers);
}
void glDeleteFramebuffers(GLsizei n, GLuint * framebuffers) __attribute__((alias("glshim_glDeleteFramebuffers")));
#endif
#ifndef skip_glDeleteRenderbuffers
void glshim_glDeleteRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    LOAD_GLES_OES(glDeleteRenderbuffers);
#ifndef direct_glDeleteRenderbuffers
    PUSH_IF_COMPILING(glDeleteRenderbuffers)
#endif
    gles_glDeleteRenderbuffers(n, renderbuffers);
}
void glDeleteRenderbuffers(GLsizei n, GLuint * renderbuffers) __attribute__((alias("glshim_glDeleteRenderbuffers")));
#endif
#ifndef skip_glDrawTexf
void glshim_glDrawTexf(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height) {
    LOAD_GLES_OES(glDrawTexf);
#ifndef direct_glDrawTexf
    PUSH_IF_COMPILING(glDrawTexf)
#endif
    gles_glDrawTexf(x, y, z, width, height);
}
void glDrawTexf(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height) __attribute__((alias("glshim_glDrawTexf")));
#endif
#ifndef skip_glDrawTexi
void glshim_glDrawTexi(GLint x, GLint y, GLint z, GLint width, GLint height) {
    LOAD_GLES_OES(glDrawTexi);
#ifndef direct_glDrawTexi
    PUSH_IF_COMPILING(glDrawTexi)
#endif
    gles_glDrawTexi(x, y, z, width, height);
}
void glDrawTexi(GLint x, GLint y, GLint z, GLint width, GLint height) __attribute__((alias("glshim_glDrawTexi")));
#endif
#ifndef skip_glFramebufferRenderbuffer
void glshim_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    LOAD_GLES_OES(glFramebufferRenderbuffer);
#ifndef direct_glFramebufferRenderbuffer
    PUSH_IF_COMPILING(glFramebufferRenderbuffer)
#endif
    gles_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) __attribute__((alias("glshim_glFramebufferRenderbuffer")));
#endif
#ifndef skip_glFramebufferTexture2D
void glshim_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    LOAD_GLES_OES(glFramebufferTexture2D);
#ifndef direct_glFramebufferTexture2D
    PUSH_IF_COMPILING(glFramebufferTexture2D)
#endif
    gles_glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) __attribute__((alias("glshim_glFramebufferTexture2D")));
#endif
#ifndef skip_glGenFramebuffers
void glshim_glGenFramebuffers(GLsizei n, GLuint * ids) {
    LOAD_GLES_OES(glGenFramebuffers);
#ifndef direct_glGenFramebuffers
    PUSH_IF_COMPILING(glGenFramebuffers)
#endif
    gles_glGenFramebuffers(n, ids);
}
void glGenFramebuffers(GLsizei n, GLuint * ids) __attribute__((alias("glshim_glGenFramebuffers")));
#endif
#ifndef skip_glGenRenderbuffers
void glshim_glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    LOAD_GLES_OES(glGenRenderbuffers);
#ifndef direct_glGenRenderbuffers
    PUSH_IF_COMPILING(glGenRenderbuffers)
#endif
    gles_glGenRenderbuffers(n, renderbuffers);
}
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) __attribute__((alias("glshim_glGenRenderbuffers")));
#endif
#ifndef skip_glGenerateMipmap
void glshim_glGenerateMipmap(GLenum target) {
    LOAD_GLES_OES(glGenerateMipmap);
#ifndef direct_glGenerateMipmap
    PUSH_IF_COMPILING(glGenerateMipmap)
#endif
    gles_glGenerateMipmap(target);
}
void glGenerateMipmap(GLenum target) __attribute__((alias("glshim_glGenerateMipmap")));
#endif
#ifndef skip_glGetFramebufferAttachmentParameteriv
void glshim_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    LOAD_GLES_OES(glGetFramebufferAttachmentParameteriv);
#ifndef direct_glGetFramebufferAttachmentParameteriv
    PUSH_IF_COMPILING(glGetFramebufferAttachmentParameteriv)
#endif
    gles_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetFramebufferAttachmentParameteriv")));
#endif
#ifndef skip_glGetRenderbufferParameteriv
void glshim_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES_OES(glGetRenderbufferParameteriv);
#ifndef direct_glGetRenderbufferParameteriv
    PUSH_IF_COMPILING(glGetRenderbufferParameteriv)
#endif
    gles_glGetRenderbufferParameteriv(target, pname, params);
}
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetRenderbufferParameteriv")));
#endif
#ifndef skip_glIsFramebuffer
GLboolean glshim_glIsFramebuffer(GLuint framebuffer) {
    LOAD_GLES_OES(glIsFramebuffer);
#ifndef direct_glIsFramebuffer
    PUSH_IF_COMPILING(glIsFramebuffer)
#endif
    return gles_glIsFramebuffer(framebuffer);
}
GLboolean glIsFramebuffer(GLuint framebuffer) __attribute__((alias("glshim_glIsFramebuffer")));
#endif
#ifndef skip_glIsRenderbuffer
GLboolean glshim_glIsRenderbuffer(GLuint renderbuffer) {
    LOAD_GLES_OES(glIsRenderbuffer);
#ifndef direct_glIsRenderbuffer
    PUSH_IF_COMPILING(glIsRenderbuffer)
#endif
    return gles_glIsRenderbuffer(renderbuffer);
}
GLboolean glIsRenderbuffer(GLuint renderbuffer) __attribute__((alias("glshim_glIsRenderbuffer")));
#endif
#ifndef skip_glRenderbufferStorage
void glshim_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    LOAD_GLES_OES(glRenderbufferStorage);
#ifndef direct_glRenderbufferStorage
    PUSH_IF_COMPILING(glRenderbufferStorage)
#endif
    gles_glRenderbufferStorage(target, internalformat, width, height);
}
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) __attribute__((alias("glshim_glRenderbufferStorage")));
#endif
#ifndef skip_glTexGenfv
void glshim_glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    LOAD_GLES_OES(glTexGenfv);
#ifndef direct_glTexGenfv
    PUSH_IF_COMPILING(glTexGenfv)
#endif
    gles_glTexGenfv(coord, pname, params);
}
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) __attribute__((alias("glshim_glTexGenfv")));
#endif
#ifndef skip_glTexGeni
void glshim_glTexGeni(GLenum coord, GLenum pname, GLint param) {
    LOAD_GLES_OES(glTexGeni);
#ifndef direct_glTexGeni
    PUSH_IF_COMPILING(glTexGeni)
#endif
    gles_glTexGeni(coord, pname, param);
}
void glTexGeni(GLenum coord, GLenum pname, GLint param) __attribute__((alias("glshim_glTexGeni")));
#endif
#endif
