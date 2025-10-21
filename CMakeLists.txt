cmake_minimum_required(VERSION 3.10)

project(hexy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

enable_testing()

#set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "include-what-you-use;-stdlib=libc++")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# For Windows: Prevent overriding of /MD by /MT in the debug builds
if (MSVC)
  set(gtest_force_shared_crt ON)
endif()
FetchContent_MakeAvailable(googletest)

find_package(SDL2 REQUIRED)

add_library(hexy_core STATIC src/src/Hex.cpp src/src/HexGrid.cpp)
target_include_directories(hexy_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

add_executable(hexy src/src/main.cpp)

target_link_libraries(hexy PRIVATE SDL2::SDL2 hexy_core)

add_subdirectory(tests)
