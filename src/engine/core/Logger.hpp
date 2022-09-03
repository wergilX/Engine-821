#pragma once

#include <cstdlib>

#include <fmt/format.h>
#include <fmt/ranges.h>
#include <fmt/color.h>
#include <fmt/chrono.h>

#define LOCATION fmt::format("{}:{}:", __FILE__, __LINE__)

#define LOG(...) { fmt::print("{} {}\n", LOCATION, __VA_ARGS__); } 

#define WARNING(...) { fmt::print(fg(fmt::color::yellow),"{} {}\n", LOCATION, __VA_ARGS__ ); } 

#define WARNING_IF(x, ...) \
    if(x) \
    { \
        fmt::print(fg(fmt::color::yellow),"{} {}\n", LOCATION, __VA_ARGS__); \
    } \

#define FATAL(...) \
    { \
        fmt::print(fg(fmt::color::red),"{} {}\n", LOCATION, __VA_ARGS__); \
        std::exit(1); \
    } \

#define ASSERT(x, ...) \
    if(x) \
    { \
        fmt::print(fg(fmt::color::red),"{} {}\n", LOCATION, __VA_ARGS__); \
        std::exit(1); \
    } \

#define ASSERT_FALSE(x, ...) \
    if(!x) \
    { \
        fmt::print(fg(fmt::color::red),"{} {}\n", LOCATION, __VA_ARGS__); \
        std::exit(1); \
    } \

#define ASSERT_NOT_NULL(x, ...) \
    if(x == nullptr) \
    { \
        fmt::print(fg(fmt::color::red),"{} {}\n", LOCATION, __VA_ARGS__); \
        std::exit(1); \
    } \


/*EXAMPLES*/
/* 
***Value***
LOG("Value {}, \n", 5);

***Container***
std::vector<int> v = {1, 2, 3};
LOG("Vector {}, \n", v);

***Color and style***
LOG(fg(fmt::color::steel_blue), "Hello, Color!\n");

LOG(fg(fmt::color::crimson) | fmt::emphasis::bold,
             "Hello, {}!\n", "world");

***Chrono durations***
LOG("Default format: {} {}\n", 42s, 100ms);
LOG("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);
*/