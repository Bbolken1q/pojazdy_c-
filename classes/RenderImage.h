#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#ifndef RENDER_IMAGE_H
#define RENDER_IMAGE_H

class RenderImage {
    public:
        SDL_Texture *image;
        std::string id;
        SDL_Rect *position;
        RenderImage(SDL_Surface *img, SDL_Rect *pos, std::string name, SDL_Renderer *renderer);
};

#endif