#pragma once

template<typename LoaderBase, typename LoaderProd, typename... Args>
    requires NotAbstract<LoaderProd> && Derivative<LoaderProd, LoaderBase> && Constructible<LoaderProd, Args...>
std::shared_ptr<LoaderBase> LoaderCreator<LoaderBase, LoaderProd, Args...>::create(Args &&...args) {
    return std::make_shared<LoaderProd>(std::forward<Args>(args)...);
}
