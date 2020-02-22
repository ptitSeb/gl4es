#include "../gl/attributes.h"
#include "../gl/init.h"
#include "../gl/logs.h"
#define STUB_FCT aglStub
#include "../gl/gl_lookup.h"

#include "agl.h"
#include "glx.h"
#include "hardext.h"

void aglStub(void *x, ...) {
    return;
}

void *gl4es_aglGetProcAddress(const char *name) {

    MAP("glXSwapIntervalMESA", gl4es_glXSwapInterval);
    MAP("glXSwapIntervalSGI", gl4es_glXSwapInterval);
    _EX(aglGetProcAddress);
    MAP("glXGetProcAddress", gl4es_aglGetProcAddress);
    MAP("glXGetProcAddressARB", gl4es_aglGetProcAddress);
    // direct mapping
    MAP("aglCreateContext", aglCreateContext);
    MAP("aglCreateContext2", aglCreateContext2);
    MAP("aglDestroyContext", aglDestroyContext);
    MAP("aglMakeCurrent", aglMakeCurrent);
    MAP("aglSwapBuffers", aglSwapBuffers);
    MAP("aglSetParams2", aglSetParams2);
    MAP("aglSetBitmap", aglSetBitmap);

    return gl4es_GetProcAddress(name);
}
void* aglGetProcAddress(const char* name) AliasExport("gl4es_aglGetProcAddress");
