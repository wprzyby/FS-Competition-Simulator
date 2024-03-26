set(tests_src_files
    catch_config.cpp
    test_acceleration_DC.cpp
    test_acceleration_DV.cpp
    test_acceleration.cpp
    test_autocross_DC.cpp
    test_autocross.cpp
    test_businessplan.cpp
    test_cost_and_manufacturing.cpp
    # test_endurance.cpp
    test_engineering_design_driverless.cpp
    test_engineering_design.cpp
    test_skidpad_DC.cpp
    test_skidpad_DV.cpp
    test_skidpad.cpp
    test_trackdrive.cpp
)

add_custom_target(test)
add_executable(run_tests ${tests_src_files})
add_dependencies(test run_tests)
target_include_directories(run_tests PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(run_tests compsim_logic)
