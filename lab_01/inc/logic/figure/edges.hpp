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

void init_edges(Edges &edges);

ErrorFigure upload_edges(const char *filepath, Edges &edges);

#endif//EDGES_HPP
