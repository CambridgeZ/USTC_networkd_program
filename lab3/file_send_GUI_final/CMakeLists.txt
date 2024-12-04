cmake_minimum_required(VERSION 3.5)

project(SocketClient)

# 设置 Qt 的路径
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Network)

# 启用 AUTOMOC 处理 Qt 元对象
set(CMAKE_AUTOMOC ON)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加源文件
set(SOURCES
    main.cpp
    clientapp.cpp
)

# 添加头文件
set(HEADERS
    clientapp.h
)

# 设置可执行文件
add_executable(SocketClient ${SOURCES} ${HEADERS})

target_link_libraries(SocketClient Qt5::Core Qt5::Widgets Qt5::Network)

target_link_libraries(SocketClient ${QT_LIBRARIES})

