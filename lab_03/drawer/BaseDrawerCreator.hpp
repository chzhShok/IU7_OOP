#pragma once
#include "BaseDrawer.hpp"
#include <memory>

class BaseDrawerCreator {
public:
    BaseDrawerCreator() = default;
    virtual ~BaseDrawerCreator() = 0;

    virtual std::shared_ptr<BaseDrawer> create() = 0;
};
