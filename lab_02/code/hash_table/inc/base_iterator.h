#pragma once

#include <cstddef>
#include <iterator>

class BaseIterator {
public:
    virtual ~BaseIterator() = default;

protected:
    size_t current_bucket = 0;
    size_t total_buckets = 0;
};
