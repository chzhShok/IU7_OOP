#include <iostream>

#include "DrawSceneQtCommand.hpp"
#include "QtDrawerCreator.hpp"

DrawSceneQtCommand::DrawSceneQtCommand(QGraphicsScene *sceneQt) {
    __sceneQt = sceneQt;
}

void DrawSceneQtCommand::execute() {
    auto camera = _sceneManager->getMainCamera();
    auto scene = _sceneManager->getScene();
    _drawManager->drawScene<QtDrawerCreator, QGraphicsScene *>(scene, camera, __sceneQt);
}
