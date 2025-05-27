#pragma once

#include "BaseDrawer.hpp"
#include "Visitor.hpp"

//class Visitor;

class DrawVisitor : public Visitor {
public:
    DrawVisitor() = delete;
    DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera);
    ~DrawVisitor() = default;

    virtual void visit(CarcassModel &model) const;
    virtual void visit(Camera &camera) const;

private:
    Vertex getCameraProjection(const Vertex &point) const;
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
};
