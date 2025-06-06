#include "CarcassModel.hpp"

CarcassModel::CarcassModel() : _model(nullptr) {}

CarcassModel::CarcassModel(std::shared_ptr<ModelStructure> model) : _model(model) {}

CarcassModel::CarcassModel(const CarcassModel &model) : _model(model._model) {}

void CarcassModel::accept(const Visitor &v) {
    v.visit(*this);
}

//void CarcassModel::transform(const TransformAction &action) {
//    _model->transform(action);
//}

void CarcassModel::transform(const TransformAction &action) {
    if (_model) {
        _model->transform(action);
    }
    // Не изменяем _transformMatrix базового класса,
    // так как трансформации применяются только к модели
}

Vertex CarcassModel::getCenter() const {
    return _model->getCenter();
}
