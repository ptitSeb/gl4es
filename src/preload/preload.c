#define _GNU_SOURCE

#include <SDL/SDL.h>
#include <dlfcn.h>
#include <X11/Xlib.h>

/*
SDL_GrabMode SDL_WM_GrabInput(SDL_GrabMode mode) {
    printf("SDL_WM_GrabInput\n");
    return mode;
}

int SDL_ShowCursor(int toggle) {
    printf("SDL_ShowCursor(%i)\n", toggle);
    return toggle;
}

void SDL_WarpMouse(Uint16 x, Uint16 y) {
    printf("SDL_WM_WarpMouse\n");
}

int SDL_PollEvent(SDL_Event *event) {
    return 0;
}
*/

int SDL_SetGamma(float r, float g, float b) {
    return 0;
}

typedef int (*XSYNCPTR)(Display *, Bool);

int XSync(Display *display, Bool discard) {
    discard = 1;

    static XSYNCPTR real_XSync;
    if (!real_XSync) {
        real_XSync = (XSYNCPTR)dlsym(RTLD_NEXT, "XSync");
    }
    return real_XSync(display, discard);
}
