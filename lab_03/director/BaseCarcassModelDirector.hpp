#pragma once

#include "BaseCarcassModelBuilder.hpp"
#include "BaseDirector.hpp"
#include "CarcassModelLoader.hpp"

class BaseCarcassModelDirector : public BaseDirector {
public:
    BaseCarcassModelDirector(std::shared_ptr<CarcassModelLoader> loader);

    virtual ~BaseCarcassModelDirector() = 0;

    virtual std::shared_ptr<BaseObject> create();

protected:
    std::shared_ptr<BaseCarcassModelBuilder> _builder;
    std::shared_ptr<CarcassModelLoader> _loader;
};
