# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU

# Include any dependencies generated for this target.
include CMakeFiles/PositrigoRU.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PositrigoRU.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PositrigoRU.dir/flags.make

CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.o: CMakeFiles/PositrigoRU.dir/flags.make
CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.o: PositrigoRU.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.o -c /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU/PositrigoRU.cc

CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU/PositrigoRU.cc > CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.i

CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU/PositrigoRU.cc -o CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.s

# Object files for target PositrigoRU
PositrigoRU_OBJECTS = \
"CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.o"

# External object files for target PositrigoRU
PositrigoRU_EXTERNAL_OBJECTS =

PositrigoRU: CMakeFiles/PositrigoRU.dir/PositrigoRU.cc.o
PositrigoRU: CMakeFiles/PositrigoRU.dir/build.make
PositrigoRU: CMakeFiles/PositrigoRU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PositrigoRU"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PositrigoRU.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PositrigoRU.dir/build: PositrigoRU

.PHONY : CMakeFiles/PositrigoRU.dir/build

CMakeFiles/PositrigoRU.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PositrigoRU.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PositrigoRU.dir/clean

CMakeFiles/PositrigoRU.dir/depend:
	cd /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU /mnt/c/Users/chalampalakis/CLionProjects/PositrigoRU/CMakeFiles/PositrigoRU.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PositrigoRU.dir/depend
