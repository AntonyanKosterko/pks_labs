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
include classes/CMakeFiles/classes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include classes/CMakeFiles/classes.dir/compiler_depend.make

# Include the progress variables for this target.
include classes/CMakeFiles/classes.dir/progress.make

# Include the compile flags for this target's objects.
include classes/CMakeFiles/classes.dir/flags.make

classes/CMakeFiles/classes.dir/classes.cpp.obj: classes/CMakeFiles/classes.dir/flags.make
classes/CMakeFiles/classes.dir/classes.cpp.obj: C:/labs/lab7/classes/classes.cpp
classes/CMakeFiles/classes.dir/classes.cpp.obj: classes/CMakeFiles/classes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/labs/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object classes/CMakeFiles/classes.dir/classes.cpp.obj"
	cd C:/labs/lab7/build/classes && c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT classes/CMakeFiles/classes.dir/classes.cpp.obj -MF CMakeFiles/classes.dir/classes.cpp.obj.d -o CMakeFiles/classes.dir/classes.cpp.obj -c C:/labs/lab7/classes/classes.cpp

classes/CMakeFiles/classes.dir/classes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/classes.dir/classes.cpp.i"
	cd C:/labs/lab7/build/classes && c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/labs/lab7/classes/classes.cpp > CMakeFiles/classes.dir/classes.cpp.i

classes/CMakeFiles/classes.dir/classes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/classes.dir/classes.cpp.s"
	cd C:/labs/lab7/build/classes && c:/gcc/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/labs/lab7/classes/classes.cpp -o CMakeFiles/classes.dir/classes.cpp.s

# Object files for target classes
classes_OBJECTS = \
"CMakeFiles/classes.dir/classes.cpp.obj"

# External object files for target classes
classes_EXTERNAL_OBJECTS =

classes/libclasses.a: classes/CMakeFiles/classes.dir/classes.cpp.obj
classes/libclasses.a: classes/CMakeFiles/classes.dir/build.make
classes/libclasses.a: classes/CMakeFiles/classes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/labs/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libclasses.a"
	cd C:/labs/lab7/build/classes && $(CMAKE_COMMAND) -P CMakeFiles/classes.dir/cmake_clean_target.cmake
	cd C:/labs/lab7/build/classes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/classes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
classes/CMakeFiles/classes.dir/build: classes/libclasses.a
.PHONY : classes/CMakeFiles/classes.dir/build

classes/CMakeFiles/classes.dir/clean:
	cd C:/labs/lab7/build/classes && $(CMAKE_COMMAND) -P CMakeFiles/classes.dir/cmake_clean.cmake
.PHONY : classes/CMakeFiles/classes.dir/clean

classes/CMakeFiles/classes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/labs/lab7 C:/labs/lab7/classes C:/labs/lab7/build C:/labs/lab7/build/classes C:/labs/lab7/build/classes/CMakeFiles/classes.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : classes/CMakeFiles/classes.dir/depend

