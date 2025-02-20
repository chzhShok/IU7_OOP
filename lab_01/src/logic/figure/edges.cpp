#include <iostream>
#include <cstdio>

#include "logic/figure/edges.hpp"

void init_edges(Edges &edges) {
    edges.array = nullptr;
}

static Edge *allocate_edges(const size_t size) {
    if (size == 0)
        return nullptr;

    const auto edges = static_cast<Edge *>(malloc(size * sizeof(Edge)));
    if (!edges)
        return nullptr;

    return edges;
}

void free_edges(Edge *edges) {
    free(edges);
}

ErrorFigure upload_edges(const char *filepath, Edges &edges) {
    if (!filepath)
        return ARGS_ERROR;

    FILE *file = fopen(filepath, "r");
    if (!file)
        return OPEN_FILE_ERROR;

    ErrorFigure error = OK;
    const int n = count_lines(file, error);
    if (error) {
        fclose(file);
        return error;
    }
    if (n < 0) {
        fclose(file);
        return READ_FILE_ERROR;
    }

    edges.array = allocate_edges(n);
    if (!edges.array) {
        fclose(file);
        return MEMORY_ERROR;
    }

    size_t i = 0;
    while (i != n) {
        if (fscanf(file, "%d%d", &edges.array[i].vertex1, &edges.array[i].vertex2) != 2 && !feof(file)) {
            fclose(file);
            free_edges(edges.array);
            return READ_FILE_ERROR;
        }
        i++;
    }

    edges.size = i;

    fclose(file);

    return OK;
}
