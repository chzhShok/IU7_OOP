#pragma once

#include "BaseLoadCommand.hpp"

class MatrixLoadCommand : public BaseLoadCommand {
public:
    MatrixLoadCommand();
    virtual ~MatrixLoadCommand() = default;

    virtual void execute();
};
