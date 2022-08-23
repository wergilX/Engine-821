#include "engine/engine.h"

#undef main
int main()
{
    Engine engine;
    engine.Initialize();
    engine.Run();
    engine.Destroy();
    return 0;
}
