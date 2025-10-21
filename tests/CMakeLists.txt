cmake_minimum_required(VERSION 3.10)

project(hexy_tests)

add_executable(hexy_tests HexGridTest.cpp)

target_link_libraries(hexy_tests PRIVATE
  GTest::gtest_main
  GTest::gtest
  hexy_core
)

target_include_directories(hexy_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/include)

include(GoogleTest)
gtest_discover_tests(hexy_tests)