#pragma once

#include "BaseCarcassModelDirector.hpp"
#include "ListModelBuilder.hpp"

class ListModelDirector : public BaseCarcassModelDirector {
public:
    ListModelDirector(std::shared_ptr<CarcassModelLoader> loader);
    virtual ~ListModelDirector() = default;
};
