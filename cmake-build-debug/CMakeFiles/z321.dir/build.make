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
include CMakeFiles/z321.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/z321.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/z321.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/z321.dir/flags.make

CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o: CMakeFiles/z321.dir/flags.make
CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o: /home/miftarosky/CLionProjects/FINKI-OOP/Задачи\ за\ вежбање\ за\ прв\ колоквиум/4.cpp
CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o: CMakeFiles/z321.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o -MF CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o.d -o CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o -c "/home/miftarosky/CLionProjects/FINKI-OOP/Задачи за вежбање за прв колоквиум/4.cpp"

CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/miftarosky/CLionProjects/FINKI-OOP/Задачи за вежбање за прв колоквиум/4.cpp" > CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.i

CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/miftarosky/CLionProjects/FINKI-OOP/Задачи за вежбање за прв колоквиум/4.cpp" -o CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.s

# Object files for target z321
z321_OBJECTS = \
"CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o"

# External object files for target z321
z321_EXTERNAL_OBJECTS =

z321: CMakeFiles/z321.dir/Задачи_за_вежбање_за_прв_колоквиум/4.cpp.o
z321: CMakeFiles/z321.dir/build.make
z321: CMakeFiles/z321.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable z321"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/z321.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/z321.dir/build: z321
.PHONY : CMakeFiles/z321.dir/build

CMakeFiles/z321.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/z321.dir/cmake_clean.cmake
.PHONY : CMakeFiles/z321.dir/clean

CMakeFiles/z321.dir/depend:
	cd /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/miftarosky/CLionProjects/FINKI-OOP /home/miftarosky/CLionProjects/FINKI-OOP /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug /home/miftarosky/CLionProjects/FINKI-OOP/cmake-build-debug/CMakeFiles/z321.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/z321.dir/depend
