#pragma once

#include <map>

#include "BaseDirectorCreator.hpp"
#include "DirectorCreator.h"
#include "Exception.hpp"

class DirectorSolution {
public:
    DirectorSolution();
    DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list);
    ~DirectorSolution();

    void registerCreator(std::size_t index, std::shared_ptr<BaseDirectorCreator> creator);
    bool check(std::size_t index);
    std::shared_ptr<BaseDirectorCreator> create(std::size_t index);

private:
    std::map<size_t, std::shared_ptr<BaseDirectorCreator>> __creators;
};
