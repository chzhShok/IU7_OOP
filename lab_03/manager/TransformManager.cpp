#include "TransformManager.hpp"
#include "BaseObject.hpp"
#include "MoveAction.hpp"
#include "RotateAction.hpp"
#include "ScaleAction.hpp"
#include "TransformAction.hpp"
#include "TransformVisitor.hpp"
#include <memory>

void TransformManager::rotateObject(std::shared_ptr<BaseObject> object, double ox, double oy, double oz) {
    TransformVisitor vis(std::make_shared<RotateAction>(object->getCenter(), ox, oy, oz));
    object->accept(std::make_shared<TransformVisitor>(vis));
}

void TransformManager::scaleObject(std::shared_ptr<BaseObject> object, double kx, double ky, double kz) {
    TransformVisitor vis(std::make_shared<ScaleAction>(object->getCenter(), kx, ky, kz));
    object->accept(std::make_shared<TransformVisitor>(vis));
}
void TransformManager::moveObject(std::shared_ptr<BaseObject> object, double x, double y, double z) {
    TransformVisitor vis(std::make_shared<MoveAction>(x, y, z));
    object->accept(std::make_shared<TransformVisitor>(vis));
}
void TransformManager::transformObject(std::shared_ptr<BaseObject> object, std::shared_ptr<TransformAction> transform) {
    TransformVisitor vis(transform);
    object->accept(std::make_shared<TransformVisitor>(vis));
}
