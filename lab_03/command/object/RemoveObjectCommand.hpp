#pragma once

#include <cstddef>

#include "BaseObjectCommand.hpp"

class RemoveObjectCommand : public BaseObjectCommand {
public:
    RemoveObjectCommand() = delete;
    virtual ~RemoveObjectCommand() = default;
    RemoveObjectCommand(std::size_t id);

    virtual void execute();

private:
    size_t __id;
};