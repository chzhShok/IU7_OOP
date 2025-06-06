#include <iostream>

#include "TxtLoadCommandDecorator.hpp"

TxtLoadCommandDecorator::TxtLoadCommandDecorator(BaseLoadCommand &command, const char *filename) : BaseLoadCommandDecorator(command), _filename(filename) {
    _command = command;
    _loader_id = TXTMODELLOADERCREATOR_ID;
}

void TxtLoadCommandDecorator::execute() {
    _command.execute();
    _director_id = _command.getDirectorId();
    auto obj = _loadManager->loadCarcassModelFile(_director_id, _loader_id, _filename);

    _sceneManager->addObject(obj);
}
