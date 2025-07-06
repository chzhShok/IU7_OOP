#pragma once

#include <vector>

#include "Vertex.hpp"

class BaseCenterStrategy {
public:
    BaseCenterStrategy() = default;
    virtual ~BaseCenterStrategy() = 0;

    virtual Vertex CenterAlgorithm(std::vector<Vertex> vertices) const = 0;
};
