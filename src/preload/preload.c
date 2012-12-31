#include <SDL/SDL.h>

SDL_GrabMode SDL_WM_GrabInput(SDL_GrabMode mode) {
    printf("SDL_WM_GrabInput\n");
    return mode;
}

int SDL_ShowCursor(int toggle) {
    printf("SDL_ShowCursor\n");
    return 0;
}

void SDL_WarpMouse(Uint16 x, Uint16 y) {
    printf("SDL_WM_WarpMouse\n");
}
/*
int SDL_PollEvent(SDL_Event *event) {
    return 0;
}
*/