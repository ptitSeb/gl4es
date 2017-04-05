#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <dlfcn.h>

#include "rpi.h"

// Code specific to RPI
// everything is dynamicaly linked, so this can be saffely compiled everywhere
extern void* bcm_host;
extern void* vcos;

typedef uint32_t DISPMANX_DISPLAY_HANDLE_T;
typedef uint32_t DISPMANX_UPDATE_HANDLE_T;
typedef uint32_t DISPMANX_ELEMENT_HANDLE_T;
typedef uint32_t DISPMANX_RESOURCE_HANDLE_T;
typedef uint32_t DISPMANX_PROTECTION_T;
typedef struct tag_VC_RECT_T {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
} VC_RECT_T;
typedef struct {
    DISPMANX_ELEMENT_HANDLE_T element;
    int width;
    int height;
} EGL_DISPMANX_WINDOW_T;
int32_t (*graphics_get_display_size)(const uint16_t, uint32_t *, uint32_t*);
DISPMANX_DISPLAY_HANDLE_T (*vc_dispmanx_display_open)(uint32_t);
DISPMANX_UPDATE_HANDLE_T (*vc_dispmanx_update_start)(int32_t);
DISPMANX_ELEMENT_HANDLE_T (*vc_dispmanx_element_add)(
    DISPMANX_UPDATE_HANDLE_T, DISPMANX_DISPLAY_HANDLE_T, int32_t,
    VC_RECT_T *, DISPMANX_RESOURCE_HANDLE_T,
    VC_RECT_T *, DISPMANX_PROTECTION_T, 
    /*VC_DISPMANX_ALPHA_T*/void*, /*DISPMANX_CLAMP_T*/void*, 
    /*DISPMANX_TRANSFORM_T*/ int32_t);
int (*vc_dispmanx_update_submit_sync)(DISPMANX_RESOURCE_HANDLE_T);
static DISPMANX_UPDATE_HANDLE_T dispman_update;
static DISPMANX_DISPLAY_HANDLE_T dispman_display;
static VC_RECT_T dst_rect;
static VC_RECT_T src_rect;

void rpi_init() {
        #define GO(A) A=dlsym(bcm_host, #A); if(A==NULL) A=dlsym(vcos, #A); if(A==NULL) printf("LIBGL: Warning, " #A " is null")
        GO(graphics_get_display_size);
        GO(vc_dispmanx_display_open);
        GO(vc_dispmanx_update_start);
        GO(vc_dispmanx_element_add);
        GO(vc_dispmanx_update_submit_sync);
        #undef GO
}

void* create_rpi_window(int w, int h) {
    static EGL_DISPMANX_WINDOW_T nativewindow;
    if(!bcm_host) return NULL;
    // create a simple RPI nativewindow of size w*h, on output 0 (i.e. LCD)...
    // code heavily inspired from Allegro 5.2
    uint32_t screenwidth, screenheight;
    graphics_get_display_size(/*LCD*/ 0, &screenwidth, & screenheight);
    if(w==0) w=screenwidth;
    if(h==0) h=screenheight;
    DISPMANX_ELEMENT_HANDLE_T dispman_element;
    VC_RECT_T dst_rect, src_rect;
    dst_rect.x = 0; dst_rect.y = 0;
    dst_rect.width = screenwidth;
    dst_rect.height = screenheight;
    src_rect.x = 0; src_rect.y = 0;
    src_rect.width = w << 16;
    src_rect.height = h << 16;
    dispman_display = vc_dispmanx_display_open(/*LCD*/ 0);
    dispman_update = vc_dispmanx_update_start(0);
    dispman_element = vc_dispmanx_element_add(
        dispman_update,dispman_display, 0, &dst_rect,
        0, &src_rect, /*DISPMANX_PROTECTION_NONE*/ 0, 0, 0, 
        /*DISPMAN_NO_ROTATE*/ 0);
    nativewindow.element = dispman_element;
    nativewindow.width = w;
    nativewindow.height = h;
    vc_dispmanx_update_submit_sync(dispman_update);

    return &nativewindow;
}
