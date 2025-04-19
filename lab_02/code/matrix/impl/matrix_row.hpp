#pragma once

#include "exception.h"

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
