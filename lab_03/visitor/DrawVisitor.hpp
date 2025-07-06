#pragma once

#include "BaseDrawer.hpp"
#include "ModelStructure.hpp"
#include "Vector3.hpp"
#include "Visitor.hpp"

class DrawVisitor : public Visitor {
public:
    DrawVisitor() = delete;
    DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera);
    ~DrawVisitor() = default;

    virtual void visit(CarcassModel &model) const;
    virtual void visit(Camera &camera) const;
    virtual void visit(Composite &composite) const;

    void setEdgesVisibilityEnabled(bool enabled) { _edgesVisibilityEnabled = enabled; }
    bool isEdgesVisibilityEnabled() const { return _edgesVisibilityEnabled; }

private:
    Vertex getCameraProjection(const Vertex &point) const;
    bool isFaceVisible(const std::vector<Vertex> &points, const Face &face, const Vector3 &cameraPos) const;
    Vector3 getCameraPosition() const;
    Vector3 calculateFaceNormal(const Vertex &p1, const Vertex &p2, const Vertex &p3) const;
    Vertex calculateModelCenter(const std::vector<Vertex> &points) const;

    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
    bool _edgesVisibilityEnabled = true;
};
