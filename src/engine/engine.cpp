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

    if (p_Winodw = SDL_CreateWindow("Engine 821", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_RESIZABLE); p_Winodw == nullptr)
    {
        printf("Failed to create window: %s\n", SDL_GetError()); // TODO: assert (with fmt)
        return;
    }

    if (p_Renderer = SDL_CreateRenderer(p_Winodw, 1, SDL_RENDERER_ACCELERATED); p_Renderer == nullptr)
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
        HandleEvents();

        static float power = 0.01f;
        static float red = 0.f;
        red += power;

        if (red > 255.f || red < 0.f)
        {
            power = -power;
        }

        uint8_t r = static_cast<uint8_t>(red);
        
        SDL_SetRenderDrawColor(p_Renderer, red, red / 4, red / 2, 255);
        SDL_RenderClear(p_Renderer);
        SDL_RenderPresent(p_Renderer);
    }
    
}

void Engine::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                OnQuitEvent();
                break;
            }

            case SDL_WINDOWEVENT:
            {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    OnWindowResizedEvent({
                        .Width  = event.window.data1,
                        .Height = event.window.data2,
                    });
                }
                break;
            }

            case SDL_MOUSEBUTTONDOWN:
            {
                OnClickEvent({
                    .X = event.button.x,
                    .Y = event.button.y,
                    .Action = ButtonAction::Press,
                    .Button = static_cast<MouseButton>(event.button.button),                
                });
                break;
            }

            case SDL_MOUSEBUTTONUP:
            {
                OnClickEvent({
                    .X = event.button.x,
                    .Y = event.button.y,
                    .Action = ButtonAction::Release,
                    .Button = static_cast<MouseButton>(event.button.button),                
                });
                break;
            }
            
            default: break;
        }
    }
}

void Engine::OnQuitEvent()
{
    m_Running = false;
}

void Engine::OnWindowResizedEvent(const WindowResizedEvent& event)
{
    printf("Window size: %dx%d\n", event.Width, event.Height);
}

void Engine::OnClickEvent(const MouseClickEvent& event)
{
    if (event.Action == ButtonAction::Press)
    {
        printf("Pressed: %dx%d\n", event.X, event.Y);
    }
    else
    {
        printf("Released: %dx%d\n", event.X, event.Y);
    }
}