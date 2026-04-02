set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

project(change_me LANGUAGES CXX VERSION 26.03.01)

add_executable(main)
target_sources(main PRIVATE main.cc)
target_compile_features(main PUBLIC cxx_std_23)
target_compile_options(main PUBLIC -Wall -Wextra -Wpedantic)
target_link_libraries(main PRIVATE stdc++exp)
add_executable(week02hello)
target_sources(week02hello PRIVATE week02hello.cc)
target_compile_options(week02hello PUBLIC -std=c++23)
target_link_libraries(week02hello PRIVATE stdc++exp)