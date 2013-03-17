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
    EX(glActiveTextureARB);
    EX(glBegin);
    EX(glClearDepth);
    EX(glDisable);
    EX(glEnable);
    EX(glEnd);
    EX(glFogi);
    EX(glFrustum);
    EX(glGetDoublev);
    EX(glNormal3d);
    EX(glOrtho);
    EX(glTexCoord2d);
    EX(glTexCoord2f);
    EX(glTexImage1D);
    EX(glTranslated);
    EX(glVertex3f);
    // batch thunking!

    #define THUNK(suffix, type)\
    EX(glColor3##suffix);\
    EX(glColor4##suffix);\
    EX(glColor3##suffix##v);\
    EX(glColor4##suffix##v);\
    EX(glIndex##suffix);\
    EX(glIndex##suffix##v);\
    EX(glSecondaryColor3##suffix);\
    EX(glSecondaryColor3##suffix##v);\
    EX(glVertex2##suffix);\
    EX(glVertex3##suffix);

    THUNK(b, GLbyte);
    THUNK(d, GLdouble);
    THUNK(i, GLint);
    THUNK(s, GLshort);
    THUNK(ub, GLubyte);
    THUNK(ui, GLuint);
    THUNK(us, GLushort);

    EX(glVertex2f);
    EX(glColor3f);
    #undef THUNK

    // functions we actually define
    EX(glArrayElement);
    EX(glBitmap);
    EX(glBlendEquationSeparatei);
    EX(glBlendFuncSeparate);
    EX(glBlendFuncSeparatei);
    EX(glCallList);
    EX(glCopyPixels);
    EX(glDeleteLists);
    EX(glDrawBuffer);
    EX(glDrawPixels);
    EX(glEdgeFlag);
    EX(glEdgeFlag);
    EX(glEndList);
    EX(glFogCoordd);
    EX(glFogCoorddv);
    EX(glFogCoordf);
    EX(glFogCoordfv);
    EX(glGenLists);
    EX(glGetTexImage);
    EX(glGetTexLevelParameterfv);
    EX(glGetTexLevelParameteriv);
    EX(glIndexf);
    EX(glIndexf);
    EX(glInitNames);
    EX(glLightModeli);
    EX(glLoadName);
    EX(glNewList);
    EX(glNormal3dv);
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
    EX(glSecondaryColor3f);
    EX(glSecondaryColor3f);
    EX(glTexImage3D);

    printf("%s not found.\n", name);
    return NULL;
}

void *glXGetProcAddress(const char *name) {
    return glXGetProcAddressARB(name);
}
