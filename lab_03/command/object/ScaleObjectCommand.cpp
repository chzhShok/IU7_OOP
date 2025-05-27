#include "ScaleObjectCommand.hpp"

ScaleObjectCommand::ScaleObjectCommand(std::size_t id, double kx, double ky, double kz)
    : _id(id), _kx(kx), _ky(ky), _kz(kz) {}

void ScaleObjectCommand::execute() {
    auto obj = _sceneManager->getObject(_id);
    _transformManager->scaleObject(obj, _kx, _ky, _kz);
}
