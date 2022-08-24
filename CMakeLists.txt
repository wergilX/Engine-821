cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_NAME Engine-821)
set(EXECUTABLE_NAME engine-821)

set(FMT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libraries/fmt/include)
set(SDL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libraries/sdl2/include)

project(${PROJECT_NAME} VERSION 0.1)

add_executable(${EXECUTABLE_NAME} src/main.cpp)

include_directories(${EXECUTABLE_NAME} ${FMT_INCLUDE_DIR})
include_directories(${EXECUTABLE_NAME} ${SDL_INCLUDE_DIR})

target_link_libraries(
    ${EXECUTABLE_NAME}
    $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/libraries/sdl2/lib/debug/SDL2.lib>
    $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}/libraries/sdl2/lib/release/SDL2.lib>
)

target_link_libraries(
    ${EXECUTABLE_NAME}
    $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/libraries/fmt/lib/debug/fmt.lib>
    $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}/libraries/fmt/lib/release/fmt.lib>
)

add_subdirectory(src/engine)
add_subdirectory(src/game)

if (WIN32)
    message(" +---------- WINDOWS OS ----------+ ")
endif(WIN32)