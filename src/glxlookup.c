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
    EX(glBegin);
    EX(glBindTexture);
    EX(glBlendFunc);
    EX(glColor4f);
    EX(glDisable);
    EX(glEnable);
    EX(glEnd);
    EX(glFlush);
    EX(glGenTextures);
    EX(glGetString);
    EX(glLoadIdentity);
    EX(glMatrixMode);
    EX(glPixelStorei);
    EX(glPopMatrix);
    EX(glPushMatrix);
    EX(glTexCoord2f);
    EX(glTexEnvf);
    EX(glTexImage2D);
    EX(glTexParameteri);
    EX(glTexSubImage2D);
    EX(glVertex2i);
    EX(glViewport);
    MAP(glOrtho, glOrthof);
    STUB(glPopAttrib);
    STUB(glPopClientAttrib);
    STUB(glPushAttrib);
    STUB(glPushClientAttrib);

    return NULL;
}
