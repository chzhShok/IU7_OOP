#pragma once

#include "Vertex.hpp"
#include "Matrix.h"

class TransformAction {
public:
    TransformAction();
    virtual ~TransformAction() = default;

    Vertex &transformVertex(Vertex &p) const;
    Matrix<double> getMatrix() const;

protected:
    Matrix<double> _matrix;
};
