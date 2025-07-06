#pragma once

#include <vector>

#include "Edge.hpp"
#include "ModelStructure.hpp"
#include "TransformAction.hpp"
#include "Vertex.hpp"

class ListModelStructure : public ModelStructure {
public:
    ListModelStructure();
    ~ListModelStructure() = default;

    virtual void transform(const TransformAction &action);
    virtual std::vector<Vertex> getVertices() const;
    virtual std::vector<Edge> getEdges() const;
    virtual std::vector<Face> getFaces() const;
    virtual void addVertex(const Vertex &point);
    virtual void addEdge(const Edge &edge);
    virtual void addFace(const Face& face);
    virtual Vertex getCenter() const;
    virtual void setCenter(const Vertex &center);
    virtual std::shared_ptr<ModelStructure> clone() const;

protected:
    Vertex _center;
    std::vector<Vertex> _vertices;
    std::vector<Edge> _edges;
    std::vector<Face> _faces;
};
