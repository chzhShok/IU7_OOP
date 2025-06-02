#include "BaseCarcassModelBuilder.hpp"

BaseCarcassModelBuilder::~BaseCarcassModelBuilder() {}

void BaseCarcassModelBuilder::buildVertex(const Vertex &vertex) {
    _model->addVertex(vertex);
}

void BaseCarcassModelBuilder::buildEdge(const Edge &edge) {
    _model->addEdge(edge);
}

void BaseCarcassModelBuilder::buildCenter(const Vertex &center) {
    _model->setCenter(center);
}

std::shared_ptr<CarcassModel> BaseCarcassModelBuilder::get() {
    return std::make_shared<CarcassModel>(_model);
}

bool BaseCarcassModelBuilder::isBuilt() {
    return _model->getVertices().size() != 0;
}
