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
CMAKE_SOURCE_DIR = /home/ubuntu/USTC_networkd_program/lab2/client_GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build

# Include any dependencies generated for this target.
include src/CMakeFiles/SocketClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/SocketClient.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/SocketClient.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/SocketClient.dir/flags.make

src/CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o: src/CMakeFiles/SocketClient.dir/flags.make
src/CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o: src/SocketClient_autogen/mocs_compilation.cpp
src/CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o: src/CMakeFiles/SocketClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o -c /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src/SocketClient_autogen/mocs_compilation.cpp

src/CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.i"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src/SocketClient_autogen/mocs_compilation.cpp > CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.i

src/CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.s"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src/SocketClient_autogen/mocs_compilation.cpp -o CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.s

src/CMakeFiles/SocketClient.dir/main.cpp.o: src/CMakeFiles/SocketClient.dir/flags.make
src/CMakeFiles/SocketClient.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/SocketClient.dir/main.cpp.o: src/CMakeFiles/SocketClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/SocketClient.dir/main.cpp.o"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/SocketClient.dir/main.cpp.o -MF CMakeFiles/SocketClient.dir/main.cpp.o.d -o CMakeFiles/SocketClient.dir/main.cpp.o -c /home/ubuntu/USTC_networkd_program/lab2/client_GUI/src/main.cpp

src/CMakeFiles/SocketClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketClient.dir/main.cpp.i"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/USTC_networkd_program/lab2/client_GUI/src/main.cpp > CMakeFiles/SocketClient.dir/main.cpp.i

src/CMakeFiles/SocketClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketClient.dir/main.cpp.s"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/USTC_networkd_program/lab2/client_GUI/src/main.cpp -o CMakeFiles/SocketClient.dir/main.cpp.s

src/CMakeFiles/SocketClient.dir/ClientApp.cpp.o: src/CMakeFiles/SocketClient.dir/flags.make
src/CMakeFiles/SocketClient.dir/ClientApp.cpp.o: ../src/ClientApp.cpp
src/CMakeFiles/SocketClient.dir/ClientApp.cpp.o: src/CMakeFiles/SocketClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/SocketClient.dir/ClientApp.cpp.o"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/SocketClient.dir/ClientApp.cpp.o -MF CMakeFiles/SocketClient.dir/ClientApp.cpp.o.d -o CMakeFiles/SocketClient.dir/ClientApp.cpp.o -c /home/ubuntu/USTC_networkd_program/lab2/client_GUI/src/ClientApp.cpp

src/CMakeFiles/SocketClient.dir/ClientApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SocketClient.dir/ClientApp.cpp.i"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/USTC_networkd_program/lab2/client_GUI/src/ClientApp.cpp > CMakeFiles/SocketClient.dir/ClientApp.cpp.i

src/CMakeFiles/SocketClient.dir/ClientApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SocketClient.dir/ClientApp.cpp.s"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/USTC_networkd_program/lab2/client_GUI/src/ClientApp.cpp -o CMakeFiles/SocketClient.dir/ClientApp.cpp.s

# Object files for target SocketClient
SocketClient_OBJECTS = \
"CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/SocketClient.dir/main.cpp.o" \
"CMakeFiles/SocketClient.dir/ClientApp.cpp.o"

# External object files for target SocketClient
SocketClient_EXTERNAL_OBJECTS =

src/SocketClient: src/CMakeFiles/SocketClient.dir/SocketClient_autogen/mocs_compilation.cpp.o
src/SocketClient: src/CMakeFiles/SocketClient.dir/main.cpp.o
src/SocketClient: src/CMakeFiles/SocketClient.dir/ClientApp.cpp.o
src/SocketClient: src/CMakeFiles/SocketClient.dir/build.make
src/SocketClient: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
src/SocketClient: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
src/SocketClient: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
src/SocketClient: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
src/SocketClient: src/CMakeFiles/SocketClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable SocketClient"
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SocketClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/SocketClient.dir/build: src/SocketClient
.PHONY : src/CMakeFiles/SocketClient.dir/build

src/CMakeFiles/SocketClient.dir/clean:
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src && $(CMAKE_COMMAND) -P CMakeFiles/SocketClient.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/SocketClient.dir/clean

src/CMakeFiles/SocketClient.dir/depend:
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/USTC_networkd_program/lab2/client_GUI /home/ubuntu/USTC_networkd_program/lab2/client_GUI/src /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src /home/ubuntu/USTC_networkd_program/lab2/client_GUI/build/src/CMakeFiles/SocketClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/SocketClient.dir/depend

