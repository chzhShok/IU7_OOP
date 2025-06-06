#include <cmath>

#include "Vector3.hpp"

Vector3::Vector3() : _x(0), _y(0), _z(0) {}

Vector3::Vector3(double x, double y, double z) : _x(x), _y(y), _z(z) {}

Vector3::Vector3(const Vertex &p) : _x(p.getX()), _y(p.getY()), _z(p.getZ()) {}

double Vector3::getX() const {
    return _x;
}

double Vector3::getY() const {
    return _y;
}

double Vector3::getZ() const {
    return _z;
}

void Vector3::setX(double x) {
    _x = x;
}

void Vector3::setY(double y) {
    _y = y;
}

void Vector3::setZ(double z) {
    _z = z;
}

Vector3 Vector3::operator+(const Vector3 &other) const {
    return Vector3(_x + other._x, _y + other._y, _z + other._z);
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    return Vector3(_x - other._x, _y - other._y, _z - other._z);
}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3(_x * scalar, _y * scalar, _z * scalar);
}

Vector3 Vector3::operator/(double scalar) const {
    return Vector3(_x / scalar, _y / scalar, _z / scalar);
}

Vector3 &Vector3::operator+=(const Vector3 &other) {
    _x += other._x;
    _y += other._y;
    _z += other._z;

    return *this;
}

double Vector3::dot(const Vector3 &other) const {
    return _x * other._x + _y * other._y + _z * other._z;
}

Vector3 Vector3::cross(const Vector3 &other) const {
    return Vector3(
            _y * other._z - _z * other._y,
            _z * other._x - _x * other._z,
            _x * other._y - _y * other._x);
}

double Vector3::length() const {
    return std::sqrt(_x * _x + _y * _y + _z * _z);
}

Vector3 Vector3::normalize() const {
    double len = length();
    if (len > 0)
        return *this / len;

    return Vector3();
}

Vertex Vector3::toVertex() const {
    return Vertex(_x, _y, _z);
}
