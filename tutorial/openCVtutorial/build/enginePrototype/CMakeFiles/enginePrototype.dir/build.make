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
include CMakeFiles/enginePrototype.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/enginePrototype.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/enginePrototype.dir/flags.make

CMakeFiles/enginePrototype.dir/mainEngine.cxx.o: CMakeFiles/enginePrototype.dir/flags.make
CMakeFiles/enginePrototype.dir/mainEngine.cxx.o: /home/michele/workspace/openCVtutorial/src/enginePrototype/mainEngine.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/michele/workspace/openCVtutorial/build/enginePrototype/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/enginePrototype.dir/mainEngine.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/enginePrototype.dir/mainEngine.cxx.o -c /home/michele/workspace/openCVtutorial/src/enginePrototype/mainEngine.cxx

CMakeFiles/enginePrototype.dir/mainEngine.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/enginePrototype.dir/mainEngine.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/michele/workspace/openCVtutorial/src/enginePrototype/mainEngine.cxx > CMakeFiles/enginePrototype.dir/mainEngine.cxx.i

CMakeFiles/enginePrototype.dir/mainEngine.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/enginePrototype.dir/mainEngine.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/michele/workspace/openCVtutorial/src/enginePrototype/mainEngine.cxx -o CMakeFiles/enginePrototype.dir/mainEngine.cxx.s

CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.requires:
.PHONY : CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.requires

CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.provides: CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.requires
	$(MAKE) -f CMakeFiles/enginePrototype.dir/build.make CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.provides.build
.PHONY : CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.provides

CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.provides.build: CMakeFiles/enginePrototype.dir/mainEngine.cxx.o
.PHONY : CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.provides.build

# Object files for target enginePrototype
enginePrototype_OBJECTS = \
"CMakeFiles/enginePrototype.dir/mainEngine.cxx.o"

# External object files for target enginePrototype
enginePrototype_EXTERNAL_OBJECTS =

enginePrototype: CMakeFiles/enginePrototype.dir/mainEngine.cxx.o
enginePrototype: libengLib.so
enginePrototype: libsobel.so
enginePrototype: CMakeFiles/enginePrototype.dir/build.make
enginePrototype: CMakeFiles/enginePrototype.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable enginePrototype"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/enginePrototype.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/enginePrototype.dir/build: enginePrototype
.PHONY : CMakeFiles/enginePrototype.dir/build

CMakeFiles/enginePrototype.dir/requires: CMakeFiles/enginePrototype.dir/mainEngine.cxx.o.requires
.PHONY : CMakeFiles/enginePrototype.dir/requires

CMakeFiles/enginePrototype.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/enginePrototype.dir/cmake_clean.cmake
.PHONY : CMakeFiles/enginePrototype.dir/clean

CMakeFiles/enginePrototype.dir/depend:
	cd /home/michele/workspace/openCVtutorial/build/enginePrototype && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michele/workspace/openCVtutorial/src/enginePrototype /home/michele/workspace/openCVtutorial/src/enginePrototype /home/michele/workspace/openCVtutorial/build/enginePrototype /home/michele/workspace/openCVtutorial/build/enginePrototype /home/michele/workspace/openCVtutorial/build/enginePrototype/CMakeFiles/enginePrototype.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/enginePrototype.dir/depend

