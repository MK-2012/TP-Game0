# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mikhail_2012/TP-Game/game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mikhail_2012/TP-Game/game/build

# Include any dependencies generated for this target.
include src/CMakeFiles/UnitTreasury.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/UnitTreasury.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/UnitTreasury.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/UnitTreasury.dir/flags.make

src/CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o: src/CMakeFiles/UnitTreasury.dir/flags.make
src/CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o: ../src/UnitTreasury.cpp
src/CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o: src/CMakeFiles/UnitTreasury.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikhail_2012/TP-Game/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o -MF CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o.d -o CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o -c /home/mikhail_2012/TP-Game/game/src/UnitTreasury.cpp

src/CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.i"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail_2012/TP-Game/game/src/UnitTreasury.cpp > CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.i

src/CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.s"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail_2012/TP-Game/game/src/UnitTreasury.cpp -o CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.s

# Object files for target UnitTreasury
UnitTreasury_OBJECTS = \
"CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o"

# External object files for target UnitTreasury
UnitTreasury_EXTERNAL_OBJECTS =

src/libUnitTreasury.so: src/CMakeFiles/UnitTreasury.dir/UnitTreasury.cpp.o
src/libUnitTreasury.so: src/CMakeFiles/UnitTreasury.dir/build.make
src/libUnitTreasury.so: src/CMakeFiles/UnitTreasury.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mikhail_2012/TP-Game/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libUnitTreasury.so"
	cd /home/mikhail_2012/TP-Game/game/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnitTreasury.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/UnitTreasury.dir/build: src/libUnitTreasury.so
.PHONY : src/CMakeFiles/UnitTreasury.dir/build

src/CMakeFiles/UnitTreasury.dir/clean:
	cd /home/mikhail_2012/TP-Game/game/build/src && $(CMAKE_COMMAND) -P CMakeFiles/UnitTreasury.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/UnitTreasury.dir/clean

src/CMakeFiles/UnitTreasury.dir/depend:
	cd /home/mikhail_2012/TP-Game/game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mikhail_2012/TP-Game/game /home/mikhail_2012/TP-Game/game/src /home/mikhail_2012/TP-Game/game/build /home/mikhail_2012/TP-Game/game/build/src /home/mikhail_2012/TP-Game/game/build/src/CMakeFiles/UnitTreasury.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/UnitTreasury.dir/depend

