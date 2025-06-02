#pragma once

#include "BaseCarcassModelBuilder.hpp"
#include "CarcassModel.hpp"
#include "ListModelStructure.hpp"

class ListModelBuilder : public BaseCarcassModelBuilder {
public:
    ListModelBuilder();
    virtual ~ListModelBuilder() = default;
};
