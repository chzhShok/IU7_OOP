#include "Composite.hpp"

Composite::Composite(std::shared_ptr<BaseObject> &object) {
    _objects.push_back(object);
}


Composite::Composite(const std::vector<std::shared_ptr<BaseObject>> &vector) {
    _objects = vector;
}


void Composite::add(const std::shared_ptr<BaseObject> &object) {
    _objects.push_back(object);
}


void Composite::remove(const iterator &iterator) {
    _objects.erase(iterator);
}

bool Composite::isVisible() {
    return false;
}

bool Composite::isComposite() {
    return true;
}

Vertex Composite::getCenter() const {
    Vertex center = Vertex(0, 0, 0);
    size_t count = 0;

    for (const auto &element: _objects) {
        center = center + element->getCenter();
        count++;
    }

    center = Vertex(center.getX() / count,
                    center.getY() / count,
                    center.getZ() / count);
}

void Composite::transform() {
}

BaseObject::iterator Composite::begin() {
    return _objects.begin();
}


BaseObject::iterator Composite::end() {
    return _objects.end();
}
