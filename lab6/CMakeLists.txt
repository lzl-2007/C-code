cmake_minimum_required(VERSION 3.22)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

project(lab6)

# add gtest lib for testing
enable_testing()

# use fechContent to download gtest
include(cmake/SetupDependencies.cmake)
setup_dependencies()

add_executable(vec_test vec_test.cpp)
target_link_libraries(vec_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
