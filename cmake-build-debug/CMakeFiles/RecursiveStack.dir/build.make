# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mario\CLionProjects\DataStructures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mario\CLionProjects\DataStructures\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RecursiveStack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RecursiveStack.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RecursiveStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RecursiveStack.dir/flags.make

CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.obj: CMakeFiles/RecursiveStack.dir/flags.make
CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.obj: C:/Users/mario/CLionProjects/DataStructures/Homework8b/RecursiveStack.cpp
CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.obj: CMakeFiles/RecursiveStack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\mario\CLionProjects\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.obj -MF CMakeFiles\RecursiveStack.dir\Homework8b\RecursiveStack.cpp.obj.d -o CMakeFiles\RecursiveStack.dir\Homework8b\RecursiveStack.cpp.obj -c C:\Users\mario\CLionProjects\DataStructures\Homework8b\RecursiveStack.cpp

CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mario\CLionProjects\DataStructures\Homework8b\RecursiveStack.cpp > CMakeFiles\RecursiveStack.dir\Homework8b\RecursiveStack.cpp.i

CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mario\CLionProjects\DataStructures\Homework8b\RecursiveStack.cpp -o CMakeFiles\RecursiveStack.dir\Homework8b\RecursiveStack.cpp.s

# Object files for target RecursiveStack
RecursiveStack_OBJECTS = \
"CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.obj"

# External object files for target RecursiveStack
RecursiveStack_EXTERNAL_OBJECTS =

RecursiveStack.exe: CMakeFiles/RecursiveStack.dir/Homework8b/RecursiveStack.cpp.obj
RecursiveStack.exe: CMakeFiles/RecursiveStack.dir/build.make
RecursiveStack.exe: CMakeFiles/RecursiveStack.dir/linkLibs.rsp
RecursiveStack.exe: CMakeFiles/RecursiveStack.dir/objects1.rsp
RecursiveStack.exe: CMakeFiles/RecursiveStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\mario\CLionProjects\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RecursiveStack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RecursiveStack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RecursiveStack.dir/build: RecursiveStack.exe
.PHONY : CMakeFiles/RecursiveStack.dir/build

CMakeFiles/RecursiveStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RecursiveStack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RecursiveStack.dir/clean

CMakeFiles/RecursiveStack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mario\CLionProjects\DataStructures C:\Users\mario\CLionProjects\DataStructures C:\Users\mario\CLionProjects\DataStructures\cmake-build-debug C:\Users\mario\CLionProjects\DataStructures\cmake-build-debug C:\Users\mario\CLionProjects\DataStructures\cmake-build-debug\CMakeFiles\RecursiveStack.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/RecursiveStack.dir/depend

