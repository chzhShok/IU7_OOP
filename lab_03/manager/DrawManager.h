#pragma once

#include "BaseDrawerCreator.hpp"
#include "Concept.hpp"
#include "DrawVisitor.hpp"
#include "Scene.hpp"
#include <memory>

class DrawManager {
public:
    DrawManager() = default;
    ~DrawManager() = default;

    template<typename DrawerCreator, typename... Args>
        requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
    void drawScene(std::shared_ptr<SceneManager> sceneMngr, Args... args);
};

#include "DrawManager.hpp"
