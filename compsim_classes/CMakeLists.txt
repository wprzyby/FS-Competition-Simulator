set(base_classes_src_files
    Competition.cpp
    Event.cpp
    Team.cpp
    exceptions.cpp
    event_tools.cpp
    DynamicEvent.cpp
    StaticEvent.cpp
)

add_library(compsim_classes ${base_classes_src_files})
target_include_directories(compsim_classes PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(compsim_classes compsim_enums)