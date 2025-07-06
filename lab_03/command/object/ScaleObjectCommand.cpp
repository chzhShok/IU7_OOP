#include "ScaleObjectCommand.hpp"

ScaleObjectCommand::ScaleObjectCommand(std::size_t id, double kx, double ky, double kz) : __id(id), __kx(kx), __ky(ky), __kz(kz) {}

void ScaleObjectCommand::execute() {
    auto obj = _sceneManager->getObject(__id);
    _transformManager->scaleObject(obj, __kx, __ky, __kz);
}
