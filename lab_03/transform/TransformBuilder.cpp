#include "TransformBuilder.hpp"

Matrix<double> TransformBuilder::move(double dx, double dy, double dz) {
    Matrix<double> new_mtr = Matrix<double>(4, 4);

    Matrix<double> mtr = new_mtr.identity();
    mtr[0][3] = dx;
    mtr[1][3] = dy;
    mtr[2][3] = dz;

    return mtr;
}

Matrix<double> TransformBuilder::scale(double kx, double ky, double kz) {
    Matrix<double> new_mtr = Matrix<double>(4, 4);

    Matrix<double> mtr = new_mtr.identity();
    mtr[0][0] = kx;
    mtr[1][1] = ky;
    mtr[2][2] = kz;

    return mtr;
}

Matrix<double> TransformBuilder::rotate(double angleX, double angleY, double angleZ) {
    double cx = cos(angleX), sx = sin(angleX);
    double cy = cos(angleY), sy = sin(angleY);
    double cz = cos(angleZ), sz = sin(angleZ);

    Matrix<double> new_mtr = Matrix<double>(4, 4);

    Matrix<double> rotX = new_mtr.identity();
    rotX[1][1] = cx;
    rotX[1][2] = -sx;
    rotX[2][1] = sx;
    rotX[2][2] = cx;

    Matrix<double> rotY = new_mtr.identity();
    rotY[0][0] = cy;
    rotY[0][2] = sy;
    rotY[2][0] = -sy;
    rotY[2][2] = cy;

    Matrix<double> rotZ = new_mtr.identity();
    rotZ[0][0] = cz;
    rotZ[0][1] = -sz;
    rotZ[1][0] = sz;
    rotZ[1][1] = cz;

    return rotZ * rotY * rotX;
}
