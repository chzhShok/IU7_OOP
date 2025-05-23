#pragma once

#include "BaseAdapter.hpp"
#include "BaseDrawer.hpp"
#include "BaseObject.hpp"
#include "Composite.hpp"
#include "DrawCompositeAdapter.hpp"
#include "Scene.hpp"
#include "Vertex.hpp"

class DrawManager {
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    DrawManager &operator=(const DrawManager &manager) = delete;
    ~DrawManager() = default;

    void setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter);

    void drawScene(std::shared_ptr<Scene> scene);

private:
    std::shared_ptr<DrawCompositeAdapter> _adapter;
};
