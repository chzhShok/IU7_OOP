#include "RotateObjectCommand.hpp"

RotateObjectCommand::RotateObjectCommand(std::size_t id, double ox, double oy, double oz) : _id(id), _ox(ox), _oy(oy), _oz(oz) {}

void RotateObjectCommand::execute() {
    auto obj = _sceneManager->getObject(_id);
    _transformManager->rotateObject(obj, _ox, _oy, _oz);
}
