cmake_minimum_required(VERSION 3.6)
project(game)


set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
        set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
        set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
        set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX "/usr/share/simplegame")
set(SOURCE_FILES main.cpp)


set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

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
target_compile_definitions(game PUBLIC IMAGE_DIR="../images/")


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
link_directories(${GTK3_LIBRARY_DIRS})
add_compile_options(${GTK3_CFLAGS_OTHER})

set(RESOURCE_DIR)
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
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
install(DIRECTORY "${CMAKE_SOURCE_DIR}/images" 
	DESTINATION "${CMAKE_INSTALL_PREFIX}"
)
install(PROGRAMS "${CMAKE_SOURCE_DIR}/simplegame"
	DESTINATION "/usr/games"
)
