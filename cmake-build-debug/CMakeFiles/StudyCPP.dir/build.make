# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "D:\CLion 2021.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\ClionProject\StudyCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\ClionProject\StudyCPP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StudyCPP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/StudyCPP.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/StudyCPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StudyCPP.dir/flags.make

CMakeFiles/StudyCPP.dir/Day1/Student.cpp.obj: CMakeFiles/StudyCPP.dir/flags.make
CMakeFiles/StudyCPP.dir/Day1/Student.cpp.obj: ../Day1/Student.cpp
CMakeFiles/StudyCPP.dir/Day1/Student.cpp.obj: CMakeFiles/StudyCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\ClionProject\StudyCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StudyCPP.dir/Day1/Student.cpp.obj"
	"D:\CLion 2021.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StudyCPP.dir/Day1/Student.cpp.obj -MF CMakeFiles\StudyCPP.dir\Day1\Student.cpp.obj.d -o CMakeFiles\StudyCPP.dir\Day1\Student.cpp.obj -c G:\ClionProject\StudyCPP\Day1\Student.cpp

CMakeFiles/StudyCPP.dir/Day1/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudyCPP.dir/Day1/Student.cpp.i"
	"D:\CLion 2021.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\ClionProject\StudyCPP\Day1\Student.cpp > CMakeFiles\StudyCPP.dir\Day1\Student.cpp.i

CMakeFiles/StudyCPP.dir/Day1/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudyCPP.dir/Day1/Student.cpp.s"
	"D:\CLion 2021.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\ClionProject\StudyCPP\Day1\Student.cpp -o CMakeFiles\StudyCPP.dir\Day1\Student.cpp.s

CMakeFiles/StudyCPP.dir/Day1/T9.cpp.obj: CMakeFiles/StudyCPP.dir/flags.make
CMakeFiles/StudyCPP.dir/Day1/T9.cpp.obj: ../Day1/T9.cpp
CMakeFiles/StudyCPP.dir/Day1/T9.cpp.obj: CMakeFiles/StudyCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\ClionProject\StudyCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StudyCPP.dir/Day1/T9.cpp.obj"
	"D:\CLion 2021.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StudyCPP.dir/Day1/T9.cpp.obj -MF CMakeFiles\StudyCPP.dir\Day1\T9.cpp.obj.d -o CMakeFiles\StudyCPP.dir\Day1\T9.cpp.obj -c G:\ClionProject\StudyCPP\Day1\T9.cpp

CMakeFiles/StudyCPP.dir/Day1/T9.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudyCPP.dir/Day1/T9.cpp.i"
	"D:\CLion 2021.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\ClionProject\StudyCPP\Day1\T9.cpp > CMakeFiles\StudyCPP.dir\Day1\T9.cpp.i

CMakeFiles/StudyCPP.dir/Day1/T9.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudyCPP.dir/Day1/T9.cpp.s"
	"D:\CLion 2021.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\ClionProject\StudyCPP\Day1\T9.cpp -o CMakeFiles\StudyCPP.dir\Day1\T9.cpp.s

# Object files for target StudyCPP
StudyCPP_OBJECTS = \
"CMakeFiles/StudyCPP.dir/Day1/Student.cpp.obj" \
"CMakeFiles/StudyCPP.dir/Day1/T9.cpp.obj"

# External object files for target StudyCPP
StudyCPP_EXTERNAL_OBJECTS =

StudyCPP.exe: CMakeFiles/StudyCPP.dir/Day1/Student.cpp.obj
StudyCPP.exe: CMakeFiles/StudyCPP.dir/Day1/T9.cpp.obj
StudyCPP.exe: CMakeFiles/StudyCPP.dir/build.make
StudyCPP.exe: CMakeFiles/StudyCPP.dir/linklibs.rsp
StudyCPP.exe: CMakeFiles/StudyCPP.dir/objects1.rsp
StudyCPP.exe: CMakeFiles/StudyCPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\ClionProject\StudyCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable StudyCPP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StudyCPP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StudyCPP.dir/build: StudyCPP.exe
.PHONY : CMakeFiles/StudyCPP.dir/build

CMakeFiles/StudyCPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StudyCPP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StudyCPP.dir/clean

CMakeFiles/StudyCPP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\ClionProject\StudyCPP G:\ClionProject\StudyCPP G:\ClionProject\StudyCPP\cmake-build-debug G:\ClionProject\StudyCPP\cmake-build-debug G:\ClionProject\StudyCPP\cmake-build-debug\CMakeFiles\StudyCPP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StudyCPP.dir/depend

