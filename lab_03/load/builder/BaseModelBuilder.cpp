#include "BaseModelBuilder.hpp"

BaseModelBuilder::BaseModelBuilder() : _loader(nullptr), _isBuilt(false) {}

BaseModelBuilder::BaseModelBuilder(std::shared_ptr<BaseLoader> loader) : _loader(loader), _isBuilt(false) {
    _loader->open();
}

BaseModelBuilder::~BaseModelBuilder() {
    if (_loader && _loader->isOpen())
        _loader->close();
}

void BaseModelBuilder::buildPoints() {
    if (_loader) {
        auto vertices = _loader->readVertices();

        for (auto &v: vertices)
            _model->addVertex(v);
    }
}

void BaseModelBuilder::buildEdges() {
    if (_loader) {
        auto edges = _loader->readEdges();

        for (auto &e: edges)
            _model->addEdge(e);
    }
}

void BaseModelBuilder::buildCenter() {
    if (_loader)
        _model->setCenter(_loader->readCenter());
}

std::shared_ptr<CarcassModel> BaseModelBuilder::get() {
    return std::make_shared<CarcassModel>(_model);
}

bool BaseModelBuilder::isBuilt() {
    return _isBuilt;
}
