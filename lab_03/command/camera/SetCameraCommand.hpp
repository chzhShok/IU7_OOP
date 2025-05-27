#pragma once

#include "BaseCameraCommand.hpp"

class SetCameraCommand : public BaseCameraCommand {
public:
    SetCameraCommand(std::size_t id);
    SetCameraCommand() = delete;
    virtual ~SetCameraCommand() = default;

    virtual void execute();
private:
    size_t _id;
};
