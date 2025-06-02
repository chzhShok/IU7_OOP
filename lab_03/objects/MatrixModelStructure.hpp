#pragma once

#include <vector>

#include "ModelStructure.hpp"
#include "Vertex.hpp"

class MatrixModelStructure : public ModelStructure {
public:
    MatrixModelStructure();
    ~MatrixModelStructure() = default;

    virtual void transform(const TransformAction &action);
    virtual std::vector<Vertex> getVertices() const;
    virtual std::vector<Edge> getEdges() const;
    virtual void addVertex(const Vertex &vertex);
    virtual void addEdge(const Edge &edge);
    virtual Vertex getCenter() const;
    virtual void setCenter(const Vertex &center);
    virtual std::shared_ptr<ModelStructure> clone() const;

private:
    Vertex __center;
    std::vector<Vertex> __vertices;
    Matrix<int> __edgeMatrix;
};
