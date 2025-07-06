#include "DirectorSolution.hpp"

DirectorSolution::DirectorSolution() : __creators(std::map<std::size_t, std::shared_ptr<BaseDirectorCreator>>()) {}

DirectorSolution::~DirectorSolution() {}

DirectorSolution::DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list) {
    for (const auto &pair: list)
        __creators[pair.first] = pair.second;
}

bool DirectorSolution::check(std::size_t index) {
    return __creators.find(index) != __creators.end();
}

std::shared_ptr<BaseDirectorCreator> DirectorSolution::create(std::size_t index) {
    if (check(index))
        return __creators[index];

    time_t now = time(nullptr);
    throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}

void DirectorSolution::registerCreator(std::size_t index, std::shared_ptr<BaseDirectorCreator> creator) {
    if (check(index)) {
        time_t now = time(nullptr);
        throw SolutionAlreadyInException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    __creators[index] = creator;
}
