#include "Rendering/Spritesheet.hpp"

Spritesheet::Spritesheet(std::string filename)
{
    Logger::log(LogLevel::INFO, "Opening file " + filename);
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (surface == NULL)
    {
        Logger::log(LogLevel::ERROR, "Error loading " + filename);
        Logger::log(LogLevel::ERROR, IMG_GetError());
    }


    //SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);

    this->spritesheet = surface;
    this->spritesheet->refcount += 1;

    //SDL_FreeSurface(surface);
}