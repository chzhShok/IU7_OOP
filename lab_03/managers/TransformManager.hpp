#pragma once

#include "BaseObject.hpp"
#include "Matrix.h"

class TransformManager {
public:
    TransformManager() = default;
    TransformManager(const TransformManager &manager) = delete;
    TransformManager &operator=(const TransformManager &manager) = delete;

    ~TransformManager() = default;

    static void moveObject(const std::shared_ptr<BaseObject> &object,
                           const double &dx,
                           const double &dy,
                           const double &dz);
    static void scaleObject(const std::shared_ptr<BaseObject> &object,
                            const double &kx,
                            const double &ky,
                            const double &kz);
    static void rotateObject(const std::shared_ptr<BaseObject> &object,
                             const double &ox,
                             const double &oy,
                             const double &oz);

    static void transformObject(const std::shared_ptr<BaseObject> &object, const Matrix<double> &mtr);
};
