// auto-wrap these functions, prefixed with gles_

// don't auto-wrap these functions
#define skip_glColor4f
#define skip_glColor4ub
#define skip_glDisable
#define skip_glEnable
#define skip_glGetIntegerv
#define skip_glGetString
#define skip_glLightModelf
#define skip_glMaterialfv
#define skip_glPixelStorei
#define skip_glTexImage2D
#define skip_glViewport

// glDrawArrays
#define skip_glDrawArrays
#define skip_glVertexPointer
#define skip_glColorPointer
#define skip_glNormalPointer
#define skip_glTexCoordPointer
#define skip_glDisableClientState
#define skip_glEnableClientState

// don't compile these into display lists
#define direct_glColorPointer
#define direct_glDeleteLists
#define direct_glDisableClientState
#define direct_glEdgeFlagPointer
#define direct_glEnableClientState
#define direct_glFeedbackBuffer
#define direct_glFinish
#define direct_glFlush
#define direct_glGenLists
#define direct_glIndexPointer
#define direct_glInterleavedArrays
#define direct_glIsEnabled
#define direct_glIsList
#define direct_glNormalPointer
#define direct_glPopClientAttrib
#define direct_glPixelStore
#define direct_glPushClientAttrib
#define direct_glReadPixels
#define direct_glRenderMode
#define direct_glSelectBuffer
#define direct_glTexCoordPointer
#define direct_glVertexPointer
