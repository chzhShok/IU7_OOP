#include <vector>

#include "TransformAction.hpp"

TransformAction::TransformAction() : _matrix(Matrix<double>(4)) {
    _matrix[0][0] = 1;
    _matrix[1][1] = 1;
    _matrix[2][2] = 1;
    _matrix[3][3] = 1;
}

Vertex &TransformAction::transformVertex(Vertex &p) const {
    std::vector<double> pvector = {p.getX(), p.getY(), p.getZ(), 1};
    std::vector<double> result = _matrix.multiplyLeft(pvector);

    p.setX(result[0]);
    p.setY(result[1]);
    p.setZ(result[2]);

    return p;
}

Matrix<double> TransformAction::getMatrix() const {
    return _matrix;
}
