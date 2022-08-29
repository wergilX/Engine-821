#include "engine/engine.h"

#include <fmt/format.h>
#include <cstdio>

#undef main
int main()
{
    const Engine::Config config
    {
        .Window{
            .Title  = fmt::format("Engine 821 ver {}.{}", 0, 1),
            .Width  = 1920,
            .Height = 1080,
        }
    };

    Engine engine;
    engine.Initialize(config);
    engine.Run();
    engine.Destroy();
    return 0;
}
