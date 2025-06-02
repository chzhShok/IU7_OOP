#include "MoveCameraCommand.hpp"

MoveCameraCommand::MoveCameraCommand(std::size_t id, double dx, double dy, double dz) : __id(id), __dx(dx), __dy(dy), __dz(dz) {}

void MoveCameraCommand::execute() {
    auto cam = _sceneManager->getCamera(__id);
    _transformManager->moveObject(cam, __dx, __dy, __dz);
}
