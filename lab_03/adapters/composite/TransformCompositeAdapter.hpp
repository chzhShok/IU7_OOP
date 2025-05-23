#pragma once

#include <memory>
#include <vector>

#include "BaseObject.hpp"
#include "Matrix.h"

class TransformCompositeAdapter {
public:
    TransformCompositeAdapter() = default;
    ~TransformCompositeAdapter() = default;

    void setAdaptee(const std::vector<std::shared_ptr<BaseObject>> &objects);
    void request(const Matrix<double> &matrix);

private:
    void applyTransform(const std::shared_ptr<BaseObject> &obj, const Matrix<double> &matrix);

    std::vector<std::shared_ptr<BaseObject>> _objects;
};
