# Install script for directory: /home/mikhail_2012/TP-Game0-dev/game/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/share/simplegame")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnit.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnit.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnit.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libUnit.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libUnit.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnit.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnit.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnit.so"
         OLD_RPATH ":::::::::::::::::::::::::"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnit.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructure.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructure.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructure.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libStructure.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libStructure.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructure.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructure.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructure.so"
         OLD_RPATH ":::::::::::::::::::::::::"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructure.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libGameField.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libGameField.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libGameField.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libGameField.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libGameField.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libGameField.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libGameField.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libGameField.so"
         OLD_RPATH "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src:"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libGameField.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libGraphics.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libGraphics.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libGraphics.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libGraphics.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libGraphics.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libGraphics.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libGraphics.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libGraphics.so"
         OLD_RPATH "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src:"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libGraphics.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libCursor.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libCursor.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libCursor.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libCursor.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libCursor.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libCursor.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libCursor.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libCursor.so"
         OLD_RPATH "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src:"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libCursor.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libTreasury.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libTreasury.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libTreasury.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libTreasury.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libTreasury.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libTreasury.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libTreasury.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libTreasury.so"
         OLD_RPATH "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src:"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libTreasury.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libPlayer.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libPlayer.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libPlayer.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libPlayer.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libPlayer.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libPlayer.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libPlayer.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libPlayer.so"
         OLD_RPATH "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src:"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libPlayer.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnitTreasury.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnitTreasury.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnitTreasury.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libUnitTreasury.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libUnitTreasury.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnitTreasury.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnitTreasury.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnitTreasury.so"
         OLD_RPATH ":::::::::::::::::::::::::"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libUnitTreasury.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructureTreasury.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructureTreasury.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructureTreasury.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libStructureTreasury.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libStructureTreasury.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructureTreasury.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructureTreasury.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructureTreasury.so"
         OLD_RPATH ":::::::::::::::::::::::::"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libStructureTreasury.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libRivers.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libRivers.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libRivers.so"
         RPATH "/usr/share/simplegame/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/simplegame/lib/libRivers.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/simplegame/lib" TYPE SHARED_LIBRARY FILES "/home/mikhail_2012/TP-Game0-dev/game/cmake-build-debug/src/libRivers.so")
  if(EXISTS "$ENV{DESTDIR}/usr/share/simplegame/lib/libRivers.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/share/simplegame/lib/libRivers.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/share/simplegame/lib/libRivers.so"
         OLD_RPATH ":::::::::::::::::::::::::"
         NEW_RPATH "/usr/share/simplegame/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/share/simplegame/lib/libRivers.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

