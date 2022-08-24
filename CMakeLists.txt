cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_NAME Engine-821)
set(EXECUTABLE_NAME engine-821)
set(FMT_DIR ${CMAKE_SOURCE_DIR}/libraries/fmt)

project(${PROJECT_NAME} VERSION 0.1)

find_package(SDL2 REQUIRED)
add_executable(${EXECUTABLE_NAME} src/main.cpp)

target_include_directories(
    ${EXECUTABLE_NAME} 
    PRIVATE ${SDL2_INCLUDE_DIRS} 
            ${FMT_DIR}/include
    )

target_link_libraries(
    ${EXECUTABLE_NAME} 
    PRIVATE ${SDL2_LIBRARIES} 
            ${FMT_DIR}/libfmt.a
    )

add_subdirectory(src/engine)
add_subdirectory(src/game)