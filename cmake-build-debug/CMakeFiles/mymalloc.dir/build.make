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
include CMakeFiles/mymalloc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mymalloc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mymalloc.dir/flags.make

CMakeFiles/mymalloc.dir/main.cpp.o: CMakeFiles/mymalloc.dir/flags.make
CMakeFiles/mymalloc.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mymalloc.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymalloc.dir/main.cpp.o -c /tmp/tmp.p67NHqaNhG/main.cpp

CMakeFiles/mymalloc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymalloc.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.p67NHqaNhG/main.cpp > CMakeFiles/mymalloc.dir/main.cpp.i

CMakeFiles/mymalloc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymalloc.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.p67NHqaNhG/main.cpp -o CMakeFiles/mymalloc.dir/main.cpp.s

CMakeFiles/mymalloc.dir/mymalloc.cpp.o: CMakeFiles/mymalloc.dir/flags.make
CMakeFiles/mymalloc.dir/mymalloc.cpp.o: ../mymalloc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mymalloc.dir/mymalloc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymalloc.dir/mymalloc.cpp.o -c /tmp/tmp.p67NHqaNhG/mymalloc.cpp

CMakeFiles/mymalloc.dir/mymalloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymalloc.dir/mymalloc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.p67NHqaNhG/mymalloc.cpp > CMakeFiles/mymalloc.dir/mymalloc.cpp.i

CMakeFiles/mymalloc.dir/mymalloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymalloc.dir/mymalloc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.p67NHqaNhG/mymalloc.cpp -o CMakeFiles/mymalloc.dir/mymalloc.cpp.s

CMakeFiles/mymalloc.dir/span.cpp.o: CMakeFiles/mymalloc.dir/flags.make
CMakeFiles/mymalloc.dir/span.cpp.o: ../span.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mymalloc.dir/span.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymalloc.dir/span.cpp.o -c /tmp/tmp.p67NHqaNhG/span.cpp

CMakeFiles/mymalloc.dir/span.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymalloc.dir/span.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.p67NHqaNhG/span.cpp > CMakeFiles/mymalloc.dir/span.cpp.i

CMakeFiles/mymalloc.dir/span.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymalloc.dir/span.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.p67NHqaNhG/span.cpp -o CMakeFiles/mymalloc.dir/span.cpp.s

CMakeFiles/mymalloc.dir/central.cpp.o: CMakeFiles/mymalloc.dir/flags.make
CMakeFiles/mymalloc.dir/central.cpp.o: ../central.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mymalloc.dir/central.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymalloc.dir/central.cpp.o -c /tmp/tmp.p67NHqaNhG/central.cpp

CMakeFiles/mymalloc.dir/central.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymalloc.dir/central.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.p67NHqaNhG/central.cpp > CMakeFiles/mymalloc.dir/central.cpp.i

CMakeFiles/mymalloc.dir/central.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymalloc.dir/central.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.p67NHqaNhG/central.cpp -o CMakeFiles/mymalloc.dir/central.cpp.s

# Object files for target mymalloc
mymalloc_OBJECTS = \
"CMakeFiles/mymalloc.dir/main.cpp.o" \
"CMakeFiles/mymalloc.dir/mymalloc.cpp.o" \
"CMakeFiles/mymalloc.dir/span.cpp.o" \
"CMakeFiles/mymalloc.dir/central.cpp.o"

# External object files for target mymalloc
mymalloc_EXTERNAL_OBJECTS =

mymalloc: CMakeFiles/mymalloc.dir/main.cpp.o
mymalloc: CMakeFiles/mymalloc.dir/mymalloc.cpp.o
mymalloc: CMakeFiles/mymalloc.dir/span.cpp.o
mymalloc: CMakeFiles/mymalloc.dir/central.cpp.o
mymalloc: CMakeFiles/mymalloc.dir/build.make
mymalloc: CMakeFiles/mymalloc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable mymalloc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mymalloc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mymalloc.dir/build: mymalloc

.PHONY : CMakeFiles/mymalloc.dir/build

CMakeFiles/mymalloc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mymalloc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mymalloc.dir/clean

CMakeFiles/mymalloc.dir/depend:
	cd /tmp/tmp.p67NHqaNhG/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.p67NHqaNhG /tmp/tmp.p67NHqaNhG /tmp/tmp.p67NHqaNhG/cmake-build-debug /tmp/tmp.p67NHqaNhG/cmake-build-debug /tmp/tmp.p67NHqaNhG/cmake-build-debug/CMakeFiles/mymalloc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mymalloc.dir/depend

