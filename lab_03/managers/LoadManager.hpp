#pragma once

#include <cstdlib>
#include <memory>

#include "BaseObject.hpp"
#include "DirectorSolution.hpp"
#include "LoaderSolution.hpp"

/// ID директоров
#define LISTBONEMODELDIRECTORCREATOR_ID 1
#define MATRIXBONEMODELDIRECTORCREATOR_ID 2

/// ID загрузчиков
#define TXTBONEMODELREADERCREATOR_ID 1
#define CSVBONEMODELREADERCREATOR_ID 2

class LoadManager {
public:
    LoadManager();
    ~LoadManager() = default;

    std::shared_ptr<BaseObject> load(std::size_t directorID, std::size_t readerID, std::string filename);

protected:
    DirectorSolution _dsolution;
    LoaderSolution _lsolution;
};
