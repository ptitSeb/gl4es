#define SYS_proxy 9999
#define MAX_EVAL_ORDER 30
#define MAX_TEX 8
#define MAX_STACK_PROJECTION	16
#define MAX_STACK_TEXTURE	16
#define MAX_STACK_MODELVIEW	64
#define MAX_STACK_COLOR 16

// don't auto-wrap these functions
#define skip_glColor4ub

// gl.c
#define skip_glColor4f
#define skip_glDisable
#define skip_glEnable
#define skip_glGetIntegerv
#define skip_glGetString
#define skip_glIsEnabled
#define skip_glMaterialfv
#define skip_glMaterialf
#define skip_glNormal3f

#define skip_glGetFloatv

#define skip_glPushMatrix
#define skip_glPopMatrix

#define skip_glBindBuffer
#define skip_glBufferData
#define skip_glBufferSubData
#define skip_glDeleteBuffers
#define skip_glGenBuffers
#define skip_glIsBuffer
#define skip_glGetBufferPointerv
#define skip_glMapBuffer
#define skip_glUnmapBuffer
#define skip_glGetBufferParameteriv
#define skip_glGetBufferSubData
#define skip_glGetPointerv

#define skip_glBlendColor
#define skip_glBlendFunc

#define skip_glFogfv

//#define skip_glBlendEquation
#define skip_glBlendEquationSeparate
#define skip_glBlendEquationSeparatei
#define skip_glBlendFuncSeparate
#define skip_glBlendFuncSeparatei

#define skip_glGetError

// light.c
#define skip_glLightModelf
#define skip_glLightModelfv
#define skip_glLightfv
#define skip_glLightf

// raster.c
#define skip_glViewport

// texture.c
#define skip_glIsTexture
#define skip_glBindTexture
#define skip_glCopyTexImage2D
#define skip_glCopyTexSubImage2D
#define skip_glGenTextures
#define skip_glDeleteTextures
#define skip_glPixelStorei
#define skip_glPixelStoref
#define skip_glTexImage2D
#define skip_glTexParameteri
#define skip_glTexParameterf
#define skip_glTexSubImage2D
#define skip_glActiveTexture
#define skip_glClientActiveTexture
#define skip_glMultiTexCoord4f
#define skip_glTexGeni
#define skip_glTexGenfv
#define skip_glReadPixels
#define skip_glCompressedTexImage2D
#define skip_glCompressedTexSubImage2D

// glDrawArrays
#define skip_glDrawArrays
#define skip_glDrawElements
#define skip_glVertexPointer
#define skip_glColorPointer
#define skip_glNormalPointer
#define skip_glTexCoordPointer
#define skip_glDisableClientState
#define skip_glEnableClientState

// Framebuffers
#define skip_glGenFramebuffers
#define skip_glDeleteFramebuffers
#define skip_glIsFramebuffer
#define skip_glCheckFramebufferStatus
#define skip_glBindFramebuffer
#define skip_glFramebufferTexture2D
#define skip_glGenRenderbuffers
#define skip_glFramebufferRenderbuffer
#define skip_glDeleteRenderbuffers
#define skip_glRenderbufferStorage
#define skip_glRenderbufferStorageMultisample
#define skip_glBindRenderbuffer
#define skip_glIsRenderbuffer
#define skip_glGenerateMipmap
#define skip_glGetFramebufferAttachmentParameteriv
#define skip_glGetRenderbufferParameteriv

#define skip_glFlush
#define skip_glFinish

// matrix don't go to stack well, because values are pointer, not immediate...
#define skip_glLoadMatrixf
#define skip_glMultMatrixf

// don't compile these into display lists
#define direct_glColorPointer
#define direct_glDeleteLists
#define direct_glDisableClientState
#define direct_glEdgeFlagPointer
#define direct_glEnableClientState
#define direct_glClientActiveTexture
#define direct_glFeedbackBuffer
#define direct_glGenLists
#define direct_glIndexPointer
#define direct_glInterleavedArrays
#define direct_glIsEnabled
#define direct_glIsList
#define direct_glNormalPointer
#define direct_glPopClientAttrib
#define direct_glPixelStorei
#define direct_glPixelStoref
#define direct_glPushClientAttrib
#define direct_glRenderMode
#define direct_glSelectBuffer
#define direct_glTexCoordPointer
#define direct_glVertexPointer
#define direct_glGenTextures
#define direct_glGetError
