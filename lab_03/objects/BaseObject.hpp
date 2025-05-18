#pragma once

#include <memory>
#include <vector>

#include "Vertex.hpp"

class BaseObject {
public:
    using iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

    BaseObject();
    virtual ~BaseObject() = 0;

    virtual void add(const std::shared_ptr<BaseObject> &object) = 0;
    virtual void remove(const iterator &) = 0;
    virtual void transform() = 0;

    virtual iterator begin() { return iterator(); };
    virtual iterator end() { return iterator(); };

    virtual bool isVisible() { return false; };
    virtual bool isComposite() { return false; };

    virtual Vertex getCenter() const = 0;
    virtual std::size_t getId() { return _id; }

protected:
    std::size_t _id;
    static std::size_t _nextId;
};