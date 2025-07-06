#include "Camera.hpp"
#include "Visitor.hpp"

Camera::Camera() : _self(Vertex(0, 0, -500)), _normalForward(Vertex(0, 0, 1)), _normalUp(Vertex(0, 1, 0)), _normalRight(Vertex(1, 0, 0)) {}

Camera::Camera(const Vertex &self) : _self(self), _normalForward(Vertex(0, 0, 1)), _normalUp(Vertex(0, 1, 0)), _normalRight(Vertex(1, 0, 0)) {}

Camera::Camera(const Camera &other) : _self(other._self), _normalForward(Vertex(0, 0, 1)), _normalUp(Vertex(0, 1, 0)), _normalRight(Vertex(1, 0, 0)) {}

Camera::Camera(double x, double y, double z) : _self(Vertex(x, y, z)), _normalForward(Vertex(0, 0, 1)), _normalUp(Vertex(0, 1, 0)), _normalRight(Vertex(1, 0, 0)) {}

void Camera::accept(const Visitor &v) {
    v.visit(*this);
}

void Camera::transform(const TransformAction &action) {
    _self = action.transformVertex(_self);
    _normalForward = action.transformVertex(_normalForward);
    _normalUp = action.transformVertex(_normalUp);
    _normalRight = action.transformVertex(_normalRight);
}

bool Camera::isComposite() const {
    return false;
}

Vertex Camera::getCenter() const {
    Vertex copy(_self);
    return copy;
}

std::shared_ptr<BaseObject> Camera::clone() const {
    return std::make_shared<Camera>(*this);
}
