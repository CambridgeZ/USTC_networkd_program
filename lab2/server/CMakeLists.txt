# Project name
PROJECT(server)

# Set C++ standard
SET(CMAKE_CXX_STANDARD 11)

# Set source files
# 设置源文为./src 文件夹下面的所有以cpp结尾的文件
FILE(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(server ${SRC_FILES})

