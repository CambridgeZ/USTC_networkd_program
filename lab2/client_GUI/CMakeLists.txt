cmake_minimum_required(VERSION 3.5)

project(ChatClientApp)

set(CMAKE_CXX_STANDARD 17)

# 查找 Qt5 必需模块
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# 启用 Qt 自动功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 源文件列表
set(SOURCES
    src/ChatWindow.cpp
    src/ChatClient.cpp
    src/Socket.cpp
    src/main.cpp
)

# 添加可执行文件
add_executable(ChatClientApp ${SOURCES})

# 链接 Qt5 库
target_link_libraries(ChatClientApp Qt5::Core Qt5::Widgets)



# PROJECT(client)

# SET(CMAKE_CXX_STANDARD 11)

# FILE(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# add_executable(client ${SRC_FILES})
