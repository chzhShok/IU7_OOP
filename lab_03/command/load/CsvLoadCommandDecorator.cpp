#include "CsvLoadCommandDecorator.hpp"

CsvLoadCommandDecorator::CsvLoadCommandDecorator(BaseLoadCommand &command, std::string filename) : BaseLoadCommandDecorator(command), _filename(filename) {
    _command = command;
    _loader_id = static_cast<size_t>(LoaderType::CSV);
}

void CsvLoadCommandDecorator::execute() {
    _command.execute();
    _director_id = _command.getDirectorId();
    auto obj = _loadManager->loadModelFile(_director_id, _loader_id, _filename);

    _sceneManager->addObject(obj);
};
