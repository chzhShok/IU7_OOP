#pragma once

template<typename T>
Iterator<T>::Iterator(const Matrix<T> &matrix) {
    index = 0;
    rows = matrix.rows;
    cols = matrix.cols;
    data = matrix.data;
}

template<typename T>
Iterator<T>::Iterator(const Iterator<T> &iterator) {
    data = iterator.data;
    index = iterator.index;
    rows = iterator.rows;
    cols = iterator.cols;
}

template<typename T>
Iterator<T>::Iterator(const Iterator<T> &iterator, size_t new_index) {
    index = new_index;
    data = iterator.data;
    rows = iterator.rows;
    cols = iterator.cols;
}

template<typename T>
T &Iterator<T>::operator*() {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols][index % cols];
}

template<typename T>
const T &Iterator<T>::operator*() const {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols][index % cols];
}

template<typename T>
T *Iterator<T>::operator->() {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols].getAddr() + (index % cols);
}

template<typename T>
const T *Iterator<T>::operator->() const {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols].getAddr() + (index % cols);
}

template<typename T>
Iterator<T>::operator bool() const {
    return data.expired();
}

template<typename T>
T &Iterator<T>::value() {
    return operator*();
}

template<typename T>
const T &Iterator<T>::value() const {
    return operator*();
}

template<typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &iterator) {
    check_validity(__LINE__);

    data = iterator.data, index = iterator.index, rows = iterator.rows, cols = iterator.cols;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator+=(int value) {
    check_validity(__LINE__);

    index += value;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++() {
    check_validity(__LINE__);

    if (index < cols * rows)
        ++index;

    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
    check_validity(__LINE__);

    Iterator<T> iterator(*this);
    ++(*this);
    return iterator;
}

template<typename T>
Iterator<T> Iterator<T>::operator+(const int value) const {
    check_validity(__LINE__);

    Iterator<T> iterator(*this);

    if (index + value <= rows * cols)
        iterator += value;

    return iterator;
}

template<typename T>
Iterator<T> &Iterator<T>::operator-=(int value) {
    check_validity(__LINE__);

    index -= value;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator--() {
    check_validity(__LINE__);

    if (index > 0)
        --index;

    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int) {
    check_validity(__LINE__);

    Iterator<T> iterator(*this);
    --(*this);
    return iterator;
}

template<typename T>
Iterator<T> Iterator<T>::operator-(int value) const {
    check_validity(__LINE__);

    Iterator<T> iterator(*this);

    if (index >= value - 1)
        iterator -= value;

    return iterator;
}

template<typename T>
bool Iterator<T>::operator<(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index < iterator.index;
}

template<typename T>
bool Iterator<T>::operator<=(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index <= iterator.index;
}


template<typename T>
bool Iterator<T>::operator>=(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index >= iterator.index;
}

template<typename T>
bool Iterator<T>::operator>(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index > iterator.index;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index == iterator.index;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return !(*this == iterator);
}

template<typename T>
bool Iterator<T>::isEnd() const {
    return index == rows * cols;
}

template<typename T>
bool Iterator<T>::isValid() const {
    return !data.expired();
}

template<typename T>
Iterator<T> &Iterator<T>::next() {
    return operator++();
}

template<typename T>
void Iterator<T>::check_index(int line) const {
    if (index >= rows * cols || index < 0) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}

template<typename T>
void Iterator<T>::check_validity(int line) const {
    if (!isValid()) {
        time_t currentTime = time(NULL);
        throw MemoryError(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}
