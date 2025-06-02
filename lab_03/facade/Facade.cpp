#include <memory>

#include "Facade.hpp"

Facade::Facade() {
    __drawManager = std::make_shared<DrawManager>();
    __loadManager = std::make_shared<LoadManager>();
    __sceneManager = std::make_shared<SceneManager>();
    __transformManager = std::make_shared<TransformManager>();
}

void Facade::execute(BaseCommand &command) {
    command.setManagers(__sceneManager, __loadManager, __transformManager, __drawManager);
    command.execute();
}

std::shared_ptr<TransformManager> Facade::getTransformManager() {
    return __transformManager;
}
