#pragma once

#include "AbstractDrawerFactory.hpp"
#include "QtDrawerFactory.hpp"

template<typename Tfactory, typename Tscene>
class DrawerFactorySolution {
public:
    std::unique_ptr<BaseDrawer> createDrawer(Tscene *scene);
};
