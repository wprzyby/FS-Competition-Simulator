cmake_minimum_required(VERSION 3.5)
project(competition-simulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-std=c++20 -Wall -Wextra -g)

add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(qt_interface)
