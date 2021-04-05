cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp game_field.h graphics.h Unit.h Structure.h CursorImages.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)



find_package(Cairo)
include_directories(${CAIRO_INCLUDE_DIRS})
add_executable(game ${SOURCE_FILES})

target_compile_definitions(game PUBLIC IMAGE_DIR="${CMAKE_SOURCE_DIR}/images/")


link_directories(${CAIRO_LIBRARY_DIRS})
target_link_libraries(game ${CAIRO_LIBRARIES})

 
message(STATUS ${CMAKE_INSTALL_PREFIX})
if("${CMAKE_INSTALL_PREFIX}" STREQUAL "") 

else()
install(TARGETS game
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
install(DIRECTORY images
	DESTINATION ${CMAKE_INSTALL_PREFIX}
)
endif()

message(STATUS ${CAIRO_LIBRARY_DIRS})
message(STATUS ${CAIRO_LIBRARIES})
