#include "RemoveCameraCommand.hpp"

RemoveCameraCommand::RemoveCameraCommand(std::size_t id) : _id(id) {}

void RemoveCameraCommand::execute() {
    _sceneManager->removeCamera(_id);
}
