#pragma once
#include "BaseCarcassModelDirector.hpp"


class LinkListModelDirector : public BaseCarcassModelDirector {
public:
    LinkListModelDirector(std::shared_ptr<CarcassModelLoader> loader);
    virtual ~LinkListModelDirector() = default;
};
