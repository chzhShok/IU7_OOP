cmake_minimum_required(VERSION 3.16)

project(lab_03 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Поиск SQLite
find_package(SQLite3 REQUIRED)

# Включение всех заголовочных файлов через один вызов
include_directories(
        builder
        center
        command
        command/camera
        command/draw
        command/load
        command/object
        command/scene
        concepts
        director
        drawer
        exception
        facade
        manager
        objects
        loader
        scene
        matrix
        transform_strategy
        visitor
)

# Группировка исходных файлов
set(PROJECT_SOURCES
        builder/BaseCarcassModelBuilder.cpp
        builder/BaseCarcassModelBuilder.hpp
        builder/LinkListModelBuilder.cpp
        builder/LinkListModelBuilder.hpp
        builder/MatrixModelBuilder.cpp
        builder/MatrixModelBuilder.hpp
        command/camera/AddCameraCommand.cpp
        command/camera/AddCameraCommand.hpp
        command/camera/BaseCameraCommand.cpp
        command/camera/BaseCameraCommand.hpp
        command/camera/RemoveCameraCommand.cpp
        command/camera/RemoveCameraCommand.hpp
        command/camera/SetCameraCommand.cpp
        command/camera/SetCameraCommand.hpp
        command/draw/BaseDrawCommand.cpp
        command/draw/BaseDrawCommand.hpp
        command/draw/DrawSceneQtCommand.cpp
        command/draw/DrawSceneQtCommand.hpp
        command/load/BaseLoadCommand.cpp
        command/load/BaseLoadCommand.hpp
        command/load/BaseLoadCommandDecorator.cpp
        command/load/BaseLoadCommandDecorator.hpp
        command/load/ListLoadCommand.cpp
        command/load/ListLoadCommand.hpp
        command/load/MatrixLoadCommand.cpp
        command/load/MatrixLoadCommand.hpp
        command/load/CsvLoadCommandDecorator.cpp
        command/load/CsvLoadCommandDecorator.hpp
        command/load/TxtLoadCommandDecorator.cpp
        command/load/TxtLoadCommandDecorator.hpp
        command/object/BaseObjectCommand.cpp
        command/object/BaseObjectCommand.hpp
        command/object/CompositeObjectCommand.cpp
        command/object/CompositeObjectCommand.hpp
        command/object/DeleteObjectCommand.cpp
        command/object/DeleteObjectCommand.hpp
        command/object/RotateObjectCommand.cpp
        command/object/RotateObjectCommand.hpp
        command/object/ScaleObjectCommand.cpp
        command/object/ScaleObjectCommand.hpp
        command/object/MoveObjectCommand.cpp
        command/object/MoveObjectCommand.hpp
        command/scene/BaseSceneCommand.cpp
        command/scene/BaseSceneCommand.hpp
        command/scene/ClearSceneCommand.cpp
        command/scene/ClearSceneCommand.hpp
        command/scene/GetCameraIDsSceneCommand.cpp
        command/scene/GetCameraIDsSceneCommand.hpp
        command/scene/GetObjectIDsSceneCommand.cpp
        command/scene/GetObjectIDsSceneCommand.hpp
        command/BaseCommand.cpp
        command/BaseCommand.hpp
        concepts/Concept.hpp
        director/BaseCarcassModelDirector.cpp
        director/BaseCarcassModelDirector.hpp
        director/BaseDirector.cpp
        director/BaseDirector.hpp
        director/BaseDirectorCreator.hpp
        director/DirectorCreator.h
        director/DirectorCreator.hpp
        director/DirectorSolution.cpp
        director/DirectorSolution.h
        director/DirectorSolution.hpp
        director/LinkListModelDirector.cpp
        director/LinkListModelDirector.hpp
        director/MatrixModelDirector.cpp
        director/MatrixModelDirector.hpp
        drawer/BaseDrawer.cpp
        drawer/BaseDrawerCreator.cpp
        drawer/BaseDrawerCreator.hpp
        drawer/QtDrawer.cpp
        drawer/QtDrawer.hpp
        drawer/QtDrawerCreator.cpp
        drawer/QtDrawerCreator.hpp
        exception/Exception.cpp
        exception/Exception.hpp
        facade/Facade.cpp
        facade/Facade.hpp
        manager/DrawManager.h
        manager/DrawManager.hpp
        manager/LoadManager.cpp
        manager/LoadManager.hpp
        manager/SceneManager.cpp
        manager/SceneManager.hpp
        manager/TransformManager.cpp
        manager/TransformManager.hpp
        objects/BaseModel.cpp
        objects/CarcassModel.cpp
        objects/Camera.cpp
        objects/Camera.hpp
        objects/Composite.cpp
        objects/Composite.hpp
        objects/Edge.cpp
        objects/InvisibleObject.cpp
        objects/InvisibleObject.hpp
        objects/ListModelStructure.cpp
        objects/ListModelStructure.hpp
        objects/MatrixModelStructure.cpp
        objects/MatrixModelStructure.hpp
        objects/ModelStructure.cpp
        objects/BaseObject.cpp
        objects/Vertex.cpp
        objects/VisibleObject.cpp
        loader/BaseLoader.cpp
        loader/BaseLoaderCreator.hpp
        loader/CarcassModelLoader.cpp
        loader/CarcassModelLoader.hpp
        loader/LoaderCreator.hpp
        loader/LoaderCreator.hpp
        loader/LoaderSolution.cpp
        loader/LoaderSolution.h
        loader/LoaderSolution.hpp
        loader/CsvModelLoader.cpp
        loader/CsvModelLoader.hpp
        loader/TxtModelLoader.cpp
        loader/TxtModelLoader.hpp
        scene/Scene.cpp
        scene/Scene.hpp
        transform_strategy/CameraProjectionAction.cpp
        transform_strategy/CameraProjectionAction.hpp
        transform_strategy/RotateAction.cpp
        transform_strategy/RotateAction.hpp
        transform_strategy/ScaleAction.cpp
        transform_strategy/ScaleAction.hpp
        transform_strategy/MoveAction.cpp
        transform_strategy/MoveAction.hpp
        transform_strategy/TransformAction.cpp
        visitor/DrawVisitor.cpp
        visitor/TransformVisitor.cpp
        main.cpp
        mainwindow.cpp
        mainwindow.hpp
)

# Альтернативно можно использовать явное перечисление, как у вас было,
# но GLOB_RECURSE удобнее для больших проектов

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

# Линковка с Qt и SQLite
target_link_libraries(lab_03 PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        ${SQLite3_LIBRARIES}  # Добавляем библиотеку SQLite
)

# Для macOS специфичные настройки
if (APPLE)
    if (${QT_VERSION} VERSION_LESS 6.1.0)
        set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab_03)
    endif ()

    set_target_properties(lab_03 PROPERTIES
            ${BUNDLE_ID_OPTION}
            MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
            MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
            MACOSX_BUNDLE TRUE
    )
endif ()

# Для Windows специфичные настройки
if (WIN32)
    set_target_properties(lab_03 PROPERTIES
            WIN32_EXECUTABLE TRUE
    )
endif ()

include(GNUInstallDirs)
install(TARGETS lab_03
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab_03)
endif ()