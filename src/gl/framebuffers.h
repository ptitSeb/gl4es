#include "gl.h"

#ifndef GL_FRAMEBUFFERS_H
#define GL_FRAMEBUFFERS_H

void glshim_glGenerateMipmap(GLenum target);
void glshim_glGenFramebuffers(GLsizei n, GLuint *ids);
void glshim_glDeleteFramebuffers(GLsizei n, GLuint *framebuffers);
GLboolean glshim_glIsFramebuffer(GLuint framebuffer);
GLenum glshim_glCheckFramebufferStatus(GLenum target);
void glshim_glBindFramebuffer(GLenum target, GLuint framebuffer);
void glshim_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);
void glshim_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
void glshim_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glshim_glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers);
void glshim_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glshim_glBindRenderbuffer(GLenum target, GLuint renderbuffer);
GLboolean glshim_glIsRenderbuffer(GLuint renderbuffer);
void glshim_glGenerateMipmap(GLenum target);
void glshim_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
void glshim_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params);

void glshim_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);   // naive Wrap
void glshim_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer);   // naive Wrap
void glshim_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);    //STUB
void glshim_glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);    // naive Wrap
void glshim_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

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

void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level);   // naive Wrap
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer);   // naive Wrap
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);    //STUB
void glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);    // naive Wrap
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

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
void glFramebufferTextureLayerEXT(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

void* _framebuffers_GetProcAdress();

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
