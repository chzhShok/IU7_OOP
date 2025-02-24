#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <QGraphicsScene>

#include "logic/figure/edges.hpp"
#include "logic/figure/vertices.hpp"

typedef struct Figure Figure;
typedef struct Line Line;

struct Line {
    Vertex vertex1;
    Vertex vertex2;
};

struct View {
    QGraphicsScene *scene;
    double width;
    double height;
};

struct Figure {
    Vertices vertices;
    Edges edges;
};

ErrorFigure upload_figure(Figure &figure, const FilesPath &path);

Figure &init_figure();

void free_figure(Figure &figure);

ErrorFigure draw_figure(const View &view, const Figure &figure);

ErrorFigure move_figure(Figure &figure, const Move &move_data);

ErrorFigure rotate_figure(Figure &figure, const Rotate &rotate_data);

ErrorFigure scale_figure(Figure &figure, const Scale &scale_data);

#endif//FIGURE_HPP
