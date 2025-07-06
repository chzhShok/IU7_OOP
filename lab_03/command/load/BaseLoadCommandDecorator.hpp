#pragma once

#include "BaseLoadCommand.hpp"

class BaseLoadCommandDecorator : public BaseLoadCommand {
public:
    BaseLoadCommandDecorator(BaseLoadCommand &command);
    virtual ~BaseLoadCommandDecorator() = 0;

protected:
    BaseLoadCommand &_command;
};
