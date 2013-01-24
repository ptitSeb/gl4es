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
    EX(glCallList);
    EX(glDeleteLists);
    EX(glDrawPixels);
    EX(glEdgeFlag);
    EX(glEndList);
    EX(glFogCoordd);
    EX(glFogCoorddv);
    EX(glFogCoordf);
    EX(glFogCoordfv);
    EX(glGenLists);
    EX(glIndexf);
    EX(glNewList);
    EX(glNormal3dv);
    EX(glPopAttrib);
    EX(glPopClientAttrib);
    EX(glPushAttrib);
    EX(glPushClientAttrib);
    EX(glRasterPos2i);
    EX(glSecondaryColor3f);

    // stubs
    STUB(glBlendFuncSeparate);
    STUB(glBlendEquationSeparate);
    STUB(glCopyPixels);
    STUB(glGetTexImage);
    STUB(glGetTexLevelParameterfv);
    STUB(glGetTexLevelParameteriv);
    STUB(glPixelTransferf);
    STUB(glPixelTransferi);
    STUB(glPixelZoom);
    STUB(glTexImage3D);
    printf("%s not found.\n", name);
    return NULL;
}

void *glXGetProcAddress(const char *name) {
    return glXGetProcAddressARB(name);
}
