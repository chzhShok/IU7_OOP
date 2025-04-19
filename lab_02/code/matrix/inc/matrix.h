#pragma once

#include <initializer_list>
#include <iostream>

#include "base_matrix.h"
#include "concept.hpp"
#include "const_iterator.h"
#include "iterator.h"

template<MatrixElement T>
class Matrix : public BaseMatrix {
public:
    class MatrixRow;
    friend class Iterator<T>;
    friend class ConstIterator<T>;

    // конструкторы
    explicit Matrix() = default;
    explicit Matrix(int rows_size, int columns_size);
    Matrix(int rows_size, int columns_size, const T &value);
    Matrix(int rows_size, int columns_size, T **matrix);
    Matrix(std::initializer_list<std::initializer_list<T>> init_list);
    explicit Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix) noexcept;

    virtual ~Matrix() = default;

    // методы доступа
    int getRows() const noexcept;
    int getCols() const noexcept;
    bool isEmpty() const noexcept;

    MatrixRow operator[](int rows_size);
    const MatrixRow operator[](int rows_size) const;
    T &at(int rows_size, int columns_size);
    const T &at(int rows_size, int columns_size) const;
    T &operator()(int rows_size, int columns_size);
    const T &operator()(int rows_size, int columns_size) const;

    // присваивание
    Matrix &operator=(const Matrix &matrix);
    Matrix &operator=(Matrix &&matrix) noexcept;
    Matrix &operator=(std::initializer_list<std::initializer_list<T>> init_list);

    // математика с матрицами
    template<MatrixArithmetic<T> U>
    Matrix operator+(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix operator-(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix operator*(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix operator/(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix addMatrix(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix subMatrix(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix mulMatrix(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix divMatrix(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix &operator+=(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &operator-=(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &operator*=(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &operator/=(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &addEqMatrix(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &subEqMatrix(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &mulEqMatrix(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &divEqMatrix(const Matrix<U> &matrix);

    // математика с элементами
    template<ElementArithmetic<T> U>
    Matrix operator+(const U& elem) const noexcept;

    template<ElementArithmetic<T> U>
    Matrix operator-(const U &elem) const noexcept;

    template<ElementArithmetic<T> U>
    Matrix operator*(const U &elem) const noexcept;

    template<ElementArithmetic<T> U>
    Matrix operator/(const U &elem) const;

    template<ElementArithmetic<T> U>
    Matrix addElem(const U &elem) const noexcept;

    template<ElementArithmetic<T> U>
    Matrix subElem(const U &elem) const noexcept;

    template<ElementArithmetic<T> U>
    Matrix mulElem(const U &elem) const noexcept;

    template<ElementArithmetic<T> U>
    Matrix divElem(const U &elem) const;

    template<ElementArithmetic<T> U>
    Matrix &operator+=(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &operator-=(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &operator*=(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &operator/=(const U &elem);

    template<ElementArithmetic<T> U>
    Matrix &addEqElem(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &subEqElem(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &mulEqElem(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &divEqElem(const U &elem);

    // размеры
    void resize(int rows_size, int columns_size, const T &value = {});
    void resizeRows(int new_size, const T &filler = {});
    void resizeCols(int new_size, const T &filler = {});
    void insertRow(size_t pos, const T &filler = {});
    void insertCol(size_t pos, const T &filler = {});
    void deleteRow(size_t pos);
    void deleteCol(size_t pos);

    // доп методы
    template<ElementArithmetic U = T>
    void inverse();

    template<ElementArithmetic U = T>
    U determinant() const;

    bool isSquare() const;

    void transpose();
    void swapRows(size_t row1, size_t row2);
    void swapCols(size_t col1, size_t col2);

    Matrix operator-();
    Matrix neg();

    // итераторы
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

    // сравнение
    bool operator==(const Matrix &matrix) const;
    bool operator!=(const Matrix &matrix) const;

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

template<MatrixElement T>
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
