#pragma once
#include "common/Types.hpp"

using namespace Engine::Common::Types;

namespace Engine::Core {

    class IRenderer {
    public:

        virtual void Initialize() = 0; //const Config&) = 0; // TODO: struct EngineConfig

        virtual void Destroy() = 0;

        virtual void Clear(const Color &) = 0;

        virtual void Present() = 0;

        virtual void DrawDebugBox(const Color &, const Transform &worldTransform) = 0;

        virtual void DrawDebugArrow(const Color &, const Vector &worldStart, const Vector &worldEnd) = 0;

        virtual void DrawDebugArrow(const Color &, const Vector &worldDirection, float scale) = 0;

        virtual void DrawDebugCircle(const Color &, const Vector &worldCenter, float radius) = 0;

        virtual void DrawDebugSpline(...) = 0;

        virtual void DrawSprite(ID textureID, const Transform &worldTransform) = 0;
    };
}