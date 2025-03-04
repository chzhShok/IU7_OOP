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

static ErrorFigure edge_is_valid(const Edge &edge, size_t size) {
    ErrorFigure error = init_error();

    if (edge.vertex1 > size || edge.vertex1 <= 0 || edge.vertex2 > size || edge.vertex2 <= 0)
        error = INVALID_EDGES;

    return error;
}

static ErrorFigure figure_is_valid(const Vertices &vertices, const Edges &edges) {
    ErrorFigure error = init_error();

    for (size_t i = 0; error_is_ok(error) && i < edges.size; i++)
        error = edge_is_valid(edges.array[i], vertices.size);

    return error;
}

ErrorFigure create_figure_from_file(Figure &figure, const FilesPath &path) {
    Vertices vertices = init_vertices();

    ErrorFigure error = upload_vertices(vertices, path.path_vertices);

    if (error_is_ok(error)) {
        Edges edges = init_edges();
        error = upload_edges(edges, path.path_edges);
        if (!error_is_ok(error)) {
            free_vertices(vertices);
        } else {
            error = figure_is_valid(vertices, edges);
            if (!error_is_ok(error)) {
                free_vertices(vertices);
                free_edges(edges);
            } else {
                figure.edges = edges;
                figure.vertices = vertices;
            }
        }
    }

    return error;
}

ErrorFigure upload_figure(Figure &figure, const FilesPath &path) {
    Figure new_figure;
    ErrorFigure error = create_figure_from_file(new_figure, path);

    if (error_is_ok(error)) {
        free_figure(figure);
        figure = new_figure;
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
