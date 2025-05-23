#pragma once

#include <Matrix.h>

class TransformBuilder {
public:
    static Matrix<double> move(double dx, double dy, double dz);
    static Matrix<double> scale(double kx, double ky, double kz);
    static Matrix<double> rotate(double angleX, double angleY, double angleZ);
};
