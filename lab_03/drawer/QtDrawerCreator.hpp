#pragma once

#include "BaseDrawerCreator.hpp"
#include <QGraphicsScene>

class QtDrawerCreator : public BaseDrawerCreator {
public:
    QtDrawerCreator(QGraphicsScene *scene);
    QtDrawerCreator() = delete;
    ~QtDrawerCreator() = default;

    std::shared_ptr<BaseDrawer> create();

private:
    QGraphicsScene *_scene;
};
