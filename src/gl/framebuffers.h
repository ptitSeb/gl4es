#include "gl.h"

#ifndef GL_FRAMEBUFFERS_H
#define GL_FRAMEBUFFERS_H


extern void glGenFramebuffers(GLsizei n, GLuint *ids);
extern void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers);
extern GLboolean glIsFramebuffer(GLuint framebuffer);
extern GLenum glCheckFramebufferStatus(GLenum target);
extern void glBindFramebuffer(GLenum target, GLuint framebuffer);
extern void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);
extern void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);   // naive Wrap
extern void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer);   // naive Wrap
extern void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
extern void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers);
extern void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);    //STUB
extern void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
extern GLboolean glIsRenderbuffer(GLuint renderbuffer);
extern void glGenerateMipmap(GLenum target);
extern void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
extern void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params);

// Need  to keep track of Renderbuffer that are created as DEPTH_STENCIL, to create 2 seperate buffers...
typedef struct {
    GLuint      renderbuffer;   // This is the Depth buffer...
    GLuint      stencil;        // this will be the secondary Stencil buffer
} gldepthstencil_t;

KHASH_MAP_INIT_INT(dsr, gldepthstencil_t *)

// In case of LIBGL_FB=2, let's create an FBO for everything, that is than blitted just before the SwapBuffer
extern void createMainFBO(int width, int height);
extern void blitMainFBO();
extern void deleteMainFBO();

#endif
