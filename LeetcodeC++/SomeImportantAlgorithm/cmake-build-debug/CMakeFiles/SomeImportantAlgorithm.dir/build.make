# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SomeImportantAlgorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SomeImportantAlgorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SomeImportantAlgorithm.dir/flags.make

CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.obj: CMakeFiles/SomeImportantAlgorithm.dir/flags.make
CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SomeImportantAlgorithm.dir\main.cpp.obj -c E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\main.cpp

CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\main.cpp > CMakeFiles\SomeImportantAlgorithm.dir\main.cpp.i

CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\main.cpp -o CMakeFiles\SomeImportantAlgorithm.dir\main.cpp.s

# Object files for target SomeImportantAlgorithm
SomeImportantAlgorithm_OBJECTS = \
"CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.obj"

# External object files for target SomeImportantAlgorithm
SomeImportantAlgorithm_EXTERNAL_OBJECTS =

SomeImportantAlgorithm.exe: CMakeFiles/SomeImportantAlgorithm.dir/main.cpp.obj
SomeImportantAlgorithm.exe: CMakeFiles/SomeImportantAlgorithm.dir/build.make
SomeImportantAlgorithm.exe: CMakeFiles/SomeImportantAlgorithm.dir/linklibs.rsp
SomeImportantAlgorithm.exe: CMakeFiles/SomeImportantAlgorithm.dir/objects1.rsp
SomeImportantAlgorithm.exe: CMakeFiles/SomeImportantAlgorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SomeImportantAlgorithm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SomeImportantAlgorithm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SomeImportantAlgorithm.dir/build: SomeImportantAlgorithm.exe

.PHONY : CMakeFiles/SomeImportantAlgorithm.dir/build

CMakeFiles/SomeImportantAlgorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SomeImportantAlgorithm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SomeImportantAlgorithm.dir/clean

CMakeFiles/SomeImportantAlgorithm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\cmake-build-debug E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\cmake-build-debug E:\MyStudyFile\Study_C_PLUS_PLUS\C-PLUS-PLUS-Road\LeetcodeC++\SomeImportantAlgorithm\cmake-build-debug\CMakeFiles\SomeImportantAlgorithm.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SomeImportantAlgorithm.dir/depend
