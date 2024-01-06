set(GUI_MAIN_SRCS
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    main_gui.cpp
    TeamListItem.cpp
    CompetitionManager.cpp
    ResultSettingWidget.cpp
    ResultLineEditsWidget.cpp
    ScoresShowingWidget.cpp
    tools.cpp
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_custom_target(main_gui)
set(EXEC_NAME compsim_gui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${EXEC_NAME}
        MANUAL_FINALIZATION
        ${GUI_MAIN_SRCS}
    )
else()
    if(ANDROID)
        add_library(${EXEC_NAME} SHARED
            ${GUI_MAIN_SRCS}
        )
    else()
        add_executable(${EXEC_NAME}
            ${GUI_MAIN_SRCS}
        )
    endif()
endif()
add_dependencies(main_gui ${EXEC_NAME})

target_include_directories(${EXEC_NAME} PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(${EXEC_NAME} PRIVATE events laptime_parser Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS ${EXEC_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${EXEC_NAME})
endif()
