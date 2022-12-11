#pragma once

namespace Engine::Common::Types {

    using ID = int;

    struct Transform {
        Vector Location;
        Vector Size;
        float Angle;
        float Depth;
    };

    struct Color {
        uint8_t R;
        uint8_t G;
        uint8_t B;
        uint8_t A;
    };

    struct Vector {
        float X = 0.f;
        float Y = 0.f;
    };

}