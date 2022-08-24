#pragma once

#include "events.h"

class Engine
{
public:
    void Initialize(); // TODO: struct EngineConfig
    void Destroy();
    void Run();

private:
    void HandleEvents();

    void OnQuitEvent();
    void OnWindowResizedEvent(const WindowResizedEvent& event);
    void OnClickEvent(const MouseClickEvent& event);

private: // Temp shit:
    struct SDL_Window* p_Winodw = nullptr;
    struct SDL_Renderer* p_Renderer = nullptr;

    bool m_Running = false;
};