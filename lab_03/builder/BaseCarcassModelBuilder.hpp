#pragma once

#include "CarcassModel.hpp"
#include "ModelStructure.hpp"

class BaseCarcassModelBuilder {
public:
    BaseCarcassModelBuilder() = default;
    virtual ~BaseCarcassModelBuilder() = 0;

    virtual std::shared_ptr<CarcassModel> get();
    virtual void buildVertex(const Vertex &vertex);
    virtual void buildEdge(const Edge &edge);
    virtual void buildCenter(const Vertex &center);
    virtual bool isBuilt();

protected:
    std::shared_ptr<ModelStructure> _model;
};
