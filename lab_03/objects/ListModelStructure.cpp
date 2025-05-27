#include "ListModelStructure.hpp"

ListModelStructure::ListModelStructure() : _center(Vertex()), _vertices(std::vector<Vertex>()), _edges(std::vector<Edge>()) {};

void ListModelStructure::transform(std::shared_ptr<TransformAction> action) {
    for (Vertex &vertex: _vertices) {
        action->transformPoint(vertex);
    }
    action->transformPoint(_center);
}

std::vector<Vertex> ListModelStructure::getVertices() const {
    return _vertices;
}

std::vector<Edge> ListModelStructure::getEdges() const {
    return _edges;
}

Vertex ListModelStructure::getCenter() const {
    Vertex copy(_center);
    return copy;
}

void ListModelStructure::setCenter(const Vertex &center) {
    _center = center;
}

void ListModelStructure::addVertex(const Vertex &vertex) {
    _vertices.push_back(vertex);
}

void ListModelStructure::addEdge(const Edge &edge) {
    _edges.push_back(edge);
}

std::shared_ptr<ModelStructure> ListModelStructure::clone() const {
    auto cloned = std::make_shared<ListModelStructure>();
    cloned->setCenter(_center);
    for (const Vertex &point: _vertices)
        cloned->addVertex(point);

    for (const Edge &edge: _edges)
        cloned->addEdge(edge);

    return cloned;
}
