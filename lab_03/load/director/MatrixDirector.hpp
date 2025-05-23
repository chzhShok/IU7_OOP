#pragma once

#include "BaseModelDirector.hpp"
#include "MatrixBuilder.hpp"

class MatrixDirector : public BaseModelDirector {
public:
    MatrixDirector(std::shared_ptr<BaseLoader> loader);
    virtual ~MatrixDirector() = default;
};
