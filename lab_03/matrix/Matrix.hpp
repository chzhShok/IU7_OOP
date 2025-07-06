#include <iostream>

template<typename T>
Matrix<T>::Matrix(std::size_t size) : __size(size) {
    __rows = std::vector<std::shared_ptr<Matrix::MatrixRow>>(__size, nullptr);
    for (std::size_t i = 0; i < __size; ++i)
        __rows[i] = std::make_shared<Matrix::MatrixRow>(size);
}

template<typename T>
Matrix<T>::Matrix() : __size(0), __rows(std::vector<std::shared_ptr<Matrix::MatrixRow>>()) {}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &other) : __size(other.__size) {
    __rows = std::vector<std::shared_ptr<Matrix<T>::MatrixRow>>(__size, nullptr);
    for (std::size_t i = 0; i < __size; ++i)
        __rows[i] = std::make_shared<Matrix<T>::MatrixRow>(*other.__rows[i]);
}

template<typename T>
Matrix<T>::Matrix(Matrix<T> &&other) {
    __size = other.__size;
    __rows = std::move(other.__rows);
    other.__size = 0;
    other.__rows = std::vector<std::shared_ptr<Matrix<T>::MatrixRow>>();
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) {
    __size = other.__size;
    __rows = std::vector<std::shared_ptr<Matrix::MatrixRow>>(__size, nullptr);
    for (std::size_t i = 0; i < __size; ++i)
        __rows[i] = std::make_shared<Matrix::MatrixRow>(*other.__rows[i]);

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&other) {
    __size = other.__size;
    __rows = std::move(other.__rows);
    other.__size = 0;
    other.__rows = std::vector<std::shared_ptr<Matrix<T>::MatrixRow>>();
    return *this;
}

