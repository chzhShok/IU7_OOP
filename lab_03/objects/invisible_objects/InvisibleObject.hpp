#pragma once

#include "BaseObject.hpp"

class InvisibleObject : public BaseObject {
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    bool isVisible() override { return false; }
    bool isComposite() override { return false; }
};
