#pragma once

#include <memory>
#include <string>

#include "base_iterator.h"
#include "concept.hpp"
#include "exception.h"

template<MatrixElement T>
class Matrix;

template<MatrixElement T>
class ConstIterator : public BaseIterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T *;
    using reference = const T &;

    ConstIterator(const Matrix<T> &);
    ConstIterator(const ConstIterator<T> &);
    ConstIterator(const ConstIterator<T> &, size_t new_index);

    const reference operator*() const;
    const pointer operator->() const;
    reference operator[](int n) const;

    operator bool() const;

    const reference value() const;

    ConstIterator &operator=(const ConstIterator<T> &iterator);

    ConstIterator &operator+=(int value);
    ConstIterator &operator++();  // префиксный инкремент
    ConstIterator operator++(int);// постфиксный инкремент
    ConstIterator operator+(int value) const;

    ConstIterator &operator-=(int value);
    ConstIterator &operator--();  // префиксный декремент
    ConstIterator operator--(int);// постфиксный декремент
    ConstIterator operator-(int value) const;

    bool operator<=(const ConstIterator<T> &iterator) const;
    bool operator<(const ConstIterator<T> &iterator) const;
    bool operator>=(const ConstIterator<T> &iterator) const;
    bool operator>(const ConstIterator<T> &iterator) const;
    bool operator==(const ConstIterator<T> &iterator) const;
    bool operator!=(const ConstIterator<T> &iterator) const;

    bool isEnd() const;
    bool isValid() const;

    ConstIterator &next();

private:
    void check_index(int line) const;
    void check_validity(int line) const;

    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data{};
    int index = 0;
    size_t rows = 0;
    size_t cols = 0;
};

#include "const_iterator.hpp"
