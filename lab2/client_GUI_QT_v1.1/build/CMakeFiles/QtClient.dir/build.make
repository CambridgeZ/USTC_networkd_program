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
CMAKE_SOURCE_DIR = /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build

# Include any dependencies generated for this target.
include CMakeFiles/QtClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/QtClient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QtClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QtClient.dir/flags.make

CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o: CMakeFiles/QtClient.dir/flags.make
CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o: QtClient_autogen/mocs_compilation.cpp
CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o: CMakeFiles/QtClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o -MF CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o -c /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build/QtClient_autogen/mocs_compilation.cpp

CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build/QtClient_autogen/mocs_compilation.cpp > CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.i

CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build/QtClient_autogen/mocs_compilation.cpp -o CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.s

CMakeFiles/QtClient.dir/main.cpp.o: CMakeFiles/QtClient.dir/flags.make
CMakeFiles/QtClient.dir/main.cpp.o: ../main.cpp
CMakeFiles/QtClient.dir/main.cpp.o: CMakeFiles/QtClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/QtClient.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtClient.dir/main.cpp.o -MF CMakeFiles/QtClient.dir/main.cpp.o.d -o CMakeFiles/QtClient.dir/main.cpp.o -c /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/main.cpp

CMakeFiles/QtClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtClient.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/main.cpp > CMakeFiles/QtClient.dir/main.cpp.i

CMakeFiles/QtClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtClient.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/main.cpp -o CMakeFiles/QtClient.dir/main.cpp.s

# Object files for target QtClient
QtClient_OBJECTS = \
"CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/QtClient.dir/main.cpp.o"

# External object files for target QtClient
QtClient_EXTERNAL_OBJECTS =

QtClient: CMakeFiles/QtClient.dir/QtClient_autogen/mocs_compilation.cpp.o
QtClient: CMakeFiles/QtClient.dir/main.cpp.o
QtClient: CMakeFiles/QtClient.dir/build.make
QtClient: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
QtClient: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
QtClient: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
QtClient: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
QtClient: CMakeFiles/QtClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable QtClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QtClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QtClient.dir/build: QtClient
.PHONY : CMakeFiles/QtClient.dir/build

CMakeFiles/QtClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QtClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QtClient.dir/clean

CMakeFiles/QtClient.dir/depend:
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1 /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1 /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT_v1.1/build/CMakeFiles/QtClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QtClient.dir/depend
