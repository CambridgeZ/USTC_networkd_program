# 包含当前目录
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 自动生成 MOC 文件
set(CMAKE_AUTOMOC ON)

# 查找 Qt 库
find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

# 设置源文件
set(SOURCES
    main.cpp
    ClientApp.cpp
)

set(HEADERS
    ClientApp.h
)

# 生成可执行文件
add_executable(SocketClient ${SOURCES} ${HEADERS})

# 链接 Qt 库
target_link_libraries(SocketClient Qt5::Widgets Qt5::Network)