#include "InvisibleObject.hpp"

InvisibleObject::InvisibleObject() {}

InvisibleObject::~InvisibleObject() {}

bool InvisibleObject::isVisible() const {
    return false;
}

bool InvisibleObject::isComposite() const {
    return false;
}
