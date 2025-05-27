#pragma once

#include "BaseCarcassModelBuilder.hpp"

class LinkListModelBuilder : public BaseCarcassModelBuilder {
public:
    explicit LinkListModelBuilder(std::shared_ptr<CarcassModelLoader> loader);
};
