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
include src/CMakeFiles/Unit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/Unit.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Unit.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Unit.dir/flags.make

src/CMakeFiles/Unit.dir/BasicUnits.cpp.o: src/CMakeFiles/Unit.dir/flags.make
src/CMakeFiles/Unit.dir/BasicUnits.cpp.o: ../src/BasicUnits.cpp
src/CMakeFiles/Unit.dir/BasicUnits.cpp.o: src/CMakeFiles/Unit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikhail_2012/TP-Game/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Unit.dir/BasicUnits.cpp.o"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Unit.dir/BasicUnits.cpp.o -MF CMakeFiles/Unit.dir/BasicUnits.cpp.o.d -o CMakeFiles/Unit.dir/BasicUnits.cpp.o -c /home/mikhail_2012/TP-Game/game/src/BasicUnits.cpp

src/CMakeFiles/Unit.dir/BasicUnits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Unit.dir/BasicUnits.cpp.i"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail_2012/TP-Game/game/src/BasicUnits.cpp > CMakeFiles/Unit.dir/BasicUnits.cpp.i

src/CMakeFiles/Unit.dir/BasicUnits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Unit.dir/BasicUnits.cpp.s"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail_2012/TP-Game/game/src/BasicUnits.cpp -o CMakeFiles/Unit.dir/BasicUnits.cpp.s

src/CMakeFiles/Unit.dir/Archer.cpp.o: src/CMakeFiles/Unit.dir/flags.make
src/CMakeFiles/Unit.dir/Archer.cpp.o: ../src/Archer.cpp
src/CMakeFiles/Unit.dir/Archer.cpp.o: src/CMakeFiles/Unit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikhail_2012/TP-Game/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/Unit.dir/Archer.cpp.o"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Unit.dir/Archer.cpp.o -MF CMakeFiles/Unit.dir/Archer.cpp.o.d -o CMakeFiles/Unit.dir/Archer.cpp.o -c /home/mikhail_2012/TP-Game/game/src/Archer.cpp

src/CMakeFiles/Unit.dir/Archer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Unit.dir/Archer.cpp.i"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail_2012/TP-Game/game/src/Archer.cpp > CMakeFiles/Unit.dir/Archer.cpp.i

src/CMakeFiles/Unit.dir/Archer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Unit.dir/Archer.cpp.s"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail_2012/TP-Game/game/src/Archer.cpp -o CMakeFiles/Unit.dir/Archer.cpp.s

src/CMakeFiles/Unit.dir/Catapult.cpp.o: src/CMakeFiles/Unit.dir/flags.make
src/CMakeFiles/Unit.dir/Catapult.cpp.o: ../src/Catapult.cpp
src/CMakeFiles/Unit.dir/Catapult.cpp.o: src/CMakeFiles/Unit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikhail_2012/TP-Game/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/Unit.dir/Catapult.cpp.o"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Unit.dir/Catapult.cpp.o -MF CMakeFiles/Unit.dir/Catapult.cpp.o.d -o CMakeFiles/Unit.dir/Catapult.cpp.o -c /home/mikhail_2012/TP-Game/game/src/Catapult.cpp

src/CMakeFiles/Unit.dir/Catapult.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Unit.dir/Catapult.cpp.i"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail_2012/TP-Game/game/src/Catapult.cpp > CMakeFiles/Unit.dir/Catapult.cpp.i

src/CMakeFiles/Unit.dir/Catapult.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Unit.dir/Catapult.cpp.s"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail_2012/TP-Game/game/src/Catapult.cpp -o CMakeFiles/Unit.dir/Catapult.cpp.s

src/CMakeFiles/Unit.dir/Cavalery.cpp.o: src/CMakeFiles/Unit.dir/flags.make
src/CMakeFiles/Unit.dir/Cavalery.cpp.o: ../src/Cavalery.cpp
src/CMakeFiles/Unit.dir/Cavalery.cpp.o: src/CMakeFiles/Unit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikhail_2012/TP-Game/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/Unit.dir/Cavalery.cpp.o"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Unit.dir/Cavalery.cpp.o -MF CMakeFiles/Unit.dir/Cavalery.cpp.o.d -o CMakeFiles/Unit.dir/Cavalery.cpp.o -c /home/mikhail_2012/TP-Game/game/src/Cavalery.cpp

