cmake_minimum_required(VERSION 3.14)
project(SocketClient)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Qt 库
find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

# 添加子目录
add_subdirectory(src)