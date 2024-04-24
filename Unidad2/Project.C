#include <stdio.h>
#include <SDL.h>

#define TRUE 1
#define FALSE 0
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

SDL_Window* window = NULL;


int init_window(void){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error SDL_Init\n");
        return FALSE;
    }

    window = SDL_CreateWindow(
        "My first Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS);
    if (window == NULL) {
        printf("Error SDL_CreateWindow\n");
        return FALSE;
    }
    return TRUE;
}


int main(int argc, char* argv[]) {
    init_window();
    while (TRUE) {
    }
    return 0;
}