src/CMakeFiles/Unit.dir/Cavalery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Unit.dir/Cavalery.cpp.i"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail_2012/TP-Game/game/src/Cavalery.cpp > CMakeFiles/Unit.dir/Cavalery.cpp.i

src/CMakeFiles/Unit.dir/Cavalery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Unit.dir/Cavalery.cpp.s"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail_2012/TP-Game/game/src/Cavalery.cpp -o CMakeFiles/Unit.dir/Cavalery.cpp.s

src/CMakeFiles/Unit.dir/HorseArcher.cpp.o: src/CMakeFiles/Unit.dir/flags.make
src/CMakeFiles/Unit.dir/HorseArcher.cpp.o: ../src/HorseArcher.cpp
src/CMakeFiles/Unit.dir/HorseArcher.cpp.o: src/CMakeFiles/Unit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikhail_2012/TP-Game/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/Unit.dir/HorseArcher.cpp.o"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Unit.dir/HorseArcher.cpp.o -MF CMakeFiles/Unit.dir/HorseArcher.cpp.o.d -o CMakeFiles/Unit.dir/HorseArcher.cpp.o -c /home/mikhail_2012/TP-Game/game/src/HorseArcher.cpp

src/CMakeFiles/Unit.dir/HorseArcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Unit.dir/HorseArcher.cpp.i"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikhail_2012/TP-Game/game/src/HorseArcher.cpp > CMakeFiles/Unit.dir/HorseArcher.cpp.i

src/CMakeFiles/Unit.dir/HorseArcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Unit.dir/HorseArcher.cpp.s"
	cd /home/mikhail_2012/TP-Game/game/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikhail_2012/TP-Game/game/src/HorseArcher.cpp -o CMakeFiles/Unit.dir/HorseArcher.cpp.s

# Object files for target Unit
Unit_OBJECTS = \
"CMakeFiles/Unit.dir/BasicUnits.cpp.o" \
"CMakeFiles/Unit.dir/Archer.cpp.o" \
"CMakeFiles/Unit.dir/Catapult.cpp.o" \
"CMakeFiles/Unit.dir/Cavalery.cpp.o" \
"CMakeFiles/Unit.dir/HorseArcher.cpp.o"

# External object files for target Unit
Unit_EXTERNAL_OBJECTS =

src/libUnit.so: src/CMakeFiles/Unit.dir/BasicUnits.cpp.o
src/libUnit.so: src/CMakeFiles/Unit.dir/Archer.cpp.o
src/libUnit.so: src/CMakeFiles/Unit.dir/Catapult.cpp.o
src/libUnit.so: src/CMakeFiles/Unit.dir/Cavalery.cpp.o
src/libUnit.so: src/CMakeFiles/Unit.dir/HorseArcher.cpp.o
src/libUnit.so: src/CMakeFiles/Unit.dir/build.make
src/libUnit.so: src/CMakeFiles/Unit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mikhail_2012/TP-Game/game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libUnit.so"
	cd /home/mikhail_2012/TP-Game/game/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Unit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Unit.dir/build: src/libUnit.so
.PHONY : src/CMakeFiles/Unit.dir/build

src/CMakeFiles/Unit.dir/clean:
	cd /home/mikhail_2012/TP-Game/game/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Unit.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Unit.dir/clean

src/CMakeFiles/Unit.dir/depend:
	cd /home/mikhail_2012/TP-Game/game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mikhail_2012/TP-Game/game /home/mikhail_2012/TP-Game/game/src /home/mikhail_2012/TP-Game/game/build /home/mikhail_2012/TP-Game/game/build/src /home/mikhail_2012/TP-Game/game/build/src/CMakeFiles/Unit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Unit.dir/depend

