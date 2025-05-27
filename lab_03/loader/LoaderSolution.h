#pragma once

#include <map>

#include "BaseLoader.hpp"
#include "BaseLoaderCreator.hpp"
#include "Concept.hpp"
#include "Exception.hpp"

enum class LoaderType;

class LoaderSolution {
public:
    LoaderSolution();
    LoaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseLoaderCreator>>> list);

    void registerCreator(LoaderType type, std::shared_ptr<BaseLoaderCreator> creator);
    void registerCreator(std::size_t index, std::shared_ptr<BaseLoaderCreator> creator);
    bool check(std::size_t index);

    template<typename ConLoaderCreator>
        requires Derivative<ConLoaderCreator, BaseLoaderCreator>
    std::shared_ptr<ConLoaderCreator> create(std::size_t index);

    ~LoaderSolution();

private:
    std::map<size_t, std::shared_ptr<BaseLoaderCreator>> _creators;
};

#include "LoaderSolution.hpp"
