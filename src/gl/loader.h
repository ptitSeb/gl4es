#ifndef LOADER_H
#define LOADER_H

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"
#include "../glx/hardext.h"

// will become references to dlopen'd gles and egl
extern void *gles, *egl, *bcm_host, *vcos;

void *open_lib(const char **names, const char *override);

#define WARN_NULL(name) if (name == NULL) LOGD("LIBGL: warning, " #name " is NULL\n");

#define DEFINE_RAW(lib, name) static name##_PTR lib##_##name
#define LOAD_RAW(lib, name, ...) \
    { \
        static bool first = true; \
        if (first) { \
            first = false; \
            if (lib != NULL) { \
                lib##_##name = (name##_PTR)__VA_ARGS__; \
            } \
            WARN_NULL(lib##_##name); \
        } \
    }

#define LOAD_RAW_SILENT(lib, name, ...) \
    { \
        static bool first = true; \
        if (first) { \
            first = false; \
            if (lib != NULL) { \
                lib##_##name = (name##_PTR)__VA_ARGS__; \
            } \
        } \
    }

#define LOAD_RAW_ALT(lib, alt, name, ...) \
    { \
        static bool first = true; \
        if (first) { \
            first = false; \
            if (lib != NULL) { \
                lib##_##name = (name##_PTR)__VA_ARGS__; \
            } \
            if(lib##_##name == NULL) \
                lib##_##name = alt##_##name; \
        } \
    }

#define LOAD_LIB(lib, name) DEFINE_RAW(lib, name); LOAD_RAW(lib, name, dlsym(lib, #name))
#define LOAD_LIB_SILENT(lib, name) DEFINE_RAW(lib, name); LOAD_RAW_SILENT(lib, name, dlsym(lib, #name))
#define LOAD_LIB_ALT(lib, alt, name) DEFINE_RAW(lib, name); LOAD_RAW_ALT(lib, alt, name, dlsym(lib, #name))

#define LOAD_GLES(name) \
    LOAD_LIB(gles, name)
    
#define LOAD_GLES2(name) \
    LOAD_LIB_SILENT(gles, name)

#define LOAD_GLES_OR_FPE(name) \
    LOAD_LIB_ALT(gles, fpe, name)

#define LOAD_GLES_FPE(name) \
    DEFINE_RAW(gles, name); \
    if(hardext.esversion==1) { \
        LOAD_RAW(gles, name, dlsym(gles, #name)); \
    } else { \
        gles_##name = fpe_##name; \
    }
    
#define LOAD_EGL(name) LOAD_LIB(egl, name)

#ifdef NOEGL
#define LOAD_GLES_OES(name) \
    DEFINE_RAW(gles, name); \
    { \
        LOAD_RAW(gles, name, dlsym(gles, #name"OES")); \
    }

#define LOAD_GLES_EXT(name) \
    DEFINE_RAW(gles, name); \
    { \
        LOAD_RAW(gles, name, dlsym(gles, #name"EXT")); \
    }

#define LOAD_GLES2_OR_OES(name) \
    DEFINE_RAW(gles, name); \
    { \
        LOAD_RAW_SILENT(gles, name, dlsym(gles, #name)); \
    }

#else

#define LOAD_GLES_OES(name) \
    DEFINE_RAW(gles, name); \
    { \
        LOAD_EGL(eglGetProcAddress); \
        LOAD_RAW(gles, name, egl_eglGetProcAddress(#name"OES")); \
    }

#define LOAD_GLES_EXT(name) \
    DEFINE_RAW(gles, name); \
    { \
        LOAD_EGL(eglGetProcAddress); \
        LOAD_RAW(gles, name, egl_eglGetProcAddress(#name"EXT")); \
    }

#define LOAD_GLES2_OR_OES(name) \
    DEFINE_RAW(gles, name); \
    { \
        LOAD_EGL(eglGetProcAddress); \
        LOAD_RAW_SILENT(gles, name, ((hardext.esversion==1)?((void*)egl_eglGetProcAddress(#name"OES")):((void*)dlsym(gles, #name)))); \
    }
#endif //NOEGL

#endif
