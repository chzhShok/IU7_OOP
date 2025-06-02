#pragma once

#include <memory>

class CarcassModel;
class Camera;
class Composite;

class Visitor {
public:
    Visitor() {};
    virtual ~Visitor() {};

    virtual void visit(CarcassModel &model) const = 0;
    virtual void visit(Camera &camera) const = 0;
    virtual void visit(Composite &composite) const = 0;
};
