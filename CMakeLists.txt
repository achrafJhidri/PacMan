cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME pacman)
project(${PROJECT_NAME})

add_compile_options(-Wall -Wextra -std=c++11 -Wno-unknown-pragmas -g -DSFML_STATIC)
add_compile_options(-lsfml-graphics-s -lsfml-audio-s -lsfml-networks-s)

# SFML
find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-graphics sfml-audio sfml-network)
pkg_check_modules(LIBPNG REQUIRED libpng)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SFML_LINK_LIBRARIES} ${LIBPNG_LINK_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${SFML_CFLAGS_OTHER} ${LIBPNG_CFLAGS_OTHER})
