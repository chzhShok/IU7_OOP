#pragma once

#include "BaseModelBuilder.hpp"
#include "BaseDirector.hpp"
#include "BaseLoader.hpp"

class BaseModelDirector : public BaseDirector {
public:
    BaseModelDirector(std::shared_ptr<BaseLoader> reader);
    virtual ~BaseModelDirector() = 0;

    virtual std::shared_ptr<BaseObject> create();

protected:
    std::shared_ptr<BaseModelBuilder> _builder;
    std::shared_ptr<BaseLoader> _loader;
};
