#include <SDL/SDL.h>

SDL_GrabMode SDL_WM_GrabInput(SDL_GrabMode mode) {
    printf("SDL_WM_GrabInput\n");
}

int SDL_ShowCursor(int toggle) {
    printf("SDL_ShowCursor\n");
}

void SDL_WarpMouse(Uint16 x, Uint16 y) {
    printf("SDL_WM_WarpMouse\n");
}
