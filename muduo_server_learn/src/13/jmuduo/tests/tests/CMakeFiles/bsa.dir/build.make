# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mengbw/muduo_server_learn/src/13/jmuduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mengbw/muduo_server_learn/src/13/jmuduo/tests

# Include any dependencies generated for this target.
include tests/CMakeFiles/bsa.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/bsa.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/bsa.dir/flags.make

tests/CMakeFiles/bsa.dir/bsa.cc.o: tests/CMakeFiles/bsa.dir/flags.make
tests/CMakeFiles/bsa.dir/bsa.cc.o: bsa.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mengbw/muduo_server_learn/src/13/jmuduo/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/bsa.dir/bsa.cc.o"
	cd /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/tests && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bsa.dir/bsa.cc.o -c /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/bsa.cc

tests/CMakeFiles/bsa.dir/bsa.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bsa.dir/bsa.cc.i"
	cd /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/tests && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/bsa.cc > CMakeFiles/bsa.dir/bsa.cc.i

tests/CMakeFiles/bsa.dir/bsa.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bsa.dir/bsa.cc.s"
	cd /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/tests && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/bsa.cc -o CMakeFiles/bsa.dir/bsa.cc.s

tests/CMakeFiles/bsa.dir/bsa.cc.o.requires:

.PHONY : tests/CMakeFiles/bsa.dir/bsa.cc.o.requires

tests/CMakeFiles/bsa.dir/bsa.cc.o.provides: tests/CMakeFiles/bsa.dir/bsa.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/bsa.dir/build.make tests/CMakeFiles/bsa.dir/bsa.cc.o.provides.build
.PHONY : tests/CMakeFiles/bsa.dir/bsa.cc.o.provides

tests/CMakeFiles/bsa.dir/bsa.cc.o.provides.build: tests/CMakeFiles/bsa.dir/bsa.cc.o


# Object files for target bsa
bsa_OBJECTS = \
"CMakeFiles/bsa.dir/bsa.cc.o"

# External object files for target bsa
bsa_EXTERNAL_OBJECTS =

bin/bsa: tests/CMakeFiles/bsa.dir/bsa.cc.o
bin/bsa: tests/CMakeFiles/bsa.dir/build.make
bin/bsa: tests/CMakeFiles/bsa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mengbw/muduo_server_learn/src/13/jmuduo/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/bsa"
	cd /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bsa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/bsa.dir/build: bin/bsa

.PHONY : tests/CMakeFiles/bsa.dir/build

tests/CMakeFiles/bsa.dir/requires: tests/CMakeFiles/bsa.dir/bsa.cc.o.requires

.PHONY : tests/CMakeFiles/bsa.dir/requires

tests/CMakeFiles/bsa.dir/clean:
	cd /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/tests && $(CMAKE_COMMAND) -P CMakeFiles/bsa.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/bsa.dir/clean

tests/CMakeFiles/bsa.dir/depend:
	cd /home/mengbw/muduo_server_learn/src/13/jmuduo/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mengbw/muduo_server_learn/src/13/jmuduo /home/mengbw/muduo_server_learn/src/13/jmuduo/tests /home/mengbw/muduo_server_learn/src/13/jmuduo/tests /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/tests /home/mengbw/muduo_server_learn/src/13/jmuduo/tests/tests/CMakeFiles/bsa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/bsa.dir/depend
