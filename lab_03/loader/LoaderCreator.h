#pragma once

#include <memory>

#include "BaseLoaderCreator.hpp"
#include "CarcassModelLoader.hpp"
#include "Concept.hpp"
#include "JsonModelLoader.hpp"
#include "TxtModelLoader.hpp"

template<typename LoaderBase, typename LoaderProd, typename... Args>
    requires NotAbstract<LoaderProd> && Derivative<LoaderProd, LoaderBase> && Constructible<LoaderProd, Args...>
class LoaderCreator : public BaseLoaderCreatorTemplate<LoaderBase, Args...> {
public:
    virtual ~LoaderCreator() = default;

    virtual std::shared_ptr<LoaderBase> create(Args &&...args);
};

using TxtCarcassModelLoaderCreator = LoaderCreator<CarcassModelLoader, TxtModelLoader, const char *>;
using SqlCarcassModelLoaderCreator = LoaderCreator<CarcassModelLoader, JsonModelLoader, const char *>;

#include "LoaderCreator.hpp"
