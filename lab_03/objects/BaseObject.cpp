#include "BaseObject.hpp"
#include "Visitor.hpp"

std::size_t GetNextId() {
    static std::size_t id = 0;
    return id++;
}

BaseObject::BaseObject() : _id(GetNextId()) {}

BaseObject::~BaseObject() {}


std::size_t BaseObject::getId() const {
    return _id;
}

void BaseObject::add(std::shared_ptr<BaseObject> obj) {
    (void) obj;
}

void BaseObject::remove(const iterator &it) {
    (void) it;
}

BaseObject::iterator BaseObject::begin() {
    return iterator();
}

BaseObject::iterator BaseObject::end() {
    return iterator();
}

void BaseObject::accept(std::shared_ptr<Visitor> v) {
    (void) v;
}

std::shared_ptr<BaseObject> BaseObject::clone() const {
    return nullptr;
}

Vertex BaseObject::getCenter() const {
    return Vertex();
}

bool BaseObject::isComposite() const {
    return false;
}
