#include "MatrixBuilder.hpp"

MatrixBuilder::MatrixBuilder(std::shared_ptr<BaseLoader> loader) : BaseModelBuilder(loader) {
    _model = std::make_shared<MatrixStructure>();
}
