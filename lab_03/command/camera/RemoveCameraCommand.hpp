#pragma once

#include <cstddef>

#include "BaseCameraCommand.hpp"

class RemoveCameraCommand : public BaseCameraCommand {
public:
    RemoveCameraCommand(size_t id);
    RemoveCameraCommand() = delete;
    virtual ~RemoveCameraCommand() = default;

    virtual void execute();

private:
    size_t __id;
};
