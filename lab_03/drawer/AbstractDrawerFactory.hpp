#pragma once

#include "BaseDrawer.hpp"
#include <memory>

class AbstractDrawerFactory {
public:
    virtual std::unique_ptr<BaseDrawer> createDrawer() = 0;
};
