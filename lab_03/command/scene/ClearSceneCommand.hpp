#pragma once

#include "BaseSceneCommand.hpp"

class ClearSceneCommand : public BaseSceneCommand {
public:
    ClearSceneCommand() = default;
    virtual ~ClearSceneCommand() = default;

    virtual void execute();
};
