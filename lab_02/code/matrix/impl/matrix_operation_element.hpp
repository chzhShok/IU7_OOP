#pragma once

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> Matrix<T>::operator+(const U &elem) const noexcept {
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] + elem;

    return tmp;
}

template<typename T, typename U>
    requires ElementArithmetic<T, U>
Matrix<T> operator+(const U &elem, const Matrix<T> &matrix) {
    return matrix + elem;
}


template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> Matrix<T>::operator-(const U &elem) const noexcept {
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] - elem;

    return tmp;
}

template<typename T, typename U>
    requires ElementArithmetic<T, U>
Matrix<T> operator-(const U &elem, const Matrix<T> &matrix) {
    return matrix - elem;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> Matrix<T>::operator*(const U &elem) const noexcept {
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] * elem;

    return tmp;
}

template<typename T, typename U>
    requires ElementArithmetic<T, U>
Matrix<T> operator*(const U &elem, const Matrix<T> &matrix) {
    return matrix * elem;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> Matrix<T>::operator/(const U &elem) const {
    if (elem == 0) {
        time_t currentTime = time(NULL);
        throw ZeroDivision(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] / elem;

    return tmp;
}

template<typename T, typename U>
    requires ElementArithmetic<T, U>
Matrix<T> operator/(const U &elem, const Matrix<T> &matrix) {
    return matrix / elem;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> Matrix<T>::addElem(const U &elem) const noexcept {
    return operator+(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> Matrix<T>::subElem(const U &elem) const noexcept {
    return operator-(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> Matrix<T>::mulElem(const U &elem) const noexcept {
    return operator*(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> Matrix<T>::divElem(const U &elem) const {
    return operator/(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::operator+=(const U &elem) noexcept {
    for (auto &element: *this)
        element += elem;

    return *this;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::operator-=(const U &elem) noexcept {
    for (auto &element: *this)
        element -= elem;

    return *this;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::operator*=(const U &elem) noexcept {
    for (auto &element: *this)
        element *= elem;

    return *this;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::operator/=(const U &elem) {
    if (elem == 0) {
        time_t currentTime = time(NULL);
        throw ZeroDivision(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] /= elem;

    return *this;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::addEqElem(const U &elem) noexcept {
    return operator+=(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::subEqElem(const U &elem) noexcept {
    return operator-=(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::mulEqElem(const U &elem) noexcept {
    return operator*=(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::divEqElem(const U &elem) {
    return operator/=(elem);
}
