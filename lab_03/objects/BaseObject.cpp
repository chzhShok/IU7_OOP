#include "BaseObject.hpp"

static std::size_t counter = 0;

std::size_t getNextId() {
    return counter++;
}

BaseObject::BaseObject() : _transformMatrix(Matrix<double>(4)) {
    _id = getNextId();
    _transformMatrix[0][0] = 1;
    _transformMatrix[1][1] = 1;
    _transformMatrix[2][2] = 1;
    _transformMatrix[3][3] = 1;
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

void BaseObject::accept(const Visitor &visitor) {
    (void) visitor;
}

std::shared_ptr<BaseObject> BaseObject::clone() const {
    return nullptr;
}

std::size_t BaseObject::getId() const {
    return _id;
}

void BaseObject::transform(const TransformAction &action) {
    _transformMatrix = _transformMatrix * action.getMatrix();
}

Matrix<double> BaseObject::getTransformMatrix() const {
    return _transformMatrix;
}

void BaseObject::setTransformMatrix(const Matrix<double> &matrix) {
    _transformMatrix = matrix;
}
