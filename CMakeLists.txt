cmake_minimum_required(VERSION 3.1)


# Project
set(PROJECT_NAME pacman)
project(${PROJECT_NAME})

add_compile_options(-Wall -Wextra)
add_compile_options(-std=c++11)
add_compile_options(-Wno-unknown-pragmas)
add_compile_options(-g)


# Where to find sources
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)


# To do before linking
add_executable(${PROJECT_NAME} ${SOURCES})

# Dependencies
find_package(OpenAL REQUIRED)
find_package(SFML 2 REQUIRED COMPONENTS audio graphics)
if(${SFML_FOUND})
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-graphics)
endif()
find_package(PNG REQUIRED)

