#include "logic/figure/figure.hpp"

Figure init_figure() {
    Figure figure;
    figure.vertices = init_vertices();
    figure.edges = init_edges();

    return figure;
}

void free_figure(Figure &figure) {
    free_vertices(figure.vertices);
    free_edges(figure.edges);
}

static void move_figure(Figure &dst, const Figure &src) {
    dst = src;
}

static ErrorFigure validate_figure(const Vertices &vertices, const Edges &edges) {
    if (!vertices.array || !vertices.size)
        return ARGS_ERROR;

    ErrorFigure error = init_error();

    for (size_t i = 0; error_is_ok(error) && i < edges.size; i++)
        error = edge_is_valid(edges.array[i], vertices.size);

    return error;
}

ErrorFigure create_figure_from_file(Figure &figure, const FilesPath &path) {
    ErrorFigure error = upload_vertices(figure.vertices, path.path_vertices);

    if (error_is_ok(error)) {
        error = upload_edges(figure.edges, path.path_edges);
        if (!error_is_ok(error)) {
            free_vertices(figure.vertices);
        }
    }

    return error;
}

ErrorFigure upload_figure(Figure &figure, const FilesPath &path) {
    Figure new_figure;
    ErrorFigure error = create_figure_from_file(new_figure, path);

    if (error_is_ok(error)) {
        error = validate_figure(new_figure.vertices, new_figure.edges);
        if (error_is_ok(error)) {
            free_figure(figure);
            move_figure(figure, new_figure);
        } else {
            free_figure(new_figure);
        }
    }

    return error;
}

ErrorFigure move_figure(Figure &figure, const Move &move_data) {
    if (!is_init_vertices_array(figure.vertices))
        return ARGS_ERROR;

    return move_all_vertices(figure.vertices, move_data);
}

ErrorFigure rotate_figure(Figure &figure, const Rotate &rotate_data) {
    if (!is_init_vertices_array(figure.vertices))
        return ARGS_ERROR;

    return rotate_all_vertices(figure.vertices, rotate_data);
}

ErrorFigure scale_figure(Figure &figure, const Scale &scale_data) {
    if (!is_init_vertices_array(figure.vertices))
        return ARGS_ERROR;

    return scale_all_vertices(figure.vertices, scale_data);
}
