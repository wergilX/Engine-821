cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME Engine-821)
set(EXECUTABLE_NAME Engine-821)

project(${PROJECT_NAME})

find_package(SDL2 REQUIRED)
include_directories(${EXECUTABLE_NAME} ${SDL2_INCLUDE_DIRS})

add_executable(${EXECUTABLE_NAME} src/main.cpp)

add_subdirectory(src/engine)
add_subdirectory(src/game)

target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARIES})