#include <memory>

#include "QtDrawerCreator.hpp"

QtDrawerCreator::QtDrawerCreator(QGraphicsScene *scene) : __scene(scene) {}

std::shared_ptr<BaseDrawer> QtDrawerCreator::create() {
    return std::make_shared<QtDrawer>(__scene);
}
