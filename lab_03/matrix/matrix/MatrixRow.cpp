#pragma once

#include "Matrix.h"

template<MatrixElement T>
T &Matrix<T>::MatrixRow::operator[](size_t index) {
    if (index >= size || index < 0) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    return data[index];
}

template<MatrixElement T>
const T &Matrix<T>::MatrixRow::operator[](size_t index) const {
    if (index >= size || index < 0) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    return data[index];
}

template<MatrixElement T>
void Matrix<T>::MatrixRow::reset(T *ptr, const size_t new_size) {
    if (new_size > 0 && !ptr) {
        time_t currentTime = time(NULL);
        throw InvalidArgument(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    data.reset(ptr);
    size = new_size;
}

template<MatrixElement T>
void Matrix<T>::MatrixRow::reset() {
    size = 0;
    data.reset();
}

template<MatrixElement T>
T *Matrix<T>::MatrixRow::getAddr() {
    return data.get();
}

template<MatrixElement T>
const T *Matrix<T>::MatrixRow::getAddr() const {
    return data.get();
}

template<MatrixElement T>
Matrix<T>::MatrixRow::iterator Matrix<T>::MatrixRow::begin() { return data.begin(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::iterator Matrix<T>::MatrixRow::end() { return data.end(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::const_iterator Matrix<T>::MatrixRow::begin() const { return data.begin(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::const_iterator Matrix<T>::MatrixRow::end() const { return data.end(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::const_iterator Matrix<T>::MatrixRow::cbegin() const { return data.cbegin(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::const_iterator Matrix<T>::MatrixRow::cend() const { return data.cend(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::reverse_iterator Matrix<T>::MatrixRow::rbegin() { return data.rbegin(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::reverse_iterator Matrix<T>::MatrixRow::rend() { return data.rend(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::const_reverse_iterator Matrix<T>::MatrixRow::rbegin() const { return data.rbegin(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::const_reverse_iterator Matrix<T>::MatrixRow::rend() const { return data.rend(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::const_reverse_iterator Matrix<T>::MatrixRow::crbegin() const { return data.crbegin(); }

template<MatrixElement T>
Matrix<T>::MatrixRow::const_reverse_iterator Matrix<T>::MatrixRow::crend() const { return data.crend(); }
