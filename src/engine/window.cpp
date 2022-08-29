#include "window.h"

#include <SDL.h>

void Window::Initialize(const Config& config)
{
    p_Handle = SDL_CreateWindow(
        config.Title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        config.Width,
        config.Height,
        SDL_WINDOW_RESIZABLE
    );

    // TODO: ASSERT(p_Handle != nullptr);
    m_Width  = config.Width;
    m_Height = config.Height;
}

void Window::Destroy()
{
    SDL_DestroyWindow(p_Handle);
    m_Height = 0;
    m_Width  = 0;
}

bool Window::OnResize(int32_t width, int32_t height)
{
    if (m_Width != width || m_Height != height)
    {
        m_Width  = width;
        m_Height = height;
        return true;
    }
    return false;    
}

void Window::GetSize(int32_t& outWidth, int32_t& outHeight) const
{
    outWidth  = m_Width;
    outHeight = m_Height;
}

SDL_Window* Window::GetHandle() const
{
    return p_Handle;
}