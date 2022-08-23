#pragma once

class Engine
{
public:
    void Initialize(); // TODO: struct EngineConfig
    void Destroy();
    void Run();

private: // Temp shit:
    struct SDL_Window* p_Winodw = nullptr;
    struct SDL_Renderer* p_Renderer = nullptr;

    bool m_Running = false;
};