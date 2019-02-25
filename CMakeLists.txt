cmake_minimum_required(VERSION 3.1)
set(EXECUTABLE_NAME pacman)

# set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
# set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
add_compile_options(-Wall -Wextra -std=c++11 -g)
# add_compile_options(-I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1)

project(${EXECUTABLE_NAME})

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

# target_include_directories(${EXECUTABLE_NAME} SYSTEM PRIVATE $ENV{INCLUDE})
