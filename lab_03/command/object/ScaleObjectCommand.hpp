#pragma once

#include <cstddef>

#include "BaseObjectCommand.hpp"

class ScaleObjectCommand : public BaseObjectCommand {
public:
    ScaleObjectCommand() = delete;
    virtual ~ScaleObjectCommand() = default;
    ScaleObjectCommand(std::size_t id, double kx, double ky, double kz);

    virtual void execute();

private:
    size_t __id;
    double __kx;
    double __ky;
    double __kz;
};
