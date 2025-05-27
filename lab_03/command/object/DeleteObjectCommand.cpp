#include "DeleteObjectCommand.hpp"

DeleteObjectCommand::DeleteObjectCommand(std::size_t id) : _id(id) {}

void DeleteObjectCommand::execute() {
    _sceneManager->removeObject(_id);
}
