#include <cstdio>
#include <iostream>

#include "logic/figure/edges.hpp"

Edges init_edges() {
    return {nullptr, 0};
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

    edges.array = nullptr;
    edges.size = 0;
}

ErrorFigure edge_is_valid(const Edge &edge, size_t size) {
    ErrorFigure error = init_error();

    if (edge.vertex1 > size || edge.vertex1 <= 0 || edge.vertex2 > size || edge.vertex2 <= 0)
        error = INVALID_EDGES;

    return error;
}

static bool read_edge(Edge &edge, FILE *file) {
    return fscanf(file, "%d%d", &edge.vertex1, &edge.vertex2) == 2 || feof(file);
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

    ErrorFigure error = count_lines(edges.size, file);
    if (error_is_ok(error) && edges.size > 0) {
        error = allocate_edges(edges.array, edges.size);
        if (error_is_ok(error)) {
            error = read_edges_from_file(edges.array, file, edges.size);
            if (!error_is_ok(error)) {
                free(edges.array);
            }
        }
    }

    return error;
}

ErrorFigure upload_edges(Edges &edges, const char *filepath) {
    if (!filepath)
        return ARGS_ERROR;

    edges = init_edges();
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
