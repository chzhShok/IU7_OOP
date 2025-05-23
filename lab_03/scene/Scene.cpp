#include <iostream>

#include "Scene.hpp"

Scene::Scene() : _objects(std::list<std::shared_ptr<BaseObject>>()), _cameras(std::list<iterator>()) {}

void Scene::addObject(const std::shared_ptr<BaseObject> obj) {
    _objects.push_back(obj);
}

void Scene::removeObject(const const_iterator &it) {
    _objects.erase(it);
}

void Scene::addCamera(const std::shared_ptr<BaseObject> obj) {
    _objects.push_back(obj);
    auto it = _objects.begin();
    auto itnext = ++_objects.begin();
    for (; itnext != _objects.end(); ++it, ++itnext)
        ;

    _cameras.push_back(it);
}

void Scene::removeCamera(const std::list<iterator>::const_iterator &it) {
    _objects.erase(*it);
    _cameras.erase(it);
}

std::shared_ptr<BaseObject> Scene::getCamera(const iteratorCamera &it) {
    return **it;
}

Scene::iterator Scene::begin() {
    return _objects.begin();
}

Scene::iterator Scene::end() {
    return _objects.end();
}

Scene::const_iterator Scene::begin() const {
    return _objects.begin();
}

Scene::const_iterator Scene::end() const {
    return _objects.end();
}

Scene::const_iterator Scene::cbegin() const {
    return _objects.cbegin();
}

Scene::const_iterator Scene::cend() const {
    return _objects.cend();
}

Scene::reverse_iterator Scene::rbegin() {
    return _objects.rbegin();
}

Scene::reverse_iterator Scene::rend() {
    return _objects.rend();
}

Scene::const_reverse_iterator Scene::rbegin() const {
    return _objects.rbegin();
}

Scene::const_reverse_iterator Scene::rend() const {
    return _objects.rend();
}

Scene::const_reverse_iterator Scene::crbegin() const {
    return _objects.crbegin();
}

Scene::const_reverse_iterator Scene::crend() const {
    return _objects.crend();
}

Scene::size_type Scene::size() const {
    return _objects.size();
}

Scene::iteratorCamera Scene::beginCamera() {
    return _cameras.cbegin();
}

Scene::iteratorCamera Scene::endCamera() {
    return _cameras.cend();
}

std::shared_ptr<Scene> Scene::clone() {
    std::shared_ptr<Scene> clone = std::make_shared<Scene>();
    auto cit = beginCamera();
    for (const auto &obj: _objects) {
        if (cit != endCamera() && obj == **cit) {
            clone->addCamera(obj->clone());
            ++cit;
        } else {
            clone->addObject(obj->clone());
        }
    }

    return clone;
}

void Scene::addComposite(const std::vector<std::shared_ptr<BaseObject>> objects) {
    std::shared_ptr<Composite> composite = std::make_shared<Composite>();
    for (const auto &obj: objects) {
        composite->add(obj);
    }

    addObject(composite);
}
