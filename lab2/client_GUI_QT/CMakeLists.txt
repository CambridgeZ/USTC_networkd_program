cmake_minimum_required(VERSION 3.16)

project(QtSocketClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt libraries
find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)

# Enable AUTOMOC for Q_OBJECT
set(CMAKE_AUTOMOC ON)

# Add source files
set(SOURCES
    src/main.cpp
    src/ClientApp.cpp
)

set(HEADERS
    include/ClientApp.hpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets Qt5::Network)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)