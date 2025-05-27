#include "BaseCarcassModelBuilder.hpp"

BaseCarcassModelBuilder::BaseCarcassModelBuilder() : _loader(nullptr), _isBuilt(false) {}

BaseCarcassModelBuilder::BaseCarcassModelBuilder(std::shared_ptr<CarcassModelLoader> reader) : _loader(reader), _isBuilt(false) {
    _loader->open();
}

BaseCarcassModelBuilder::~BaseCarcassModelBuilder() {
    if (_loader && _loader->isOpen())
        _loader->close();
}

void BaseCarcassModelBuilder::buildVertices() {
    if (_loader) {
        auto vertices = _loader->readVertices();

        for (auto &vertex: vertices)
            _model->addVertex(vertex);
    }
}

void BaseCarcassModelBuilder::buildEdges() {
    if (_loader) {
        auto edges = _loader->readEdges();

        for (auto &e: edges)
            _model->addEdge(e);
    }
}

void BaseCarcassModelBuilder::buildCenter() {
    if (_loader)
        _model->setCenter(_loader->readCenter());
}

std::shared_ptr<CarcassModel> BaseCarcassModelBuilder::get() {
    return std::make_shared<CarcassModel>(_model);
}

bool BaseCarcassModelBuilder::isBuilt() { return _isBuilt; }
