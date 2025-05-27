#pragma once

#include "TransformAction.hpp"
#include "Visitor.hpp"

#include <cstddef>
#include <memory>
#include <vector>

std::size_t GetNextId();

class BaseObject {
public:
    using iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;
    BaseObject();
    virtual ~BaseObject() = 0;

    virtual void add(std::shared_ptr<BaseObject> obj);
    virtual void remove(const iterator &it);
    virtual iterator begin();
    virtual iterator end();
    virtual void accept(std::shared_ptr<Visitor> v);
    virtual std::shared_ptr<BaseObject> clone() const;

    virtual std::size_t getId() const;

    virtual Vertex getCenter() const;// Done
    virtual bool isVisible() const = 0;
    virtual bool isComposite() const;

protected:
    std::size_t _id = 0;
};
