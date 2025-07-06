#include "SetCameraCommand.hpp"

SetCameraCommand::SetCameraCommand(std::size_t id) : __id(id) {}

void SetCameraCommand::execute() {
    _sceneManager->setCamera(__id);
}
