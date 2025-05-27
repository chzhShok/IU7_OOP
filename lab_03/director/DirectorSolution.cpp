#include "DirectorSolution.h"

DirectorSolution::DirectorSolution() : _creators(std::map<std::size_t, std::shared_ptr<BaseDirectorCreator>>()) {}

DirectorSolution::~DirectorSolution() {}

DirectorSolution::DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list) {
    for (const auto &pair: list) {
        _creators[pair.first] = pair.second;
    }
}

bool DirectorSolution::check(std::size_t index) {
    return _creators.find(index) != _creators.end();
}

void DirectorSolution::registerCreator(std::size_t index, std::shared_ptr<BaseDirectorCreator> creator) {
    if (check(index)) {
        time_t now = time(nullptr);
        throw SolutionAlreadyInException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    _creators[index] = creator;
}

void DirectorSolution::registerCreator(DirectorType type, std::shared_ptr<BaseDirectorCreator> creator) {
    registerCreator(static_cast<std::size_t>(type), creator);
}
