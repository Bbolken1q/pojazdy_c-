#include <SDL2/SDL.h>
#include "RenderPipeline.h"
#include "ArgumentHelper.h"
#include <any>
#include <iostream>
#include <typeinfo>
#include <functional>
#include <cstring>

using function = std::function<void()>;

void display(bool *running, RenderPipeline pipeline, SDL_Renderer *renderer, ArgumentHelper args)
{
    bool b_debug = false;
    if(std::strcmp(std::any_cast<const char*>(args.argValues.at("--debug").value),"1") == 0) { b_debug = true; }
    float time = SDL_GetTicks64();
    Uint64 frametime = 1000/60;
    while(*running)
    {
        if(b_debug) { std::cout<<"Attempting to draw thread, time: "<<SDL_GetTicks64()-time<<std::endl; }
        
        if(SDL_GetTicks64() - frametime > time)
        {
            time = SDL_GetTicks64();
            pipeline.displayPipeline(renderer);

            if(b_debug) { std::cout<<"DRAWING THREAD #############################################################, time: "<<SDL_GetTicks64()-time<<std::endl; }
        }
    }
}

void runAsyncAtFrameSpeed(function fun, int userTime) //time in frames
{
    auto thread = std::async([&]()
    {
        float time = SDL_GetTicks64();
        Uint64 frametime = 1000/60;
        int frames = 0;
        do
        {
            if(SDL_GetTicks64() - frametime > time)
            {
                time = SDL_GetTicks64();
                fun();
                frames++;
            }
        }
        while(frames<userTime);
    });
    
}

void move_by(SDL_Rect &pos, SDL_Rect posTarget, int frameTime /*time in frames @ 60 frames per second, POSITIONS ARE RELATIVE*/)
{
    runAsyncAtFrameSpeed([&]()
    {
    pos.x = pos.x + ((posTarget.x-pos.x)/frameTime);
    pos.y = pos.y + ((posTarget.y-pos.y)/frameTime);
    pos.w = pos.w + ((posTarget.w-pos.w)/frameTime);
    pos.h = pos.h + ((posTarget.h-pos.h)/frameTime);
    return 0;
    }, frameTime);
    
}