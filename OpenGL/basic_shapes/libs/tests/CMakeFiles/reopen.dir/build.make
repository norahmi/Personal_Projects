# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/glfw-3.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs

# Include any dependencies generated for this target.
include tests/CMakeFiles/reopen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/reopen.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/reopen.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/reopen.dir/flags.make

tests/CMakeFiles/reopen.dir/reopen.c.o: tests/CMakeFiles/reopen.dir/flags.make
tests/CMakeFiles/reopen.dir/reopen.c.o: /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/glfw-3.4/tests/reopen.c
tests/CMakeFiles/reopen.dir/reopen.c.o: tests/CMakeFiles/reopen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/reopen.dir/reopen.c.o"
	cd /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/reopen.dir/reopen.c.o -MF CMakeFiles/reopen.dir/reopen.c.o.d -o CMakeFiles/reopen.dir/reopen.c.o -c /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/glfw-3.4/tests/reopen.c

tests/CMakeFiles/reopen.dir/reopen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/reopen.dir/reopen.c.i"
	cd /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/glfw-3.4/tests/reopen.c > CMakeFiles/reopen.dir/reopen.c.i

tests/CMakeFiles/reopen.dir/reopen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/reopen.dir/reopen.c.s"
	cd /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/glfw-3.4/tests/reopen.c -o CMakeFiles/reopen.dir/reopen.c.s

# Object files for target reopen
reopen_OBJECTS = \
"CMakeFiles/reopen.dir/reopen.c.o"

# External object files for target reopen
reopen_EXTERNAL_OBJECTS =

tests/reopen: tests/CMakeFiles/reopen.dir/reopen.c.o
tests/reopen: tests/CMakeFiles/reopen.dir/build.make
tests/reopen: src/libglfw3.a
tests/reopen: /usr/lib/x86_64-linux-gnu/libm.so
tests/reopen: /usr/lib/x86_64-linux-gnu/librt.a
tests/reopen: /usr/lib/x86_64-linux-gnu/libm.so
tests/reopen: tests/CMakeFiles/reopen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable reopen"
	cd /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reopen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/reopen.dir/build: tests/reopen
.PHONY : tests/CMakeFiles/reopen.dir/build

tests/CMakeFiles/reopen.dir/clean:
	cd /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/tests && $(CMAKE_COMMAND) -P CMakeFiles/reopen.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/reopen.dir/clean

tests/CMakeFiles/reopen.dir/depend:
	cd /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/glfw-3.4 /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/glfw-3.4/tests /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/tests /mnt/c/Users/norah/Documents/personal_projects/OpenGL/basic_shapes/libs/tests/CMakeFiles/reopen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/reopen.dir/depend

