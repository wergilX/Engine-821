#include "Renderer.hpp"
#include "core/Logger.hpp"
#include "common/Circle.hpp"

namespace Engine::Core {

    void Renderer::Initialize()
    {
        ASSERT((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0), "Failed to init SDL: {}}\n", SDL_GetError());
        LOG("SDL_Init: complete")

        p_Window = SDL_CreateWindow("Engine 821", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
        ASSERT_NOT_NULL(p_Window, "Failed to create window: {}\n", SDL_GetError());
        LOG("SDL_CreateWindow: complete")

        p_Renderer = SDL_CreateRenderer(p_Window, 1, SDL_RENDERER_ACCELERATED);
        ASSERT_NOT_NULL(p_Renderer, "Failed to create renderer {}\n", SDL_GetError());
        LOG("SDL_CreateRenderer: complete")
    }

    void Renderer::Destroy()
    {
        SDL_DestroyRenderer(p_Renderer);
        SDL_DestroyWindow(p_Window);
    }

    void Renderer::SetColor(const Color& color)
    {
        SDL_SetRenderDrawColor(p_Renderer, color.R, color.G, color.B, color.A);
    }

    void Renderer::Clear(const Color& color)
    {
        SetColor(color);
        SDL_RenderClear(p_Renderer);
    }

    void Renderer::Present()
    {
        SDL_RenderPresent(p_Renderer);
    }

    void Renderer::DrawDebugBox(const Color& color, const Transform& worldTransform)
    {
        SetColor(color);
        SDL_RenderDrawRect(
                p_Renderer,
                {
                    worldTransform.Location.X,
                    worldTransform.Location.Y,
                    worldTransform.Size.X,
                    worldTransform.Size.Y
                });
    }

    void Renderer::DrawDebugArrow(const Color& color, const Vector& worldStart, const Vector& worldEnd)
    {
        SetColor(color);
        SDL_RenderDrawLine(p_Renderer,
                           worldStart.X, worldStart.Y, worldEnd.X,worldEnd.Y);
    }

    void Renderer::DrawDebugArrow(const Color& color, const Vector& worldDirection, float scale)
    {
        SetColor(color);
    }

    void Renderer::DrawDebugCircle(const Color& color, const Vector& worldCenter, float radius)
    {
        SetColor(color);
        Common::Circle::DrawCircle(p_Renderer, worldCenter, radius);
    }

    void Renderer::DrawSprite(ID textureID, const Transform& worldTransform)
    {
        //todo TextureManager
    }

    void Renderer::DrawDebugSpline(...)
    {
        // todo SplineManager
    }
}
