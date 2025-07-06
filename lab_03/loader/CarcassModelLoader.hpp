#pragma once

#include <vector>

#include "BaseLoader.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

class CarcassModelLoader : public BaseLoader {
public:
    CarcassModelLoader() = default;
    virtual ~CarcassModelLoader() = 0;

    virtual void open() = 0;
    virtual void close() = 0;
    virtual bool isOpen() = 0;

    virtual std::vector<Vertex> readVertices() = 0;
    virtual std::vector<Edge> readEdges() = 0;
    virtual Vertex readCenter() = 0;
};
