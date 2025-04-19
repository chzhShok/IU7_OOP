#pragma once

template<MatrixElement T>
Iterator<T>::Iterator(const Matrix<T> &matrix)
    : index(0), rows(matrix.rows), cols(matrix.cols), data(matrix.data) {
}

template<MatrixElement T>
Iterator<T>::Iterator(const Iterator<T> &iterator)
    : index(iterator.index), rows(iterator.rows), cols(iterator.cols), data(iterator.data) {
}

template<MatrixElement T>
Iterator<T>::Iterator(const Iterator<T> &iterator, size_t new_index)
    : index(new_index), rows(iterator.rows), cols(iterator.cols), data(iterator.data) {
}

template<MatrixElement T>
Iterator<T>::reference Iterator<T>::operator*() {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols][index % cols];
}

template<MatrixElement T>
const Iterator<T>::reference Iterator<T>::operator*() const {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols][index % cols];
}

template<MatrixElement T>
Iterator<T>::pointer Iterator<T>::operator->() {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols].getAddr() + (index % cols);
}

template<MatrixElement T>
const Iterator<T>::pointer Iterator<T>::operator->() const {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols].getAddr() + (index % cols);
}

template<MatrixElement T>
Iterator<T>::operator bool() const {
    return data.expired();
}

template<MatrixElement T>
Iterator<T>::reference Iterator<T>::value() {
    return operator*();
}

template<MatrixElement T>
const Iterator<T>::reference Iterator<T>::value() const {
    return operator*();
}

template<MatrixElement T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &iterator) {
    check_validity(__LINE__);

    data = iterator.data, index = iterator.index, rows = iterator.rows, cols = iterator.cols;
    return *this;
}

template<MatrixElement T>
Iterator<T> &Iterator<T>::operator+=(int value) {
    check_validity(__LINE__);

    index += value;
    return *this;
}

template<MatrixElement T>
Iterator<T> &Iterator<T>::operator++() {
    check_validity(__LINE__);

    if (index < cols * rows)
        ++index;

    return *this;
}

template<MatrixElement T>
Iterator<T> Iterator<T>::operator++(int) {
    check_validity(__LINE__);

    Iterator<T> iterator(*this);
    ++(*this);
    return iterator;
}

template<MatrixElement T>
Iterator<T> Iterator<T>::operator+(const int value) const {
    check_validity(__LINE__);

    Iterator<T> iterator(*this);

    if (index + value <= rows * cols)
        iterator += value;

    return iterator;
}

template<MatrixElement T>
Iterator<T> &Iterator<T>::operator-=(int value) {
    check_validity(__LINE__);

    index -= value;
    return *this;
}

template<MatrixElement T>
Iterator<T> &Iterator<T>::operator--() {
    check_validity(__LINE__);

    if (index > 0)
        --index;

    return *this;
}

template<MatrixElement T>
Iterator<T> Iterator<T>::operator--(int) {
    check_validity(__LINE__);

    Iterator<T> iterator(*this);
    --(*this);
    return iterator;
}

template<MatrixElement T>
Iterator<T> Iterator<T>::operator-(int value) const {
    check_validity(__LINE__);

    Iterator<T> iterator(*this);

    if (index >= value - 1)
        iterator -= value;

    return iterator;
}

template<MatrixElement T>
bool Iterator<T>::operator<(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index < iterator.index;
}

template<MatrixElement T>
bool Iterator<T>::operator<=(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index <= iterator.index;
}


template<MatrixElement T>
bool Iterator<T>::operator>=(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index >= iterator.index;
}

template<MatrixElement T>
bool Iterator<T>::operator>(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index > iterator.index;
}

template<MatrixElement T>
bool Iterator<T>::operator==(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return index == iterator.index;
}

template<MatrixElement T>
bool Iterator<T>::operator!=(const Iterator<T> &iterator) const {
    check_validity(__LINE__);

    return !(*this == iterator);
}

template<MatrixElement T>
bool Iterator<T>::isEnd() const {
    return index == rows * cols;
}

template<MatrixElement T>
bool Iterator<T>::isValid() const {
    return !data.expired();
}

template<MatrixElement T>
Iterator<T> &Iterator<T>::next() {
    return operator++();
}

template<MatrixElement T>
void Iterator<T>::check_index(int line) const {
    if (index >= rows * cols || index < 0) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}

template<MatrixElement T>
void Iterator<T>::check_validity(int line) const {
    if (!isValid()) {
        time_t currentTime = time(NULL);
        throw MemoryError(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}

template<MatrixElement T>
Iterator<T>::reference Iterator<T>::operator[](int n) {
    check_validity(__LINE__);

    int new_index = index + n;
    if (new_index < 0 || static_cast<size_t>(new_index) >= rows * cols) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    auto shared_data = data.lock();

    size_t row = static_cast<size_t>(new_index) / cols;
    size_t col = static_cast<size_t>(new_index) % cols;
    return shared_data[row][col];
}

template<MatrixElement T>
const Iterator<T>::reference Iterator<T>::operator[](int n) const {
    check_validity(__LINE__);

    int new_index = index + n;
    if (new_index < 0 || static_cast<size_t>(new_index) >= rows * cols) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    auto shared_data = data.lock();

    size_t row = static_cast<size_t>(new_index) / cols;
    size_t col = static_cast<size_t>(new_index) % cols;
    return shared_data[row][col];
}
