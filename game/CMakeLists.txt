cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp game_field.h graphics.h Unit.h Structure.h)


find_package(Cairo)
include_directories(${CAIRO_INCLUDE_DIRS})
add_executable(game ${SOURCE_FILES})

link_directories(${CAIRO_LIBRARY_DIRS})
target_link_libraries(game ${CAIRO_LIBRARIES})
install(
        TARGETS game
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
)
message(STATUS ${CAIRO_LIBRARY_DIRS})
message(STATUS ${CAIRO_LIBRARIES})
