cmake_minimum_required(VERSION 3.5)

project(ChatClientApp)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)

add_executable(ChatClientApp main.cpp ChatClient.cpp)

target_link_libraries(ChatClientApp Qt5::Widgets)