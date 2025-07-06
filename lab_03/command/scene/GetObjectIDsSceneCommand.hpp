#pragma once

#include <vector>

#include "BaseSceneCommand.hpp"

class GetObjectIDsSceneCommand : public BaseSceneCommand {
public:
    GetObjectIDsSceneCommand();
    virtual ~GetObjectIDsSceneCommand() = default;

    virtual void execute();
    std::vector<std::size_t> getIDs();

private:
    std::vector<std::size_t> __ids;
};
