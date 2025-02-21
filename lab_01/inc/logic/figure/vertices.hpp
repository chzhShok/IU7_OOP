#ifndef VERTICES_HPP
#define VERTICES_HPP

#include "logic/errors/errors.hpp"
#include "logic/utils/file_utils.hpp"

struct Move {
    double dx;
    double dy;
    double dz;
};

struct Rotate {
    double x;
    double y;
    double z;
    double dx;
    double dy;
    double dz;
};

struct Scale {
    double x;
    double y;
    double z;
    double k;
};

struct Vertex {
    double x;
    double y;
    double z;
};

struct Vertices {
    Vertex *array;
    size_t size;
};

void init_vertices(Vertices &vertices);

void free_vertices(Vertices &vertices);

int is_init_vertices_array(const Vertices &vertices);

ErrorFigure upload_vertices(Vertices &vertices, const char *filepath);

ErrorFigure move_all_vertices(Vertices &vertices, const Move &move_data);

ErrorFigure rotate_all_vertices(Vertices &vertices, const Rotate &rotate_data);

ErrorFigure scale_all_vertices(Vertices &vertices, const Scale &scale_data);

#endif//VERTICES_HPP
