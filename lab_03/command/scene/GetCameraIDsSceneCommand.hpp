#pragma once

#include <vector>

#include "BaseSceneCommand.hpp"

class GetCameraIDsSceneCommand : public BaseSceneCommand {
public:
    GetCameraIDsSceneCommand();
    virtual ~GetCameraIDsSceneCommand() = default;

    virtual void execute();
    std::vector<size_t> getIDs();

private:
    std::vector<size_t> __ids;
};
