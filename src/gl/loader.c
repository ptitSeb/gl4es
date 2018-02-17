#include "loader.h"
#include "logs.h"
#include "init.h"
#ifdef AMIGAOS4
#include "../agl/amigaos.h"
#include <limits.h>
#else
#include <linux/limits.h>
#endif

void *gles = NULL, *egl = NULL, *bcm_host = NULL, *vcos = NULL;
#ifndef AMIGAOS4
static const char *path_prefix[] = {
    "",
    "/opt/vc/lib/",
    "/usr/local/lib/",
    "/usr/lib/",
    NULL,
};

static const char *lib_ext[] = {
    "so",
    "so.1",
    "so.2",
    "dylib",
    "dll",
    NULL,
};

static const char *gles2_lib[] = {
    "libGLESv2_CM",
    "libGLESv2",
    "libbrcmGLESv2",
    NULL
};

static const char *gles_lib[] = {
    "libGLESv1_CM",
    "libGLES_CM",
    "libbrcmGLESv1_CM",
    NULL
};

static const char *egl_lib[] = {
    "libEGL",
    "libbrcmEGL",
    NULL
};

void *open_lib(const char **names, const char *override) {
    void *lib = NULL;

    char path_name[PATH_MAX + 1];
    int flags = RTLD_LOCAL | RTLD_NOW;
#ifdef RTLD_DEEPBIND
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
                    if(!globals4es.nobanner) LOGD("LIBGL:loaded: %s\n", path_name);
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
    char *gles_override = getenv("LIBGL_GLES");
    // optimistically try to load the raspberry pi libs
    if (! gles_override) {
        const char *bcm_host_name[] = {"libbcm_host", NULL};
        const char *vcos_name[] = {"libvcos", NULL};
        bcm_host = open_lib(bcm_host_name, NULL);
        vcos = open_lib(vcos_name, NULL);
    }
    gles = open_lib((globals4es.es==1)?gles_lib:gles2_lib, gles_override);
    WARN_NULL(gles);

#ifdef NOEGL
    egl = gles;
#else
    char *egl_override = getenv("LIBGL_EGL");
    egl = open_lib(egl_lib, egl_override);
#endif
    WARN_NULL(egl);
}
#else
void load_libs() {
    os4OpenLib();
}
#endif //AMIGAOS4