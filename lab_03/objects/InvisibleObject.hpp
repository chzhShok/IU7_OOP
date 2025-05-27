#pragma once

#include "BaseObject.hpp"

class InvisibleObject : public BaseObject {
public:
    InvisibleObject();
    virtual ~InvisibleObject() = 0;

    virtual bool isVisible() const;
    virtual bool isComposite() const;
};
