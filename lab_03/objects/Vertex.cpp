#include "Vertex.hpp"

Vertex::Vertex(double x, double y, double z) : __x(x), __y(y), __z(z) {};


double Vertex::getX() const {
    return __x;
}

double Vertex::getY() const {
    return __y;
}

double Vertex::getZ() const {
    return __z;
}

void Vertex::setX(double x) {
    __x = x;
}

void Vertex::setY(double y) {
    __y = y;
}


void Vertex::setZ(double z) {
    __z = z;
}

void Vertex::set(const Vertex &p) {
    __x = p.__x;
    __y = p.__y;
    __z = p.__z;
}

void Vertex::set(double x, double y, double z) {
    __x = x;
    __y = y;
    __z = z;
}

bool Vertex::isEqual(const Vertex &p) const {
    return __x == p.__x && __y == p.__y && __z == p.__z;
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
