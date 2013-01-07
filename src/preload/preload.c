#include <SDL/SDL.h>

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

/*
int SDL_PollEvent(SDL_Event *event) {
    return 0;
}
*/

int SDL_SetGamma(float r, float g, float b) {
    return 0;
}
