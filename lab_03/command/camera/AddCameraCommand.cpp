#include "AddCameraCommand.hpp"

AddCameraCommand::AddCameraCommand(const Vertex &position) : __position(position) {}

void AddCameraCommand::execute() {
    _sceneManager->addCamera(__position);
}
