#include "JsonLoadCommandDecorator.hpp"

JsonLoadCommandDecorator::JsonLoadCommandDecorator(BaseLoadCommand &command, const char *filename) : BaseLoadCommandDecorator(command), _filename(filename) {
    _command = command;
    _loader_id = JSONMODELLOADERCREATOR_ID;
}

void JsonLoadCommandDecorator::execute() {
    _command.execute();
    _director_id = _command.getDirectorId();
    auto obj = _loadManager->loadCarcassModelFile(_director_id, _loader_id, _filename);
    _sceneManager->addObject(obj);
};
