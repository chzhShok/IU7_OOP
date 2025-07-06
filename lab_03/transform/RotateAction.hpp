#pragma once

#include "Matrix.h"
#include "TransformAction.hpp"
#include "Vertex.hpp"
#include "MoveAction.hpp"

class RotateAction : public TransformAction {
public:
    RotateAction(double ox, double oy, double oz);
    RotateAction(const Vertex &center, double ox, double oy, double oz);
    virtual ~RotateAction() = default;
};
