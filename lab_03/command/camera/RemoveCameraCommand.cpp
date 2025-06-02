#include "RemoveCameraCommand.hpp"

RemoveCameraCommand::RemoveCameraCommand(std::size_t id) : __id(id) {}

void RemoveCameraCommand::execute() {
    _sceneManager->removeCamera(__id);
}
