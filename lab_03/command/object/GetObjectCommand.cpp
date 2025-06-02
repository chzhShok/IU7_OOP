#include "GetObjectCommand.hpp"

GetObjectCommand::GetObjectCommand(std::size_t id) : __id(id) {}

void GetObjectCommand::execute() {
    __object = _sceneManager->getObject(__id);
}
