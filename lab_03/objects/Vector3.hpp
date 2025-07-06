#pragma once

#include <cmath>

#include "Vertex.hpp"

class Vector3 {
public:
    Vector3();
    Vector3(double x, double y, double z);
    Vector3(const Vertex &p);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    Vector3 operator+(const Vector3 &other) const;
    Vector3 operator-(const Vector3 &other) const;
    Vector3 operator*(double scalar) const;
    Vector3 operator/(double scalar) const;
    Vector3 &operator+=(const Vector3 &other);

    double dot(const Vector3 &other) const;
    Vector3 cross(const Vector3 &other) const;
    double length() const;
    Vector3 normalize() const;
    Vertex toVertex() const;

private:
    double _x, _y, _z;
};
