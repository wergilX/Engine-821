#pragma once

#include "IRenderer.hpp"
#include "common/Types.hpp"

#include <SDL.h>

using namespace Engine::Common::Types;

namespace Engine::Core {

    class Renderer : public IRenderer {
    public:

        void Initialize() override;

        void Destroy() override;

        void Clear(const Color &) override;

        void Present() override;

        void DrawDebugBox(const Color &color, const Transform &worldTransform) override;

        void DrawDebugArrow(const Color &color, const Vector &worldStart, const Vector &worldEnd) override;

        void DrawDebugArrow(const Color &color, const Vector &worldDirection, float scale) override;

        void DrawDebugCircle(const Color &color, const Vector &worldCenter, float radius) override;

        void DrawSprite(ID textureID, const Transform &worldTransform) override;

        void DrawDebugSpline(...) override;

    private:
        void SetColor(const Color& color);

        SDL_Window* p_Window = nullptr;
        SDL_Renderer* p_Renderer = nullptr;
    };
}