# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build

# Utility rule file for ChatClientApp_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/ChatClientApp_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ChatClientApp_autogen.dir/progress.make

CMakeFiles/ChatClientApp_autogen: ChatClientApp_autogen/timestamp

ChatClientApp_autogen/timestamp: /usr/lib/qt5/bin/moc
ChatClientApp_autogen/timestamp: /usr/lib/qt5/bin/uic
ChatClientApp_autogen/timestamp: CMakeFiles/ChatClientApp_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ChatClientApp"
	/usr/local/bin/cmake -E cmake_autogen /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles/ChatClientApp_autogen.dir/AutogenInfo.json ""
	/usr/local/bin/cmake -E touch /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/ChatClientApp_autogen/timestamp

ChatClientApp_autogen: CMakeFiles/ChatClientApp_autogen
ChatClientApp_autogen: ChatClientApp_autogen/timestamp
ChatClientApp_autogen: CMakeFiles/ChatClientApp_autogen.dir/build.make
.PHONY : ChatClientApp_autogen

# Rule to build all files generated by this target.
CMakeFiles/ChatClientApp_autogen.dir/build: ChatClientApp_autogen
.PHONY : CMakeFiles/ChatClientApp_autogen.dir/build

CMakeFiles/ChatClientApp_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChatClientApp_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChatClientApp_autogen.dir/clean

CMakeFiles/ChatClientApp_autogen.dir/depend:
	cd /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles/ChatClientApp_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ChatClientApp_autogen.dir/depend
