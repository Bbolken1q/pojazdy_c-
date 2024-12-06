#include "RenderPipeline.h"
#include <vector>
#include <iostream>

void RenderPipeline::Dodaj_pole(RenderImage* image /*image to add*/) { // dodaje pole do 
    obrazki.push_back(image);
}
void RenderPipeline::displayPipeline(SDL_Renderer *renderer /*window renderer instance*/) {
    SDL_RenderClear(renderer);
    for(int i = 0; i < obrazki.size(); i++)
    {
        //std::cout<<"Attempting to draw image with id: "<<obrazki.at(i)->id<<std::endl;
        SDL_RenderCopy(renderer, obrazki.at(i)->image, NULL, obrazki.at(i)->position);
    }
    SDL_RenderPresent(renderer); // finalize renderer
}
void RenderPipeline::removeFromPipeline(std::string idToRemove /*id of element to remove*/, SDL_Renderer *renderer /*window renderer instance*/) {
    for(int i = 0; i < obrazki.size(); i++) // loop through array to find element
    {
        if(obrazki.at(i)->id == idToRemove)
        {
            obrazki.erase(obrazki.begin()+i);
        }
    }
    SDL_RenderPresent(renderer); // finalize renderer
}