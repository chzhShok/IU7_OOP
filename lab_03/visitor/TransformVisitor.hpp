#pragma once

#include "TransformAction.hpp"
#include "Visitor.hpp"

class TransformVisitor : public Visitor {
public:
    TransformVisitor() = delete;
    TransformVisitor(std::shared_ptr<TransformAction> action);
    ~TransformVisitor() = default;

    virtual void visit(CarcassModel &model) const;
    virtual void visit(Camera &camera) const;

private:
    std::shared_ptr<TransformAction> _action;
};
