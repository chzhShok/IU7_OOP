#pragma once

#include "BaseObject.hpp"


class Composite : public BaseObject {
public:
    Composite() = default;
    explicit Composite(std::shared_ptr<BaseObject> &object);
    explicit Composite(const std::vector<std::shared_ptr<BaseObject>> &vector);
    virtual ~Composite() = default;

    virtual void add(const std::shared_ptr<BaseObject> &object) override;
    virtual void remove(const iterator &iterator) override;
    virtual void transform() override;

    virtual iterator begin() override;
    virtual iterator end() override;

    virtual bool isVisible() override;
    virtual bool isComposite() override;

    virtual Vertex getCenter() const override;

private:
    std::vector<std::shared_ptr<BaseObject>> _objects;
};
