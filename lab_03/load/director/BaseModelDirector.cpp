#include <iostream>

#include "BaseModelDirector.hpp"

BaseModelDirector::~BaseModelDirector() {};

BaseModelDirector::BaseModelDirector(std::shared_ptr<BaseLoader> reader) : _loader(reader) {}

std::shared_ptr<BaseObject> BaseModelDirector::create() {
    if (_loader == nullptr)
        std::cout << "BaseBoneModelDirector::Create" << std::endl;

    _builder->buildPoints();
    _builder->buildEdges();
    _builder->buildCenter();

    return _builder->get();
}
