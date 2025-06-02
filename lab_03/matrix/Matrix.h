#pragma once

#include <cstddef>
#include <memory>
#include <vector>

#include "Exception.hpp"

template<typename T>
class Matrix {
public:
    class MatrixRow {
        friend class Matrix;
        using value_type = T;
        using size_type = std::size_t;
        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;
        using reverse_iterator = typename std::vector<T>::reverse_iterator;
        using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;

    public:
        MatrixRow(std::size_t size);
        MatrixRow(std::size_t size, T value);
        MatrixRow();
        MatrixRow(const MatrixRow &other);
        MatrixRow(MatrixRow &&other);
        ~MatrixRow() = default;

        MatrixRow &operator=(const MatrixRow &other);
        MatrixRow &operator=(MatrixRow &&other);
        T &operator[](std::size_t index);
        T operator[](std::size_t index) const;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;
        std::size_t size() const;

    private:
        std::size_t __size;
        std::vector<T> __values;
        void add(T val);
        void resize(std::size_t inc, T val);
    };

    using value_type = typename std::shared_ptr<MatrixRow>;
    using size_type = typename std::size_t;
    using iterator = typename std::vector<value_type>::iterator;
    using const_iterator = typename std::vector<value_type>::const_iterator;
    using reverse_iterator = typename std::vector<value_type>::reverse_iterator;
    using const_reverse_iterator = typename std::vector<value_type>::const_reverse_iterator;

    Matrix(std::size_t size);
    Matrix();
    Matrix(const Matrix &other);
    Matrix(Matrix &&other);
    ~Matrix() = default;

    Matrix &operator=(const Matrix &other);
    Matrix &operator=(Matrix &&other);

    MatrixRow &operator[](std::size_t index);
    MatrixRow operator[](std::size_t index) const;

    std::size_t size() const;
    std::vector<T> getRow(std::size_t index) const;
    std::vector<T> getColumn(std::size_t index) const;
    Matrix &expend(std::size_t inc, T value);
    Matrix &resize(std::size_t new_size, T value);

    Matrix multiply(const Matrix &other) const;
    Matrix multiply(T other) const;
    Matrix operator*(T other) const;
    Matrix operator*(const Matrix &other) const;
    Matrix &operator*=(const Matrix &other);
    Matrix &operator*=(T other);

    std::vector<T> multiplyLeft(const std::vector<T> &other) const;
    std::vector<T> multiplyRight(const std::vector<T> &other) const;
    std::vector<T> operator*(const std::vector<T> &other) const;

    Matrix add(const Matrix &other) const;
    Matrix add(T other) const;
    Matrix operator+(T other) const;
    Matrix operator+(const Matrix &other) const;
    Matrix &operator+=(const Matrix &other);
    Matrix &operator+=(T other);

    Matrix subtract(const Matrix &other) const;
    Matrix subtract(T other) const;
    Matrix operator-(T other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix &operator-=(const Matrix &other);
    Matrix &operator-=(T other);
    Matrix &transpose();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

private:
    std::size_t __size;
    std::vector<std::shared_ptr<MatrixRow>> __rows;
};

#include "Matrix.hpp"
#include "MatrixRow.hpp"
