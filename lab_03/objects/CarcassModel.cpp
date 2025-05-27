#include "CarcassModel.hpp"

CarcassModel::CarcassModel() : _model(nullptr) {}

CarcassModel::CarcassModel(std::shared_ptr<ModelStructure> model) : _model(model) {}

CarcassModel::CarcassModel(const CarcassModel &model) : _model(model._model) {}

void CarcassModel::accept(std::shared_ptr<Visitor> v) {
    v->visit(*this);
}

Vertex CarcassModel::getCenter() const {
    return _model->getCenter();
}
