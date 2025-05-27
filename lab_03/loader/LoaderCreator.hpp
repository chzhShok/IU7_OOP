#pragma once

#include "LoaderCreator.h"

template<Loadable LoaderBase, Loadable LoaderProd, typename... Args>
std::shared_ptr<LoaderBase> LoaderCreator<LoaderBase, LoaderProd, Args...>::create(Args &&...args) {
    return std::make_shared<LoaderProd>(args...);
}
