#include "Facade.hpp"

Facade::Facade() {
    _drawManager = std::make_shared<DrawManager>();
    _loadManager = std::make_shared<LoadManager>();
    _sceneManager = std::make_shared<SceneManager>();
    _transformManager = std::make_shared<TransformManager>();
}

void Facade::execute(BaseCommand &command) {
    command.setManagers(_sceneManager, _loadManager, _transformManager, _drawManager);
    command.execute();
}
