#include "CenterStrategy.hpp"

Vertex CenterStrategy::CenterAlgorithm(std::vector<Vertex> vertices) const {
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
