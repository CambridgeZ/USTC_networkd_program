cmake_minimum_required(VERSION 3.16)

# 设置项目名称
project(FileTransferApp)

# 查找Qt包，指定需要的模块
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Network)

# 设置编译选项
set(CMAKE_CXX_STANDARD 17)

# 设置目标可执行文件
add_executable(FileTransferApp main.cpp)

# 链接 Qt 库
target_link_libraries(FileTransferApp Qt5::Core Qt5::Widgets Qt5::Network)

# 设置 Qt5 的头文件目录和库目录
target_include_directories(FileTransferApp PRIVATE ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS})
