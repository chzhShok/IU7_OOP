#pragma once

#include "Matrix.h"
#include "TransformAction.hpp"
#include "Vertex.hpp"
#include "MoveAction.hpp"

class ScaleAction : public TransformAction {
public:
    ScaleAction(double mx, double my, double mz);
    ScaleAction(const Vertex &p, double mx, double my, double mz);
    ScaleAction(double m);
    ScaleAction(const Vertex &center, double m);
    virtual ~ScaleAction() = default;
};
