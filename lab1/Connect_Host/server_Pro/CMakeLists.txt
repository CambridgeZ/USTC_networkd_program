cmake_minimum_required(VERSION 3.10)
project(WebSocketServerProject)

set(CMAKE_CXX_STANDARD 17)

# 设置头文件路径
include_directories(include)

# 添加源文件
add_executable(WebSocketServer
    src/main.cpp
    src/WebSocketServer.cpp
)

# 链接 WebSocket++ 依赖项
find_package(Boost REQUIRED system)
target_link_libraries(WebSocketServer Boost::boost Boost::system)