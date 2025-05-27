#include "MoveObjectCommand.hpp"

MoveObjectCommand::MoveObjectCommand(std::size_t id, double x, double y, double z)
    : _id(id), _x(x), _y(y), _z(z) {}

void MoveObjectCommand::execute() {
    auto obj = _sceneManager->getObject(_id);
    _transformManager->moveObject(obj, _x, _y, _z);
}
