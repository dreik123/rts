# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/pi/rts/spring_103.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/rts/spring_103.0

# Include any dependencies generated for this target.
include tools/pr-downloader/test/CMakeFiles/prd_test.dir/depend.make

# Include the progress variables for this target.
include tools/pr-downloader/test/CMakeFiles/prd_test.dir/progress.make

# Include the compile flags for this target's objects.
include tools/pr-downloader/test/CMakeFiles/prd_test.dir/flags.make

tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o: tools/pr-downloader/test/CMakeFiles/prd_test.dir/flags.make
tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o: tools/pr-downloader/test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring_103.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o"
	cd /home/pi/rts/spring_103.0/tools/pr-downloader/test && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prd_test.dir/test.cpp.o -c /home/pi/rts/spring_103.0/tools/pr-downloader/test/test.cpp

tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prd_test.dir/test.cpp.i"
	cd /home/pi/rts/spring_103.0/tools/pr-downloader/test && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/rts/spring_103.0/tools/pr-downloader/test/test.cpp > CMakeFiles/prd_test.dir/test.cpp.i

tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prd_test.dir/test.cpp.s"
	cd /home/pi/rts/spring_103.0/tools/pr-downloader/test && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/rts/spring_103.0/tools/pr-downloader/test/test.cpp -o CMakeFiles/prd_test.dir/test.cpp.s

tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o.requires:

.PHONY : tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o.requires

tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o.provides: tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o.requires
	$(MAKE) -f tools/pr-downloader/test/CMakeFiles/prd_test.dir/build.make tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o.provides.build
.PHONY : tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o.provides

tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o.provides.build: tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o


# Object files for target prd_test
prd_test_OBJECTS = \
"CMakeFiles/prd_test.dir/test.cpp.o"

# External object files for target prd_test
prd_test_EXTERNAL_OBJECTS =

tools/pr-downloader/test/prd_test: tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o
tools/pr-downloader/test/prd_test: tools/pr-downloader/test/CMakeFiles/prd_test.dir/build.make
tools/pr-downloader/test/prd_test: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
tools/pr-downloader/test/prd_test: tools/pr-downloader/src/libDownloader.a
tools/pr-downloader/test/prd_test: /usr/lib/x86_64-linux-gnu/libcurl.so
tools/pr-downloader/test/prd_test: /usr/lib/x86_64-linux-gnu/libz.so
tools/pr-downloader/test/prd_test: tools/pr-downloader/src/lib/md5/libpr-md5.a
tools/pr-downloader/test/prd_test: tools/pr-downloader/src/lib/sha1/libpr-sha1.a
tools/pr-downloader/test/prd_test: tools/pr-downloader/src/lib/bencode/libbencode.a
tools/pr-downloader/test/prd_test: tools/pr-downloader/src/lib/7z/libpr-7z.a
tools/pr-downloader/test/prd_test: /usr/lib/x86_64-linux-gnu/libminizip.so
tools/pr-downloader/test/prd_test: tools/pr-downloader/test/CMakeFiles/prd_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/rts/spring_103.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prd_test"
	cd /home/pi/rts/spring_103.0/tools/pr-downloader/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prd_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/pr-downloader/test/CMakeFiles/prd_test.dir/build: tools/pr-downloader/test/prd_test

.PHONY : tools/pr-downloader/test/CMakeFiles/prd_test.dir/build

tools/pr-downloader/test/CMakeFiles/prd_test.dir/requires: tools/pr-downloader/test/CMakeFiles/prd_test.dir/test.cpp.o.requires

.PHONY : tools/pr-downloader/test/CMakeFiles/prd_test.dir/requires

tools/pr-downloader/test/CMakeFiles/prd_test.dir/clean:
	cd /home/pi/rts/spring_103.0/tools/pr-downloader/test && $(CMAKE_COMMAND) -P CMakeFiles/prd_test.dir/cmake_clean.cmake
.PHONY : tools/pr-downloader/test/CMakeFiles/prd_test.dir/clean

tools/pr-downloader/test/CMakeFiles/prd_test.dir/depend:
	cd /home/pi/rts/spring_103.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/rts/spring_103.0 /home/pi/rts/spring_103.0/tools/pr-downloader/test /home/pi/rts/spring_103.0 /home/pi/rts/spring_103.0/tools/pr-downloader/test /home/pi/rts/spring_103.0/tools/pr-downloader/test/CMakeFiles/prd_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/pr-downloader/test/CMakeFiles/prd_test.dir/depend

