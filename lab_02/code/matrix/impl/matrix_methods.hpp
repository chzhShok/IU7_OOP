#pragma once

template<MatrixElement T>
Matrix<T>::Matrix(int rows_size, int columns_size) {
    initialize(rows_size, columns_size);
}

template<MatrixElement T>
Matrix<T>::Matrix(int rows_size, int columns_size, const T &value) {
    initialize(rows_size, columns_size);

    for (int i = 0; i < rows_size; i++)
        for (int j = 0; j < columns_size; j++)
            data[i][j] = value;
}

template<MatrixElement T>
static void checkPtr(T ptr) {
    if (!ptr) {
        time_t currentTime = time(nullptr);
        throw InvalidSize(__FILE__, "", __LINE__, ctime(&currentTime));
    }
}

template<MatrixElement T>
Matrix<T>::Matrix(int rows_size, int columns_size, T **matrix) {
    checkPtr(matrix);
    initialize(rows_size, columns_size);

    for (int i = 0; i < rows_size; i++) {
        checkPtr(matrix[i]);
        for (int j = 0; j < columns_size; j++)
            data[i][j] = matrix[i][j];
    }
}

template<MatrixElement T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init_list) {
    if (init_list.size() == 0) {
        time_t currentTime = time(nullptr);
        throw InvalidArgument(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    int rows_init_list = init_list.size();
    int cols_init_list = init_list.begin()->size();

    for (const auto &row: init_list)
        if (row.size() != cols_init_list) {
            time_t currentTime = time(nullptr);
            throw InvalidArgument(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
        }

    initialize(rows_init_list, cols_init_list);

    int i = 0;
    for (const auto &row: init_list)
        for (const auto &elem: row) {
            data[i / cols][i % cols] = elem;
            ++i;
        }
}

template<MatrixElement T>
Matrix<T>::Matrix(const Matrix &matrix) {
    initialize(matrix.rows, matrix.cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = matrix[i][j];
}

template<MatrixElement T>
Matrix<T>::Matrix(Matrix &&matrix) noexcept : rows(matrix.rows), cols(matrix.cols), data(matrix.data) {
    matrix.rows = 0;
    matrix.cols = 0;
    matrix.data = nullptr;
}

template<MatrixElement T>
int Matrix<T>::getRows() const noexcept {
    return this->rows;
}

template<MatrixElement T>
int Matrix<T>::getCols() const noexcept {
    return this->cols;
}

template<MatrixElement T>
bool Matrix<T>::isEmpty() const noexcept {
    return cols && rows;
}

template<MatrixElement T>
std::shared_ptr<typename Matrix<T>::MatrixRow[]> Matrix<T>::allocateMemory(int rows_size, int cols_size) {
    std::shared_ptr<typename Matrix<T>::MatrixRow[]> matrix_rows = nullptr;
    try {
        matrix_rows.reset(new MatrixRow[rows_size]);
        for (int i = 0; i < rows_size; i++) {
            T *row_data = new T[cols_size]();
            matrix_rows[i].reset(row_data, cols_size);
        }
    } catch (std::bad_alloc &error) {
        time_t currentTime = time(nullptr);
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    return matrix_rows;
}

template<MatrixElement T>
void Matrix<T>::initialize(int rows_size, int columns_size) {
    if (rows_size <= 0 || columns_size <= 0) {
        time_t currentTime = time(nullptr);
        throw InvalidSize(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    rows = rows_size;
    cols = columns_size;

    data = allocateMemory(rows, cols);
    if (!data) {
        time_t currentTime = time(nullptr);
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<MatrixElement T>
template<MatrixElement U>
void Matrix<T>::checkSizes(const Matrix<U> &matrix) const {
    if (rows != matrix.getRows() || cols != matrix.getCols()) {
        time_t currentTime = time(nullptr);
        throw IncompatibleMatrices(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<MatrixElement T>
template<MatrixElement U>
void Matrix<T>::checkMultSizes(const Matrix<U> &matrix) const {
    if (cols != matrix.getRows()) {
        time_t currentTime = time(nullptr);
        throw IncompatibleMatrices(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<MatrixElement T>
void Matrix<T>::checkIndex(size_t pos, size_t limit) const {
    if (pos > limit) {
        time_t currentTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<MatrixElement T>
void Matrix<T>::moveRow(size_t from, size_t to) {
    auto tmp = data[from];

    for (size_t i = from; i > to; --i)
        data[i] = data[i - 1];

    for (size_t i = from; i < to; ++i)
        data[i] = data[i + 1];

    data[to] = tmp;
}

template<MatrixElement T>
void Matrix<T>::moveCol(size_t from, size_t to) {
    for (size_t j = 0; j < rows; ++j) {
        auto tmp = data[j][from];

        for (size_t i = from; i > to; --i)
            data[j][i] = data[j][i - 1];

        for (size_t i = from; i < to; ++i)
            data[j][i] = data[j][i + 1];

        data[j][to] = tmp;
    }
}

template<MatrixElement T>
bool Matrix<T>::isSquare() const {
    return rows == cols;
}

template<MatrixElement T>
template<ElementArithmetic U>
U Matrix<T>::determinant() const {
    if (!isSquare()) {
        time_t currentTime = time(nullptr);
        throw InvalidMatrix(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    Matrix<U> tmp(*this);
    U det = 1;
    const int n = rows;

    for (int k = 0; k < n; ++k) {
        int max_row = k;
        for (int i = k + 1; i < n; ++i)
            if (std::abs(tmp[i][k]) > std::abs(tmp[max_row][k]))
                max_row = i;

        if (max_row != k) {
            tmp.swapRows(k, max_row);
            det = -det;
        }

        if (tmp[k][k] == 0)
            return 0;

        det *= tmp[k][k];

        for (int i = k + 1; i < n; ++i) {
            U factor = tmp[i][k] / tmp[k][k];
            for (int j = k + 1; j < n; ++j)
                tmp[i][j] -= factor * tmp[k][j];
        }
    }

    return det;
}

template<MatrixElement T>
void Matrix<T>::transpose() {
    auto tmp = allocateMemory(cols, rows);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[j][i] = data[i][j];

    data = tmp;
    std::swap(rows, cols);
}

template<MatrixElement T>
template<ElementArithmetic U>
void Matrix<T>::inverse() {
    if (!isSquare()) {
        time_t currentTime = time(nullptr);
        throw InvalidMatrix(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    const size_t n = rows;
    U det = determinant();

    if (std::abs(det) < std::numeric_limits<U>::epsilon()) {
        time_t currentTime = time(nullptr);
        throw InvalidMatrix(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    Matrix<T> augmented(n, 2 * n);

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            augmented[i][j] = (*this)[i][j];

    for (size_t i = 0; i < n; ++i)
        augmented[i][n + i] = 1;

    for (size_t k = 0; k < n; ++k) {
        size_t max_row = k;
        for (size_t i = k + 1; i < n; ++i)
            if (std::abs(augmented[i][k]) > std::abs(augmented[max_row][k]))
                max_row = i;

        if (max_row != k)
            augmented.swapRows(k, max_row);

        T pivot = augmented[k][k];
        for (size_t j = k; j < 2 * n; ++j)
            augmented[k][j] /= pivot;

        for (size_t i = k + 1; i < n; ++i) {
            T factor = augmented[i][k];
            for (size_t j = k; j < 2 * n; ++j)
                augmented[i][j] -= factor * augmented[k][j];
        }
    }

    for (int k = n - 1; k >= 0; --k) {
        for (int i = k - 1; i >= 0; --i) {
            T factor = augmented[i][k];
            for (size_t j = k; j < 2 * n; ++j)
                augmented[i][j] -= factor * augmented[k][j];
        }
    }

    Matrix<T> inverse(n, n);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            inverse[i][j] = augmented[i][n + j];

    *this = inverse;
}

template<MatrixElement T>
void Matrix<T>::resize(int new_rows, int new_cols) {
    static_assert(std::is_default_constructible_v<T>, "Type T must be default constructible for resize() without fill value");
    resize(new_rows, new_cols, T{});
}

template<MatrixElement T>
void Matrix<T>::resize(int rows_size, int columns_size, const T &value) {
    if ((rows_size < 0 || columns_size < 0)) {
        time_t currentTime = time(nullptr);
        throw InvalidSize(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    if (rows_size == 0 || columns_size == 0) {
        data.reset();
        rows = 0;
        cols = 0;
        return;
    }

    if (rows_size == rows && columns_size == cols) {
        return;
    }

    auto new_data = allocateMemory(rows_size, columns_size);

    const int rows_to_copy = std::min(rows, rows_size);
    const int cols_to_copy = std::min(cols, columns_size);

    for (int i = 0; i < rows_to_copy; ++i) {
        for (int j = 0; j < cols_to_copy; ++j) {
            if constexpr (std::is_move_constructible_v<T>)
                new_data[i][j] = std::move(data[i][j]);
            else
                new_data[i][j] = data[i][j];
        }
    }

    if (rows_size > rows || columns_size > cols)
        for (int i = 0; i < rows_size; ++i)
            for (int j = 0; j < columns_size; ++j)
                if (i >= rows || j >= cols)
                    new_data[i][j] = value;

    data = std::move(new_data);
    rows = rows_size;
    cols = columns_size;
}

template<MatrixElement T>
void Matrix<T>::resizeRows(int new_size) {
    static_assert(std::is_default_constructible_v<T>, "Type T must be default constructible for resize() without fill value");
    resize(new_size, cols, T{});
}

template<MatrixElement T>
void Matrix<T>::resizeRows(int new_size, const T &filler) {
    resize(new_size, cols, filler);
}

template<MatrixElement T>
void Matrix<T>::resizeCols(int new_size) {
    static_assert(std::is_default_constructible_v<T>, "Type T must be default constructible for resize() without fill value");
    resize(rows, new_size, T{});
}

template<MatrixElement T>
void Matrix<T>::resizeCols(int new_size, const T &filler) {
    resize(rows, new_size, filler);
}

template<MatrixElement T>
void Matrix<T>::insertRow(size_t pos, const T &filler) {
    checkIndex(pos, rows);

    resizeRows(rows + 1);
    fill(end() - static_cast<int>(cols), end(), filler);
    moveRow(rows - 1, pos);
}

template<MatrixElement T>
void Matrix<T>::insertCol(size_t pos, const T &filler) {
    checkIndex(pos, cols);

    resizeCols(cols + 1);
    for (size_t i = 0; i < rows; i++)
        data[i][cols - 1] = filler;

    moveCol(cols - 1, pos);
}

template<MatrixElement T>
void Matrix<T>::deleteRow(size_t pos) {
    checkIndex(pos, static_cast<size_t>(rows));
    for (size_t i = pos; i + 1 < static_cast<size_t>(rows); ++i)
        swapRows(i, i + 1);

    resize(rows - 1, cols);
}

template<MatrixElement T>
void Matrix<T>::deleteCol(size_t pos) {
    checkIndex(pos, static_cast<size_t>(cols));
    for (size_t i = pos; i + 1 < static_cast<size_t>(cols); ++i)
        swapCols(i, i + 1);

    resize(rows, cols - 1);
}


template<MatrixElement T>
void Matrix<T>::swapRows(size_t row1, size_t row2) {
    if (row1 >= rows || row2 >= rows) {
        time_t currentTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    if (row1 == row2)
        return;

    std::swap(data[row1], data[row2]);
}

template<MatrixElement T>
void Matrix<T>::swapCols(size_t col1, size_t col2) {
    if (col1 >= cols || col2 >= cols) {
        time_t currentTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    if (col1 == col2)
        return;

    for (size_t i = 0; i < rows; ++i)
        std::swap(data[i][col1], data[i][col2]);
}
