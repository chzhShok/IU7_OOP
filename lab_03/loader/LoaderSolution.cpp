#include "LoaderSolution.hpp"

LoaderSolution::LoaderSolution() : __creators(std::map<std::size_t, std::shared_ptr<BaseLoaderCreator>>()) {}

LoaderSolution::~LoaderSolution() {}

LoaderSolution::LoaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseLoaderCreator>>> list) {
    for (const auto &pair: list)
        __creators[pair.first] = pair.second;
}

bool LoaderSolution::check(std::size_t index) {
    return __creators.find(index) != __creators.end();
}

std::shared_ptr<BaseLoaderCreator> LoaderSolution::create(std::size_t index) {
    if (check(index))
        return __creators[index];

    time_t now = time(nullptr);
    throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}


void LoaderSolution::registerCreator(std::size_t index, std::shared_ptr<BaseLoaderCreator> creator) {
    if (check(index)) {
        time_t now = time(nullptr);
        throw SolutionAlreadyInException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    __creators[index] = creator;
}
