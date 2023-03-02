cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
  hello_test
  hello_test.cpp
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)
message("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include(GoogleTest)
gtest_discover_tests(hello_test)