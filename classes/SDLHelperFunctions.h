#include <SDL2/SDL.h>
#include "RenderPipeline.h"
#include "ArgumentHelper.h"
#include <any>
#include <iostream>
#include <typeinfo>
#include <cstring>

void display(bool *running, RenderPipeline pipeline, SDL_Renderer *renderer, ArgumentHelper args)
{
    bool b_debug = false;
    // if(std::strcmp(std::any_cast<const char*>(args.argValues.at("--debug").value),"1") == 0) { b_debug = true; }
    float time = SDL_GetTicks64();
    Uint64 frametime = 1000/60;
    while(running)
    {
        if(b_debug) { std::cout<<"Attempting to draw thread, time: "<<SDL_GetTicks64()-time<<std::endl; }
        
        if(SDL_GetTicks64() - frametime > time)
        {
            if(b_debug) { std::cout<<"DRAWING THREAD #############################################################, time: "<<SDL_GetTicks64()-time<<std::endl; }
            
            time = SDL_GetTicks64();
            pipeline.displayPipeline(renderer);
        }
    }
}