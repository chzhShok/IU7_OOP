#include "QtDrawer.hpp"
#include <iostream>

QtDrawer::QtDrawer(QGraphicsScene *scene) : _scene(scene) {}

void QtDrawer::drawLine(const Vertex &p1, const Vertex &p2) {
    _scene->addLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

void QtDrawer::clear() {
    _scene->clear();
}
