#pragma once

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

private:
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<TransformManager> _transformManager;
    std::shared_ptr<DrawManager> _drawManager;
};
