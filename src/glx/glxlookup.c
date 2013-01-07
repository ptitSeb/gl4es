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
    // stubs we actually define
    EX(glPopAttrib);
    EX(glPushAttrib);
    EX(glPopClientAttrib);
    EX(glPushClientAttrib);
    EX(glSecondaryColor3f);
    EX(glIndexf);
    EX(glFogCoordd);
    EX(glFogCoordf);
    EX(glFogCoorddv);
    EX(glFogCoordfv);
    EX(glArrayElement);
    EX(glEdgeFlag);
    EX(glEndList);
    EX(glCallList);
    EX(glDeleteLists);
    EX(glGenLists);
    EX(glNewList);
    EX(glNormal3dv);

    // stubs
    STUB(glBitmap);
    STUB(glCopyPixels);
    STUB(glPixelTransferi);
    STUB(glPixelTransferf);
    STUB(glPixelZoom);
    STUB(glGetTexLevelParameterfv);
    STUB(glDrawPixels);

    printf("%s not found.\n", name);
    return glXStub;
}
