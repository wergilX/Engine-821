#include "Engine.hpp"
#include "core/Logger.hpp"

#include <SDL.h>
#include <cstdio>

void Engine::Initialize()
{
    ASSERT((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0), "Failed to init SDL: {}}\n", SDL_GetError());
    LOG("SDL_Init: complete")

    p_Winodw = SDL_CreateWindow("Engine 821", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    ASSERT_NOT_NULL(p_Winodw, "Failed to create window: {}\n", SDL_GetError());
    LOG("SDL_CreateWindow: complete")
   
    p_Renderer = SDL_CreateRenderer(p_Winodw, 1, SDL_RENDERER_ACCELERATED);
    ASSERT_NOT_NULL(p_Renderer, "Failed to create renderer {}\n", SDL_GetError());
    LOG("SDL_CreateRenderer: complete")
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