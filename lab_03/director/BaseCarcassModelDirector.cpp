#include <iostream>

#include "BaseCarcassModelDirector.hpp"

BaseCarcassModelDirector::~BaseCarcassModelDirector() {};

BaseCarcassModelDirector::BaseCarcassModelDirector(std::shared_ptr<CarcassModelLoader> loader)
    : _loader(loader) {}

std::shared_ptr<BaseObject> BaseCarcassModelDirector::create() {
    if (_loader == nullptr) {
        std::cout << "BaseCarcassModelDirector::Create" << std::endl;
    }

    _builder->buildVertices();
    _builder->buildEdges();
    _builder->buildCenter();
    return _builder->get();
}
