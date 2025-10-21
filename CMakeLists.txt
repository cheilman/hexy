cmake_minimum_required(VERSION 3.10)

project(hexy)

#set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "include-what-you-use;-stdlib=libc++")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

find_package(SDL2 REQUIRED)

add_executable(hexy src/src/main.cpp)

target_link_libraries(hexy PRIVATE SDL2::SDL2)
