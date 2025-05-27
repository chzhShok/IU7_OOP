#include "TransformVisitor.hpp"
#include "Camera.hpp"
#include "CarcassModel.hpp"

TransformVisitor::TransformVisitor(std::shared_ptr<TransformAction> action) : _action(action) {}

void TransformVisitor::visit(CarcassModel &model) const {
    model._model->transform(_action);
}

void TransformVisitor::visit(Camera &cam) const {
    cam._self = _action->transformPoint(cam._self);
    cam._normalForward = _action->transformPoint(cam._normalForward);
    cam._normalUp = _action->transformPoint(cam._normalUp);
    cam._normalRight = _action->transformPoint(cam._normalRight);
}
