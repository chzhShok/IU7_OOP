#pragma once
#include "Matrix.h"
#include "TransformAction.hpp"
#include "Vertex.hpp"

class MoveAction : public TransformAction {
public:
    MoveAction(double sx, double sy, double sz);
    MoveAction(const Vertex &p);
    MoveAction(double x, double y, double z, double w);
    MoveAction();

    virtual ~MoveAction() = default;
};