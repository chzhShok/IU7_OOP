#ifndef ERRORS_HPP
#define ERRORS_HPP

enum ErrorFigure {
    OK,
    ARGS_ERROR,
    OPEN_FILE_ERROR,
    READ_FILE_ERROR,
    MEMORY_ERROR,
    DEBUG,
};

char *manage_error(const ErrorFigure error);

int error_is_ok(const ErrorFigure error);

#endif//ERRORS_HPP
