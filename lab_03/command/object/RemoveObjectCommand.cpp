#include "RemoveObjectCommand.hpp"

RemoveObjectCommand::RemoveObjectCommand(std::size_t id) : __id(id) {}

void RemoveObjectCommand::execute() {
    _sceneManager->removeObject(__id);
}
