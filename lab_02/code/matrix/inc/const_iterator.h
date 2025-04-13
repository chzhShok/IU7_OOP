#pragma once

#include <memory>
#include <string>

#include "base_iterator.h"
#include "exception.h"

template<typename T>
class Matrix;

template<typename T>
class ConstIterator : public BaseIterator {
public:
    ConstIterator(const Matrix<T> &);
    ConstIterator(const ConstIterator<T> &);
    ConstIterator(const ConstIterator<T> &, size_t new_index);

    const T &operator*() const;
    const T *operator->() const;
    operator bool() const;

    const T &value() const;

    ConstIterator<T> &operator=(const ConstIterator<T> &iterator);

    ConstIterator<T> &operator+=(int value);
    ConstIterator<T> &operator++();  // префиксный инкремент
    ConstIterator<T> operator++(int);// постфиксный инкремент
    ConstIterator<T> operator+(int value) const;

    ConstIterator<T> &operator-=(int value);
    ConstIterator<T> &operator--();  // префиксный декремент
    ConstIterator<T> operator--(int);// постфиксный декремент
    ConstIterator<T> operator-(int value) const;

    bool operator<=(const ConstIterator<T> &iterator) const;
    bool operator<(const ConstIterator<T> &iterator) const;
    bool operator>=(const ConstIterator<T> &iterator) const;
    bool operator>(const ConstIterator<T> &iterator) const;
    bool operator==(const ConstIterator<T> &iterator) const;
    bool operator!=(const ConstIterator<T> &iterator) const;

    bool isEnd() const;
    bool isValid() const;

    ConstIterator<T> &next();

protected:
    void check_index(int line) const;
    void check_validity(int line) const;

private:
    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data{};
    int index = 0;
    size_t rows = 0;
    size_t cols = 0;
};

#include "const_iterator.hpp"
