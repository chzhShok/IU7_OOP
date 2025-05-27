#pragma once

#include "Matrix.h"
#include "Vertex.hpp"

class TransformAction {
public:
    TransformAction();

    virtual ~TransformAction() = default;

    Vertex &transformPoint(Vertex &p) const;
    const Matrix<double> &getMatrix() const;
    Matrix<double> &getMatrix();

protected:
    Matrix<double> _matrix;
};
