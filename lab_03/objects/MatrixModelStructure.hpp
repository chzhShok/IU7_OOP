#pragma once

#include <vector>

#include "ModelStructure.hpp"
#include "Vertex.hpp"
#include "Exception.hpp"

class MatrixModelStructure : public ModelStructure {
public:
    MatrixModelStructure();

    ~MatrixModelStructure() = default;
    virtual void transform(std::shared_ptr<TransformAction> action);
    virtual std::vector<Vertex> getVertices() const;
    virtual std::vector<Edge> getEdges() const;
    virtual void addVertex(const Vertex &point);
    virtual void addEdge(const Edge &edge);
    virtual Vertex getCenter() const;
    virtual void setCenter(const Vertex &center);
    virtual std::shared_ptr<ModelStructure> clone() const;

private:
    Vertex _center;

    std::vector<Vertex> _vertices;
    Matrix<int> _edgeMatrix;
};
