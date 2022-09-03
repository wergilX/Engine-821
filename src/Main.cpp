#include "engine/Engine.hpp"
#include "engine/core/Logger.hpp"

#include <cstdio>
#include <vector>

#include <fmt/format.h>

#undef main
int main()
{
    Engine engine;
    engine.Initialize();
    engine.Run();
    engine.Destroy();
    return 0;
}
