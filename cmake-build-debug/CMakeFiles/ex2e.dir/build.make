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
CMAKE_COMMAND = /home/miftarosky/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/miftarosky/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/miftarosky/CLionProjects/FINKI-OOP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex2e.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ex2e.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ex2e.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex2e.dir/flags.make

CMakeFiles/ex2e.dir/Exercises_(EN)/2.o: CMakeFiles/ex2e.dir/flags.make
CMakeFiles/ex2e.dir/Exercises_(EN)/2.o: /home/miftarosky/CLionProjects/FINKI-OOP/Exercises\ (EN)/2.cpp
CMakeFiles/ex2e.dir/Exercises_(EN)/2.o: CMakeFiles/ex2e.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex2e.dir/Exercises_(EN)/2.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT "CMakeFiles/ex2e.dir/Exercises_(EN)/2.o" -MF "CMakeFiles/ex2e.dir/Exercises_(EN)/2.o.d" -o "CMakeFiles/ex2e.dir/Exercises_(EN)/2.o" -c "/home/miftarosky/CLionProjects/FINKI-OOP/Exercises (EN)/2.cpp"

CMakeFiles/ex2e.dir/Exercises_(EN)/2.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ex2e.dir/Exercises_(EN)/2.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/miftarosky/CLionProjects/FINKI-OOP/Exercises (EN)/2.cpp" > "CMakeFiles/ex2e.dir/Exercises_(EN)/2.i"

CMakeFiles/ex2e.dir/Exercises_(EN)/2.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ex2e.dir/Exercises_(EN)/2.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/miftarosky/CLionProjects/FINKI-OOP/Exercises (EN)/2.cpp" -o "CMakeFiles/ex2e.dir/Exercises_(EN)/2.s"

# Object files for target ex2e
ex2e_OBJECTS = \
"CMakeFiles/ex2e.dir/Exercises_(EN)/2.o"

# External object files for target ex2e
ex2e_EXTERNAL_OBJECTS =

ex2e: CMakeFiles/ex2e.dir/Exercises_(EN)/2.o
ex2e: CMakeFiles/ex2e.dir/build.make
ex2e: CMakeFiles/ex2e.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex2e"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex2e.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex2e.dir/build: ex2e
.PHONY : CMakeFiles/ex2e.dir/build

CMakeFiles/ex2e.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex2e.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex2e.dir/clean

CMakeFiles/ex2e.dir/depend:
	cd /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/miftarosky/CLionProjects/FINKI-OOP /home/miftarosky/CLionProjects/FINKI-OOP /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug/CMakeFiles/ex2e.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ex2e.dir/depend
