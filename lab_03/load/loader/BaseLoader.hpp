#pragma once

#include <vector>

#include "Vertex.hpp"
#include "Edge.hpp"

class BaseLoader {
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = 0;

    virtual void open() = 0;
    virtual void close() = 0;
    virtual bool isOpen() = 0;

    virtual std::vector<Vertex> readVertices();
    virtual std::vector<Edge> readEdges();
};
