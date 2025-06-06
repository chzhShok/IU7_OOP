#pragma once

#include <memory>

#include "Matrix.h"
#include "ModelStructure.hpp"

class BaseObject;

class TransformMemento {
public:
    TransformMemento(std::shared_ptr<BaseObject> object, Matrix<double> matrix, std::shared_ptr<ModelStructure> modelState = nullptr);

    std::shared_ptr<BaseObject> getObject() const;
    Matrix<double> getMatrix() const;
    std::shared_ptr<ModelStructure> getModelState() const;

private:
    std::shared_ptr<BaseObject> __object;
    Matrix<double> __savedMatrix;
    std::shared_ptr<ModelStructure> __modelState;
};
