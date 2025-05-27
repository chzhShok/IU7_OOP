#pragma once

#include <memory>

#include "BaseObject.hpp"
#include "Visitor.hpp"
#include "Vertex.hpp"

class Composite : public BaseObject {
public:
    Composite() = default;
    Composite(std::vector<std::shared_ptr<BaseObject>> objects);

    virtual ~Composite() = default;
    virtual std::shared_ptr<BaseObject> clone() const;
    virtual void add(const std::shared_ptr<BaseObject> object);
    virtual void remove(const iterator &it);
    virtual void accept(std::shared_ptr<Visitor> v);
    virtual bool isComposite() const;
    virtual bool isVisible() const;
    virtual Vertex getCenter() const;
    virtual iterator begin();
    virtual iterator end();

protected:
    std::vector<std::shared_ptr<BaseObject>> _objects;
};
