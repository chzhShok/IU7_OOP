#pragma once

#include <cstddef>

class BaseHashTable {
public:
    virtual ~BaseHashTable() = default;

    virtual bool isEmpty() const noexcept = 0;
    virtual double getLoadFactor() const noexcept = 0;

    virtual size_t getSize() const noexcept = 0;
    virtual double getMaxLoadFactor() const noexcept = 0;
    virtual size_t getBucketCount() const noexcept = 0;

protected:
    size_t size_ = 0;
    double max_load_factor_ = 1.0;
};
