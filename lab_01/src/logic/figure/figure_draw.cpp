#include "logic/figure/figure.hpp"

Vertex conversion(Vertex vertex, const View &view) {
    vertex.x += view.width / 2;
    vertex.y -= view.height / 2;

    return vertex;
}

Line get_points(const View &view, const Edge &edge, const Vertex *vertices) {
    Line line;

    line.vertex1 = conversion(vertices[edge.vertex1 - 1], view);
    line.vertex2 = conversion(vertices[edge.vertex2 - 1], view);

    return line;
}

void draw_line(const View &view, const Vertex &vertex1, const Vertex &vertex2) {
    view.scene->addLine(vertex1.x, vertex1.y, vertex2.x, vertex2.y);
}

ErrorFigure draw_lines(const View &view, const Vertices &vertices, const Edges &edges) {
    if (!vertices.array || !edges.array || !view.scene)
        return ARGS_ERROR;

    Line line;
    for (int i = 0; i < edges.size; i++) {
        line = get_points(view, edges.array[i], vertices.array);
        draw_line(view, line.vertex1, line.vertex2);
    }

    return OK;
}

ErrorFigure draw_figure(const View &view, const Figure &figure) {
    if (!view.scene)
        return ARGS_ERROR;
    view.scene->clear();

    return draw_lines(view, figure.vertices, figure.edges);
}
