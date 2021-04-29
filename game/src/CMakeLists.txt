cmake_minimum_required(VERSION 3.6)
project(libraries)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)


include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(Cairo REQUIRED)
include_directories(${CAIRO_INCLUDE_DIRS})
include_directories(${GTK_INCLUDE_DIR})
add_library(Unit SHARED BasicUnits.cpp Archer.cpp Catapult.cpp Cavalery.cpp HorseArcher.cpp)
add_library(Structure SHARED Structure.cpp)
add_library(GameField SHARED game_field.cpp)
add_library(Graphics SHARED graphics.cpp)
add_library(Cursor SHARED Cursor.cpp PlayerEnum.cpp)
add_library(Treasury SHARED Treasury.cpp)
add_library(Player SHARED Player.cpp)
add_library(UnitTreasury SHARED UnitTreasury.cpp)
add_library(StructureTreasury SHARED StructureTreasury.cpp)
add_library(Rivers SHARED Rivers.cpp)


target_compile_definitions(Graphics PUBLIC IMAGE_DIR="${CMAKE_SOURCE_DIR}/images/")


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
target_link_libraries(Graphics ${CAIRO_LIBRARIES})
target_link_libraries(Graphics ${GTK3_LIBRARIES})
target_link_libraries(GameField Unit)
target_link_libraries(GameField Structure)
target_link_libraries(GameField Rivers)
target_link_libraries(Graphics GameField)
target_link_libraries(Cursor Unit)
target_link_libraries(Cursor Structure)
target_link_libraries(Cursor GameField)
target_link_libraries(Treasury Unit)
target_link_libraries(Treasury Structure)
target_link_libraries(Player Cursor)
target_link_libraries(Player Treasury)
target_link_libraries(Cursor StructureTreasury)
target_link_libraries(Cursor UnitTreasury)
target_link_libraries(Treasury UnitTreasury)
target_link_libraries(Treasury StructureTreasury)
