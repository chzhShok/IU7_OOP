#pragma once

#include "BaseCameraCommand.hpp"

class MoveCameraCommand : public BaseCameraCommand {
public:
    MoveCameraCommand(std::size_t id, double dx, double dy, double dz);
    MoveCameraCommand() = delete;
    virtual ~MoveCameraCommand() = default;

    virtual void execute();

private:
    size_t __id;
    double __dx;
    double __dy;
    double __dz;
};
