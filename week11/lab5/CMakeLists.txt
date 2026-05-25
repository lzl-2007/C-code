cmake_minimum_required(VERSION 3.14)

project(node_lab CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # 解决intellisense报错的问题


add_executable(node node.cc)add_executable(node1 node1.cc)
