cmake_minimum_required(VERSION 3.16)

project(lab_01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.2\\mingw_64\\lib\\cmake")


include_directories(inc/ src/)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/main.cpp
        src/ui/mainwindow.cpp
        src/ui/mainwindow.ui
        src/logic/actions/actions.cpp
        src/logic/errors/errors.cpp
        src/logic/figure/edges.cpp
        src/logic/figure/figure.cpp
        src/logic/figure/figure_draw.cpp
        src/logic/figure/vertices.cpp
        src/logic/utils/file_utils.cpp
        inc/logic/actions/actions.hpp
        inc/logic/errors/errors.hpp
        inc/logic/figure/edges.hpp
        inc/logic/figure/figure.hpp
        inc/logic/figure/vertices.hpp
        inc/logic/utils/file_utils.hpp
        inc/ui/mainwindow.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab_01
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(lab_01
            ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(lab_01 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab_01)
endif()
set_target_properties(lab_01 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab_01
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab_01)
endif()
