#pragma once

#include "BaseObjectCommand.hpp"

class RotateObjectCommand : public BaseObjectCommand {
public:
    RotateObjectCommand() = delete;
    virtual ~RotateObjectCommand() = default;
    RotateObjectCommand(std::size_t id, double ox, double oy, double oz);

    virtual void execute();

private:
    size_t _id;
    double _ox;
    double _oy;
    double _oz;
};
