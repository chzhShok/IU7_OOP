#pragma once

#include <map>

#include "BaseLoader.hpp"
#include "BaseLoaderCreator.hpp"
#include "Exception.hpp"

class LoaderSolution {
public:
    LoaderSolution();
    LoaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseLoaderCreator>>> list);
    ~LoaderSolution();

    void registerCreator(std::size_t index, std::shared_ptr<BaseLoaderCreator> creator);
    bool check(std::size_t index);
    std::shared_ptr<BaseLoaderCreator> create(std::size_t index);

private:
    std::map<size_t, std::shared_ptr<BaseLoaderCreator>> __creators;
};
