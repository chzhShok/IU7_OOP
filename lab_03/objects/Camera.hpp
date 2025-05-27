#pragma once

#include "CameraProjectionAction.hpp"
#include "DrawVisitor.hpp"
#include "InvisibleObject.hpp"
#include "TransformAction.hpp"
#include "TransformVisitor.hpp"

class Camera : public InvisibleObject {
    friend class DrawVisitor;
    friend class TransformVisitor;
    friend class CameraProjectionAction;

public:
    Camera();
    Camera(double x, double y, double z);
    explicit Camera(const Vertex &p);
    explicit Camera(const Camera &other);

    virtual bool isComposite() const;
    virtual void accept(std::shared_ptr<Visitor> v);
    virtual Vertex getCenter() const;

    virtual ~Camera() = default;

protected:
    Vertex _self;
    Vertex _normalForward;
    Vertex _normalUp;
    Vertex _normalRight;
};
