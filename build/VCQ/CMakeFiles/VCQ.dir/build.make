# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/node10/yangxu/TDSC23-VCQ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/node10/yangxu/TDSC23-VCQ/build

# Include any dependencies generated for this target.
include VCQ/CMakeFiles/VCQ.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include VCQ/CMakeFiles/VCQ.dir/compiler_depend.make

# Include the progress variables for this target.
include VCQ/CMakeFiles/VCQ.dir/progress.make

# Include the compile flags for this target's objects.
include VCQ/CMakeFiles/VCQ.dir/flags.make

VCQ/CMakeFiles/VCQ.dir/Client.cpp.o: VCQ/CMakeFiles/VCQ.dir/flags.make
VCQ/CMakeFiles/VCQ.dir/Client.cpp.o: ../VCQ/Client.cpp
VCQ/CMakeFiles/VCQ.dir/Client.cpp.o: VCQ/CMakeFiles/VCQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/node10/yangxu/TDSC23-VCQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object VCQ/CMakeFiles/VCQ.dir/Client.cpp.o"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT VCQ/CMakeFiles/VCQ.dir/Client.cpp.o -MF CMakeFiles/VCQ.dir/Client.cpp.o.d -o CMakeFiles/VCQ.dir/Client.cpp.o -c /home/node10/yangxu/TDSC23-VCQ/VCQ/Client.cpp

VCQ/CMakeFiles/VCQ.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VCQ.dir/Client.cpp.i"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/node10/yangxu/TDSC23-VCQ/VCQ/Client.cpp > CMakeFiles/VCQ.dir/Client.cpp.i

VCQ/CMakeFiles/VCQ.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VCQ.dir/Client.cpp.s"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/node10/yangxu/TDSC23-VCQ/VCQ/Client.cpp -o CMakeFiles/VCQ.dir/Client.cpp.s

VCQ/CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o: VCQ/CMakeFiles/VCQ.dir/flags.make
VCQ/CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o: ../VCQ/Crypto_Primitives.cpp
VCQ/CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o: VCQ/CMakeFiles/VCQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/node10/yangxu/TDSC23-VCQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object VCQ/CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT VCQ/CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o -MF CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o.d -o CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o -c /home/node10/yangxu/TDSC23-VCQ/VCQ/Crypto_Primitives.cpp

VCQ/CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.i"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/node10/yangxu/TDSC23-VCQ/VCQ/Crypto_Primitives.cpp > CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.i

VCQ/CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.s"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/node10/yangxu/TDSC23-VCQ/VCQ/Crypto_Primitives.cpp -o CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.s

VCQ/CMakeFiles/VCQ.dir/Server.cpp.o: VCQ/CMakeFiles/VCQ.dir/flags.make
VCQ/CMakeFiles/VCQ.dir/Server.cpp.o: ../VCQ/Server.cpp
VCQ/CMakeFiles/VCQ.dir/Server.cpp.o: VCQ/CMakeFiles/VCQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/node10/yangxu/TDSC23-VCQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object VCQ/CMakeFiles/VCQ.dir/Server.cpp.o"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT VCQ/CMakeFiles/VCQ.dir/Server.cpp.o -MF CMakeFiles/VCQ.dir/Server.cpp.o.d -o CMakeFiles/VCQ.dir/Server.cpp.o -c /home/node10/yangxu/TDSC23-VCQ/VCQ/Server.cpp

VCQ/CMakeFiles/VCQ.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VCQ.dir/Server.cpp.i"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/node10/yangxu/TDSC23-VCQ/VCQ/Server.cpp > CMakeFiles/VCQ.dir/Server.cpp.i

VCQ/CMakeFiles/VCQ.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VCQ.dir/Server.cpp.s"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/node10/yangxu/TDSC23-VCQ/VCQ/Server.cpp -o CMakeFiles/VCQ.dir/Server.cpp.s

VCQ/CMakeFiles/VCQ.dir/main.cpp.o: VCQ/CMakeFiles/VCQ.dir/flags.make
VCQ/CMakeFiles/VCQ.dir/main.cpp.o: ../VCQ/main.cpp
VCQ/CMakeFiles/VCQ.dir/main.cpp.o: VCQ/CMakeFiles/VCQ.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/node10/yangxu/TDSC23-VCQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object VCQ/CMakeFiles/VCQ.dir/main.cpp.o"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT VCQ/CMakeFiles/VCQ.dir/main.cpp.o -MF CMakeFiles/VCQ.dir/main.cpp.o.d -o CMakeFiles/VCQ.dir/main.cpp.o -c /home/node10/yangxu/TDSC23-VCQ/VCQ/main.cpp

VCQ/CMakeFiles/VCQ.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VCQ.dir/main.cpp.i"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/node10/yangxu/TDSC23-VCQ/VCQ/main.cpp > CMakeFiles/VCQ.dir/main.cpp.i

VCQ/CMakeFiles/VCQ.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VCQ.dir/main.cpp.s"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/node10/yangxu/TDSC23-VCQ/VCQ/main.cpp -o CMakeFiles/VCQ.dir/main.cpp.s

# Object files for target VCQ
VCQ_OBJECTS = \
"CMakeFiles/VCQ.dir/Client.cpp.o" \
"CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o" \
"CMakeFiles/VCQ.dir/Server.cpp.o" \
"CMakeFiles/VCQ.dir/main.cpp.o"

# External object files for target VCQ
VCQ_EXTERNAL_OBJECTS =

../bin/VCQ: VCQ/CMakeFiles/VCQ.dir/Client.cpp.o
../bin/VCQ: VCQ/CMakeFiles/VCQ.dir/Crypto_Primitives.cpp.o
../bin/VCQ: VCQ/CMakeFiles/VCQ.dir/Server.cpp.o
../bin/VCQ: VCQ/CMakeFiles/VCQ.dir/main.cpp.o
../bin/VCQ: VCQ/CMakeFiles/VCQ.dir/build.make
../bin/VCQ: ../lib/libPuncturable_PRF.a
../bin/VCQ: /home/node10/anaconda3/lib/libcrypto.so
../bin/VCQ: VCQ/CMakeFiles/VCQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/node10/yangxu/TDSC23-VCQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../../bin/VCQ"
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VCQ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
VCQ/CMakeFiles/VCQ.dir/build: ../bin/VCQ
.PHONY : VCQ/CMakeFiles/VCQ.dir/build

VCQ/CMakeFiles/VCQ.dir/clean:
	cd /home/node10/yangxu/TDSC23-VCQ/build/VCQ && $(CMAKE_COMMAND) -P CMakeFiles/VCQ.dir/cmake_clean.cmake
.PHONY : VCQ/CMakeFiles/VCQ.dir/clean

VCQ/CMakeFiles/VCQ.dir/depend:
	cd /home/node10/yangxu/TDSC23-VCQ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/node10/yangxu/TDSC23-VCQ /home/node10/yangxu/TDSC23-VCQ/VCQ /home/node10/yangxu/TDSC23-VCQ/build /home/node10/yangxu/TDSC23-VCQ/build/VCQ /home/node10/yangxu/TDSC23-VCQ/build/VCQ/CMakeFiles/VCQ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : VCQ/CMakeFiles/VCQ.dir/depend
