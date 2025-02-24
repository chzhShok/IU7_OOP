#include "logic/errors/errors.hpp"

int error_is_ok(const ErrorFigure error) {
    return error == OK;
}

char *manage_error(const ErrorFigure error) {
    char *message = "";

    if (error == ARGS_ERROR)
        message = "Некорректные аргументы";
    else if (error == OPEN_FILE_ERROR)
        message = "Ошибка при открытии файла";
    else if (error == READ_FILE_ERROR)
        message = "Ошибка во время чтения файла";
    else if (error == MEMORY_ERROR)
        message = "Ошибка работы с памятью";
    else if (error == DEBUG)
        message = "Попался";

    return message;
}
