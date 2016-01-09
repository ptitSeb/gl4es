#include "stub.h"

#define STUB(ret, def, args)\
ret glshim_ ## def args {\
    char *debug = getenv("LIBGL_DEBUG");\
    if (debug && strcmp(debug, "1") == 0)\
        printf("stub: %s;\n", #def);\
} \
ret def args __attribute((alias("glshim_"#def)));

STUB(void,glFogCoordd,(GLdouble coord));
STUB(void,glFogCoordf,(GLfloat coord));
STUB(void,glFogCoorddv,(const GLdouble *coord));
STUB(void,glFogCoordfv,(const GLfloat *coord));
#ifdef BCMHOST
STUB(void,glDiscardFramebufferEXT,(GLenum target, GLsizei numAttachments, const GLenum *attachments));
#endif

#ifdef USE_ES2
STUB(void,glClipPlanef,(GLenum plane, const GLfloat *equation));
STUB(void,glDisableClientState,(GLenum state));
STUB(void,glEnableClientState,(GLenum state));
STUB(void,glFogf,(GLenum pname, GLfloat param));
STUB(void,glFogfv,(GLenum pname, const GLfloat *params));
STUB(void,glFrustumf,(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far));
STUB(void,glGetClipPlanef,(GLenum plane, GLfloat *equation));
STUB(void,glLightf,(GLenum light, GLenum pname, GLfloat param));
STUB(void,glLightfv,(GLenum light, GLenum pname, const GLfloat *params));
STUB(void,glLoadIdentity,());
STUB(void,glLoadMatrixf,(const GLfloat *m));
STUB(void,glMaterialf,(GLenum face, GLenum pname, GLfloat param));
STUB(void,glMatrixMode,(GLenum mode));
STUB(void,glMultiTexCoord4f,(GLenum target, GLfloat s, GLfloat r, GLfloat q, GLfloat t));
STUB(void,glMultMatrixf,(const GLfloat *m));
STUB(void,glOrthof,(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat nearVal, GLfloat farVal));
STUB(void,glPopMatrix,());
STUB(void,glPushMatrix,());
STUB(void,glRotatef,(GLfloat angle, GLfloat x, GLfloat y, GLfloat z));
STUB(void,glScalef,(GLfloat x, GLfloat y, GLfloat z));
STUB(void,glTexEnvf,(GLenum target, GLenum pname, GLfloat param));
STUB(void,glTexEnvi,(GLenum target, GLenum pname, GLint param));
STUB(void,glTranslatef,(GLfloat x, GLfloat y, GLfloat z));
#endif

/*
STUB(void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha))
STUB(void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha))
*/
STUB(void,glClearAccum,(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha));
STUB(void,glColorMaterial,(GLenum face, GLenum mode));
STUB(void,glCopyPixels,(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type));
STUB(void,glDrawBuffer,(GLenum mode));
STUB(void,glEdgeFlag,(GLboolean flag));
STUB(void,glIndexf,(GLfloat c));
STUB(void,glPolygonStipple,(const GLubyte *mask));
STUB(void,glReadBuffer,(GLenum mode));
//STUB(void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b));
STUB(void,glColorTable,(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table));

STUB(void,glAccum,(GLenum op, GLfloat value));
STUB(void,glPrioritizeTextures,(GLsizei n, const GLuint *textures, const GLclampf *priorities));
STUB(void,glPixelMapfv,(GLenum map, GLsizei mapsize, const GLfloat *values));
STUB(void,glPixelMapuiv,(GLenum map,GLsizei mapsize, const GLuint *values));
STUB(void,glPixelMapusv,(GLenum map,GLsizei mapsize, const GLushort *values));
STUB(void,glPassThrough,(GLfloat token));
STUB(void,glIndexMask,(GLuint mask));
STUB(void,glGetPixelMapfv,(GLenum map, GLfloat *data));
STUB(void,glGetPixelMapuiv,(GLenum map, GLuint *data));
STUB(void,glGetPixelMapusv,(GLenum map, GLushort *data));
STUB(void,glClearIndex,(GLfloat c));
STUB(void,glGetPolygonStipple,(GLubyte *pattern));
STUB(void,glFeedbackBuffer,(GLsizei size, GLenum type, GLfloat *buffer));
STUB(void,glEdgeFlagv,(GLboolean *flag));
//STUB(void glIndexPointer(GLenum  type,  GLsizei  stride,  const GLvoid *  pointer));
#undef STUB
