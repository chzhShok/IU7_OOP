#pragma once

#include "BaseSceneCommand.hpp"

class GetCameraIDsSceneCommand : public BaseSceneCommand {
public:
    GetCameraIDsSceneCommand();
    virtual ~GetCameraIDsSceneCommand() = default;

    virtual void execute();
    std::vector<std::size_t> getIDs();
private:
    std::vector<std::size_t> _ids;
};
