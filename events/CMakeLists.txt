set(events_src_files
    AccelerationEvent.cpp
    AutocrossEvent.cpp
    BusinessPlanEvent.cpp
    CostAndManufacturingEvent.cpp
    EnduranceEvent.cpp
    EngineeringDesignEvent.cpp
    SkidpadEvent.cpp
)

add_library(events ${events_src_files})
target_include_directories(events PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(events compsim_classes)