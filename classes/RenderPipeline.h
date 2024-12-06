#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "RenderImage.h"
#include <iostream>

#ifndef RENDER_PIPELINE_H
#define RENDER_PIPELINE_H

class RenderPipeline
{
    private:
    std::vector<RenderImage*> obrazki;

    public:
    void Dodaj_pole(RenderImage* dodaj);
    void displayPipeline(SDL_Renderer *renderer);
    void removeFromPipeline(std::string idToRemove, SDL_Renderer *renderer);
};

#endif