# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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
CMAKE_COMMAND = /usr/bin/bin/cmake

# The command to remove a file.
RM = /usr/bin/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.p67NHqaNhG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.p67NHqaNhG/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/threadMallocTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/threadMallocTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/threadMallocTest.dir/flags.make

CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.o: CMakeFiles/threadMallocTest.dir/flags.make
CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.o: ../test/threadMallocTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.o -c /tmp/tmp.p67NHqaNhG/test/threadMallocTest.cpp

CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.p67NHqaNhG/test/threadMallocTest.cpp > CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.i

CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.p67NHqaNhG/test/threadMallocTest.cpp -o CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.s

# Object files for target threadMallocTest
threadMallocTest_OBJECTS = \
"CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.o"

# External object files for target threadMallocTest
threadMallocTest_EXTERNAL_OBJECTS =

threadMallocTest: CMakeFiles/threadMallocTest.dir/test/threadMallocTest.cpp.o
threadMallocTest: CMakeFiles/threadMallocTest.dir/build.make
threadMallocTest: CMakeFiles/threadMallocTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable threadMallocTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threadMallocTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/threadMallocTest.dir/build: threadMallocTest

.PHONY : CMakeFiles/threadMallocTest.dir/build

CMakeFiles/threadMallocTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/threadMallocTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/threadMallocTest.dir/clean

CMakeFiles/threadMallocTest.dir/depend:
	cd /tmp/tmp.p67NHqaNhG/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.p67NHqaNhG /tmp/tmp.p67NHqaNhG /tmp/tmp.p67NHqaNhG/cmake-build-debug /tmp/tmp.p67NHqaNhG/cmake-build-debug /tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles/threadMallocTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/threadMallocTest.dir/depend

