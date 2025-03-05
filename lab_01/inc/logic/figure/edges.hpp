#ifndef EDGES_HPP
#define EDGES_HPP

#include "logic/figure/vertices.hpp"

typedef struct Edge Edge;
typedef struct Edges Edges;

struct Edge {
    int vertex1;
    int vertex2;
};

struct Edges {
    Edge *array;
    size_t size;
};

Edges init_edges();

void free_edges(Edges &edges);

ErrorFigure upload_edges(Edges &edges, const char *filepath);
ErrorFigure edge_is_valid(const Edge &edge, size_t size);

#endif//EDGES_HPP
