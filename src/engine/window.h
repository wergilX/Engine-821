#pragma once

#include <string>

class Window
{
public:
    struct Config
    {
        std::string Title;
        int32_t Width;
        int32_t Height;
    };
public:
    void Initialize(const Config& config);
    void Destroy();

    bool OnResize(int32_t width, int32_t height);

    void GetSize(int32_t& outWidth, int32_t& outHeight) const;
    struct SDL_Window* GetHandle() const;

private:
    struct SDL_Window* p_Handle = nullptr;

    int32_t m_Width  = 0;
    int32_t m_Height = 0;
};