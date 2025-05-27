#include "LoaderSolution.h"

LoaderSolution::LoaderSolution() : _creators(std::map<std::size_t, std::shared_ptr<BaseLoaderCreator>>()) {}

LoaderSolution::~LoaderSolution() {}

LoaderSolution::LoaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseLoaderCreator>>> list) {
    for (const auto &pair: list)
        _creators[pair.first] = pair.second;
}

bool LoaderSolution::check(std::size_t index) {
    return _creators.find(index) != _creators.end();
}

void LoaderSolution::registerCreator(std::size_t index, std::shared_ptr<BaseLoaderCreator> creator) {
    if (check(index)) {
        time_t now = time(nullptr);
        throw SolutionAlreadyInException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    _creators[index] = creator;
}

void LoaderSolution::registerCreator(LoaderType type, std::shared_ptr<BaseLoaderCreator> creator) {
    registerCreator(static_cast<size_t>(type), creator);
}
