#include "MatrixModelStructure.hpp"
#include <iostream>

MatrixModelStructure::MatrixModelStructure() : _center(Vertex()), _vertices(std::vector<Vertex>()), _edgeMatrix(Matrix<int>()) {};

void MatrixModelStructure::transform(std::shared_ptr<TransformAction> action) {
    for (Vertex &vertex: _vertices) {
        action->transformPoint(vertex);
    }
    action->transformPoint(_center);
}

std::vector<Vertex> MatrixModelStructure::getVertices() const {
    return _vertices;
}

std::vector<Edge> MatrixModelStructure::getEdges() const {
    std::vector<Edge> _edges;

    for (size_t i = 0; i < _edgeMatrix.getSize(); ++i)
        for (auto it = _edgeMatrix[i].begin() + i; it != _edgeMatrix[i].end(); ++it)
            if (*it)
                _edges.push_back(Edge(i, std::distance(_edgeMatrix[i].begin(), it)));

    return _edges;
}

Vertex MatrixModelStructure::getCenter() const {
    Vertex copy(_center);
    return copy;
}

void MatrixModelStructure::setCenter(const Vertex &center) {
    _center = center;
}

void MatrixModelStructure::addVertex(const Vertex &vertex) {
    _vertices.push_back(vertex);
    _edgeMatrix.resize(_vertices.size(), false);
}

void MatrixModelStructure::addEdge(const Edge &edge) {
    if (edge.getFirst() >= _vertices.size() || edge.getSecond() >= _vertices.size()) {
        time_t now = time(nullptr);
        throw EdgeOutOfPointsException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    *(_edgeMatrix[edge.getFirst()].begin() + edge.getSecond()) = true;
    *(_edgeMatrix[edge.getSecond()].begin() + edge.getFirst()) = true;
}

std::shared_ptr<ModelStructure> MatrixModelStructure::clone() const {
    auto cloned = std::make_shared<MatrixModelStructure>();
    cloned->setCenter(_center);
    for (const Vertex &vertex: _vertices)
        cloned->addVertex(vertex);

    cloned->_edgeMatrix = _edgeMatrix;
    std::cout << "Cloned" << std::endl;

    return cloned;
}
