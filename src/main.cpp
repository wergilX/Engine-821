#include "engine/engine.h"

#include <fmt/format.h>
#include <cstdio>

#undef main
int main()
{
    std::string s = fmt::format("The answer is {}.", 42);
    printf("%s\n", s.c_str());

    Engine engine;
    engine.Initialize();
    engine.Run();
    engine.Destroy();
    return 0;
}
