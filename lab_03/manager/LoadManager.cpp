#include <memory>

#include "LoadManager.hpp"
#include "LoaderCreator.h"

LoadManager::LoadManager() {
    _dsolution.registerCreator(LISTMODELDIRECTORCREATOR_ID, std::make_shared<ListModelDirectorCreator>());
    _dsolution.registerCreator(MATRIXMODELDIRECTORCREATOR_ID, std::make_shared<MatrixModelDirectorCreator>());

    _lsolution.registerCreator(TXTMODELLOADERCREATOR_ID, std::make_shared<TxtCarcassModelLoaderCreator>());
    _lsolution.registerCreator(JSONMODELLOADERCREATOR_ID, std::make_shared<SqlCarcassModelLoaderCreator>());
}

std::shared_ptr<BaseObject> LoadManager::loadBoneModelFile(std::size_t directorID, std::size_t loaderID, const char *filename) {
    std::shared_ptr<BaseDirectorCreator> absDirectorCreator = _dsolution.create(directorID);
    std::shared_ptr<BaseLoaderCreator> absLoaderCreator = _lsolution.create(loaderID);

    std::shared_ptr<CarcassModelDirectorCreator_t> carcassModelDirectorCreator = std::dynamic_pointer_cast<CarcassModelDirectorCreator_t>(absDirectorCreator);
    if (carcassModelDirectorCreator == nullptr) {
        time_t now = time(nullptr);
        throw LoadManagerWrongDirectorException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<CarcassModelLoaderCreator_t> carcassModelLoaderCreator = std::dynamic_pointer_cast<CarcassModelLoaderCreator_t>(absLoaderCreator);
    if (carcassModelLoaderCreator == nullptr) {
        time_t now = time(nullptr);
        throw LoadManagerWrongLoaderException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<CarcassModelLoader> carcassModelLoader = carcassModelLoaderCreator->create(std::move(filename));
    std::shared_ptr<BaseCarcassModelDirector> carcassModelDirector = carcassModelDirectorCreator->create(std::move(carcassModelLoader));
    carcassModelDirector->create();
    return carcassModelDirector->get();
}
