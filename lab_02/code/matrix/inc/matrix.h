#pragma once

#include <initializer_list>
#include <iostream>

#include "base_matrix.h"
#include "const_iterator.h"
#include "iterator.h"

template<typename T>
class Matrix : public BaseMatrix {
public:
    class MatrixRow;
    friend class Iterator<T>;
    friend class ConstIterator<T>;

    explicit Matrix(int rows_size = 0, int columns_size = 0);
    Matrix(int rows_size, int columns_size, const T &value);
    Matrix(int rows_size, int columns_size, T **matrix);
    Matrix(std::initializer_list<std::initializer_list<T>> init_list);
    explicit Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix);

    virtual ~Matrix() = default;

    int getRows() const noexcept;
    int getCols() const noexcept;
    bool isEmpty() const noexcept;

    Matrix<T> &operator=(const Matrix &matrix);
    Matrix<T> &operator=(Matrix &&matrix);
    Matrix<T> &operator=(std::initializer_list<std::initializer_list<T>> init_list);

    Matrix<T> operator+(const Matrix &matrix) const;
    Matrix<T> operator-(const Matrix &matrix) const;
    Matrix<T> operator*(const Matrix &matrix) const;
    Matrix<T> operator/(const Matrix &matrix) const;

    Matrix<T> addMatrix(const Matrix &matrix) const;
    Matrix<T> subMatrix(const Matrix &matrix) const;
    Matrix<T> mulMatrix(const Matrix &matrix) const;
    Matrix<T> divMatrix(const Matrix &matrix) const;

    Matrix<T> operator+(const T &elem) const noexcept;
    Matrix<T> operator-(const T &elem) const noexcept;
    Matrix<T> operator*(const T &elem) const noexcept;
    Matrix<T> operator/(const T &elem) const;

    Matrix<T> addElem(const T &elem) const noexcept;
    Matrix<T> subElem(const T &elem) const noexcept;
    Matrix<T> mulElem(const T &elem) const noexcept;
    Matrix<T> divElem(const T &elem) const;

    void resize(int rows_size, int columns_size, const T &value = {});
    void inverse();
    bool isSquare() const;
    T determinant() const;
    void transpose();

    Matrix<T> operator-();
    Matrix<T> neg();

    Matrix<T> &operator+=(const Matrix &matrix);
    Matrix<T> &operator-=(const Matrix &matrix);
    Matrix<T> &operator*=(const Matrix &matrix);
    Matrix<T> &operator/=(const Matrix &matrix);

    Matrix<T> &addEqMatrix(const Matrix &matrix);
    Matrix<T> &subEqMatrix(const Matrix &matrix);
    Matrix<T> &mulEqMatrix(const Matrix &matrix);
    Matrix<T> &divEqMatrix(const Matrix &matrix);

    Matrix<T> &operator+=(const T &elem) noexcept;
    Matrix<T> &operator-=(const T &elem) noexcept;
    Matrix<T> &operator*=(const T &elem) noexcept;
    Matrix<T> &operator/=(const T &elem);

    Matrix<T> &addEqElem(const T &elem) noexcept;
    Matrix<T> &subEqElem(const T &elem) noexcept;
    Matrix<T> &mulEqElem(const T &elem) noexcept;
    Matrix<T> &divEqElem(const T &elem);

    ConstIterator<T> begin() const;
    ConstIterator<T> end() const;
    Iterator<T> begin();
    Iterator<T> end();
    ConstIterator<T> cbegin() const;
    ConstIterator<T> cend() const;

    void fill(Iterator<T> start, const Iterator<T> &end, const T &value);
    void fill(Iterator<T> start, Iterator<T> source_start, const Iterator<T> &source_end);
    void fill(Iterator<T> start, ConstIterator<T> source_start, const ConstIterator<T> &source_end);
    void reverseSeq(Iterator<T> start, Iterator<T> end);

    void resizeRows(int new_size, const T &filler = {});
    void resizeCols(int new_size, const T &filler = {});

    void insertRow(size_t pos, const T &filler = {});
    void insertCol(size_t pos, const T &filler = {});

    void deleteRow(size_t pos);
    void deleteCol(size_t pos);

    bool operator==(const Matrix &matrix) const;
    bool operator!=(const Matrix &matrix) const;

    MatrixRow operator[](int rows_size);
    const MatrixRow operator[](int rows_size) const;
    T &at(int rows_size, int columns_size);
    const T &at(int rows_size, int columns_size) const;
    T &operator()(int rows_size, int columns_size);
    const T &operator()(int rows_size, int columns_size) const;

private:
    std::shared_ptr<MatrixRow[]> allocateMemory(int rows_size, int columns_size);
    void initialize(int rows_size, int columns_size);

    void checkSizes(const Matrix<T> &matrix) const;
    void checkMultSizes(const Matrix<T> &matrix) const;
    void checkIndex(size_t pos, size_t limit) const;

    void moveRow(size_t from, size_t to);
    void moveCol(size_t from, size_t to);

    std::shared_ptr<MatrixRow[]> data{nullptr};
    int rows = 0;
    int cols = 0;

public:
    class MatrixRow {
    public:
        friend class Iterator<T>;
        friend class ConstIterator<T>;

        MatrixRow(T *data, const size_t size) : data(data), size(size) {}
        MatrixRow() : data(nullptr), size(0) {}
        ~MatrixRow() = default;

        T &operator[](size_t index);
        const T &operator[](size_t index) const;

        void reset(T *ptr, const size_t new_size);
        void reset();
        T *getAddr();
        const T *getAddr() const;

    private:
        std::shared_ptr<T[]> data = nullptr;
        size_t size = 0;
    };
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix) {
    for (int i = 0; i < matrix.getRows(); ++i) {
        if (i != 0)
            out << '\n';

        for (int j = 0; j < matrix.getCols(); ++j) {
            if (j != 0)
                out << "      ";
            out << matrix[i][j];
        }
    }
    return out;
}

#include "matrix_iterator.hpp"
#include "matrix_methods.hpp"
#include "matrix_operation_element.hpp"
#include "matrix_operations_matrix.hpp"
#include "matrix_row.hpp"
