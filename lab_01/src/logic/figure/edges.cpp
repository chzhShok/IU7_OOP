#include <cstdio>
#include <iostream>

#include "logic/figure/edges.hpp"

void init_edges(Edges &edges) {
    edges.array = nullptr;
    edges.size = 0;
}

static Edge *allocate_edges(const size_t size) {
    if (size == 0)
        return nullptr;

    return static_cast<Edge *>(malloc(size * sizeof(Edge)));
}

void free_edges(Edges &edges) {
    free(edges.array);
}

bool edge_exists(Edge &edge, const int vertices_count) {
    return edge.vertex1 > 0 && edge.vertex1 <= vertices_count && edge.vertex2 > 0 && edge.vertex2 <= vertices_count;
}

bool read_edge(Edge &edge, FILE *file, const int vertices_count) {
    bool correct;

    if (fscanf(file, "%d%d", &edge.vertex1, &edge.vertex2) != 2 || feof(file))
        correct = false;
    else
        correct = edge_exists(edge, vertices_count);

    return correct;
}

ErrorFigure read_edges_from_file(Edges &edges, FILE *file, const int count, const int vertices_count) {
    if (!file)
        return ARGS_ERROR;

    ErrorFigure error = OK;

    edges.array = allocate_edges(count);
    if (!edges.array) {
        error = MEMORY_ERROR;
    } else {
        for (size_t i = 0; i < static_cast<size_t>(count); i++) {
            if (!read_edge(edges.array[i], file, vertices_count)) {
                free_edges(edges);
                error = READ_FILE_ERROR;
                break;
            }
        }

        if (!error)
            edges.size = count;
    }

    return error;
}

ErrorFigure process_edges_file(Edges &edges, FILE *file, const int vertices_count) {
    if (!file)
        return ARGS_ERROR;

    ErrorFigure error = OK;
    int count = count_lines(file, error);
    if (!error) {
        if (count < 0)
            error = READ_FILE_ERROR;
        else
            error = read_edges_from_file(edges, file, count, vertices_count);
    }

    return error;
}

ErrorFigure upload_edges(Edges &edges, const char *filepath, const Vertices &vertices) {
    if (!filepath)
        return ARGS_ERROR;

    ErrorFigure error = OK;
    FILE *file = fopen(filepath, "r");
    if (!file) {
        error = OPEN_FILE_ERROR;
    } else {
        error = process_edges_file(edges, file, vertices.size);
    }

    fclose(file);

    return error;
}
