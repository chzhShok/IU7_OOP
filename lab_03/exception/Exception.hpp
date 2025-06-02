#pragma once

#include <exception>
#include <string>

class Exception : public std::exception {
protected:
    static const size_t errSize = 512;
    char errMsg[errSize] = "";

public:
    Exception(const char *time, const char *filename,
              const size_t line, const char *class_name,
              const char *method_name, const char *info);
    virtual const char *what() const noexcept override;
};

class DirectorException : public Exception {
public:
    DirectorException(const char *time, const char *filename,
                      const size_t line, const char *class_name,
                      const char *method_name,
                      const char *info = "Director exception.")
        : Exception(time, filename, line, class_name, method_name, info) {};
};

class BoneModelDirectorException : public DirectorException {
public:
    BoneModelDirectorException(const char *time, const char *filename,
                               const size_t line, const char *class_name,
                               const char *method_name,
                               const char *info = "Bonemodel director exception.")
        : DirectorException(time, filename, line, class_name, method_name, info) {};
};

class BoneModelDirectorWrongLoaderException : public BoneModelDirectorException {
public:
    BoneModelDirectorWrongLoaderException(const char *time, const char *filename,
                                          const size_t line, const char *class_name,
                                          const char *method_name,
                                          const char *info = "Wrong Loader type passed to director, expected BoneModelLoader exception.")
        : BoneModelDirectorException(time, filename, line, class_name, method_name, info) {};
};

class ManagerException : public Exception {
public:
    ManagerException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Manager exception.")
        : Exception(time, filename, line, class_name, method_name, info) {};
};

class LoadManagerException : public ManagerException {
public:
    LoadManagerException(const char *time, const char *filename,
                         const size_t line, const char *class_name,
                         const char *method_name,
                         const char *info = "Manager exception.")
        : ManagerException(time, filename, line, class_name, method_name, info) {};
};

class LoadManagerWrongDirectorException : public LoadManagerException {
public:
    LoadManagerWrongDirectorException(const char *time, const char *filename,
                                      const size_t line, const char *class_name,
                                      const char *method_name,
                                      const char *info = "Manager exception.")
        : LoadManagerException(time, filename, line, class_name, method_name, info) {};
};

class LoadManagerWrongLoaderException : public LoadManagerException {
public:
    LoadManagerWrongLoaderException(const char *time, const char *filename,
                                    const size_t line, const char *class_name,
                                    const char *method_name,
                                    const char *info = "Manager exception.")
        : LoadManagerException(time, filename, line, class_name, method_name, info) {};
};

class MatrixException : public Exception {
public:
    MatrixException(const char *time, const char *filename,
                    const size_t line, const char *class_name,
                    const char *method_name,
                    const char *info = "Matrix exception.")
        : Exception(time, filename, line, class_name, method_name, info) {};
};

class MatrixRowException : public MatrixException {
public:
    MatrixRowException(const char *time, const char *filename,
                       const size_t line, const char *class_name,
                       const char *method_name,
                       const char *info = "Matrix exception.")
        : MatrixException(time, filename, line, class_name, method_name, info) {};
};

class MatrixRowOutOfRangeException : public MatrixRowException {
public:
    MatrixRowOutOfRangeException(const char *time, const char *filename,
                                 const size_t line, const char *class_name,
                                 const char *method_name,
                                 const char *info = "Matrix Row index out of range.")
        : MatrixRowException(time, filename, line, class_name, method_name, info) {};
};

class MatrixOutOfRangeException : public MatrixException {
public:
    MatrixOutOfRangeException(const char *time, const char *filename,
                              const size_t line, const char *class_name,
                              const char *method_name,
                              const char *info = "Matrix index out of range.")
        : MatrixException(time, filename, line, class_name, method_name, info) {};
};

class MatrixMultiplySizeException : public MatrixException {
public:
    MatrixMultiplySizeException(const char *time, const char *filename,
                                const size_t line, const char *class_name,
                                const char *method_name,
                                const char *info = "Matrix multiplication sizes exception.")
        : MatrixException(time, filename, line, class_name, method_name, info) {};
};

