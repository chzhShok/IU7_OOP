#pragma once

#include "AbstractDrawerFactory.hpp"
#include "QtDrawer.hpp"


class QtDrawerFactory : public AbstractDrawerFactory {
public:
    explicit QtDrawerFactory(QGraphicsScene *scene);

    std::unique_ptr<BaseDrawer> createDrawer() override;

private:
    QGraphicsScene *_scene;
};
