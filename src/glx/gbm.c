#include "hardext.h"
#include "../gl/loader.h"
#include "../gl/init.h"
#include "../gl/gl4es.h"
#include "glx_gbm.h"

#define SHUT(a) if(!globals4es.nobanner) a

#ifndef NO_GBM
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <gbm.h>

#ifndef NO_GBM
#ifndef EGL_PLATFORM_GBM_KHR
#define EGL_PLATFORM_GBM_KHR                     0x31D7
#endif
#endif

// define static function pointers
// for GBM
#define GBMFUNC(ret, name, args) \
    typedef ret (*PFN##name) args; \
    static PFN##name gbmdrm_##name = NULL;
#include "gbmfunc.h"
#undef GBMFUNC

static void CancelGBM()
{
    if(gbm)
        dlclose(gbm);
    #define GBMFUNC(ret, name, args) \
        gbmdrm_##name = NULL;
    #include "gbmfunc.h"
    #undef GBMFUNC

    gbm = NULL;
    globals4es.usegbm = 0;
}

static int drm_fd = -1; // drm handle
static struct gbm_device *gbmdev = NULL;

static int OpenGBM()
{
    int available = 0;

    int drm_fd = open(globals4es.drmcard, O_RDWR | O_CLOEXEC);
    if (drm_fd >= 0) {
        gbmdev = gbmdrm_gbm_create_device(drm_fd);
        if(!gbmdev) {
            printf("LIBGL: Error initializing gbm device\n");
        } else {
            available = 1;
        }
    }

    SHUT(printf("LIBGL: GBM on card %s is %s\n", globals4es.drmcard, available?"Available":"Not available"));

    return available;
}

void LoadGBMFunctions()
{
    if(!gbm)
        return;
    // load functions
    #define GBMFUNC(ret, name, args) \
        gbmdrm_##name = (PFN##name)dlsym(gbm, #name); \
        if(!gbmdrm_##name) { \
            printf("LIBGL: function %s missing, no gbm surface enabled\n", #name); \
            CancelGBM(); \
            return; \
        }
    #include "gbmfunc.h"
    #undef GBMFUNC
    // Check card
    if(!OpenGBM()) {
        CancelGBM();
        return;
    }
    // all done
    return;
}

void CloseGBMFunctions()
{
    if(gbmdev) {
        gbmdrm_gbm_device_destroy(gbmdev);
        gbmdev = NULL;
    }
    if (drm_fd >= 0) {
        close(drm_fd);
        drm_fd = -1;
    }

}

void* OpenGBMDisplay(void* display)
{
    if(hardext.gbm) {
        LOAD_EGL(eglGetPlatformDisplay);
        return egl_eglGetPlatformDisplay(EGL_PLATFORM_GBM_KHR, gbmdev, NULL);
    } else {
        LOAD_EGL(eglGetDisplay);
        return egl_eglGetDisplay((EGLNativeDisplayType)gbmdev);
    }
}

void* CreateGBMWindow(int w, int h)
{
    void* ret = gbmdrm_gbm_surface_create(gbmdev, w, h, GBM_FORMAT_XRGB8888, GBM_BO_USE_RENDERING);
    if(!ret)
        printf("LIBGL: Warning, cannot create gbm surface %dx%d\n", w, h);
}

void DeleteGBMWindow(void* win)
{
    gbmdrm_gbm_surface_destroy((struct gbm_surface*)win);
}

int FindGBMConfig(EGLConfig *configs, int numFounds)
{
    int idx = 0;
    while(idx<numFounds)
    {
        EGLint gbm_format;
        if (eglGetConfigAttrib(gbmdev, configs[idx], EGL_NATIVE_VISUAL_ID, &gbm_format)) {
            if (gbm_format == GBM_FORMAT_XRGB8888) {
                return idx;
            }
        }
        ++idx;
    }
    printf("LIBGL: Warning, no EGLConfig matching GBM Format found\n");
    return 0;   // not found...
}

#else // NO_GBM

void LoadGBMFunctions()
{
}

void CloseGBMFunctions()
{
}

void* OpenGBMDisplay(void* display)
{
    return NULL;
}

void* CreateGBMWindow(int w, int h)
{
    return NULL;
}

void DeleteGBMWindow(void* win)
{
}

#if !defined(NOEGL) && !defined(ANDROID)
int FindGBMConfig(EGLConfig *configs, int numFounds)
{
    return 0;
}
#endif

#endif // NO_GBM