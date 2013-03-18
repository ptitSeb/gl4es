#include "glx.h"
#include <gl.h>

#define EX(func_name)\
    if (strcmp(name, #func_name) == 0) return func_name

#define MAP(func_name, func)\
    if (strcmp(name, #func_name) == 0) return func

#define STUB(func_name)\
    if (strcmp(name, #func_name) == 0) return glXStub

void glXStub(void *x, ...) {
    return;
}

void *glXGetProcAddressARB(const char *name) {
    // generated gles wrappers
    #include "glxfuncs.inc"

    // glX calls
    EX(glXChooseVisual);
    EX(glXCreateContext);
    EX(glXDestroyContext);
    EX(glXMakeCurrent);
    EX(glXSwapBuffers);
    EX(glXGetConfig);
    EX(glXQueryExtensionsString);
    EX(glXGetCurrentDisplay);

    // OES wrapper
    EX(glClearDepthfOES);
    EX(glClipPlanefOES);
    EX(glDepthRangefOES);
    EX(glFrustumfOES);
    EX(glGetClipPlanefOES);
    EX(glOrthofOES);

    // passthrough
    // batch thunking!

    #define THUNK(suffix, type)\
    EX(glColor3##suffix##v);\
    EX(glColor3##suffix);\
    EX(glColor4##suffix##v);\
    EX(glColor4##suffix);\
    EX(glSecondaryColor3##suffix##v);\
    EX(glSecondaryColor3##suffix);\
    EX(glIndex##suffix##v);\
    EX(glIndex##suffix);\
    EX(glNormal3##suffix##v);\
    EX(glNormal3##suffix);\
    EX(glRasterPos2##suffix##v);\
    EX(glRasterPos2##suffix);\
    EX(glRasterPos3##suffix##v);\
    EX(glRasterPos3##suffix);\
    EX(glVertex2##suffix##v);\
    EX(glVertex2##suffix);\
    EX(glVertex3##suffix##v);\
    EX(glVertex3##suffix);\
    EX(glVertex4##suffix);\
    EX(glVertex4##suffix##v);\
    EX(glTexCoord1##suffix##v);\
    EX(glTexCoord1##suffix);\
    EX(glTexCoord2##suffix##v);\
    EX(glTexCoord2##suffix);\
    EX(glTexCoord3##suffix##v);\
    EX(glTexCoord3##suffix);\
    EX(glTexCoord4##suffix);\
    EX(glTexCoord4##suffix##v);

    THUNK(b, GLbyte);
    THUNK(d, GLdouble);
    THUNK(i, GLint);
    THUNK(s, GLshort);
    THUNK(ub, GLubyte);
    THUNK(ui, GLuint);
    THUNK(us, GLushort);
    THUNK(f, GLfloat);
    #undef THUNK

    // functions we actually define
    EX(glActiveTextureARB);
    EX(glArrayElement);
    EX(glBegin);
    EX(glBitmap);
    EX(glBlendEquationSeparatei);
    EX(glBlendFuncSeparate);
    EX(glBlendFuncSeparatei);
    EX(glCallList);
    EX(glClearDepth);
    EX(glClipPlane);
    EX(glCopyPixels);
    EX(glDeleteLists);
    EX(glDepthRange);
    EX(glDisable);
    EX(glDrawBuffer);
    EX(glDrawPixels);
    EX(glEdgeFlag);
    EX(glEnable);
    EX(glEnd);
    EX(glEndList);
    EX(glFogCoordd);
    EX(glFogCoorddv);
    EX(glFogCoordf);
    EX(glFogCoordfv);
    EX(glFogi);
    EX(glFrustum);
    EX(glGenLists);
    EX(glGetDoublev);
    EX(glGetIntegerv);
    EX(glGetTexImage);
    EX(glGetTexLevelParameterfv);
    EX(glGetTexLevelParameteriv);
    EX(glInitNames);
    EX(glLightModeli);
    EX(glLoadMatrixd);
    EX(glLoadName);
    EX(glMateriali);
    EX(glMultiTexCoord2f);
    EX(glMultMatrixd);
    EX(glNewList);
    EX(glOrtho);
    EX(glPixelTransferf);
    EX(glPixelTransferi);
    EX(glPixelZoom);
    EX(glPolygonMode);
    EX(glPolygonStipple);
    EX(glPopAttrib);
    EX(glPopClientAttrib);
    EX(glPopName);
    EX(glPushAttrib);
    EX(glPushClientAttrib);
    EX(glPushName);
    EX(glRasterPos2i);
    EX(glReadBuffer);
    EX(glRenderMode);
    EX(glRotated);
    EX(glScaled);
    EX(glTexImage1D);
    EX(glTexImage3D);
    EX(glTranslated);

    printf("glXGetProcAddress: %s not found.\n", name);
    return NULL;
}

void *glXGetProcAddress(const char *name) {
    return glXGetProcAddressARB(name);
}
