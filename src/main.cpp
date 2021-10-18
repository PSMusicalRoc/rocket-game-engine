/**
 * @file main.cpp
 * 
 * This is the main file of the entire engine.
 * Here is where inputs are handled, rendering
 * takes place, and where SDL does all its magic.
 * 
 * @todo Implement function pointers into components,
 * especially the upcoming input component.
 * @todo Make multiple files (or even a small new
 * language) that when called, initializes a
 * certain entity with certain properties (instead
 * of putting them all into init.hpp)
 */

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "Common/Entity.hpp"
#include "Common/EntCompFunctions.hpp"
#include "Common/Globals.hpp"

#include "Logging/Logger.hpp"

#include "IncludeAllComponents.hpp"
#include "init.hpp"

#include <iostream>
#include <functional>
#include <random>
#include <chrono>

#include <unistd.h>

typedef std::vector<std::shared_ptr<Entity>> EntPtrVector;
typedef std::shared_ptr<Entity> SharedPtrEntity;


Uint32 last_frame_time = 0;
Uint32 this_frame_time = SDL_GetTicks();
double delta_time = 0;

//
// Random Number Generator variables
//

unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_int_distribution distribution(0, 255);

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error initializing SDL2..." << std::endl;
        return -1;
    }

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    TTF_Init();


    init_fonts();


    SDL_Window* window = SDL_CreateWindow("Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        Globals::screen_width, Globals::screen_height, SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        std::cout << "Error creating window..." << std::endl;
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);
    if (renderer == NULL)
    {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        return -1;
    }


    /* Initialize all entities */
    init();
    
    /* get txt = our FPS entity */
    SharedPtrEntity fps_entity = find_entities_by_label("fps")[0];
    auto txt = std::any_cast<TextRenderer>(&fps_entity->component_list[0]);

    SharedPtrEntity kiwi = find_entities_by_label("kiwi")[0];
    AnimatedTextRenderer* kiwi_txt = std::any_cast<AnimatedTextRenderer>(&kiwi->component_list[1]);

    bool is_running = true;
    Logger::log(LogLevel::INFO, "Running!");
    SDL_Event event;
    //int i = 0;

    while (is_running)
    {
        last_frame_time = this_frame_time;
        this_frame_time = SDL_GetTicks();
        delta_time = (double)((this_frame_time - last_frame_time) / (double)1000);

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    std::shared_ptr<Entity> ent = create_entity();
                    ent->labels.emplace_back("ent");
                    add_component_to_entity<GravityComponent>(GravityComponent(), ent);
                    int r = distribution(generator);
                    int g = distribution(generator);
                    int b = distribution(generator);
                    add_component_to_entity<SquareComponent>(SquareComponent(32, r, g, b), ent);
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S)
                {
                    kiwi_txt->advance_dialogue();
                }
            }
        }

        physics_update(delta_time);

        update_ui(delta_time);


        /* FPS CALCULATIONS */
        long int FPS = (long int)((double)1 / (double)delta_time);
        txt->text = "FPS: " + std::to_string(FPS);



        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);

        // Problem: Spritesheet does not want to retain its
        // refcount >:(

        render(renderer);

        render_ui(renderer);

        SDL_RenderPresent(renderer);

        Uint32 time_taken = SDL_GetTicks() - this_frame_time;

        if (Uint32((double)1000/(double)Globals::FPS) > time_taken)
        {
            SDL_Delay((Uint32)((double)1000/(double)Globals::FPS) - time_taken);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}