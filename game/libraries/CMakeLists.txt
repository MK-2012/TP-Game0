cmake_minimum_required(VERSION 2.8)

project(libraries)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)



#add_subdirectory(SU)
add_library(game_field SHARED game_field.cpp)