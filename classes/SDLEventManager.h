#include <SDL2/SDL.h>
#include <iostream>

void EventHandler(SDL_Event e, bool *running, SDL_Renderer *renderer, SDL_Window *window) {
    switch(e.type) {
            case SDL_QUIT: {
                *running = false;
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                break;
            }
            case SDL_KEYUP:
            case SDL_KEYDOWN: {
                *running = false;
                break;
            } 
            default: {
                break;
            }
        }
}