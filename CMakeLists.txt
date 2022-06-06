cmake_minimum_required(VERSION 2.8.9)
project(competiton_simulation)

add_compile_options(-std=c++20 -Wall -Wextra)
include_directories(base_classes enums events tests)

file(GLOB TEST_SOURCES "base_classes/*.cpp" "events/*.cpp" "tests/*.cpp" "enums/*.cpp" "./*.cpp")
file(GLOB MAIN_SOURCES "base_classes/*.cpp" "events/*.cpp" "enums/*.cpp" "./*.cpp" "interface/*.cpp")

add_custom_target(tests)
add_executable(run_tests ${TEST_SOURCES})
add_dependencies(tests run_tests)

add_custom_target(main)
add_executable(main_executable ${MAIN_SOURCES})
add_dependencies(main main_executable)