#include "CameraProjectionAction.hpp"

CameraProjectionAction::CameraProjectionAction(std::shared_ptr<Camera> camera) : TransformAction(), __camera(camera) {
    MoveAction toCenter(Vertex(-camera->_self.getX(), -camera->_self.getY(), -camera->_self.getZ()));

    Matrix<double> toCameraBasis(4);

    toCameraBasis[0][0] = camera->_normalRight.getX();
    toCameraBasis[1][0] = camera->_normalRight.getY();
    toCameraBasis[2][0] = camera->_normalRight.getZ();
    toCameraBasis[3][0] = 0;

    toCameraBasis[0][1] = camera->_normalUp.getX();
    toCameraBasis[1][1] = camera->_normalUp.getY();
    toCameraBasis[2][1] = camera->_normalUp.getZ();
    toCameraBasis[3][1] = 0;

    toCameraBasis[0][2] = camera->_normalForward.getX();
    toCameraBasis[1][2] = camera->_normalForward.getY();
    toCameraBasis[2][2] = camera->_normalForward.getZ();
    toCameraBasis[3][2] = 0;

    toCameraBasis[0][3] = 0;
    toCameraBasis[1][3] = 0;
    toCameraBasis[2][3] = 0;
    toCameraBasis[3][3] = 1;

    _matrix = toCameraBasis * toCenter.getMatrix();
}
