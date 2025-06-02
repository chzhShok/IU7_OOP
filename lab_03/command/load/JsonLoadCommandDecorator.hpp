#pragma once

#include "BaseLoadCommandDecorator.hpp"

class JsonLoadCommandDecorator : public BaseLoadCommandDecorator {
public:
    virtual ~JsonLoadCommandDecorator() = default;
    JsonLoadCommandDecorator() = delete;
    JsonLoadCommandDecorator(BaseLoadCommand &command, const char *filename);

    virtual void execute();

protected:
    const char *_filename;
};
