set(compsim_sources
    Competition.cpp
    dynamic_formulas_FSG.cpp
    dynamic_formulas_FSN.cpp
    dynamic_preprocessing.cpp
    dynamic_sims.cpp
    event_tools.cpp
    EventSimulatorStandard.cpp
    exceptions.cpp
    LapTimeParser.cpp
    PointsCalculatorFSG.cpp
    simulator_factory.cpp
    static_formulas_FSG.cpp
    static_preprocessing.cpp
    static_sims.cpp
    Team.cpp
)

add_library(compsim_logic ${compsim_sources})
target_include_directories(compsim_logic PUBLIC ${PROJECT_SOURCE_DIR}/include)
