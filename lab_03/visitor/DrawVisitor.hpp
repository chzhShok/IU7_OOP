#pragma once

#include "BaseDrawer.hpp"
#include "Vertex.hpp"
#include "Visitor.hpp"
#include "CameraProjectionAction.hpp"
#include "CarcassModel.hpp"
#include "Composite.hpp"

class DrawVisitor : public Visitor {
public:
    DrawVisitor() = delete;
    DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera);
    ~DrawVisitor() = default;

    virtual void visit(CarcassModel &model) const;
    virtual void visit(Camera &camera) const;
    virtual void visit(Composite &composite) const;


private:
    Vertex getCameraProjection(const Vertex &point) const;
    std::shared_ptr<BaseDrawer> __drawer;
    std::shared_ptr<Camera> __camera;
};
