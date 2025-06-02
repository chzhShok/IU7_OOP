#include "TransformMemento.hpp"

TransformMemento::TransformMemento(std::shared_ptr<BaseObject> object, Matrix<double> matrix) : __object(object), __savedMatrix(std::move(matrix)) {}

std::shared_ptr<BaseObject> TransformMemento::getObject() const {
    return __object;
}

Matrix<double> TransformMemento::getMatrix() const {
    return __savedMatrix;
}
