
# set generated code to directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# set target name to hello.exe[out], using *.cpp source file
add_executable(hello hello.cpp)

# set c++ standard for c++20: avaliable c++11,c++14,c++17,c++20,c++23
target_compile_options(hello PRIVATE -std=c++20)