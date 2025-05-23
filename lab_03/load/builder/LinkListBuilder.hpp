#pragma once

#include "BaseModelBuilder.hpp"
#include "BaseLoader.hpp"
#include "LinkDotStructure.hpp"

class LinkListBuilder : public BaseModelBuilder {
public:
    explicit LinkListBuilder(std::shared_ptr<BaseLoader> loader);
};
