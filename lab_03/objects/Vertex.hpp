#pragma once

#include <vector>

class Vertex {
public:
    Vertex() = default;
    Vertex(double x, double y, double z);

    explicit Vertex(const Vertex &p) = default;
    Vertex(Vertex &&p) noexcept = default;

    Vertex &operator=(const Vertex &p) = default;
    Vertex &operator=(Vertex &&p) noexcept = default;

    ~Vertex() = default;

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void set(const Vertex &p);
    void set(double x, double y, double z);

    bool operator==(const Vertex &p) const;
    bool operator!=(const Vertex &p) const;
    bool isEqual(const Vertex &p) const;
    bool isNotEqual(const Vertex &p) const;

    static Vertex findCenter(std::vector<Vertex> vertices);
private:
    double _x, _y, _z;
};
