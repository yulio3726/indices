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
CMAKE_COMMAND = /home/cesar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/163.10154.43/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/cesar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/163.10154.43/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cesar/SISAP/src/indexes/ghs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cesar/SISAP/src/indexes/ghs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ghs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ghs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ghs.dir/flags.make

CMakeFiles/ghs.dir/ghs.c.o: CMakeFiles/ghs.dir/flags.make
CMakeFiles/ghs.dir/ghs.c.o: ../ghs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cesar/SISAP/src/indexes/ghs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ghs.dir/ghs.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ghs.dir/ghs.c.o   -c /home/cesar/SISAP/src/indexes/ghs/ghs.c

CMakeFiles/ghs.dir/ghs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ghs.dir/ghs.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cesar/SISAP/src/indexes/ghs/ghs.c > CMakeFiles/ghs.dir/ghs.c.i

CMakeFiles/ghs.dir/ghs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ghs.dir/ghs.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cesar/SISAP/src/indexes/ghs/ghs.c -o CMakeFiles/ghs.dir/ghs.c.s

CMakeFiles/ghs.dir/ghs.c.o.requires:

.PHONY : CMakeFiles/ghs.dir/ghs.c.o.requires

CMakeFiles/ghs.dir/ghs.c.o.provides: CMakeFiles/ghs.dir/ghs.c.o.requires
	$(MAKE) -f CMakeFiles/ghs.dir/build.make CMakeFiles/ghs.dir/ghs.c.o.provides.build
.PHONY : CMakeFiles/ghs.dir/ghs.c.o.provides

CMakeFiles/ghs.dir/ghs.c.o.provides.build: CMakeFiles/ghs.dir/ghs.c.o


# Object files for target ghs
ghs_OBJECTS = \
"CMakeFiles/ghs.dir/ghs.c.o"

# External object files for target ghs
ghs_EXTERNAL_OBJECTS =

ghs: CMakeFiles/ghs.dir/ghs.c.o
ghs: CMakeFiles/ghs.dir/build.make
ghs: CMakeFiles/ghs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cesar/SISAP/src/indexes/ghs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ghs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ghs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ghs.dir/build: ghs

.PHONY : CMakeFiles/ghs.dir/build

CMakeFiles/ghs.dir/requires: CMakeFiles/ghs.dir/ghs.c.o.requires

.PHONY : CMakeFiles/ghs.dir/requires

CMakeFiles/ghs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ghs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ghs.dir/clean

CMakeFiles/ghs.dir/depend:
	cd /home/cesar/SISAP/src/indexes/ghs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cesar/SISAP/src/indexes/ghs /home/cesar/SISAP/src/indexes/ghs /home/cesar/SISAP/src/indexes/ghs/cmake-build-debug /home/cesar/SISAP/src/indexes/ghs/cmake-build-debug /home/cesar/SISAP/src/indexes/ghs/cmake-build-debug/CMakeFiles/ghs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ghs.dir/depend

