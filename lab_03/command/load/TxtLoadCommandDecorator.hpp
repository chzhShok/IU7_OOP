#pragma once

#include "BaseLoadCommandDecorator.hpp"

class TxtLoadCommandDecorator : public BaseLoadCommandDecorator {
public:
    virtual ~TxtLoadCommandDecorator() = default;
    TxtLoadCommandDecorator() = delete;
    TxtLoadCommandDecorator(BaseLoadCommand &command, const char *filename);

    virtual void execute();

protected:
    const char *_filename;
};
