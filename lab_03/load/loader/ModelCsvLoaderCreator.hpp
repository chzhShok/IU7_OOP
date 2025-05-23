#pragma once

#include "BaseLoaderCreator.hpp"
#include "ModelCsvLoader.hpp"

class ModelCsvLoaderCreator : public BaseLoaderCreator {
public:
    ModelCsvLoaderCreator() = default;
    ~ModelCsvLoaderCreator() override = default;

    std::shared_ptr<BaseLoader> createLoader(std::string filename) const override;
};
