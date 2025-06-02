#include "TransformManager.hpp"

TransformManager::TransformManager() {}

void TransformManager::rotateObject(std::shared_ptr<BaseObject> object, double ox, double oy, double oz) {
    __caretaker.save(std::make_shared<TransformMemento>(object, object->getTransformMatrix()));
    auto action = RotateAction(object->getCenter(), ox, oy, oz);
    object->transform(action);
}

void TransformManager::scaleObject(std::shared_ptr<BaseObject> object, double kx, double ky, double kz) {
    __caretaker.save(std::make_shared<TransformMemento>(object, object->getTransformMatrix()));
    auto action = ScaleAction(object->getCenter(), kx, ky, kz);
    object->transform(action);
}

void TransformManager::moveObject(std::shared_ptr<BaseObject> object, double x, double y, double z) {
    __caretaker.save(std::make_shared<TransformMemento>(object, object->getTransformMatrix()));
    auto action = MoveAction(x, y, z);
    object->transform(action);
}

void TransformManager::transformObject(std::shared_ptr<BaseObject> object, const TransformAction &transform) {
    __caretaker.save(std::make_shared<TransformMemento>(object, object->getTransformMatrix()));
    object->transform(transform);
}

bool TransformManager::undo() {
    if (!__caretaker.canUndo())
        return false;

    auto memento = __caretaker.undo();
    if (memento)
        memento->getObject()->setTransformMatrix(memento->getMatrix());

    return true;
}
