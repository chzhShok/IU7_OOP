#pragma once

#include <memory>

#include "BaseDrawerCreator.hpp"
#include "Concept.hpp"
#include "DrawVisitor.hpp"
#include "Scene.hpp"

class DrawManager {
public:
    DrawManager() = default;
    ~DrawManager() = default;

    template<typename DrawerCreator, typename... Args>
        requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
    void drawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args);
};

#include "DrawManager.hpp"
