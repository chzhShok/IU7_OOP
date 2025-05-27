#include "GetObjectIDsSceneCommand.hpp"

GetObjectIDsSceneCommand::GetObjectIDsSceneCommand() : _ids(std::vector<std::size_t>()) {}

void GetObjectIDsSceneCommand::execute() {
    _ids = _sceneManager->getObjectIds();
}
std::vector<std::size_t> GetObjectIDsSceneCommand::getIDs() {
    return _ids;
}
