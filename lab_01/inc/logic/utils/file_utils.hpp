#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include <cstdio>
#include <QString>

#include "logic/errors/errors.hpp"

#define VERTICES_STD_PATH "vertices.txt"
#define EDGES_STD_PATH "edges.txt"

struct FilesPath {
    char *path_vertices;
    char *path_edges;
};

ErrorFigure count_lines(size_t &count, FILE *file);

FilesPath dir_path_to_files_paths(const QString &dir_path);

#endif// FILE_UTILS_HPP
