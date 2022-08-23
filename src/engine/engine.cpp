#include "engine.h"

#include <SDL.h>
#include <cstdio>


void Engine::Initialize()
{
    // Initilize SDL:
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        printf("Failed to init SDL: %s\n", SDL_GetError()); // TODO: assert (with fmt)
        return;
    }

    if (p_Winodw = SDL_CreateWindow("Engine 821", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0); p_Winodw == nullptr)
    {
        printf("Failed to create window: %s\n", SDL_GetError()); // TODO: assert (with fmt)
        return;
    }

    if (p_Renderer = SDL_CreateRenderer(p_Winodw, 1, SDL_RENDERER_ACCELERATED))
    {
        printf("Failed to create renderer: %s\n", SDL_GetError()); // TODO: assert (with fmt)
        return;
    }
}

void Engine::Destroy()
{
    SDL_DestroyRenderer(p_Renderer);
    SDL_DestroyWindow(p_Winodw);
}

void Engine::Run()
{
    m_Running = true;
    while (m_Running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                m_Running = false;
            }
        }

        static uint8_t red = 0;
        red += 1;


        SDL_SetRenderDrawColor(p_Renderer, red, 0, 0, 255);
        SDL_RenderClear(p_Renderer);



        SDL_RenderPresent(p_Renderer);
    }
    
}