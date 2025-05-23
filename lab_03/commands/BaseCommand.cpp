#include "BaseCommand.hpp"

BaseCommand::~BaseCommand() {}

void BaseCommand::setManagers(std::shared_ptr<SceneManager> sceneManager,
                              std::shared_ptr<LoadManager> loadManager,
                              std::shared_ptr<TransformManager> transformManager,
                              std::shared_ptr<DrawManager> drawManager) {
    _sceneManager = sceneManager;
    _loadManager = loadManager;
    _transformManager = transformManager;
    _drawManager = drawManager;
}
