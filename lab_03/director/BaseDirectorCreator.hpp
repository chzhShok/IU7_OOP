#pragma once

#include "BaseCarcassModelDirector.hpp"
#include "BaseDirector.hpp"
#include "BaseLoader.hpp"

class BaseDirectorCreator {
public:
    virtual ~BaseDirectorCreator() = default;
};

template<typename Director, typename... Args>
class BaseDirectorCreatorTemplate : public BaseDirectorCreator {
public:
    virtual ~BaseDirectorCreatorTemplate() = default;

    virtual std::shared_ptr<Director> create(Args &&...args) = 0;
};

using CarcassModelDirectorCreator_t = BaseDirectorCreatorTemplate<BaseCarcassModelDirector, std::shared_ptr<CarcassModelLoader>>;
