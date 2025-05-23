cmake_minimum_required(VERSION 3.16)

project(lab_03 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)
include_directories(objects)
include_directories(objects/visible_objects)
include_directories(objects/invisible_objects)
include_directories(objects/visible_objects/structures)
include_directories(matrix)
include_directories(matrix/matrix)
include_directories(matrix/iterator)
include_directories(matrix/exception)
include_directories(matrix/concept)
include_directories(managers)
include_directories(concepts)
include_directories(adapters)
include_directories(adapters/composite)
include_directories(adapters/model)
include_directories(commands)
include_directories(drawer)
include_directories(facade)
include_directories(exceptions)
include_directories(scene)
include_directories(load)
include_directories(load/loader)
include_directories(load/director)
include_directories(load/builder)
include_directories(transform)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui
        exceptions/Exceptions.hpp
        matrix/concept/MatrixConcept.hpp
        matrix/exception/ExceptionMatrix.hpp
        matrix/exception/ExceptionMatrix.сpp
        matrix/iterator/ConstIterator.cpp
        matrix/iterator/ConstIterator.hpp
        matrix/iterator/MatrixIterator.cpp
        matrix/iterator/MatrixIterator.hpp
        matrix/matrix/MatrixRow.cpp
        matrix/matrix/Matrix.hpp
        matrix/matrix/Matrix.h
        objects/visible_objects/structures/Edge.cpp
        objects/visible_objects/structures/Edge.hpp
        objects/visible_objects/structures/LinkDotStructure.cpp
        objects/visible_objects/structures/LinkDotStructure.hpp
        objects/visible_objects/structures/MatrixStructure.cpp
        objects/visible_objects/structures/MatrixStructure.hpp
        objects/visible_objects/structures/ModelStructure.cpp
        objects/visible_objects/structures/ModelStructure.hpp
        objects/visible_objects/structures/Vertex.cpp
        objects/visible_objects/structures/Vertex.hpp
        objects/visible_objects/BaseModel.cpp
        objects/visible_objects/BaseModel.hpp
        objects/visible_objects/CarcassModel.cpp
        objects/visible_objects/CarcassModel.hpp
        objects/visible_objects/VisibleObject.cpp
        objects/visible_objects/VisibleObject.hpp
        objects/BaseObject.cpp
        objects/BaseObject.hpp
        objects/Composite.cpp
        objects/Composite.hpp
        objects/invisible_objects/Camera.cpp
        objects/invisible_objects/Camera.hpp
        objects/invisible_objects/InvisibleObject.cpp
        objects/invisible_objects/InvisibleObject.hpp
        managers/DrawManager.cpp
        managers/DrawManager.hpp
        managers/LoadManager.cpp
        managers/LoadManager.hpp
        managers/SceneManager.cpp
        managers/SceneManager.hpp
        managers/TransformManager.cpp
        managers/TransformManager.hpp
        concepts/Concepts.hpp
        adapters/composite/CompositeAdapter.hpp
        adapters/composite/DrawCompositeAdapter.cpp
        adapters/composite/DrawCompositeAdapter.hpp
        adapters/model/DrawCarcassModelAdapter.cpp
        adapters/model/DrawCarcassModelAdapter.hpp
        adapters/model/ModelAdapter.hpp
        adapters/BaseAdapter.hpp
        load/loader/LoaderSolution.cpp
        load/loader/LoaderSolution.hpp
        load/loader/BaseLoader.cpp
        load/loader/BaseLoader.hpp
        load/loader/BaseLoaderCreator.cpp
        load/loader/BaseLoaderCreator.hpp
        load/loader/ModelCsvLoaderCreator.cpp
        load/loader/ModelCsvLoaderCreator.hpp
        load/loader/ModelTxtLoaderCreator.cpp
        load/loader/ModelTxtLoaderCreator.hpp
        load/loader/ModelCsvLoader.cpp
        load/loader/ModelCsvLoader.hpp
        load/loader/ModelTxtLoader.cpp
        load/loader/ModelTxtLoader.hpp
        load/director/LinkListDirector.cpp
        load/director/LinkListDirector.hpp
        load/director/MatrixDirector.cpp
        load/director/MatrixDirector.hpp
        load/builder/BaseBuilder.cpp
        load/builder/BaseBuilder.hpp
        load/builder/BaseModelBuilder.cpp
        load/builder/BaseModelBuilder.hpp
        load/builder/MatrixBuilder.cpp
        load/builder/MatrixBuilder.hpp
        load/builder/LinkListBuilder.cpp
        load/builder/LinkListBuilder.hpp
        drawer/AbstractDrawerFactory.cpp
        drawer/BaseDrawer.cpp
        drawer/QtDrawer.cpp
        drawer/QtDrawerFactory.cpp
        drawer/AbstractDrawerFactory.cpp
        drawer/QtDrawer.cpp
        drawer/QtDrawerFactory.cpp
        drawer/BaseDrawer.cpp
        transform/TransformBuilder.cpp
        transform/TransformBuilder.hpp
        adapters/composite/TransformCompositeAdapter.cpp
        adapters/composite/TransformCompositeAdapter.hpp
        adapters/model/TransformModelAdapter.cpp
        adapters/model/TransformModelAdapter.hpp

)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab_03
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )
else ()
    add_executable(lab_03
            ${PROJECT_SOURCES}
    )
endif ()

target_link_libraries(lab_03 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if (${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab_03)
endif ()
set_target_properties(lab_03 PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab_03
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab_03)
endif ()
