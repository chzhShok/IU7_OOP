#include "DirectorSolution.hpp"
#include <stdexcept>

void DirectorSolution::registerCreator(std::size_t index, std::function<std::shared_ptr<BaseModelDirector>()> creator) {
    _creators[index] = std::move(creator);
}

bool DirectorSolution::check(std::size_t index) const {
    return _creators.contains(index);
}

std::shared_ptr<BaseModelDirector> DirectorSolution::create(std::size_t index) const {
    auto it = _creators.find(index);
    if (it == _creators.end())
        throw std::runtime_error("Director not registered with given index");

    return it->second();
}
