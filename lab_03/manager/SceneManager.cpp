#include "SceneManager.hpp"

SceneManager::SceneManager() : _scene(std::make_shared<Scene>()), _camera(std::make_shared<Camera>()) {}

void SceneManager::setScene(std::shared_ptr<Scene> scene) {
    _scene = scene;
}

std::shared_ptr<Scene> SceneManager::getScene() {
    return _scene;
}

void SceneManager::setCamera(std::shared_ptr<Camera> camera) {
    _camera = camera;
}

void SceneManager::addObject(std::shared_ptr<BaseObject> object) {
    _scene->addObject(object);
}

std::vector<std::shared_ptr<BaseObject>> SceneManager::getObjects() {
    std::vector<std::shared_ptr<BaseObject>> objects;
    for (auto &item: *_scene)
        objects.push_back(item);

    return objects;
}

void SceneManager::addCamera(const Vertex &pos) {
    auto camera = std::make_shared<Camera>(pos);
    _scene->addCamera(camera);
}

std::shared_ptr<BaseObject> SceneManager::getObject(std::size_t id) {
    for (auto &item: *_scene)
        if ((item)->getId() == id)
            return item;

    return nullptr;
}

void SceneManager::removeObject(std::size_t id) {
    for (auto it = _scene->cbegin(); it != _scene->cend(); ++it)
        if ((*it)->getId() == id) {
            _scene->removeObject(it);
            return;
        }
}

std::vector<std::shared_ptr<BaseObject>> SceneManager::getCameras() {
    std::vector<std::shared_ptr<BaseObject>> cameras;
    for (auto it = _scene->beginCamera(); it != _scene->endCamera(); ++it)
        cameras.push_back(**it);

    return cameras;
}

std::shared_ptr<Camera> SceneManager::getCamera(std::size_t id) {
    for (auto it = _scene->beginCamera(); it != _scene->endCamera(); ++it) {
        if ((**it)->getId() == id) {
            auto obj = std::dynamic_pointer_cast<Camera>(**it);
            if (obj == nullptr)
                throw std::runtime_error("Object is not a camera");

            return obj;
        }
    }

    return nullptr;
}

void SceneManager::removeCamera(std::size_t id) {
    for (auto it = _scene->beginCamera(); it != _scene->endCamera(); ++it)
        if ((**it)->getId() == id) {
            _scene->removeCamera(it);
            return;
        }
}

void SceneManager::setCamera(std::size_t id) {
    _camera = getCamera(id);
}

void SceneManager::clearScene() {
    _scene->_cameras.clear();
    _scene->_objects.clear();
}

std::shared_ptr<Camera> SceneManager::getMainCamera() {
    return _camera;
}

std::vector<std::size_t> SceneManager::getObjectIds() {
    std::vector<std::size_t> ids;
    for (auto &it: *_scene)
        ids.push_back(it->getId());

    return ids;
}

std::vector<std::size_t> SceneManager::getCameraIds() {
    std::vector<std::size_t> ids;
    for (auto it = _scene->beginCamera(); it != _scene->endCamera(); ++it)
        if (**it)
            ids.push_back((**it)->getId());

    return ids;
}

//void SceneManager::makeComposite(const std::vector<size_t> ids) {
//    std::vector<std::shared_ptr<BaseObject>> objects;
//    objects.reserve(ids.size());
//
//    for (const auto id: ids)
//        if (auto obj = getObject(id))
//            objects.push_back(obj);
//
//    _scene->addComposite(objects);
//}

void SceneManager::makeComposite(std::vector<size_t> ids) {
    std::vector<std::shared_ptr<BaseObject>> objects;
    for (auto it = ids.begin(); it != ids.end(); ++it)
        objects.push_back(getObject(*it));

    _scene->addComposite(objects);
}
