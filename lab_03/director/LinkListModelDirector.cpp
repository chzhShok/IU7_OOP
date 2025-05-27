#include "LinkListModelDirector.hpp"
#include "LinkListModelBuilder.hpp"

LinkListModelDirector::LinkListModelDirector(std::shared_ptr<CarcassModelLoader> loader) : BaseCarcassModelDirector(loader) {
    _builder = std::make_shared<LinkListModelBuilder>(_loader);
}
