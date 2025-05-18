#pragma once

#include "BaseModel.hpp"
#include "ModelStructure.hpp"

class CarcassModel : public BaseModel {
public:
    CarcassModel() : _modelStructure(new ModelStructure) {}
    explicit CarcassModel(const std::shared_ptr<ModelStructure> &modelStructure) : _modelStructure(modelStructure) {}
    explicit CarcassModel(const CarcassModel &model);
    ~CarcassModel() override = default;

    virtual Vertex getCenter() const override;
    virtual void transform() override;

protected:
    std::shared_ptr<ModelStructure> _modelStructure;
};
