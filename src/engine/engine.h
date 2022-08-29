#pragma once

#include "events.h"
#include "window.h"

class Engine
{
public:
    struct Config
    {
        Window::Config Window;
    };

public:
    void Initialize(const Config& config);
    void Destroy();
    void Run();

private:
    void HandleEvents();

    // TODO: Finish other events
    // TODO: Axis / Action
    void OnQuitEvent();
    void OnWindowResizedEvent(const WindowResizedEvent& event);
    void OnClickEvent(const MouseClickEvent& event);

private:
    Window m_Window;
    struct SDL_Renderer* p_Renderer = nullptr;  // Temp shit

    bool m_Running = false;
};