# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michele/workspace/NarutoHandSealsFighting/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michele/workspace/NarutoHandSealsFighting/bin

# Include any dependencies generated for this target.
include gameStack/CMakeFiles/gameStackTest.dir/depend.make

# Include the progress variables for this target.
include gameStack/CMakeFiles/gameStackTest.dir/progress.make

# Include the compile flags for this target's objects.
include gameStack/CMakeFiles/gameStackTest.dir/flags.make

gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o: gameStack/CMakeFiles/gameStackTest.dir/flags.make
gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o: /home/michele/workspace/NarutoHandSealsFighting/src/gameStack/gameStackTest.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/michele/workspace/NarutoHandSealsFighting/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o"
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/gameStack && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o -c /home/michele/workspace/NarutoHandSealsFighting/src/gameStack/gameStackTest.cxx

gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameStackTest.dir/gameStackTest.cxx.i"
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/gameStack && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/michele/workspace/NarutoHandSealsFighting/src/gameStack/gameStackTest.cxx > CMakeFiles/gameStackTest.dir/gameStackTest.cxx.i

gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameStackTest.dir/gameStackTest.cxx.s"
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/gameStack && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/michele/workspace/NarutoHandSealsFighting/src/gameStack/gameStackTest.cxx -o CMakeFiles/gameStackTest.dir/gameStackTest.cxx.s

gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.requires:
.PHONY : gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.requires

gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.provides: gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.requires
	$(MAKE) -f gameStack/CMakeFiles/gameStackTest.dir/build.make gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.provides.build
.PHONY : gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.provides

gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.provides.build: gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o
.PHONY : gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.provides.build

# Object files for target gameStackTest
gameStackTest_OBJECTS = \
"CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o"

# External object files for target gameStackTest
gameStackTest_EXTERNAL_OBJECTS =

gameStack/gameStackTest: gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o
gameStack/gameStackTest: /usr/local/lib/libSDLmain.a
gameStack/gameStackTest: /usr/local/lib/libSDL.so
gameStack/gameStackTest: gameStack/libgameStack.so
gameStack/gameStackTest: gameStack/menu/libmenuLib.so
gameStack/gameStackTest: gameStack/controller/libcontrollerLib.so
gameStack/gameStackTest: /usr/local/lib/libSDLmain.a
gameStack/gameStackTest: /usr/local/lib/libSDL.so
gameStack/gameStackTest: gameStack/CMakeFiles/gameStackTest.dir/build.make
gameStack/gameStackTest: gameStack/CMakeFiles/gameStackTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable gameStackTest"
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/gameStack && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameStackTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gameStack/CMakeFiles/gameStackTest.dir/build: gameStack/gameStackTest
.PHONY : gameStack/CMakeFiles/gameStackTest.dir/build

gameStack/CMakeFiles/gameStackTest.dir/requires: gameStack/CMakeFiles/gameStackTest.dir/gameStackTest.cxx.o.requires
.PHONY : gameStack/CMakeFiles/gameStackTest.dir/requires

gameStack/CMakeFiles/gameStackTest.dir/clean:
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/gameStack && $(CMAKE_COMMAND) -P CMakeFiles/gameStackTest.dir/cmake_clean.cmake
.PHONY : gameStack/CMakeFiles/gameStackTest.dir/clean

gameStack/CMakeFiles/gameStackTest.dir/depend:
	cd /home/michele/workspace/NarutoHandSealsFighting/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michele/workspace/NarutoHandSealsFighting/src /home/michele/workspace/NarutoHandSealsFighting/src/gameStack /home/michele/workspace/NarutoHandSealsFighting/bin /home/michele/workspace/NarutoHandSealsFighting/bin/gameStack /home/michele/workspace/NarutoHandSealsFighting/bin/gameStack/CMakeFiles/gameStackTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gameStack/CMakeFiles/gameStackTest.dir/depend

