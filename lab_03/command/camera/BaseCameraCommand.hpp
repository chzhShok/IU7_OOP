#pragma once

#include "BaseCommand.hpp"

class BaseCameraCommand : public BaseCommand {
public:
    BaseCameraCommand() = default;
    virtual ~BaseCameraCommand() = 0;
};
