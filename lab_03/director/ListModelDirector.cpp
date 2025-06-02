#include <memory>

#include "ListModelDirector.hpp"

ListModelDirector::ListModelDirector(std::shared_ptr<CarcassModelLoader> loader) : BaseCarcassModelDirector(loader) {
    _builder = std::make_shared<ListModelBuilder>();
}