template<typename T>
Matrix<T>::MatrixRow &Matrix<T>::operator[](std::size_t index) {
    if (__size <= index) {
        time_t now = time(nullptr);
        throw MatrixOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return *__rows[index];
}

template<typename T>
typename Matrix<T>::MatrixRow Matrix<T>::operator[](std::size_t index) const {
    if (__size <= index) {
        time_t now = time(nullptr);
        throw MatrixOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return *__rows[index];
}

template<typename T>
std::size_t Matrix<T>::size() const {
    return __size;
}

template<typename T>
std::vector<T> Matrix<T>::getRow(std::size_t index) const {
    if (__size <= index) {
        time_t now = time(nullptr);
        throw MatrixOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::vector<T> arr(__size);
    for (std::size_t i = 0; i < __size; ++i)
        arr[i] = (*this)[index][i];

    return arr;
}

template<typename T>
std::vector<T> Matrix<T>::getColumn(std::size_t index) const {
    if (__size <= index) {
        time_t now = time(nullptr);
        throw MatrixOutOfRangeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::vector<T> arr(__size);
    for (std::size_t i = 0; i < __size; ++i)
        arr[i] = (*this)[index][i];

    return arr;
}

template<typename T>
Matrix<T> &Matrix<T>::expend(std::size_t inc, T value) {
    const std::size_t new_size = __size + inc;
    __rows.reserve(new_size);
    for (std::size_t i = 0; i < inc; i++)
        __rows.push_back(std::make_shared<MatrixRow>(new_size, value));

    for (auto &row: __rows)
        row->resize(new_size, value);

    __size = new_size;
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::resize(std::size_t new_size, T value) {
    if (new_size < __size) {
        __rows.resize(new_size);
        for (auto &row: __rows)
            row->resize(new_size, value);
    } else if (new_size > __size) {
        expend(new_size - __size, value);
    }

    __size = new_size;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::multiply(const Matrix<T> &other) const {
    if (__size != other.__size) {
        time_t now = time(nullptr);
        throw MatrixMultiplySizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    Matrix result(__size);
    for (std::size_t i = 0; i < __size; i++)
        for (std::size_t j = 0; j < __size; j++)
            for (std::size_t k = 0; k < __size; k++)
                result[i][j] += (*this)[i][k] * other[k][j];

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::multiply(T other) const {
    Matrix result(__size);
    for (std::size_t i = 0; i < __size; i++)
        for (std::size_t j = 0; j < __size; j++)
            result[i][j] = (*this)[i][j] * other;

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(T other) const {
    return multiply(other);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
    return multiply(other);
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &other) {
    return *this = std::move(multiply(other));
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(T other) {
    return *this = std::move(Multiply(other));
}

template<typename T>
std::vector<T> Matrix<T>::multiplyLeft(const std::vector<T> &other) const {
    if (__size != other.size()) {
        time_t now = time(nullptr);
        throw MatrixMultiplySizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::vector<T> result(__size);
    for (std::size_t i = 0; i < __size; i++)
        for (std::size_t j = 0; j < __size; j++)
            result[i] += (*this)[j][i] * other[j];

    return result;
}

template<typename T>
std::vector<T> Matrix<T>::multiplyRight(const std::vector<T> &other) const {
    if (__size != other.size()) {
        time_t now = time(nullptr);
        throw MatrixMultiplySizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::vector<T> result(__size);
    for (std::size_t i = 0; i < __size; i++)
        for (std::size_t j = 0; j < __size; j++)
            result[i] += (*this)[i][j] * other[j];

    return result;
}

template<typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T> &other) const {
    return multiplyRight(other);
}

template<typename T>
Matrix<T> Matrix<T>::add(const Matrix<T> &other) const {
    if (__size != other.__size) {
        time_t now = time(nullptr);
        throw MatrixAddSizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    Matrix<T> result(__size);
    for (std::size_t i = 0; i < __size; i++)
        for (std::size_t j = 0; j < __size; j++)
            result[i][j] = (*this)[i][j] + other[i][j];

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::add(T other) const {
    Matrix<T> result(__size);
    for (std::size_t i = 0; i < __size; i++)
        for (std::size_t j = 0; j < __size; j++)
            result[i][j] = (*this)[i][j] + other;

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(T other) const {
    return add(other);
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const {
    return add(other);
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &other) {
    return *this = std::move(Add(other));
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(T other) {
    return *this = std::move(Add(other));
}

template<typename T>
Matrix<T> Matrix<T>::subtract(const Matrix<T> &other) const {
    if (__size != other.__size) {
        time_t now = time(nullptr);
        throw MatrixAddSizeException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    Matrix result(__size);
    for (std::size_t i = 0; i < __size; i++)
        for (std::size_t j = 0; j < __size; j++)
            result[i][j] = (*this)[i][j] - other[i][j];

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::subtract(T other) const {
    Matrix result(__size);
    for (std::size_t i = 0; i < __size; i++)
        for (std::size_t j = 0; j < __size; j++)
            result[i][j] = (*this)[i][j] - other;

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(T other) const {
    return subtract(other);
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const {
    return subtract(other);
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &other) {
    return *this = std::move(Subtract(other));
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(T other) {
    return *this = std::move(Subtract(other));
}

template<typename T>
Matrix<T> &Matrix<T>::transpose() {
    for (std::size_t i = 0; i < __size; i++) {
        for (std::size_t j = 0; j < __size; j++) {
            T tmp = (*this)[i][j];
            (*this)[i][j] = (*this)[j][i];
            (*this)[j][i] = tmp;
        }
    }

    return *this;
}

template<typename T>
typename Matrix<T>::iterator Matrix<T>::begin() {
    return __rows.begin();
}

template<typename T>
typename Matrix<T>::iterator Matrix<T>::end() {
    return __rows.end();
}

template<typename T>
typename Matrix<T>::const_iterator Matrix<T>::begin() const {
    return __rows.cbegin();
}

template<typename T>
typename Matrix<T>::const_iterator Matrix<T>::end() const {
    return __rows.cend();
}

template<typename T>
typename Matrix<T>::const_iterator Matrix<T>::cbegin() const {
    return __rows.cbegin();
}

template<typename T>
typename Matrix<T>::const_iterator Matrix<T>::cend() const {
    return __rows.cend();
}

template<typename T>
typename Matrix<T>::reverse_iterator Matrix<T>::rbegin() {
    return __rows.rbegin();
}

template<typename T>
typename Matrix<T>::reverse_iterator Matrix<T>::rend() {
    return __rows.rend();
}

template<typename T>
typename Matrix<T>::const_reverse_iterator Matrix<T>::rbegin() const {
    return __rows.crbegin();
}

template<typename T>
typename Matrix<T>::const_reverse_iterator Matrix<T>::rend() const {
    return __rows.crend();
}

template<typename T>
typename Matrix<T>::const_reverse_iterator Matrix<T>::crbegin() const {
    return __rows.crbegin();
}

template<typename T>
typename Matrix<T>::const_reverse_iterator Matrix<T>::crend() const {
    return __rows.crend();
}
