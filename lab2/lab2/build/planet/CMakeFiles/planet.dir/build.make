# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/labs/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/labs/lab2/build

# Include any dependencies generated for this target.
include planet/CMakeFiles/planet.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include planet/CMakeFiles/planet.dir/compiler_depend.make

# Include the progress variables for this target.
include planet/CMakeFiles/planet.dir/progress.make

# Include the compile flags for this target's objects.
include planet/CMakeFiles/planet.dir/flags.make

planet/CMakeFiles/planet.dir/planet.cpp.obj: planet/CMakeFiles/planet.dir/flags.make
planet/CMakeFiles/planet.dir/planet.cpp.obj: C:/labs/lab2/planet/planet.cpp
planet/CMakeFiles/planet.dir/planet.cpp.obj: planet/CMakeFiles/planet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/labs/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object planet/CMakeFiles/planet.dir/planet.cpp.obj"
	cd C:/labs/lab2/build/planet && c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT planet/CMakeFiles/planet.dir/planet.cpp.obj -MF CMakeFiles/planet.dir/planet.cpp.obj.d -o CMakeFiles/planet.dir/planet.cpp.obj -c C:/labs/lab2/planet/planet.cpp

planet/CMakeFiles/planet.dir/planet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/planet.dir/planet.cpp.i"
	cd C:/labs/lab2/build/planet && c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/labs/lab2/planet/planet.cpp > CMakeFiles/planet.dir/planet.cpp.i

planet/CMakeFiles/planet.dir/planet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/planet.dir/planet.cpp.s"
	cd C:/labs/lab2/build/planet && c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/labs/lab2/planet/planet.cpp -o CMakeFiles/planet.dir/planet.cpp.s

# Object files for target planet
planet_OBJECTS = \
"CMakeFiles/planet.dir/planet.cpp.obj"

# External object files for target planet
planet_EXTERNAL_OBJECTS =

planet/libplanet.a: planet/CMakeFiles/planet.dir/planet.cpp.obj
planet/libplanet.a: planet/CMakeFiles/planet.dir/build.make
planet/libplanet.a: planet/CMakeFiles/planet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/labs/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libplanet.a"
	cd C:/labs/lab2/build/planet && $(CMAKE_COMMAND) -P CMakeFiles/planet.dir/cmake_clean_target.cmake
	cd C:/labs/lab2/build/planet && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/planet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
planet/CMakeFiles/planet.dir/build: planet/libplanet.a
.PHONY : planet/CMakeFiles/planet.dir/build

planet/CMakeFiles/planet.dir/clean:
	cd C:/labs/lab2/build/planet && $(CMAKE_COMMAND) -P CMakeFiles/planet.dir/cmake_clean.cmake
.PHONY : planet/CMakeFiles/planet.dir/clean

planet/CMakeFiles/planet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/labs/lab2 C:/labs/lab2/planet C:/labs/lab2/build C:/labs/lab2/build/planet C:/labs/lab2/build/planet/CMakeFiles/planet.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : planet/CMakeFiles/planet.dir/depend

