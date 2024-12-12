# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(UdpClientApp VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Source files
set(SOURCES
    main.cpp
    UdpClient.cpp
    MessageReceiver.cpp
)

# Executable target
add_executable(udp_client ${SOURCES})

# Link pthread library
find_package(Threads REQUIRED)
target_link_libraries(udp_client PRIVATE Threads::Threads)

# Compiler warnings (optional, for better development experience)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(udp_client PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(udp_client PRIVATE /W4 /permissive-)
endif()