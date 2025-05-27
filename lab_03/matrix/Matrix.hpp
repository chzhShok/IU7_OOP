template<typename T>
Matrix<T>::Matrix() : size(0) {}

template<typename T>
Matrix<T>::Matrix(size_t n, T initial_value) : size(n) {
    matrix.resize(n, std::vector<T>(n, initial_value));
}

template<typename T>
size_t Matrix<T>::getSize() const {
    return size;
}

template<typename T>
void Matrix<T>::resize(size_t new_size, const T &initial_value) {
    if (new_size == size)
        return;

    std::vector<std::vector<T>> new_matrix(new_size, std::vector<T>(new_size, initial_value));

    for (size_t i = 0; i < std::min(size, new_size); ++i)
        for (size_t j = 0; j < std::min(size, new_size); ++j)
            new_matrix[i][j] = matrix[i][j];

    size = new_size;
    matrix = std::move(new_matrix);
}


template<typename T>
T &Matrix<T>::at(size_t row, size_t col) {
    return matrix[row][col];
}

template<typename T>
const T &Matrix<T>::at(size_t row, size_t col) const {
    return matrix[row][col];
}

template<typename T>
std::vector<T> &Matrix<T>::operator[](size_t row) {
    return matrix[row];
}

template<typename T>
const std::vector<T> &Matrix<T>::operator[](size_t row) const {
    return matrix[row];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const {
    Matrix<T> result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = matrix[i][j] + other[i][j];

    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &other) {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            matrix[i][j] += other[i][j];

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
    Matrix<T> result(size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            for (size_t k = 0; k < size; ++k) {
                result[i][j] += matrix[i][k] * other[k][j];
            }
        }
    }
    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &other) {
    *this = *this * other;
    return *this;
}

template<typename T>
std::vector<T> Matrix<T>::multiplyLeft(const std::vector<T> &vec) const {
    std::vector<T> result(size, T());
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i] += matrix[i][j] * vec[j];

    return result;
}

template<typename T>
std::vector<T> Matrix<T>::multiplyRight(const std::vector<T> &vec) const {
    std::vector<T> result(size, T());
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[j] += matrix[i][j] * vec[i];

    return result;
}
