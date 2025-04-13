#pragma once

#include <cstddef>

class BaseMatrix {
public:
    virtual ~BaseMatrix() = default;

    virtual bool isEmpty() const noexcept = 0;
    virtual int getRows() const noexcept = 0;
    virtual int getCols() const noexcept = 0;

protected:
    int rows = 0;
    int cols = 0;
};
