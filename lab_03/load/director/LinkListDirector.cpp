#include "LinkListDirector.hpp"

LinkListDirector::LinkListDirector(std::shared_ptr<BaseLoader> loader) : BaseModelDirector(loader) {
    _builder = std::make_shared<LinkListBuilder>(_loader);
}
