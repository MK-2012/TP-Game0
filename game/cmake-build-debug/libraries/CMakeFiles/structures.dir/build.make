# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/val-de-mar/CLionProjects/tp_game/game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug

# Include any dependencies generated for this target.
include libraries/CMakeFiles/structures.dir/depend.make

# Include the progress variables for this target.
include libraries/CMakeFiles/structures.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/CMakeFiles/structures.dir/flags.make

libraries/CMakeFiles/structures.dir/Structure.cpp.o: libraries/CMakeFiles/structures.dir/flags.make
libraries/CMakeFiles/structures.dir/Structure.cpp.o: ../libraries/Structure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libraries/CMakeFiles/structures.dir/Structure.cpp.o"
	cd /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/libraries && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/structures.dir/Structure.cpp.o -c /home/val-de-mar/CLionProjects/tp_game/game/libraries/Structure.cpp

libraries/CMakeFiles/structures.dir/Structure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/structures.dir/Structure.cpp.i"
	cd /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/libraries && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/val-de-mar/CLionProjects/tp_game/game/libraries/Structure.cpp > CMakeFiles/structures.dir/Structure.cpp.i

libraries/CMakeFiles/structures.dir/Structure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/structures.dir/Structure.cpp.s"
	cd /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/libraries && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/val-de-mar/CLionProjects/tp_game/game/libraries/Structure.cpp -o CMakeFiles/structures.dir/Structure.cpp.s

# Object files for target structures
structures_OBJECTS = \
"CMakeFiles/structures.dir/Structure.cpp.o"

# External object files for target structures
structures_EXTERNAL_OBJECTS =

../lib/libstructures.so: libraries/CMakeFiles/structures.dir/Structure.cpp.o
../lib/libstructures.so: libraries/CMakeFiles/structures.dir/build.make
../lib/libstructures.so: libraries/CMakeFiles/structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libstructures.so"
	cd /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/libraries && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/structures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/CMakeFiles/structures.dir/build: ../lib/libstructures.so

.PHONY : libraries/CMakeFiles/structures.dir/build

libraries/CMakeFiles/structures.dir/clean:
	cd /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/libraries && $(CMAKE_COMMAND) -P CMakeFiles/structures.dir/cmake_clean.cmake
.PHONY : libraries/CMakeFiles/structures.dir/clean

libraries/CMakeFiles/structures.dir/depend:
	cd /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/val-de-mar/CLionProjects/tp_game/game /home/val-de-mar/CLionProjects/tp_game/game/libraries /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/libraries /home/val-de-mar/CLionProjects/tp_game/game/cmake-build-debug/libraries/CMakeFiles/structures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libraries/CMakeFiles/structures.dir/depend
