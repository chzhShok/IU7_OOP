#include "LinkDotStructure.hpp"

LinkDotStructure::LinkDotStructure() : _center(Vertex()), _vertices(std::vector<Vertex>()), _edges(std::vector<Edge>()) {};

void LinkDotStructure::transform() {
}

const std::vector<Vertex> &LinkDotStructure::getVertices() const {
    return _vertices;
}

const std::vector<Edge> &LinkDotStructure::getEdges() const {
    return _edges;
}

const Vertex &LinkDotStructure::getCenter() const {
    Vertex copy(_center);
    return copy;
}

void LinkDotStructure::setCenter(const Vertex &center) {
    _center = center;
}

void LinkDotStructure::addVertex(const Vertex &vertex) {
    _vertices.push_back(vertex);
}

void LinkDotStructure::addEdge(const Edge &edge) {
    _edges.push_back(edge);
}
