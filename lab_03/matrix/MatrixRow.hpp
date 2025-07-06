//#include "Matrix.h"

template<typename T>
Matrix<T>::MatrixRow::MatrixRow() : __size(0), __values(std::vector<T>()) {}

template<typename T>
Matrix<T>::MatrixRow::MatrixRow(size_t size) : __size(size), __values(std::vector<T>(size, 0)) {}

template<typename T>
Matrix<T>::MatrixRow::MatrixRow(size_t size, T value) : __size(size), __values(std::vector<T>(size, value)) {}

template<typename T>
Matrix<T>::MatrixRow::MatrixRow(const MatrixRow &other) : __size(other.__size), __values(std::vector<T>(other.__size, 0)) {
    for (size_t i = 0; i < __size; ++i)
        __values[i] = other.__values[i];
}

template<typename T>
Matrix<T>::MatrixRow::MatrixRow(MatrixRow &&other) : __size(other.__size), __values(std::move(other.__values)) {}

template<typename T>
typename Matrix<T>::MatrixRow &Matrix<T>::MatrixRow::operator=(const MatrixRow &other) {
    __size = other.__size;
    __values = std::vector<T>(other.__size, 0);
    for (size_t i = 0; i < __size; ++i)
        __values[i] = other.__values[i];

    return *this;
}

template<typename T>
typename Matrix<T>::MatrixRow &Matrix<T>::MatrixRow::operator=(MatrixRow &&other) {
    __size = other.__size;
    __values = std::move(other.__values);
    return *this;
}

template<typename T>
T &Matrix<T>::MatrixRow::operator[](std::size_t index) {
    if (__size <= index) {
        time_t now = time(nullptr);
        throw MatrixRowOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return __values[index];
}

template<typename T>
T Matrix<T>::MatrixRow::operator[](std::size_t index) const {
    if (__size <= index) {
        time_t now = time(nullptr);
        throw MatrixRowOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return __values[index];
}

template<typename T>
typename Matrix<T>::MatrixRow::iterator Matrix<T>::MatrixRow::begin() {
    return __values.begin();
}

template<typename T>
typename Matrix<T>::MatrixRow::iterator Matrix<T>::MatrixRow::end() {
    return __values.end();
}

template<typename T>
typename Matrix<T>::MatrixRow::const_iterator Matrix<T>::MatrixRow::begin() const {
    return __values.begin();
}

template<typename T>
typename Matrix<T>::MatrixRow::const_iterator Matrix<T>::MatrixRow::end() const {
    return __values.end();
}

template<typename T>
typename Matrix<T>::MatrixRow::const_iterator Matrix<T>::MatrixRow::cbegin() const {
    return __values.cbegin();
}

template<typename T>
typename Matrix<T>::MatrixRow::const_iterator Matrix<T>::MatrixRow::cend() const {
    return __values.cend();
}

template<typename T>
typename Matrix<T>::MatrixRow::reverse_iterator Matrix<T>::MatrixRow::rbegin() {
    return __values.rbegin();
}

template<typename T>
typename Matrix<T>::MatrixRow::reverse_iterator Matrix<T>::MatrixRow::rend() {
    return __values.rend();
}

template<typename T>
typename Matrix<T>::MatrixRow::const_reverse_iterator Matrix<T>::MatrixRow::rbegin() const {
    return __values.rbegin();
}

template<typename T>
typename Matrix<T>::MatrixRow::const_reverse_iterator Matrix<T>::MatrixRow::rend() const {
    return __values.rend();
}

template<typename T>
typename Matrix<T>::MatrixRow::const_reverse_iterator Matrix<T>::MatrixRow::crbegin() const {
    return __values.crbegin();
}

template<typename T>
typename Matrix<T>::MatrixRow::const_reverse_iterator Matrix<T>::MatrixRow::crend() const {
    return __values.crend();
}

template<typename T>
size_t Matrix<T>::MatrixRow::size() const {
    return __size;
}

template<typename T>
void Matrix<T>::MatrixRow::add(T value) {
    __values.push_back(value);
    __size++;
}

template<typename T>
void Matrix<T>::MatrixRow::resize(std::size_t size, T val) {
    __values.resize(size, val);
    __size = size;
}
