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
CMAKE_SOURCE_DIR = C:/labs/lab7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/labs/lab7/build

# Include any dependencies generated for this target.
include CMakeFiles/lab7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab7.dir/flags.make

CMakeFiles/lab7.dir/main.cpp.obj: CMakeFiles/lab7.dir/flags.make
CMakeFiles/lab7.dir/main.cpp.obj: C:/labs/lab7/main.cpp
CMakeFiles/lab7.dir/main.cpp.obj: CMakeFiles/lab7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/labs/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab7.dir/main.cpp.obj"
	c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab7.dir/main.cpp.obj -MF CMakeFiles/lab7.dir/main.cpp.obj.d -o CMakeFiles/lab7.dir/main.cpp.obj -c C:/labs/lab7/main.cpp

CMakeFiles/lab7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab7.dir/main.cpp.i"
	c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/labs/lab7/main.cpp > CMakeFiles/lab7.dir/main.cpp.i

CMakeFiles/lab7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab7.dir/main.cpp.s"
	c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/labs/lab7/main.cpp -o CMakeFiles/lab7.dir/main.cpp.s

# Object files for target lab7
lab7_OBJECTS = \
"CMakeFiles/lab7.dir/main.cpp.obj"

# External object files for target lab7
lab7_EXTERNAL_OBJECTS =

lab7.exe: CMakeFiles/lab7.dir/main.cpp.obj
lab7.exe: CMakeFiles/lab7.dir/build.make
lab7.exe: classes/libclasses.a
lab7.exe: CMakeFiles/lab7.dir/linkLibs.rsp
lab7.exe: CMakeFiles/lab7.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/labs/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab7.exe"
	"C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f CMakeFiles/lab7.dir/objects.a
	C:/gcc/bin/ar.exe qc CMakeFiles/lab7.dir/objects.a @CMakeFiles/lab7.dir/objects1.rsp
	c:/gcc/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/lab7.dir/objects.a -Wl,--no-whole-archive -o lab7.exe -Wl,--out-implib,liblab7.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/lab7.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/lab7.dir/build: lab7.exe
.PHONY : CMakeFiles/lab7.dir/build

CMakeFiles/lab7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab7.dir/clean

CMakeFiles/lab7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/labs/lab7 C:/labs/lab7 C:/labs/lab7/build C:/labs/lab7/build C:/labs/lab7/build/CMakeFiles/lab7.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab7.dir/depend

