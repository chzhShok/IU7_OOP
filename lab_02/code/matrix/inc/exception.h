#pragma once

#include <string>

class ExceptionMatrix : public std::exception {
public:
    ExceptionMatrix(const std::string filename, const std::string classname, const int line, const char *time, std::string info = "Error!");
    virtual const char *what() const noexcept override { return error_info.c_str(); }
    virtual ~ExceptionMatrix() {};

protected:
    std::string error_info;
};

class MemoryError : public ExceptionMatrix {
public:
    MemoryError(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Memory allocation error\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class IndexError : public ExceptionMatrix {
public:
    IndexError(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Index error\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class InvalidIterator : public ExceptionMatrix {
public:
    InvalidIterator(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Invalid iterator\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class InvalidSize : public ExceptionMatrix {
public:
    InvalidSize(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Invalid size of matrix\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class InvalidPointer : public ExceptionMatrix {
public:
    InvalidPointer(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Invalid pointer\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class InvalidArgument : public ExceptionMatrix {
public:
    InvalidArgument(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Invalid argument\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class IncompatibleMatrices : public ExceptionMatrix {
public:
    IncompatibleMatrices(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Incompatible matrices\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class InvalidMatrix : public ExceptionMatrix {
public:
    InvalidMatrix(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Invalid matrix\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class IncompatibleElements : public ExceptionMatrix {
public:
    IncompatibleElements(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Incompatible elements\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};


class ZeroDivision : public ExceptionMatrix {
public:
    ZeroDivision(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Zero division\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

#include "exception.hpp"
