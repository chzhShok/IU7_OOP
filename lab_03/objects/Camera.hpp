#pragma once

#include "DrawVisitor.hpp"
#include "InvisibleObject.hpp"
#include "TransformAction.hpp"

class Camera : public InvisibleObject {
    friend class DrawVisitor;
    friend class CameraProjectionAction;

public:
    Camera();
    Camera(double x, double y, double z);
    explicit Camera(const Vertex &p);
    explicit Camera(const Camera &other);
    virtual ~Camera() = default;

    virtual bool isComposite() const;
    virtual void transform(const TransformAction &action);
    virtual void accept(const Visitor &visitor);
    virtual Vertex getCenter() const;

protected:
    Vertex _self;
    Vertex _normalForward;
    Vertex _normalUp;
    Vertex _normalRight;
};
