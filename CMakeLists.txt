cmake_minimum_required(VERSION 3.7)
project(Engine-821)

find_package(SDL2 REQUIRED)
include_directories(engine ${SDL2_INCLUDE_DIRS})

add_executable(engine main.cpp)
target_link_libraries(engine ${SDL2_LIBRARIES})
