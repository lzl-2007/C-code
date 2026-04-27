cmake_minimum_required(VERSION 3.14)
project(buffer_lab CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # 解决intellisense报错的问题

include(cmake/SetupDependencies.cmake)
setup_dependencies()

# 添加src子目录
add_subdirectory(src)

