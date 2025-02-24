#include "logic/figure/figure.hpp"

Figure &init_figure() {
    static Figure figure;

    init_vertices(figure.vertices);
    init_edges(figure.edges);

    return figure;
}

void free_figure(Figure &figure) {
    free_vertices(figure.vertices);
    free_edges(figure.edges);
}

ErrorFigure upload_figure(Figure &figure, const FilesPath &path) {
    if (!path.path_edges || !path.path_vertices)
        return ARGS_ERROR;

    Figure new_figure;
    init_vertices(new_figure.vertices);
    init_edges(new_figure.edges);

    ErrorFigure error = upload_vertices(new_figure.vertices, path.path_vertices);
    if (error_is_ok(error)) {
        error = upload_edges(new_figure.edges, path.path_edges, new_figure.vertices);
        if (error_is_ok(error))
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
