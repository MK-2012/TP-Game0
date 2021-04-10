cmake_minimum_required(VERSION 3.6)
project(libraries)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 11)

find_package(Cairo)
include_directories(${CAIRO_INCLUDE_DIRS})
add_library(Unit SHARED Unit.cpp)
add_library(Structure SHARED Structure.cpp)
add_library(GameField SHARED game_field.cpp)
add_library(Graphics SHARED graphics.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)


target_compile_definitions(Graphics PUBLIC IMAGE_DIR="${CMAKE_SOURCE_DIR}/images/")


link_directories(${CAIRO_LIBRARY_DIRS})
target_link_libraries(Graphics ${CAIRO_LIBRARIES})
target_link_libraries(GameField Unit)
target_link_libraries(GameField Structure)
target_link_libraries(Graphics GameField)