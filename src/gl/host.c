#include "host.h"

#define INIT_EGL(name) \
    host_functions.name = (name##_PTR) proc_address(egl, "eglGetProcAddress"); \
    WARN_NULL(host_functions.name); \

#define INIT_GLES_FPE(name) \
    host_functions.fpe_##name = (name##_PTR) ((globals4es.es == 1) ? proc_address(gles, #name) : (void*) fpe_##name); \
    WARN_NULL(host_functions.fpe_##name); \

#define INIT_GLES_OR_FPE(name) \
    host_functions.name = (name##_PTR) proc_address(gles, #name); \
    host_functions.fpe_##name = (name##_PTR) ((globals4es.es == 1) ? host_functions.name : (void*) fpe_##name); \
    WARN_NULL(host_functions.fpe_##name); \

#define INIT_GLES(name) \
    host_functions.name = (name##_PTR) proc_address(gles, #name); \
    WARN_NULL(host_functions.name); \

#define INIT_GLES_OPT(name) \
    host_functions.name = (name##_PTR) host_functions.eglGetProcAddress(#name); \

#define INIT_GLES_NO_FPE(name) \
    host_functions.name = (name##_PTR) proc_address(gles, #name); \
    if(globals4es.es==1) {WARN_NULL(host_functions.name);} \

#define INIT_GLES_NO_1(name) \
    host_functions.name = (name##_PTR) proc_address(gles, #name); \
    if(globals4es.es!=1) {WARN_NULL(host_functions.name);}

#define INIT_GLES_OR_OES(name) \
    if(globals4es.es > 1) { host_functions.name = (name##_PTR) proc_address(gles, #name); } else { host_functions.name = (name##_PTR) host_functions.eglGetProcAddress(#name"OES"); } \
    if(globals4es.es > 1) {WARN_NULL(host_functions.name);} \

#define INIT_GLES_EXT(name) \
    host_functions.name = (name##_PTR) host_functions.eglGetProcAddress(#name"EXT"); \
    /*WARN_NULL(host_functions.name);*/ \

#define INIT_GLES_OES(name) \
    host_functions.name = (name##_PTR) host_functions.eglGetProcAddress(#name"OES"); \
    /*WARN_NULL(host_functions.name);*/ \

gl_functions host_functions = {};
void init_gl_functions() {
    ALL_FUNCTIONS(); 
};
#undef INIT_GLES_FPE
#undef INIT_GLES_OR_FPE
#undef INIT_GLES_NO_FPE
#undef INIT_GLES_NO_1
#undef INIT_GLES
#undef INIT_GLES_OR_OES
#undef INIT_GLES_EXT
#undef INIT_GLES_OES
#undef INIT_EGL
