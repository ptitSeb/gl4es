#include "agl.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#undef __USE_INLINE__
#include <proto/exec.h>
#include <interfaces/ogles2.h>

extern struct OGLES2IFace *IOGLES2;

void* NewGLState(void* shared_glstate, int es2only);
void DeleteGLState(void* oldstate);
void ActivateGLState(void* new_glstate);
void GetHardwareExtensions(int notest);

typedef struct _agl_ctx_glstate {
    void* context;
    void* glstate;
} agl_ctx_glstate;

static agl_ctx_glstate *agl_context = NULL;
static int agl_context_len = 0;
static int agl_context_cap = 0;

// find (or add if not found) a context in the list, and activate glstate...
void agl_context_find(void* ctx) {
    if(!ctx)
        return;
    if(!agl_context) {
        agl_context_cap = 10;
        agl_context = (agl_ctx_glstate*)malloc(sizeof(agl_ctx_glstate)*agl_context_cap);
        memset(agl_context, 0, sizeof(agl_ctx_glstate)*agl_context_cap);
    }
    int idx = 0;
    while (idx<agl_context_len && agl_context[idx].context!=ctx) idx++;
    if(idx==agl_context_len) {
        agl_context = (agl_ctx_glstate*)realloc(agl_context, sizeof(agl_ctx_glstate)*(agl_context_cap+10));
        memset(agl_context+agl_context_cap, 0, sizeof(agl_ctx_glstate)*10);
        agl_context_cap+=10;
    }
    agl_context[idx].context = ctx;
    if(idx==agl_context_len) ++agl_context_len;

    // create glstate if needed
    if(!agl_context[idx].glstate) {
        agl_context[idx].glstate = NewGLState(NULL, 0);
        // Hardware testing
        GetHardwareExtensions(0);
    }
    ActivateGLState(agl_context[idx].glstate);
}

// remove a context (delete array if size is null)
void agl_context_remove(void* ctx) {
    if (!ctx)
        return;
    if(!agl_context)
        return; // empty list?
    int idx = 0;
    while (idx<agl_context_len && agl_context[idx].context!=ctx) idx++;
    if(idx==agl_context_len)
        return; // not found...
    if(agl_context[idx].glstate) {
        DeleteGLState(agl_context[idx].glstate);
        agl_context[idx].glstate = NULL;
    }
    agl_context[idx].context = 0;
    // shrink if possible
    while(agl_context_len && !agl_context[agl_context_len].context) --agl_context_len;
    if(!agl_context_len) {
        agl_context_cap = 0;
        free(agl_context);
        agl_context = NULL;
    }
}

// AGL functions

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

        agl_context_remove(context); // remove the associated glstate
    }
}

void aglMakeCurrent(void* context) {
    if(IOGLES2) {
        IOGLES2->aglMakeCurrent(context);

        if (context)
            agl_context_find(context);  // activate (and create if needed) the correct glstate
    }
}

void amiga_pre_swap();
void amiga_post_swap();
void aglSwapBuffers() {
    amiga_pre_swap();
    // Swap the Buffers!
    if(IOGLES2) {
        IOGLES2->aglSwapBuffers();
    }
    amiga_post_swap();
}

// what is the use of this function?
void aglSetBitmap(struct BitMap *bitmap) {
    if(IOGLES2) {
        IOGLES2->aglSetBitmap(bitmap);
    }
}

//void* aglGetProcAddress(const char* name); //-> declared in glx/lookup.c
