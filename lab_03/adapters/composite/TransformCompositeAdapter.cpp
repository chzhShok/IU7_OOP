#include "TransformCompositeAdapter.hpp"

void TransformCompositeAdapter::setAdaptee(const std::vector<std::shared_ptr<BaseObject>> &objects) {
    _objects = objects;
}

void TransformCompositeAdapter::request(const Matrix<double> &matrix) {
    for (const auto &obj: _objects) {
        applyTransform(obj, matrix);
    }
}

void TransformCompositeAdapter::applyTransform(const std::shared_ptr<BaseObject> &obj, const Matrix<double> &matrix) {
    if (!obj) return;

    if (obj->isComposite()) {
        for (auto it = obj->begin(); it != obj->end(); ++it) {
            applyTransform(*it, matrix);
        }
    } else if (obj->isVisible()) {
        obj->transform(matrix);
    }
}
