#pragma once

#include <memory>

#include "BaseObject.hpp"
#include "MoveAction.hpp"
#include "RotateAction.hpp"
#include "ScaleAction.hpp"
#include "TransformAction.hpp"
#include "TransformCaretaker.hpp"
#include "CarcassModel.hpp"

class TransformManager {
public:
    TransformManager();

    void rotateObject(std::shared_ptr<BaseObject> object, double ox, double oy, double oz);
    void scaleObject(std::shared_ptr<BaseObject> object, double kx, double ky, double kz);
    void moveObject(std::shared_ptr<BaseObject> object, double x, double y, double z);
    void transformObject(std::shared_ptr<BaseObject> object, const TransformAction &transform);
    bool undo();

private:
    TransformCaretaker __caretaker;
};
