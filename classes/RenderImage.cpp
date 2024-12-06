#include "RenderImage.h"
#include <iostream>
#include <stdexcept>


RenderImage::RenderImage(SDL_Surface *img /*image file*/, SDL_Rect *pos /*position in SDL_Rect*/, std::string id /*id of object*/, SDL_Renderer *renderer /*window renderer instance*/)
{
    this->image = SDL_CreateTextureFromSurface(renderer, img); // creates texture object from surface (image file) 
    if(this->image == NULL)
    {
        throw std::invalid_argument("[ERROR]: Unable to load texture");
    }
    this->position = pos;
    this->id = id;
}