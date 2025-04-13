#include <iostream>

#include "matrix.h"

#define CONSTRUCTOR
#define INSERT_DELETE_RESIZE
#define GET
#define ITERATORS
#define CONST_ITERATORS
#define MATH_OPERATIONS
#define ERRORS

int main() {
#ifdef CONSTRUCTOR
    // CONSTRUCTOR -----------------------------------------------
//    std::cout << "CONSTRUCTOR TESTING SECTION:"
//              << "\n\n";
//    try {
//        std::cout << "Attempt to create matrix with negative size"
//                  << " (conversion to very big size_t number)" << std::endl;
//        Matrix<int> err_m(-1, 2);
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    size_t q = 2, z = 3;
//    std::cout << "Constructor with two size_t numbers:\n";
//    Matrix<int> a(q, z);
//    std::cout << a << "\n\n";
//
//    std::cout << "Check of constructor with c-matrix:\n";
//    int **c_matrix = new int *[2];
//    for (int i = 0; i < 2; ++i) {
//        c_matrix[i] = new int[2];
//        for (int j = 0; j < 2; ++j)
//            c_matrix[i][j] = i + j;
//    }
//
//    Matrix<int> matr{2, 2, c_matrix};
//    std::cout << matr << "\n\n";
//    for (int i = 0; i < 2; ++i)
//        delete[] c_matrix[i];
//    delete[] c_matrix;
//
//    std::cout << "Constructor with one zero size:\n";
//    try {
//        Matrix<int> ab(0, 3);
//        std::cout << "Sizes of matrix: " << ab.getRows() << " and " << ab.getCols() << "\n\n";
//    } catch (ExceptionMatrix &err) {
//        std::cerr << err.what() << "\n\n";
//    }
//
//    std::cout << "Constructor with filler [Matrix<double> b(3, 2, 12)]:\n";
//    Matrix<double> b(3, 2, 12);
//    std::cout << b << "\n\n";
//
//    std::cout << "Constructor with initialization list [Matrix<double> c({ { 2., 3. }, { 3., 4. } })]:\n";
//    Matrix<double> c({{2., 3.}, {3., 4.}});
//    std::cout << c << "\n\n";
//
//    std::cout << "CONSTRUCTOR SECTION END\n\n\n";
    // CONSTRUCTOR -----------------------------------------------
#endif

    std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n";

#ifdef INSERT_DELETE_RESIZE
    // INSERT-DELETE-RESIZE --------------------------------------
//    std::cout << "INSERT-DELETE-RESIZE OPERATIONS TESTING SECTION:\n\n";
//    std::cout << "Working with matrix c_insert:\n";
//    Matrix<double> c_insert({{2., 3.}, {3., 4.}});
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.insertRow(1, 3.33);\n";
//    c_insert.insertRow(1, 3.33);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.insertCol(1, 4.321);\n";
//    c_insert.insertCol(1, 4.321);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.deleteCol(1);\n";
//    c_insert.deleteCol(1);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.deleteRow(0);\n";
//    c_insert.deleteRow(0);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.resizeRows(c_insert.getRows() + 1);\n";
//    c_insert.resizeRows(c_insert.getRows() + 1);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.resizeCols(c_insert.getCols() + 1);\n";
//    c_insert.resizeCols(c_insert.getCols() + 1);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.resizeRows(c_insert.getRows() + 1, 34);\n";
//    c_insert.resizeRows(c_insert.getRows() + 1, 34);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.resizeCols(c_insert.getCols() + 1, 43);\n";
//    c_insert.resizeCols(c_insert.getCols() + 1, 43);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.resize(c_insert.getRows() + 2, c_insert.getCols() + 1);\n";
//    c_insert.resize(c_insert.getRows() + 2, c_insert.getCols() + 1);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Command: c_insert.resize(c_insert.getRows() - 2, c_insert.getCols() - 1);\n";
//    c_insert.resize(c_insert.getRows() - 2, c_insert.getCols() - 1);
//    std::cout << c_insert << "\n\n";
//
//    std::cout << "Check of transpose method on matrix c_insert (but first - resize (+ 2 rows)):\n";
//    std::cout << "Command: c_insert.resizeRows(c_insert.getRows() + 2, 32.10);\n";
//    c_insert.resizeRows(c_insert.getRows() + 2, 32.10);
//    std::cout << "Result: \n"
//              << c_insert << "\n\n";
//    std::cout << "Command: c_insert.transpose();\n";
//    c_insert.transpose();
//    std::cout << "Result: \n"
//              << c_insert << "\n\n";
//
//    std::cout << "INSERT-DELETE-RESIZE OPERATIONS SECTION END\n\n\n";

    // INSERT-DELETE-RESIZE --------------------------------------
#endif

    std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n";

#ifdef GET
    // GET ELEMENT -----------------------------------------------
//    std::cout << "GET ELEMENT METHODS SECTION:\n\n";
//    Matrix<std::string> new_m = {{"a1", "a2", "a3"}, {"b1", "b2", "b3"}, {"c1", "c2", "c3"}};
//    std::cout << "Working with matrix new_m: \n"
//              << new_m << "\n\n";
//
//    std::cout << "Commands: new_m[1][1] and new_m.at(1, 1)\n";
//    std::cout << new_m[1][1] << " / " << new_m.at(1, 1) << "\n\n";
//
//    std::cout << "Commands: new_m[1][1] = new1 and new_m.at(1, 2) = new2\n";
//    new_m[1][1] = "new1";
//    new_m.at(1, 2) = "new2";
//    std::cout << "new_m[1][1] = " << new_m[1][1] << ", new_m[1][2] = " << new_m[1][2] << "\n\n";
//    std::cout << "GET ELEMENT METHODS SECTION END\n\n\n";
    // GET ELEMENT -----------------------------------------------
#endif

    std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n";

#ifdef ITERATORS
    // ITERATORS -------------------------------------------------
//    std::cout << "ITERATORS SECTION\n\n";
//    std::cout << "Matrix m_iter:\n";
//    Matrix<std::string> m_iter{
//            {"a1", "a2", "a3"},
//            {"b1", "new1", "new2"},
//            {"c1", "c2", "c3"}};
//    std::cout << m_iter << "\n\n";
//
//    std::cout << "Command: range-based for cycle (const elem &), ' ' as delimiter\n";
//    for (const auto &elem: m_iter)
//        std::cout << elem << ' ';
//    std::cout << "\n\n";
//
//    size_t cnt = 0;
//    std::cout << "Range-based for filling matrix with string \"new_test<number>\":\n";
//    for (auto &elem: m_iter)
//        elem = "new_test" + std::to_string(++cnt);
//    std::cout << m_iter << "\n\n";
//
//    std::cout << "Test fill [from, to, filler]:\n";
//    m_iter.fill(m_iter.end() - static_cast<int>(m_iter.getCols()), m_iter.end(), "filler_for_last_line");
//    std::cout << m_iter << "\n\n";
//
//    std::cout << "Test fill from another matrix container via iterators:\n";
//    Matrix<std::string> test_m = {{"test1", "test2", "test3"}, {"test4", "test5", "test6"}};
//    m_iter.fill(m_iter.end() - static_cast<int>(m_iter.getCols()), test_m.begin(), test_m.end());
//    std::cout << m_iter << "\n\n";
//
//    std::cout << "Reverse method check (reverseSeq first line): \n";
//    m_iter.reverseSeq(m_iter.begin(), m_iter.begin() + static_cast<int>(m_iter.getCols()));
//    std::cout << m_iter << "\n\n";
//
//    std::cout << "ITERATORS SECTION ENDS\n\n";
    // ITERATORS -------------------------------------------------
#endif

    std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n";

#ifdef CONST_ITERATORS
    // CONST ITERATORS AND OBJECTS -------------------------------
//    std::cout << "CONST ITERATORS AND OBJECTS SECTION\n\n";
//
//    std::cout << "Create const matrix = { { '11', '12', '13' }, { '21', '22', '23' } }\n";
//    const Matrix<std::string> const_m = {{"11", "12", "13"}, {"21", "22", "23"}};
//
//    std::cout << "Range-based for cycle for const matrix:\n";
//    for (const auto &elem: const_m)
//        std::cout << elem << "; ";
//    std::cout << "\n\n";
//
//    std::cout << "Insert in c_m_tmp matrix from const matrix:\n";
//    Matrix<std::string> c_m_tmp{
//            {"1", "2", "3"},
//            {"4", "5", "6"},
//            {"7", "8", "9"}};
//    std::cout << "c_m_tmp matrix:\n"
//              << c_m_tmp << "\n\n";
//    std::cout << "Insert command: c_m_tmp.fill(c_m_tmp.begin(), const_m.begin(), const_m.begin() + 3);\n";
//    c_m_tmp.fill(c_m_tmp.begin(), const_m.begin(), const_m.begin() + 3);
//    std::cout << "c_m_tmp matrix after insertion: \n"
//              << c_m_tmp << "\n\n";
//
//    std::cout << "Check of cbegin and cend methods of non-constant object (c_m_tmp matrix):\n";
//    for (auto it = c_m_tmp.cbegin(); it < c_m_tmp.cend(); it++)
//        std::cout << *it << "; ";
//    std::cout << "\n\n";
//    std::cout << "CONST ITERATORS AND OBJECTS SECTION ENDS\n\n";
    // CONST ITERATORS AND OBJECTS -------------------------------
#endif

    std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n";

#ifdef MATH_OPERATIONS
    // MATH OPERATIONS -------------------------------------------
//    std::cout << "MATH OPERATIONS SECTION\n\n";
//
//    Matrix<double> math_matrix = {{1, 2, 3, 4}, {7, 9, 11, 13}, {4, 2, 0, -2}, {1, 4, 7, 10}};
//    std::cout << "Matrix to work with here (math_matrix): \n";
//    std::cout << math_matrix << "\n\n";
//
//    std::cout << "Operation: math_matrix += 2.5;\n";
//    math_matrix += 2.5;
//    std::cout << "matrix after operation:\n";
//    std::cout << math_matrix << "\n\n";
//
//    std::cout << "Operation: math_matrix -= 2.5;\n";
//    math_matrix -= 2.5;
//    std::cout << "matrix after operation:\n";
//    std::cout << math_matrix << "\n\n";
//
//    std::cout << "Operation: math_matrix *= 2.5;\n";
//    math_matrix *= 2.5;
//    std::cout << "matrix after operation:\n";
//    std::cout << math_matrix << "\n\n";
//
//    std::cout << "Operation: math_matrix /= 2.5;\n";
//    math_matrix /= 2.5;
//    std::cout << "matrix after operation:\n";
//    std::cout << math_matrix << "\n\n";
//
//    std::cout << "Same operations, but using METHODS\n";
//    std::cout << "Operation: math_matrix.addEqElem(2.5);\n";
//    math_matrix.addEqElem(2.5);
//    std::cout << "matrix after operation:\n";
//    std::cout << math_matrix << "\n\n";
//
//    std::cout << "Operation: math_matrix.subEqElem(2.5);\n";
//    math_matrix.subEqElem(2.5);
//    std::cout << "matrix after operation:\n";
//    std::cout << math_matrix << "\n\n";
//
//    std::cout << "Operation: math_matrix.mulEqElem(2.5);\n";
//    math_matrix.mulEqElem(2.5);
//    std::cout << "matrix after operation:\n";
//    std::cout << math_matrix << "\n\n";
//
//    std::cout << "Operation: math_matrix.divEqElem(2.5);\n";
//    math_matrix.divEqElem(2.5);
//    std::cout << "matrix after operation:\n";
//    std::cout << math_matrix << "\n\n";
//
//    Matrix<double> tmp;
//
//    std::cout << "Operation: tmp = math_matrix + 2.5;\n";
//    tmp = math_matrix + 2.5;
//    std::cout << "matrix after operation:\n";
//    std::cout << tmp << "\n\n";
//
//    std::cout << "Operation: tmp = math_matrix - 2.5;\n";
//    tmp = math_matrix - 2.5;
//    std::cout << "matrix after operation:\n";
//    std::cout << tmp << "\n\n";
//
//    std::cout << "Operation: tmp = math_matrix * 2.5;\n";
//    tmp = math_matrix * 2.5;
//    std::cout << "matrix after operation:\n";
//    std::cout << tmp << "\n\n";
//
//    std::cout << "Operation: tmp = math_matrix / 2.5;\n";
//    tmp = math_matrix / 2.5;
//    std::cout << "matrix after operation:\n";
//    std::cout << tmp << "\n\n";
//
//    std::cout << "Same operations, but using METHODS..\n";
//    std::cout << "Operation: tmp = math_matrix.addElem(2.5);\n";
//    tmp = math_matrix.addElem(2.5);
//    std::cout << "matrix after operation:\n";
//    std::cout << tmp << "\n\n";
//
//    std::cout << "Operation: tmp = math_matrix.subElem(2.5);\n";
//    tmp = math_matrix.subElem(2.5);
//    std::cout << "matrix after operation:\n";
//    std::cout << tmp << "\n\n";
//
//    std::cout << "Operation: tmp = math_matrix.mulElem(2.5);\n";
//    tmp = math_matrix.mulElem(2.5);
//    std::cout << "matrix after operation:\n";
//    std::cout << tmp << "\n\n";
//
//    std::cout << "Operation: tmp = math_matrix.divElem(2.5);\n";
//    tmp = math_matrix.divElem(2.5);
//    std::cout << "matrix after operation:\n";
//    std::cout << tmp << "\n\n";
//
//    std::cout << "Negative matrix: \n"
//              << -math_matrix << "\nand one more time with METHOD (neg):\n"
//              << math_matrix.neg() << '\n\n';
//
//    Matrix<double> det_matrix = {{38, 382, 21, 9}, {21, 1, 9, 11}, {118, 5, 85, 2}, {10, 8, 22, 13}};
//    std::cout << "\n\ndet_matrix:\n"
//              << det_matrix << "\n\n";
//    std::cout << "Operation: det_matrix.determinant();\n";
//    std::cout << "Result: " << det_matrix.determinant() << "\n\n";
//
//    std::cout << "Operation: det_matrix.inverse();\n";
//    det_matrix.inverse();
//    std::cout << "Result: \n"
//              << det_matrix << "\n\n";
//    det_matrix.inverse();
//    std::cout << "\nInverse one more time\nResult: \n"
//              << det_matrix << "\n\n";
//
//    std::cout << "Matrix multiplication check: \n";
//    Matrix<double> res;
//    Matrix<double> m1 = {{1}, {2}, {3}}, m2 = {{1, 2}};
//    std::cout << "Operation: m1 * m2 (m1 = { { 1 }, { 2 }, { 3 } }, m2 = { { 1, 2 } })\n";
//    res = m1 * m2;
//    std::cout << "Result:\n"
//              << res << "\n\n";
//    std::cout << "*with method* Operation: m1 * m2 (m1 = { { 1 }, { 2 }, { 3 } }, m2 = { { 1, 2 } })\n";
//    res = m1.mulMatrix(m2);
//    std::cout << "Result:\n"
//              << res << "\n\n";
//
//    std::cout << "Matrix division check: \n";
//    Matrix<double> m3 = {{1, 2}, {3, 4}};
//    Matrix<double> m4 = {{1, 2}, {3, 4}};
//    std::cout << "Operation: m3 / m4 (m4 = m3, sizes: 2x2, code line: " << __LINE__ << ")\n";
//    res = m3 / m4;
//    std::cout << "Result:\n"
//              << res << "\n\n";
//    std::cout << "*with method* Operation: m3 / m4 (m4 = m3, sizes: 2x2, code line: " << __LINE__ << ")\n";
//    res = m3.divMatrix(m4);
//    std::cout << "Result:\n"
//              << res << "\n\n";
//
//    std::cout << "MATH OPERATIONS SECTION END\n\n";
    // MATH OPERATIONS -------------------------------------------
#endif

    std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n";

#ifdef ERRORS
    // ERRORS ----------------------------------------------------
//    std::cout << "ERRORS OPERATIONS SECTION\n\n";
//
//    Matrix<double> err_matrix{{1, 2}, {3, 4}};
//
//    std::cout << "Attempt to reach wrong column:\n";
//    try {
//        err_matrix[0][100] = 1;
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    std::cout << "Attempt to reach wrong row:\n";
//    try {
//        err_matrix[100][0] = 22;
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    std::cout << "Attempt to read expired iterator\n";
//    try {
//        Iterator<double> it_tmp = err_matrix.begin();
//        {
//            Matrix<double> tmp = {{1, 2}, {3, 4}};
//            it_tmp = tmp.begin();
//        }
//        std::cout << *it_tmp;
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    std::cout << "call operator* for iterator out of the bounds:\n";
//    try {
//        Iterator<double> it_tmp = err_matrix.end();
//        std::cout << *it_tmp;
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    std::cout << "operator + for incompatible matrices:\n";
//    try {
//        Matrix<int> m1 = {{1, 2, 3}};
//        Matrix<int> m2 = {{1, 2}, {3, 4}};
//        std::cout << m1 + m2;
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    std::cout << "operator * for incompatible matrices:\n";
//    try {
//        Matrix<int> m1 = {{1, 2, 3}};
//        Matrix<int> m2 = {{1, 2, 3}};
//        std::cout << m1 * m2;
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    std::cout << "Call of constructor with invalid argument:\n";
//    try {
//        Matrix<int> matrix_inv = {{1, 2}, {3}};
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    std::cout << "Call of operator= with init list (correct and incorrect):\n";
//    try {
//        Matrix<int> matrix_inv = {{1, 2}, {3, 4}};
//        matrix_inv = {{3, 4, 5}, {1, 2, 3}};
//        std::cout << "Correct init-list done:\n"
//                  << matrix_inv << "\n";
//        matrix_inv = {{4, 5}, {1, 2, 3}};
//    } catch (ExceptionMatrix &err) {
//        std::cout << err.what() << "\n\n";
//    }
//
//    std::cout << "ERRORS OPERATIONS SECTION END\n\n";
    // ERRORS ----------------------------------------------------
#endif
}
