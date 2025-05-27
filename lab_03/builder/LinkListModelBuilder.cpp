#include "LinkListModelBuilder.hpp"
#include "ListModelStructure.hpp"

LinkListModelBuilder::LinkListModelBuilder(std::shared_ptr<CarcassModelLoader> loader) : BaseCarcassModelBuilder(loader) {
    _model = std::make_shared<ListModelStructure>();
}
