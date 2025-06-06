#include "TransformManager.hpp"
#include "CarcassModel.hpp"
#include "ModelStructure.hpp"

TransformManager::TransformManager() {}

void TransformManager::rotateObject(std::shared_ptr<BaseObject> object, double ox, double oy, double oz) {
    auto carcass = std::dynamic_pointer_cast<CarcassModel>(object);
    if (carcass && carcass->_model) {
        __caretaker.save(std::make_shared<TransformMemento>(
                object,
                object->getTransformMatrix(),
                carcass->_model->clone()// Используем clone() вместо конструктора копирования
                ));
    } else {
        __caretaker.save(std::make_shared<TransformMemento>(object, object->getTransformMatrix()));
    }

    auto action = RotateAction(object->getCenter(), ox, oy, oz);
    object->transform(action);
}

void TransformManager::scaleObject(std::shared_ptr<BaseObject> object, double kx, double ky, double kz) {
    auto carcass = std::dynamic_pointer_cast<CarcassModel>(object);
    if (carcass && carcass->_model) {
        __caretaker.save(std::make_shared<TransformMemento>(
                object,
                object->getTransformMatrix(),
                carcass->_model->clone()));
    } else {
        __caretaker.save(std::make_shared<TransformMemento>(object, object->getTransformMatrix()));
    }

    auto action = ScaleAction(object->getCenter(), kx, ky, kz);
    object->transform(action);
}

void TransformManager::moveObject(std::shared_ptr<BaseObject> object, double x, double y, double z) {
    auto carcass = std::dynamic_pointer_cast<CarcassModel>(object);
    if (carcass && carcass->_model) {
        __caretaker.save(std::make_shared<TransformMemento>(
                object,
                object->getTransformMatrix(),
                carcass->_model->clone()));
    } else {
        __caretaker.save(std::make_shared<TransformMemento>(object, object->getTransformMatrix()));
    }

    auto action = MoveAction(x, y, z);
    object->transform(action);
}

void TransformManager::transformObject(std::shared_ptr<BaseObject> object, const TransformAction &transform) {
    auto carcass = std::dynamic_pointer_cast<CarcassModel>(object);
    if (carcass && carcass->_model) {
        __caretaker.save(std::make_shared<TransformMemento>(
                object,
                object->getTransformMatrix(),
                carcass->_model->clone()));
    } else {
        __caretaker.save(std::make_shared<TransformMemento>(object, object->getTransformMatrix()));
    }

    object->transform(transform);
}

bool TransformManager::undo() {
    auto memento = __caretaker.undo();
    if (!memento) return false;

    auto obj = memento->getObject();
    if (obj) {
        obj->setTransformMatrix(memento->getMatrix());

        auto carcass = std::dynamic_pointer_cast<CarcassModel>(obj);
        if (carcass && memento->getModelState())
            carcass->_model = memento->getModelState();

        return true;
    }

    return false;
}