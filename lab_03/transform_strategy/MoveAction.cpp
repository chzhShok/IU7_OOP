#include "MoveAction.hpp"

MoveAction::MoveAction(double x, double y, double z) {
    _matrix[0][0] = 1.;
    _matrix[1][1] = 1.;
    _matrix[2][2] = 1.;
    _matrix[3][0] = x;
    _matrix[3][1] = y;
    _matrix[3][2] = z;
    _matrix[3][3] = 1.0;
}

MoveAction::MoveAction(double x, double y, double z, double w) {
    _matrix[0][0] = 1.;
    _matrix[1][1] = 1.;
    _matrix[2][2] = 1.;
    _matrix[3][0] = x;
    _matrix[3][1] = y;
    _matrix[3][2] = z;
    _matrix[3][3] = w;
}

MoveAction::MoveAction(const Vertex &p) {
    _matrix[0][0] = 1.;
    _matrix[1][1] = 1.;
    _matrix[2][2] = 1.;
    _matrix[3][0] = p.getX();
    _matrix[3][1] = p.getY();
    _matrix[3][2] = p.getZ();
    _matrix[3][3] = 1.0;
}