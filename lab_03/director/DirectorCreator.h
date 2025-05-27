#pragma once

#include "BaseCarcassModelDirector.hpp"
#include "BaseDirectorCreator.hpp"
#include "Concept.hpp"
#include "LinkListModelDirector.hpp"
#include "MatrixModelDirector.hpp"
#include <memory>

template<typename DirectorBase, typename DirectorProd, typename... Args>
    requires NotAbstract<DirectorProd> && Derivative<DirectorProd, DirectorBase> && Constructible<DirectorProd, Args...>
class DirectorCreator : public BaseDirectorCreatorTemplate<DirectorBase, Args...> {
public:
    virtual ~DirectorCreator() = default;
    virtual std::shared_ptr<DirectorBase> create(Args &&...args);
};

using LinkListModelDirectorCreator = DirectorCreator<BaseCarcassModelDirector, LinkListModelDirector, std::shared_ptr<CarcassModelLoader>>;
using MatriModelDirectorCreator = DirectorCreator<BaseCarcassModelDirector, MatrixModelDirector, std::shared_ptr<CarcassModelLoader>>;

#include "DirectorCreator.hpp"
