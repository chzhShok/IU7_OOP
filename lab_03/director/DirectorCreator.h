#pragma once

#include <memory>

#include "BaseCarcassModelDirector.hpp"
#include "BaseDirectorCreator.hpp"
#include "Concept.hpp"
#include "ListModelDirector.hpp"
#include "MatrixModelDirector.hpp"

template<typename DirectorBase, typename DirectorProd, typename... Args>
    requires NotAbstract<DirectorProd> && Derivative<DirectorProd, DirectorBase> && Constructible<DirectorProd, Args...>
class DirectorCreator : public BaseDirectorCreatorTemplate<DirectorBase, Args...> {
public:
    virtual ~DirectorCreator() = default;
    virtual std::shared_ptr<DirectorBase> create(Args &&...args);
};

using ListModelDirectorCreator = DirectorCreator<BaseCarcassModelDirector, ListModelDirector, std::shared_ptr<CarcassModelLoader>>;
using MatrixModelDirectorCreator = DirectorCreator<BaseCarcassModelDirector, MatrixModelDirector, std::shared_ptr<CarcassModelLoader>>;

#include "DirectorCreator.hpp"
