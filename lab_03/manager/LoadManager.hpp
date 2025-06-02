#pragma once

#include <cstdlib>
#include <memory>

#include "DirectorSolution.hpp"
#include "LoaderSolution.hpp"

constexpr std::size_t LISTMODELDIRECTORCREATOR_ID = 1;
constexpr std::size_t MATRIXMODELDIRECTORCREATOR_ID = 2;

constexpr std::size_t TXTMODELLOADERCREATOR_ID = 1;
constexpr std::size_t JSONMODELLOADERCREATOR_ID = 2;

class LoadManager {
public:
    LoadManager();
    ~LoadManager() = default;

    std::shared_ptr<BaseObject> loadBoneModelFile(std::size_t directorID, std::size_t loaderID, const char *filename);

protected:
    DirectorSolution _dsolution;
    LoaderSolution _lsolution;
};
