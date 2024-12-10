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
#include "classes/SDLEventManager.h"

std::string window_name = "Pojazdy";

using function = std::function<void()>;
Uint32 window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_MOUSE_GRABBED;


int main(int argc, char *argv[]) {

    std::map<std::string, const std::type_info&> flagmap;

    flagmap.insert({"--quantity", typeid(int)});
    flagmap.insert({"--points", typeid(int)});
    flagmap.insert({"--debug", typeid(bool)});
    flagmap.insert({"--max_simulations", typeid(int)});

    ArgumentHelper *args = new ArgumentHelper(argc, argv, flagmap);

    // for(const auto& elem : args->argValues)
    // {
    //     std::cout << elem.first << " " << elem.second.typeInfo.name() << " " << atoi(std::any_cast<const char*>(elem.second.value)) << "\n";
    // }

    // std::cout << "Running with " << std::to_string(argc-1) << " argument(s)" << std::endl;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640*2, 480*2, window_flags); // create renderer & window;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0); // init 
    SDL_Event e; // event object
    bool running = true;

    RenderPipeline pipeline;

    SDL_Rect box_position = {400, 400, 400, 400};
    RenderImage *red_box = new RenderImage(IMG_Load("assets/obrazek.png"), &box_position, "red_box", renderer);
    pipeline.Dodaj_pole(red_box);
    // pipeline.displayPipeline(renderer);
    // SDL_RenderPresent(renderer);

    auto renderThread = std::async(display, &running, pipeline, renderer, *args);
    while (SDL_PollEvent(&e) > 0) {
    	EventHandler(e, &running, renderer, window);
    } 

    while(true)
    {
        move_by(box_position, SDL_Rect{400, 400, 400, 400}, 30);
        SDL_Delay(500);
        move_by(box_position, SDL_Rect{200, 400, 400, 400}, 30);
        SDL_Delay(500);
    }

    // SDL_Delay(3000);

    running = false;

    return 0;
}