#pragma once

#include <QGraphicsScene>

#include "BaseDrawCommand.hpp"

class DrawSceneQtCommand : public BaseDrawCommand {
public:
    DrawSceneQtCommand() = delete;
    virtual ~DrawSceneQtCommand() = default;
    DrawSceneQtCommand(QGraphicsScene *sceneQt);

    virtual void execute();

private:
    QGraphicsScene *__sceneQt;
};
