#include "SetCameraCommand.hpp"

SetCameraCommand::SetCameraCommand(std::size_t id) : _id(id) {}

void SetCameraCommand::execute() {
    _sceneManager->setCamera(_id);
}
