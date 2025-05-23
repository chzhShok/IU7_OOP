#pragma once

#include <initializer_list>
#include <iostream>

#include "ConstIterator.hpp"
#include "MatrixConcept.hpp"
#include "MatrixIterator.hpp"

template<MatrixElement T>
class Matrix {
public:
    class MatrixRow;
    friend class Iterator<T>;
    friend class ConstIterator<T>;

    // конструкторы
    explicit Matrix();
    explicit Matrix(int rows_size, int columns_size);
    Matrix(int rows_size, int columns_size, const T &value);
    Matrix(int rows_size, int columns_size, T **matrix);
    Matrix(std::initializer_list<std::initializer_list<T>> init_list);
    explicit Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix) noexcept;

    virtual ~Matrix() = default;

    // методы доступа
    int getRows() const noexcept;
    int getCols() const noexcept;
    bool isEmpty() const noexcept;
    Matrix identity();

    MatrixRow &operator[](int rows_size);
    const MatrixRow &operator[](int rows_size) const;
    T &at(int rows_size, int columns_size);
    const T &at(int rows_size, int columns_size) const;
    T &operator()(int rows_size, int columns_size);
    const T &operator()(int rows_size, int columns_size) const;

    // присваивание
    Matrix &operator=(const Matrix &matrix);
    Matrix &operator=(Matrix &&matrix) noexcept;
    Matrix &operator=(std::initializer_list<std::initializer_list<T>> init_list);

    // математика с матрицами
    template<typename U>
    decltype(auto) operator+(const Matrix<U> &matrix) const;

    template<typename U>
    decltype(auto) operator-(const Matrix<U> &matrix) const;

    template<typename U>
    decltype(auto) operator*(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix<T> mulByElement(const Matrix<U> &matrix) const;

    template<typename U>
    decltype(auto) operator/(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix<T> divByElement(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix &operator+=(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &operator-=(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &operator*=(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &operator/=(const Matrix<U> &matrix);

    Matrix operator-();

    // математика с элементами
    template<typename U>
    decltype(auto) operator+(const U &elem) const noexcept;

    template<typename U>
    decltype(auto) operator-(const U &elem) const noexcept;

    template<typename U>
    decltype(auto) operator*(const U &elem) const noexcept;

    template<typename U>
    decltype(auto) operator/(const U &elem) const;

    template<ElementArithmetic<T> U>
    Matrix &operator+=(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &operator-=(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &operator*=(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &operator/=(const U &elem);

    // размеры
    void resize(int new_rows, int new_cols);
    void resize(int rows_size, int columns_size, const T &value);

    void resizeRows(int new_size);
    void resizeRows(int new_size, const T &filler);

    void resizeCols(int new_size);
    void resizeCols(int new_size, const T &filler);

    void insertRow(size_t pos, const T &filler = {});
    void insertCol(size_t pos, const T &filler = {});
    void deleteRow(size_t pos);
    void deleteCol(size_t pos);
    void swapRows(size_t row1, size_t row2);
    void swapCols(size_t col1, size_t col2);

    // доп методы
    template<ElementArithmetic U = T>
    void inverse();

    template<ElementArithmetic U = T>
    U determinant() const;
    bool isSquare() const;
    void transpose();

    // итераторы
    Iterator<T> begin();
    Iterator<T> end();
    ConstIterator<T> cbegin() const;
    ConstIterator<T> cend() const;

    void fill(Iterator<T> start, const Iterator<T> &end, const T &value);
    void fill(Iterator<T> start, Iterator<T> source_start, const Iterator<T> &source_end);
    void fill(Iterator<T> start, ConstIterator<T> source_start, const ConstIterator<T> &source_end);
    void reverseSeq(Iterator<T> start, Iterator<T> end);

    // сравнение
    bool operator==(const Matrix &matrix) const;
    bool operator!=(const Matrix &matrix) const;

protected:
    template<typename U>
    decltype(auto) addMatrix(const Matrix<U> &matrix) const;

    template<typename U>
    decltype(auto) subMatrix(const Matrix<U> &matrix) const;

    template<typename U>
    decltype(auto) mulMatrix(const Matrix<U> &matrix) const;

    template<typename U>
    decltype(auto) divMatrix(const Matrix<U> &matrix) const;

    template<MatrixArithmetic<T> U>
    Matrix &addEqMatrix(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &subEqMatrix(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &mulEqMatrix(const Matrix<U> &matrix);

    template<MatrixArithmetic<T> U>
    Matrix &divEqMatrix(const Matrix<U> &matrix);

    template<typename U>
    decltype(auto) addElem(const U &elem) const noexcept;

    template<typename U>
    decltype(auto) subElem(const U &elem) const noexcept;

    template<typename U>
    decltype(auto) mulElem(const U &elem) const noexcept;

    template<typename U>
    decltype(auto) divElem(const U &elem) const;

    template<ElementArithmetic<T> U>
    Matrix &addEqElem(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &subEqElem(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &mulEqElem(const U &elem) noexcept;

    template<ElementArithmetic<T> U>
    Matrix &divEqElem(const U &elem);

    Matrix neg();

private:
    std::shared_ptr<MatrixRow[]> allocateMemory(int rows_size, int columns_size);
    void initialize(int rows_size, int columns_size);

    void checkIndex(size_t pos, size_t limit) const;

    void moveRow(size_t from, size_t to);
    void moveCol(size_t from, size_t to);

    template<MatrixElement U>
    void checkSizes(const Matrix<U> &matrix) const;

    template<MatrixElement U>
    void checkMultSizes(const Matrix<U> &matrix) const;

    std::shared_ptr<MatrixRow[]> data{nullptr};
    int rows = 0;
    int cols = 0;

public:
    class MatrixRow {
    public:
        friend class Iterator<T>;
        friend class ConstIterator<T>;

        using value_type = T;
        using size_type = std::size_t;
        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;
        using reverse_iterator = typename std::vector<T>::reverse_iterator;
        using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;

        MatrixRow(T *data, const size_t size) : data(data), size(size) {}
        MatrixRow() : data(nullptr), size(0) {}
        ~MatrixRow() = default;

        T &operator[](size_t index);
        const T &operator[](size_t index) const;

        void reset(T *ptr, const size_t new_size);
        void reset();
        T *getAddr();
        const T *getAddr() const;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;
        //        std::size_t size() const;

    private:
        std::shared_ptr<T[]> data = nullptr;
        size_t size = 0;
    };
};

#include "Matrix.hpp"
