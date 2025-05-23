#pragma once

#include <list>
#include <memory>
#include <vector>

#include "BaseObject.hpp"
#include "Composite.hpp"

class Scene {
    friend class SceneManager;

public:
    using iterator = std::list<std::shared_ptr<BaseObject>>::iterator;
    using const_iterator = std::list<std::shared_ptr<BaseObject>>::const_iterator;
    using reverse_iterator = std::list<std::shared_ptr<BaseObject>>::reverse_iterator;
    using const_reverse_iterator = std::list<std::shared_ptr<BaseObject>>::const_reverse_iterator;
    using size_type = std::list<std::shared_ptr<BaseObject>>::size_type;
    using difference_type = std::list<std::shared_ptr<BaseObject>>::difference_type;
    using iteratorCamera = std::list<iterator>::const_iterator;

    Scene();
    ~Scene() = default;

    void addObject(const std::shared_ptr<BaseObject> obj);
    void removeObject(const const_iterator &it);
    void addComposite(const std::vector<std::shared_ptr<BaseObject>> objects);

    std::size_t addCamera(const Vertex &location);
    void removeCamera(const iteratorCamera &it);
    std::shared_ptr<BaseObject> getCamera(const iteratorCamera &it);

    // Доступ к объектам
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
    size_type size() const;

    iteratorCamera beginCamera();
    iteratorCamera endCamera();

    std::vector<std::shared_ptr<BaseObject>> getVisibleObjects() const;
    iterator getObjectIter(const std::size_t id);
    std::shared_ptr<BaseObject> getObject(const std::size_t id);

    std::shared_ptr<Scene> clone();

private:
    std::list<std::shared_ptr<BaseObject>> _objects;
    std::list<iterator> _cameras;
};
