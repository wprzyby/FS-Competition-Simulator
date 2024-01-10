

set(base_classes_src_files
    Competition.cpp
    Team.cpp
    exceptions.cpp
    event_tools.cpp
    PointsCalculatorFSG.cpp
    EventSimulatorStandard.cpp
    preprocessing_standard.cpp
    static_events_sims.cpp
    dynamic_events_sims.cpp
)

add_library(compsim_classes ${base_classes_src_files})
target_include_directories(compsim_classes PUBLIC EventSimulatorStandard PointsCalculatorFSG)
target_include_directories(compsim_classes PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(compsim_classes compsim_enums)