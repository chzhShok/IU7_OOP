#pragma once

#include "BaseModelDirector.hpp"
#include "BaseLoader.hpp"
#include "LinkListBuilder.hpp"

class LinkListDirector : public BaseModelDirector {
public:
    LinkListDirector(std::shared_ptr<BaseLoader> loader);
    virtual ~LinkListDirector() = default;
};
