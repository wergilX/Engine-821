#pragma once

#include "IRenderer.hpp"

#include <memory>

namespace Engine::Core{

    class Engine
    {
    public:
        void Initialize();
        void Destroy();
        void Run();

    private:
        std::shared_ptr<IRenderer> m_renderer = nullptr;

        bool m_Running = false;
    };
}
