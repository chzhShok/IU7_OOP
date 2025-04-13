#pragma once

#include <memory>
#include <string>

#include "base_iterator.h"
#include "exception.h"

template<typename T>
class Matrix;

template<typename T>
class Iterator : public BaseIterator {
public:
    Iterator() = default;
    Iterator(const Matrix<T> &);
    Iterator(const Iterator<T> &);
    Iterator(const Iterator<T> &, size_t new_index);

    T &operator*();
    const T &operator*() const;
    T *operator->();
    const T *operator->() const;
    operator bool() const;

    T &value();
    const T &value() const;

    Iterator<T> &operator=(const Iterator<T> &iterator);

    Iterator<T> &operator+=(int value);
    Iterator<T> &operator++();  // префиксный инкремент
    Iterator<T> operator++(int);// постфиксный инкремент
    Iterator<T> operator+(int value) const;

    Iterator<T> &operator-=(int value);
    Iterator<T> &operator--();  // префиксный декремент
    Iterator<T> operator--(int);// постфиксный декремент
    Iterator<T> operator-(int value) const;

    bool operator<=(const Iterator<T> &iterator) const;
    bool operator<(const Iterator<T> &iterator) const;
    bool operator>=(const Iterator<T> &iterator) const;
    bool operator>(const Iterator<T> &iterator) const;
    bool operator==(const Iterator<T> &iterator) const;
    bool operator!=(const Iterator<T> &iterator) const;

    bool isEnd() const;
    bool isValid() const;

    Iterator<T> &next();

protected:
    void check_index(int line) const;
    void check_validity(int line) const;

private:
    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data{};
    int index = 0;
    size_t rows = 0;
    size_t cols = 0;
};

#include "iterator.hpp"
