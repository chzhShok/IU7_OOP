#include "TransformAction.hpp"
#include <vector>

TransformAction::TransformAction() : _matrix(Matrix<double>(4)) {
    _matrix[0][0] = 1;
    _matrix[1][1] = 1;
    _matrix[2][2] = 1;
    _matrix[3][3] = 1;
}

Vertex &TransformAction::transformPoint(Vertex &p) const {
    std::vector<double> pvector = {p.getX(), p.getY(), p.getZ(), 1};
    std::vector<double> result = _matrix.multiplyRight(pvector);
    if (result[3] == 0) {
        p.setX(0);
        p.setY(0);
        p.setZ(0);
    } else {
        p.setX(result[0] / result[3]);
        p.setY(result[1] / result[3]);
        p.setZ(result[2] / result[3]);
    }

    return p;
}

const Matrix<double> &TransformAction::getMatrix() const {
    return _matrix;
}

Matrix<double> &TransformAction::getMatrix() {
    return _matrix;
}
