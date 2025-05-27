#include "GetCameraIDsSceneCommand.hpp"

GetCameraIDsSceneCommand::GetCameraIDsSceneCommand() : _ids(std::vector<std::size_t>()) {}

void GetCameraIDsSceneCommand::execute() {
    _ids = _sceneManager->getCameraIds();
}

std::vector<std::size_t> GetCameraIDsSceneCommand::getIDs() {
    return _ids;
}
