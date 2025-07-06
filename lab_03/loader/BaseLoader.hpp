#pragma once

class BaseLoader {
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = 0;

    virtual void open() = 0;
    virtual void close() = 0;
    virtual bool isOpen() = 0;
};
