#pragma once

#include <memory>

#include "BaseLoader.hpp"

class BaseLoaderCreator {
public:
    BaseLoaderCreator() = default;
    virtual ~BaseLoaderCreator() = default;

    virtual std::shared_ptr<BaseLoader> createLoader(std::string filename) const = 0;
};
