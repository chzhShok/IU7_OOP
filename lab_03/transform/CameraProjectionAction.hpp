#pragma once

#include <memory>

#include "TransformAction.hpp"
#include "MoveAction.hpp"
#include "Camera.hpp"

class CameraProjectionAction : public TransformAction {
public:
    CameraProjectionAction(std::shared_ptr<Camera> camera);
    CameraProjectionAction() = delete;
    ~CameraProjectionAction() = default;

private:
    std::shared_ptr<Camera> __camera;
};
