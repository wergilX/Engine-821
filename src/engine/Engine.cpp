#include "Engine.hpp"
#include "core/Logger.hpp"
#include "Renderer.hpp"

#include <SDL.h>

namespace Engine::Core {

    void Engine::Initialize() {
        m_renderer = std::make_shared<Renderer>();
        ASSERT_NOT_NULL(m_renderer, "Failed to create Renderer");

        m_renderer->Initialize();
    }

    void Engine::Destroy() {
        m_renderer->Destroy();
    }

    void Engine::Run() {
        m_Running = true;
        while (m_Running) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    m_Running = false;
                }
            }

            static uint8_t red = 0;
            red += 1;

            m_renderer->Clear({red, 0, 0, 255});
            m_renderer->Present();
        }
    }

}