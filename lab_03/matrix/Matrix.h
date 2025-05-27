#pragma once

#include <memory>
#include <vector>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix;
    size_t size;

public:
    Matrix();
    Matrix(size_t n, T initial_value = T());
    size_t getSize() const;
    void resize(size_t new_size, const T &initial_value = T());
    T &at(size_t row, size_t col);
    const T &at(size_t row, size_t col) const;
    std::vector<T> &operator[](size_t row);
    const std::vector<T> &operator[](size_t row) const;
    Matrix<T> operator+(const Matrix<T> &other) const;
    Matrix<T> &operator+=(const Matrix<T> &other);
    Matrix<T> operator*(const Matrix<T> &other) const;
    Matrix<T> &operator*=(const Matrix<T> &other);
    std::vector<T> multiplyLeft(const std::vector<T> &vec) const;
    std::vector<T> multiplyRight(const std::vector<T> &vec) const;
};

#include "Matrix.hpp"
