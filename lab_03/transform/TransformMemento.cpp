#include "TransformMemento.hpp"

TransformMemento::TransformMemento(std::shared_ptr<BaseObject> object, Matrix<double> matrix, std::shared_ptr<ModelStructure> modelState)
    : __object(object), __savedMatrix(std::move(matrix)), __modelState(modelState) {}

std::shared_ptr<BaseObject> TransformMemento::getObject() const {
    return __object;
}

Matrix<double> TransformMemento::getMatrix() const {
    return __savedMatrix;
}

std::shared_ptr<ModelStructure> TransformMemento::getModelState() const {
    return __modelState;
}
