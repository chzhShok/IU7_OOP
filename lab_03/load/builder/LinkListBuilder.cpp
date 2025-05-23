#include "LinkListBuilder.hpp"

LinkListBuilder::LinkListBuilder(std::shared_ptr<BaseLoader> loader) : BaseModelBuilder(loader) {
    _model = std::make_shared<LinkDotStructure>();
}
