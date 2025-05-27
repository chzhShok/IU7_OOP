#pragma once

#include "BaseDrawer.hpp"
#include <QGraphicsScene>

class QtDrawer : public BaseDrawer {
public:
    QtDrawer() = delete;
    QtDrawer(QGraphicsScene *scene);
    virtual ~QtDrawer() = default;
    virtual void drawLine(const Vertex &p1, const Vertex &p2);
    virtual void clear();

private:
    QGraphicsScene *_scene;
};
