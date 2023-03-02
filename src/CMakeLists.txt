cmake_minimum_required(VERSION 3.20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message("${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(main main.cpp)