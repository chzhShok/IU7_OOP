#include <QFile>
#include <QString>

#include <cstdio>

#include "logic/utils/file_utils.hpp"

ErrorFigure count_lines(size_t &count, FILE *file) {
    if (!file)
        return ARGS_ERROR;

    ErrorFigure error = init_error();
    size_t n = 0;
    while (!feof(file)) {
        if (fscanf(file, "%*[^\n]%*c") == -1 && !feof(file))
            error = MEMORY_ERROR;
        else
            n++;
    }

    if (error_is_ok(error))
        count = n - 1;

    rewind(file);

    return error;
}

FilesPath dir_path_to_files_paths(const QString &dir_path) {
    FilesPath paths = {nullptr, nullptr};

    QString verticesPath = dir_path + "/" + VERTICES_STD_PATH;
    QString edgesPath = dir_path + "/" + EDGES_STD_PATH;

    if (QFile::exists(verticesPath))
        paths.path_vertices = strdup(verticesPath.toStdString().c_str());

    if (QFile::exists(edgesPath))
        paths.path_edges = strdup(edgesPath.toStdString().c_str());

    return paths;
}
