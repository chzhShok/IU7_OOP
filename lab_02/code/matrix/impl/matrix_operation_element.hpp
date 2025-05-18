#pragma once

template<MatrixElement T>
template<typename U>
decltype(auto) Matrix<T>::operator+(const U &elem) const noexcept {
    return addElem(elem);
}

template<typename T, typename U>
    requires ElementArithmetic<T, U>
decltype(auto) operator+(const U &elem, const Matrix<T> &matrix) {
    return matrix + elem;
}

template<MatrixElement T>
template<typename U>
decltype(auto) Matrix<T>::operator-(const U &elem) const noexcept {
    return subElem(elem);
}

template<typename T, typename U>
    requires ElementArithmetic<T, U>
decltype(auto) operator-(const U &elem, const Matrix<T> &matrix) {
    return matrix - elem;
}

template<MatrixElement T>
template<typename U>
decltype(auto) Matrix<T>::operator*(const U &elem) const noexcept {
    return mulElem(elem);
}

template<typename T, typename U>
    requires ElementArithmetic<T, U>
decltype(auto) operator*(const U &elem, const Matrix<T> &matrix) {
    return matrix * elem;
}

template<MatrixElement T>
template<typename U>
decltype(auto) Matrix<T>::operator/(const U &elem) const {
    return divElem(elem);
}

template<typename T, typename U>
    requires ElementArithmetic<T, U>
decltype(auto) operator/(const U &elem, const Matrix<T> &matrix) {
    return matrix / elem;
}

template<MatrixElement T>
template<typename U>
decltype(auto) Matrix<T>::addElem(const U &elem) const noexcept {
    Matrix<T> result(*this);
    result += elem;
    return result;
}

template<MatrixElement T>
template<typename U>
decltype(auto) Matrix<T>::subElem(const U &elem) const noexcept {
    Matrix<T> result(*this);
    result -= elem;
    return result;
}

template<MatrixElement T>
template<typename U>
decltype(auto) Matrix<T>::mulElem(const U &elem) const noexcept {
    Matrix<T> result(*this);
    result *= elem;
    return result;
}

template<typename U>
inline bool is_zero(const U &elem) {
    if constexpr (std::is_arithmetic_v<U>)
        return elem == 0;
    return elem == U{};
}

template<MatrixElement T>
template<typename U>
decltype(auto) Matrix<T>::divElem(const U &elem) const {
    if (is_zero(elem)) {
        time_t currentTime = time(NULL);
        throw ZeroDivision(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    Matrix<T> result(*this);
    result /= elem;
    return result;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::operator+=(const U &elem) noexcept {
    return addEqElem(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::operator-=(const U &elem) noexcept {
    return subEqElem(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::operator*=(const U &elem) noexcept {
    return mulEqElem(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::operator/=(const U &elem) {
    return divEqElem(elem);
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::addEqElem(const U &elem) noexcept {
    for (auto &element: *this)
        element += elem;

    return *this;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::subEqElem(const U &elem) noexcept {
    for (auto &element: *this)
        element -= elem;

    return *this;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::mulEqElem(const U &elem) noexcept {
    for (auto &element: *this)
        element *= elem;

    return *this;
}

template<MatrixElement T>
template<ElementArithmetic<T> U>
Matrix<T> &Matrix<T>::divEqElem(const U &elem) {
    if (is_zero(elem)) {
        time_t currentTime = time(NULL);
        throw ZeroDivision(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    for (auto &element: *this)
        element /= elem;

    return *this;
}
