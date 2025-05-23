#pragma once

#include "BaseLoader.hpp"
#include "CarcassModel.hpp"

class BaseModelBuilder {
public:
    BaseModelBuilder();
    explicit BaseModelBuilder(std::shared_ptr<BaseLoader> reader);
    ~BaseModelBuilder();

    virtual void buildPoints();
    virtual void buildEdges();
    virtual void buildCenter();
    virtual std::shared_ptr<CarcassModel> get();
    virtual bool isBuilt();

protected:
    std::shared_ptr<BaseLoader> _loader;
    std::shared_ptr<ModelStructure> _model;
    bool _isBuilt;
};
