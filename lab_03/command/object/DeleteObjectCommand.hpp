#pragma once

#include "BaseObjectCommand.hpp"

class DeleteObjectCommand : public BaseObjectCommand {
public:
    DeleteObjectCommand() = delete;
    virtual ~DeleteObjectCommand() = default;
    DeleteObjectCommand(std::size_t id);

    virtual void execute();

private:
    size_t _id;
};
