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
CMAKE_SOURCE_DIR = /home/michele/workspace/openCVtutorial/src/enginePrototype

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michele/workspace/openCVtutorial/build/enginePrototype

# Include any dependencies generated for this target.
include CMakeFiles/engLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/engLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engLib.dir/flags.make

CMakeFiles/engLib.dir/RecognitionEngine.cxx.o: CMakeFiles/engLib.dir/flags.make
CMakeFiles/engLib.dir/RecognitionEngine.cxx.o: /home/michele/workspace/openCVtutorial/src/enginePrototype/RecognitionEngine.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/michele/workspace/openCVtutorial/build/enginePrototype/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/engLib.dir/RecognitionEngine.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/engLib.dir/RecognitionEngine.cxx.o -c /home/michele/workspace/openCVtutorial/src/enginePrototype/RecognitionEngine.cxx

CMakeFiles/engLib.dir/RecognitionEngine.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engLib.dir/RecognitionEngine.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/michele/workspace/openCVtutorial/src/enginePrototype/RecognitionEngine.cxx > CMakeFiles/engLib.dir/RecognitionEngine.cxx.i

CMakeFiles/engLib.dir/RecognitionEngine.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engLib.dir/RecognitionEngine.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/michele/workspace/openCVtutorial/src/enginePrototype/RecognitionEngine.cxx -o CMakeFiles/engLib.dir/RecognitionEngine.cxx.s

CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.requires:
.PHONY : CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.requires

CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.provides: CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.requires
	$(MAKE) -f CMakeFiles/engLib.dir/build.make CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.provides.build
.PHONY : CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.provides

CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.provides.build: CMakeFiles/engLib.dir/RecognitionEngine.cxx.o
.PHONY : CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.provides.build

# Object files for target engLib
engLib_OBJECTS = \
"CMakeFiles/engLib.dir/RecognitionEngine.cxx.o"

# External object files for target engLib
engLib_EXTERNAL_OBJECTS =

libengLib.so: CMakeFiles/engLib.dir/RecognitionEngine.cxx.o
libengLib.so: CMakeFiles/engLib.dir/build.make
libengLib.so: CMakeFiles/engLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libengLib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engLib.dir/build: libengLib.so
.PHONY : CMakeFiles/engLib.dir/build

CMakeFiles/engLib.dir/requires: CMakeFiles/engLib.dir/RecognitionEngine.cxx.o.requires
.PHONY : CMakeFiles/engLib.dir/requires

CMakeFiles/engLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engLib.dir/clean

CMakeFiles/engLib.dir/depend:
	cd /home/michele/workspace/openCVtutorial/build/enginePrototype && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michele/workspace/openCVtutorial/src/enginePrototype /home/michele/workspace/openCVtutorial/src/enginePrototype /home/michele/workspace/openCVtutorial/build/enginePrototype /home/michele/workspace/openCVtutorial/build/enginePrototype /home/michele/workspace/openCVtutorial/build/enginePrototype/CMakeFiles/engLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engLib.dir/depend

