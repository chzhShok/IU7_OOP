#pragma once

#include "BaseLoadCommandDecorator.hpp"
#include "LoadManager.hpp"

class TxtLoadCommandDecorator : public BaseLoadCommandDecorator {
public:
    TxtLoadCommandDecorator() = delete;
    TxtLoadCommandDecorator(BaseLoadCommand &command, std::string filename);
    virtual ~TxtLoadCommandDecorator() = default;

    virtual void execute();
protected:
    std::string _filename;
};
