#pragma once

#include <memory>
#include <vector>

#include "Camera.hpp"
#include "Scene.hpp"

class SceneManager {
protected:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<Camera> _camera;

public:
    SceneManager();
    ~SceneManager() = default;

    void setScene(std::shared_ptr<Scene> scene);
    std::shared_ptr<Scene> getScene();
    void setCamera(std::shared_ptr<Camera> camera);
    void addObject(std::shared_ptr<BaseObject> object);
    std::vector<std::shared_ptr<BaseObject>> getObjects();
    std::shared_ptr<BaseObject> getObject(std::size_t id);
    std::vector<std::size_t> getObjectIds();
    void removeObject(std::size_t id);
    void makeComposite(std::vector<size_t> ids);

    void addCamera(const Vertex &pos);
    std::vector<std::shared_ptr<BaseObject>> getCameras();
    std::vector<std::size_t> getCameraIds();
    std::shared_ptr<Camera> getCamera(std::size_t id);
    std::shared_ptr<Camera> getMainCamera();
    void removeCamera(std::size_t id);
    void setCamera(std::size_t id);

    void clearScene();
};
