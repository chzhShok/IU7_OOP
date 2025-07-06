#pragma once

#include <QGraphicsScene>

#include "BaseDrawerCreator.hpp"
#include "QtDrawer.hpp"

class QtDrawerCreator : public BaseDrawerCreator {
public:
    QtDrawerCreator(QGraphicsScene *scene);
    QtDrawerCreator() = delete;
    ~QtDrawerCreator() = default;

    std::shared_ptr<BaseDrawer> create();

private:
    QGraphicsScene *__scene;
};
