#pragma once

#include <memory>

#include "BaseCommand.hpp"
#include "DrawManager.h"
#include "LoadManager.hpp"
#include "SceneManager.hpp"
#include "TransformManager.hpp"

class Facade {
public:
    Facade();
    ~Facade() = default;

    void execute(BaseCommand &command);
    std::shared_ptr<TransformManager> getTransformManager();

private:
    std::shared_ptr<SceneManager> __sceneManager;
    std::shared_ptr<LoadManager> __loadManager;
    std::shared_ptr<TransformManager> __transformManager;
    std::shared_ptr<DrawManager> __drawManager;
};
