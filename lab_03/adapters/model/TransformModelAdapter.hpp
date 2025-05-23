#pragma once

#include "TransformCompositeAdapter.hpp"

class TransformModelAdapter : public TransformCompositeAdapter {
public:
    TransformModelAdapter() = default;
    ~TransformModelAdapter() override = default;

    void setAdaptee(const std::vector<std::shared_ptr<BaseObject>> &objects) override;
    void request(const Matrix<double> &matrix) override;

private:
    std::vector<std::shared_ptr<BaseObject>> _objects;
};
