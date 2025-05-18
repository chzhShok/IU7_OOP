#pragma once

#include "exception.h"

ExceptionMatrix::ExceptionMatrix(const std::string filename, const std::string classname, const int line, const char *time, std::string info) {
    error_info = "\nFile name: " + filename +
                 "\nClass: " + classname +
                 "\nLine: " + std::to_string(line) +
                 "\nTime: " + time +
                 "Info: " + info;
}
