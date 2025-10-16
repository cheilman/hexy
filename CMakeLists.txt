cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

#set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "include-what-you-use;-stdlib=libc++")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

add_executable(hello_world src/src/main.cpp)
