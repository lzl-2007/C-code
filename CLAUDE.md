# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Common Commands

- **Build entire project**:
  ```bash
  mkdir -p build && cd build && cmake .. && make
  ```

- **Build and run a specific exercise** (e.g., week01/part1):
  ```bash
  # From repository root
  mkdir -p build && cd build
  cmake ..
  make -C week01/part1
  ../week01/part1/hello
  ```

- **Build with verbose output** (for debugging):
  ```bash
  cmake --build build --target hello --verbose
  ```

- **Clean build artifacts**:
  ```bash
  rm -rf build
  ```

## Code Architecture

The repository is structured as a series of C++ programming exercises organized by week:

- **Weekly organization**:
  - Top-level directories (`week01/`, `week02/`, etc.) contain weekly assignments
  - Each week has subdirectories for individual exercises (e.g., `week01/part1/`, `week02/ex01/`)

- **Build system**:
  - Hierarchical CMake configuration starting from root `CMakeLists.txt`
  - Root CMake file aggregates all weekly exercises via `add_subdirectory`
  - Each exercise has its own `CMakeLists.txt` defining:
    - Executable targets (e.g., `hello`, `main`, `week02hello`)
    - C++ standard version (C++20 in week01, C++23 in week02)
    - Compiler flags (e.g., `-Wall -Wextra -Wpedantic` in week02)
    - Linker dependencies (e.g., `stdc++exp` for experimental C++23 features)

- **Output handling**:
  - Executables are placed in source directories via `EXECUTABLE_OUTPUT_PATH`
  - Build artifacts are generated in the `build/` directory
  - Example: `week01/part1/hello` executable is built to `week01/part1/` directory

## Development Notes

- **C++ Standards**:
  - Week 01 uses C++20 (`-std=c++20`)
  - Week 02+ uses C++23 (`-std=c++23` or `cxx_std_23`)

- **Compiler Warnings**:
  - Week 02+ enables strict warning flags (`-Wall -Wextra -Wpedantic`)
  - Address warnings during development as they indicate potential issues

- **Experimental Features**:
  - Some exercises link against `stdc++exp` for experimental C++23 features
  - Ensure your toolchain supports these features when working on later weeks