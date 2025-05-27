#include "Vertex.hpp"


Vertex::Vertex(double x, double y, double z) : _x(x), _y(y), _z(z) {};

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

Vertex Vertex::findCenter(std::vector<Vertex> vertices) {
    if (vertices.empty())
        return Vertex();

    double minX = vertices[0].getX(), minY = vertices[0].getY(), minZ = vertices[0].getZ();
    double maxX = vertices[0].getX(), maxY = vertices[0].getY(), maxZ = vertices[0].getZ();

    for (auto &p: vertices) {
        if (minX > p.getX())
            minX = p.getX();
        if (minY > p.getY())
            minY = p.getY();
        if (minZ > p.getZ())
            minZ = p.getZ();
        if (maxX < p.getX())
            maxX = p.getX();
        if (maxY < p.getY())
            maxY = p.getY();
        if (maxZ < p.getZ())
            maxZ = p.getZ();
    }

    return Vertex((minX + maxX) / 2, (minY + maxY) / 2, (maxZ + minZ) / 2);
}
