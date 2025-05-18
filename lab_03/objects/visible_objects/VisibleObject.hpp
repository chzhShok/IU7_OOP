#pragma once

#include "BaseObject.hpp"

class VisibleObject : public BaseObject {
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool isVisible() override { return true; }
    bool isComposite() override { return false; }
};
