#pragma once

#include <memory>

#include "BaseDrawer.hpp"

class BaseDrawerCreator {
public:
    BaseDrawerCreator() = default;
    virtual ~BaseDrawerCreator() = 0;

    virtual std::shared_ptr<BaseDrawer> create() = 0;
};
