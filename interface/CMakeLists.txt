set(interface_src_files
    FileSaver.cpp
    ui_tools.cpp
)

add_library(interface ${interface_src_files})
target_include_directories(interface PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(interface events laptime_parser)