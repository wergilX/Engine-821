#pragma once

#include <cstdint>

enum class ButtonAction : uint8_t
{
    Press,
    Release,
};

enum class MouseButton : uint8_t
{
    Left   = 1,
    Middle = 2,
    Right  = 3,
};

struct MouseClickEvent
{
    int32_t X;
    int32_t Y;
    ButtonAction Action;
    MouseButton  Button;
};

struct WindowResizedEvent
{
    int32_t Width  = 0;
    int32_t Height = 0;
};