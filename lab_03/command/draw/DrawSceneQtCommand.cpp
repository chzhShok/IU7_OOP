#include "DrawSceneQtCommand.hpp"

DrawSceneQtCommand::DrawSceneQtCommand(QGraphicsScene *sceneQt) {
    _sceneQt = sceneQt;
}

void DrawSceneQtCommand::execute() {
    _drawManager->drawScene<QtDrawerCreator, QGraphicsScene *>(_sceneManager, _sceneQt);
}
