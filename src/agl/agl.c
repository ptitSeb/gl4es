#include "agl.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#undef _USE_INLINE_
#include <proto/exec.h>

#include "../gl/gl.h"

extern struct OGLES2IFace *IOGLES2;

void* aglCreateContext(ULONG * errcode, struct TagItem * tags) {
    if(IOGLES2)
        return IOGLES2->aglCreateContext(errcode, tags);
    return NULL;
}

void* aglCreateContextTags(ULONG * errcode, ...) {
    void* ret = NULL;
    if(IOGLES2) {
        va_list args;
        va_start(args,errcode);
        ret = IOGLES2->aglCreateContextTags(errcode, args);
        va_end(args);
    }
    return ret;
}

void aglDestroyContext(void* context) {
    if(IOGLES2) {
        IOGLES2->aglDestroyContext(context);
    }
}

void aglMakeCurrent(void* context) {
    if(IOGLES2) {
        IOGLES2->aglMakeCurrent(context);
    }
}

void aglSwapBuffers() {
    // make sure everything is flushed before swapping buffers
    int old_batch = glstate->gl_batch;
    if (glstate->gl_batch || glstate->list.active){
        flush();
    }
    if (glstate->raster.bm_drawing)
        bitmap_flush();

    if (globals4es.usefbo) {
        glstate->gl_batch = 0;
        unbindMainFBO();
        blitMainFBO();
        // blit the main_fbo before swap
    }
    // Swap the Buffers!
    if(IOGLES2) {
        IOGLES2->aglSwapBuffers();
    }
    // If drawing in fbo, rebind it...
    if (globals4es.usefbo) {
        glstate->gl_batch = old_batch;
        bindMainFBO();
    }
}

void aglSetBitmap(struct BitMap *bitmap) {
    if(IOGLES2) {
        IOGLES2->aglSetBitmap(bitmap);
    }
}

//void* aglGetProcAddress(const char* name); //-> declared in glx/lookup.c
