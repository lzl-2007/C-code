cmake_minimum_required(VERSION 3.14)

project(lab4 CXX)
# 阶段1测试程序
add_executable(test_stage1 test_stage1.cc)

# 阶段2测试程序
add_executable(test_stage2 test_stage2.cc)

# Benchmark程序（对比两个阶段）
add_executable(bench_compare bench_compare.cc)
target_link_libraries(bench_compare benchmark::benchmark)


# 打印构建信息
message(STATUS "Build targets:")
message(STATUS "  test_stage1    - Test BadBuffer problems and GoodBuffer fixes")
message(STATUS "  test_stage2    - Test move semantics functionality")
message(STATUS "  bench_compare  - Compare performance between Stage 1 and Stage 2")
