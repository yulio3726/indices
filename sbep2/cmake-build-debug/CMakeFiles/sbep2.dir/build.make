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
CMAKE_SOURCE_DIR = /home/cesar/SISAP/src/indexes/sbep2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cesar/SISAP/src/indexes/sbep2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sbep2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sbep2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sbep2.dir/flags.make

CMakeFiles/sbep2.dir/sbep2.c.o: CMakeFiles/sbep2.dir/flags.make
CMakeFiles/sbep2.dir/sbep2.c.o: ../sbep2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cesar/SISAP/src/indexes/sbep2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sbep2.dir/sbep2.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sbep2.dir/sbep2.c.o   -c /home/cesar/SISAP/src/indexes/sbep2/sbep2.c

CMakeFiles/sbep2.dir/sbep2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sbep2.dir/sbep2.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cesar/SISAP/src/indexes/sbep2/sbep2.c > CMakeFiles/sbep2.dir/sbep2.c.i

CMakeFiles/sbep2.dir/sbep2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sbep2.dir/sbep2.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cesar/SISAP/src/indexes/sbep2/sbep2.c -o CMakeFiles/sbep2.dir/sbep2.c.s

CMakeFiles/sbep2.dir/sbep2.c.o.requires:

.PHONY : CMakeFiles/sbep2.dir/sbep2.c.o.requires

CMakeFiles/sbep2.dir/sbep2.c.o.provides: CMakeFiles/sbep2.dir/sbep2.c.o.requires
	$(MAKE) -f CMakeFiles/sbep2.dir/build.make CMakeFiles/sbep2.dir/sbep2.c.o.provides.build
.PHONY : CMakeFiles/sbep2.dir/sbep2.c.o.provides

CMakeFiles/sbep2.dir/sbep2.c.o.provides.build: CMakeFiles/sbep2.dir/sbep2.c.o


# Object files for target sbep2
sbep2_OBJECTS = \
"CMakeFiles/sbep2.dir/sbep2.c.o"

# External object files for target sbep2
sbep2_EXTERNAL_OBJECTS =

sbep2: CMakeFiles/sbep2.dir/sbep2.c.o
sbep2: CMakeFiles/sbep2.dir/build.make
sbep2: CMakeFiles/sbep2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cesar/SISAP/src/indexes/sbep2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sbep2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sbep2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sbep2.dir/build: sbep2

.PHONY : CMakeFiles/sbep2.dir/build

CMakeFiles/sbep2.dir/requires: CMakeFiles/sbep2.dir/sbep2.c.o.requires

.PHONY : CMakeFiles/sbep2.dir/requires

CMakeFiles/sbep2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sbep2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sbep2.dir/clean

CMakeFiles/sbep2.dir/depend:
	cd /home/cesar/SISAP/src/indexes/sbep2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cesar/SISAP/src/indexes/sbep2 /home/cesar/SISAP/src/indexes/sbep2 /home/cesar/SISAP/src/indexes/sbep2/cmake-build-debug /home/cesar/SISAP/src/indexes/sbep2/cmake-build-debug /home/cesar/SISAP/src/indexes/sbep2/cmake-build-debug/CMakeFiles/sbep2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sbep2.dir/depend
