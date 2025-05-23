#ifndef FACADE_H
#define FACADE_H

#include "BaseCommand.hpp"
#include "DrawManager.hpp"
#include "LoadManager.hpp"
#include "SceneManager.hpp"
#include "TransformManager.hpp"

#include <memory>

class Facade {
public:
    Facade();
    ~Facade() = default;

    void execute(BaseCommand &command);

private:
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
};

#endif//FACADE_H
