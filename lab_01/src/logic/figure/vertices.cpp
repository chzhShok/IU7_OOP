#include <cmath>
#include <cstdio>

#include "logic/figure/vertices.hpp"

double to_radians(const double angle) {
    return angle * M_PI / 180;
}

void init_vertices(Vertices &vertices) {
    vertices.array = nullptr;
    vertices.size = 0;
}

static Vertex *allocate_vertices(const size_t size) {
    if (size == 0)
        return nullptr;

    return static_cast<Vertex *>(malloc(size * sizeof(Vertex)));
}

void free_vertices(Vertices &vertices) {
    free(vertices.array);
}

int is_init_vertices_array(const Vertices &vertices) {
    return vertices.array != nullptr;
}

bool read_vertex(Vertex &vertex, FILE *file) {
    return fscanf(file, "%lf%lf%lf", &vertex.x, &vertex.y, &vertex.z) == 3 || feof(file);
}

ErrorFigure read_vertices_from_file(Vertices &vertices, FILE *file, const int count) {
    if (!file)
        return ARGS_ERROR;

    ErrorFigure error = OK;

    vertices.array = allocate_vertices(count);
    if (!vertices.array) {
        error = MEMORY_ERROR;
    } else {
        for (size_t i = 0; i < static_cast<size_t>(count); i++) {
            if (!read_vertex(vertices.array[i], file)) {
                free_vertices(vertices);
                error = READ_FILE_ERROR;
                break;
            }
        }

        if (!error)
            vertices.size = count;
    }

    return error;
}

ErrorFigure process_file(Vertices &vertices, FILE *file) {
    if (!file)
        return ARGS_ERROR;

    ErrorFigure error = OK;
    int count = count_lines(file, error);
    if (!error) {
        if (count < 0)
            error = READ_FILE_ERROR;
        else
            error = read_vertices_from_file(vertices, file, count);
    }

    return error;
}

ErrorFigure upload_vertices(Vertices &vertices, const char *filepath) {
    if (!filepath)
        return ARGS_ERROR;

    ErrorFigure error = OK;
    FILE *file = fopen(filepath, "r");
    if (!file) {
        error = OPEN_FILE_ERROR;
    } else {
        error = process_file(vertices, file);
    }

    fclose(file);

    return error;
}

void move_vertex(Vertex &vertex, const Move &move_data) {
    vertex.x += move_data.dx;
    vertex.y += move_data.dy;
    vertex.z += move_data.dz;
}

ErrorFigure move_all_vertices(Vertices &vertices, const Move &move_data) {
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

ErrorFigure rotate_all_vertices(Vertices &vertices, const Rotate &rotate_data) {
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

ErrorFigure scale_all_vertices(Vertices &vertices, const Scale &scale_data) {
    if (!vertices.array || !vertices.size)
        return ARGS_ERROR;

    for (size_t i = 0; i != vertices.size; i++)
        scale_vertex(vertices.array[i], scale_data);

    return OK;
}
