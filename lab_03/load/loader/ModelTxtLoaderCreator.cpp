#include "ModelTxtLoaderCreator.hpp"

std::shared_ptr<BaseLoader> ModelTxtLoaderCreator::createLoader(std::string filename) const {
    return std::make_shared<ModelTxtLoader>(filename);
}
