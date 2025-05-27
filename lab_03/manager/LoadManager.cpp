#include "LoadManager.hpp"

LoadManager::LoadManager() {
    _dsolution.registerCreator(DirectorType::LIST, std::make_shared<LinkListModelDirectorCreator>());
    _dsolution.registerCreator(DirectorType::MATRIX, std::make_shared<MatriModelDirectorCreator>());

    _lsolution.registerCreator(LoaderType::TXT, std::make_shared<TxtModelLoaderCreator>());
    _lsolution.registerCreator(LoaderType::CSV, std::make_shared<CsvModelLoaderCreator>());
}

std::shared_ptr<BaseObject> LoadManager::loadModelFile(std::size_t directorID, std::size_t LoaderID, std::string filename) {
    auto directorCreator = _dsolution.create<CarcassModelDirectorCreator_t>(directorID);
    auto loaderCreator = _lsolution.create<CarcassModelLoaderCreator_t>(LoaderID);

    std::shared_ptr<CarcassModelLoader> carcassModelLoader = loaderCreator->create(std::move(filename));
    std::shared_ptr<BaseCarcassModelDirector> carcassModelDirector = directorCreator->create(std::move(carcassModelLoader));
    return carcassModelDirector->create();
}
