#pragma once

template<MatrixElement T>
ConstIterator<T>::ConstIterator(const Matrix<T> &matrix)
    : index(0), rows(matrix.rows), cols(matrix.cols), data(matrix.data) {
}

template<MatrixElement T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &iterator)
    : index(iterator.index), rows(iterator.rows), cols(iterator.cols), data(iterator.data) {
}

template<MatrixElement T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &iterator, size_t new_index)
    : index(new_index), rows(iterator.rows), cols(iterator.cols), data(iterator.data) {
}

template<MatrixElement T>
const ConstIterator<T>::reference ConstIterator<T>::operator*() const {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols][index % cols];
}

template<MatrixElement T>
const ConstIterator<T>::pointer ConstIterator<T>::operator->() const {
    check_index(__LINE__);
    check_validity(__LINE__);

    std::shared_ptr<typename Matrix<T>::MatrixRow[]> data_ptr = data.lock();
    return data_ptr[index / cols].getAddr() + (index % cols);
}

template<MatrixElement T>
ConstIterator<T>::operator bool() const {
    return data.expired();
}

template<MatrixElement T>
const ConstIterator<T>::reference ConstIterator<T>::value() const {
    return operator*();
}

template<MatrixElement T>
ConstIterator<T> &ConstIterator<T>::operator=(const ConstIterator<T> &iterator) {
    check_validity(__LINE__);

    data = iterator.data, index = iterator.index, rows = iterator.rows, cols = iterator.cols;
    return *this;
}

template<MatrixElement T>
ConstIterator<T> &ConstIterator<T>::operator+=(int value) {
    check_validity(__LINE__);

    index += value;
    return *this;
}

template<MatrixElement T>
ConstIterator<T> &ConstIterator<T>::operator++() {
    check_validity(__LINE__);

    if (index < cols * rows)
        ++index;

    return *this;
}

template<MatrixElement T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
    check_validity(__LINE__);

    ConstIterator<T> iterator(*this);
    ++(*this);
    return iterator;
}

template<MatrixElement T>
ConstIterator<T> ConstIterator<T>::operator+(int value) const {
    check_validity(__LINE__);

    ConstIterator<T> iterator(*this);

    if (index + value <= rows * cols)
        iterator += value;

    return iterator;
}

template<MatrixElement T>
ConstIterator<T> &ConstIterator<T>::operator-=(int value) {
    check_validity(__LINE__);

    index -= value;
    return *this;
}

template<MatrixElement T>
ConstIterator<T> &ConstIterator<T>::operator--() {
    check_validity(__LINE__);

    if (index > 0)
        --index;

    return *this;
}

template<MatrixElement T>
ConstIterator<T> ConstIterator<T>::operator--(int) {
    check_validity(__LINE__);

    ConstIterator<T> iterator(*this);
    --(*this);
    return iterator;
}

template<MatrixElement T>
ConstIterator<T> ConstIterator<T>::operator-(int value) const {
    check_validity(__LINE__);

    ConstIterator<T> iterator(*this);

    if (index >= value - 1)
        iterator -= value;

    return iterator;
}

template<MatrixElement T>
bool ConstIterator<T>::operator<=(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index <= iterator.index;
}

template<MatrixElement T>
bool ConstIterator<T>::operator<(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index < iterator.index;
}

template<MatrixElement T>
bool ConstIterator<T>::operator>=(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index >= iterator.index;
}

template<MatrixElement T>
bool ConstIterator<T>::operator>(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index > iterator.index;
}

template<MatrixElement T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return index == iterator.index;
}

template<MatrixElement T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &iterator) const {
    check_validity(__LINE__);

    return !(*this == iterator);
}

template<MatrixElement T>
bool ConstIterator<T>::isEnd() const {
    return index == rows * cols;
}

template<MatrixElement T>
bool ConstIterator<T>::isValid() const {
    return !data.expired();
}

template<MatrixElement T>
ConstIterator<T> &ConstIterator<T>::next() {
    return operator++();
}

template<MatrixElement T>
void ConstIterator<T>::check_index(int line) const {
    if (index >= rows * cols || index < 0) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}

template<MatrixElement T>
void ConstIterator<T>::check_validity(int line) const {
    if (!isValid()) {
        time_t currentTime = time(NULL);
        throw MemoryError(__FILE__, typeid(*this).name(), line, ctime(&currentTime));
    }
}

template<MatrixElement T>
typename ConstIterator<T>::reference ConstIterator<T>::operator[](int n) const {
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
