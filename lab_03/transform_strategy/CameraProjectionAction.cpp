#include "CameraProjectionAction.hpp"
#include "Camera.hpp"
#include "MoveAction.hpp"

CameraProjectionAction::CameraProjectionAction(std::shared_ptr<Camera> camera) : TransformAction(), _camera(camera) {
    MoveAction toCenter(Vertex(-camera->_self.getX(), -camera->_self.getY(), -camera->_self.getZ()));
    Matrix<double> toCameraBasis(4);

    toCameraBasis[0][0] = camera->_normalRight.getX() - camera->_self.getX();
    toCameraBasis[1][0] = camera->_normalRight.getY() - camera->_self.getY();
    toCameraBasis[2][0] = camera->_normalRight.getZ() - camera->_self.getZ();
    toCameraBasis[3][0] = 0;

    toCameraBasis[0][1] = camera->_normalUp.getX() - camera->_self.getX();
    toCameraBasis[1][1] = camera->_normalUp.getY() - camera->_self.getY();
    toCameraBasis[2][1] = camera->_normalUp.getZ() - camera->_self.getZ();
    toCameraBasis[3][1] = 0;

    toCameraBasis[0][2] = camera->_normalForward.getX() - camera->_self.getX();
    toCameraBasis[1][2] = camera->_normalForward.getY() - camera->_self.getY();
    toCameraBasis[2][2] = camera->_normalForward.getZ() - camera->_self.getZ();
    toCameraBasis[3][2] = 0;
    toCameraBasis[3][3] = 1;

    _matrix *= toCenter.getMatrix();
    _matrix *= toCameraBasis;
}
