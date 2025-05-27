#pragma once

#include "BaseObject.hpp"

class VisibleObject : public BaseObject {
public:
    VisibleObject();
    virtual ~VisibleObject() = 0;

    virtual bool isVisible() const;
    virtual bool isComposite() const;
};
