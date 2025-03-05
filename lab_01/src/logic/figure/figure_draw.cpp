#include "logic/figure/figure.hpp"

static ErrorFigure convert_vertex(Vertex &dest, const Vertex &src, const View &view) {
    if (!view.scene)
        return ARGS_ERROR;

    dest.x = src.x + view.width / 2;
    dest.y = src.y - view.height / 2;
    dest.z = src.z;

    return OK;
}

ErrorFigure get_points(Line &line, const View &view, const Edge &edge, const Vertex *vertices) {
    if (!vertices || !view.scene)
        return ARGS_ERROR;

    Vertex temp1 = init_vertex();
    Vertex temp2 = init_vertex();
    ErrorFigure error = convert_vertex(temp1, vertices[edge.vertex1 - 1], view);
    if (error_is_ok(error))
        error = convert_vertex(temp2, vertices[edge.vertex2 - 1], view);

    if (error_is_ok(error)) {
        line.vertex1 = temp1;
        line.vertex2 = temp2;
    }

    return error;
}

ErrorFigure draw_line(const View &view, const Vertex &vertex1, const Vertex &vertex2) {
    if (!view.scene)
        return ARGS_ERROR;

    view.scene->addLine(vertex1.x, vertex1.y, vertex2.x, vertex2.y);
    return OK;
}

Line init_line() {
    Line line{};
    line.vertex1 = Vertex{0, 0, 0};
    line.vertex2 = Vertex{0, 0, 0};
    return line;
}

ErrorFigure draw_lines(const View &view, const Vertices &vertices, const Edges &edges) {
    if (!vertices.array || !edges.array || !view.scene)
        return ARGS_ERROR;

    Line line = init_line();
    ErrorFigure error = init_error();
    for (int i = 0; i < edges.size && error_is_ok(error); i++) {
        error = get_points(line, view, edges.array[i], vertices.array);
        if (error_is_ok(error))
            error = draw_line(view, line.vertex1, line.vertex2);
    }

    return error;
}

void clear_scene(const View &view) {
    view.scene->clear();
}

ErrorFigure draw_figure(const View &view, const Figure &figure) {
    if (!view.scene)
        return ARGS_ERROR;

    clear_scene(view);
    return draw_lines(view, figure.vertices, figure.edges);
}