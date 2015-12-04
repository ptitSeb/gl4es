#ifndef LOADER_H
#define LOADER_H

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"

// will become references to dlopen'd gles and egl
extern void *gles, *egl, *bcm_host, *vcos;

extern void *open_lib(const char **names, const char *override);
extern void load_libs();

#ifndef WARN_NULL
#define WARN_NULL(name) if (name == NULL) printf("libGL: warning, " #name " is NULL\n");
#endif

#ifndef LOAD_RAW
#define DEFINE_RAW(lib, name) static name##_PTR lib##_##name
#define LOAD_RAW(lib, name, ...) \
    { \
        static bool first = true; \
        if (first) { \
            first = false; \
            if (lib == NULL) { \
                load_libs(); \
            } \
            if (lib != NULL) { \
                lib##_##name = (name##_PTR)__VA_ARGS__; \
            } \
            WARN_NULL(lib##_##name); \
        } \
    }
#endif

#define LOAD_LIB(lib, name) DEFINE_RAW(lib, name); LOAD_RAW(lib, name, dlsym(lib, #name))

#ifndef LOAD_GLES
#define LOAD_GLES(name) \
    LOAD_LIB(gles, name)
    
#endif

#define LOAD_EGL(name) LOAD_LIB(egl, name)
#define LOAD_GLES_OES(name) \
    DEFINE_RAW(gles, name); \
    { \
        LOAD_EGL(eglGetProcAddress); \
        LOAD_RAW(gles, name, egl_eglGetProcAddress(#name"OES")); \
    }

#endif
