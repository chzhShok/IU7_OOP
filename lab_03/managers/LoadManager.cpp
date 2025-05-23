#include "LoadManager.hpp"

LoadManager::LoadManager() {
    _dsolution.registerCreator(LISTBONEMODELDIRECTORCREATOR_ID, std::make_shared<ListBoneModelDirectorCreator>());
    _dsolution.registerCreator(MATRIXBONEMODELDIRECTORCREATOR_ID, std::make_shared<MatrixBoneModelDirectorCreator>());

    _lsolution.registerCreator(TXTBONEMODELREADERCREATOR_ID, std::make_shared<TxtBoneModelReaderCreator>());
    _lsolution.registerCreator(CSVBONEMODELREADERCREATOR_ID, std::make_shared<SqliteBoneModelReaderCreator>());
}


std::shared_ptr<Object> LoadManager::LoadBoneModelFile(std::size_t directorID, std::size_t ReaderID, std::string filename) {// done
    auto directorCr = _dsolution.Create<BoneModelDirectorCreator_t>(directorID);
    auto readerCr = _rsolution.Create<BoneModelReaderCreator_t>(ReaderID);// Done

    std::shared_ptr<BoneModelReader> boneModelReader = readerCr->Create(std::move(filename));
    std::shared_ptr<BaseBoneModelDirector> boneModelDirector = directorCr->Create(std::move(boneModelReader));
    return boneModelDirector->Create();
};
