cmake_minimum_required(VERSION 3.5)

# 自动生成 MOC 文件
set(CMAKE_AUTOMOC ON)

project(FileTransferApp)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Network)

set(CMAKE_CXX_STANDARD 11)



add_executable(FileTransferApp main.cpp)

# 添加 Qt5 的包含目录
target_link_libraries(FileTransferApp Qt5::Widgets Qt5::Network)
