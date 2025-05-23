#pragma once

#include <map>

#include "BaseLoader.hpp"
#include "BaseLoaderCreator.hpp"
#include "Concepts.hpp"

class LoaderSolution {
public:
    LoaderSolution();
    LoaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseLoaderCreator>>> list);
    ~LoaderSolution();

    void registerCreator(std::size_t index, std::shared_ptr<BaseLoaderCreator> creator);
    bool check(std::size_t index);

    template<typename ConReaderCreator>
        requires Derivative<ConReaderCreator, BaseLoaderCreator>
    std::shared_ptr<ConReaderCreator> create(std::size_t index);

private:
    std::map<size_t, std::shared_ptr<BaseLoaderCreator>> _creators;
};
