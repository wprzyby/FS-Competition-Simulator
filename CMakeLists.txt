cmake_minimum_required(VERSION 3.13)

project(competiton_simulator)

add_compile_options(-std=c++20 -Wall -Wextra -g)

set(MAIN_SOURCES main.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_custom_target(main)
add_executable(${PROJECT_NAME} ${MAIN_SOURCES})
add_dependencies(main ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_SOURCE_DIR}"
                           "${PROJECT_SOURCE_DIR}/compsim_enums"
                           "${PROJECT_SOURCE_DIR}/compsim_classes"
                           "${PROJECT_SOURCE_DIR}/events"
                           "${PROJECT_SOURCE_DIR}/laptime_parser"
                           "${PROJECT_SOURCE_DIR}/interface"
                           "${PROJECT_SOURCE_DIR}/tests")

add_subdirectory(compsim_enums)
add_subdirectory(compsim_classes)
add_subdirectory(events)
add_subdirectory(laptime_parser)
add_subdirectory(interface)
add_subdirectory(tests)

target_link_libraries(${PROJECT_NAME} compsim_enums compsim_classes events laptime_parser interface)