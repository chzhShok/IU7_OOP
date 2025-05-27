#include "MatrixModelBuilder.hpp"
#include "MatrixModelStructure.hpp"

MatrixModelBuilder::MatrixModelBuilder(std::shared_ptr<CarcassModelLoader> loader) : BaseCarcassModelBuilder(loader) {
    _model = std::make_shared<MatrixModelStructure>();
}
