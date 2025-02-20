#include "logic/figure/figure.hpp"

Figure &init_figure() {
    static Figure figure;

    init_vertices(figure.vertices);
    init_edges(figure.edges);

    return figure;
}

ErrorFigure upload_figure(const FilesPath &path, Figure &figure) {
    if (!path.path_edges || !path.path_vertices)
        return ARGS_ERROR;

    ErrorFigure error = OK;

    error = upload_vertices(path.path_vertices, figure.vertices);
    if (!error_is_ok(error))
        return error;

    error = upload_edges(path.path_edges, figure.edges);
    if (!error_is_ok(error))
        return error;

    return error;
}

ErrorFigure move_figure(const Move &move_data, const Figure &figure) {
    if (!is_init_vertices_array(figure.vertices))
        return ARGS_ERROR;

    return move_all_vertices(figure.vertices, move_data);
}

ErrorFigure rotate_figure(const Rotate &rotate_data, const Figure &figure) {
    if (!is_init_vertices_array(figure.vertices))
        return ARGS_ERROR;

    return rotate_all_vertices(figure.vertices, rotate_data);
}

ErrorFigure scale_figure(const Scale &scale_data, const Figure &figure) {
    if (!is_init_vertices_array(figure.vertices))
        return ARGS_ERROR;

    return scale_all_vertices(figure.vertices, scale_data);
}
