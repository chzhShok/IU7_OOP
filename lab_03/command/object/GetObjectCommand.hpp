#pragma once

#include <cstddef>

#include "BaseCommand.hpp"
#include "BaseObject.hpp"

class GetObjectCommand : public BaseCommand {
public:
    GetObjectCommand() = delete;
    virtual ~GetObjectCommand() = default;
    GetObjectCommand(std::size_t id);

    virtual void execute();

private:
    size_t __id;
    std::shared_ptr<BaseObject> __object;
};
