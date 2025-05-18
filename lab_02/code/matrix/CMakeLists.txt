cmake_minimum_required(VERSION 3.10)

project(matrix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(inc impl src)

add_executable(matrix
        src/main.cpp
        inc/base_iterator.h
        inc/base_matrix.h
        inc/const_iterator.h
        inc/exception.h
        inc/iterator.h
        inc/matrix.h
        impl/const_iterator.hpp
        impl/exception.hpp
        impl/iterator.hpp
        impl/matrix_iterator.hpp
        impl/matrix_methods.hpp
        impl/matrix_operation_element.hpp
        impl/matrix_operations_matrix.hpp
        impl/matrix_row.hpp
        impl/concept.hpp
)
