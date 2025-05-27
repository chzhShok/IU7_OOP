#include "Composite.hpp"

Composite::Composite(std::vector<std::shared_ptr<BaseObject>> vec) : _objects(vec) {}

void Composite::add(std::shared_ptr<BaseObject> obj) {
    _objects.push_back(obj);
}

void Composite::remove(const iterator &it) {
    _objects.erase(it);
}

std::shared_ptr<BaseObject> Composite::clone() const {
    std::shared_ptr<Composite> copy = std::make_shared<Composite>();
    for (auto &obj: _objects)
        copy->add(obj->clone());

    return copy;
}

void Composite::accept(std::shared_ptr<Visitor> v) {
    for (auto &elem: _objects)
        elem->accept(v);
}

Composite::iterator Composite::begin() {
    return _objects.begin();
}

Composite::iterator Composite::end() {
    return _objects.end();
}

bool Composite::isComposite() const {
    return true;
}

bool Composite::isVisible() const {
    return true;
}

Vertex Composite::getCenter() const {
    std::vector<Vertex> centers;
    for (auto &obj: _objects)
        centers.push_back(obj->getCenter());

    return Vertex::findCenter(centers);
}
