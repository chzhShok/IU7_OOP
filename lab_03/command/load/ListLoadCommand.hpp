#pragma once

#include "BaseLoadCommand.hpp"

class ListLoadCommand : public BaseLoadCommand {
public:
    ListLoadCommand();
    virtual ~ListLoadCommand() = default;

    virtual void execute();
};
