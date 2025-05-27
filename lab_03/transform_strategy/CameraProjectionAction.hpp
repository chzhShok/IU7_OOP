#pragma once

#include "TransformAction.hpp"
#include <memory>

class Camera;

class CameraProjectionAction : public TransformAction {
public:
    CameraProjectionAction(std::shared_ptr<Camera> camera);
    CameraProjectionAction() = delete;

    ~CameraProjectionAction() = default;

private:
    std::shared_ptr<Camera> _camera;
};
