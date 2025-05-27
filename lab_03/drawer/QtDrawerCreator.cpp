#include "QtDrawerCreator.hpp"
#include "QtDrawer.hpp"
#include <iostream>

QtDrawerCreator::QtDrawerCreator(QGraphicsScene *scene) : _scene(scene) {}

std::shared_ptr<BaseDrawer> QtDrawerCreator::create() {
    return std::make_shared<QtDrawer>(_scene);
}
