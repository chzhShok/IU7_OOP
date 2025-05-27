#include "CompositeObjectCommand.hpp"

CompositeObjectCommand::CompositeObjectCommand(std::vector<size_t> ids) : _ids(ids) {}

void CompositeObjectCommand::execute() {
    _sceneManager->makeComposite(_ids);
}
