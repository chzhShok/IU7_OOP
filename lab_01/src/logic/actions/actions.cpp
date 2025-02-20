#include "logic/actions/actions.hpp"

ErrorFigure manage_action(const Action &action) {
    static Figure figure = init_figure();

    ErrorFigure error = OK;
    switch (action.type) {
        case UPLOAD:
            error = upload_figure(action.path, figure);
            break;
        case DRAW:
            error = draw_figure(action.view, figure);
            break;
        case MOVE:
            error = move_figure(action.move, figure);
            break;
        case ROTATE:
            error = rotate_figure(action.rotate, figure);
            break;
        case SCALE:
            error = scale_figure(action.scale, figure);
            break;
    }

    return error;
}
