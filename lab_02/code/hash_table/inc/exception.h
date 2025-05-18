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

class NegativeIncrement : public ExceptionMatrix {
public:
    NegativeIncrement(
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
            std::string info = "Invalid iterator\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};

class InvalidMaxLoadFactor : public ExceptionMatrix {
public:
    InvalidMaxLoadFactor(
            const std::string filename,
            std::string classname,
            int line,
            const char *time,
            std::string info = "Invalid iterator\n") : ExceptionMatrix(filename, classname, line, time, info) {};
};
