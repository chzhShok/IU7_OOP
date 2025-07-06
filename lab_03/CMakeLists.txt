cmake_minimum_required(VERSION 3.16)

project(lab_03 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

find_package(nlohmann_json 3.11.2 REQUIRED)

# Включение всех заголовочных файлов через один вызов
include_directories(
        builder
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
        strategy
        transform
        visitor
        matrix
)

# Группировка исходных файлов
set(PROJECT_SOURCES
        builder/BaseCarcassModelBuilder.cpp
        builder/BaseCarcassModelBuilder.hpp
        builder/ListModelBuilder.cpp
        builder/ListModelBuilder.hpp
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
        command/load/JsonLoadCommandDecorator.cpp
        command/load/JsonLoadCommandDecorator.hpp
        command/load/TxtLoadCommandDecorator.cpp
        command/load/TxtLoadCommandDecorator.hpp
        command/object/BaseObjectCommand.cpp
        command/object/BaseObjectCommand.hpp
        command/object/CompositeObjectCommand.cpp
        command/object/CompositeObjectCommand.hpp
        command/object/GetObjectCommand.cpp
        command/object/GetObjectCommand.hpp
        command/object/MoveObjectCommand.cpp
        command/object/MoveObjectCommand.hpp
        command/object/RemoveObjectCommand.cpp
        command/object/RemoveObjectCommand.hpp
        command/object/RotateObjectCommand.cpp
        command/object/RotateObjectCommand.hpp
        command/object/ScaleObjectCommand.cpp
        command/object/ScaleObjectCommand.hpp
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
        director/DirectorSolution.hpp
        director/ListModelDirector.cpp
        director/ListModelDirector.hpp
        director/MatrixModelDirector.cpp
        director/MatrixModelDirector.hpp
        drawer/BaseDrawer.cpp
        drawer/BaseDrawerCreator.cpp
        drawer/QtDrawer.cpp
        drawer/QtDrawer.hpp
        drawer/QtDrawerCreator.cpp
        drawer/QtDrawerCreator.hpp
        exception/Exception.cpp
        exception/Exception.hpp
        facade/Facade.cpp
        facade/Facade.hpp
        loader/BaseLoader.cpp
        loader/BaseLoader.hpp
        loader/BaseLoaderCreator.hpp
        loader/CarcassModelLoader.cpp
        loader/CarcassModelLoader.hpp
        loader/LoaderCreator.h
        loader/LoaderCreator.hpp
        loader/LoaderSolution.cpp
        loader/LoaderSolution.hpp
        loader/JsonModelLoader.cpp
        loader/JsonModelLoader.hpp
        loader/TxtModelLoader.cpp
        loader/TxtModelLoader.hpp
        manager/LoadManager.cpp
        manager/LoadManager.hpp
        manager/SceneManager.cpp
        manager/SceneManager.hpp
        manager/TransformManager.cpp
        manager/TransformManager.hpp
        matrix/Matrix.h
        matrix/Matrix.hpp
        matrix/MatrixRow.hpp
        objects/BaseModel.cpp
        objects/BaseModel.hpp
        objects/BaseObject.cpp
        objects/BaseObject.hpp
        objects/CarcassModel.cpp
        objects/CarcassModel.hpp
        objects/Camera.cpp
        objects/Camera.hpp
        objects/Composite.cpp
        objects/Composite.hpp
        objects/Edge.cpp
        objects/Edge.hpp
        objects/InvisibleObject.cpp
        objects/InvisibleObject.hpp
        objects/ListModelStructure.cpp
        objects/ListModelStructure.hpp
        objects/MatrixModelStructure.cpp
        objects/MatrixModelStructure.hpp
        objects/ModelStructure.cpp
        objects/ModelStructure.hpp
        objects/Vertex.cpp
        objects/VisibleObject.cpp
        objects/VisibleObject.hpp
        scene/Scene.cpp
        scene/Scene.hpp
        strategy/CenterStrategy.cpp
        strategy/CenterStrategy.hpp
        transform/CameraProjectionAction.cpp
        transform/MoveAction.cpp
        transform/MoveAction.hpp
        transform/RotateAction.cpp
        transform/RotateAction.hpp
        transform/ScaleAction.cpp
        transform/ScaleAction.hpp
        transform/TransformAction.cpp
        transform/TransformCaretaker.cpp
        transform/TransformMemento.cpp
        visitor/DrawVisitor.cpp
        main.cpp
        mainwindow.cpp
        mainwindow.hpp
        strategy/BaseCenterStrategy.hpp
        strategy/BaseCenterStrategy.cpp
        manager/DrawManager.cpp
        command/draw/SwapEdgesVisibility.cpp
        objects/FaceBuilder.cpp
        objects/Vector3.cpp
        command/camera/MoveCameraCommand.cpp
        command/camera/MoveCameraCommand.hpp
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
        Qt${QT_VERSION_MAJOR}::Sql
        nlohmann_json::nlohmann_json
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