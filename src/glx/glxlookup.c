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
    // passthrough
    EX(glActiveTextureARB);
    EX(glBegin);
    EX(glBindTexture);
    EX(glBlendFunc);
    EX(glClearDepth);
    EX(glColor4f);
    EX(glDisable);
    EX(glEnable);
    EX(glEnd);
    EX(glFlush);
    EX(glFogi);
    EX(glFrustum);
    EX(glGenTextures);
    EX(glGetDoublev);
    EX(glGetString);
    EX(glLoadIdentity);
    EX(glMatrixMode);
    EX(glMultMatrixf);
    EX(glNormal3d);
    EX(glOrtho);
    EX(glPixelStorei);
    EX(glPopMatrix);
    EX(glPushMatrix);
    EX(glTexCoord2d);
    EX(glTexCoord2f);
    EX(glTexEnvf);
    EX(glTexImage1D);
    EX(glTexImage2D);
    EX(glTexParameteri);
    EX(glTexSubImage2D);
    EX(glTranslated);
    EX(glViewport);
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
    EX(glColorMaterial);
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

    // tmp
    EX(glClear);
    EX(glClearColor);
    EX(glColorPointer);
    EX(glCopyTexImage2D);
    EX(glCopyTexSubImage2D);
    EX(glDeleteTextures);
    EX(glDisableClientState);
    EX(glDrawArrays);
    EX(glDrawElements);
    EX(glEnableClientState);
    EX(glFinish);
    EX(glGetError);
    EX(glGetFloatv);
    EX(glGetTexParameterfv);
    EX(glHint);
    EX(glLightfv);
    EX(glLineWidth);
    EX(glPointSize);
    EX(glReadPixels);
    EX(glRotatef);
    EX(glScalef);
    EX(glTexCoordPointer);
    EX(glTexParameterf);
    EX(glTranslatef);
    EX(glVertexPointer);
    EX(glScissor);
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
