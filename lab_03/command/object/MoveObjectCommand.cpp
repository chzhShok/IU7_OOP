#include "MoveObjectCommand.hpp"

MoveObjectCommand::MoveObjectCommand(std::size_t id, double x, double y, double z) : __id(id), __x(x), __y(y), __z(z) {}

void MoveObjectCommand::execute() {
    auto obj = _sceneManager->getObject(__id);
    _transformManager->moveObject(obj, __x, __y, __z);
}
