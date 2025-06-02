#pragma once

#include <memory>

#include "BaseModel.hpp"
#include "DrawVisitor.hpp"
#include "ModelStructure.hpp"
#include "TransformAction.hpp"

class Visitor;

class CarcassModel : public BaseModel {
    friend class DrawVisitor;

public:
    CarcassModel();
    explicit CarcassModel(std::shared_ptr<ModelStructure>);
    explicit CarcassModel(const CarcassModel &other);
    ~CarcassModel() = default;

    virtual void accept(const Visitor &visitor);
    virtual void transform(const TransformAction &action);
    virtual Vertex getCenter() const;

protected:
    std::shared_ptr<ModelStructure> _model;
};
