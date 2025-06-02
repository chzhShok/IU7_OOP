#include "GetObjectIDsSceneCommand.hpp"

GetObjectIDsSceneCommand::GetObjectIDsSceneCommand() : __ids(std::vector<std::size_t>()) {}

void GetObjectIDsSceneCommand::execute() {
    __ids = _sceneManager->getObjectIds();
}

std::vector<std::size_t> GetObjectIDsSceneCommand::getIDs() {
    return __ids;
}
