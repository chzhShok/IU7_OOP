#pragma once

template<typename T>
Matrix<T>::Matrix(int rows_size, int columns_size) {
    initialize(rows_size, columns_size);
}

template<typename T>
Matrix<T>::Matrix(int rows_size, int columns_size, const T &value) {
    initialize(rows_size, columns_size);

    for (int i = 0; i < rows_size; i++)
        for (int j = 0; j < columns_size; j++)
            data[i][j] = value;
}

template<typename T>
static void checkPtr(T ptr) {
    if (!ptr) {
        time_t currentTime = time(NULL);
        throw InvalidSize(__FILE__, NULL, __LINE__, ctime(&currentTime));
    }
}

template<typename T>
Matrix<T>::Matrix(int rows_size, int columns_size, T **matrix) {
    checkPtr(matrix);
    initialize(rows_size, columns_size);

    for (int i = 0; i < rows_size; i++) {
        checkPtr(matrix[i]);
        for (int j = 0; j < columns_size; j++)
            data[i][j] = matrix[i][j];
    }
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init_list) {
    if (init_list.size() == 0) {
        time_t currentTime = time(NULL);
        throw InvalidArgument(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    int rows_init_list = init_list.size();
    int cols_init_list = init_list.begin()->size();

    for (const auto &row: init_list)
        if (row.size() != cols_init_list) {
            time_t currentTime = time(NULL);
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

template<typename T>
Matrix<T>::Matrix(const Matrix &matrix) {
    initialize(matrix.rows, matrix.rows);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = matrix[i][j];
}

template<typename T>
Matrix<T>::Matrix(Matrix &&matrix) {
    rows = matrix.rows;
    cols = matrix.cols;
    data = matrix.data;
}


template<typename T>
int Matrix<T>::getRows() const noexcept {
    return this->rows;
}

template<typename T>
int Matrix<T>::getCols() const noexcept {
    return this->cols;
}

template<typename T>
bool Matrix<T>::isEmpty() const noexcept {
    return cols && rows;
}

template<typename T>
std::shared_ptr<typename Matrix<T>::MatrixRow[]> Matrix<T>::allocateMemory(int rows_size, int cols_size) {
    std::shared_ptr<typename Matrix<T>::MatrixRow[]> matrix_rows = nullptr;
    try {
        matrix_rows.reset(new MatrixRow[rows_size]);
        for (int i = 0; i < rows_size; i++) {
            T *row_data = new T[cols_size];
            matrix_rows[i].reset(row_data, cols_size);
        }
    } catch (std::bad_alloc &error) {
        time_t currentTime = time(NULL);
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    return matrix_rows;
}

template<typename T>
void Matrix<T>::initialize(int rows_size, int columns_size) {
    if (rows_size < 0 || columns_size < 0) {
        time_t currentTime = time(NULL);
        throw InvalidSize(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    if (rows_size == 0 || columns_size == 0) {
        rows = 0;
        cols = 0;
        data = nullptr;
        return;
    }

    rows = rows_size;
    cols = columns_size;

    data = allocateMemory(rows, cols);
    if (!data) {
        time_t currentTime = time(NULL);
        throw MemoryError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<typename T>
void Matrix<T>::checkSizes(const Matrix<T> &matrix) const {
    if (rows != matrix.rows || cols != matrix.cols) {
        time_t currentTime = time(NULL);
        throw IncompatibleMatrices(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<typename T>
void Matrix<T>::checkMultSizes(const Matrix<T> &matrix) const {
    if (cols != matrix.rows) {
        time_t currentTime = time(NULL);
        throw IncompatibleMatrices(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<typename T>
void Matrix<T>::checkIndex(size_t pos, size_t limit) const {
    if (pos > limit) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<typename T>
void Matrix<T>::moveRow(size_t from, size_t to) {
    auto tmp = data[from];

    for (size_t i = from; i > to; --i)
        data[i] = data[i - 1];

    for (size_t i = from; i < to; ++i)
        data[i] = data[i + 1];

    data[to] = tmp;
}

template<typename T>
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

template<typename T>
void Matrix<T>::resize(int rows_size, int columns_size, const T &value) {
    if ((rows_size == 0 && columns_size != 0) || (rows_size != 0 && columns_size == 0)) {
        rows_size = 0;
        columns_size = 0;
    }

    auto tmp = allocateMemory(rows_size, columns_size);

    for (int i = 0; i < std::min(rows, rows_size); ++i) {
        for (int j = 0; j < std::min(cols, columns_size); ++j)
            tmp[i][j] = data[i][j];

        for (int j = cols; j < columns_size; ++j)
            tmp[i][j] = value;
    }

    for (int i = rows; i < rows_size; ++i)
        for (int j = 0; j < columns_size; ++j)
            tmp[i][j] = value;

    data = tmp;
    rows = rows_size;
    cols = columns_size;
}

template<typename T>
bool Matrix<T>::isSquare() const {
    return rows == cols;
}

template<typename T>
static void _excludeCopy(Matrix<T> &target, const Matrix<T> &source, int ex_row, int ex_col) {
    if (target.getRows() != source.getRows() - 1 || target.getCols() != source.getCols() - 1) {
        time_t currentTime = time(NULL);
        throw IncompatibleElements(__FILE__, NULL, __LINE__, ctime(&currentTime));
    }

    int row_index, col_index;
    for (int i = 0; i < source.getRows() - 1; ++i)
        for (int j = 0; j < source.getCols() - 1; ++j) {
            row_index = i >= ex_row ? i + 1 : i;
            col_index = j >= ex_col ? j + 1 : j;
            target[i][j] = source[row_index][col_index];
        }
}

template<typename T>
static T _determinant(const Matrix<T> &matrix) {
    if (matrix.getRows() == 2)
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    if (matrix.getRows() == 1)
        return matrix[0][0];

    Matrix<T> tmp(matrix.getRows() - 1, matrix.getCols() - 1);
    T res = {};
    for (int i = 0; i < matrix.getRows(); ++i) {
        _excludeCopy(tmp, matrix, 0, i);
        T minor = _determinant(tmp);
        if (i & 1)
            minor = -minor;
        res += minor * matrix[0][i];
    }

    return res;
}

template<typename T>
T Matrix<T>::determinant() const {
    if (!isSquare()) {
        time_t currentTime = time(NULL);
        throw InvalidMatrix(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    return _determinant(*this);
}

template<typename T>
void Matrix<T>::transpose() {
    auto tmp = allocateMemory(cols, rows);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tmp[j][i] = data[i][j];

    data = tmp;
    std::swap(rows, cols);
}

template<typename T>
void Matrix<T>::inverse() {
    T det = determinant();
    if (!isSquare() || !det) {
        time_t currentTime = time(NULL);
        throw InvalidMatrix(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    Matrix<T> res(rows, cols);
    Matrix<T> tmp(rows - 1, cols - 1);
    T value = {};

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            _excludeCopy(tmp, *this, i, j);
            value = tmp.determinant() / det;
            if ((i + j) & 1)
                value = -value;
            res[j][i] = value;
        }

    *this = res;
}

template<typename T>
void Matrix<T>::resizeRows(int new_size, const T &filler) {
    resize(new_size, cols, filler);
}

template<typename T>
void Matrix<T>::resizeCols(int new_size, const T &filler) {
    resize(rows, new_size, filler);
}

template<typename T>
void Matrix<T>::insertRow(size_t pos, const T &filler) {
    checkIndex(pos, rows);

    resizeRows(rows + 1);
    fill(end() - static_cast<int>(cols), end(), filler);
    moveRow(rows - 1, pos);
}

template<typename T>
void Matrix<T>::insertCol(size_t pos, const T &filler) {
    checkIndex(pos, cols);

    resizeCols(cols + 1);
    for (size_t i = 0; i < rows; i++)
        data[i][cols - 1] = filler;
    moveCol(cols - 1, pos);
}

template<typename T>
void Matrix<T>::deleteRow(size_t pos) {
    checkIndex(pos, rows - 1);
    auto tmp = allocateMemory(rows - 1, cols);

    size_t si = 0, di = 0;
    while (si < rows) {
        if (si != pos) {
            for (size_t i = 0; i < cols; ++i)
                tmp[di][i] = data[si][i];
            ++di;
        }
        ++si;
    }

    data = tmp;
    --rows;
}

template<typename T>
void Matrix<T>::deleteCol(size_t pos) {
    checkIndex(pos, cols - 1);
    auto tmp = allocateMemory(rows, cols - 1);

    size_t si = 0, di = 0;
    while (si < cols) {
        if (si != pos) {
            for (size_t i = 0; i < rows; ++i)
                tmp[i][di] = data[i][si];
            ++di;
        }
        ++si;
    }

    data = tmp;
    --cols;
}
