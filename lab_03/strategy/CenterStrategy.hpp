#pragma once

#include "BaseCenterStrategy.hpp"

class CenterStrategy : public BaseCenterStrategy {
public:
    CenterStrategy() = default;
    virtual ~CenterStrategy() = default;

    virtual Vertex CenterAlgorithm(std::vector<Vertex> vertices) const;
};
