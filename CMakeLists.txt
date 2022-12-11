cmake_minimum_required(VERSION 3.7)
project(Engine-821 VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_NAME engine-821)

add_executable(${EXECUTABLE_NAME} src/Main.cpp src/engine/IRenderer.hpp src/engine/core/Renderer.cpp src/engine/core/Renderer.hpp src/engine/Renderer.hpp src/engine/common/Circle.hpp src/engine/common/Types.hpp)

include_directories(${EXECUTABLE_NAME} PUBLIC src/engine/core)

target_include_directories(
        ${EXECUTABLE_NAME} 
            PUBLIC external/sdl/include
            PUBLIC external/fmt/include
    )

target_link_libraries(
       ${EXECUTABLE_NAME} 
            PRIVATE ${PROJECT_SOURCE_DIR}/external/sdl/build/libSDL2.a
            PRIVATE ${PROJECT_SOURCE_DIR}/external/fmt/build/libfmt.a
   )

add_subdirectory(src/engine)
add_subdirectory(src/game)