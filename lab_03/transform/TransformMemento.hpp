#pragma once

#include <memory>

#include "Matrix.h"

class BaseObject;

class TransformMemento {
public:
    TransformMemento(std::shared_ptr<BaseObject> object, Matrix<double> matrix);

    std::shared_ptr<BaseObject> getObject() const;
    Matrix<double> getMatrix() const;

private:
    std::shared_ptr<BaseObject> __object;
    Matrix<double> __savedMatrix;
};
