#pragma once

#include <functional>
#include <map>
#include <memory>

#include "BaseModelDirector.hpp"

class DirectorSolution {
public:
    DirectorSolution() = default;
    ~DirectorSolution() = default;

    void registerCreator(std::size_t index, std::function<std::shared_ptr<BaseModelDirector>()> creator);
    bool check(std::size_t index) const;

    std::shared_ptr<BaseModelDirector> create(std::size_t index) const;

private:
    std::map<std::size_t, std::function<std::shared_ptr<BaseModelDirector>()>> _creators;
};
