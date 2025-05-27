#pragma once

#include "BaseLoaderCreator.hpp"
#include "CarcassModelLoader.hpp"
#include "Concept.hpp"
#include "CsvModelLoader.hpp"
#include "TxtModelLoader.hpp"

#include <memory>

template<Loadable LoaderBase, Loadable LoaderProd, typename... Args>
class LoaderCreator : public BaseLoaderCreatorTemplate<LoaderBase, Args...> {
public:
    virtual ~LoaderCreator() = default;
    virtual std::shared_ptr<LoaderBase> create(Args &&...args);
};

using TxtModelLoaderCreator = LoaderCreator<CarcassModelLoader, TxtModelLoader, std::string>;
using CsvModelLoaderCreator = LoaderCreator<CarcassModelLoader, CsvModelLoader, std::string>;

#include "LoaderCreator.hpp"
