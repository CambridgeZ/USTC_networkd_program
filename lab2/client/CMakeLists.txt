cmake_minimum_required(VERSION 3.5)

# 项目名称和标准设置
project(ChatClientApp)

set(CMAKE_CXX_STANDARD 11)

# 查找 Qt5 Widgets 库
find_package(Qt5Widgets REQUIRED)

# 定义源文件和头文件
set(SOURCES
    src/main.cpp
    src/ChatClient.cpp
    src/ChatWindow.cpp
    src/Socket.cpp
)

set(HEADERS
    src/ChatClient.hpp
    src/ChatWindow.hpp
    src/Socket.hpp
    src/config.hpp
)

# 自动处理包含 Q_OBJECT 宏的头文件
qt5_wrap_cpp(MOC_SOURCES
    src/ChatWindow.hpp
)

# 添加可执行文件
add_executable(ChatClientApp ${SOURCES} ${MOC_SOURCES})

# 链接 Qt5 Widgets 库
target_link_libraries(ChatClientApp Qt5::Widgets)

# 指定头文件路径（可选，根据需要设置）
target_include_directories(ChatClientApp PRIVATE src)
