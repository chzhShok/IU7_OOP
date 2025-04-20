#pragma once

#include <memory>
#include <string>

#include "base_iterator.h"
#include "exception.h"

template<MatrixElement T>
class Matrix;

template<MatrixElement T>
class Iterator : public BaseIterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    Iterator() = default;
    Iterator(const Matrix<T> &matrix);
    Iterator(const Iterator<T> &other);
    Iterator(const Iterator<T> &other, size_t new_index);

    reference operator*();
    const reference operator*() const;
    pointer operator->();
    const pointer operator->() const;
    reference operator[](int n);
    const reference operator[](int n) const;

    operator bool() const;

    reference value();
    const reference value() const;

    Iterator &operator=(const Iterator<T> &iterator);

    Iterator &operator+=(int value);
    Iterator &operator++();  // префиксный инкремент
    Iterator operator++(int);// постфиксный инкремент
    Iterator operator+(int value) const;

    Iterator &operator-=(int value);
    Iterator &operator--();  // префиксный декремент
    Iterator operator--(int);// постфиксный декремент
    Iterator operator-(int value) const;

    bool operator<=(const Iterator<T> &iterator) const;
    bool operator<(const Iterator<T> &iterator) const;
    bool operator>=(const Iterator<T> &iterator) const;
    bool operator>(const Iterator<T> &iterator) const;
    bool operator==(const Iterator<T> &iterator) const;
    bool operator!=(const Iterator<T> &iterator) const;

    bool isEnd() const;
    bool isValid() const;

    Iterator &next();

private:
    void check_index(int line) const;
    void check_validity(int line) const;

    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data{};
    int index = 0;
    size_t rows = 0;
    size_t cols = 0;
};

#include "iterator.hpp"
