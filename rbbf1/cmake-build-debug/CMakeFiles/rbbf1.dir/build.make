# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/cesar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/163.13906.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/cesar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/163.13906.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cesar/SISAP/src/indexes/rbbf1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cesar/SISAP/src/indexes/rbbf1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rbbf1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rbbf1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rbbf1.dir/flags.make

CMakeFiles/rbbf1.dir/rbbf1.c.o: CMakeFiles/rbbf1.dir/flags.make
CMakeFiles/rbbf1.dir/rbbf1.c.o: ../rbbf1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cesar/SISAP/src/indexes/rbbf1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rbbf1.dir/rbbf1.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rbbf1.dir/rbbf1.c.o   -c /home/cesar/SISAP/src/indexes/rbbf1/rbbf1.c

CMakeFiles/rbbf1.dir/rbbf1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rbbf1.dir/rbbf1.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cesar/SISAP/src/indexes/rbbf1/rbbf1.c > CMakeFiles/rbbf1.dir/rbbf1.c.i

CMakeFiles/rbbf1.dir/rbbf1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rbbf1.dir/rbbf1.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cesar/SISAP/src/indexes/rbbf1/rbbf1.c -o CMakeFiles/rbbf1.dir/rbbf1.c.s

CMakeFiles/rbbf1.dir/rbbf1.c.o.requires:

.PHONY : CMakeFiles/rbbf1.dir/rbbf1.c.o.requires

CMakeFiles/rbbf1.dir/rbbf1.c.o.provides: CMakeFiles/rbbf1.dir/rbbf1.c.o.requires
	$(MAKE) -f CMakeFiles/rbbf1.dir/build.make CMakeFiles/rbbf1.dir/rbbf1.c.o.provides.build
.PHONY : CMakeFiles/rbbf1.dir/rbbf1.c.o.provides

CMakeFiles/rbbf1.dir/rbbf1.c.o.provides.build: CMakeFiles/rbbf1.dir/rbbf1.c.o


# Object files for target rbbf1
rbbf1_OBJECTS = \
"CMakeFiles/rbbf1.dir/rbbf1.c.o"

# External object files for target rbbf1
rbbf1_EXTERNAL_OBJECTS =

rbbf1: CMakeFiles/rbbf1.dir/rbbf1.c.o
rbbf1: CMakeFiles/rbbf1.dir/build.make
rbbf1: CMakeFiles/rbbf1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cesar/SISAP/src/indexes/rbbf1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rbbf1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rbbf1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rbbf1.dir/build: rbbf1

.PHONY : CMakeFiles/rbbf1.dir/build

CMakeFiles/rbbf1.dir/requires: CMakeFiles/rbbf1.dir/rbbf1.c.o.requires

.PHONY : CMakeFiles/rbbf1.dir/requires

CMakeFiles/rbbf1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rbbf1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rbbf1.dir/clean

CMakeFiles/rbbf1.dir/depend:
	cd /home/cesar/SISAP/src/indexes/rbbf1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cesar/SISAP/src/indexes/rbbf1 /home/cesar/SISAP/src/indexes/rbbf1 /home/cesar/SISAP/src/indexes/rbbf1/cmake-build-debug /home/cesar/SISAP/src/indexes/rbbf1/cmake-build-debug /home/cesar/SISAP/src/indexes/rbbf1/cmake-build-debug/CMakeFiles/rbbf1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rbbf1.dir/depend

