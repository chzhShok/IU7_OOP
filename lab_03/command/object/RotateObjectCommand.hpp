#pragma once

#include <cstddef>

#include "BaseObjectCommand.hpp"

class RotateObjectCommand : public BaseObjectCommand {
public:
    RotateObjectCommand() = delete;
    virtual ~RotateObjectCommand() = default;
    RotateObjectCommand(std::size_t id, double ox, double oy, double oz);

    virtual void execute();

private:
    size_t __id;
    double __ox;
    double __oy;
    double __oz;
};
