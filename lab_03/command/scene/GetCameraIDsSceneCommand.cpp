#include "GetCameraIDsSceneCommand.hpp"

GetCameraIDsSceneCommand::GetCameraIDsSceneCommand() : __ids(std::vector<size_t>()) {}

void GetCameraIDsSceneCommand::execute() {
    __ids = _sceneManager->getCameraIds();
}

std::vector<size_t> GetCameraIDsSceneCommand::getIDs() {
    return __ids;
}
