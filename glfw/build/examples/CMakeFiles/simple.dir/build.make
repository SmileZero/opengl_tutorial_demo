# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yan_runchen/iPhoneWorks/opengltest/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/simple.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/simple.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/simple.dir/flags.make

examples/CMakeFiles/simple.dir/simple.c.o: examples/CMakeFiles/simple.dir/flags.make
examples/CMakeFiles/simple.dir/simple.c.o: ../examples/simple.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/simple.dir/simple.c.o"
	cd /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simple.dir/simple.c.o   -c /Users/yan_runchen/iPhoneWorks/opengltest/glfw/examples/simple.c

examples/CMakeFiles/simple.dir/simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/simple.c.i"
	cd /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/yan_runchen/iPhoneWorks/opengltest/glfw/examples/simple.c > CMakeFiles/simple.dir/simple.c.i

examples/CMakeFiles/simple.dir/simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/simple.c.s"
	cd /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/yan_runchen/iPhoneWorks/opengltest/glfw/examples/simple.c -o CMakeFiles/simple.dir/simple.c.s

examples/CMakeFiles/simple.dir/simple.c.o.requires:

.PHONY : examples/CMakeFiles/simple.dir/simple.c.o.requires

examples/CMakeFiles/simple.dir/simple.c.o.provides: examples/CMakeFiles/simple.dir/simple.c.o.requires
	$(MAKE) -f examples/CMakeFiles/simple.dir/build.make examples/CMakeFiles/simple.dir/simple.c.o.provides.build
.PHONY : examples/CMakeFiles/simple.dir/simple.c.o.provides

examples/CMakeFiles/simple.dir/simple.c.o.provides.build: examples/CMakeFiles/simple.dir/simple.c.o


# Object files for target simple
simple_OBJECTS = \
"CMakeFiles/simple.dir/simple.c.o"

# External object files for target simple
simple_EXTERNAL_OBJECTS =

examples/simple.app/Contents/MacOS/simple: examples/CMakeFiles/simple.dir/simple.c.o
examples/simple.app/Contents/MacOS/simple: examples/CMakeFiles/simple.dir/build.make
examples/simple.app/Contents/MacOS/simple: src/libglfw3.a
examples/simple.app/Contents/MacOS/simple: examples/CMakeFiles/simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable simple.app/Contents/MacOS/simple"
	cd /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/simple.dir/build: examples/simple.app/Contents/MacOS/simple

.PHONY : examples/CMakeFiles/simple.dir/build

examples/CMakeFiles/simple.dir/requires: examples/CMakeFiles/simple.dir/simple.c.o.requires

.PHONY : examples/CMakeFiles/simple.dir/requires

examples/CMakeFiles/simple.dir/clean:
	cd /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/simple.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/simple.dir/clean

examples/CMakeFiles/simple.dir/depend:
	cd /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yan_runchen/iPhoneWorks/opengltest/glfw /Users/yan_runchen/iPhoneWorks/opengltest/glfw/examples /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/examples /Users/yan_runchen/iPhoneWorks/opengltest/glfw/build/examples/CMakeFiles/simple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/simple.dir/depend

