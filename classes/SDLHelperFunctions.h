// #include <SDL2/SDL.h>
#include "RenderPipeline.h"

void display(bool *running, RenderPipeline pipeline, SDL_Renderer *renderer)
{
    float time = SDL_GetTicks64();
    Uint64 frametime = 1000/60;
    while(running)
    {
        //std::cout<<"Attempting to draw thread, time: "<<time-SDL_GetTicks64()<<std::endl;
        if(SDL_GetTicks64() - frametime > time)
        {
            //std::cout<<"DRAWING THREAD #############################################################, time: "<<time-SDL_GetTicks64()<<std::endl;
            time = SDL_GetTicks64();
            pipeline.displayPipeline(renderer);
        }
    }
}