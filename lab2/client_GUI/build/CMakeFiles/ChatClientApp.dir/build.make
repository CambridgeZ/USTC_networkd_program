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

# Include any dependencies generated for this target.
include CMakeFiles/ChatClientApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ChatClientApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ChatClientApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChatClientApp.dir/flags.make

ChatClientApp_autogen/timestamp: /usr/lib/qt5/bin/moc
ChatClientApp_autogen/timestamp: /usr/lib/qt5/bin/uic
ChatClientApp_autogen/timestamp: CMakeFiles/ChatClientApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ChatClientApp"
	/usr/local/bin/cmake -E cmake_autogen /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles/ChatClientApp_autogen.dir/AutogenInfo.json ""
	/usr/local/bin/cmake -E touch /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/ChatClientApp_autogen/timestamp

CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o: CMakeFiles/ChatClientApp.dir/flags.make
CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o: ChatClientApp_autogen/mocs_compilation.cpp
CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o: CMakeFiles/ChatClientApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o -MF CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o -c /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/ChatClientApp_autogen/mocs_compilation.cpp

CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/ChatClientApp_autogen/mocs_compilation.cpp > CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.i

CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/ChatClientApp_autogen/mocs_compilation.cpp -o CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.s

CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o: CMakeFiles/ChatClientApp.dir/flags.make
CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o: /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/ChatWindow.cpp
CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o: CMakeFiles/ChatClientApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o -MF CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o.d -o CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o -c /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/ChatWindow.cpp

CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/ChatWindow.cpp > CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.i

CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/ChatWindow.cpp -o CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.s

CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o: CMakeFiles/ChatClientApp.dir/flags.make
CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o: /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/ChatClient.cpp
CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o: CMakeFiles/ChatClientApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o -MF CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o.d -o CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o -c /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/ChatClient.cpp

CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/ChatClient.cpp > CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.i

CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/ChatClient.cpp -o CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.s

CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o: CMakeFiles/ChatClientApp.dir/flags.make
CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o: /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/Socket.cpp
CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o: CMakeFiles/ChatClientApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o -MF CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o.d -o CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o -c /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/Socket.cpp

CMakeFiles/ChatClientApp.dir/src/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ChatClientApp.dir/src/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/Socket.cpp > CMakeFiles/ChatClientApp.dir/src/Socket.cpp.i

CMakeFiles/ChatClientApp.dir/src/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ChatClientApp.dir/src/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/Socket.cpp -o CMakeFiles/ChatClientApp.dir/src/Socket.cpp.s

CMakeFiles/ChatClientApp.dir/src/main.cpp.o: CMakeFiles/ChatClientApp.dir/flags.make
CMakeFiles/ChatClientApp.dir/src/main.cpp.o: /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/main.cpp
CMakeFiles/ChatClientApp.dir/src/main.cpp.o: CMakeFiles/ChatClientApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ChatClientApp.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChatClientApp.dir/src/main.cpp.o -MF CMakeFiles/ChatClientApp.dir/src/main.cpp.o.d -o CMakeFiles/ChatClientApp.dir/src/main.cpp.o -c /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/main.cpp

CMakeFiles/ChatClientApp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ChatClientApp.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/main.cpp > CMakeFiles/ChatClientApp.dir/src/main.cpp.i

CMakeFiles/ChatClientApp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ChatClientApp.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/src/main.cpp -o CMakeFiles/ChatClientApp.dir/src/main.cpp.s

# Object files for target ChatClientApp
ChatClientApp_OBJECTS = \
"CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o" \
"CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o" \
"CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o" \
"CMakeFiles/ChatClientApp.dir/src/main.cpp.o"

# External object files for target ChatClientApp
ChatClientApp_EXTERNAL_OBJECTS =

ChatClientApp: CMakeFiles/ChatClientApp.dir/ChatClientApp_autogen/mocs_compilation.cpp.o
ChatClientApp: CMakeFiles/ChatClientApp.dir/src/ChatWindow.cpp.o
ChatClientApp: CMakeFiles/ChatClientApp.dir/src/ChatClient.cpp.o
ChatClientApp: CMakeFiles/ChatClientApp.dir/src/Socket.cpp.o
ChatClientApp: CMakeFiles/ChatClientApp.dir/src/main.cpp.o
ChatClientApp: CMakeFiles/ChatClientApp.dir/build.make
ChatClientApp: /usr/lib/aarch64-linux-gnu/libQt5Widgets.so.5.15.3
ChatClientApp: /usr/lib/aarch64-linux-gnu/libQt5Gui.so.5.15.3
ChatClientApp: /usr/lib/aarch64-linux-gnu/libQt5Core.so.5.15.3
ChatClientApp: CMakeFiles/ChatClientApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ChatClientApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChatClientApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChatClientApp.dir/build: ChatClientApp
.PHONY : CMakeFiles/ChatClientApp.dir/build

CMakeFiles/ChatClientApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChatClientApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChatClientApp.dir/clean

CMakeFiles/ChatClientApp.dir/depend: ChatClientApp_autogen/timestamp
	cd /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build /home/parallels/Desktop/USTC_networkd_program/lab2/client_GUI/build/CMakeFiles/ChatClientApp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ChatClientApp.dir/depend
