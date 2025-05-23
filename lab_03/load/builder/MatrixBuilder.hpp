#pragma once

#include "BaseLoader.hpp"
#include "BaseModelBuilder.hpp"
#include "MatrixStructure.hpp"

class MatrixBuilder : public BaseModelBuilder {
public:
    explicit MatrixBuilder(std::shared_ptr<BaseLoader> loader);
};