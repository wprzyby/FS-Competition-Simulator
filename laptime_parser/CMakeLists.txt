set(laptime_parser_src_files
    LapTimeParser.cpp
    json_config.cpp
)

add_library(laptime_parser ${laptime_parser_src_files})
target_include_directories(laptime_parser PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(laptime_parser compsim_enums)
