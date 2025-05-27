#pragma once

#include <exception>
#include <string>

class BaseException : public std::exception {
protected:
    static const size_t errSize = 512;
    char errMsg[errSize] = "";

public:
    BaseException(const char *time, const char *filename, const size_t line,
                  const char *class_name, const char *method_name,
                  const char *info);
    virtual const char *what() const noexcept override;
};

class TxtNoFileException : public BaseException {
public:
    TxtNoFileException(const char *time, const char *filename,
                       const size_t line, const char *class_name,
                       const char *method_name,
                       const char *info = "Can't open txt file exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class TxtReadException : public BaseException {
public:
    TxtReadException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Can't read from txt file exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class CsvNoFileException : public BaseException {
public:
    CsvNoFileException(const char *time, const char *filename,
                       const size_t line, const char *class_name,
                       const char *method_name,
                       const char *info = "Can't open csv file exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class CsvReadException : public BaseException {
public:
    CsvReadException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Can't read from csv file exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class EdgeOutOfPointsException : public BaseException {
public:
    EdgeOutOfPointsException(const char *time, const char *filename,
                             const size_t line, const char *class_name,
                             const char *method_name,
                             const char *info = "Edge has not existing points exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class MatrixRowException : public BaseException {
public:
    MatrixRowException(const char *time, const char *filename,
                       const size_t line, const char *class_name,
                       const char *method_name,
                       const char *info = "Matrix exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class MatrixRowOutOfRangeException : public BaseException {
public:
    MatrixRowOutOfRangeException(const char *time, const char *filename,
                                 const size_t line, const char *class_name,
                                 const char *method_name,
                                 const char *info = "Matrix Row index out of range.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class MatrixOutOfRangeException : public BaseException {
public:
    MatrixOutOfRangeException(const char *time, const char *filename,
                              const size_t line, const char *class_name,
                              const char *method_name,
                              const char *info = "Matrix index out of range.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class MatrixMultiplySizeException : public BaseException {
public:
    MatrixMultiplySizeException(const char *time, const char *filename,
                                const size_t line, const char *class_name,
                                const char *method_name,
                                const char *info = "Matrix multiplication sizes exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class MatrixAddSizeException : public BaseException {
public:
    MatrixAddSizeException(const char *time, const char *filename,
                           const size_t line, const char *class_name,
                           const char *method_name,
                           const char *info = "Matrix add sizes exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class LoadManagerException : public BaseException {
public:
    LoadManagerException(const char *time, const char *filename,
                         const size_t line, const char *class_name,
                         const char *method_name,
                         const char *info = "Manager exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class LoadManagerWrongDirectorException : public BaseException {
public:
    LoadManagerWrongDirectorException(const char *time, const char *filename,
                                      const size_t line, const char *class_name,
                                      const char *method_name,
                                      const char *info = "Manager exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class LoadManagerWrongReaderException : public BaseException {
public:
    LoadManagerWrongReaderException(const char *time, const char *filename,
                                    const size_t line, const char *class_name,
                                    const char *method_name,
                                    const char *info = "Manager exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class BoneModelDirectorWrongReaderException : public BaseException {
public:
    BoneModelDirectorWrongReaderException(const char *time, const char *filename,
                                          const size_t line, const char *class_name,
                                          const char *method_name,
                                          const char *info = "Wrong Reader type passed to director, expected CarcassModelLoader exception.")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class SolutionAlreadyInException : public BaseException {
public:
    SolutionAlreadyInException(const char *time, const char *filename,
                               const size_t line, const char *class_name,
                               const char *method_name,
                               const char *info = "Solution already exists")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class SolutionNotFoundException : public BaseException {
public:
    SolutionNotFoundException(const char *time, const char *filename,
                               const size_t line, const char *class_name,
                               const char *method_name,
                               const char *info = "Solution not found")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};

class NoFileException : public BaseException {
public:
    NoFileException(const char *time, const char *filename,
                              const size_t line, const char *class_name,
                              const char *method_name,
                              const char *info = "No such file")
        : BaseException(time, filename, line, class_name, method_name, info) {};
};
