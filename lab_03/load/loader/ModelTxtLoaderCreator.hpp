#pragma once

#include "BaseLoaderCreator.hpp"
#include "ModelTxtLoader.hpp"

class ModelTxtLoaderCreator : public BaseLoaderCreator {
public:
    ModelTxtLoaderCreator() = default;
    ~ModelTxtLoaderCreator() override = default;

    std::shared_ptr<BaseLoader> createLoader(std::string filename) const override;
};
