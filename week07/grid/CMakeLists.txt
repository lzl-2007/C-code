cmake_minimum_required(VERSION 3.28)

project(ackermann LANGUAGES CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})

add_executable(grid grid.cc grid_main.cc)
target_compile_options(grid PRIVATE -std=c++23)
