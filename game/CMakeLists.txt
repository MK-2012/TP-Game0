cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

add_subdirectory(src)
find_package(Cairo)
if (${CMAKE_SYSTEM} MATCHES "Linux")
    find_package(GTK3_GTK REQUIRED)
endif()
include_directories(${CAIRO_INCLUDE_DIRS})
include_directories(${GTK_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR})
add_executable(game ${SOURCE_FILES})
target_compile_definitions(game PUBLIC IMAGE_DIR="${CMAKE_SOURCE_DIR}/images/")


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
link_directories(${GTK3_LIBRARY_DIRS})
add_compile_options(${GTK3_CFLAGS_OTHER})

set(FLAGS "-I${GTK3_INCLUDE_DIRS}")
message(STATUS "Flags: ${FLAGS}")
string(REPLACE ";" " -I" FLAGS "${FLAGS}")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GTK3_FLAGS} ${FLAGS})



link_directories(${CAIRO_LIBRARY_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
target_link_libraries(game ${CAIRO_LIBRARIES})
target_link_libraries(game ${GTK3_LIBRARIES})
target_link_libraries(game Graphics)
target_link_libraries(game GameField)
target_link_libraries(game Structure)
target_link_libraries(game Unit)
target_link_libraries(game Cursor)
target_link_libraries(game Player)
install(
        TARGETS game
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
)
message(STATUS ${CAIRO_LIBRARY_DIRS})
message(STATUS ${CAIRO_LIBRARIES})
