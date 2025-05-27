#include "Camera.hpp"

Camera::Camera() : _self(Vertex(0, 0, -10)), _normalForward(Vertex(0, 0, 1)), _normalUp(Vertex(0, 1, 0)), _normalRight(Vertex(1, 0, 0)) {}

Camera::Camera(const Vertex &self) : _self(self), _normalForward(Vertex(0, 0, 1)), _normalUp(Vertex(0, 1, 0)), _normalRight(Vertex(1, 0, 0)) {}

Camera::Camera(const Camera &other) : _self(other._self), _normalForward(Vertex(0, 0, 1)), _normalUp(Vertex(0, 1, 0)), _normalRight(Vertex(1, 0, 0)) {}

Camera::Camera(double x, double y, double z) : _self(Vertex(x, y, z)), _normalForward(Vertex(0, 0, 1)), _normalUp(Vertex(0, 1, 0)), _normalRight(Vertex(1, 0, 0)) {}

void Camera::accept(std::shared_ptr<Visitor> v) {
    v->visit(*this);
}

bool Camera::isComposite() const {
    return false;
}

Vertex Camera::getCenter() const {
    Vertex copy(_self);
    return copy;
}
