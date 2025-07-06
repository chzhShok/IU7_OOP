#pragma once

#include <map>
#include <set>
#include <vector>

#include "Edge.hpp"
#include "ModelStructure.hpp"
#include "Vertex.hpp"

class FaceBuilder {
public:
    FaceBuilder() = default;
    static std::vector<Face> buildFacesFromEdges(const std::vector<Vertex> &vertices, const std::vector<Edge> &edges);

private:
    static bool isPointOnPlane(const Vertex &p, const Vertex &p1, const Vertex &p2, const Vertex &p3);
    static void removeDuplicateFaces(std::vector<Face> &faces);
};
