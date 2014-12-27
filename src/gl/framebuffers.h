#include "gl.h"

#ifndef GL_FRAMEBUFFERS_H
#define GL_FRAMEBUFFERS_H

/*
void glGenFramebuffers(GLsizei n, GLuint *ids);
void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers);
GLboolean glIsFramebuffer(GLuint framebuffer);
GLenum glCheckFramebufferStatus(GLenum target);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);
void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers);
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
GLboolean glIsRenderbuffer(GLuint renderbuffer);
void glGenerateMipmap(GLenum target);
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params);
*/
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);   // naive Wrap
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer);   // naive Wrap
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);    //STUB


// Direct creation of EXT versions...
void glGenFramebuffersEXT(GLsizei n, GLuint *ids);
void glDeleteFramebuffersEXT(GLsizei n, GLuint *framebuffers);
GLboolean glIsFramebufferEXT(GLuint framebuffer);
GLenum glCheckFramebufferStatusEXT(GLenum target);
void glBindFramebufferEXT(GLenum target, GLuint framebuffer);
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);   // naive Wrap
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer);   // naive Wrap
void glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers);
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glDeleteRenderbuffersEXT(GLsizei n, GLuint *renderbuffers);
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer);
GLboolean glIsRenderbufferEXT(GLuint renderbuffer);
void glGenerateMipmapEXT(GLenum target);
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params);
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint * params);

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
