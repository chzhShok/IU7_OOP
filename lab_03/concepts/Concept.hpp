#pragma once

#include <concepts>

#include "BaseLoader.hpp"

template<typename Type>
concept Abstract = std::is_abstract_v<Type>;

template<typename Type>
concept NotAbstract = !std::is_abstract_v<Type>;

template<typename Derived, typename Base>
concept Derivative = std::derived_from<Derived, Base>;

template<typename Type, typename... Args>
concept Constructible = requires(Args... args) {
    Type{args...};
};

template<typename T>
concept Loadable = requires {
    Derivative<T, BaseLoader>;
    NotAbstract<T>;
};
