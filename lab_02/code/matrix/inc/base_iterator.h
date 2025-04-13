#pragma once

#include <cstddef>
#include <iterator>

class BaseIterator {
public:
    virtual ~BaseIterator() = default;

protected:
    size_t index = 0;
    size_t rows = 0;
    size_t cols = 0;
};
