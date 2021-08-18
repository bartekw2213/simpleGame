cmake_minimum_required(VERSION 3.0)

project(SimpleGame)

enable_testing()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(GTest REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS} include)

add_subdirectory(src)
add_subdirectory(test)