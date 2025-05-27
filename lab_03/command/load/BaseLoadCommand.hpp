#pragma once

#include "BaseCommand.hpp"

class BaseLoadCommand : public BaseCommand {
public:
    BaseLoadCommand() = default;
    virtual ~BaseLoadCommand() = 0;

    size_t getDirectorId();
    size_t getLoaderId();

protected:
    size_t _loader_id;
    size_t _director_id;
};
