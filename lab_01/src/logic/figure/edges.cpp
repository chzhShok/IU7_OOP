#include <cstdio>
#include <iostream>

#include "logic/figure/edges.hpp"

Edges init_edges() {
    return {NULL, 0};
}

static ErrorFigure allocate_edges(Edge *&edge, const size_t size) {
    if (size == 0)
        return ARGS_ERROR;

    ErrorFigure error = init_error();
    Edge *tmp = static_cast<Edge *>(malloc(size * sizeof(Edge)));
    if (!tmp)
        error = MEMORY_ERROR;
    else
        edge = tmp;

    return error;
}

void free_edges(Edges &edges) {
    if (edges.array)
        free(edges.array);

    edges.array = NULL;
    edges.size = 0;
}

static bool read_edge(Edge &edge, FILE *file) {
    return fscanf(file, "%d%d", &edge.vertex1, &edge.vertex2) != 2 || feof(file);
}

static ErrorFigure read_edges_from_file(Edge *&array, FILE *file, const size_t count) {
    if (!file || !array)
        return ARGS_ERROR;

    ErrorFigure error = init_error();
    for (size_t i = 0; i < count && error_is_ok(error); i++) {
        if (!read_edge(array[i], file))
            error = READ_FILE_ERROR;
    }
    return error;
}

static ErrorFigure process_edges_file(Edges &edges, FILE *file) {
    if (!file)
        return ARGS_ERROR;

    size_t count = 0;
    ErrorFigure error = count_lines(count, file);
    if (error_is_ok(error) && count > 0) {
        Edge *temp = nullptr;
        error = allocate_edges(temp, count);
        if (error_is_ok(error)) {
            error = read_edges_from_file(temp, file, count);
            if (!error_is_ok(error)) {
                free(temp);
            } else {
                edges.array = temp;
                edges.size = count;
            }
        }
    }

    return error;
}

ErrorFigure upload_edges(Edges &edges, const char *filepath) {
    if (!filepath)
        return ARGS_ERROR;

    ErrorFigure error = init_error();
    FILE *file = fopen(filepath, "r");
    if (!file) {
        error = OPEN_FILE_ERROR;
    } else {
        error = process_edges_file(edges, file);
        fclose(file);
    }

    return error;
}
