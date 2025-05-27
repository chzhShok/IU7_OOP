#pragma once

#include "BaseCarcassModelDirector.hpp"
#include "MatrixModelBuilder.hpp"

class MatrixModelDirector : public BaseCarcassModelDirector {
public:
    MatrixModelDirector(std::shared_ptr<CarcassModelLoader> loader);
    virtual ~MatrixModelDirector() = default;
};