class MatrixAddSizeException : public MatrixException {
public:
    MatrixAddSizeException(const char *time, const char *filename,
                           const size_t line, const char *class_name,
                           const char *method_name,
                           const char *info = "Matrix add sizes exception.")
        : MatrixException(time, filename, line, class_name, method_name, info) {};
};

class ModelStructureException : public Exception {
public:
    ModelStructureException(const char *time, const char *filename,
                            const size_t line, const char *class_name,
                            const char *method_name,
                            const char *info = "Model structure exception.")
        : Exception(time, filename, line, class_name, method_name, info) {};
};

class EdgeOutOfPointsException : public ModelStructureException {
public:
    EdgeOutOfPointsException(const char *time, const char *filename,
                             const size_t line, const char *class_name,
                             const char *method_name,
                             const char *info = "Edge has not existing points exception.")
        : ModelStructureException(time, filename, line, class_name, method_name, info) {};
};

class SolutionException : public Exception {
public:
    SolutionException(const char *time, const char *filename,
                      const size_t line, const char *class_name,
                      const char *method_name,
                      const char *info = "Solution exception.")
        : Exception(time, filename, line, class_name, method_name, info) {};
};

class SolutionNotFoundException : public SolutionException {
public:
    SolutionNotFoundException(const char *time, const char *filename,
                              const size_t line, const char *class_name,
                              const char *method_name,
                              const char *info = "Solution exception.")
        : SolutionException(time, filename, line, class_name, method_name, info) {};
};

class SolutionAlreadyInException : public SolutionException {
public:
    SolutionAlreadyInException(const char *time, const char *filename,
                               const size_t line, const char *class_name,
                               const char *method_name,
                               const char *info = "Solution exception.")
        : SolutionException(time, filename, line, class_name, method_name, info) {};
};

class SqlLoaderException : public Exception {
public:
    SqlLoaderException(const char *time, const char *filename,
                       const size_t line, const char *class_name,
                       const char *method_name,
                       const char *info = "Sql Loader exception.")
        : Exception(time, filename, line, class_name, method_name, info) {};
};

class SqlNoFileException : public SqlLoaderException {
public:
    SqlNoFileException(const char *time, const char *filename,
                       const size_t line, const char *class_name,
                       const char *method_name,
                       const char *info = "Can't open sql file exception.")
        : SqlLoaderException(time, filename, line, class_name, method_name, info) {};
};

class SqlReadException : public SqlLoaderException {
public:
    SqlReadException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Can't read from sql file exception.")
        : SqlLoaderException(time, filename, line, class_name, method_name, info) {};
};

class TxtLoaderException : public Exception {
public:
    TxtLoaderException(const char *time, const char *filename,
                       const size_t line, const char *class_name,
                       const char *method_name,
                       const char *info = "Txt Loader exception.")
        : Exception(time, filename, line, class_name, method_name, info) {};
};

class TxtNoFileException : public TxtLoaderException {
public:
    TxtNoFileException(const char *time, const char *filename,
                       const size_t line, const char *class_name,
                       const char *method_name,
                       const char *info = "Can't open txt file exception.")
        : TxtLoaderException(time, filename, line, class_name, method_name, info) {};
};

class TxtReadException : public TxtLoaderException {
public:
    TxtReadException(const char *time, const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Can't read from txt file exception.")
        : TxtLoaderException(time, filename, line, class_name, method_name, info) {};
};

class JsonLoaderException : public Exception {
public:
    JsonLoaderException(const char *time, const char *filename,
                        const size_t line, const char *class_name,
                        const char *method_name,
                        const char *info = "Json Loader exception.")
        : Exception(time, filename, line, class_name, method_name, info) {};
};

class JsonNoFileException : public JsonLoaderException {
public:
    JsonNoFileException(const char *time, const char *filename,
                        const size_t line, const char *class_name,
                        const char *method_name,
                        const char *info = "Can't open json file exception.")
        : JsonLoaderException(time, filename, line, class_name, method_name, info) {};
};
