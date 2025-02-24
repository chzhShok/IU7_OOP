#include "logic/actions/actions.hpp"

ErrorFigure manage_action(const Action &action) {
    static Figure figure = init_figure();

    ErrorFigure error = OK;
    switch (action.type) {
        case UPLOAD:
            error = upload_figure(figure, action.path);
            break;
        case DRAW:
            error = draw_figure(action.view, figure);
            break;
        case MOVE:
            error = move_figure(figure, action.move);
            break;
        case ROTATE:
            error = rotate_figure(figure, action.rotate);
            break;
        case SCALE:
            error = scale_figure(figure, action.scale);
            break;
        case QUIT:
            free_figure(figure);
            break;
    }

    return error;
}
