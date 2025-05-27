#include "MatrixModelDirector.hpp"

MatrixModelDirector::MatrixModelDirector(std::shared_ptr<CarcassModelLoader> loader) : BaseCarcassModelDirector(loader) {
    _builder = std::make_shared<MatrixModelBuilder>(_loader);
}
