#pragma once

#include <cstddef>

#include "BaseObjectCommand.hpp"

class MoveObjectCommand : public BaseObjectCommand {
public:
    MoveObjectCommand() = delete;
    virtual ~MoveObjectCommand() = default;
    MoveObjectCommand(size_t id, double x, double y, double z);

    virtual void execute();

private:
    size_t __id;
    double __x;
    double __y;
    double __z;
};
