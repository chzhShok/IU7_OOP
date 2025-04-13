#pragma once

template<typename T>
Iterator<T> Matrix<T>::begin() {
    return Iterator<T>(*this, 0);
}

template<typename T>
Iterator<T> Matrix<T>::end() {
    return Iterator<T>(*this, cols * rows);
}

template<typename T>
ConstIterator<T> Matrix<T>::begin() const {
    return ConstIterator<T>(*this, 0);
}

template<typename T>
ConstIterator<T> Matrix<T>::end() const {
    return ConstIterator<T>(*this, cols * rows);
}


template<typename T>
ConstIterator<T> Matrix<T>::cbegin() const {
    return ConstIterator<T>(*this, 0);
}

template<typename T>
ConstIterator<T> Matrix<T>::cend() const {
    return ConstIterator<T>(*this, cols * rows);
}

template<typename T>
void Matrix<T>::fill(Iterator<T> start, const Iterator<T> &end, const T &value) {
    for (auto iter = start; iter < end; ++iter)
        *iter = value;
}

template<typename T>
void Matrix<T>::fill(Iterator<T> start, Iterator<T> source_start, const Iterator<T> &source_end) {
    auto source_iter = source_start;
    auto iter = start;

    while (!iter.isEnd() && source_iter < source_end) {
        *iter = *source_iter;
        ++iter;
        ++source_iter;
    }
}

template<typename T>
void Matrix<T>::fill(Iterator<T> start, ConstIterator<T> source_start, const ConstIterator<T> &source_end) {
    auto source_iter = source_start;
    auto iter = start;

    while (!iter.isEnd() && source_iter < source_end) {
        *iter = *source_iter;
        ++iter;
        ++source_iter;
    }
}

template<typename T>
void Matrix<T>::reverseSeq(Iterator<T> start, Iterator<T> end) {
    end = end - 1;
    for (; start < end; start++, end = end - 1) {
        auto tmp = *start;
        *start = *end;
        *end = tmp;
    }
}
