#pragma once

#include "BaseCameraCommand.hpp"

class AddCameraCommand : public BaseCameraCommand {
public:
    AddCameraCommand(const Vertex &position);
    AddCameraCommand() = delete;
    virtual ~AddCameraCommand() = default;
    virtual void execute();

private:
    Vertex __position;
};
