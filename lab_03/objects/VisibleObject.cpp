#include "VisibleObject.hpp"

VisibleObject::VisibleObject() {}

VisibleObject::~VisibleObject() {}

bool VisibleObject::isVisible() const {
    return true;
}

bool VisibleObject::isComposite() const {
    return false;
}
