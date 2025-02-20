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

ErrorFigure upload_figure(const FilesPath &path, Figure &figure);

Figure &init_figure();

ErrorFigure draw_figure(const View &view, const Figure &figure);

ErrorFigure move_figure(const Move &move_data, const Figure &figure);

ErrorFigure rotate_figure(const Rotate &rotate_data, const Figure &figure);

ErrorFigure scale_figure(const Scale &scale_data, const Figure &figure);

#endif//FIGURE_HPP
