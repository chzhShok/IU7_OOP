#pragma once

#include <memory>

#include "BaseCarcassModelDirector.hpp"
#include "BaseDirector.hpp"
#include "BaseLoader.hpp"

class BaseDirectorCreator {
public:
    virtual ~BaseDirectorCreator() = default;
};

template<typename Director, typename Arg>
class BaseDirectorCreatorTemplate : public BaseDirectorCreator {
public:
    virtual ~BaseDirectorCreatorTemplate() = default;
    virtual std::shared_ptr<Director> create(Arg &&arg) = 0;
};

using CarcassModelDirectorCreator_t = BaseDirectorCreatorTemplate<BaseCarcassModelDirector, std::shared_ptr<CarcassModelLoader>>;
