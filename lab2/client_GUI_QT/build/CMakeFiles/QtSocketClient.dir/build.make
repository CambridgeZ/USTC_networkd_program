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
CMAKE_SOURCE_DIR = /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build

# Include any dependencies generated for this target.
include CMakeFiles/QtSocketClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/QtSocketClient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QtSocketClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QtSocketClient.dir/flags.make

CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o: CMakeFiles/QtSocketClient.dir/flags.make
CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o: QtSocketClient_autogen/mocs_compilation.cpp
CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o: CMakeFiles/QtSocketClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o -MF CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o -c /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build/QtSocketClient_autogen/mocs_compilation.cpp

CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build/QtSocketClient_autogen/mocs_compilation.cpp > CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.i

CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build/QtSocketClient_autogen/mocs_compilation.cpp -o CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.s

CMakeFiles/QtSocketClient.dir/src/main.cpp.o: CMakeFiles/QtSocketClient.dir/flags.make
CMakeFiles/QtSocketClient.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/QtSocketClient.dir/src/main.cpp.o: CMakeFiles/QtSocketClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/QtSocketClient.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtSocketClient.dir/src/main.cpp.o -MF CMakeFiles/QtSocketClient.dir/src/main.cpp.o.d -o CMakeFiles/QtSocketClient.dir/src/main.cpp.o -c /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/src/main.cpp

CMakeFiles/QtSocketClient.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtSocketClient.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/src/main.cpp > CMakeFiles/QtSocketClient.dir/src/main.cpp.i

CMakeFiles/QtSocketClient.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtSocketClient.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/src/main.cpp -o CMakeFiles/QtSocketClient.dir/src/main.cpp.s

CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o: CMakeFiles/QtSocketClient.dir/flags.make
CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o: ../src/ClientApp.cpp
CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o: CMakeFiles/QtSocketClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o -MF CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o.d -o CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o -c /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/src/ClientApp.cpp

CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/src/ClientApp.cpp > CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.i

CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/src/ClientApp.cpp -o CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.s

# Object files for target QtSocketClient
QtSocketClient_OBJECTS = \
"CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/QtSocketClient.dir/src/main.cpp.o" \
"CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o"

# External object files for target QtSocketClient
QtSocketClient_EXTERNAL_OBJECTS =

QtSocketClient: CMakeFiles/QtSocketClient.dir/QtSocketClient_autogen/mocs_compilation.cpp.o
QtSocketClient: CMakeFiles/QtSocketClient.dir/src/main.cpp.o
QtSocketClient: CMakeFiles/QtSocketClient.dir/src/ClientApp.cpp.o
QtSocketClient: CMakeFiles/QtSocketClient.dir/build.make
QtSocketClient: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
QtSocketClient: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
QtSocketClient: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
QtSocketClient: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
QtSocketClient: CMakeFiles/QtSocketClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable QtSocketClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QtSocketClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QtSocketClient.dir/build: QtSocketClient
.PHONY : CMakeFiles/QtSocketClient.dir/build

CMakeFiles/QtSocketClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QtSocketClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QtSocketClient.dir/clean

CMakeFiles/QtSocketClient.dir/depend:
	cd /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build /home/ubuntu/USTC_networkd_program/lab2/client_GUI_QT/build/CMakeFiles/QtSocketClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QtSocketClient.dir/depend
