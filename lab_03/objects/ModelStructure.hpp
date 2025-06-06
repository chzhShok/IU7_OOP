#pragma once

#include <memory>
#include <vector>
#include <set>

#include "Edge.hpp"
#include "TransformAction.hpp"
#include "Vertex.hpp"

using Face = std::set<int>;

class ModelStructure {
public:
    ModelStructure() = default;
    ModelStructure(const ModelStructure &other) = delete;
    ModelStructure(ModelStructure &&other) = delete;
    virtual ~ModelStructure() = 0;

    virtual void transform(const TransformAction &action) = 0;
    virtual std::vector<Vertex> getVertices() const = 0;
    virtual std::vector<Edge> getEdges() const = 0;
    virtual std::vector<Face> getFaces() const = 0;
    virtual void addVertex(const Vertex &vertex) = 0;
    virtual void addEdge(const Edge &edge) = 0;
    virtual void addFace(const Face& face) = 0;
    virtual Vertex getCenter() const = 0;
    virtual void setCenter(const Vertex &center) = 0;
    virtual std::shared_ptr<ModelStructure> clone() const = 0;
};
