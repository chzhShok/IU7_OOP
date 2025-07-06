#pragma once

#include "DrawManager.h"
#include "LoadManager.hpp"
#include "SceneManager.hpp"
#include "TransformManager.hpp"

class BaseCommand {
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = 0;

    void setManagers(std::shared_ptr<SceneManager> sceneManager,
                     std::shared_ptr<LoadManager> loadManager,
                     std::shared_ptr<TransformManager> transformManager,
                     std::shared_ptr<DrawManager> drawManager);


    virtual void execute() = 0;

protected:
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<TransformManager> _transformManager;
    std::shared_ptr<DrawManager> _drawManager;
};