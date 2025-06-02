#pragma once

#include <iostream>

#include "BaseCarcassModelBuilder.hpp"
#include "BaseDirector.hpp"
#include "CarcassModelLoader.hpp"
#include "CenterStrategy.hpp"

class BaseCarcassModelDirector : public BaseDirector {
public:
    BaseCarcassModelDirector(std::shared_ptr<CarcassModelLoader> loader);
    virtual ~BaseCarcassModelDirector() = 0;

    virtual void create();
    virtual std::shared_ptr<BaseObject> get();

protected:
    std::shared_ptr<BaseCarcassModelBuilder> _builder;
    std::shared_ptr<BaseCenterStrategy> _strategy;
    std::shared_ptr<CarcassModelLoader> _loader;
};
