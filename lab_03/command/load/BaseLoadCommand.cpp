#include "BaseLoadCommand.hpp"

BaseLoadCommand::~BaseLoadCommand() {}

size_t BaseLoadCommand::getDirectorId() {
    return _director_id;
}

size_t BaseLoadCommand::getLoaderId() {
    return _loader_id;
}
