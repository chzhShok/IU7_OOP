#pragma once

#include "CarcassModel.hpp"
#include "CarcassModelLoader.hpp"
#include "ModelStructure.hpp"

class BaseCarcassModelBuilder {
public:
    BaseCarcassModelBuilder();
    explicit BaseCarcassModelBuilder(std::shared_ptr<CarcassModelLoader> reader);
    ~BaseCarcassModelBuilder();

    virtual void buildVertices();
    virtual void buildEdges();
    virtual void buildCenter();
    virtual std::shared_ptr<CarcassModel> get();
    virtual bool isBuilt();

protected:
    std::shared_ptr<CarcassModelLoader> _loader;
    std::shared_ptr<ModelStructure> _model;
    bool _isBuilt;
};
