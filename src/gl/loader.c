#include "loader.h"

void (*gl4es_getMainFBSize)(GLint* width, GLint* height);

#if defined NO_LOADER

void *gles = (void*)(~(uintptr_t)0);
void *egl = (void*)(~(uintptr_t)0);
void *open_lib(const char **names, const char *override) {
    return (void*)(~(uintptr_t)0);
}
void load_libs() {
}

#elif defined AMIGAOS4
#include "../agl/amigaos.h"
void *gles;
void load_libs() {
    os4OpenLib(&gles);
}

void *open_lib(const char **names, const char *override) {
    return (void*)(~(uintptr_t)0);
}


#else
// PATH_MAX
#ifdef __linux__
#include <linux/limits.h>
#else
#include <limits.h>
#endif
#include "logs.h"
#include "init.h"
#include "envvars.h"

void *gles = NULL, *egl = NULL, *bcm_host = NULL, *vcos = NULL, *gbm = NULL, *drm = NULL;
#ifndef NO_GBM
static const char *drm_lib[] = {
    "libdrm",
    NULL
};
static const char *gbm_lib[] = {
    "libgbm",
    NULL
};
#endif

static const char *path_prefix[] = {
    "",
    "/opt/vc/lib/",
    "/usr/local/lib/",
    "/usr/lib/",
    NULL,
};

static const char *lib_ext[] = {
#ifndef NO_GBM
    "so.19",
#endif
    "so",
    "so.1",
    "so.2",
    "dylib",
    "dll",
    NULL,
};

static const char *gles2_lib[] = {
    #if defined(BCMHOST)
    "libbrcmGLESv2",
    #endif
    "libGLESv2_CM",
    "libGLESv2",
    NULL
};

static const char *gles_lib[] = {
    #if defined(BCMHOST)
    "libbrcmGLESv1_CM",
    #endif
    "libGLESv1_CM",
    "libGLES_CM",
    NULL
};

static const char *egl_lib[] = {
    #if defined(BCMHOST)
    "libbrcmEGL",
    #endif
    "libEGL",
    NULL
};

void *open_lib(const char **names, const char *override) {
    void *lib = NULL;

    char path_name[PATH_MAX + 1];
    int flags = RTLD_LOCAL | RTLD_NOW;
#if defined(RTLD_DEEPBIND) && !defined(PYRA)
    // note: breaks address sanitizer
    flags |= RTLD_DEEPBIND;
#endif
    if (override) {
        if ((lib = dlopen(override, flags))) {
            strncpy(path_name, override, PATH_MAX);
            if(!globals4es.nobanner) LOGD("LIBGL:loaded: %s\n", path_name);
            return lib;
        } else {
            LOGE("LIBGL_GLES override failed: %s\n", dlerror());
        }
    }
    for (int p = 0; path_prefix[p]; p++) {
        for (int i = 0; names[i]; i++) {
            for (int e = 0; lib_ext[e]; e++) {
                snprintf(path_name, PATH_MAX, "%s%s.%s", path_prefix[p], names[i], lib_ext[e]);
                if ((lib = dlopen(path_name, flags))) {
                    if(!globals4es.nobanner) LOGD("loaded: %s\n", path_name);
                    return lib;
                }
            }
        }
    }
    return lib;
}

void load_libs() {
    static int first = 1;
    if (! first) return;
    first = 0;
    const char *gles_override = GetEnvVar("LIBGL_GLES");
#if defined(BCMHOST) && !defined(ANDROID)
    // optimistically try to load the raspberry pi libs
    if (! gles_override) {
        const char *bcm_host_name[] = {"libbcm_host", NULL};
        const char *vcos_name[] = {"libvcos", NULL};
        bcm_host = open_lib(bcm_host_name, NULL);
        vcos = open_lib(vcos_name, NULL);
    }
#endif
    gles = open_lib((globals4es.es==1)?gles_lib:gles2_lib, gles_override);
    WARN_NULL(gles);

#ifdef NOEGL
    egl = gles;
#else
    const char *egl_override = GetEnvVar("LIBGL_EGL");
    egl = open_lib(egl_lib, egl_override);
#endif
    WARN_NULL(egl);

#ifndef NO_GBM
    const char *gbm_override = GetEnvVar("LIBGL_GBM");
    gbm = open_lib(gbm_lib, gbm_override);
    const char *drm_override = GetEnvVar("LIBGL_DRM");
    drm = open_lib(drm_lib, drm_override);
#endif
}
#endif

// user-defined getProcAddress
void *(*gles_getProcAddress)(const char *name);

void *proc_address(void *lib, const char *name) {
    if (gles_getProcAddress)
        return gles_getProcAddress(name);
#ifdef AMIGAOS4
    return os4GetProcAddress(name);
#elif defined __EMSCRIPTEN__
    void *emscripten_GetProcAddress(const char *name);
    return emscripten_GetProcAddress(name);
#elif defined __APPLE__
    // apple code seems to use RTLD_NEXT which is usually ((void*)-1)
    // remove if it not needed
    return dlsym((void*)(~(uintptr_t)0), name);
#elif !defined NO_LOADER
    return dlsym(lib, name);
#else
    return NULL;
#endif
}
