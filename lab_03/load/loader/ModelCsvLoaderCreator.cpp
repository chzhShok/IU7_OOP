#include "ModelCsvLoaderCreator.hpp"

std::shared_ptr<BaseLoader> ModelCsvLoaderCreator::createLoader(std::string filename) const {
    return std::make_shared<ModelCsvLoader>(filename);
}
