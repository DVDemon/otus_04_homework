# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/cmake-3.12.4/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/travis/build/DVDemon/otus_04_homework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/travis/build/DVDemon/otus_04_homework

# Include any dependencies generated for this target.
include CMakeFiles/gtests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtests.dir/flags.make

CMakeFiles/gtests.dir/tests.cpp.o: CMakeFiles/gtests.dir/flags.make
CMakeFiles/gtests.dir/tests.cpp.o: tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/DVDemon/otus_04_homework/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtests.dir/tests.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtests.dir/tests.cpp.o -c /home/travis/build/DVDemon/otus_04_homework/tests.cpp

CMakeFiles/gtests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtests.dir/tests.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/DVDemon/otus_04_homework/tests.cpp > CMakeFiles/gtests.dir/tests.cpp.i

CMakeFiles/gtests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtests.dir/tests.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/DVDemon/otus_04_homework/tests.cpp -o CMakeFiles/gtests.dir/tests.cpp.s

# Object files for target gtests
gtests_OBJECTS = \
"CMakeFiles/gtests.dir/tests.cpp.o"

# External object files for target gtests
gtests_EXTERNAL_OBJECTS =

gtests: CMakeFiles/gtests.dir/tests.cpp.o
gtests: CMakeFiles/gtests.dir/build.make
gtests: /usr/lib/libgtest.a
gtests: liblibrary.a
gtests: liblibrary.a
gtests: CMakeFiles/gtests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/travis/build/DVDemon/otus_04_homework/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gtests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtests.dir/build: gtests

.PHONY : CMakeFiles/gtests.dir/build

CMakeFiles/gtests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtests.dir/clean

CMakeFiles/gtests.dir/depend:
	cd /home/travis/build/DVDemon/otus_04_homework && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/travis/build/DVDemon/otus_04_homework /home/travis/build/DVDemon/otus_04_homework /home/travis/build/DVDemon/otus_04_homework /home/travis/build/DVDemon/otus_04_homework /home/travis/build/DVDemon/otus_04_homework/CMakeFiles/gtests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtests.dir/depend

