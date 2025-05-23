#include "MatrixDirector.hpp"

MatrixDirector::MatrixDirector(std::shared_ptr<BaseLoader> loader) : BaseModelDirector(loader) {
    _builder = std::make_shared<MatrixBuilder>(_loader);
}
