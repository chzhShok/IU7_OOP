#pragma once

#include <map>

#include "BaseDirectorCreator.hpp"
#include "Concept.hpp"
#include "DirectorCreator.h"
#include "Exception.hpp"

enum class DirectorType;

class DirectorSolution {
public:
    DirectorSolution();
    DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list);

    void registerCreator(DirectorType type, std::shared_ptr<BaseDirectorCreator> creator);
    void registerCreator(std::size_t index, std::shared_ptr<BaseDirectorCreator> creator);
    bool check(std::size_t index);

    template<typename ConDirectorCreator>
        requires Derivative<ConDirectorCreator, BaseDirectorCreator>
    std::shared_ptr<ConDirectorCreator> create(std::size_t index);

    ~DirectorSolution();

private:
    std::map<size_t, std::shared_ptr<BaseDirectorCreator>> _creators;
};

#include "DirectorSolution.hpp"
