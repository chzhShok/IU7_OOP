#include <iostream>
#include <cstdio>
#include <cmath>

#include "logic/figure/vertices.hpp"

double to_radians(const double angle) {
    return angle * M_PI / 180;
}

void init_vertices(Vertices &vertices) {
    vertices.array = nullptr;
}

static Vertex *allocate_vertices(const size_t size) {
    if (size == 0)
        return nullptr;

    const auto vertices = static_cast<Vertex *>(malloc(size * sizeof(Vertex)));
    if (!vertices)
        return nullptr;

    return vertices;
}

void free_vertices(Vertex *vertices) {
    free(vertices);
}

int is_init_vertices_array(const Vertices &vertices) {
    return vertices.array != nullptr;
}

ErrorFigure upload_vertices(const char *filepath, Vertices &vertices) {
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

    vertices.array = allocate_vertices(n);
    if (!vertices.array) {
        fclose(file);
        return MEMORY_ERROR;
    }

    size_t i = 0;
    while (i != static_cast<size_t>(n)) {
        if (fscanf(file, "%lf%lf%lf", &vertices.array[i].x, &vertices.array[i].y, &vertices.array[i].z) != 3 && !
            feof(file)) {
            free_vertices(vertices.array);
            fclose(file);
            return READ_FILE_ERROR;
        }
        i++;
    }

    vertices.size = i;

    fclose(file);

    return OK;
}

void move_vertex(Vertex &vertex, const Move &move_data) {
    vertex.x += move_data.dx;
    vertex.y += move_data.dy;
    vertex.z += move_data.dz;
}

ErrorFigure move_all_vertices(const Vertices &vertices, const Move &move_data) {
    if (!vertices.array || !vertices.size)
        return ARGS_ERROR;

    for (size_t i = 0; i != vertices.size; i++)
        move_vertex(vertices.array[i], move_data);

    return OK;
}

static void rotate_xp(Vertex &vertex, const Rotate &rotate_data) {
    const double cos_x = cos(to_radians(rotate_data.dx));
    const double sin_x = sin(to_radians(rotate_data.dx));
    const double y = vertex.y;

    vertex.y = (vertex.y - rotate_data.y) * cos_x + (vertex.z - rotate_data.z) * sin_x + rotate_data.y;
    vertex.z = -(y - rotate_data.y) * sin_x + (vertex.z - rotate_data.z) * cos_x + rotate_data.z;
}

static void rotate_yp(Vertex &vertex, const Rotate &rotate_data) {
    const double cos_y = cos(to_radians(rotate_data.dy));
    const double sin_y = sin(to_radians(rotate_data.dy));
    const double x = vertex.x;

    vertex.x = (vertex.x - rotate_data.x) * cos_y + (vertex.z - rotate_data.z) * sin_y + rotate_data.x;
    vertex.z = -(x - rotate_data.x) * sin_y + (vertex.z - rotate_data.z) * cos_y + rotate_data.z;
}

static void rotate_zp(Vertex &vertex, const Rotate &rotate_data) {
    const double cos_z = cos(to_radians(rotate_data.dz));
    const double sin_z = sin(to_radians(rotate_data.dz));
    const double x = vertex.x;

    vertex.x = (vertex.x - rotate_data.x) * cos_z + (vertex.y - rotate_data.y) * sin_z + rotate_data.x;
    vertex.y = -(x - rotate_data.x) * sin_z + (vertex.y - rotate_data.y) * cos_z + rotate_data.y;
}

void rotate_vertex(Vertex &vertex, const Rotate &rotate_data) {
    rotate_xp(vertex, rotate_data);
    rotate_yp(vertex, rotate_data);
    rotate_zp(vertex, rotate_data);
}

ErrorFigure rotate_all_vertices(const Vertices &vertices, const Rotate &rotate_data) {
    if (!vertices.array || !vertices.size)
        return ARGS_ERROR;

    for (size_t i = 0; i != vertices.size; i++)
        rotate_vertex(vertices.array[i], rotate_data);

    return OK;
}

void scale_vertex(Vertex &vertex, const Scale &scale_data) {
    vertex.x = scale_data.x + (vertex.x - scale_data.x) * scale_data.k;
    vertex.y = scale_data.y + (vertex.y - scale_data.y) * scale_data.k;
    vertex.z = scale_data.z + (vertex.z - scale_data.z) * scale_data.k;
}

ErrorFigure scale_all_vertices(const Vertices &vertices, const Scale &scale_data) {
    if (!vertices.array || !vertices.size)
        return ARGS_ERROR;

    for (size_t i = 0; i != vertices.size; i++)
        scale_vertex(vertices.array[i], scale_data);

    return OK;
}
