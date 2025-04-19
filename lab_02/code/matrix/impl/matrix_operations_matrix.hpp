#pragma once

#include "concept.hpp"

template<MatrixElement T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrix) {
    initialize(matrix.rows, matrix.cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = matrix[i][j];

    return *this;
}

template<MatrixElement T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&matrix) noexcept {
    data = matrix.data;
    rows = matrix.rows;
    cols = matrix.cols;

    return *this;
}

template<MatrixElement T>
Matrix<T> &Matrix<T>::operator=(std::initializer_list<std::initializer_list<T>> init_list) {
    if (init_list.size() == 0) {
        time_t currentTime = time(NULL);
        throw InvalidArgument(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    int rows_init_list = init_list.size();
    int cols_init_list = init_list.begin()->size();

    for (const auto &row: init_list)
        if (row.size() != cols_init_list) {
            time_t currentTime = time(NULL);
            throw InvalidArgument(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
        }

    resize(rows_init_list, cols_init_list);
    int i = 0;
    for (const auto &row: init_list)
        for (const auto &elem: row) {
            data[i / cols][i % cols] = elem;
            ++i;
        }

    return *this;
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> Matrix<T>::operator+(const Matrix<U> &matrix) const {
    checkSizes(matrix);
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] + matrix[i][j];

    return tmp;
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> Matrix<T>::operator-(const Matrix<U> &matrix) const {
    checkSizes(matrix);
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] - matrix[i][j];

    return tmp;
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> Matrix<T>::operator*(const Matrix<U> &matrix) const {
    checkMultSizes(matrix);
    Matrix<T> tmp(rows, matrix.cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < matrix.cols; ++j)
            for (int k = 0; k < cols; ++k)
                tmp[i][j] += data[i][k] * matrix[k][j];

    return tmp;
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> Matrix<T>::operator/(const Matrix<U> &matrix) const {
    Matrix<T> tmp(matrix);
    tmp.inverse();
    return operator*(tmp);
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> Matrix<T>::addMatrix(const Matrix<U> &matrix) const {
    return operator+(matrix);
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> Matrix<T>::subMatrix(const Matrix<U> &matrix) const {
    return operator-(matrix);
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> Matrix<T>::mulMatrix(const Matrix<U> &matrix) const {
    return operator*(matrix);
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> Matrix<T>::divMatrix(const Matrix<U> &matrix) const {
    return operator/(matrix);
}

template<MatrixElement T>
Matrix<T> Matrix<T>::operator-() {
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = -data[i][j];

    return tmp;
}

template<MatrixElement T>
Matrix<T> Matrix<T>::neg() {
    return operator-();
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> &Matrix<T>::operator+=(const Matrix<U> &matrix) {
    checkSizes(matrix);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] += matrix[i][j];

    return *this;
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> &Matrix<T>::operator-=(const Matrix<U> &matrix) {
    checkSizes(matrix);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] -= matrix[i][j];

    return *this;
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> &Matrix<T>::operator*=(const Matrix<U> &matrix) {
    checkSizes(matrix);
    checkMultSizes(matrix);

    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            for (int k = 0; k < rows; ++k)
                tmp[i][j] += data[i][k] + matrix[k][j];

    *this = tmp;

    return *this;
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> &Matrix<T>::operator/=(const Matrix<U> &matrix) {
    Matrix<T> tmp = operator/(matrix);
    *this = tmp;

    return *this;
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> &Matrix<T>::addEqMatrix(const Matrix<U> &matrix) {
    return operator+=(matrix);
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> &Matrix<T>::subEqMatrix(const Matrix<U> &matrix) {
    return operator-=(matrix);
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> &Matrix<T>::mulEqMatrix(const Matrix<U> &matrix) {
    return operator*=(matrix);
}

template<MatrixElement T>
template<MatrixArithmetic<T> U>
Matrix<T> &Matrix<T>::divEqMatrix(const Matrix<U> &matrix) {
    return operator/=(matrix);
}

template<MatrixElement T>
bool Matrix<T>::operator==(const Matrix &matrix) const {
    if ((rows != matrix.rows) || (cols != matrix.cols))
        return false;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (data[i][j] != matrix[i][j])
                return false;

    return true;
}

template<MatrixElement T>
bool Matrix<T>::operator!=(const Matrix &matrix) const {
    return !operator==(matrix);
}

template<MatrixElement T>
Matrix<T>::MatrixRow Matrix<T>::operator[](int rows_size) {
    return data[rows_size];
}

template<MatrixElement T>
const Matrix<T>::MatrixRow Matrix<T>::operator[](int rows_size) const {
    return data[rows_size];
}

template<MatrixElement T>
T &Matrix<T>::at(int rows_size, int columns_size) {
    return data[rows_size][columns_size];
}

template<MatrixElement T>
const T &Matrix<T>::at(int rows_size, int columns_size) const {
    return data[rows_size][columns_size];
}

template<MatrixElement T>
T &Matrix<T>::operator()(int rows_size, int columns_size) {
    return data[rows_size][columns_size];
}

template<MatrixElement T>
const T &Matrix<T>::operator()(int rows_size, int columns_size) const {
    return data[rows_size][columns_size];
}
