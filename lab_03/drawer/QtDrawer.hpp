#pragma once

#include <QGraphicsScene>

#include "BaseDrawer.hpp"

class QtDrawer : public BaseDrawer {
public:
    QtDrawer() = delete;
    QtDrawer(QGraphicsScene *scene);
    virtual ~QtDrawer() = default;

    virtual void drawLine(const Vertex &p1, const Vertex &p2);
    virtual void clear();

private:
    QGraphicsScene *__scene;
};
