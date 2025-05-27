#pragma once

#include "BaseCarcassModelBuilder.hpp"

class MatrixModelBuilder : public BaseCarcassModelBuilder {
public:
    explicit MatrixModelBuilder(std::shared_ptr<CarcassModelLoader> loader);
};
