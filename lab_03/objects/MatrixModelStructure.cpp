#include <iostream>

#include "MatrixModelStructure.hpp"

MatrixModelStructure::MatrixModelStructure() : __center(Vertex()), __vertices(std::vector<Vertex>()), __edgeMatrix(Matrix<int>()) {};

void MatrixModelStructure::transform(const TransformAction &action) {
    for (Vertex &vertex: __vertices)
        action.transformVertex(vertex);

    action.transformVertex(__center);
}

std::vector<Vertex> MatrixModelStructure::getVertices() const {
    return __vertices;
}

std::vector<Edge> MatrixModelStructure::getEdges() const {
    std::vector<Edge> _edges;

    for (size_t i = 0; i < __edgeMatrix.size(); ++i)
        for (size_t j = i; j < __edgeMatrix[i].size(); ++j)
            if (__edgeMatrix[i][j])
                _edges.push_back(Edge(i, j));

    return _edges;
}

std::vector<Face> MatrixModelStructure::getFaces() const {
    return _faces;
}

Vertex MatrixModelStructure::getCenter() const {
    Vertex copy(__center);
    return copy;
}

void MatrixModelStructure::setCenter(const Vertex &center) {
    __center = center;
}

void MatrixModelStructure::addVertex(const Vertex &vertex) {
    __vertices.push_back(vertex);

    if (__edgeMatrix.size() == 0)
        __edgeMatrix = Matrix<int>(__vertices.size());
    else
        __edgeMatrix.resize(__vertices.size(), 0);
}

void MatrixModelStructure::addEdge(const Edge &edge) {
    if (edge.getFirst() >= __vertices.size() || edge.getSecond() >= __vertices.size()) {
        time_t now = time(nullptr);
        throw EdgeOutOfPointsException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    __edgeMatrix[edge.getFirst()][edge.getSecond()] = true;
    __edgeMatrix[edge.getSecond()][edge.getFirst()] = true;
}

void MatrixModelStructure::addFace(const Face &face) {
    _faces.push_back(face);
}

std::shared_ptr<ModelStructure> MatrixModelStructure::clone() const {
    auto cloned = std::make_shared<MatrixModelStructure>();
    cloned->setCenter(__center);
    cloned->__vertices = __vertices;

    cloned->__edgeMatrix = Matrix<int>(__vertices.size());

    for (size_t i = 0; i < __edgeMatrix.size(); ++i)
        for (size_t j = 0; j < __edgeMatrix[i].size(); ++j)
            cloned->__edgeMatrix[i][j] = __edgeMatrix[i][j];

    for (const Face& face : _faces)
        cloned->addFace(face);

    return cloned;
}
