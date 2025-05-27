#pragma once

#include <list>

#include "BaseObject.hpp"
#include "SceneManager.hpp"
#include "Visitor.hpp"

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

    void addCamera(const std::shared_ptr<BaseObject> obj);
    void removeCamera(const std::list<iterator>::const_iterator &it);
    std::shared_ptr<BaseObject> getCamera(const iteratorCamera &it);

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

    void accept(std::shared_ptr<Visitor>);
    std::shared_ptr<Scene> clone();

protected:
    std::list<std::shared_ptr<BaseObject>> _objects;
    std::list<iterator> _cameras;
};
