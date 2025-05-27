#include "RotateAction.hpp"
#include "MoveAction.hpp"
#include <cmath>
#include <vector>

RotateAction::RotateAction(double ox, double oy, double oz) {
    Matrix<double> z(4);
    z[0][0] = cos(oz);
    z[0][1] = sin(oz);
    z[1][0] = -sin(oz);
    z[1][1] = cos(oz);
    z[2][2] = 1;
    z[3][3] = 1;

    Matrix<double> y(4);
    y[0][0] = cos(oy);
    y[0][2] = -sin(oy);
    y[1][1] = 1;
    y[2][0] = sin(oy);
    y[2][2] = cos(oy);
    y[3][3] = 1;

    Matrix<double> x(4);
    x[0][0] = 1;
    x[1][1] = cos(ox);
    x[1][2] = sin(ox);
    x[2][1] = -sin(ox);
    x[2][2] = cos(ox);
    x[3][3] = 1;

    _matrix *= x * y * z;
}

RotateAction::RotateAction(const Vertex &center, double ox, double oy, double oz) {
    MoveAction toCenter(Vertex(-center.getX(), -center.getY(), -center.getZ()));
    _matrix *= toCenter.getMatrix();
    RotateAction rotate(ox, oy, oz);
    _matrix *= rotate.getMatrix();
    MoveAction fromCenter(center);
    _matrix *= fromCenter.getMatrix();
}