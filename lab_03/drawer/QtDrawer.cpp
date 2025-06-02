#include "QtDrawer.hpp"

QtDrawer::QtDrawer(QGraphicsScene *scene) : __scene(scene) {}

void QtDrawer::drawLine(const Vertex &p1, const Vertex &p2) {
    QPen pen(Qt::white);
    __scene->addLine(p1.getX(), p1.getY(), p2.getX(), p2.getY(), pen);
}

void QtDrawer::clear() {
    __scene->clear();
}
