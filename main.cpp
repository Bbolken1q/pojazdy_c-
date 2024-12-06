#include <iostream>
#include <conio.h>
#include <map>
#include <typeinfo>
#include <any>
#include "classes/ArgumentHelper.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <functional>
#include <future>
#include <thread>
#include "classes/SDLHelperFunctions.h"
#include "classes/RenderPipeline.h"

std::string window_name = "Pojazdy";

using function = std::function<void()>;
Uint32 window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
SDL_Window* window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640*2, 480*2, window_flags); // create renderer & window;
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0); // init 
SDL_Event e; // event object
bool running = true;

int main(int argc, char *argv[]) {

    std::map<std::string, const std::type_info&> flagmap;

    flagmap.insert({"--quantity", typeid(int)});
    flagmap.insert({"--points", typeid(int)});
    flagmap.insert({"--debug", typeid(bool)});
    flagmap.insert({"--max_simulations", typeid(int)});

    ArgumentHelper *args = new ArgumentHelper(argc, argv, flagmap);

    for(const auto& elem : args->argValues)
    {
        std::cout << elem.first << " " << elem.second.typeInfo.name() << " " << atoi(std::any_cast<const char*>(elem.second.value)) << "\n";
    }

    std::cout << "Running with " << std::to_string(argc-1) << " argument(s)";

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    RenderPipeline pipeline;

    auto renderThread = std::async(display, &running, pipeline, renderer); 
    // getch();
    return 0;
}