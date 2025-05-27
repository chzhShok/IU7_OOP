#pragma once

#include "BaseModel.hpp"
#include "DrawVisitor.hpp"
#include "ModelStructure.hpp"
#include "TransformAction.hpp"
#include "TransformVisitor.hpp"
#include <memory>

class CarcassModel : public BaseModel {
    friend class DrawVisitor;
    friend class TransformVisitor;

public:
    CarcassModel();
    explicit CarcassModel(std::shared_ptr<ModelStructure>);
    explicit CarcassModel(const CarcassModel &other);
    ~CarcassModel() = default;

    virtual void accept(std::shared_ptr<Visitor> v);
    virtual Vertex getCenter() const;

protected:
    std::shared_ptr<ModelStructure> _model;
};
