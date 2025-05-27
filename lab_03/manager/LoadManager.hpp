#pragma once

#include "DirectorSolution.h"
#include "LoaderCreator.hpp"
#include "LoaderSolution.h"

#include <cstdlib>
#include <memory>

enum class LoaderType { TXT = 1,
                        CSV = 2 };

enum class DirectorType { LIST = 1,
                          MATRIX = 2 };

class LoadManager {
public:
    LoadManager();
    ~LoadManager() = default;

    std::shared_ptr<BaseObject> loadModelFile(std::size_t directorID, std::size_t loaderID, std::string filename);

protected:
    DirectorSolution _dsolution;
    LoaderSolution _lsolution;
};
