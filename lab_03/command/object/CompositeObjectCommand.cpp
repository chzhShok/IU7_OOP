#include "CompositeObjectCommand.hpp"

CompositeObjectCommand::CompositeObjectCommand(std::vector<size_t> ids) : __ids(ids) {}

void CompositeObjectCommand::execute() {
    _sceneManager->makeComposite(__ids);
}
