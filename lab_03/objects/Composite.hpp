#pragma once

#include <memory>

#include "BaseObject.hpp"
#include "CenterStrategy.hpp"
#include "Visitor.hpp"

class Composite : public BaseObject {
public:
    Composite() = default;
    Composite(std::vector<std::shared_ptr<BaseObject>> objects);
    virtual ~Composite() = default;

    virtual std::shared_ptr<BaseObject> clone() const;
    virtual void add(const std::shared_ptr<BaseObject> object);
    virtual void remove(const iterator &it);
    virtual void transform(const TransformAction &transform);
    virtual void accept(const Visitor &visitor);
    virtual bool isComposite() const;
    virtual bool isVisible() const;
    virtual Vertex getCenter() const;

    virtual iterator begin();
    virtual iterator end();

protected:
    std::vector<std::shared_ptr<BaseObject>> _objects;
};
