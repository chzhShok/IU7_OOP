#include "Vertex.hpp"

Vertex::Vertex(double x, double y, double z) : _x(x), _y(y), _z(z) {};

Vertex::Vertex(double i, double j) : _x(i), _y(j), _z(0.0) {}

double Vertex::getX() const {
    return _x;
}

double Vertex::getY() const {
    return _y;
}

double Vertex::getZ() const {
    return _z;
}

void Vertex::setX(double x) {
    _x = x;
}

void Vertex::setY(double y) {
    _y = y;
}


void Vertex::setZ(double z) {
    _z = z;
}

void Vertex::set(const Vertex &p) {
    _x = p._x;
    _y = p._y;
    _z = p._z;
}

void Vertex::set(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

bool Vertex::isEqual(const Vertex &p) const {
    return _x == p._x && _y == p._y && _z == p._z;
}

bool Vertex::isNotEqual(const Vertex &p) const {
    return !isEqual(p);
}

bool Vertex::operator==(const Vertex &p) const {
    return isEqual(p);
}

bool Vertex::operator!=(const Vertex &p) const {
    return isNotEqual(p);
}
