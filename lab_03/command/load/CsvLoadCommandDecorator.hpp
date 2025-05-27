#pragma once

#include "BaseLoadCommandDecorator.hpp"
#include "LoadManager.hpp"

class CsvLoadCommandDecorator : public BaseLoadCommandDecorator {
public:
    CsvLoadCommandDecorator() = delete;
    CsvLoadCommandDecorator(BaseLoadCommand &command, std::string filename);
    virtual ~CsvLoadCommandDecorator() = default;

    virtual void execute();

protected:
    std::string _filename;
};
