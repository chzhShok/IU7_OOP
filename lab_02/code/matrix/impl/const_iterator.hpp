#pragma once

template<typename T>
ConstIterator<T>::ConstIterator(const Matrix<T> &matrix) {
    index = 0;
    rows = matrix.rows;
    cols = matrix.cols;
    data = matrix.data;
}

template<typename T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &c_iterator) {
    data = c_iterator.data;
    index = c_iterator.index;
    rows = c_iterator.rows;
    cols = c_iterator.cols;
}

template<typename T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &iterator, size_t new_index) {
    index = new_index;
    data = iterator.data;
    rows = iterator.rows;
    cols = iterator.cols;
}

template<typename T>
const T &ConstIterator<T>::operator*() const {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols][index % cols];
}

template<typename T>
const T *ConstIterator<T>::operator->() const {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols].getAddr() + (index % cols);
}

template<typename T>
ConstIterator<T>::operator bool() const {
    return data.expired();
}

template<typename T>
const T &ConstIterator<T>::value() const {
    return operator*();
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator=(const ConstIterator<T> &iterator) {
    check_validity(__LINE__);

    data = iterator.data, index = iterator.index, rows = iterator.rows, cols = iterator.cols;
    return *this;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator+=(int value) {
    check_validity(__LINE__);

    index += value;
    return *this;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator++() {
    check_validity(__LINE__);

    if (index < cols * rows)
        ++index;

    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
    check_validity(__LINE__);

    ConstIterator<T> iterator(*this);
    ++(*this);
    return iterator;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator+(int value) const {
    check_validity(__LINE__);

    ConstIterator<T> iterator(*this);

    if (index + value <= rows * cols)
        iterator += value;

    return iterator;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator-=(int value) {
    check_validity(__LINE__);

    index -= value;
    return *this;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator--() {
    check_validity(__LINE__);

    if (index > 0)
        --index;

    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator--(int) {
    check_validity(__LINE__);

    ConstIterator<T> iterator(*this);
    --(*this);
    return iterator;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator-(int value) const {
    check_validity(__LINE__);

    ConstIterator<T> iterator(*this);

    if (index >= value - 1)
        iterator -= value;

    return iterator;
}

template<typename T>
bool ConstIterator<T>::operator<=(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index <= iterator.index;
}

template<typename T>
bool ConstIterator<T>::operator<(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index < iterator.index;
}

template<typename T>
bool ConstIterator<T>::operator>=(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index >= iterator.index;
}

template<typename T>
bool ConstIterator<T>::operator>(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index > iterator.index;
}

template<typename T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index == iterator.index;
}

template<typename T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return !(*this == iterator);
}

template<typename T>
bool ConstIterator<T>::isEnd() const {
    return index == rows * cols;
}

template<typename T>
bool ConstIterator<T>::isValid() const {
    return !data.expired();
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::next() {
    return operator++();
}

template<typename T>
void ConstIterator<T>::check_index(int line) const {
    if (index >= rows * cols || index < 0) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}

template<typename T>
void ConstIterator<T>::check_validity(int line) const {
    if (!isValid()) {
        time_t currentTime = time(NULL);
        throw MemoryError(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}
