#include "gl.h"

#ifndef GL_FRAMEBUFFERS_H
#define GL_FRAMEBUFFERS_H

void gl4es_glGenerateMipmap(GLenum target);
void gl4es_glGenFramebuffers(GLsizei n, GLuint *ids);
void gl4es_glDeleteFramebuffers(GLsizei n, GLuint *framebuffers);
GLboolean gl4es_glIsFramebuffer(GLuint framebuffer);
GLenum gl4es_glCheckFramebufferStatus(GLenum target);
void gl4es_glBindFramebuffer(GLenum target, GLuint framebuffer);
void gl4es_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);
void gl4es_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
void gl4es_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void gl4es_glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers);
void gl4es_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void gl4es_glBindRenderbuffer(GLenum target, GLuint renderbuffer);
GLboolean gl4es_glIsRenderbuffer(GLuint renderbuffer);
void gl4es_glGenerateMipmap(GLenum target);
void gl4es_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
void gl4es_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params);

void gl4es_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);   // naive Wrap
void gl4es_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer);   // naive Wrap
void gl4es_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);    //STUB
void gl4es_glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);    // naive Wrap
void gl4es_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

// Need  to keep track of Renderbuffer that are created as DEPTH_STENCIL, to create 2 seperate buffers...
typedef struct {
    GLuint      renderbuffer;   // This is the Depth buffer...
    GLuint      stencil;        // this will be the secondary Stencil buffer
} gldepthstencil_t;

KHASH_MAP_INIT_INT(dsr, gldepthstencil_t *)

// In case of LIBGL_FB=2, let's create an FBO for everything, that is than blitted just before the SwapBuffer
void createMainFBO(int width, int height);
void blitMainFBO();
void deleteMainFBO();
void bindMainFBO();
void unbindMainFBO();

void readfboBegin();
void readfboEnd();
#endif
