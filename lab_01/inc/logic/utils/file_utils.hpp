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

int count_lines(FILE *file, ErrorFigure &error);

FilesPath dir_path_to_files_paths(const QString &dir_path);

#endif// FILE_UTILS_HPP
