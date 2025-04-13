cmake_minimum_required(VERSION 3.30)
project(hash_table)

set(CMAKE_CXX_STANDARD 20)

include_directories(inc src impl)

add_executable(hash_table
        src/main.cpp
        inc/base_hash_table.h
        inc/base_iterator.h
        inc/exception.h
        inc/hash_iterator.h
        inc/hash_table.h
        impl/hash_iterator.hpp
)
