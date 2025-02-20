#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "logic/figure/figure.hpp"

typedef struct Action Action;

enum ActionType {
    UPLOAD,
    DRAW,
    MOVE,
    ROTATE,
    SCALE,
};

struct Action {
    ActionType type;
    FilesPath path;

    union {
        View view;
        Move move;
        Rotate rotate;
        Scale scale;
    };
};

ErrorFigure manage_action(const Action &action);

#endif//ACTIONS_HPP
