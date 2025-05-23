#pragma once

#include "InvisibleObject.hpp"

class Camera : public InvisibleObject {
public:
    Camera() = default;
    Camera(const Vertex &location) : _location(location) {}
    ~Camera() override = default;

    Vertex getCenter() const override;
    void transform() override;

private:
    Vertex _location;
};
