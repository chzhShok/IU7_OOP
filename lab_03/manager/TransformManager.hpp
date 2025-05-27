#pragma once

#include "BaseObject.hpp"
#include "TransformAction.hpp"

class TransformManager {
public:
    TransformManager() = default;
    ~TransformManager() = default;

    void rotateObject(std::shared_ptr<BaseObject> object, double ox, double oy, double oz);
    void scaleObject(std::shared_ptr<BaseObject> object, double kx, double ky, double kz);
    void moveObject(std::shared_ptr<BaseObject> object, double x, double y, double z);
    void transformObject(std::shared_ptr<BaseObject> object, std::shared_ptr<TransformAction> transform);
};
