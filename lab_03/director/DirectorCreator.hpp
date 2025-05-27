#pragma once

template <typename DirectorBase, typename DirectorProd, typename... Args>
requires NotAbstract<DirectorProd> && Derivative<DirectorProd, DirectorBase> && Constructible<DirectorProd, Args...>
std::shared_ptr<DirectorBase> DirectorCreator<DirectorBase, DirectorProd, Args...>::create(Args&&... args) {
    return std::make_shared<DirectorProd>(args...);
}