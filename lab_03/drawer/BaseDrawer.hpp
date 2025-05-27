#pragma once
#include "Vertex.hpp"

class BaseDrawer {
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = 0;

    virtual void drawLine(const Vertex &p1, const Vertex &p2) = 0;
    virtual void clear() = 0;
};
