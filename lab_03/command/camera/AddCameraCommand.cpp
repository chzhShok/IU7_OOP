#include "AddCameraCommand.hpp"

AddCameraCommand::AddCameraCommand(const Vertex &position) : _position(position) {}

void AddCameraCommand::execute() {
    _sceneManager->addCamera(_position);
}
