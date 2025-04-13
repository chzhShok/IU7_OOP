#pragma once

template<typename T>
Matrix<T> Matrix<T>::operator+(const T &elem) const noexcept {
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] + elem;

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T &elem) const noexcept {
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] - elem;

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &elem) const noexcept {
    Matrix<T> tmp(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[i][j] = data[i][j] * elem;

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T &elem) const {
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

template<typename T>
Matrix<T> Matrix<T>::addElem(const T &elem) const noexcept {
    return operator+(elem);
}

template<typename T>
Matrix<T> Matrix<T>::subElem(const T &elem) const noexcept {
    return operator-(elem);
}

template<typename T>
Matrix<T> Matrix<T>::mulElem(const T &elem) const noexcept {
    return operator*(elem);
}

template<typename T>
Matrix<T> Matrix<T>::divElem(const T &elem) const {
    return operator/(elem);
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const T &elem) noexcept {
    for (auto &element: *this)
        element += elem;

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const T &elem) noexcept {
    for (auto &element: *this)
        element -= elem;

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const T &elem) noexcept {
    for (auto &element: *this)
        element *= elem;

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator/=(const T &elem) {
    if (elem == 0) {
        time_t currentTime = time(NULL);
        throw ZeroDivision(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] /= elem;

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::addEqElem(const T &elem) noexcept {
    return operator+=(elem);
}

template<typename T>
Matrix<T> &Matrix<T>::subEqElem(const T &elem) noexcept {
    return operator-=(elem);
}

template<typename T>
Matrix<T> &Matrix<T>::mulEqElem(const T &elem) noexcept {
    return operator*=(elem);
}

template<typename T>
Matrix<T> &Matrix<T>::divEqElem(const T &elem) {
    return operator/=(elem);
}
