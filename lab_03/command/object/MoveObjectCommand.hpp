#pragma once

#include "BaseObjectCommand.hpp"

class MoveObjectCommand : public BaseObjectCommand {
public:
    MoveObjectCommand() = delete;
    virtual ~MoveObjectCommand() = default;
    MoveObjectCommand(std::size_t id, double x, double y, double z);

    virtual void execute();

private:
    size_t _id;
    double _x;
    double _y;
    double _z;
};
