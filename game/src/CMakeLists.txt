cmake_minimum_required(VERSION 3.6)
project(libraries)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 11)


include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(Cairo)
include_directories(${CAIRO_INCLUDE_DIRS})
add_library(Unit SHARED BasicUnits.cpp Archer.cpp Catapult.cpp Cavalery.cpp HorseArcher.cpp)
add_library(Structure SHARED Structure.cpp)
add_library(GameField SHARED game_field.cpp)
add_library(Graphics SHARED graphics.cpp)
add_library(Cursor SHARED Cursor.cpp PlayerEnum.cpp)
add_library(Treasury SHARED Treasury.cpp)
add_library(Player SHARED Player.cpp)
add_library(UnitTreasury SHARED UnitTreasury.cpp)
add_library(StructureTreasury SHARED StructureTreasury.cpp)


target_compile_definitions(Graphics PUBLIC IMAGE_DIR="${CMAKE_SOURCE_DIR}/images/")


link_directories(${CAIRO_LIBRARY_DIRS})
target_link_libraries(Graphics ${CAIRO_LIBRARIES})
target_link_libraries(GameField Unit)
target_link_libraries(GameField Structure)
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