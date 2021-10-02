#include "Rendering/UI/Fonts.hpp"

TTF_Font* Fonts::ARIAL;
TTF_Font* Fonts::SMALL_ARIAL;

bool init_fonts()
{
    /*
    Load Fonts
    */
    Fonts::ARIAL = TTF_OpenFont("res/font/arial.ttf", 80);
    if (Fonts::ARIAL == NULL)
    {
        std::cout << "Couldn't load Arial " << TTF_GetError() << std::endl;
        char cwd[100];
        std::cout << getcwd(cwd, 100) << std::endl;
        return false;
    }

    Fonts::SMALL_ARIAL = TTF_OpenFont("res/font/arial.ttf", 20);
    if (Fonts::SMALL_ARIAL == NULL)
    {
        std::cout << "Couldn't load Arial " << TTF_GetError() << std::endl;
        char cwd[100];
        std::cout << getcwd(cwd, 100) << std::endl;
        return false;
    }

    return true;
}