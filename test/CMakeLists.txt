cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
  heap_test 
  heap_test.cpp
)

target_include_directories(
  heap_test PRIVATE
  "../src"
)

target_link_libraries(
  heap_test
  GTest::gtest_main
)

message("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include(GoogleTest)
gtest_discover_tests(heap_test)