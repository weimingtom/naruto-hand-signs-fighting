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
include recognitionEngine/CMakeFiles/reTest.dir/depend.make

# Include the progress variables for this target.
include recognitionEngine/CMakeFiles/reTest.dir/progress.make

# Include the compile flags for this target's objects.
include recognitionEngine/CMakeFiles/reTest.dir/flags.make

recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o: recognitionEngine/CMakeFiles/reTest.dir/flags.make
recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o: /home/michele/workspace/NarutoHandSealsFighting/src/recognitionEngine/reTest.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/michele/workspace/NarutoHandSealsFighting/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o"
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/recognitionEngine && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/reTest.dir/reTest.cxx.o -c /home/michele/workspace/NarutoHandSealsFighting/src/recognitionEngine/reTest.cxx

recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reTest.dir/reTest.cxx.i"
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/recognitionEngine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/michele/workspace/NarutoHandSealsFighting/src/recognitionEngine/reTest.cxx > CMakeFiles/reTest.dir/reTest.cxx.i

recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reTest.dir/reTest.cxx.s"
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/recognitionEngine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/michele/workspace/NarutoHandSealsFighting/src/recognitionEngine/reTest.cxx -o CMakeFiles/reTest.dir/reTest.cxx.s

recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.requires:
.PHONY : recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.requires

recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.provides: recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.requires
	$(MAKE) -f recognitionEngine/CMakeFiles/reTest.dir/build.make recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.provides.build
.PHONY : recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.provides

recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.provides.build: recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o
.PHONY : recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.provides.build

# Object files for target reTest
reTest_OBJECTS = \
"CMakeFiles/reTest.dir/reTest.cxx.o"

# External object files for target reTest
reTest_EXTERNAL_OBJECTS =

recognitionEngine/reTest: recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o
recognitionEngine/reTest: /usr/local/lib/libSDLmain.a
recognitionEngine/reTest: /usr/local/lib/libSDL.so
recognitionEngine/reTest: recognitionEngine/librecognitionEngine.so
recognitionEngine/reTest: recognitionEngine/engineModules/libengineModules.so
recognitionEngine/reTest: gameLogic/libgameLogic.so
recognitionEngine/reTest: recognitionEngine/evaluationFunctions/libevaluationFunctions.so
recognitionEngine/reTest: gameLogic/tinyxml/libtinyxml.so
recognitionEngine/reTest: /usr/local/lib/libSDLmain.a
recognitionEngine/reTest: /usr/local/lib/libSDL.so
recognitionEngine/reTest: recognitionEngine/CMakeFiles/reTest.dir/build.make
recognitionEngine/reTest: recognitionEngine/CMakeFiles/reTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable reTest"
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/recognitionEngine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
recognitionEngine/CMakeFiles/reTest.dir/build: recognitionEngine/reTest
.PHONY : recognitionEngine/CMakeFiles/reTest.dir/build

recognitionEngine/CMakeFiles/reTest.dir/requires: recognitionEngine/CMakeFiles/reTest.dir/reTest.cxx.o.requires
.PHONY : recognitionEngine/CMakeFiles/reTest.dir/requires

recognitionEngine/CMakeFiles/reTest.dir/clean:
	cd /home/michele/workspace/NarutoHandSealsFighting/bin/recognitionEngine && $(CMAKE_COMMAND) -P CMakeFiles/reTest.dir/cmake_clean.cmake
.PHONY : recognitionEngine/CMakeFiles/reTest.dir/clean

recognitionEngine/CMakeFiles/reTest.dir/depend:
	cd /home/michele/workspace/NarutoHandSealsFighting/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michele/workspace/NarutoHandSealsFighting/src /home/michele/workspace/NarutoHandSealsFighting/src/recognitionEngine /home/michele/workspace/NarutoHandSealsFighting/bin /home/michele/workspace/NarutoHandSealsFighting/bin/recognitionEngine /home/michele/workspace/NarutoHandSealsFighting/bin/recognitionEngine/CMakeFiles/reTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : recognitionEngine/CMakeFiles/reTest.dir/depend

