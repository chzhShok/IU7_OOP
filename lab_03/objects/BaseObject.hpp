#pragma once

#include <cstddef>
#include <memory>
#include <vector>

#include "Matrix.h"
#include "TransformAction.hpp"
#include "TransformMemento.hpp"

class Visitor;

std::size_t GetNextId();

class BaseObject {
public:
    using iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

    BaseObject();
    virtual ~BaseObject() = default;

    virtual void add(std::shared_ptr<BaseObject> obj);
    virtual void remove(const iterator &it);
    virtual void transform(const TransformAction &action);
    Matrix<double> getTransformMatrix() const;
    void setTransformMatrix(const Matrix<double> &matrix);
    virtual void accept(const Visitor &visitor);
    virtual std::shared_ptr<BaseObject> clone() const;
    virtual std::size_t getId() const;

    virtual iterator begin();
    virtual iterator end();

    virtual Vertex getCenter() const = 0;
    virtual bool isVisible() const = 0;
    virtual bool isComposite() const = 0;

protected:
    std::size_t _id;
    Matrix<double> _transformMatrix;
};
