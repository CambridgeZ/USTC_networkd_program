cmake_minimum_required(VERSION 3.14)

# 项目名称和版本
project(QtClient LANGUAGES CXX)

# 查找 Qt 必需组件
set(CMAKE_AUTOMOC ON) # 自动处理 MOC 文件
set(CMAKE_AUTORCC ON) # 自动处理资源文件
set(CMAKE_AUTOUIC ON) # 自动处理 .ui 文件

find_package(Qt5 REQUIRED COMPONENTS Widgets Network)

# 添加源文件
add_executable(QtClient
    main.cpp
)

# 链接 Qt 库
target_link_libraries(QtClient PRIVATE Qt5::Widgets Qt5::Network)

# 设置 C++ 标准
set_target_properties(QtClient PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)