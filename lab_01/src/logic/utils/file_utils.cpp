#include <QString>
#include <QFile>

#include <cstdio>

#include "logic/utils/file_utils.hpp"

int count_lines(FILE *file, ErrorFigure &error) {
    if (!file) {
        error = ARGS_ERROR;
        return -1;
    }

    size_t count = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file))
        ++count;

    rewind(file);
    error = OK;

    return static_cast<int>(count);
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
