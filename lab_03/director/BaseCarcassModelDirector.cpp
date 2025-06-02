#include <iostream>

#include "BaseCarcassModelDirector.hpp"

BaseCarcassModelDirector::~BaseCarcassModelDirector() {};

BaseCarcassModelDirector::BaseCarcassModelDirector(std::shared_ptr<CarcassModelLoader> loader) : _strategy(std::make_shared<CenterStrategy>()), _loader(loader) {}

void BaseCarcassModelDirector::create() {
    _loader->open();
    auto vertices = _loader->readVertices();
    auto edges = _loader->readEdges();
    _loader->close();

    for (auto &p: vertices)
        _builder->buildVertex(p);

    for (auto &e: edges)
        _builder->buildEdge(e);

    _builder->buildCenter(_strategy->CenterAlgorithm(vertices));
}

std::shared_ptr<BaseObject> BaseCarcassModelDirector::get() {
    return _builder->get();
}
