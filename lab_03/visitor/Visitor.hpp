#pragma once

#include <memory>

class Camera;
class CarcassModel;

class Visitor {
public:
    Visitor() {};

    virtual ~Visitor() {};
    virtual void visit(CarcassModel &model) const = 0;
    virtual void visit(Camera &camera) const = 0;
};
