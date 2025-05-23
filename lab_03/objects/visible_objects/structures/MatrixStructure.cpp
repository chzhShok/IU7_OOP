#include "MatrixStructure.hpp"

MatrixStructure::MatrixStructure() : _center(Vertex()), _vertices(std::vector<Vertex>()), _edgeMatrix(Matrix<int>()) {};

void MatrixStructure::transform() {
}

const std::vector<Vertex> &MatrixStructure::getVertices() const {
    return _vertices;
}

const std::vector<Edge> &MatrixStructure::getEdges() const {
    std::vector<Edge> _edges;

    for (size_t i = 0; i < _edgeMatrix.getRows(); ++i)
        for (auto it = _edgeMatrix[i].cbegin() + i; it != _edgeMatrix[i].cend(); ++it)
            if (*it)
                _edges.push_back(Vertex(i, std::distance(_edgeMatrix[i].cbegin(), it)));

    return _edges;
}

const Vertex &MatrixStructure::getCenter() const {
    Vertex copy(_center);
    return copy;
}

void MatrixStructure::setCenter(const Vertex &center) {
    _center = center;
}

void MatrixStructure::addVertex(const Vertex &point) {
    _vertices.push_back(point);
    _edgeMatrix.resize(_vertices.size(), false);
}

void MatrixStructure::addEdge(const Edge &edge) {
    if (edge.getFirst() >= _vertices.size() || edge.getSecond() >= _vertices.size()) {
        time_t now = time(nullptr);
        throw EdgeOutOfPointsException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    *(_edgeMatrix[edge.getFirst()].begin() + edge.getSecond()) = true;
    *(_edgeMatrix[edge.getSecond()].begin() + edge.getFirst()) = true;
}
