#pragma once

#include "ModelStructure.hpp"
#include "SquareMatrix.hpp"

class MatrixStructure : public ModelStructure {
public:
    MatrixStructure();
    ~MatrixStructure() = default;

    const std::vector<Vertex> &getVertices() const override;
    const std::vector<Edge> &getEdges() const override;
    const Vertex getCenter() const override;

    void addVertex(const Vertex &vertex) override;
    void addEdge(const Edge &edge) override;
    void setCenter(const Vertex &center) override;

    void transform();

private:
    Vertex _center;

    std::vector<Vertex> _vertices;
    SquareMatrix<int> _edgeMatrix;
};