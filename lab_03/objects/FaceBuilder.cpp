#include <algorithm>
#include <cmath>

#include "FaceBuilder.hpp"

std::vector<Face> FaceBuilder::buildFacesFromEdges(const std::vector<Vertex> &vertices, const std::vector<Edge> &edges) {
    std::vector<Face> faces;
    std::map<int, std::set<int>> adjacencyList;

    for (const auto &edge: edges) {
        int u = edge.getFirst();
        int v = edge.getSecond();
        adjacencyList[u].insert(v);
        adjacencyList[v].insert(u);
    }

    int count = 0;
    for (const auto &v1: vertices) {
        for (const auto &[v2, neighbours]: adjacencyList) {
            if (neighbours.size() < 2)
                continue;

            Vertex vertex1(vertices[v2]);

            auto it1 = neighbours.begin();
            for (; it1 != neighbours.end(); ++it1) {
                auto it2 = std::next(it1);
                for (; it2 != neighbours.end(); ++it2) {
                    int element_1 = *it1;
                    int element_2 = *it2;

                    Vertex vertex2(vertices[element_1]);
                    Vertex vertex3(vertices[element_2]);

                    if (isPointOnPlane(v1, vertex1, vertex2, vertex3)) {
                        bool added = false;
                        for (auto &surface: faces) {
                            if (surface.count(element_1) > 0 && surface.count(element_2) > 0 && surface.count(v2) > 0) {
                                surface.insert(count);
                                added = true;
                                break;
                            }
                        }

                        if (!added) {
                            Face newSurface = {element_1, element_2, v2, count};
                            faces.push_back(newSurface);
                        }
                    }
                }
            }
        }
        count++;
    }

    removeDuplicateFaces(faces);
    return faces;
}

bool FaceBuilder::isPointOnPlane(const Vertex &p, const Vertex &p1, const Vertex &p2, const Vertex &p3) {
    Vertex v4 = Vertex(p.getX() - p1.getX(), p.getY() - p1.getY(), p.getZ() - p1.getZ());

    Vertex v2_v1 = Vertex(p2.getX() - p1.getX(), p2.getY() - p1.getY(), p2.getZ() - p1.getZ());
    Vertex v3_v1 = Vertex(p3.getX() - p1.getX(), p3.getY() - p1.getY(), p3.getZ() - p1.getZ());

    double x1 = v2_v1.getY() * v3_v1.getZ() - v2_v1.getZ() * v3_v1.getY();
    double y1 = v2_v1.getZ() * v3_v1.getX() - v2_v1.getX() * v3_v1.getZ();
    double z1 = v2_v1.getX() * v3_v1.getY() - v2_v1.getY() * v3_v1.getX();

    double dotProduct = x1 * v4.getX() + y1 * v4.getY() + z1 * v4.getZ();

    return std::abs(dotProduct) < 1e-9;
}

void FaceBuilder::removeDuplicateFaces(std::vector<Face> &faces) {
    std::sort(faces.begin(), faces.end());
    faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
}
