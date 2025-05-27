#pragma once

#include "BaseCameraCommand.hpp"

class RemoveCameraCommand : public BaseCameraCommand {
public:
    RemoveCameraCommand(std::size_t id);
    RemoveCameraCommand() = delete;
    virtual ~RemoveCameraCommand() = default;

    virtual void execute();
private:
    size_t _id;
};
