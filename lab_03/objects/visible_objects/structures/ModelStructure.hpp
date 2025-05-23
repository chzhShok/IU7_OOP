#pragma once

#include <vector>

#include "Edge.hpp"
#include "Vertex.hpp"

class ModelStructure {
public:
    ModelStructure() = default;
    ModelStructure(const ModelStructure &other) = delete;
    ModelStructure(ModelStructure &&other) = delete;
    ~ModelStructure() = default;

    virtual const std::vector<Vertex> &getVertices() const = 0;
    virtual const std::vector<Edge> &getEdges() const = 0;
    virtual const Vertex &getCenter() const = 0;

    virtual void addVertex(const Vertex &vertex) = 0;
    virtual void addEdge(const Edge &edge) = 0;
    virtual void setCenter(const Vertex &center) = 0;

    virtual void transform() = 0;
};
