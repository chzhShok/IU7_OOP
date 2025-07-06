#include "RotateObjectCommand.hpp"

RotateObjectCommand::RotateObjectCommand(std::size_t id, double ox, double oy, double oz) : __id(id), __ox(ox), __oy(oy), __oz(oz) {}

void RotateObjectCommand::execute() {
    auto obj = _sceneManager->getObject(__id);
    _transformManager->rotateObject(obj, __ox, __oy, __oz);
}
