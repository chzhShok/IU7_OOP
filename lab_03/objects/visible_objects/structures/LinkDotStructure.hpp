#pragma once

#include "ModelStructure.hpp"

class LinkDotStructure : public ModelStructure {
public:
    LinkDotStructure();
    ~LinkDotStructure() = default;

    const std::vector<Vertex> &getVertices() const override;
    const std::vector<Edge> &getEdges() const override;
    const Vertex &getCenter() const override;

    void addVertex(const Vertex &vertex) override;
    void addEdge(const Edge &edge) override;
    void setCenter(const Vertex &center) override;

    void transform();

protected:
    Vertex _center;

    std::vector<Vertex> _vertices;
    std::vector<Edge> _edges;
};
