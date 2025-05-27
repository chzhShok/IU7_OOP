#pragma once

#include <concepts>
#include <memory>

#include "CarcassModelLoader.hpp"

class BaseLoaderCreator {
public:
    virtual ~BaseLoaderCreator() = default;
};

template<typename Loader, typename... Args>
class BaseLoaderCreatorTemplate : public BaseLoaderCreator {
public:
    virtual ~BaseLoaderCreatorTemplate() = default;

    virtual std::shared_ptr<Loader> create(Args &&...args) = 0;
};

using CarcassModelLoaderCreator_t = BaseLoaderCreatorTemplate<CarcassModelLoader, std::string>;
